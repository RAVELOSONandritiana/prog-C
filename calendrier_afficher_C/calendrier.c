#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fonc_cal.h"
int main(){
	int j,m,a;
	while(1)
	{
		printf("Date(05/01/2023) : ");
		scanf("%d/%d/%d",&j,&m,&a);
		affiche_mois(j,m,a);
	}
	return 0;
}
