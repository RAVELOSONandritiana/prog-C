#ifndef FONC_CAL_H
#define FONC_CAL_H
int isleap(int an){
	if(an%4==0 && (an%100!=0 || an%400==0))
		return 1;
	return 0;
}
int getDay(int jour,int mois,int an){
	int day = 0;
	if(mois == 1)
	{
		an--;
		mois = 13;
	}
	
	if(mois == 2)
	{
		an--;
		mois = 14;
	}
	int k = an%100;
	int j = an/100;
	
	day = (jour + (13*(mois+1))/5+k+k/4+j/4-2*j)%7;
	
	return day;
}
char *jour_lettre(int day,int month,int year){
	int jour = getDay(day,month,year);
	char *andro;
	andro = (char *)malloc(20);
	if(jour==0)
		strcpy(andro,"Sabotsy");
	if(jour==1)
		strcpy(andro,"Alahady");
	if(jour==2)
		strcpy(andro,"Alatsinainy");
	if(jour==3)
		strcpy(andro,"Talata");
	if(jour==4)
		strcpy(andro,"Alarobia");
	if(jour==5)
		strcpy(andro,"Alakamisy");
	if(jour==6)
		strcpy(andro,"Zoma");
	return andro;
}

void affiche_mois(int jour,int mois,int an){
	char *j = jour_lettre(1,mois,an);
	int index = 0;
	//printf("%s",j);
	int espace = 0;
	int boucle_jour = 0;
	if(isleap(an)){
		if(mois==1 || mois==3 || mois==5 || mois==7|| mois==8|| mois==10|| mois==12)
			boucle_jour = 31;
		else{
			if(mois==2)
				boucle_jour=29;
			else
				boucle_jour=30;
		}
	}
	else{
		if(mois==1 || mois==3 || mois==5 || mois==7|| mois==8|| mois==10|| mois==12)
			boucle_jour = 31;
		else{
			if(mois==1)
				boucle_jour=28;
			else
				boucle_jour=30;
		}
	}
	printf("A  T  A  A  Z  S  A\n");
	if(strcmp(j,"Alatsinainy")==0)
	{
		espace = 0;
	}
	if(strcmp(j,"Talata")==0)
	{
		espace = 1;
	}
	if(strcmp(j,"Alarobia")==0)
	{
		espace = 2;
	}
	if(strcmp(j,"Alakamisy")==0)
	{
		espace = 3;
	}
	if(strcmp(j,"Zoma")==0)
	{
		espace = 4;
	}
	if(strcmp(j,"Sabotsy")==0)
	{
		espace = 5;
	}
	if(strcmp(j,"Alahady")==0)
	{
		espace = 6;
	}
	index = espace;
	for(int i = 0;i<espace;i++)
			printf("   ");
	for(int i = 0;i<boucle_jour;i++)
	{
		if((i+1)==jour && i<9){
			printf("\e[35m0%d \e[0m",i+1);
			goto next;
		}
		if((i+1)==jour && i>9){
			printf("\e[35m%d \e[0m",i+1);
			goto next;
		}
		if(i<9)printf("0");
		printf("%d ",i+1);
next:;
		index++;
		if(index == 7)
		{
			printf("\n");
			index = 0;
		}
	}
	printf("\n\nle %d de cette mois est un %s\n\n",jour,jour_lettre(jour,mois,an));
}

#endif
