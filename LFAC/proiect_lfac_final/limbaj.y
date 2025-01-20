    %{
    #include <iostream>
    #include <vector>
    #include <string>
    #include<cstring>
    #include "SymTable.h"
    #include "functii.h"
    #include "ast.h"

        using namespace std;
        extern FILE* yyin;
        extern char* yytext;
        extern int yylineno;
        extern int yylex();

        class SymTable* global;
        class SymTable* current;
        int errorCount = 0;

        vector<variabile>param;
        vector<variabile>param_value;



        %}


    %union {
        struct {
            char *tip;
            char* val;
            class AST *rad;
        } pair;
        char *val_str;
    }

    %token  BGIN END NR IF ELSE FOR WHILE PRINT CLASS   ACCESS EQUAL ELIF
    %token NEQ LEQ GEQ AND OR
    %token<val_str> NUME TIP
    %token RETURN
    %token<val_str> STRING
    %token<val_str> BOOL
    %token<val_str> INTEGER
    %token<val_str> FLOAT
    %token<val_str> CHAR
    %token<val_str> VOID

    %type <pair> conditie valoare expr term factor conditie_logica declarare_functii
    %type list_param param_val
    %token  TYPEOF
    %start program
    %type <val_str>comparatie '!' AND OR EQUAL NEQ LEQ GEQ '<' '>' '+' '-' '*' '/' '%'
    %nonassoc ELSE
    %left '!'
    %left OR
    %left AND
    %nonassoc EQUAL NEQ LEQ GEQ
    %left '<' '>'
    %left '+' '-'
    %left '*' '/' '%'

    %%

    program:
    {
        global=new SymTable("Program","GLOBAL:");
        current=global;
    }
    global_list BGIN
    {
        SymTable *nou=new SymTable("Main_Program","MAIN:",current);

        current->addScope(nou);
        current=nou;


    }
    main END
    {
        current=current->parinte;
        cout<<current->nume<<"-ul s-a incheiat cu "<<errorCount<<" erori\n";
    }
    ;


    global_list:
    global
    | global_list global
    ;


    global:
    declarare_variabile
    | declarare_functii
    | clase
    ;


    declarare_variabile:
    TIP NUME ';'
        { current->addVariabila($1,$2); }

    | TIP NUME '[' INTEGER ']' ';'
        {current->addVariabila($1,$2,stoi($4));}

    | TIP NUME '=' conditie ';'
    {

        if(strcmp($1,$4.tip)!=0)
            cout<<"Warning la linia "<<yylineno<< ": \""<< $1 <<"\" si " << $4.tip <<" nu au acelasi tip(1)\n",errorCount++;
        else
        {
            current->addVariabila($1,$2,0,$4.rad->compute().value.c_str());
        }
    }

    |NUME NUME ';'
    {
        if(global->existsScope($1)==false)
        {
            cout<<"Warning la linia "<<yylineno<< ": \""<< $1 <<"\" tip necunoscut(2)\n",errorCount++;
        }
        else  if(current->isDefined($1)==true)
        {
            cout<<"Warning la linia "<<yylineno<< ": \""<< $1 <<"\" este deja definit(3)\n",errorCount++;
        }
        else
            current->addVariabila($1,$2);
    }

    | NUME NUME '[' conditie ']' ';'
    {
        if(global->existsScope($1)==false)
        {
            cout<<"Warning la linia "<<yylineno<< ": \""<< $1 <<"\" tip necunoscut(2)\n",errorCount++;
        }
        else  if(current->isDefined($1)==true)
        {
            cout<<"Warning la linia "<<yylineno<< ": \""<< $1 <<"\" este deja definit(3)\n",errorCount++;
        }
        else
            current->addVariabila($1,$2,stoi($4.val));

    }
    ;


    declarare_functii:

    TIP NUME '(' list_param ')' ';'
    {
        SymTable *nou=new SymTable($2,"FUNCTIE:",current,$1);
        current->addScope(nou,param);
        param.clear();
    }

    |TIP NUME '(' list_param ')'

    '{'
    {
        SymTable *nou=new SymTable($2,"FUNCTIE:",current,$1);
        current->addScope(nou,param);
        current=nou;
        param.clear();
    }

    corp_func

    RETURN conditie ';'

    {
        string aux=current->returnType;

        char *aux1=$10.tip;

        strcpy(aux1,aux.c_str());

        if(strcmp(aux1,$10.tip)!=0)
            {cout<<"Warning la linia "<<yylineno<< ": functia si "<< $10.val <<" nu au acelasi tip(4)\n";errorCount++;}

    }
    '}'
    {
        current=current->parinte;
    }
    | VOID NUME '(' list_param ')'';'
    {
        SymTable *nou=new SymTable($2,"FUNCTIE:",current,$1);
        current->addScope(nou,param);
        param.clear();
    }

    | VOID NUME '(' list_param ')'
    {
        SymTable *nou=new SymTable($2,"FUNCTIE:",current,$1);
        current->addScope(nou,param);
        current=nou;
        param.clear();
    }
    '{' corp_func '}'
    {
        current=current->parinte;
    }

    ;



    list_param:
    TIP NUME
    {param.push_back({"parametru var: ",$1,$2});}

    | TIP NUME '[' INTEGER ']'
    {param.push_back({"parametru array: ",$1,$2,stoi($4)});}

    | list_param ',' TIP NUME
    {param.push_back({"parametru var: ",$3,$4});}

    | list_param ',' TIP NUME '[' INTEGER ']'
    {param.push_back({"parametru array: ",$3,$4,stoi($6)});}

    |
    ;



    corp_func:
    | block_de_cod corp_func

    | '{' corp_func RETURN conditie ';' '}' corp_func
    ;



    else_statement:
    ELSE '{'
    {
        SymTable *nou=new SymTable("","ELSE:",current);
        current->addScope(nou);
        current=nou;
    }

    option

    {
        current=current->parinte;
    }

    '}'
    ;



    elif_statement:
    ELIF '(' conditie ')' '{'
    {
        SymTable *nou=new SymTable("","ELIF:",current);
        current->addScope(nou);
        current=nou;
    }
    option
    {
        current=current->parinte;
    }
    '}'
    ;


    if_statement:
    IF '(' conditie ')' '{'
    {
        SymTable *nou=new SymTable("","IF:",current);
        current->addScope(nou);
        current=nou;
    }
    option
    {
        current=current->parinte;
    }
    '}'
    ;



    while_statement:
    WHILE '(' conditie ')' '{'
    {
        SymTable *nou=new SymTable("","WHILE:",current);
        current->addScope(nou);
        current=nou;
    }
    option
    {
        current=current->parinte;
    }
    '}'
    ;



    for_statement:
    FOR '(' NUME '=' conditie ';' conditie ';' NUME '=' NUME '+' conditie ')' '{'
    {
        SymTable *nou=new SymTable("","FOR:",current);

        variabile *aux1=current->returnVariabile($3),*aux2=current->returnVariabile($9),*aux3=current->returnVariabile($11);
        if(aux1==nullptr||aux2==nullptr||aux3==nullptr)
        {
            cout<<"Warning la linia "<<yylineno<< ""<<  "o variabila nu este definita(5)\n";
            errorCount++;
        }
        else if(strcmp(aux1->tip.c_str(),$5.tip)!=0||strcmp(aux2->tip.c_str(),aux3->tip.c_str())!=0||strcmp(aux2->tip.c_str(),$13.tip)!=0)
        {
            cout<<"Warning la linia "<<yylineno<< ""<<  "tipuri incompatibile(6)\n";
            errorCount++;
        }
        else
        {
            current->addScope(nou);

        }

        current=nou;
    }
    option

    {
        current=current->parinte;
    }
    '}'

    | FOR '(' TIP NUME '=' conditie ';' conditie ';' NUME '=' NUME '+' conditie ')' '{'
    {
        SymTable *nou=new SymTable("","FOR:",current);
        variabile *aux1=current->returnVariabile($10),*aux2=current->returnVariabile($12);
        if(aux1==nullptr||aux2==nullptr||current->isDefined($4)==false)
        {
            cout<<"Warning la linia "<<yylineno<< ""<<  " o variabila nu este definita(7)\n";
            errorCount++;
        }
        else if(strcmp($3,$6.tip)!=0||strcmp(aux1->tip.c_str(),aux2->tip.c_str())!=0||strcmp(aux2->tip.c_str(),$14.tip)!=0)
        {
            cout<<"Warning la linia "<<yylineno<< ""<<  " tipuri incompatibile(8)\n";
            errorCount++;
        }
        else
        {
            current->addScope(nou);
        }

        current=nou;
    }
    option

    {
        current=current->parinte;
    }
    '}'
    ;



    option:
    block_de_cod option

    | RETURN conditie ';'

    |
    ;



    block_de_cod:
    apeluri

    | declarare_variabile

    | if_statement else_statement

    | if_statement elif_statement

    | if_statement

    | while_statement

    | for_statement
    ;


    apeluri:
    NUME '=' conditie ';'
    {
        variabile *aux=current->returnVariabile($1);

        if(current->isDefined($1)!=true)
        {
            cout<<"Warning la linia "<<yylineno<< ": \""<< $1<<"\" nu este definit(9)\n";
            errorCount++;
        }
        else if(aux==nullptr||strcmp(aux->tip.c_str(),$3.tip)!=0)
        {
            cout<<"Warning la linia "<<yylineno<< ": " <<" tipuri incompatibile(10)\n";
            errorCount++;
        }
        else
        {
            SymTable *ar=current->getScope($1);
            if(current->tip_scop=="MAIN:")
            ar->modificareVariabila($1,$3.rad->compute().value.c_str());
        }

    }


    | NUME '(' { param_value.clear();} param_val ')' ';'
    {

        SymTable *aux=nullptr,*aux12;
        aux=global->verScopeColegi($1);

        for(int i=0; i<global->tabla.size(); i++)
        {
            aux12=global->tabla[i].second->verScopeColegi($1);
            if(aux12!=nullptr&&aux12->nume==$1)
            {

                aux=global->tabla[i].second->verScopeColegi($1);
                break;

            }

        }

        if(aux==nullptr)
            cout<<"Warning la linia "<<yylineno<< ": \""<< $1<<"\" nu este definita(11)\n",errorCount++;

        else if(param_value.size()!=aux->param.size()&&aux->tip_scop!="CLASA:")
        {

            cout<<"Warning la linia "<<yylineno<< ": "<< "numar de argumente invalide(12)\n";errorCount++;
        }
        else if(aux->tip_scop=="CLASA:")
        {
            aux=aux->verScopeColegi($1);

            if(aux!=nullptr &&aux->nume!=$1)
            {
                cout<<"Warning la linia "<<yylineno<< ": \""<< $1<<"\" nu este definita(13)\n";errorCount++;
            }
            else
            {
                bool gasit=true;
                for(int i=0; i<param_value.size(); i++)
                    if(param_value[i].tip!=aux->param[i].tip)
                    {
                        gasit=false;
                        break;
                    }
                if(gasit==false)
                    cout<<"Warning la linia "<<yylineno<< ": "<< "tipuri invalide(14)\n",errorCount++;
            }

        }
        else
        {
            bool gasit=true;
            for(int i=0; i<param_value.size(); i++)

                if(param_value[i].tip!=aux->param[i].tip)
                {
                    gasit=false;

                    break;
                }


            if(gasit==false)
                cout<<"Warning la linia "<<yylineno<< ": "<< "tipuri invalide(15)\n",errorCount++;
        }

    }
    | NUME '.' NUME ';'
    {
        SymTable *aux=current->getScope($1);
        if(aux==nullptr)
            cout<<"Warning la linia "<<yylineno<< ": \""<< $1<<"\" clasa nu este definita(14)\n",errorCount++;
        else
        {
            SymTable *aux2=nullptr;
            string tip=aux->getType($1);
            char* charPtr = &tip[0];
            aux2=global->verScopeColegi(charPtr);
            if(aux2->existsVariabila($3)==false)
                cout<<" Warning la linia "<<yylineno<< ": \""<< $3<<"\" nu este definit(15)\n",errorCount++;
        }

    }

    | NUME '[' INTEGER ']' '=' conditie ';'
    {
        if(current->isDefined($1)==false)
        {
            cout<<"Warning la linia "<<yylineno<< ": \"" << $1<<"\" nu este definit(16)\n";errorCount++;
        }
        else
        {

            variabile *aux=current->returnVariabile($1);

            if(current->isDefined($1)!=true)
            {
                cout<<"Warning la linia "<<yylineno<< ": \""<< $1<<"\" nu este definit(17)\n";errorCount++;
            }
            else if(aux==nullptr||strcmp(aux->tip.c_str(),$6.tip)!=0)
            {
                cout<<"Warning la linia "<<yylineno<< ": " <<" tipuri incompatibile(18)\n";errorCount++;
            }
            else
            {
                SymTable *ar=current->getScope($1);
                ar->modificareVector($1,$6.rad->compute().value.c_str(),stoi($3));
            }


        }
    }
    | NUME '.' NUME '=' conditie ';'
    {
        SymTable *aux=current->getScope($1);
        if(aux==nullptr)
            cout<<"Warning la linia "<<yylineno<< ": \""<< $1<<"\" clasa nu este definita(19)\n",errorCount++;
        else
        {
            SymTable *aux2=nullptr;
            string tip=aux->getType($1);
            char* charPtr = &tip[0];
            aux2=global->verScopeColegi(charPtr);

            if(aux2->existsVariabila($3)==false)
                cout<<" Warning la linia "<<yylineno<< ": \""<< $3<<"\" nu este definit(20)\n",errorCount++;

            else
            {

            }

        }

    }


    | NUME '.' NUME '(' { param_value.clear();} param_val ')' ';'
    {
        SymTable *aux=nullptr,*aux12;
        aux=current->getScope($1);
        if(aux==nullptr)
        {	cout<<"Warning la linia "<<yylineno<< ": \""<< $1<<"\" clasa nu este definita(33)\n";
            errorCount++;
        }

        else
        {
            SymTable *aux2=nullptr;
            string tip=aux->getType($1);
            char* charPtr = &tip[0];
            char *tiip=new char[2000];
            strcpy(tiip,tip.c_str());
            aux=global->verScopeColegi(tiip);

            if(aux!=nullptr)
                aux=aux->verScopeColegi($3);

            if(aux==nullptr)
            {	cout<<" Warning la linia "<<yylineno<< ": \""<< $3<<"\" nu este definit(34)\n";
                errorCount++;
            }
            else
            {
                bool gasit=true;

                for(int i=0; i<param_value.size(); i++)
                    if(param_value[i].tip!=aux->param[i].tip)
                    {
                        gasit=false;
                        break;
                    }

                if(gasit==false)
                {	cout<<"Warning la linia "<<yylineno<< ": "<< "tipuri invalide(35)\n";errorCount++;

                }
            }

        }

    }


    | functii_predefinite
    | functii_predefinite ';'
    ;

    functii_predefinite:
    PRINT '(' conditie ')'

    {
        if(current->tip_scop=="MAIN:")
        cout<<"Info linia "<<yylineno<< "-> Rezultat: PRINT("<<$3.val<<")="<<$3.rad->compute().value.c_str()<<'\n';
    }

    | TYPEOF '(' conditie ')'
    {
        if(current->tip_scop=="MAIN:")
        cout<<"Info linia "<<yylineno<< "-> Rezultat: TYPEOF("<<$3.val<<")="<<$3.rad->arbType()<<'\n';
    }
    ;

    conditie:
    expr comparatie expr
    {
        {
            {
                if(strcmp($1.tip,$3.tip)==0)
                {	char* aux=$1.val;
                    char* aux1=$3.val;
                    strcat(aux,$2);
                    strcat(aux,aux1);

                    char* aux3=$1.tip;

                    strcpy($$.tip,"bool");
                    strcpy($$.val,aux);
                    AST *st = $1.rad;
                    AST *dr = $3.rad;
                    AST *root = new AST(strdup("expr comp"), strdup(""), strdup($2), st, dr);
                    $$.rad=root;
                }
                else
                {
                    cout<<"Warning la linia "<<yylineno<< ": \""<< $1.val<<"\" si \" " << $3.val <<"\" nu acelasi tip(24)\n";errorCount++;

                }


            }
        }
    }

    | expr
    {
        $$.tip=$1.tip;
        $$.val=$1.val;
        $$.rad=$1.rad;
    }
    | conditie_logica
    {
        $$.tip=strdup("bool");
        $$.val=$1.val;
        $$.rad=$1.rad;

    }
    | '!' conditie
    {
        $$.tip=$2.tip;
        char*a2=$1;
        strcat(a2,$2.val);
        strcpy($$.val,a2);
        AST *st = $2.rad;
        AST *root = new AST(strdup(""), strdup("string"), strdup("&&"), st);
        $$.rad=root;
    }
    ;

    conditie_logica:
    conditie AND conditie
    {
        {
            {
                if(strcmp($1.tip,$3.tip)==0&& strcmp($1.tip,$3.tip)==0)
                {	char* aux=$1.val;
                    char* aux1=$3.val;
                    strcat(aux,"&&");
                    strcat(aux,aux1);
                    char* aux3=$1.tip;
                    strcpy($$.tip,"bool");
                    strcpy($$.val,aux);

                    AST *st = $1.rad;
                    AST *dr = $3.rad;
                    AST *root = new AST(strdup("expr bool"), strdup("string"), strdup("&&"), st, dr);
                    $$.rad=root;
                }
                else
                {

                    cout<<"Warning la linia "<<yylineno<< ": \""<< $1.val<<"\" si \" " << $3.val <<"\" nu acelasi tip(25)\n";errorCount++;

                }


            }
        }
    }
    | conditie OR conditie
    {
        {
            {
                if(strcmp($1.tip,$3.tip)==0 && strcmp($1.tip,"bool")==0)
                {	char* aux=$1.val;
                    char* aux1=$3.val;
                    strcat(aux,"||");
                    strcat(aux,aux1);

                    char* aux3=$1.tip;


                    strcpy($$.tip,"bool");
                    strcpy($$.val,aux);
                    AST *st = $1.rad;
                    AST *dr = $3.rad;
                    AST *root = new AST(strdup("expr bool"), strdup("string"), strdup("||"), st, dr);
                    $$.rad=root;

                }
                else
                {
                    cout<<"Warning la linia "<<yylineno<< ": \""<< $1.val<<"\" si \" " << $3.val <<"\" nu acelasi tip(26)\n";errorCount++;

                }


            }
        }
    }
    ;

    comparatie:
    '>'
    {
        $$=strdup(">");
    }
    | '<'
    {
        $$=strdup("<");
    }
    | EQUAL
    {
        $$=strdup("==");
    }
    | NEQ
    {
        $$=strdup("!=");
    }
    | LEQ
    {
        $$=strdup("<=");
    }
    | GEQ
    {
        $$=strdup(">=");
    }
    ;

    expr:
    expr '+' expr
    {
        {
            {
                if(strcmp($1.tip,$3.tip)==0)
                {	char* aux=$1.val;
                    char* aux1=$3.val;
                    strcat(aux,"+");
                    strcat(aux,aux1);

                    char* aux3=$1.tip;


                    strcpy($$.tip,aux3);
                    strcpy($$.val,aux);
                    AST *st = $1.rad;
                    AST *dr = $3.rad;
                    AST *root = new AST(strdup("expr aritm"), strdup("string"), strdup("+"), st, dr);
                    $$.rad=root;

                }
                else
                {
                    cout<<"Warning la linia "<<yylineno<< ": \""<< $1.val<<"\" si \" " << $3.val <<"\" nu acelasi tip(27)\n";errorCount++;

                }


            }
        }
    }

    | expr '-' expr
    {
        {
            {
                if(strcmp($1.tip,$3.tip)==0)
                {	char* aux=$1.val;
                    char* aux1=$3.val;
                    strcat(aux,"-");
                    strcat(aux,aux1);

                    char* aux3=$1.tip;


                    strcpy($$.tip,$1.tip);
                    strcpy($$.val,aux);
                    AST *st = $1.rad;
                    AST *dr = $3.rad;
                    AST *root = new AST(strdup("expr aritm"), strdup("string"), strdup("-"), st, dr);
                    $$.rad=root;


                }
                else
                {
                    cout<<"Warning la linia "<<yylineno<< ": \""<< $1.val<<"\" si \" " << $3.val <<"\" nu acelasi tip(28)\n";errorCount++;

                }


            }
        }
    }
    | term
    {
        $$.tip=$1.tip;
        $$.val=$1.val;
    }

    ;

    term:
    term '*' term
    {
        {
            {
                if(strcmp($1.tip,$3.tip)==0)
                {	char* aux=$1.val;
                    char* aux1=$3.val;
                    strcat(aux,"*");
                    strcat(aux,aux1);

                    char* aux3=$1.tip;


                    strcpy($$.tip,aux3);
                    strcpy($$.val,aux);

                    AST *st = $1.rad;
                    AST *dr = $3.rad;
                    AST *root = new AST(strdup("expr aritm"), strdup("string"), strdup("*"), st, dr);
                    $$.rad=root;
                }
                else
                {
                    cout<<"Warning la linia "<<yylineno<< ": \""<< $1.val<<"\" si \" " << $3.val <<"\" nu acelasi tip(29)\n";errorCount++;

                }


            }
        }
    }
    | term '/' term
    {
        {
            {
                if(strcmp($1.tip,$3.tip)==0)
                {	char* aux=$1.val;
                    char* aux1=$3.val;
                    strcat(aux,"/");
                    strcat(aux,aux1);

                    char* aux3=$1.tip;


                    strcpy($$.tip,aux3);
                    strcpy($$.val,aux);
                    AST *st = $1.rad;
                    AST *dr = $3.rad;
                    AST *root = new AST(strdup("expr aritm"), strdup("string"), strdup("/"), st, dr);
                    $$.rad=root;

                }
                else
                {
                    cout<<"Warning la linia "<<yylineno<< ": \""<< $1.val<<"\" si \" " << $3.val <<"\" nu acelasi tip(30)\n";errorCount++;

                }


            }
        }
    }
    | term '%' term
    {
        {
            {
                if(strcmp($1.tip,$3.tip)==0)
                {	char* aux=$1.val;
                    char* aux1=$3.val;
                    strcat(aux,"%");
                    strcat(aux,aux1);

                    char* aux3=$1.tip;


                    strcpy($$.tip,aux3);
                    strcpy($$.val,aux);
                    AST *st = $1.rad;
                    AST *dr = $3.rad;
                    AST *root = new AST(strdup("expr aritm"), strdup("string"), strdup("%"), st, dr);
                    $$.rad=root;


                }
                else
                {
                    cout<<"Warning la linia "<<yylineno<< ": \""<< $1.val<<"\" si \" " << $3.val <<"\" nu acelasi tip(31)\n";errorCount++;

                }


            }
        }
    }
    | factor
    {
        $$.tip =$1.tip;
        $$.val =$1.val;
        $$.rad=$1.rad;
    }
    ;

    factor:
    valoare
    {
        $$.tip=$1.tip;
        $$.val=$1.val;
        $$.rad=$1.rad;
    }
    ;



    main:
    option
    ;

    clase:
    CLASS NUME ';'
    {
        SymTable *nou=new SymTable($2,"CLASA:",current);
        current->addScope(nou);

    }



    | CLASS NUME '{'
    {
        SymTable *nou=new SymTable($2,"CLASA:",current);


        current->addScope(nou);
        current=nou;

    }

    corp_clasa '}' ';'
    {

        current=current->parinte;
    }
    ;

    corp_clasa:
    ACCESS declarare_variabile corp_clasa
    | declarare_variabile corp_clasa
    | ACCESS declarare_functii corp_clasa
    | declarare_functii corp_clasa
    |functii_predefinite corp_clasa
    |
    ;

    valoare:
    INTEGER{
        $$.tip=strdup("int");
        $$.val=strdup($1);
        $$.rad=new AST(strdup("var"), strdup("int"), strdup($1));
    }
    | FLOAT{
        $$.tip=strdup("float");
        $$.val=strdup($1);
        $$.rad=new AST(strdup("var"), strdup("float"), strdup($1));
    }
    | CHAR{
        $$.tip=strdup("char");
        $$.val=strdup($1);
        $$.rad=new AST(strdup("var"), strdup("char"), strdup($1));
    }
    | STRING{  $$.tip=strdup("string");
        $$.val=strdup($1);
        $$.rad=new AST(strdup("var"), strdup("string"), strdup($1));
    }

    | BOOL{
        $$.tip=strdup("bool");
        $$.val=strdup($1);
        $$.rad=new AST(strdup("var"), strdup("bool"), strdup($1));
    }
    | NUME
    {
        if(current->isDefined($1)==true)
        {
            variabile *aux=current->returnVariabile($1);

            if(aux!= nullptr )
            {
                string ax=aux->tip;

                $$.tip=strdup(&ax[0]);

                if(aux->value.size()!=0&&aux->value[0]!="")
                {	ax=aux->value[0];

                    $$.val=strdup(&ax[0]);
                    $$.rad=new AST(strdup("var"), $$.tip, $$.val);
                }
                else {
                    $$.val=strdup("");
                    $$.rad=new AST(strdup("default"), $$.tip, strdup(""));
                }
            }
            else
            {
                $$.tip=strdup("");
                $$.val=strdup("");
                $$.rad=new AST(strdup("default"), strdup(""), strdup(""));
            }



        }
        else
        {
            cout<<"Warning la linia "<<yylineno<< ": \""<< $1<<"\" nu este definit(32)\n";
            $$.tip=strdup("");
            $$.val=strdup("");
            $$.rad=new AST(strdup("default"), strdup(""), strdup(""));
        }

    }
    | NUME '.' NUME '(' {param_value.clear();} param_val ')'

    {
        SymTable *aux=nullptr,*aux12;
        aux=current->getScope($1);

        if(aux==nullptr)
        {	cout<<"Warning la linia "<<yylineno<< ": \""<< $1<<"\" clasa nu este definita(33)\n";errorCount++;
            $$.tip=strdup("");
             $$.rad=new AST(strdup("default"), strdup(""), strdup(""));
            $$.val=strdup("");
        }

        else
        {
            SymTable *aux2=nullptr;
            string tip=aux->getType($1);

            char* charPtr = &tip[0];

            char *tiip=new char[2000];

            strcpy(tiip,tip.c_str());

            aux=global->verScopeColegi(tiip);

            if(aux!=nullptr)
                aux=aux->verScopeColegi($3);

            if(aux==nullptr)
            {	cout<<" Warning la linia "<<yylineno<< ": \""<< $3<<"\" nu este definit(34)\n";errorCount++;
                $$.tip=strdup("");
                 $$.rad=new AST(strdup("default"), strdup(""), strdup(""));
                $$.val=strdup("");
            }
            else

            {
                bool gasit=true;
                char *aax=new char[2000];
                strcpy(aax,$1);
                strcat(aax,".");
                strcat(aax,$3);
                strcat(aax,"(");

                for(int i=0; i<param_value.size(); i++)
                    if(param_value[i].tip!=aux->param[i].tip)
                    {
                        gasit=false;
                        break;
                    } else
                    {
                        strcat(aax,param_value[i].nume.c_str());
                    }
                strcat(aax,")");

                if(gasit==false)
                {	cout<<"Warning la linia "<<yylineno<< ": "<< "tipuri invalide(35)\n";errorCount++;
                    $$.tip=strdup("");
                     $$.rad=new AST(strdup("default"), strdup(""), strdup(""));
                    $$.val=strdup("");
                }
                else
                {
                    $$.val=aax;
                    strcpy(tiip,aux->returnType.c_str());


                    $$.tip=tiip;
                    $$.rad=new AST(strdup("default"), $$.tip, $$.val);

                }

            }

        }

    }


    | NUME '(' {param_value.clear();} param_val ')'
    {

        SymTable *aux=nullptr,*aux12;
        aux=global->verScopeColegi($1);



        if(aux==nullptr)
        {	cout<<"Warning la linia "<<yylineno<< ": \""<< $1<<"\" nu este definita(36)\n";errorCount++;
            $$.tip=strdup("");
            $$.val=strdup("");
             $$.rad=new AST(strdup("default"), strdup(""), strdup(""));
        }

        else if(param_value.size()!=aux->param.size()&&aux->tip_scop!="CLASA:")
        {

            cout<<" Warning la linia "<<yylineno<< ": "<< "numar de argumente invalide(37)\n";errorCount++;
            $$.tip=strdup("");
             $$.rad=new AST(strdup("default"), strdup(""), strdup(""));
            $$.val=strdup("");
        }
        else if(aux->tip_scop=="CLASA:")
        {
            aux=aux->verScopeColegi($1);

            if(aux!=nullptr &&aux->nume!=$1)
            {
                cout<<"Warning la linia "<<yylineno<< ": \""<< $1<<"\" nu este definita(38)\n";errorCount++;
                $$.tip=strdup("");
                $$.val=strdup("");
                 $$.rad=new AST(strdup("default"), strdup(""), strdup(""));
            }
            else
            {

                bool gasit=true;
                char *aax=new char[2000];
                strcpy(aax,$1);


                strcat(aax,"(");

                for(int i=0; i<param_value.size(); i++)
                    if(param_value[i].tip!=aux->param[i].tip)
                    {
                        gasit=false;
                        break;
                    } else
                    {
                        strcat(aax,param_value[i].nume.c_str());
                    }
                strcat(aax,")");

                if(gasit==false)
                {	cout<<"Warning la linia "<<yylineno<< ": "<< "tipuri invalide(39)\n";errorCount++;

                    $$.tip=strdup("");
                    $$.val=strdup("");
                     $$.rad=new AST(strdup("default"), strdup(""), strdup(""));
                }
                else
                {

                    $$.val=aax;

                    char *mm=strdup("");
                    strcpy(mm,aux->returnType.c_str());

                    $$.tip=mm;

                    $$.rad=new AST(strdup("default"), $$.tip, $$.val);


                }

            }


        }
        else {

            bool gasit=true;
            char *aax=new char[2000];
            strcpy(aax,$1);


            strcat(aax,"(");

            for(int i=0; i<param_value.size(); i++)
                if(param_value[i].tip!=aux->param[i].tip)
                {
                    gasit=false;
                    break;
                } else
                {
                    strcat(aax,param_value[i].nume.c_str());
                }
            strcat(aax,")");

            if(gasit==false)
            {	cout<<"Warning la linia "<<yylineno<< ": "<< "tipuri invalide(39)\n";errorCount++;
 $$.rad=new AST(strdup("default"), strdup(""), strdup(""));
                $$.tip=strdup("");
                $$.val=strdup("");
            }
            else
            {

                $$.val=aax;

                char *mm=strdup("");
                strcpy(mm,aux->returnType.c_str());

                $$.tip=mm;

                $$.rad=new AST(strdup("default"), $$.tip, $$.val);


            }

        }
    }

    | NUME '[' INTEGER ']' {
        if(current->isDefined($1)!=true)
        {
            cout<<"Warning la linia "<<yylineno<< ": \"" << $1<<"\" nu este definit(40)\n";errorCount++;
            $$.tip=strdup("");
            $$.val=strdup("");
        }
        else
        {

            variabile *aux=current->returnVariabile($1);

            if(current->isDefined($1)!=true)
            {
                cout<<"Warning la linia "<<yylineno<< ": \""<< $1<<"\" nu este definit(41)\n";errorCount++;
                $$.tip=strdup("");
                $$.val=strdup("");
            }
            else if(aux==nullptr)
            {
                cout<<"Warning la linia "<<yylineno<< ": " <<" indexul nu este intreg(42)\n";errorCount++;
                $$.tip=strdup("");
                $$.rad=new AST(strdup("default"), strdup("int"), strdup(""));
                $$.val=strdup("");
            }
            else
            {
                SymTable *ar=current->getScope($1);
                variabile *varr=ar->returnVariabile($1);

                char *axx=new char[2000];

                strcpy(axx,$1);
                strcat(axx,"[");

                if(($3[0]>='a'&& $3[0]<='z')||($3[0]>='A'&& $3[0]<='Z'))
                    strcat(axx,"");
                else
                    strcat(axx,$3);

                strcat(axx,"]");
                $$.val=axx;
                char *mm=strdup("");
                strcpy(mm,varr->tip.c_str());

                $$.tip=mm;
                char *m=new char[100];

                if(strncmp(varr->nume_scop.c_str(),"parame",5)==0)
                    $$.rad=new AST(strdup("default"), $$.tip, strdup(""));

                else if(atoi($3)<varr->size)
                {	strcpy(m,varr->value[atoi($3)].c_str());
                    $$.rad=new AST(strdup("var"), $$.tip, m);
                }
                else
                    $$.rad=new AST(strdup("default"), $$.tip, strdup(axx));

            }
        }

    }

    | NUME '[' NUME ']' {
        if(current->isDefined($1)!=true)
        {
            cout<<"Warning la linia "<<yylineno<< ": \"" << $1<<"\" nu este definit(40)\n";errorCount++;
            $$.tip=strdup("");
            $$.val=strdup("");
             $$.rad=new AST(strdup("default"), strdup(""), strdup(""));

        }
        else
        {

            variabile *aux=current->returnVariabile($1);
            variabile *aux1=current->returnVariabile($3);
            if(current->isDefined($1)!=true)
            {
                cout<<"Warning la linia "<<yylineno<< ": \""<< $1<<"\" nu este definit(41)\n";errorCount++;
                $$.tip=strdup("");
                $$.val=strdup("");
            }
            else if(strcmp("int",aux1->tip.c_str())!=0)
            {
                cout<<"Warning la linia "<<yylineno<< ": " <<" indexul nu este intreg(42)\n";errorCount++;
                $$.tip=strdup("");
                $$.val=strdup("");
                 $$.rad=new AST(strdup("default"), strdup(""), strdup(""));
            }
            else if(aux==nullptr)
            {
                $$.rad=new AST(strdup("default"), strdup("int"), strdup(""));
            }
            else
            {

                SymTable *ar=current->getScope($1);
                variabile *varr=ar->returnVariabile($1);

                char *axx=new char[2000];

                strcpy(axx,$1);
                strcat(axx,"[");

                if(($3[0]>='a'&& $3[0]<='z')||($3[0]>='A'&& $3[0]<='Z'))
                    strcat(axx,"");
                else
                    strcat(axx,$3);

                strcat(axx,"]");
                $$.val=axx;
                char *mm=strdup("");
                strcpy(mm,varr->tip.c_str());

                $$.tip=mm;
                char *m=new char[100];

                if(aux1!=nullptr)
                {	strcpy(m,aux1->value[0].c_str());
                    $$.rad=new AST(strdup("var"), $$.tip, m);
                }
                else
                    $$.rad=new AST(strdup("default"), $$.tip, strdup(axx));

            }
        }

    }
    | NUME '.' NUME
    {
        SymTable *aux=current->getScope($1);
        if(aux==nullptr)
        {	cout<<"Warning la linia "<<yylineno<< ": \""<< $1<<"\" clasa nu este definita(43)\n";errorCount++;
            $$.tip=strdup("");
            $$.val=strdup("");
             $$.rad=new AST(strdup("default"), strdup(""), strdup(""));
        }
        else
        {

            variabile *a=aux->returnVariabile($1);

            char *aa=new char[100];
            strcpy(aa,a->tip.c_str());
            aux=global->verScopeColegi(aa);

            if(aux==nullptr)
            {
                cout<<"Warning la linia "<<yylineno<< ": \""<< $1<<"\" nu este definita(38)\n";errorCount++;
                $$.tip=strdup("");
                $$.val=strdup("");
                 $$.rad=new AST(strdup("default"), strdup(""), strdup(""));
            }
            else
            {
                variabile *varr=aux->returnVariabile($3);
                bool gasit=true;
                char *aax=new char[2000];
                strcpy(aax,$1);
                strcat(aax,".");

                if(varr!=nullptr)
                {
                    strcat(aax,$3);
                    $$.val=aax;

                    char *mm=strdup("");
                    strcpy(mm,varr->tip.c_str());

                    $$.tip=mm;
                    $$.rad=new AST(strdup("default"), $$.tip, $$.val);

                }


                else
                {	cout<<"Warning la linia "<<yylineno<< ": "<< "tipuri invalide(39)\n";errorCount++;

                    $$.tip=strdup("");
                    $$.val=strdup("");
                    $$.rad=new AST(strdup("default"), strdup(""), strdup(""));
                }


            }


        }}

    | '('

    conditie ')' {

        int n=strlen($2.val);
        char *aux2=$2.val;

        char * aux=new char[1000];
        strcpy(aux,"(");
        strcat(aux,aux2);

        strcat(aux,")");

        $$.val=aux;

        $$.tip=$2.tip;
        $$.rad=$2.rad;
    }
    ;

    param_val:
    param_val ',' conditie
    {
        if( !($3.tip == nullptr || $3.val == nullptr || strcmp($3.tip, "") == 0 || strcmp($3.val, "") == 0))
        {
            char * aux=new char[1000];

            strcpy(aux,$3.tip);
            char * aux1=new char[1000];

            strcpy(aux1,$3.val);

            param_value.push_back({"2",aux,aux1});

        }
    }
    | conditie
    {
        if (!($1.tip == nullptr || $1.val == nullptr || strcmp($1.tip, "") == 0 || strcmp($1.val, "") == 0))
        {

            char * aux=new char[44];

            strcpy(aux,$1.tip);

            char * aux1=new char[44];
            strcpy(aux1,$1.val);

            param_value.push_back({"2",aux,aux1});


        }
    }
    |
    ;



    %%

    int main(int argc, char** argv) {
        ofstream outFile("symTable_out.txt");
        if (!outFile) {
            cerr << "Eroare la deschiderea fisierului!\n";
            return 1;
        }
        yyin = fopen(argv[1], "r");
        int cnt = 0;

        yyparse();

        fclose(yyin);

        current->print(outFile);

        outFile.close();

        return 0;
    }