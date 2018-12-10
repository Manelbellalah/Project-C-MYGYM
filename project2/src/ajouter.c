#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ajouter.h"
void ajouter (char login[],char Password,int role)
{f=fopen("Users.txt""a+");
if(f!=NULL){
printf("Saisir les données");
fflush(stdin);
gets(login);
fflush(stdin);
gets(Password);
scanf("%d",&role);
fprintf(f,"%s %s %d\n",login,Password,role);
}
fclose(f);
}


