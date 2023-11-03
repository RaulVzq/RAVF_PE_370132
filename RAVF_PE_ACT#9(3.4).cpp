// ///////////////////////////////////////////////////////////////// ///
// RAUL ARAM VAZQUEZ FIGUEROA   MATRICULA:370132                      //
// 23-10-2023                                                         //
// ACTIVIDAD 9(3/4) "CURP"                                            //
// Realiza un programa que sirva para generar el CURP de una persona. //
// ///////////////////////////////////////////////////////////////// ///

// ///////////////////////////////
// ////////// LIBRERIAS //////////
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>

/// ///////////////////////////////////////////// //
// ////////// PROTOTIPOS DE FUNCIONES ////////// //
void CURP(void);
void MyMenu(void);

/// /////////////////////////////////////////////// //
// ////////// FUNCION PRINCIPAL (int main) /////// //
int main(void)
{
    MyMenu();
    return 0;
}

/// /////////////////////////////// //
// ////////// FUNCION MENU /////// //
void MyMenu(void)
{
    int opc;

    do
    {
        system("cls");
        printf("* * * * * M E N U * * * * *");
        printf("\n\n1.- GENERA CURP");
        printf("\n\n0.- SALIR");
        printf("\n\n\nESCOGE UNA OPCION: ");
        scanf("%d", &opc);

        switch (opc)
        {
        case 1:
            CURP();
            break;
        }

    } while (opc != 0);
}

/// ///////////////////////////////////////////// //
// ///////// FUNCION QUE GENERA EL CURP //////// //
void CURP(void)
{
    char Nombre1[20], Nombre2[20], Apellido1[20], Apellido2[20], Ano[3], Mes[3], Dia[3], Sexo[2], Entidad[3];
    int x, opc, num1, num2, Nomcomun;
    char primvocApellido, primconsApellido, primconsApellido2, primconsNombre1, primconsNombre2;

    printf("LOS NOMBRES Y APELLIDOS NO DEBEN LLEVAR ACENTOS\n");
    printf("\nCuantos Nombres tienes?\n");
    printf("\n1) Unicamente Uno\n");
    printf("2) Mas de Uno");
    scanf("%d", &opc);
    switch (opc)
    {
    case 1:
        printf("Dame tu Nombre: \n");
        scanf("%s", &Nombre1);
        strupr(Nombre1);
        break;
    case 2:
        printf("Dame tu primer Nombre: \n");
        scanf("%s", &Nombre1);
        strupr(Nombre1);
        if (strcmp(Nombre1, "JOSE") == 0)
        {
            printf("Dame tu segundo Nombre: \n");
            scanf("%s", &Nombre2);
            strupr(Nombre2);
            Nomcomun = 1;
        }
        else if (strcmp(Nombre1, "BRENDA") == 0)
        {
            printf("Dame tu segundo Nombre: \n");
            scanf("%s", &Nombre2);
            strupr(Nombre2);
            Nomcomun = 1;
        }
        break;
    }
    printf("Apellido Paterno: \n");
    scanf("%s", &Apellido1);
    strupr(Apellido1);
    printf("Apellido Materno: \n");
    scanf("%s", &Apellido2);
    strupr(Apellido2);
    printf("Anio de Nacimiento (aa) Ej: 2001 --> 01 : \n");
    scanf("%s", &Ano);
    printf("Mes de Nacimiento (mm): \n");
    scanf("%s", &Mes);
    printf("Dia de Nacimiento (dd): \n");
    scanf("%s", &Dia);
    printf("Sexo (M-H): \n");
    scanf("%s", &Sexo);
    strupr(Sexo);

    printf("Entidad Federativa donde naciste:\nAguascalientes (AS) \nBaja California (BC) \nBaja California Sur (BS)\n");
    printf("Campeche (CC) \nCoahuila (CL) \nColima (CM) \nChiapas (CS) \nChihuahua (CH)\n");
    printf("Distrito Federal (DF) \nDurango (DG) \nGuanajuato (GT) \nGuerrero (GR)\n");
    printf("Hidalgo (HG) \nJalisco (JC) \nMexico (MC) \nMichoacan (MN) \nMorelos (MS)\n");
    printf("Nayarit (NT) \nNuevo Leon (NL) \nOaxaca (OC) \nPuebla (PL) \nQuerÈtaro (QT)\n");
    printf("Quintana Roo (QR) \nSan Luis Potosi (SP) \nSinaloa (SL) \nSonora (SR)\n");
    printf("Tabasco (TC) \nTamaulipas (TS) \nTlaxcala (TL) \nVeracruz (VZ)\n");
    printf("Yucatan (YN) \nZacatecas (ZS) \nNacido en el extranjero NE\n");
    printf("Opcion: ");
    scanf("%s", &Entidad);

    for (x = 1; x <= strlen(Apellido1); x++)
        if (Apellido1[x] == 'A' || Apellido1[x] == 'E' || Apellido1[x] == 'I' || Apellido1[x] == 'O' || Apellido1[x] == 'U')
            break;

    primvocApellido = Apellido1[x];
    for (x = 1; x <= strlen(Apellido1); x++)
        if (Apellido1[x] != 'A' && Apellido1[x] != 'E' && Apellido1[x] != 'I' && Apellido1[x] != 'O' && Apellido1[x] != 'U')
            break;

    primconsApellido = Apellido1[x];
    for (x = 1; x <= strlen(Apellido2); x++)
        if (Apellido2[x] != 'A' && Apellido2[x] != 'E' && Apellido2[x] != 'I' && Apellido2[x] != 'O' && Apellido2[x] != 'U')
            break;

    primconsApellido2 = Apellido2[x];
    for (x = 1; x <= strlen(Nombre1); x++)
        if (Nombre1[x] != 'A' && Nombre1[x] != 'E' && Nombre1[x] != 'I' && Nombre1[x] != 'O' && Nombre1[x] != 'U')
            break;

    primconsNombre1 = Nombre1[x];
    for (x = 1; x <= strlen(Nombre2); x++)
        if (Nombre2[x] != 'A' && Nombre2[x] != 'E' && Nombre2[x] != 'I' && Nombre2[x] != 'O' && Nombre2[x] != 'U')
            break;

    primconsNombre2 = Nombre2[x];
    Entidad[0] = toupper(Entidad[0]);
    Entidad[1] = toupper(Entidad[1]);
    srand(time(NULL));
    num1 = rand() % 8 + 1;
    num2 = rand() % 8 + 1;
    printf("\nTu CURP es: ");
    printf("%c%c%c", Apellido1[0], primvocApellido, Apellido2[0]);
    if (Nomcomun == 1)
        printf("%c", Nombre2[0]);
    else
        printf("%c", Nombre1[0]);
    printf("%s%s%s%s%s%c%c", Ano, Mes, Dia, Sexo, Entidad, primconsApellido, primconsApellido2);
    if (Nomcomun == 1)
        printf("%c%d%d", primconsNombre2, num1, num2);
    else
        printf("%c%d%d", primconsNombre1, num1, num2);

    getch();
}