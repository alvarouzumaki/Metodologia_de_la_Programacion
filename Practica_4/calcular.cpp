#include <iostream>
#include "matriz_operaciones.h"
#include "matriz_bit.h"
#include "string.h"
using namespace std;

int main(int argc, char* argv[]){
   MatrizBit m1, m2, res;
   bool exito = false;

   if(!strcmp(argv[1], "NOT") || !strcmp(argv[1], "TRS")){
      if(argc == 3){
         Leer(argv[2], m1);
         exito = true;
      }
      else{
         Leer(cin, m1);
         exito = true;
      }
   }

   else if(!strcmp(argv[1], "AND") || !strcmp(argv[1], "OR")){
      if (argc == 3){
         Leer(argv[2], m2) && Leer(cin, m1);
         exito = true;
      }
      else if (argc == 4){
         Leer(argv[2], m1) && Leer(argv[3], m2);
         exito = true;
      }
      else{
         Leer(cin, m1) && Leer(cin, m2);
         exito = true;
      }
   }

   else{
      cout << endl << "Error: No se ha podido realizar la lectura con exito." << endl;
   }

   if(exito){
      if(!strcmp(argv[1], "AND")){
         And(res, m1, m2);
      }
      else if (!strcmp(argv[1], "OR")){
         Or(res, m1, m2);
      }
      else if(!strcmp(argv[1], "NOT")){
         Not(res, m1);
      }
      else if(!strcmp(argv[1], "TRS")){
         Traspuesta(res, m1);
      }
      else{
         cout << endl << "Error: Operacion no valida, intentelo de nuevo." << endl;
      }
      Escribir(cout, res);
   }
}