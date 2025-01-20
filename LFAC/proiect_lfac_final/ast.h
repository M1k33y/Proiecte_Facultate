#include <string>

#include <iostream>

#include <sstream>

#include <algorithm>

using namespace std;
extern int yylineno;

class nod {
  public: string scop = "default";
  string tip = "string";
  string value = "";
};

class AST {

  public: string tip = "";
  nod info;
  AST * st;
  AST * dr;

  AST(char * scop = strdup(""), char * tip = strdup(""), char * value = strdup(""), AST * st = nullptr, AST * dr = nullptr) {
    info.scop = scop;
    info.tip = tip;
    info.value = value;
    this -> st = st;
    this -> dr = dr;
  }

  nod compute() {

    if (info.value.size() == 0) {
      if(info.scop == "default") {
        if ( info.tip == "int")
          info.value = "0";
        else if (info.tip == "float")
          info.value  = "0.0";
        else if (st -> info.tip == "bool")
          info.value  = "false";

      }
      return info;
    }

    string t_st;
    string t_dr;
    if (st != nullptr && dr != nullptr) {
      string t_st = st -> arbType();
      string t_dr = dr -> arbType();

      if (t_st == "" && st -> info.scop == "default")
        t_st = t_dr;
      else if (t_dr == "" && dr -> info.scop == "default")
        t_dr = t_st;

    }
    if (st != nullptr && dr != nullptr && t_st == t_dr) {

      nod stRes = st -> compute();
      nod drRes = dr -> compute();
      nod res;

      string aux_st = stRes.value;
      string aux_dr = drRes.value;

      if (st -> info.scop == "default") {
        if (st -> info.tip == "int")
          aux_st = "0";
        else if (st -> info.tip == "float")
          aux_st = "0.0";
        else if (st -> info.tip == "bool")
          aux_st = "false";
      }

      if (dr -> info.scop == "default") {
        if (dr -> info.tip == "int")
          aux_dr = "0";
        else if (dr -> info.tip == "float")
          aux_dr = "0.0";
        else if (dr -> info.tip == "bool")
          aux_dr = "false";
      }

      if (info.scop == "expr aritm") {
        if (st -> info.tip == "int") {
          res.tip = "int";
          int number;
          if (info.value == "+") {
            res.value = to_string(stoi(aux_st) + stoi(aux_dr));

          } else if (info.value == "-") {
            res.value = to_string(stoi(aux_st) - stoi(aux_dr));
          } else if (info.value == "*") {
            res.value = to_string(stoi(aux_st) * stoi(aux_dr));
          } else if (info.value == "/") {
            res.value = to_string(stoi(aux_st) / stoi(aux_dr));
          } else if (info.value == "%") {
            res.value = to_string(stoi(aux_st) % stoi(aux_dr));
          }
        } else if (st -> info.tip == "float") {
          res.tip = "float";
          int number;
          if (info.value == "+") {
            res.value = to_string(stof(aux_st) + stof(aux_dr));

          } else if (info.value == "-") {
            res.value = to_string(stof(aux_st) - stof(aux_dr));

          } else if (info.value == "*") {
            res.value = to_string(stof(aux_st) * stof(aux_dr));

          } else if (info.value == "/") {
            res.value = to_string(stof(aux_st) / stof(aux_dr));

          } else if (info.value == "%") {
            res.value = to_string(stof(aux_st) * (-1) + stof(aux_dr));

          }
        } else if (st -> info.tip == "bool") {
          res.tip = "bool";
          int number;
          if (info.value == "+") {
            res.value = "true";

          } else if (info.value == "-") {
            res.value = "false";

          } else {
            res.value = "false";

          }
        } else if (st -> info.tip == "char") {
          res.tip = "char";
          int number;
          if (info.value == "+") {
            res.value = aux_st;

          } else if (info.value == "-") {
            res.value = aux_dr;

          } else if (info.value == "*") {
            res.value = aux_st;

          } else if (info.value == "/") {
            res.value = aux_dr;

          } else if (info.value == "%") {
            res.value = aux_st;

          }
        } else if (st -> info.tip == "string") {
          res.tip = "string";
          int number;
          if (info.value == "+") {
            res.value = aux_st + aux_dr;

          } else if (info.value == "-") {
            res.value = aux_dr;

          } else if (info.value == "*") {
            res.value = aux_dr + aux_st + aux_dr;

          } else if (info.value == "/") {
            res.value = aux_st + aux_dr + aux_st;

          } else if (info.value == "%") {
            res.value = aux_dr + aux_st;

          }
        }
        return res;
      } else if (info.scop == "expr comp")

      {
        res.tip = "bool";
        bool rez = false;

        if (st -> info.tip == "int") {

          if (info.value == ">") {
            rez = stoi(aux_st) > stoi(aux_dr);
          }
          if (info.value == "<") {
            rez = stoi(aux_st) < stoi(aux_dr);

          } else if (info.value == ">=") {
            rez = stoi(aux_st) >= stoi(aux_dr);

          } else if (info.value == "<=") {
            rez = stoi(aux_st) <= stoi(aux_dr);

          } else if (info.value == "==") {
            rez = stoi(aux_st) == stoi(aux_dr);

          } else if (info.value == "!=") {
            rez = stoi(aux_st) != stoi(aux_dr);

          }
        } else if (st -> info.tip == "float") {

          if (info.value == ">") {
            rez = stof(aux_st) > stof(aux_dr);
          }
          if (info.value == "<") {
            rez = stof(aux_st) < stof(aux_dr);

          } else if (info.value == ">=") {
            rez = stof(aux_st) >= stof(aux_dr);

          } else if (info.value == "<=") {
            rez = stof(aux_st) <= stof(aux_dr);

          } else if (info.value == "==") {
            rez = stof(aux_st) == stof(aux_dr);

          } else if (info.value == "!=") {
            rez = stof(aux_st) != stof(aux_dr);

          }
        } else if (st -> info.tip == "char" || st -> info.tip == "string") {
          res.tip = st -> info.tip;
          int number;
          if (info.value == ">") {
            rez = aux_st > aux_dr;
          }
          if (info.value == "<") {
            rez = aux_st < aux_dr;

          } else if (info.value == ">=") {
            rez = aux_st >= aux_dr;

          } else if (info.value == "<=") {
            rez = aux_st <= aux_dr;

          } else if (info.value == "==") {
            rez = aux_st == aux_dr;

          } else if (info.value == "!=") {
            rez = aux_st != aux_dr;

          }
        }
        if (rez == false)
          res.value = "false";
        else
          res.value = "true";

        return res;

      } else if (info.scop == "expr bool") {
        bool rez = true;
        if (info.value == "||") {
          if (aux_st == "true" || aux_dr == "true")
            rez = true;
          else
            rez = false;

        } else if (info.value == "&&") {
          if (aux_st == "true" && aux_dr == "true")
            rez = true;
          else
            rez = false;

        }

        if (rez == false)
          res.value = "false";
        else
          res.value = "true";
      }
      return res;

    } else if (st && info.value == "!") {
      nod res;
      string aux_st = st -> compute().value;

      if (st -> info.tip == "int") {
        res.value = to_string(stoi(aux_st) * (-1));

      } else if (st -> info.tip == "float") {
        res.value = to_string(stof(aux_st) * (-1));

      } else if (st -> info.tip == "string") {
        reverse(aux_st.begin(), aux_st.end());
        res.value = aux_st;
      } else if (st -> info.tip == "bool") {
        if (aux_st == "true")
          res.value = "false";
        else
          res.value = "true";
      } else if (st -> info.tip == "char")
        res.value = "";
      return res;

    } else if (st && info.value == "-") {
      nod res;
      string aux_st = st -> compute().value;

      if (st -> info.tip == "int") {
        res.value = to_string(stoi(aux_st) * (-1));

      } else if (st -> info.tip == "float") {
        res.value = to_string(stof(aux_st) * (-1));

      } else if (st -> info.tip == "string") {
        reverse(aux_st.begin(), aux_st.end());
        res.value = aux_st;
      } else if (st -> info.tip == "bool") {
        if (aux_st == "true")
          res.value = "false";
        else
          res.value = "true";
      } else if (st -> info.tip == "char")
        res.value = "";
      return res;

    } else {
      return info;
    }
  }

  string arbType() {
    if (!info.value.empty()) {
      if (st != nullptr && dr != nullptr) {
        string stType = st -> arbType();
        string drType = dr -> arbType();

        if (!stType.empty() && !drType.empty()) {
          if (stType == drType) {
            if (info.scop == "expr aritm") {
              this -> info.tip = stType;
              return stType;
            } else if (info.scop == "expr comp" || info.scop == "expr bool") {
              this -> info.tip = "bool";
              return "bool";
            }
          } else {
            cout << "Warning (linia " << yylineno << "): " << info.value <<
              " - Tipurile operandilor (" << stType << " și " << drType <<
              ") nu sunt compatibile.\n";
            return "Error";
          }
        }
      } else if (st != nullptr) {
        return st -> arbType();
      }
    }

    if (info.tip == "false" || info.tip == "true")
      return "bool";
    else
      return info.tip;
  }

  void print() {

    if (st != nullptr)
      this -> st -> print();

    if (info.value != "") {
      cout << info.value << " ";
    }

    if (dr != nullptr)
      this -> dr -> print();
  }
};