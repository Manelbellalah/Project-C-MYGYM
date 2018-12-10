#include <stdio.h>
#include <string.h>
#include "patient.h"
#include <gtk/gtk.h>


//Ajouter un fiche

void ajouter_fiche(Fiche F)
{

 FILE *f;
  f=fopen("/home/fares/Projects/project2/src/fiche.txt","a+");
  if(f!=NULL) 
  {
  fprintf(f,"%d %s %s %s %s %d %d %d %s %s \n",F.num,F.nom,F.prenom,F.tel,F.mail,F.age,F.poids,F.taille,F.groupesanguin,F.antecedent);
  fclose(f);

}

}


//Afficher une fiche


void afficher_fiche(GtkWidget *liste)
{
	enum   
{       
	NUM,        
	NOM,
	PRENOM,
        TEL,
        MAIL,
	AGE,
	POIDS,
	TAILLE,
	GROUPESANGUIN,
	ANTECEDENT,
        COLUMNS
};
        GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;

	char num[10];	
	char nom [30];
	char prenom [30];
	char tel [12];
	char mail [200];
        char age[30];
	char poids[30];
	char taille[30];
	char groupesanguin[20];
	char antecedent[60];
        store=NULL;

       FILE *f;
	
	//store=gtk_tree_view_get_model(liste);	
	if (store==NULL)
	{
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("N° fiche", renderer,"text",NUM, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Nom", renderer,"text",NOM, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);	
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Prenom", renderer,"text",PRENOM, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Tel", renderer,"text",TEL, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Mail", renderer,"text",MAIL, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
		
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Age", renderer,"text",AGE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Poids", renderer,"text",POIDS, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Taille", renderer,"text",TAILLE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Groupe sanguin", 	renderer,"text",GROUPESANGUIN, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Antecedent", renderer,"text",ANTECEDENT, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

               
	
	}

	
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

	f = fopen("/home/fares/Projects/project2/src/fiche.txt","r");
	
	if(f==NULL)
	{

		return;
	}		
	else 

	{ f = fopen("/home/fares/Projects/project2/src/fiche.txt","a+");
              while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s \n",num,nom,prenom,tel,mail,age,poids,taille,groupesanguin,antecedent)!=EOF)
		{
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter,NUM,num, NOM, nom, PRENOM, prenom,TEL,tel,MAIL,mail,AGE,age,POIDS,poids,TAILLE,taille,GROUPESANGUIN,groupesanguin,ANTECEDENT,
antecedent, -1); 
		}
		fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
    g_object_unref (store);
	}
}

//Supprimer une fiche
void supprimer(int num1)
{
FILE *f;
FILE *f1;
Fiche F;
f=fopen("/home/fares/Projects/project2/src/fiche.txt","r");
f1=fopen("doc.txt","a+");
while (fscanf(f,"%d %s %s %s %s %d %d %d %s %s \n",&F.num,F.nom,F.prenom,F.tel,F.mail,&F.age,&F.poids,&F.taille,F.groupesanguin,F.antecedent)!=EOF)
{
	if (F.num!=num1)	
	fprintf(f1,"%d %s %s %s %s %d %d %d %s %s \n",F.num,F.nom,F.prenom,F.tel,F.mail,F.age,F.poids,F.taille,F.groupesanguin,F.antecedent);
}
fclose(f);
fclose(f1);
remove("fiche.txt");
rename("doc.txt","fiche.txt");
}

//Verification du numéro de la fiche

int verif(int num)
{FILE *f;
Fiche F;
int n=0;
f=fopen("/home/fares/Projects/project2/src/fiche.txt","r");

while (fscanf(f,"%d %s %s %s %s %d %d %d %s %s \n",&F.num,F.nom,F.prenom,F.tel,F.mail,&F.age,&F.poids,&F.taille,F.groupesanguin,F.antecedent)!=EOF)
{if (num==F.num)
n=1;
}
return (n);
}

//Modifier une fiche
void modifier_fiche(Fiche F)
{	int num1;	
	char nom1[20];
	char prenom1[20];
	char tel1[12]; 
	char mail1[200];
	int  age1;
	int  poids1;
	int  taille1;
	char groupesanguin1[20];
	char antecedent1[60];

FILE *f;
FILE *f1;

int test=-1;
f=fopen("/home/fares/Projects/project2/src/fiche.txt","r");
f1=fopen("modif.txt","a+");
while (fscanf(f,"%d %s %s %s %s %d %d %d %s %s",&num1,nom1,prenom1,tel1,mail1,&age1,&poids1,&taille1,groupesanguin1,antecedent1)!=EOF)
{if (F.num==num1)
	fprintf(f1,"%d %s %s %s %s %d %d %d %s %s\n",F.num,F.nom,F.prenom,F.tel,F.mail,F.age,F.poids,F.taille,F.groupesanguin,F.antecedent);
else
	fprintf(f1,"%d %s %s %s %s %d %d %d %s %s\n",num1,nom1,prenom1,tel1,mail1,age1,poids1,taille1,groupesanguin1,antecedent1);
}
fclose(f);
fclose(f1);
remove("fiche.txt");
rename("modif.txt","fiche.txt");
}

//Ajouter une disponibilité

void ajouter_disponibilite(Date d)
{

 FILE *f3;
  f3=fopen("/home/fares/Projects/project2/src/dispo.txt","a+");
  if(f3!=NULL) 
  {
  fprintf(f3,"%d %s %d %d %d %s\n",d.numd,d.njour,d.jour,d.mois,d.annee,d.horaire);
  fclose(f3);

}

}

//Afficher disponibilité

void afficher_disponibilite(GtkWidget *liste)
{
	enum   
{       
	NUMD,  //numero de dispo.      
	NJOUR, // nom du jour
	JOUR,	
	MOIS,
        ANNEE,
        HORAIRE,
        COLUMNS
};
        GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;

	char numd[10]; //numéro de disponibilité
	char njour[20];//nom du jour
	char jour[10];
	char mois[10];
	char annee[10];
	char horaire[40];
        store=NULL;

       FILE *f;
	
	//store=gtk_tree_view_get_model(liste);	
	if (store==NULL)
	{
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("N°", renderer,"text",NUMD, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Nom Jour", renderer,"text",NJOUR, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);	
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Jour", renderer,"text",JOUR, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Mois", renderer,"text",MOIS, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Année", renderer,"text",ANNEE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
		
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Horaire", renderer,"text",HORAIRE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
               
	
	}

	
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

	f = fopen("/home/fares/Projects/project2/src/dispo.txt","r");
	
	if(f==NULL)
	{

		return;
	}		
	else 

	{ f= fopen("dispo.txt","a+");
              while(fscanf(f,"%s %s %s %s %s %s\n",numd,njour,jour,mois,annee,horaire)!=EOF)
		{
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter,NUMD,numd, NJOUR, njour, JOUR, jour,MOIS,mois,ANNEE,annee,HORAIRE,horaire, -1); 
		}
		fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
    g_object_unref (store);
	}
}

//Verification du numéro de disponibilité

int veriff(int numero)
{FILE *f;
Date d;
int n=0;
f=fopen("/home/fares/Projects/project2/src/dispo.txt","r");

while (fscanf(f,"%d %s %d %d %d %s\n",&d.numd,d.njour,&d.jour,&d.mois,&d.annee,d.horaire)!=EOF)
{if (numero==d.numd)
n=1;
}
return (n);
}

//Supprimer disponibilité

void supprim(int num6)
{
FILE *f;
FILE *f1;
Date d;
f=fopen("/home/fares/Projects/project2/src/dispo.txt","r");
f1=fopen("file.txt","a+");
while (fscanf(f,"%d %s %d %d %d %s\n",&d.numd,d.njour,&d.jour,&d.mois,&d.annee,d.horaire)!=EOF)
{
	if (d.numd!=num6)	
	fprintf(f1,"%d %s %d %d %d %s\n",d.numd,d.njour,d.jour,d.mois,d.annee,d.horaire);
}
fclose(f);
fclose(f1);
remove("dispo.txt");
rename("file.txt","dispo.txt");
}

//Modifier disponibilité
void modifier_disponibilite(Date d)
{	
	int numd1; //numéro de disponibilité
	char njour1[20];//nom du jour
	int jour1;
	int mois1;
	int annee1;
	char horaire1[40];

FILE *f;
FILE *f1;

int test=-1;
f=fopen("/home/fares/Projects/project2/src/dispo.txt","r");
f1=fopen("modisp.txt","a+");
while (fscanf(f,"%d %s %d %d %d %s\n",&numd1,njour1,&jour1,&mois1,&annee1,horaire1)!=EOF)
{if (d.numd==numd1)
	fprintf(f1,"%d %s %d %d %d %s\n",d.numd,d.njour,d.jour,d.mois,d.annee,d.horaire);
else
	fprintf(f1,"%d %s %d %d %d %s\n",numd1,njour1,jour1,mois1,annee1,horaire1);
}
fclose(f);
fclose(f1);
remove("dispo.txt");
rename("modisp.txt","dispo.txt");
}


//Ajouter un adhérent

void ajouter_ad(ad a)
{

 FILE *f;
  f=fopen("/home/fares/Projects/project2/src/adherents.txt","a+");
  if(f!=NULL) 
  {
  fprintf(f,"%s %s %s %s %s %s\n",a.nom,a.prenom,a.sexe,a.cin,a.numero,a.adresse);
  fclose(f);

}

}













