#ifndef FONCTION_H
#define FONCTION_H
#include "fonction.c"
/////////////////////////////////////////////////

void textcolor(int color);

char *file_name();

void printp(char *mot);

void anime_intro(int nombre);

int cpt_ligne(char *nomFichier);

void triage(Base *ma,int taille);

void aff(Base *nourriture,Classe *detail,int nb_ligne);

void space(int n);

void client(int numero);

void base();

/////////////////////////////////////////////////
#endif