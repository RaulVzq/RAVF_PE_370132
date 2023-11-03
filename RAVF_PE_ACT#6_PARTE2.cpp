// RAUL ARAM VAZQUEZ FIGUEROA--370132--19/09/2023
// 1.- El profesor de una materia desea conocer la cantidad de sus alumnos que no tienen derecho al examen de nivelación.
// 2.- Realiza una función en C que imprima las tablas de multiplicar del 1 al 10.
// 3.-Realizar función en C para un programa que sirva para leer n cantidad de números dentro de un rango dado por el usuario, desplegar la suma de los números y la media aritmética de los números válidos dentro del rango.
// 4.-Peso de cada pasajero en la embarcacion finistierra.
// 5.-función donde basada en sus 3 exámenes parciales calcular el promedio y basado en su promedio final, se deberá enviar mensaje al alumno de repetir materia, aprobado o baja temporal.

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
void Menu();
void Examen();
void Tablas();
void Media_Aritmetica();
void Embarcación();
void Baja();
int main()
{
    Menu();
    return 0;
}
void Menu(void)
{
    int opc;
    printf("******MENU****** \n");
    printf("1.-DERECHO A EXAMEN \n");
    printf("2.-TABLAS DE MULTIPLICAR \n");
    printf("3.-MEDIA ARITMETICA \n");
    printf("4._EMBARCACION FINISTIERRA \n");
    printf("5.-PROMEDIO FINAL\n");
    scanf("%d", &opc);
    switch (opc)
    {
    case 1:
        Examen();
        break;
    case 2:
        Tablas();
        break;
    case 3:
        Media_Aritmetica();
        break;
    case 4:
        Embarcación();
        break;
    case 5:
        Baja();
        break;
    default:
        printf("ERROR EN OPCION DE MENU");
        break;
    }
}
void Examen()
{
    int sd, i, unid1, unid2, unid3, unid4, unid5, prom; // sd = Sin Derecho
    sd = 0;
    for (i = 0; i < 40; i++)
    {
        printf("ALUMNO %d\n", i + 1);
        printf("CALIFICACION DE UNIDAD 1: \n");
        scanf("%d", &unid1);
        printf("CALIFICACION DE UNIDAD 2: \n");
        scanf("%d", &unid2);
        printf("CALIFICACION DE UNIDAD 3: \n");
        scanf("%d", &unid3);
        printf("CALIFICACION DE UNIDAD 4: \n");
        scanf("%d", &unid4);
        printf("CALIFICACION DE UNIDAD 5: \n");
        scanf("%d", &unid5);
        prom = (unid1 + unid2 + unid3 + unid4 + unid5) / 5;
        if (prom < 50)
        {
            sd = sd + 1;
        }
    }
    printf("%d SON LOS ALUMNOS SIN DERECHO A EXAMEN DE NIVELACION", sd);
}
void Tablas()
{
    int tab, i, j, res, cont;
    for (tab = 1; tab <= 10; tab++)
    {
        clearerr_s;
        for (i = 1; i <= 10; i++)
        {
            res = tab * i;
            printf("%d * %d = %d\n", tab, i, res);
        }
        printf("OPRIMA UNA TECLA PARA CONTINUAR\n");
        getch();
    }
}
void Media_Aritmetica()
{
    int i, ranmen, ranmay, num; // ranmen = Rango menor. ranmay = Rango mayor
    float med, suma;
    printf("\nINGRESA EL RANGO DE LOS NUMEROS QUE DESEAS\nDE:");
    scanf("%d", &ranmen);
    printf("\na:");
    scanf("%d", &ranmay);
    printf("\nOPRIMA LA TECLA 0 PARA TERMINAR \n");
    num = 1;
    suma = 0;
    i = 0;
    med = 0;
    while (num != 0)
    {
        printf("INGRESA UN NUMERO DENTRO DEL RANGO DE %d A %d \n", ranmen, ranmay);
        scanf("%d", &num);
        if (num >= ranmen && num <= ranmay)
        {
            suma = suma + num;
            i += 1;
        }
    }
    med = suma / i;
    printf("LA SUMA DE LOS NUMEROS ES: %.2f Y LA MEDIA ARITMETICA ES: %.2f ", suma, med);
}
void Embarcación()
{
    int peso, pas, i;
    float prom, sobrep;
    sobrep = 700 + (700 * .15);
    peso = 0;
    i = 0;
    while (peso <= 700)
    {
        printf("PASAJERO %d DEME SU PESO: ", i + 1);
        scanf("%d", &pas);
        peso = peso + pas;
        i++;
        if (i == 10)
        {
            break;
        }
    }
    if (i == 10)
    {
        printf("MAXIMA CAPACIDAD (10 PASAJEROS)\n");
        prom = peso / i;
        printf("PROMEDIO DE PESO DE LOS TURISTAS %.2f", prom);
    }
    else
    {
        if (peso > sobrep)
        {
            printf("LA EMBARCACION A SUPERADO EL LIMITE DE SOBREPESO\n");
        }
        else
        {
            printf("PESO LIMITE ALCANZADO. NO ABORDAR MAS TURISTAS\n");
            prom = peso / i;
            printf("PROMEDIO DE PESO DE LOS TURISTAS: %.2f", prom);
        }
    }
}
void Baja()
{
    int parc1, parc2, parc3, i;
    float prom;

    for (i = 0; i < 3; i++)
    {
        printf("INTENTOS DE CURSAR LA MATERIA: %d\n", i + 1);
        printf("CALIFICACION PARCIAL 1\n");
        scanf("%d", &parc1);
        printf("CALIFICACION PARCIAL 2\n");
        scanf("%d", &parc2);
        printf("CALIFICACION PARCIAL 3\n");
        scanf("%d", &parc3);
        prom = (parc1 + parc2 + parc3) / 3;
        if (prom >= 60)
        {
            break;
        }
        else
        {
            if (i < 2)
            {
                printf("RECURSAR MATERIA\n");
            }
        }
    }
    if (i == 3)
    {
        printf("EXCEDISTE EL INTENTO DE RECURSAMIENTOS.BAJA TEMPORAL");
    }
    else
    {
        printf("HAS APROBADO");
    }
}
