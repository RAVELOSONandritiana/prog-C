#include <stdio.h>
#include <stdlib.h>
#define shut system("cls");
int tailleTriangle(int n);
int remplirTriangle(int **tab,int taille);

int Pascal(){

    int **tab;
    int n=0;
    char choix;

re:;
    printf("\t\t\t\t\t==================\n"
           "\t\t\t\t\tTriangle de Pascal\n"
           "\t\t\t\t\t==================\n\n");
    printf("[1] En afficher\n");
    printf("[2] Retour\n\n");

    printf("Entrer votre choix : ");
    do{
        choix=getchar();
    }while(choix == '\n' || choix == 32);

    switch(choix)
    {
        case '1':
        {
            n=tailleTriangle(n);
            tab=(int **)calloc(sizeof(int *),n);
            for(int i=0;i<n;i++){
                *(tab+i)=(int *)calloc(sizeof(int),n);
            }
            remplirTriangle(tab,n);
            goto re;
        }
        case '2':
        {
            shut
            goto q;
        }
        default :
        {
            shut
            goto re;
        }
}
q:;
    return 0;
}
int tailleTriangle(int n){

    printf("Entrer la taille : ");
    scanf("%d",&n);

    return n;
}
int remplirTriangle(int **tab,int taille){

        for(int i=0;i<taille;i++)
        {
            for(int j=0;j<taille;j++)
            {
                tab[i][0]=1;
                if (j == i)
                tab[i][j]=1;
                else if(i>0 && j>0)
                    tab[i][j]=tab[i-1][j-1]+tab[i-1][j];
                if(tab[i][j]!=0)
                printf("%d\t",tab[i][j]);
            }
            printf("\n");
            usleep(30000);
        }
}
