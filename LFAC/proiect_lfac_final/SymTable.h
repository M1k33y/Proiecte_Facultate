#include <iostream>

#include <vector>

#include <unordered_map>

#include <string>

#include<fstream>

#include <iostream>

#include <map>

#include <string>

#include <cstring>

extern int yylineno;
using namespace std;

class variabile {
  public: string nume_scop; //variabila,vector
  string tip;
  string nume;
  int size = 0; //pentru vectori
  vector < string > value = {};

};

//asta e un singur scop
class SymTable {
  public: string nume;
  string tip_scop; //lobal,bloc(if/else/elif/for/while), functie, clasa,main
  vector < pair < string,
  SymTable * >> tabla; //fii scope-ului

  SymTable * parinte;

  vector < variabile >
  var; //variabile scop

  string returnType; //functii
  vector < variabile > param; //functii
  string value;
  public:

    SymTable(string name, string type_scop, SymTable * parent = nullptr, string tt = "", vector < variabile > params = {}) {

      nume = name;
      tip_scop = type_scop;
      parinte = parent;
      returnType = tt;
      param = params;
    }

  SymTable(const char * n,
    const char * t, SymTable * parent = nullptr,
      char * rt = nullptr,
      vector < variabile > params = {}) {
    string name = n;
    string type_scop = t;
    string returnnType;
    if (rt == nullptr)
      returnnType = "";
    else
      returnnType = rt;

    nume = name;
    tip_scop = type_scop;
    parinte = parent;
    returnType = returnnType;
    param = params;
  }
  void modificareVariabila(char * n,
    const char * vall) {

    for (int i = 0; i <
      var.size(); i++) {

      if (var [i].nume == n) {

        var [i].value[0] = vall;

      }
    }
  }

  void modificareVector(char * n,
    const char * vall, int index) {

    for (int i = 0; i <
      var.size(); i++) {

      if (var [i].nume == n) {
        if (var [i].size - 1 < index) {

          cout << "Warning la linia " << yylineno << ": indexul \"" << index << "\"  este prea mare (209)\n";

        } else
          var [i].value[index] = vall;

      }
    }
  }
  variabile * returnVariabile(char * n) {
    string name = n ? n : "";

    for (int i = 0; i <
      var.size(); i++)
      if (var [i].nume == name) {
        if (var [i].size == 0 &&
          var [i].value.size() == 0)
          var [i].value.push_back("");
        return &
          var [i];

      }

    for (int i = 0; i < param.size(); i++)
      if (param[i].nume == name) {
        return & param[i];
      }

    if (parinte == nullptr)
      return nullptr;

    return parinte -> returnVariabile(n);

  }

  void addScope(SymTable * scope, vector < variabile > paramss = vector < variabile > ()) {

    char * aux = new char[100];
    strcpy(aux, scope -> nume.c_str());

    if ((existsScope(aux) == false) || (
        scope -> tip_scop == "IF:" ||
        scope -> tip_scop == "ELSE:" ||
        scope -> tip_scop == "ELIF:" ||
        scope -> tip_scop == "WHILE:" ||
        scope -> tip_scop == "FOR:")) {
      {
        if (paramss.size() > 0) {
          scope -> param = paramss;
        }

        tabla.push_back({
          scope -> nume,
          scope
        });
      }
    } else {
      cout << "Warning la linia " << yylineno << ": tabela cu numele \"" << scope -> nume << "\" si scopul: " << scope -> tip_scop << " este deja definita(209)\n";

    }

  }

  SymTable * getScope(char * n) {

    if (existsVariabila(n) == true)
      return this;

    if (parinte == nullptr)
      return nullptr;

    return parinte -> getScope(n);

  }
  string getType(char * n) {
    variabile * aux = returnVariabile(n);
    if (aux == nullptr)
      return "";
    return aux -> tip;
  }

  SymTable * verScopeColegi(char * n)

  {
    string name = n ? n : "";
    SymTable * aux;

    for (int i = 0; i < tabla.size(); i++) {
      if (tabla[i].second -> nume == name)
        return tabla[i].second;
    }

    for (int i = 0; i < tabla.size(); i++)
      if (tabla[i].second -> existsScope(n) == true)
        return tabla[i].second;
    return nullptr;
  }

  void addVariabila(char * t, char * n, int dim = 0,
    const char * val = (char * ) nullptr) {
    string name = n ? n : "";
    string type = t ? t : "";
    if (isDefined(name.c_str()) == false) {
      variabile aux;
      aux.tip = type;
      aux.nume = name;
      aux.size = dim;

      aux.nume_scop = (dim == 0) ? "var:    " : "array:  ";
      if (dim > 0) {
        for (int i = 0; i < dim; i++) {
          if (type == "int")
            aux.value.push_back("0");
          else if (type == "float")
            aux.value.push_back("0.0");
          else if (type == "bool")
            aux.value.push_back("false");
          else aux.value.push_back("");

        }
      } else {
        if (val == nullptr || val == "") {
          if (type == "int")
            aux.value.push_back("0");
          else if (type == "float")
            aux.value.push_back("0.0");
          else if (type == "bool")
            aux.value.push_back("false");
          else aux.value.push_back("");
        } else
          aux.value.push_back(val);

      }
      var.push_back(aux);
    } else {
      cout << "Warning la linia " << yylineno << ": variabila \"" << name << ' ' << tip_scop << "\" exista deja(210)\n";

    }
  }

  void addParam(char * t, char * n, int dim = 0) {
    string name = n ? n : "";
    string type = t ? t : "";
    if (existsVariabila(name.c_str()) == false) {
      variabile aux;
      aux.tip = type;
      aux.nume = name;
      aux.size = dim;
      aux.nume_scop = (dim == 0) ? "parametru var: " : "parametru array: ";
      param.push_back(aux);
    } else {
      cout << "Warning la linia " << yylineno << ": parametrul \"" << name << "\" exista deja in acest scop(211)\n";

    }
  }

  void addParametri(vector < variabile > paramss = vector < variabile > ()) {

    param = paramss;
  }

  bool existsScope(const char * n) {
    string name(n);

    if (strcmp(nume.c_str(), n) == 0)
      return true;

    for (int i = 0; i < tabla.size(); i++) {
      {

        if (strcmp(tabla[i].first.c_str(), n) == 0) {

          return true;
        }
      }

    }

    if (parinte == nullptr)
      return false;

    return parinte -> existsScope(n);

  }

  bool existsVariabila(const char * n) {
    string name = n ? n : "";

    for (int i = 0; i <
      var.size(); i++)
      if (var [i].nume == name)
        return true;

    for (int i = 0; i < param.size(); i++)

      if (param[i].nume == name)
        return true;

    // if(parinte==nullptr)
    // return false;

    // return parinte->existsVariabila(name);
    return false;
  }

  bool isDefined(const char * n) {
    string name = n ? n : "";

    for (int i = 0; i <
      var.size(); i++)
      if (var [i].nume == name)
        return true;

    for (int i = 0; i < param.size(); i++)
      if (param[i].nume == name)
        return true;

    if (parinte == nullptr)
      return false;

    return parinte -> isDefined(name.c_str());

  }

  void print(ofstream & outFile, int cnt = 0) {
    // Indentare pentru tabelul curent
    for (int j = 0; j <= cnt; j++)
      outFile << " ";

    outFile << tip_scop;
    if (returnType != "")
      outFile << "   Return Type: " << returnType;

    if (!nume.empty())
      outFile << "   Nume: " << nume;
    outFile << "\n";
    cnt += 5;

    // Afișare parametri
    for (int i = 0; i < param.size(); i++) {
      for (int k = 0; k <= cnt; k++)
        outFile << " ";

      outFile << param[i].nume_scop << "   TIP: " << param[i].tip << ",   NUME: " << param[i].nume;
      if (param[i].size > 0)
        outFile << ",   SIZE: " << param[i].size;
      outFile << "\n";
    }

    // Afișare variabile
    for (int i = 0; i <
      var.size(); i++) {
      for (int k = 0; k <= cnt; k++)
        outFile << " ";

      outFile <<
        var [i].nume_scop << "   TIP: " <<
        var [i].tip << ",   NUME: " <<
        var [i].nume;
      if (var [i].size > 0) {
        outFile << ",   SIZE: " <<
          var [i].size;
        outFile << ",   VALORI: ";
        for (int l = 0; l <
          var [i].size; l++)
          if (var [i].value[l].size() > 0)
            outFile << ", " <<
            var [i].value[l];
          else
            outFile << ", EMPTY";
      } else if (var [i].value.size() > 0 && (var [i].tip == "int" ||
          var [i].tip == "float" ||
          var [i].tip == "char" ||
          var [i].tip == "bool" ||
          var [i].tip == "string")) {

        outFile << ",   VALUE: " <<
          var [i].value[0];;
      } else if ((var [i].tip == "int" ||
          var [i].tip == "float" ||
          var [i].tip == "char" ||
          var [i].tip == "bool" ||
          var [i].tip == "string")) {
        outFile << ",   VALUE: " << "EMPTY";
      }

      outFile << "\n";
    }

    if (nume == "Program")
      cnt -= 5;
    // Afișare scope-uri copil
    for (int i = 0; i < tabla.size(); i++) {
      tabla[i].second -> print(outFile, cnt + 5);
      outFile << "\n";
      // Recursivitate cu nivel de indentare crescut
    }
  }

};