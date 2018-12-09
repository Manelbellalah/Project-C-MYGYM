
#ifndef FONCTIONM_H
#define FONCTIONM_H
typedef struct adherent
{
   char nom [50];
   char prenom [50];
   char sexe [50];
   char cin [50];
   char numero [50];
   char adresse [50];

}ad;
void ajouter_adh(ad a);
int test_nombre(char c[]);
int existe_adh (char cinn[]); 
int verifier(char l[] , char p[] );
char getnom(char l[] , char p[] );
//////////////////////////medecin//////////////////////////////////////////////////////////////////////////

typedef struct medecin
{
   char nom [50];
   char prenom [50];
   char sexe [50];
   char cin [50];
   char numero [50];
   char adresse [50];

}med;
void ajouter_med(med m);
int existe_med (char cinn[]);

//////////////////////////////////dieteticien//////////////////////////////////////////


typedef struct diete
{
   char nom [50];
   char prenom [50];
   char sexe [50];
   char cin [50];
   char numero [50];
   char adresse [50];

}diet;
void ajouter_diet(diet d);
int existe_diet (char cinn[]);


//////////////////////////////////coach///////////////////////////////////////////////
  
typedef struct coach
{
   char nom [50];
   char prenom [50];
   char sexe [50];
   char cin [50];
   char numero [50];
   char specialite [50];

}coach;
void ajouter_coach(coach c);
int existe_coach (char cinn[]);

////////////////////////////////kine////////////////////////////////////////////////////////

typedef struct kine
{
   char nom [50];
   char prenom [50];
   char sexe [50];
   char cin [50];
   char numero [50];
   char adresse [50];

}kine;
void ajouter_kine(kine k);
int existe_kine (char cinn[]);
//////////////////////////////geration//////////////////////////////////////////////////////
typedef struct geration
{
   char nom [50];
   char prenom [50];
   char cin [50];
   char role [50];
   char moddepasse [50];
   
}geration;
void ajouter_ger(geration g);
int existe_ger (char cinn[]);
//////////////////////////////acceuil///////////////////////////////////////////////////////
typedef struct acceuil
{
   char adresse [50];
   char tel [50];
   char fax [50];
   char mail [50];
   
   
}acceuil;
void ajouter_acceuil(acceuil l);
////////////////////////////planning///////////////////////////////////////////////////////
typedef struct planning
{
   char l8 [30];
   char l10 [30];
   char l14 [30];
   char l16 [30];
   char ma8 [30];
   char ma10 [30];
   char ma14 [30];
   char ma16 [30];
   char me8 [30];
   char me10 [30];
   char me14 [30];
   char me16 [30];
   char j8 [30];
   char j10 [30];
   char j14 [30];
   char j16 [30];
   char v8 [30];
   char v10 [30];
   char v14 [30];
   char v16 [30];
   char s8 [30];
   char s10 [30];
   char s14 [30];
   char s16 [30];
}plan;
/////////////////////////deal/////////////////////////////////////////////////////////
typedef struct deal
{
   char nomdeal [50];
   char typedeal [50];
   char dateB [50];
   char dateE [50];
   char description [50];
   
}deal;

///////////////////////event/////////////////////////////////////////////////////////////////
typedef struct event
{
   char nomevent [50];
   char date [50];
   char infoevent [50];
   
   
}event;
#endif
