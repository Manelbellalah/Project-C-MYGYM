#include <gtk/gtk.h>
#include <stdio.h>
#include <string.h>

//Fiche médicale
typedef struct 
{	int  num;	
	char nom[20];
	char prenom[20];
	char tel[12]; 
	char mail[200];
	int  age;
	int  poids;
	int  taille;
	char groupesanguin[20];
	char antecedent[60];
}Fiche;

void ajouter_fiche(Fiche F);
void afficher_fiche(GtkWidget *Liste);
void supprimer(int num1);
void modifier_fiche(Fiche F);
int verif(int num);
//void modifier(int num[],char nom[],char prenom[],char tel[],char mail[],int age,int poids,int taille,char groupesanguin[],char antecedent[]);

//Disponibilité

typedef struct
{
int numd; //numéro de disponibilité
char njour[20];//nom du jour
int jour;
int mois;
int annee;
char horaire[40];
}Date;

void ajouter_disponibilite(Date d);
void afficher_disponibilite(GtkWidget *Liste);
int veriff(int numero);
void supprim(int num6);
void modifier_disponibilite(Date d);


typedef struct
{
char nom[50]; 
char prenom[50];
char sexe[50];
char cin[50];
char numero[50];
char adresse[50];
}ad;

void ajouter_ad(ad a);



























