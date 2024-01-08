#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
void description();
int collect(int nombre);
void travail(int nombre,int diviseur,int quotient);
int main(){
    int nombre=0;           //le nombre a afficher le decomposition
    int diviseur=0;         //qui sera le diviseur et doit etrer premier
    int quotient=0;         //pour stocker le nombre suivant et a permuter avec nombre apres obtention

    description();
//obtention du nombre a decomposer
while(1){
    nombre = collect(nombre);
    travail(nombre,diviseur,quotient);
}


    return 0;
}
void description(){
    printf("Montrons la decomposition d'un nombre\n");
    printf("Appuyer sur une touche d uclavier quand vous serez pret\n");
   // getch();
}
//la fonction pour obtenir le nombre a decomposer
int collect(int nombre){
    printf("Entrer le nombre (0 pour quitter): ");
    scanf("%d",&nombre);
        if(nombre == 0)
            exit(2);
    return nombre;
}

void travail(int nombre,int diviseur,int quotient){
    char stock[200];            //pour stocker afin de compter
    int t=0;
    
    do{
        diviseur=2;
        while(nombre%diviseur!=0)
        {
            diviseur++;
        }
        printf("%d",nombre);
//calcul d'espace
        sprintf(stock,"%d",nombre);
        t=strlen(stock);
//boucle pour mettre les espaces afin de les mettre bien alignes
        for(int i=0;i<=(7-t);i++)
        {
            printf(" ");
        }
        printf("| %d\n",diviseur);
            sleep(1);
        quotient=nombre/diviseur;
        nombre=quotient;

    }while(quotient!=1);
//compter ihany
        sprintf(stock,"%d",nombre);
        t=strlen(stock);

        printf("%d",nombre);
        for(int i=0;i<=(7-t);i++)
        {
            printf(" ");
        }
        printf("|\n");
}
