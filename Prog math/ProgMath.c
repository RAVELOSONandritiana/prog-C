#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <conio.h>
#include "conversionBin.h"
#include "TrianglePascal.h"
#define cadre printf("**********************************\n");
#define shut system("cls");
/*********************************************************************************/
void soratra();
char Introduction();
char dmdChoix(char choix);
void aide();
void choixEquation();
char dmdChoix2(char choix2);
void premierDegrer(float a,float b,float c,float x);
void secondDegrer(float a,float b,float c,float d,float x,float x1,float x2,float delta);
void equationDiophatienne(float a,float b,float c,float x,float y);
/*********************************************************************************/
int main(){

    char choix;                 //pour la premiere affichage
    char choix2;                //pour le choix dans le menu Equation
    float a=0,
          b=0,
          c=0,
          d=0,
          delta=0,
          x=0,
          y=0,
          x1=0,
          x2=0;
    int i=0;
    int nombre=0;
    char password[30];
    do{
    printf("Veuillez entrer la cle de license : ");
    scanf("%s",password);
        if(strcmp(password,"05/01/2023")!=0)
            i++;
        else if(strcmp(password,"05/01/2023")==0)
        {
            printf("Merci de m'avoir acheter\n");
            sleep(5);
            shut
            goto question;
        }
        if(i==4)
        {
            printf("Vous n'avez toujour pas saisie le bon cle\n");
            printf("Aurevoir et n'y tente meme pas sans la cle de licence\n");
            sleep(5);
            exit(1);
        }
    }while(i<5);
question:;
    //affiche les choix ainsi que retourne le choix
    Introduction();
    choix=dmdChoix(choix);
    //retourner le choix de l'utilisateur et traiter les donnees

    switch(choix)
    {
        case '1':
            //entrer dans le menu Equation,on va faire une fonction pour ca
question3:;                     //pour revenir au choix d'equation
            choixEquation();
            choix2=dmdChoix2(choix2);
                switch(choix2)
                {
                    case '1':
                        premierDegrer(a,b,c,x);
                        goto question3;
                    case '2':
                        secondDegrer(a,b,c,d,x,x1,x2,delta);
                        goto question3;
                    case '3':
                        equationDiophatienne(a,b,c,x,y);
                        goto question3;
                    case '4':
                        goto question;
                    default:
                        goto question3;
                }
        case '2':
            conversion();
            goto question;
        case '3':
            Pascal();
            goto question;
        case '4':
            //affiche l'aide
            aide();
            goto question;
        case '5':
            printf("Veuillez entrer la cle de licence (10 caracteres): ");
            scanf("%s",password);
            if(strcmp(password,"05/01/2023")==0)
            {
            printf("=========================================================================\n");
            printf("||NOM        : RAVELOSON                                               ||\n");
            printf("||PRENOM     : Andritiana Michel                                       ||\n");
            printf("||Age        : 17 ans                                                  ||\n");
            printf("||UNIVERSITE : Antananarivo dans la Mention Informatique et Technologie||\n");
            printf("||ANNEE      : Dimanche 07 Mai 2023                                    ||\n");
            printf("=========================================================================\n");
            getch();
            sleep(3);
            shut
            }
        else
        {
            shut
            goto question;
        }
            goto question;
        case '6':
            printf("Appuyer sur une touche si vous etes sure de vouloir quitter");
            getch();
            exit(1);
        default:
            goto question;

    }

    return 0;
}
/*******************************************************************/
char Introduction(){
    soratra();                                  //intro de EQUATION
    printf("[1] Entrer dans Equation\n"
           "[2] Entrer dans le monde du binaire\n"
           "[3] Triangle de Pascal\n"
           "[4] Aide\n"
           "[5] Voir la description du proprietaire\n"
           "[6] Quitter\n");

}
/*******************************************************************/
char dmdChoix(char choix){
    printf("\nVeuillez entrer votre choix : ");
    do{
    choix=getchar();
    }while(choix == '\n' || choix == 32);
    shut
    return choix;
}
/*******************************************************************/
void aide(){

    printf("Bienvenue dans notre menu d'aide\nCe programme sert a trouver les solutions d'une Equation\n"
    "Je vous le conseil pour corriger vos exercices pas pour les faire\n"
    "Il suffit de completer nos attentes pour qu'on puisse travailler pour vous\n");
    printf("Appuyer sur une touche du clacier pour continuer ");
   	getch();
    shut
}
/*******************************************************************/
void choixEquation(){
    soratra();
    printf("[1] Equation du premier degre\n"
           "[2] Equation du second degre (sans complexe)\n"
           "[3] Eqaution diophatienne\n"
           "[4] retour\n");
}
/*******************************************************************/
char dmdChoix2(char choix2){
    printf("\nVeuillez entrer votre choix : ");
    choix2=getchar();
    shut
    return choix2;
}
/***********************************************************************************/
//pour les trois options de l'option Equation

void premierDegrer(float a,float b,float c,float x){
    printf("Bienvenue dans RESOLUTION EQUATION PREMIER DEGRER\n");
    printf("Une equation du PREMIER DEGRER est de la forme\n\ta x + b = c\n");
    printf("Entrer a = ");
    scanf("%f",&a);
    printf("Entrer b = ");
    scanf("%f",&b);
    printf("Entrer c = ");
    scanf("%f",&c);
    printf("On a alors l'equation : %.f x + %.f = %.f\n",a,b,c);
    x=((c-b)/a);
    printf("La solution est \n\tx = %f ",x);
    printf("Appuyer sur une touche du clacier pour continuer ");
    getch();
}
/*******************************************************************/
void secondDegrer(float a,float b,float c,float d,float x,float x1,float x2,float delta){
    printf("\t\t\t\t\t\tBienvenue dans RESOLUTION EQUATION SECOND DEGRER\n\n");
    printf("Une equation du SECOND DEGRER est de la forme\n\ta x^2 + b x + c  = 0\n");
    printf("Entrer a = ");
    scanf("%f",&a);
    printf("Entrer b = ");
    scanf("%f",&b);
    printf("Entrer c = ");
    scanf("%f",&c);
    delta=((b*b)-(4*a*c));
        if(delta < 0)
        {
            printf("Aucune solution reelle pour cette Equation ! \n");
            printf("Appuyer sur une touche du clacier pour continuer ");
            getch();
        }
        else if(delta == 0)
        {
            x=-b/(2*a);
            printf("La solution unique est x = %f \n",x);
            printf("Appuyer sur une touche du clacier pour continuer ");
            getch();
        }
        else if(delta > 0)
        {
            x1=((-b-sqrt(delta))/(2*a));
            x2=((-b+sqrt(delta))/(2*a));
            printf("Les solutions sont :\nx1 = %f et x2 = %f \n",x1,x2);
            printf("Appuyer sur une touche du clacier pour continuer ");
            getch();
        }
}
/*******************************************************************/
void equationDiophatienne(float a,float b,float c,float x,float y){

    int max=0;
    int min=0;
    int cpt=0;
    int tmp1=0;
    int tmp2=0;

    printf("\t\t\t\tBienvenue dans RESOLUTION EQUATION DIOPHATIENNE\n\n");
    printf("Une equation DIOPHATIENNE est de la forme\n\ta x + b y = c\n");
    printf("Entrer a = ");
    scanf("%f",&a);
    printf("Entrer b = ");
    scanf("%f",&b);
    printf("Entrer c = ");
    scanf("%f",&c);
    //la taille de a et b

        printf("Entrer votre Intervalle de solution particuliere[min;max]\n");

            printf("Entrer min = ");
            scanf("%d",&min);
            printf("Entrer max =  ");
            scanf("%d",&max);
        //pour mettre dans min le plus petit des deux valeurs entrer par l'utilisateur
        tmp1=(min>max)?max:min;
        tmp2=(min<max)?max:min;
        min=tmp1;
        max=tmp2;
        printf("Dans l 'intervalle [%d ; %d] \n",min,max);
        printf("Les solutions generales de cette equation que j'ai trouve sont : \n");
        for(x=min;x<=max;x++)
        {
            for(y=min;y<=max;y++)
            {
                if(((a*x)+(b*y))==c)
                {
                    cpt++;
                        cadre           //Verifier macros
                    printf("Numero %d : \n",cpt);
                    printf("\t  x = -%.f k + %.f\n",b,x);
                    printf("\t  y =  %.f k + %.f\n",a,y);
                    printf("Avec k appartient a R\n");
                        cadre
                    break;
                }
                else if(x==max && y==max && cpt<1)
                {
                    printf("J'ai treouve aucune solution dans l'intervalle [%d ; %d]\n",min,max);
                }
            }
        }

        printf("Appuyer sur une touche du clacier pour continuer ");
        getch();
}
/*******************************************************************/
void soratra(){

    printf("\t\t\t\t\t\t===========\n");
    printf("\t\t\t\t\t\t EQUATION\n");
    printf("\t\t\t\t\t\t===========\n");

}
/*******************************************************************/
