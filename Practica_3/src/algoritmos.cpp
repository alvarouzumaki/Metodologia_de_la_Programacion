#include "algoritmos.h"
#include "imagenES.h"

bool Revelar(const unsigned char buffer[], const int n_pixeles, char mensaje[], const int longitud_mensaje){
   bool revelada = true;
   unsigned char c;
   int bit = 0;

   if(longitud_mensaje <= (n_pixeles / 8) ){ 
      for(int i = 0; i < longitud_mensaje; ++i){
         for (int j = 0; j < 8; ++j){
            bit = buffer[ (i*8) + j] & 1;
            if (bit == 0){
               c = c << 1;
            }
            else{
               c= c << 1;
               c = c | 1;
            }
         }
         if (i < longitud_mensaje){
            mensaje[i] = c;
         }
      }
   }
   else{
      revelada = false;
   }

   return revelada;
}

bool Ocultar(const char mensaje[], unsigned char buffer[]){
   int i;
   for(i = 0; mensaje[i] != '\0'; i++){}

   int cont=0;
   for(int j = 0; j <= i; j++){
      for (int k = 7; k >= 0; k--){
         if((mensaje[j] & (1 << k)) != 0){
            buffer[cont] = buffer[cont] | 1;
         }
         else{
            buffer[cont] = buffer[cont] & (~1);
         }
         cont++;
      }
   } 

   return true; 
}