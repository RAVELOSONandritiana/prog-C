#ifdef WIN32
#define CLEAR "cls"
#endif
#ifdef POSIX
#define CLEAR "clear"
#endif
#define ERREUR1 "DATE NON VALIDE , VEUILLEZ REESSAYER\n"
#define ERREUR2 "UNE ERREUR EST SURVENUE LORS DE L'OUVERTURE D'UN OU PLUSIEURS FICHIERS\nVEUILLEZ VERIFIER QUE LE FICHIER QUE VOUS ESSAYER D'OUVRIR EST BIEN PRESENT OU QU'IL EST DEJA OCCUPER PAR UNE AUTRE PROCESSUS\n"
#define ESPACE 20
#define TAILLE_JOUR 10
///////////////////////////////////////////////////////////////////
#include <windows.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
typedef struct Base{
    char nom[50];
    int nombre;
    long int prix;
}Base;
typedef struct Classe{
    char nom1[50];
    char nom2[50];
    char nom3[50];
}Classe;
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
//FONCTION POUR COLORIER NOTRE CODE POUR BIEN GERER LA COMMUNICATION AVEC L UTILISATEUR
void textcolor(int color){
    HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hconsole,color);
}
///////////////////////////////////////////////////////////////////
//FONCTION QUI VA AFFICHER PETIT A PETIT NOTRE PHRASE
void printp(char *mot){
    int taille = strlen(mot);
    for(int i = 0;i < taille;i++)
    {
        printf("%c",mot[i]);
        usleep(50000);
    }
}
///////////////////////////////////////////////////////////////////
//FONCTION DE PETIT ANIMATION DE DEPART
void anime_intro(int nombre){
    for(int j = 0 ;j < nombre;j++)
    {
        for(int i = 0;i < j ; i++)
        {
            printf(" ");
        }
        textcolor(11);
        printf("%c%c",4,3);
        textcolor(13);
        printf("RESTAURANT DU PARADIS");
        textcolor(11);
        printf("%c%c\n",3,4);
        usleep(50000);
        if(j != nombre-1)
            system(CLEAR);
        else
            sleep(2);
    }
}
///////////////////////////////////////////////////////////////////
//Fonction qui retourne le nom du fichier a utiliser
char *file_name(){
    char *nomFichier;
    nomFichier = (char *)malloc(sizeof(char )*100);
dmd:;
    textcolor(10);
    char jour[10];
    printf("Jour [1-7]: ");
    textcolor(3);
    scanf("%1s",jour);

    if(jour[0] == '1')
    {
        strcpy(nomFichier,"Gestion de nourriture/Lundi.csv");
    }
    else if(jour[0] == '2')
    {
        strcpy(nomFichier,"Gestion de nourriture/Mardi.csv");
    }
    else if(jour[0] == '3')
    {
        strcpy(nomFichier,"Gestion de nourriture/Mercredi.csv");
    }
    else if(jour[0] == '4')
    {
        strcpy(nomFichier,"Gestion de nourriture/Jeudi.csv");
    }
    else if(jour[0] == '5')
    {
        strcpy(nomFichier,"Gestion de nourriture/Vendredi.csv");
    }
    else if(jour[0] == '6')
    {
        strcpy(nomFichier,"Gestion de nourriture/Jeudi.csv");
    }
    else if(jour[0] == '7')
    {
        strcpy(nomFichier,"Gestion de nourriture/vendredi.csv");
    }
    else if(jour[0] == 'q' || jour[0] == 'Q')
    {
        remove("RestaurantP.exe");
        remove("RestaurantP.o");
        exit(0);
    }
    else
    {
        system(CLEAR);
        textcolor(4);
        printp(ERREUR1);
        goto dmd;
    }
    return nomFichier;
}
///////////////////////////////////////////////////////////////////
//FONCTION TROUVANT LE NOMBRE DE LIGNE DANS UNE FICHIER
int cpt_ligne(char *nomFichier){
    FILE *fichier = NULL;
    int cpt = 0;
    fichier = fopen(nomFichier,"r");
    char chaine[50];
    while(fgets(chaine,sizeof(chaine),fichier))
        cpt++;
    fclose(fichier);
    return cpt;
}
///////////////////////////////////////////////////////////////////
//FONCTION POUR TRIER A PARTIR DU PRIX DES ELEMENTS DE LA STRUCTURE
void triage(Base *ma,int taille){
    for(int i = 0;i < taille;i++)
    {
        for(int j = i+1;j < taille;j++)
        {
            if((ma+i)->prix < (ma+j)->prix)
            {
                Base tmp = ma[i];
                ma[i] = ma[j];
                ma[j] = tmp;
            }
        }
    }
}
///////////////////////////////////////////////////////////////////
//FONCTION POUR AFFICHER LES ELEMENTS
void space(int n){
    for(int i = 0;i < n;i++)
        printf(" ");
}
void aff(Base *nourriture,Classe *detail,int nb_ligne){
    for(int i = 0;i < nb_ligne;i++)
    {
        textcolor(0);
        space(20);
        if(i==0)
        {
            textcolor(64);
            printf("%s       ",(detail+i)->nom1);
            space(ESPACE-strlen((detail+i)->nom1));
            printf("%s",(detail+i)->nom2);
            space(ESPACE-strlen((detail+i)->nom2));
            printf("%s     \n",(detail+i)->nom3);
        }
        else
        {
            textcolor(48);
            printf("%s",(nourriture+i)->nom);
            space(ESPACE-strlen((nourriture+i)->nom));
            char tmp1[50],tmp2[50];
            sprintf(tmp1,"%d",(nourriture+i)->nombre);
            sprintf(tmp2,"%d",(nourriture+i)->prix);
            //textcolor(121);
            textcolor(80);
            printf("%d",(nourriture+i)->nombre);
            space(ESPACE-strlen(tmp1));
            textcolor(112);
            printf("%ld",(nourriture+i)->prix);
            space(ESPACE-strlen(tmp2));
            printf("\n");
        }
    }
}
////////////////////////////////////////////////////
//CREATION DE FICHIER POUR UNE PERSONNE
void client(int numero){
    char nom[30];
    char prenom[50];
    char recepteur[50];
    char calc[1000];
    char total[30];
    time_t m;
    char *date = NULL;
    m = time(NULL);
    printp("Nom----------: ");
    textcolor(4);scanf(" %[^\n]",nom);
    textcolor(7);
    printp("Prenom-------: ");
    textcolor(4);scanf(" %[^\n]",prenom);
    textcolor(7);
    printp("Calculatrice-: ");
    textcolor(4);scanf(" %[^\n]",calc);
            FILE *f = NULL;
            FILE *fi = NULL;
            f = fopen("c.txt","w");
                fprintf(f,"%s",calc);
                if(f == NULL)
                {
                    textcolor(4);
                    printp(ERREUR2);
                    textcolor(7);
                    remove("RestaurantP.exe");
                    remove("RestaurantP.o");
                    exit(EXIT_FAILURE);
                }
            fclose(f);
            system("py calculRestaurant.py");
            fi = fopen("v.txt","r");
                if(fi == NULL)
                {
                    textcolor(4);
                    printp(ERREUR2);
                    textcolor(7);
                    remove("RestaurantP.exe");
                    remove("RestaurantP.o");
                    exit(EXIT_FAILURE);
                }
                fgets(total,100,f);
            fclose(fi);
        //POUR SUPPRIMER LES FICHIERS DE CALCULS TEMPORAIRES
            remove("c.txt");
            remove("v.txt");
    textcolor(7);
    printp("Total--------: ");
    textcolor(10);
    printf("%s Ar\n",total);
    textcolor(7);
    getch();
    char nomFichier[50];
    sprintf(nomFichier,"client/%d%s.csv",numero,nom);
    FILE *fichier = NULL;
    fichier = fopen(nomFichier,"w+");
    if(fichier == NULL)
    {
        textcolor(4);
        printp(ERREUR2);
        textcolor(7);
        remove("RestaurantP.exe");
        remove("RestaurantP.o");
        exit(EXIT_FAILURE);
    }
    else
    {
        fprintf(fichier,"NOM  ;%s\nPRENOM  ;%s\n",nom,prenom);
        fprintf(fichier,"ENTREPRISE  ;%s\n",getlogin());
        fprintf(fichier,"TOTAL  ;%s Ar\n",total);
        date = ctime(&m);
        fprintf(fichier,"HEURE  ;%s\n",date);
    }

    fclose(fichier);
}

//////////////////////////////////////////////////////////////////////////
void base(){
    int numero = 1;
//ANIMATION DE PRESENTATION
    anime_intro(TAILLE_JOUR+21);
    while(1)
    {
        //Pour stocker tout sur notre nourriture du jour , Donc on doit taper de [0-6] pour les jours
        char *nomFichier;
        nomFichier = (char *)malloc(sizeof(char )*TAILLE_JOUR*10);
        //NOM DU FICHIER OBTENU A PARTIR DU JOUR ENTRER PAR LE RECEPTEUR
        nomFichier = file_name();
        int nb_ligne = cpt_ligne(nomFichier);
    ////////////////////////////////////////////////////////
    //PARTIE OU ON CRRER LES STRUCTURES DE DONNES QUI VONT CONTENIR NOS ELEMENTS DANS LE FICHIER
        Base *nourriture = NULL;Classe *detail = NULL;
        nourriture = (Base *)malloc(sizeof(Base )*(nb_ligne-1));
        detail = (Classe *)malloc(sizeof(Classe )*1);
    ////////////////////////////////////////////////////////
    //POINTER VERS LE FICHIER POUR OBTENIR LES DONNES
    FILE *fichier = NULL;
    fichier = fopen(nomFichier,"r+");
        if(fichier == NULL)
        {
            textcolor(4);
            printp(ERREUR2);
            textcolor(7);
            remove("RestaurantP.exe");
            remove("RestaurantP.o");
            exit(EXIT_FAILURE);
        }
        else
        {
            for(int i = 0;i < nb_ligne;i++)
            {
                char tmp[60];
                fgets(tmp,300,fichier);
                if(i == 0)
                {
                    sscanf(tmp,"%[^;];%[^;];%s",(detail+i)->nom1,(detail+i)->nom2,(detail+i)->nom3);
                }
                else
                {
                    sscanf(tmp,"%[^;];%d;%ld",(nourriture+i)->nom,&(nourriture+i)->nombre,&(nourriture+i)->prix);
                }
            }
        }
    fclose(fichier);
    ///////////////////////////////////////////////////////
    //TRIAGE DE LA STRUCTURE
        triage(nourriture,nb_ligne-1);
        aff(nourriture,detail,nb_ligne);
        textcolor(7);
        client(numero);
        numero++;
        system(CLEAR);
    }
}
