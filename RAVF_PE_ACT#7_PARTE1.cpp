// RAUL ARAM VAZQUEZ FIGUEROA
// 370132
// 25/09/2023
// 1.-LEER UNA CADENA CON EL NOMBRE DE "ENSENADA" Y DESPLEGARLA DE DIVERSAS MANERAS.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Cadena_Ensenada1()
{
    char cad[9] = {'E', 'N', 'S', 'E', 'N', 'A', 'D', 'A', '\0'};
    printf("\nSALIDA 1: %s", cad);
    printf("\n");
}
void Cadena_Ensenada2()
{
    char cad[9] = {'A', 'D', 'A', 'N', 'E', 'S', 'N', 'E', '\0'};
    printf("\nSALIDA 2: %s", cad);
    printf("\n");
}
void Cadena_Ensenada3()
{
    char cad[9] = {'E', 'N', 'S', 'E', 'N', 'A', 'D', 'A', '\0'};
    int i, tamcad = strlen(cad);
    for (i = 0; i < tamcad; i++)
    {
        char cad2 = cad[i];
        printf("\nSALIDA 3: %c", cad2);
    }
    printf("\n");
}
void Cadena_Ensenada4()
{
    char cad[9] = {'A', 'D', 'A', 'N', 'E', 'S', 'N', 'E', '\0'};
    int i, tamcad = strlen(cad);
    for (i = 0; i < tamcad; i++)
    {
        char cad2 = cad[i];
        printf("\nSALIDA 4: %c", cad2);
    }
    printf("\n");
}
void Cadena_Ensenada5()
{
    char cad[9] = {'E', 'N', 'S', 'E', 'N', 'A', 'D', 'A', '\0'};
    int i, tamcad = strlen(cad);
    for (i = 0; i < tamcad; i++)
    {
        printf("\nSALIDA 5: %s", cad + i);
    }
    printf("\n");
}
void Cadena_Ensenada6()
{
    char cad[9] = {'A', 'D', 'A', 'N', 'E', 'S', 'N', 'E', '\0'};
    int i, tamcad = strlen(cad);
    for (i = 0; i < tamcad; i++)
    {
        printf("\nSALIDA 6: %s", cad + i);
    }
}
int main()
{
    Cadena_Ensenada1();

    Cadena_Ensenada2();

    Cadena_Ensenada3();

    Cadena_Ensenada4();

    Cadena_Ensenada5();

    Cadena_Ensenada6();

    return 0;
}