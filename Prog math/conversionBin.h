#include <stdio.h>
#include <math.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#define shut system("cls");
void a();
int presentation(int nombre);
int hexa(int nombre);
int hexaInverse(int nombre);
int traitement(int nombre,int reste);
char choice(char *choix2);
/****************************************************************/
int conversion(){

    int nombre=0;
    int sortie=0;
    int reste=0;
    int base=0;
    char choix2[10];

    while(1){
d:;
    char choix=0;
    a();
    printf("[1]-Convertir un nombre en une base<10\n");
    printf("[2]-Convertir un nombre en hexadecimal\n");
    printf("[3]-Convertir un hexadecimal en nombre\n");
    printf("[4]-Retour\n\n");

    printf("entrer votre choix : ");
    do{
    choix=getchar();
    }while(choix == 32 || choix == '\n');
    printf("\n");
    switch(choix)
    {
        case '1':
        {
                nombre = presentation(nombre);
                traitement(nombre,reste);
                printf("\n");
                choice(choix2);
                if(strcmp(choix2,"non")==0)
                {
                    shut
                    goto d;
                }
        }
        case '2':
        {
                hexa(nombre);
                choice(choix2);
                if(strcmp(choix2,"non")==0)
                {
                    shut
                    goto d;
                }
        }
        case '3' :
        {
                hexaInverse(nombre);
                choice(choix2);
                if(strcmp(choix2,"non")==0){
                    shut
                    goto d;
                }
        }
        case '4':
            shut
            goto question;

    }
}
question:;
    return 0;
}

/****************************************************************/
int presentation(int nombre){

    printf("votre nombre    : ");
    scanf("%d",&nombre);

    return nombre;

}
/****************************************************************/
int traitement(int nombre,int reste){
    int base=0;
    static int q=0;
    int i=0;
    int somme=0;
    const int max=3,min=0;
    do{
    printf("Entrer la base  : ");
    scanf("%d",&base);
    }while(base<0 || base>9);
    do{
    reste=nombre%base;
    somme+=reste*pow(10,i);
    q=nombre/base;
    nombre=q;
    i++;
    }while(q!=0);
    printf("En base %d est : ",base);
    printf("%d\n",somme);
}
/****************************************************************/
void a(){

    printf("\t\t\t\t\t===================================\n"
           "\t\t\t\t\t       CONVERSION EN UNE BASE       \n"
           "\t\t\t\t\t===================================\n\n");
}
/****************************************************************/
int hexa(int nombre){
    const int max=3,min=0;
    printf("votre nombre   : ");
    scanf("%d",&nombre);
    printf("en hexadecimal : 0x%X\n\n",nombre);
}
/****************************************************************/
char choice(char *choix2){

    printf("Voulez-vous relancez[oui/non]?");
    scanf("%10s",choix2);
    printf("\n");
}
/****************************************************************/
int hexaInverse(int nombre){
    const int max=3,min=0;
    printf("l 'hexadecimal : ");
    scanf("%X",&nombre);
    printf("en entier      : %d\n\n",nombre);
}

