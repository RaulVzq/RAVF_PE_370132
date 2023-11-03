// RAUL ARAM VAZQUEZ FIGUEROA
// 370132
// 25/09/2023
// 1.- Función que reciba como parámetro una cadena y la convierta a MAYUSCULAS
// 2.- Función Que reciba como parámetro una cadena y la convierta a MINUSCULAS
// 3.- Función que reciba como parámetro una cadena y la convierta a CAPITAL
// 4.-Función que reciba como parámetro una cadena y retorne la cantidad de caracteres que tiene la cadena.
// 5.-Función que reciba como parámetro una cadena y retorne una cadena con sus caracteres acomodados de forma inversa (al reves)
// 6.-Función que reciba como parámetro una cadena y genere una nueva cadena basada en la origina pero sin espacios.
// 7.-Función que sirva para leer una cadena y solo permita caracteres alfabéticos (A...Z) y el espacio, donde una cadena no puede comenzar o terminar con espacio, no debe tener dos espacios seguidos. retornar la cadena ya sea como parámetro o variable.
// 8.-Función que reciba como parámetro una cadena, y utilizando las funciones anteriores, imprima en MAYUSCULAS, MINUSCULAS , CAPITAL, SIN ESPACIOS, ALREVES la cadena original.
// 9.-Función que reciba como parámetro una cadena, y desplegar la leyenda si la cadena es un palíndromo SI o NO (VALIDADA AL 100% NO NUMEROS, NO DOBLES ESPACIOS Y SOLO MAYUSCULAS EN LA CADENA)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void Mayusculas()
{
   char cad[11] = {'H', 'o', 'L', 'a', ' ', 'M', 'u', 'N', 'd', 'O', '\0'};
   int i = 0;
   printf("\n1.-CADENA ORIGINAL: %s", cad);
   while (cad[i] != 0)
   {
      if (cad[i] >= 'a' && cad[i] <= 'z')
      {
         cad[i] = cad[i] - ('a' - 'A');
      }
      i++;
   }
   printf("\n1.-CADENA EN MAYUSCULAS: %s", cad);
   printf("\n");
}

void Minusculas()
{
   char cad[11] = {'H', 'o', 'L', 'a', ' ', 'M', 'u', 'N', 'd', 'O', '\0'};
   int i = 0;
   printf("\n2.-CADENA ORIGINAL: %s", cad);
   while (cad[i] != 0)
   {
      if (cad[i] >= 'A' && cad[i] <= 'Z')
      {
         cad[i] = cad[i] - ('A' - 'a');
      }
      i++;
   }
   printf("\n2.-CADENA EN MINUSCULAS: %s", cad);
printf("\n");
}

void Capital()
{
   char cad[11] = {'h', 'o', 'l', 'a', ' ', 'm', 'u', 'n', 'd', 'o', '\0'};
   int i = 0;
   printf("\n3.-LA CADENA ORIGINAL ES: %s", cad);
   while (cad[i] != 0)
   {
      if (cad[i] == 'h' || cad[i] == 'm')
      {
         cad[i] = cad[i] - ('a' - 'A');
      }
      i++;
   }
   printf("\n3.-LA CADENA EN CAPITAL ES: %s", cad);
   printf("\n");
}

void N_Caracteres()
{
   char cad[11] = {'H', 'O', 'L', 'A', ' ', 'M', 'U', 'N', 'D', 'O', '\0'};
   int tamcad = strlen(cad);
   printf("\n4.-CADENA ORIGINAL: %s", cad);
   printf("\n4.-LA CANTIDAD DE CARACTERES ES DE: %d", tamcad);
   printf("\n");
}

void C_Inversa()
{
   char cad[11] = {'H', 'O', 'L', 'A', ' ', 'M', 'U', 'N', 'D', 'O', '\0'};
   char inversa;
   int i, mitad, tamcad = strlen(cad);
   printf("\n5.-LA CADENA ORIGINAL ES: %s", cad);
   mitad = tamcad / 2;
   for (i = 0; i < mitad; i++)
   {
      inversa = cad[i];
      cad[i] = cad[tamcad - i - 1];
      cad[tamcad - i - 1] = inversa;
   }
   printf("\n5.-LA CADENA INVERTIDA ES: %s", cad);
   printf("\n");
}

void S_Espacios()
{
   char cad[11] = {'H', 'O', 'L', 'A', ' ', 'M', 'U', 'N', 'D', 'O', '\0'};
   int i, l = 0, tamcad = strlen(cad);
   printf("\n6.-CADENA ORIGINAL: %s", cad);
   while (cad[l] != '\0')
   {
      if (cad[l] == ' ')
      {
         for (i = l; i < tamcad; i++)
         {
            cad[i] = cad[i + 1];
         }
         tamcad--;
      }
      l++;
   }
   printf("\n6.-LA CADENA SIN ESPACIOS RESULTA ASI: %s", cad);
   printf("\n");
}

int main()
{
   Mayusculas();

   Minusculas();

   Capital();

   N_Caracteres();

   C_Inversa();

   S_Espacios();

   return 0;
}