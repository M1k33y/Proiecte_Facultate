#include "functii.h"
extern int yylineno;
extern char* yytext;
int aux=0;
char* validare_asignare(const char* variabila, const char* valoare) {
    if (strcmp(variabila, valoare) != 0) {
        char* val_return = new char[250]; // Alocăm memorie
        sprintf(val_return, "Tip incompatibil(Se așteaptă un %s)", variabila); // Construim mesajul
        return val_return; // Returnăm mesajul de eroare
    }
    return (char*)"corect"; // Returnăm mesajul de succes
}


void validare(char * param1,char* param2)
{
char *aux=new char[250];
     			strcpy(aux,validare_asignare(param1,param2));
        			if (strcmp(aux,"corect")!=0)
        			{
            				yyerror(aux);
            			}

}
void ver_new_line(const char *s)
{
for(int i=0;i<strlen(s);i++)
	if(s[i]=='\n')
	yylineno++;

}

void yyerror(const char * s){

  if(aux!=yylineno)
    {
     cout << "Eroarea la linia "<< yylineno<<": "<< s << ' '<<yytext<<endl;
  aux=yylineno;
  }
}

