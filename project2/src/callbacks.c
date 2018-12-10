#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "verifier.h"
#include <string.h>
#include "patient.h"
//#include "ajout_Dispo.h"

 
void
on_button1_clicked (GtkWidget       *widget, gpointer         user_data)
{
	GtkWidget *login;
	GtkWidget *Password;
	GtkWidget *role;
	GtkWidget *Admin;
	GtkWidget *medecin;
	
	
	Admin=create_Admin();
	medecin=create_medecin();
	int role2;
	char login3[30];char Password3[30];
	login=lookup_widget(widget,"entry1");
	Password=lookup_widget(widget,"entry2");
	
	strcpy(login3,gtk_entry_get_text(GTK_ENTRY(login)));
	strcpy(Password3,gtk_entry_get_text(GTK_ENTRY(Password)));
	role2 =verifier(login3,Password3);
	switch (role2)
		{case 1:gtk_widget_show(Admin);
			break;
		 case 2:gtk_widget_show(medecin);
                        break;}
	


}


void
on_button2m_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *medecin;
GtkWidget *Ajoutdisp;
Ajoutdisp=create_Ajoutdisp();
gtk_widget_show(Ajoutdisp);
gtk_widget_destroy(medecin);
}


void
on_button3_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *medecin;
GtkWidget *Fiche;//Listee
GtkWidget *treeview1;
Fiche=create_Fiche();
gtk_widget_show(Fiche);
gtk_widget_destroy(medecin);
//treeview1=lookup_widget(Listee,"treeview1");

//afficher_patient(treeview1);
}



void
on_ajouter_patient_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Listee;
GtkWidget *Fiche;
Fiche=create_Fiche();
gtk_widget_show(Fiche);

}


void
on_button9_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
Fiche F;

GtkWidget *Fiche; 
GtkWidget *num,*input1, *input2,*input3,*input4,*age,*poids,*taille,*comboboxentry2,*input5;


Fiche=lookup_widget(objet,"Fiche");

num=lookup_widget(objet,"num");
input1=lookup_widget(objet,"entry4");
input2=lookup_widget(objet,"entry5");
input3=lookup_widget(objet,"entry6");
input4=lookup_widget(objet,"entry7");
input5=lookup_widget(objet,"entry8");
age=lookup_widget(objet,"age");
poids=lookup_widget(objet,"poids");
taille=lookup_widget(objet,"taille");
comboboxentry2=lookup_widget(objet,"comboboxentry2");

F.num=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(num));
strcpy(F.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(F.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(F.mail,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(F.tel,gtk_entry_get_text(GTK_ENTRY(input4)));
F.age=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(age));
F.poids=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(poids));
F.taille=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(taille));
strcpy(F.groupesanguin,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxentry2)));
strcpy(F.antecedent,gtk_entry_get_text(GTK_ENTRY(input5)));

int i=verif(F.num);
if (i==0)
ajouter_fiche(F);

}



void
on_Afficher_clicked                    (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *Fiche;
GtkWidget *Listee;
GtkWidget *treeview1;

Fiche=lookup_widget(objet,"Fiche");


//gtk_widget_destroy(Fiche);
Listee=lookup_widget(objet,"Listee");
Listee=create_Listee();

gtk_widget_show(Listee);
      

treeview1=lookup_widget(Listee,"treeview1");

afficher_fiche(treeview1); 
}


void
on_button12_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Dispo;
GtkWidget *Ajoutdisp;
Ajoutdisp=create_Ajoutdisp();
gtk_widget_show(Ajoutdisp);

}

//button confirmer
/*void
on_button10_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{Date d;
GtkWidget *jour;
GtkWidget *mois;
GtkWidget *annee;
GtkWidget *comboboxentry1;

jour=lookup_widget(objet,"jour");
mois=lookup_widget(objet,"mois");
annee=lookup_widget(objet,"annee");


d.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
d.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
d.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));

ajouter(d);

}
*/


//Afficher disponibilité
/*void
on_button11_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Ajout_disp;
GtkWidget *Dispo;//listee
GtkWidget *treeview2;

Ajout_disp=lookup_widget(objet,"Ajout_disp");


gtk_widget_destroy(Ajout_disp);
Dispo=lookup_widget(objet,"Dispo");
Dispo=create_Dispo();

gtk_widget_show(Dispo);
      

treeview2=lookup_widget(Dispo,"treeview2");

afficher(treeview2); 
}
*/

void
on_button15_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Suppression;
Suppression=create_Suppression();
gtk_widget_show(Suppression);
}

void
on_button14_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
//GtkWidget *Listee;
GtkWidget *Suppression;
//GtkWidget *input6;
GtkWidget *num1;
//GtkWidget *treeview1;

num1=lookup_widget(objet,"num1");
num1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(num1));
//input6=lookup_widget(objet,"entry9");
//strcpy(num1,gtk_entry_get_text(GTK_ENTRY(input6)));
supprimer(num1);
//Listee=create_Listee();
//gtk_widget_show(Listee);
//treeview1=lookup_widget(Listee,"treeview1");
}

void
on_button16_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Fiche;
GtkWidget *Listee;
GtkWidget *treeview1;

Fiche=lookup_widget(objet,"Fiche");
Listee=lookup_widget(objet,"Listee");
Listee=create_Listee();
gtk_widget_show(Listee);
      
treeview1=lookup_widget(Listee,"treeview1");

afficher_fiche(treeview1); 
}



void
on_button10_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
Date d;

GtkWidget *Ajoutdisp; 
GtkWidget *numd,*comboboxentry4,*jour,*mois,*annee,*comboboxentry6;


Ajoutdisp=lookup_widget(objet,"Ajoutdisp");

numd=lookup_widget(objet,"numd");
comboboxentry4=lookup_widget(objet,"comboboxentry4");
jour=lookup_widget(objet,"jour");
mois=lookup_widget(objet,"mois");
annee=lookup_widget(objet,"annee");
comboboxentry6=lookup_widget(objet,"comboboxentry6");

d.numd=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(numd));
strcpy(d.njour,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxentry4)));
d.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
d.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
d.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
strcpy(d.horaire,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxentry6)));


int i=veriff(d.numd);
if (i==0)
ajouter_disponibilite(d);
}

void
on_button11_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Ajoutdisp;
GtkWidget *Dispo;
GtkWidget *treeview2;

Ajoutdisp=lookup_widget(objet,"Ajoutdisp");


//gtk_widget_destroy(Fiche);
Dispo=lookup_widget(objet,"Dispo");
Dispo=create_Dispo();

gtk_widget_show(Dispo);
      

treeview2=lookup_widget(Dispo,"treeview2");

afficher_disponibilite(treeview2);
}

void
on_button13_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *suppr;
suppr=create_suppr();
gtk_widget_show(suppr);
}


void
on_button21_clicked                    (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *suppr;
GtkWidget *num6;
num6=lookup_widget(objet,"num6");
num6=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(num6));
supprim(num6);
}


void
on_button22_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Ajoutdispo;
GtkWidget *Dispo;
GtkWidget *treeview2;

Ajoutdispo=lookup_widget(objet,"Ajoutdispo");
Dispo=lookup_widget(objet,"Dispo");
Dispo=create_Dispo();
gtk_widget_show(Dispo);
      
treeview2=lookup_widget(Dispo,"treeview2");

afficher_disponibilite(treeview2); 

}







void
on_button23_clicked                    (GtkButton       *objet,
                                        gpointer         user_data)
{
Fiche F;

GtkWidget *Fiche; 
GtkWidget *num,*input1, *input2,*input3,*input4,*age,*poids,*taille,*comboboxentry2,*input5;


Fiche=lookup_widget(objet,"Fiche");

num=lookup_widget(objet,"num");
input1=lookup_widget(objet,"entry4");
input2=lookup_widget(objet,"entry5");
input3=lookup_widget(objet,"entry6");
input4=lookup_widget(objet,"entry7");
input5=lookup_widget(objet,"entry8");
age=lookup_widget(objet,"age");
poids=lookup_widget(objet,"poids");
taille=lookup_widget(objet,"taille");
comboboxentry2=lookup_widget(objet,"comboboxentry2");

F.num=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(num));
strcpy(F.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(F.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(F.mail,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(F.tel,gtk_entry_get_text(GTK_ENTRY(input4)));
F.age=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(age));
F.poids=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(poids));
F.taille=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(taille));
strcpy(F.groupesanguin,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxentry2)));
strcpy(F.antecedent,gtk_entry_get_text(GTK_ENTRY(input5)));

modifier_fiche(F);
}


void
on_button24_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *medecin;
medecin=create_medecin();
gtk_widget_show(medecin);
}


void
on_button25_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *medecin;
medecin=create_medecin();
gtk_widget_show(medecin);
}


void
on_button26_clicked                    (GtkButton       *objet,
                                        gpointer         user_data)
{
Date d;

GtkWidget *Ajoutdisp; 
GtkWidget *numd,*comboboxentry4,*jour,*mois,*annee,*comboboxentry6;


Ajoutdisp=lookup_widget(objet,"Ajoutdisp");

numd=lookup_widget(objet,"numd");
comboboxentry4=lookup_widget(objet,"comboboxentry4");
jour=lookup_widget(objet,"jour");
mois=lookup_widget(objet,"mois");
annee=lookup_widget(objet,"annee");
comboboxentry6=lookup_widget(objet,"comboboxentry6");

d.numd=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(numd));
strcpy(d.njour,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxentry4)));
d.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
d.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
d.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
strcpy(d.horaire,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxentry6)));

modifier_disponibilite(d);
}


void
on_button27_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Ajoutdisp;
Ajoutdisp=create_Ajoutdisp();
gtk_widget_show(Ajoutdisp);
}


void
on_button28_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Fiche;
Fiche=create_Fiche();
gtk_widget_show(Fiche);
}


void
on_button29_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Fiche ,*input10, *nom, *prenom, *numero;
ad a;
char cinn[50];

input10=lookup_widget(objet,"entry19");
nom=lookup_widget(objet,"entry4");
prenom=lookup_widget(objet,"entry5");
numero=lookup_widget(objet,"entry7");

strcpy(cinn,gtk_entry_get_text(GTK_ENTRY(input10
)));

FILE *f;
	f=fopen("/home/fares/Projects/project2/src/adherents.txt","r");
	if (f!=NULL)
	{
	while (fscanf(f,"%s %s %s %s %s %s\n",a.nom,a.prenom,a.sexe,a.cin,a.numero,a.adresse)!=EOF)
	 {
	if ((strcmp(a.cin,cinn))==0)
	{
	gtk_entry_set_text (GTK_ENTRY (nom), a.nom);
	gtk_entry_set_text (GTK_ENTRY (prenom), a.prenom);
	gtk_entry_set_text (GTK_ENTRY (numero), a.numero);


	}
	}
	}
	  fclose(f);

}









































