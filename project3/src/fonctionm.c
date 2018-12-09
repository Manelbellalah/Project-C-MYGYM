#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include "fonctionm.h"

///////////////////////////////adherent/////////////////////////////////////////////

void ajouter_adh(ad a)
{
FILE *f;

f=fopen("/home/manel/Projects/project3/project3/src/adherent.txt","a+");
if(f!=NULL)
{
fprintf(f,"%s %s %s %s %s %s\n",a.nom,a.prenom,a.sexe,a.cin,a.numero,a.adresse);
}
fclose(f);
}

void modifierr_adherent(ad c,char amodifier[50])
{
ad a;
FILE *f;
FILE *f2;
f=fopen("/home/manel/Projects/project3/project3/src/adherent.txt","r");
f2=fopen("/home/manel/Projects/project3/project3/src/Nadherent.txt","w"); 
if (f!=NULL)
{
if (f2!=NULL)

{ 
     while (fscanf(f,"%s %s %s %s %s %s\n",a.nom,a.prenom,a.sexe,a.cin,a.numero,a.adresse)!=EOF)
    { 
    if((strcmp(amodifier,a.cin))!=0)
    {
    fprintf(f2,"%s %s %s %s %s %s\n",a.nom,a.prenom,a.sexe,a.cin,a.numero,a.adresse);
     }
else {
	fprintf(f2,"%s %s %s %s %s %s\n",c.nom,c.prenom,c.sexe,c.cin,c.numero,c.adresse);
     }
     }
     }}
fclose(f);
fclose(f2);

remove("/home/manel/Projects/project3/project3/src/adherent.txt") ;
rename ("/home/manel/Projects/project3/project3/src/Nadherent.txt" , "/home/manel/Projects/project3/project3/src/adherent.txt") ;
}

void supprimer_adh(char cin_adh[])
{
  ad m ;
  FILE *f,*f1;
  f=fopen("/home/manel/Projects/project3/project3/src/adherent.txt","r");
  f1=fopen("/home/manel/Projects/project3/project3/src/Nadherent.txt","w");
  if ((f!=NULL) && (f1!=NULL))
{ 
     while (fscanf(f,"%s %s %s %s %s %s\n",m.nom,m.prenom,m.sexe,m.cin,m.numero,m.adresse)!=EOF)
   { 
    if (strcmp(cin_adh,m.cin)!=0)
   {    
  	
     fprintf(f1,"%s %s %s %s %s %s\n",m.nom,m.prenom,m.sexe,m.cin,m.numero,m.adresse);
        	
   }
}


fclose(f);
fclose(f1);}
  f=fopen("/home/manel/Projects/project3/project3/src/adherent.txt","w");
  f1=fopen("/home/manel/Projects/project3/project3/src/Nadherent.txt","r");
  if ((f!=NULL) && (f1!=NULL))
{ 
     while (fscanf(f1,"%s %s %s %s %s %s\n",m.nom,m.prenom,m.sexe,m.cin,m.numero,m.adresse)!=EOF)
   { 
    if (strcmp(cin_adh,m.cin)!=0)
   {    
  	
     fprintf(f,"%s %s %s %s %s %s\n",m.nom,m.prenom,m.sexe,m.cin,m.numero,m.adresse);
        	
   }
}
fclose(f);
fclose(f1);
}}


int existe_adh (char cinn[]) { 
FILE *f;
ad a;
int test = 0 ; 
f=fopen("/home/manel/Projects/project3/project3/src/adherent.txt","r");
if(f!=NULL) { 
while(fscanf(f,"%s %s %s %s %s %s \n",a.nom,a.prenom,a.sexe,a.cin,a.numero,a.adresse)!=EOF) 
{ if((strcmp(a.cin,cinn)==0) )
test=1 ;
 } 
fclose(f);
return test ; 
}
}


int test_nombre(char c[])
{
  int r=0,i;
  for(i=0;i<strlen(c);i++)
    {
      if(!isdigit(c[i]))
        {
          r=1; 
        }
    
    }
    
    return r;

}

///////////////medecin//////////////////////////////////////////////////////////////////


int existe_med (char cinn[]) { 
FILE *f;
med m;
int test = 0 ; 
f=fopen("/home/manel/Projects/project3/project3/src/medecin.txt","r");
if(f!=NULL) { 
while(fscanf(f,"%s %s %s %s %s %s \n",m.nom,m.prenom,m.sexe,m.cin,m.numero,m.adresse)!=EOF) 
{ if((strcmp(m.cin,cinn)==0) )
test=1 ;
 } 
fclose(f);
return test ; 
}
}


void ajouter_med(med m)
{
FILE *f;

f=fopen("/home/manel/Projects/project3/project3/src/medecin.txt","a+");
if(f!=NULL)
{
fprintf(f,"%s %s %s %s %s %s\n",m.nom,m.prenom,m.sexe,m.cin,m.numero,m.adresse);
}
fclose(f);
}

void modifierr_medecin(med c,char amodifier[50])
{
med a;
FILE *f;
FILE *f2;
f=fopen("/home/manel/Projects/project3/project3/src/medecin.txt","r");
f2=fopen("/home/manel/Projects/project3/project3/src/Nmedecin.txt","w"); 
if (f!=NULL)
{
if (f2!=NULL)

{ 
     while (fscanf(f,"%s %s %s %s %s %s\n",a.nom,a.prenom,a.sexe,a.cin,a.numero,a.adresse)!=EOF)
    { 
    if((strcmp(amodifier,a.cin))!=0)
    {
    fprintf(f2,"%s %s %s %s %s %s\n",a.nom,a.prenom,a.sexe,a.cin,a.numero,a.adresse);
     }
else {
	fprintf(f2,"%s %s %s %s %s %s\n",c.nom,c.prenom,c.sexe,c.cin,c.numero,c.adresse);
     }
     }
     }}
fclose(f);
fclose(f2);

remove("/home/manel/Projects/project3/project3/src/medecin.txt") ;
rename ("/home/manel/Projects/project3/project3/src/Nmedecin.txt" , "/home/manel/Projects/project3/project3/src/medecin.txt") ;
}

void supprimer_med(char cin_med[])
{
  med m ;
  FILE *f,*f1;
  f=fopen("/home/manel/Projects/project3/project3/src/medecin.txt","r");
  f1=fopen("/home/manel/Projects/project3/project3/src/Nmedecin.txt","w");
  if ((f!=NULL) && (f1!=NULL))
{ 
     while (fscanf(f,"%s %s %s %s %s %s\n",m.nom,m.prenom,m.sexe,m.cin,m.numero,m.adresse)!=EOF)
   { 
    if (strcmp(cin_med,m.cin)!=0)
   {    
  	
     fprintf(f1,"%s %s %s %s %s %s\n",m.nom,m.prenom,m.sexe,m.cin,m.numero,m.adresse);
        	
   }
}


fclose(f);
fclose(f1);}
  f=fopen("/home/manel/Projects/project3/project3/src/medecin.txt","w");
  f1=fopen("/home/manel/Projects/project3/project3/src/Nmedecin.txt","r");
  if ((f!=NULL) && (f1!=NULL))
{ 
     while (fscanf(f1,"%s %s %s %s %s %s\n",m.nom,m.prenom,m.sexe,m.cin,m.numero,m.adresse)!=EOF)
   { 
    if (strcmp(cin_med,m.cin)!=0)
   {    
  	
     fprintf(f,"%s %s %s %s %s %s\n",m.nom,m.prenom,m.sexe,m.cin,m.numero,m.adresse);
        	
   }
}
fclose(f);
fclose(f1);
}}


/////////////////////////////////////dieteticien/////////////////////////////////////////////////////////////////




int existe_diet (char cinn[]) { 
FILE *f;
diet d;
int test = 0 ; 
f=fopen("/home/manel/Projects/project3/project3/src/dieteticien.txt","r");
if(f!=NULL) { 
while(fscanf(f,"%s %s %s %s %s %s \n",d.nom,d.prenom,d.sexe,d.cin,d.numero,d.adresse)!=EOF) 
{ if((strcmp(d.cin,cinn)==0) )
test=1 ;
 } 
fclose(f);
return test ; 
}
}


void ajouter_diet(diet d)
{
FILE *f;

f=fopen("/home/manel/Projects/project3/project3/src/dieteticien.txt","a+");
if(f!=NULL)
{
fprintf(f,"%s %s %s %s %s %s\n",d.nom,d.prenom,d.sexe,d.cin,d.numero,d.adresse);
}
fclose(f);
}


void modifierr_dieteticien(diet c,char amodifier[50])
{
diet a;
FILE *f;
FILE *f2;
f=fopen("/home/manel/Projects/project3/project3/src/dieteticien.txt","r");
f2=fopen("/home/manel/Projects/project3/project3/src/Ndieteticien.txt","w"); 
if (f!=NULL)
{
if (f2!=NULL)

{ 
     while (fscanf(f,"%s %s %s %s %s %s\n",a.nom,a.prenom,a.sexe,a.cin,a.numero,a.adresse)!=EOF)
    { 
    if((strcmp(amodifier,a.cin))!=0)
    {
    fprintf(f2,"%s %s %s %s %s %s\n",a.nom,a.prenom,a.sexe,a.cin,a.numero,a.adresse);
     }
else {
	fprintf(f2,"%s %s %s %s %s %s\n",c.nom,c.prenom,c.sexe,c.cin,c.numero,c.adresse);
     }
     }
     }}
fclose(f);
fclose(f2);

remove("/home/manel/Projects/project3/project3/src/dieteticien.txt") ;
rename ("/home/manel/Projects/project3/project3/src/Ndieteticien.txt" , "/home/manel/Projects/project3/project3/src/dieteticien.txt") ;
}

void supprimer_diete(char cin_diete[])
{
  diet m ;
  FILE *f,*f1;
  f=fopen("/home/manel/Projects/project3/project3/src/dieteticien.txt","r");
  f1=fopen("/home/manel/Projects/project3/project3/src/Ndieteticien.txt","w");
  if ((f!=NULL) && (f1!=NULL))
{ 
     while (fscanf(f,"%s %s %s %s %s %s\n",m.nom,m.prenom,m.sexe,m.cin,m.numero,m.adresse)!=EOF)
   { 
    if (strcmp(cin_diete,m.cin)!=0)
   {    
  	
     fprintf(f1,"%s %s %s %s %s %s\n",m.nom,m.prenom,m.sexe,m.cin,m.numero,m.adresse);
        	
   }
}


fclose(f);
fclose(f1);}
  f=fopen("/home/manel/Projects/project3/project3/src/dieteticien.txt","w");
  f1=fopen("/home/manel/Projects/project3/project3/src/Ndieteticien.txt","r");
  if ((f!=NULL) && (f1!=NULL))
{ 
     while (fscanf(f1,"%s %s %s %s %s %s\n",m.nom,m.prenom,m.sexe,m.cin,m.numero,m.adresse)!=EOF)
   { 
    if (strcmp(cin_diete,m.cin)!=0)
   {    
  	
     fprintf(f,"%s %s %s %s %s %s\n",m.nom,m.prenom,m.sexe,m.cin,m.numero,m.adresse);
        	
   }
}
fclose(f);
fclose(f1);
}}


/////////////////////////////////////////////////coach//////////////////////////////////////////////////////


void ajouter_coach(coach c)
{
FILE *f;

f=fopen("/home/manel/Projects/project3/project3/src/coach.txt","a+");
if(f!=NULL)
{
fprintf(f,"%s %s %s %s %s %s\n",c.nom,c.prenom,c.sexe,c.cin,c.numero,c.specialite);
}
fclose(f);
}

void modifierr_coach(coach c,char amodifier[50])
{
coach a;
FILE *f;
FILE *f2;
f=fopen("/home/manel/Projects/project3/project3/src/coach.txt","r");
f2=fopen("/home/manel/Projects/project3/project3/src/Ncoach.txt","w"); 
if (f!=NULL)
{
if (f2!=NULL)

{ 
     while (fscanf(f,"%s %s %s %s %s %s\n",a.nom,a.prenom,a.sexe,a.cin,a.numero,a.specialite)!=EOF)
    { 
    if((strcmp(amodifier,a.cin))!=0)
    {
    fprintf(f2,"%s %s %s %s %s %s\n",a.nom,a.prenom,a.sexe,a.cin,a.numero,a.specialite);
     }
else {
	fprintf(f2,"%s %s %s %s %s %s\n",c.nom,c.prenom,c.sexe,c.cin,c.numero,c.specialite);
     }
     }
     }}
fclose(f);
fclose(f2);

remove("/home/manel/Projects/project3/project3/src/coach.txt") ;
rename ("/home/manel/Projects/project3/project3/src/Ncoach.txt" , "/home/manel/Projects/project3/project3/src/coach.txt") ;
}

void supprimer_coach(char cin_coach[])
{
  coach c ;
  FILE *f,*f1;
  f=fopen("/home/manel/Projects/project3/project3/src/coach.txt","r");
  f1=fopen("/home/manel/Projects/project3/project3/src/coach.txt","w");
  if ((f!=NULL) && (f1!=NULL))
{ 
     while (fscanf(f,"%s %s %s %s %s %s\n",c.nom,c.prenom,c.sexe,c.cin,c.numero,c.specialite)!=EOF)
   { 
    if (strcmp(cin_coach,c.cin)!=0)
   {    
  	
     fprintf(f1,"%s %s %s %s %s %s\n",c.nom,c.prenom,c.sexe,c.cin,c.numero,c.specialite);
        	
   }
}


fclose(f);
fclose(f1);}
  f=fopen("/home/manel/Projects/project3/project3/src/coach.txt","w");
  f1=fopen("/home/manel/Projects/project3/project3/src/Ncoach.txt","r");
  if ((f!=NULL) && (f1!=NULL))
{ 
     while (fscanf(f1,"%s %s %s %s %s %s\n",c.nom,c.prenom,c.sexe,c.cin,c.numero,c.specialite)!=EOF)
   { 
    if (strcmp(cin_coach,c.cin)!=0)
   {    
  	
     fprintf(f,"%s %s %s %s %s %s\n",c.nom,c.prenom,c.sexe,c.cin,c.numero,c.specialite);
        	
   }
}
fclose(f);
fclose(f1);
}}


int existe_coach (char cinn[]) { 
FILE *f;
coach c;
int test = 0 ; 
f=fopen("/home/manel/Projects/project3/project3/src/coach.txt","r");
if(f!=NULL) { 
while(fscanf(f,"%s %s %s %s %s %s \n",c.nom,c.prenom,c.sexe,c.cin,c.numero,c.specialite)!=EOF) 
{ if((strcmp(c.cin,cinn)==0) )
test=1 ;
 } 
fclose(f);
return test ; 
}
}




////////////////////////////////////////////kine////////////////////////////////////////////////////////


int existe_kine (char cinn[]) { 
FILE *f;
kine k;
int test = 0 ; 
f=fopen("/home/manel/Projects/project3/project3/src/kine.txt","r");
if(f!=NULL) { 
while(fscanf(f,"%s %s %s %s %s %s \n",k.nom,k.prenom,k.sexe,k.cin,k.numero,k.adresse)!=EOF) 
{ if((strcmp(k.cin,cinn)==0) )
test=1 ;
 } 
fclose(f);
return test ; 
}
}


void ajouter_kine(kine k)
{
FILE *f;

f=fopen("/home/manel/Projects/project3/project3/src/kine.txt","a+");
if(f!=NULL)
{
fprintf(f,"%s %s %s %s %s %s\n",k.nom,k.prenom,k.sexe,k.cin,k.numero,k.adresse);
}
fclose(f);
}


void modifierr_kine(kine k,char amodifier[50])
{
kine a;
FILE *f;
FILE *f2;
f=fopen("/home/manel/Projects/project3/project3/src/kine.txt","r");
f2=fopen("/home/manel/Projects/project3/project3/src/Nkine.txt","w"); 
if (f!=NULL)
{
if (f2!=NULL)

{ 
     while (fscanf(f,"%s %s %s %s %s %s\n",a.nom,a.prenom,a.sexe,a.cin,a.numero,a.adresse)!=EOF)
    { 
    if((strcmp(amodifier,a.cin))!=0)
    {
    fprintf(f2,"%s %s %s %s %s %s\n",a.nom,a.prenom,a.sexe,a.cin,a.numero,a.adresse);
     }
else {
	fprintf(f2,"%s %s %s %s %s %s\n",k.nom,k.prenom,k.sexe,k.cin,k.numero,k.adresse);
     }
     }
     }}
fclose(f);
fclose(f2);

remove("/home/manel/Projects/project3/project3/src/kine.txt") ;
rename ("/home/manel/Projects/project3/project3/src/Nkine.txt" , "/home/manel/Projects/project3/project3/src/kine.txt") ;
}

void supprimer_kine(char cin_kine[])
{
  kine k ;
  FILE *f,*f1;
  f=fopen("/home/manel/Projects/project3/project3/src/kine.txt","r");
  f1=fopen("/home/manel/Projects/project3/project3/src/Nkine.txt","w");
  if ((f!=NULL) && (f1!=NULL))
{ 
     while (fscanf(f,"%s %s %s %s %s %s\n",k.nom,k.prenom,k.sexe,k.cin,k.numero,k.adresse)!=EOF)
   { 
    if (strcmp(cin_kine,k.cin)!=0)
   {    
  	
     fprintf(f1,"%s %s %s %s %s %s\n",k.nom,k.prenom,k.sexe,k.cin,k.numero,k.adresse);
        	
   }
}


fclose(f);
fclose(f1);}
  f=fopen("/home/manel/Projects/project3/project3/src/kine.txt","w");
  f1=fopen("/home/manel/Projects/project3/project3/src/Nkine.txt","r");
  if ((f!=NULL) && (f1!=NULL))
{ 
     while (fscanf(f1,"%s %s %s %s %s %s\n",k.nom,k.prenom,k.sexe,k.cin,k.numero,k.adresse)!=EOF)
   { 
    if (strcmp(cin_kine,k.cin)!=0)
   {    
  	
     fprintf(f,"%s %s %s %s %s %s\n",k.nom,k.prenom,k.sexe,k.cin,k.numero,k.adresse);
        	
   }
}
fclose(f);
fclose(f1);
}}
//////////////////////////////////////gestion////////////////////////////////////////////////

void ajouter_ger(geration g)
{
FILE *f;

f=fopen("/home/manel/Projects/project3/project3/src/users.txt","a+");
if(f!=NULL)
{
fprintf(f,"%s %s %s %s %s\n",g.nom,g.prenom,g.cin,g.role,g.moddepasse);
}
fclose(f);
}

int existe_ger (char cinn[]) { 
FILE *f;
geration g;
int test = 0 ; 
f=fopen("/home/manel/Projects/project3/project3/src/users.txt","r");
if(f!=NULL) { 
while(fscanf(f,"%s %s %s %s %s\n",g.nom,g.prenom,g.cin,g.role,g.moddepasse)!=EOF) 
{ if((strcmp(g.cin,cinn)==0) )
test=1 ;
 } 
fclose(f);
return test ; 
}
}

void modifierr_gest(geration g,char amodifier[50])
{
geration a;
FILE *f;
FILE *f2;
f=fopen("/home/manel/Projects/project3/project3/src/users.txt","r");
f2=fopen("/home/manel/Projects/project3/project3/src/Nusers.txt","w"); 
if (f!=NULL)
{
if (f2!=NULL)

{ 
     while (fscanf(f,"%s %s %s %s %s\n",a.nom,a.prenom,a.cin,a.role,a.moddepasse)!=EOF)
    { 
    if((strcmp(amodifier,a.cin))!=0)
    {
    fprintf(f2,"%s %s %s %s %s\n",a.nom,a.prenom,a.cin,a.role,a.moddepasse);
     }
else {
	fprintf(f2,"%s %s %s %s %s\n",g.nom,g.prenom,g.cin,g.role,g.moddepasse);
     }
     }
     }}
fclose(f);
fclose(f2);

remove("/home/manel/Projects/project3/project3/src/users.txt") ;
rename ("/home/manel/Projects/project3/project3/src/Nusers.txt" , "/home/manel/Projects/project3/project3/src/users.txt") ;
}

void supprimer_gest(char cin_gest[])
{
  geration g ;
  FILE *f,*f1;
  f=fopen("/home/manel/Projects/project3/project3/src/users.txt","r");
  f1=fopen("/home/manel/Projects/project3/project3/src/user.txt","w");
  if ((f!=NULL) && (f1!=NULL))
{ 
     while (fscanf(f,"%s %s %s %s %s\n",g.nom,g.prenom,g.cin,g.role,g.moddepasse)!=EOF)
   { 
    if (strcmp(cin_gest,g.cin)!=0)
   {    
  	
     fprintf(f1,"%s %s %s %s %s\n",g.nom,g.prenom,g.cin,g.role,g.moddepasse);
        	
   }
}


fclose(f);
fclose(f1);}
  f=fopen("/home/manel/Projects/project3/project3/src/users.txt","w");
  f1=fopen("/home/manel/Projects/project3/project3/src/user.txt","r");
  if ((f!=NULL) && (f1!=NULL))
{ 
     while (fscanf(f1,"%s %s %s %s %s\n",g.nom,g.prenom,g.cin,g.role,g.moddepasse)!=EOF)
   { 
    if (strcmp(cin_gest,g.cin)!=0)
   {    
  	
     fprintf(f,"%s %s %s %s %s\n",g.nom,g.prenom,g.cin,g.role,g.moddepasse);
        	
   }
}
fclose(f);
fclose(f1);
}}
///////////////////////////////////////////acceuil///////////////////////////////////////
void ajouter_acceuil(acceuil l)
{
FILE *f;

f=fopen("/home/manel/Projects/project3/project3/src/acceuil.txt","a+");
if(f!=NULL)
{
fprintf(f,"%s %s %s %s\n",l.adresse,l.tel,l.fax,l.mail);
}
fclose(f);
}



//////////////////////////////////////////login////////////////////////////////////////////////


int verifier(char l[] , char p[] ) { 

char ch1[50] , ch2[50],ch3[50],ch4[50]; 
int r;

FILE * f ; 

f=fopen ("/home/manel/Projects/project3/project3/src/users.txt","r"); 

int test =0;
if (f!=NULL) { 

while(fscanf(f,"%s %s %s %d %s\n",ch1,ch2,ch3,&r,ch4)!=EOF ) {

if ((strcmp(ch3,l)==0) && (strcmp(ch4,p)==0))
return r; }
}
fclose(f);
return -1 ; }



