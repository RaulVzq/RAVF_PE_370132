//RAUL ARAM VAZQUEZ FIGUEROA-370132-18/09/2023
//1.- PROGRAMA QUE PREGUNTE LA CANTIDAD DE VECES QUE DESEA QUE SE REALICE EL PROGRAMA DE FIBONACCI
//2.- PROGRAMA QUE PIDA UN NÚMERO Y DESPLEGAR LA SALIDA DE FACTORIAL DE UN NÚMERO DADO.
//3.- PROGRAMA QUE PIDA UN NÚMERO Y DESPLEGAR LA CANTIDAD DE DÍGITOS QUE TIENE EL NÚMERO.
#include<stdio.h>
void Fibonacci_For()
{
    int i, numero, num1=0, num2=1, num3=1;
    printf("DIGITE EL NUMERO DE REPETICIONES PARA EL EJERCICIO: ");
    scanf("%i",&numero);
    
    for(i=1;i<=numero;i++)
    {
        num3=num1+num2;
        num1=num2;
        num2=num3;
        
        printf("%i,",num1);
    } 
}
void Fibonacci_While()
{
    int num1=0, num2=1, num3=1, i=1, numero;
    printf("INGRESE EL NUMERO DE REPETICIONES PARA EL EJERCICIO: ");
    scanf("%i",&numero);
    while(i<=numero)
    {
        num3=num1+num2;
        num1=num2;
        num2=num3;
        i++;
        printf("%i,",num1);
    } 
}
void Fibonacci_Do_While()
{
    int num1=0, num2=1, num3=1, i=1, numero;
    printf("INGRESE EL NUMERO DE REPETICIONES PARA EL EJERCICIO: ");
    scanf("%i",&numero);
    do
    {
        num3=num1+num2;
        num1=num2;
        num2=num3;
        i++;
        printf("%i,",num1);
    }while(i<=numero);
}

void Factorial_For()
{
    int i, num, fact=1;
    printf("DIGITE EL NUMERO PARA HALLAR SU FACTORIAL: ");
    scanf("%i",&num);
    
    for(i=1;i<=num;i++)
    {
        fact*=i;
    }
    printf("EL FACTORIAL DEL NUMERO DADO ES: %i",fact);
    
}
void Factorial_While()
{
    int num, fact=1, i=1;
    printf("DIGITE EL NUMERO PARA HALLAR SU FACTORIAL: ");
    scanf("%d",&num);
    while(i<=num)
    {
        fact*=i;
        i++;
    }
    printf("EL FACTORIAL DEL NUMERO DADO ES: %d",fact);
}
void Factorial_Do_While()
{
    int num, fact=1, i=1;
    printf("DIGITE EL NUMERO PARA HALLAR SU FACTORIAL: ");
    scanf("%d",&num);
    do
    {
        fact*=i;
        i++;
    }while(i<=num);
    printf("EL FACTORIAL DEL NUMERO DADO ES: %d",fact);
}
void Numero_De_Digitos_For()
{
    int num, i;
    printf("INGRESE UN NUMERO: ");
    scanf("%i",&num);
    for(i=1;num>=10;i++)
    {
        num=num/10;
    }
     printf("CANTIDAD DE CIFRAS: %i",i);
}
void Numero_De_Digitos_While()
{
    int num, cifras=1;
    printf("INGRESE UN NUMERO: ");
    scanf("%d",&num);
    while(num>=10)
    {
        num=num/10;
        cifras ++;
    }
    printf("CANTIDAD DE CIFRAS: %d", cifras);
}
void Numero_De_Digitos_Do_While()
{
    int num, cifras=1;
    printf("INGRESE UN NUMERO: ");
    scanf("%d",&num);
    do
    {
        num=num/10;
        cifras ++;
    }while(num>=10);
    printf("CANTIDAD DE CIFRAS: %d", cifras);
}

void Menu_For()
{
    int opc;
    printf("******MENU(FOR)******\n");
    printf("INGRESE UNA OPCION: ");
    printf("\n1.FIBONACCI: \n2.FACTORIAL: \n3.NUMERO DE DIGITOS: ");
    scanf("%d",&opc);
    switch(opc)
    {
        case 1:
        {
            Fibonacci_For();
        }
        break;
        case 2:
        {
            Factorial_For();
        }
        break;
        case 3:
        {
            Numero_De_Digitos_For();
        }
        break;
        default:
        printf("ESCOJA UNA OPCION VALIDA");
    }

}

void Menu_While()
{
    int opc;
    printf("*******MENU(WHILE)******");
    printf("INGRESE UNA OPCION: ");
    printf("\n1.FIBONACCI: \n2.FACTORIAL:  \n3.NUMERO DE DIGITOS: ");
    scanf("%d",&opc);
    switch(opc)
    {
        case 1:
        {
            Fibonacci_While();
        }
        break;
        case 2:
        {
            Factorial_While();
        }
        break;
        case 3:
        {
            Numero_De_Digitos_While();
        }
        break;
        default:
        printf("ESCOJA UNA OPCION VALIDA");
    }
}

void Menu_Do_While()
{
    int opc;
    printf("*******MENU(DO WHILE)******");
    printf("INGRESE UNA OPCION: ");
    printf("\n1.FIBONACCI: \n2.FACTORIAL:  \n3.NUMERO DE DIGITOS: ");
    scanf("%d",&opc);
    switch(opc)
    {
        case 1:
        {
            Fibonacci_Do_While();
        }
        break;
        case 2:
        {
            Factorial_Do_While();
        }
        break;
        case 3:
        {
            Numero_De_Digitos_Do_While();
        }
        break;
        default:
        printf("ESCOJA UNA OPCION VALIDA");

    }
}

int main()
{
    int opc;
    printf("******MENU******\n");
    printf("ESCOJA EL CICLO DE SU PREFERENCIA: ");
    printf("\n1.FOR: \n2.WHILE: \n3.DO_WHILE: ");
    scanf("%d",&opc);
    switch(opc)
    {
        case 1:
        {
            Menu_For();
        }
        break;
        case 2:
        {
            Menu_While();
        }
        break;
        case 3:
        {
            Menu_Do_While();
        }
        break;
        default:
        printf("ESCOJA UNA OPCION VALIDA");
    }
return 0;   
}
