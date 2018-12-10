#include "verifier.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
int verifier (char login[], char Password[])
{FILE*f;
int y=0,role=0;
char login1[30],Password1[30];

f=fopen("/home/fares/Desktop/Users.txt","r");
if(f!=NULL) { 
while (fscanf(f,"%s %s %d",login1,Password1,&role)!=EOF) 
{	
	if((strcmp(login1,login)==0) && (strcmp(Password1,Password)==0) )
	{return role; }
	}}


fclose(f);}
