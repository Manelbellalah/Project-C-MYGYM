#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonctionm.h"



void
on_adherent_clicked                    (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *win,*winp;
win=create_adherent ();winp=lookup_widget(obj,"admin");
gtk_widget_show(win);gtk_widget_hide(winp);
}



void
on_dieteticien_clicked                 (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *win,*winp;
win=create_dieteticien ();winp=lookup_widget(obj,"admin");
gtk_widget_show(win);gtk_widget_hide(winp);
}



/*

void
on_retour_admin_clicked                (GtkWidget       *obj,
                                        gpointer         user_data)
{

}


void
on_ajout_clicked                       (GtkWidget       *obj,
                                        gpointer         user_data)
{

}





void
on_afficher_clicked                    (GtkWidget       *obj,
                                        gpointer         user_data)
{

}

*/


void
on_ajout_adherent_clicked              (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *input1 ,*combobox1 ,*input2 , *input3,*input4,*input5,*input6, *output1 ,*output2,*output3,*output4,*output5,*output6,*output7;
ad a;

int r,r1,test;

combobox1 = lookup_widget(obj,"combobox2");


input1 = lookup_widget (obj , "entry1");
input2 = lookup_widget (obj , "entry2");
input3 = lookup_widget (obj , "entry53");
input4 = lookup_widget (obj , "entry4");
input5 = lookup_widget (obj , "entry5");
input6 = lookup_widget (obj , "entry6");
output1 =lookup_widget (obj , "label11");
output2 =lookup_widget (obj , "label18");
output3 =lookup_widget (obj , "label19");
output4 =lookup_widget (obj , "label20");
output5 =lookup_widget (obj , "label21");
output6 =lookup_widget (obj , "label22");
output7 =lookup_widget (obj , "label23");

strcpy(a.sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));

strcpy (a.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy (a.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
//strcpy (a.sexe,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy (a.cin,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy (a.numero,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy (a.adresse,gtk_entry_get_text(GTK_ENTRY(input6)));

r=test_nombre(a.numero);
r1=test_nombre(a.cin);
test=existe_adh(a.cin) ;


if (strcmp(a.nom,"")==0 || strcmp(a.prenom,"")==0 || strcmp(a.sexe,"")==0 || strcmp(a.cin,"")==0 || strcmp(a.numero,"")==0 || strcmp(a.adresse,"")==0) 
{
gtk_label_set_text(GTK_LABEL(output1),"Remplir tous les champs!");
}

else if (strlen(a.nom)<3)
{
gtk_label_set_text(GTK_LABEL(output2),"Le nom doit contenir au moin 4 characteres  ");
}
else if (strlen(a.prenom)<3)
{
gtk_label_set_text(GTK_LABEL(output3),"Le prenom doit contenir au moin 4 characteres  ");
}
 else if((strlen(a.cin)!=8) || (r1==1))
      {
     gtk_label_set_text(GTK_LABEL(output5),"cin doit etre sur 8 chiffres");}
else if((strlen(a.numero)!=8) || (r==1))
      {
     gtk_label_set_text(GTK_LABEL(output6),"numero doit etre sur 8 chiffres");}
 else if (existe_adh(a.cin) ==1)
{
gtk_label_set_text(GTK_LABEL(output1)," echec adherent existe deja ");
}


else  
{
ajouter_adh (a);
gtk_label_set_text(GTK_LABEL(output1),"succés d'ajout");
}

}


void
on_retour_adherent_clicked             (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *win,*winp;
win=create_adherent ();winp=lookup_widget(obj,"ajoutadherent");
gtk_widget_show(win);gtk_widget_hide(winp);

}


void
on_recherche_clicked                   (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *input1,*output1 , *output2 , *output3,*output4,*output5,*output6, *output7;
ad a;
char cinn[50];

input1=lookup_widget(obj,"entry7");
output1=lookup_widget(obj,"entry8");
output2=lookup_widget(obj,"entry9");
output3=lookup_widget(obj,"entry10");
output4=lookup_widget(obj,"entry11");
output5=lookup_widget(obj,"entry12");
output6=lookup_widget(obj,"entry13");
output7=lookup_widget(obj,"label10");

strcpy (cinn,gtk_entry_get_text(GTK_ENTRY(input1)));



FILE *f;
  f=fopen("/home/manel/Projects/project3/project3/src/adherent.txt","r"); 
   if (f!=NULL)
   {
    while (fscanf(f,"%s %s %s %s %s %s\n",a.nom,a.prenom,a.sexe,a.cin,a.numero,a.adresse)!=EOF)
    {
   if ((strcmp(a.cin,cinn))==0)
   {   
     gtk_entry_set_text (GTK_ENTRY (output1), a.nom);
     gtk_entry_set_text (GTK_ENTRY (output2), a.prenom);
     gtk_entry_set_text (GTK_ENTRY (output3), a.sexe);
     gtk_entry_set_text (GTK_ENTRY (output4), a.cin);
     gtk_entry_set_text (GTK_ENTRY (output5), a.numero);
     gtk_entry_set_text (GTK_ENTRY (output6), a.adresse);
     
     

     //break;  
   }
   
        
   }
   }
     fclose(f);    

}


void
on_medecin_clicked                     (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *win,*winp;
win=create_medecin ();winp=lookup_widget(obj,"admin");
gtk_widget_show(win);gtk_widget_hide(winp);

}


void
on_coach_clicked                       (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *win,*winp;
win=create_coach ();winp=lookup_widget(obj,"admin");
gtk_widget_show(win);gtk_widget_hide(winp);
}


void
on_afficher_adh_clicked                (GtkWidget       *obj,
                                        gpointer         user_data)
{
/*GtkWidget *win,*winp;
win=create_afficheradherent ();winp=lookup_widget(obj,"adherent");
gtk_widget_show(win);gtk_widget_hide(winp);*/
GtkWidget *win,*winp;
win=create_affadhtree ();winp=lookup_widget(obj,"adherent");
gtk_widget_show(win);gtk_widget_hide(winp);
}


void
on_ajout_adh_clicked                   (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *win,*winp;
win=create_ajoutadherent ();winp=lookup_widget(obj,"adherent");
gtk_widget_show(win);gtk_widget_hide(winp);

}


void
on_retour_admin_adh_clicked            (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *win,*winp;
win=create_admin ();winp=lookup_widget(obj,"adherent");
gtk_widget_show(win);gtk_widget_hide(winp);

}


void
on_ajout_med_clicked                   (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *win,*winp;
win=create_ajoutmed ();winp=lookup_widget(obj,"medecin");
gtk_widget_show(win);gtk_widget_hide(winp);
}


void
on_afficher_med_clicked                (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *win,*winp;
win=create_medtree();winp=lookup_widget(obj,"medecin");
gtk_widget_show(win);gtk_widget_hide(winp);
}


void
on_retour_admin_med_clicked            (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *win,*winp;
win=create_admin ();winp=lookup_widget(obj,"medecin");
gtk_widget_show(win);gtk_widget_hide(winp);

}


void
on_ajout_coach_clicked                 (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *win,*winp;
win=create_ajoutcach ();winp=lookup_widget(obj,"coach");
gtk_widget_show(win);gtk_widget_hide(winp);

}


void
on_afficher_coach_clicked              (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *win,*winp;
win=create_coachtree ();winp=lookup_widget(obj,"coach");
gtk_widget_show(win);gtk_widget_hide(winp);

}


void
on_retour_admin_coach_clicked          (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *win,*winp;
win=create_admin ();winp=lookup_widget(obj,"coach");
gtk_widget_show(win);gtk_widget_hide(winp);
}


void
on_ajout_diete_clicked                 (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *win,*winp;
win=create_ajoutdiete ();winp=lookup_widget(obj,"dieteticien");
gtk_widget_show(win);gtk_widget_hide(winp);
}


void
on_afficher_diete_clicked              (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *win,*winp;
win=create_diettree ();winp=lookup_widget(obj,"dieteticien");
gtk_widget_show(win);gtk_widget_hide(winp);
}


void
on_retour_admin_diete_clicked          (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *win,*winp;
win=create_admin ();winp=lookup_widget(obj,"dieteticien");
gtk_widget_show(win);gtk_widget_hide(winp);
}


/*void
on_retour_adherent_afficher_clicked    (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *win,*winp;
win=create_adherent ();winp=lookup_widget(obj,"afficheradherent");
gtk_widget_show(win);gtk_widget_hide(winp);
}*/


void
on_ajoutmedecin_clicked                (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *input1 ,*combobox1, *input2 , *input3,*input4,*input5,*input6, *output1 ,*output2,*output3,*output4,*output5,*output6,*output7;
med m;
int r,r1,test;

combobox1 = lookup_widget(obj,"combobox4");



input1 = lookup_widget (obj , "entry14");
input2 = lookup_widget (obj , "entry15");
//input3 = lookup_widget (obj , "entry16");
input4 = lookup_widget (obj , "entry17");
input5 = lookup_widget (obj , "entry18");
input6 = lookup_widget (obj , "entry18");
output1 =lookup_widget (obj , "label36");
output2 =lookup_widget (obj , "label30");
output3 =lookup_widget (obj , "label31");
output4 =lookup_widget (obj , "label32");
output5 =lookup_widget (obj , "label33");
output6 =lookup_widget (obj , "label34");
output7 =lookup_widget (obj , "label35");

strcpy(m.sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));


strcpy (m.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy (m.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
//strcpy (m.sexe,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy (m.cin,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy (m.numero,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy (m.adresse,gtk_entry_get_text(GTK_ENTRY(input6)));

r=test_nombre(m.numero);
r1=test_nombre(m.cin);
test=existe_med(m.cin) ;


if (strcmp(m.nom,"")==0 || strcmp(m.prenom,"")==0 || strcmp(m.sexe,"")==0 || strcmp(m.cin,"")==0 || strcmp(m.numero,"")==0 || strcmp(m.adresse,"")==0) 
{
gtk_label_set_text(GTK_LABEL(output1),"Remplir tous les champs!");
}

else if (strlen(m.nom)<3)
{
gtk_label_set_text(GTK_LABEL(output2),"Le nom doit contenir au moin 4 characteres  ");
}
else if (strlen(m.prenom)<3)
{
gtk_label_set_text(GTK_LABEL(output3),"Le prenom doit contenir au moin 4 characteres  ");
}
 else if((strlen(m.cin)!=8) || (r1==1))
      {
     gtk_label_set_text(GTK_LABEL(output5),"cin doit etre sur 8 chiffres");}
else if((strlen(m.numero)!=8) || (r==1))
      {
     gtk_label_set_text(GTK_LABEL(output6),"numero doit etre sur 8 chiffres");}
 else if (existe_med(m.cin) ==1)
{
gtk_label_set_text(GTK_LABEL(output1)," echec medecin existe deja ");
}


else  
{
ajouter_med (m);
gtk_label_set_text(GTK_LABEL(output1),"succés d'ajout");
}



}


void
on_retour_medecin_clicked              (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *win,*winp;
win=create_medecin ();winp=lookup_widget(obj,"ajoutmed");
gtk_widget_show(win);gtk_widget_hide(winp);
}


void
on_cherchermed_clicked                 (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *input1,*output1 , *output2 , *output3,*output4,*output5,*output6, *output7;
med m;
char cinn[50];

input1=lookup_widget(obj,"entry20");
output1=lookup_widget(obj,"entry21");
output2=lookup_widget(obj,"entry22");
output3=lookup_widget(obj,"entry23");
output4=lookup_widget(obj,"entry24");
output5=lookup_widget(obj,"entry25");
output6=lookup_widget(obj,"entry26");
output7=lookup_widget(obj,"label41");

strcpy (cinn,gtk_entry_get_text(GTK_ENTRY(input1)));



FILE *f;
  f=fopen("/home/manel/Projects/project3/project3/src/medecin.txt","r"); 
   if (f!=NULL)
   {
    while (fscanf(f,"%s %s %s %s %s %s\n",m.nom,m.prenom,m.sexe,m.cin,m.numero,m.adresse)!=EOF)
    {
   if ((strcmp(m.cin,cinn))==0)
   {   
     gtk_entry_set_text (GTK_ENTRY (output1), m.nom);
     gtk_entry_set_text (GTK_ENTRY (output2), m.prenom);
     gtk_entry_set_text (GTK_ENTRY (output3), m.sexe);
     gtk_entry_set_text (GTK_ENTRY (output4), m.cin);
     gtk_entry_set_text (GTK_ENTRY (output5), m.numero);
     gtk_entry_set_text (GTK_ENTRY (output6), m.adresse);
     
     

     //break;  
   }
   
        
   }
   }
     fclose(f);    

}





void
on_retour_affmed_clicked               (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *win,*winp;
win=create_medecin ();winp=lookup_widget(obj,"affichermed");
gtk_widget_show(win);gtk_widget_hide(winp);
}


void
on_ajouter_dieteticien_clicked         (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *input1 ,*combobox1, *input2 , *input3,*input4,*input5,*input6, *output1 ,*output2,*output3,*output4,*output5,*output6,*output7;
diet d;
int r,r1,test;
combobox1 = lookup_widget(obj,"combobox5");


input1 = lookup_widget (obj , "entry27");
input2 = lookup_widget (obj , "entry28");
//input3 = lookup_widget (obj , "entry29");
input4 = lookup_widget (obj , "entry30");
input5 = lookup_widget (obj , "entry31");
input6 = lookup_widget (obj , "entry32");
output1 =lookup_widget (obj , "label54");
output2 =lookup_widget (obj , "label48");
output3 =lookup_widget (obj , "label49");
output4 =lookup_widget (obj , "label50");
output5 =lookup_widget (obj , "label51");
output6 =lookup_widget (obj , "label52");
output7 =lookup_widget (obj , "label53");

strcpy(d.sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));


strcpy (d.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy (d.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
//strcpy (d.sexe,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy (d.cin,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy (d.numero,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy (d.adresse,gtk_entry_get_text(GTK_ENTRY(input6)));

r=test_nombre(d.numero);
r1=test_nombre(d.cin);
test=existe_diet(d.cin) ;


if (strcmp(d.nom,"")==0 || strcmp(d.prenom,"")==0 || strcmp(d.sexe,"")==0 || strcmp(d.cin,"")==0 || strcmp(d.numero,"")==0 || strcmp(d.adresse,"")==0) 
{
gtk_label_set_text(GTK_LABEL(output1),"Remplir tous les champs!");
}

else if (strlen(d.nom)<3)
{
gtk_label_set_text(GTK_LABEL(output2),"Le nom doit contenir au moin 4 characteres  ");
}
else if (strlen(d.prenom)<3)
{
gtk_label_set_text(GTK_LABEL(output3),"Le prenom doit contenir au moin 4 characteres  ");
}
 else if((strlen(d.cin)!=8) || (r1==1))
      {
     gtk_label_set_text(GTK_LABEL(output5),"cin doit etre sur 8 chiffres");}
else if((strlen(d.numero)!=8) || (r==1))
      {
     gtk_label_set_text(GTK_LABEL(output6),"numero doit etre sur 8 chiffres");}
 else if (existe_diet(d.cin) ==1)
{
gtk_label_set_text(GTK_LABEL(output1)," echec dieteticien existe deja ");
}


else  
{
ajouter_diet (d);
gtk_label_set_text(GTK_LABEL(output1),"succés d'ajout");
}

}




void
on_chercher_diete_clicked              (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *input1,*output1 , *output2 , *output3,*output4,*output5,*output6, *output7;
diet d;
char cinn[50];

input1=lookup_widget(obj,"entry33");
output1=lookup_widget(obj,"entry34");
output2=lookup_widget(obj,"entry35");
output3=lookup_widget(obj,"entry36");
output4=lookup_widget(obj,"entry37");
output5=lookup_widget(obj,"entry38");
output6=lookup_widget(obj,"entry39");
output7=lookup_widget(obj,"label65");

strcpy (cinn,gtk_entry_get_text(GTK_ENTRY(input1)));



FILE *f;
  f=fopen("/home/manel/Projects/project3/project3/src/dieteticien.txt","r"); 
   if (f!=NULL)
   {
    while (fscanf(f,"%s %s %s %s %s %s\n",d.nom,d.prenom,d.sexe,d.cin,d.numero,d.adresse)!=EOF)
    {
   if ((strcmp(d.cin,cinn))==0)
   {   
     gtk_entry_set_text (GTK_ENTRY (output1), d.nom);
     gtk_entry_set_text (GTK_ENTRY (output2), d.prenom);
     gtk_entry_set_text (GTK_ENTRY (output3), d.sexe);
     gtk_entry_set_text (GTK_ENTRY (output4), d.cin);
     gtk_entry_set_text (GTK_ENTRY (output5), d.numero);
     gtk_entry_set_text (GTK_ENTRY (output6), d.adresse);
     
     

     //break;  
   }
   
        
   }
   }
     fclose(f);    

}





void
on_retout_aff_diete_clicked            (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *win,*winp;
win=create_dieteticien ();winp=lookup_widget(obj,"afficherdiete");
gtk_widget_show(win);gtk_widget_hide(winp);
}


void
on_retour_diete_clicked                (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *win,*winp;
win=create_dieteticien ();winp=lookup_widget(obj,"ajoutdiete");
gtk_widget_show(win);gtk_widget_hide(winp);
}


void
on_ajout_coachh_clicked                (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *input1 ,*combobox1,*combobox2, *input2 , *input3,*input4,*input5,*input6, *output1 ,*output2,*output3,*output4,*output5,*output6;
coach c;
int r,r1,test;

combobox1 = lookup_widget(obj,"combobox6");
combobox2 = lookup_widget(obj,"combobox7");

input1 = lookup_widget (obj , "entry40");
input2 = lookup_widget (obj , "entry41");
//input3 = lookup_widget (obj , "entry42");
input4 = lookup_widget (obj , "entry43");
input5 = lookup_widget (obj , "entry44");
input6 = lookup_widget (obj , "entry45");
output1 =lookup_widget (obj , "label75");
output2 =lookup_widget (obj , "label69");
output3 =lookup_widget (obj , "label70");
output4 =lookup_widget (obj , "label71");
output5 =lookup_widget (obj , "label72");

output6 =lookup_widget (obj , "label74");

strcpy(c.sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));
strcpy(c.specialite,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)));

strcpy (c.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy (c.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy (c.cin,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy (c.numero,gtk_entry_get_text(GTK_ENTRY(input5)));


r=test_nombre(c.numero);
r1=test_nombre(c.cin);
test=existe_coach(c.cin) ;


if (strcmp(c.nom,"")==0 || strcmp(c.prenom,"")==0 || strcmp(c.sexe,"")==0 || strcmp(c.cin,"")==0 || strcmp(c.numero,"")==0 || strcmp(c.specialite,"")==0)  
{
gtk_label_set_text(GTK_LABEL(output1),"Remplir tous les champs!");
}

else if (strlen(c.nom)<3)
{
gtk_label_set_text(GTK_LABEL(output2),"Le nom doit contenir au moin 4 characteres  ");
}
else if (strlen(c.prenom)<3)
{
gtk_label_set_text(GTK_LABEL(output3),"Le prenom doit contenir au moin 4 characteres  ");
}
 else if((strlen(c.cin)!=8) || (r1==1))
      {
     gtk_label_set_text(GTK_LABEL(output5),"cin doit etre sur 8 chiffres");}
else if((strlen(c.numero)!=8) || (r==1))
      {
     gtk_label_set_text(GTK_LABEL(output6),"numero doit etre sur 8 chiffres");}
 else if (existe_coach(c.cin) ==1)
{
gtk_label_set_text(GTK_LABEL(output1)," echec coach existe deja ");
}


else  
{
ajouter_coach (c);
gtk_label_set_text(GTK_LABEL(output1),"succés d'ajout");
}

}




void
on_retour_ajout_coach_clicked          (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *win,*winp;
win=create_coach ();winp=lookup_widget(obj,"ajoutcach");
gtk_widget_show(win);gtk_widget_hide(winp);

}


void
on_chercher_coach_clicked              (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *input1,*output1 , *output2 , *output3,*output4,*output5,*output6, *output7;
coach c;
char cinn[50];

input1=lookup_widget(obj,"entry46");
output1=lookup_widget(obj,"entry47");
output2=lookup_widget(obj,"entry48");
output3=lookup_widget(obj,"entry49");
output4=lookup_widget(obj,"entry50");
output5=lookup_widget(obj,"entry51");
output6=lookup_widget(obj,"entry52");
output7=lookup_widget(obj,"label86");

strcpy (cinn,gtk_entry_get_text(GTK_ENTRY(input1)));



FILE *f;
  f=fopen("/home/manel/Projects/project3/project3/src/coach.txt","r"); 
   if (f!=NULL)
   {
    while (fscanf(f,"%s %s %s %s %s %s\n",c.nom,c.prenom,c.sexe,c.cin,c.numero,c.specialite)!=EOF)
    {
   if ((strcmp(c.cin,cinn))==0)
   {   
     gtk_entry_set_text (GTK_ENTRY (output1), c.nom);
     gtk_entry_set_text (GTK_ENTRY (output2), c.prenom);
     gtk_entry_set_text (GTK_ENTRY (output3), c.sexe);
     gtk_entry_set_text (GTK_ENTRY (output4), c.cin);
     gtk_entry_set_text (GTK_ENTRY (output5), c.numero);
     gtk_entry_set_text (GTK_ENTRY (output6), c.specialite);
     
     

     //break;  
   }
   
        
   }
   }
     fclose(f);    

}




void
on_retour_aff_coach_clicked            (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *win,*winp;
win=create_coach ();winp=lookup_widget(obj,"affichercoach");
gtk_widget_show(win);gtk_widget_hide(winp);

}


void
on_retour_adherent_tree_clicked        (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *win,*winp;
win=create_adherent ();winp=lookup_widget(obj,"affadhtree");
gtk_widget_show(win);gtk_widget_hide(winp);
}


void
on_afficher_adherent_tree_clicked      (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *tree ; 
tree=lookup_widget(obj,"treeview1") ; 
afficher(tree) ;
}


void
on_modifier_adh_clicked                (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *win,*winp;
win=create_modifieradh ();winp=lookup_widget(obj,"adherent");
gtk_widget_show(win);gtk_widget_hide(winp);

}


void
on_supprimer_adh_clicked               (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *win,*winp;
win=create_supprimeradh ();winp=lookup_widget(obj,"adherent");
gtk_widget_show(win);gtk_widget_hide(winp);
}


void
on_modifier_med_clicked                (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *win,*winp;
win=create_modifiermed ();winp=lookup_widget(obj,"medecin");
gtk_widget_show(win);gtk_widget_hide(winp);

}


void
on_supprimer_med_clicked               (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *win,*winp;
win=create_supprimermed();winp=lookup_widget(obj,"medecin");
gtk_widget_show(win);gtk_widget_hide(winp);
}


void
on_supprimer_coach_clicked             (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *win,*winp;
win=create_supprimercoach ();winp=lookup_widget(obj,"coach");
gtk_widget_show(win);gtk_widget_hide(winp);
}


void
on_modifier_coach_clicked              (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *win,*winp;
win=create_modifiercoach ();winp=lookup_widget(obj,"coach");
gtk_widget_show(win);gtk_widget_hide(winp);

}


void
on_supprimer_diete_clicked             (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *win,*winp;
win=create_supprimerdiete ();winp=lookup_widget(obj,"dieteticien");
gtk_widget_show(win);gtk_widget_hide(winp);
}


void
on_modifier_diete_clicked              (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *win,*winp;
win=create_modifierdiete ();winp=lookup_widget(obj,"dieteticien");
gtk_widget_show(win);gtk_widget_hide(winp);
}


void
on_modifier_adherent_clicked           (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *input1,*output1 , *output2 , *output3,*output4,*output5,*output6, *output7;
ad a;
char cinn[50];

input1=lookup_widget(obj,"entry54");
output1=lookup_widget(obj,"entry55");
output2=lookup_widget(obj,"entry56");
output3=lookup_widget(obj,"entry57");
output4=lookup_widget(obj,"entry58");
output5=lookup_widget(obj,"entry59");
output6=lookup_widget(obj,"entry60");
output7=lookup_widget(obj,"label110");

strcpy (cinn,gtk_entry_get_text(GTK_ENTRY(input1)));



FILE *f;
  f=fopen("/home/manel/Projects/project3/project3/src/adherent.txt","r"); 
   if (f!=NULL)
   {
    while (fscanf(f,"%s %s %s %s %s %s\n",a.nom,a.prenom,a.sexe,a.cin,a.numero,a.adresse)!=EOF)
    {
   if ((strcmp(a.cin,cinn))==0)
   {   
     gtk_entry_set_text (GTK_ENTRY (output1), a.nom);
     gtk_entry_set_text (GTK_ENTRY (output2), a.prenom);
     gtk_entry_set_text (GTK_ENTRY (output3), a.sexe);
     gtk_entry_set_text (GTK_ENTRY (output4), a.cin);
     gtk_entry_set_text (GTK_ENTRY (output5), a.numero);
     gtk_entry_set_text (GTK_ENTRY (output6), a.adresse);
     
     

     //break;  
   }
   
        
   }
   }
     fclose(f);    

}




void
on_retour_modadh_adh_clicked           (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *win,*winp;
win=create_adherent ();winp=lookup_widget(obj,"modifieradh");
gtk_widget_show(win);gtk_widget_hide(winp);

}


void
on_modifier_medecin_clicked            (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *input1,*output1 , *output2 , *output3,*output4,*output5,*output6, *output7;
med m;
char cinn[50];

input1=lookup_widget(obj,"entry61");
output1=lookup_widget(obj,"entry62");
output2=lookup_widget(obj,"entry63");
output3=lookup_widget(obj,"entry64");
output4=lookup_widget(obj,"entry65");
output5=lookup_widget(obj,"entry66");
output6=lookup_widget(obj,"entry67");
output7=lookup_widget(obj,"label118");

strcpy (cinn,gtk_entry_get_text(GTK_ENTRY(input1)));



FILE *f;
  f=fopen("/home/manel/Projects/project3/project3/src/medecin.txt","r"); 
   if (f!=NULL)
   {
    while (fscanf(f,"%s %s %s %s %s %s\n",m.nom,m.prenom,m.sexe,m.cin,m.numero,m.adresse)!=EOF)
    {
   if ((strcmp(m.cin,cinn))==0)
   {   
     gtk_entry_set_text (GTK_ENTRY (output1), m.nom);
     gtk_entry_set_text (GTK_ENTRY (output2), m.prenom);
     gtk_entry_set_text (GTK_ENTRY (output3), m.sexe);
     gtk_entry_set_text (GTK_ENTRY (output4), m.cin);
     gtk_entry_set_text (GTK_ENTRY (output5), m.numero);
     gtk_entry_set_text (GTK_ENTRY (output6), m.adresse);
     
     

     //break;  
   }
   
        
   }
   }
     fclose(f);    


}


void
on_retour_modmed_clicked               (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *win,*winp;
win=create_medecin ();winp=lookup_widget(obj,"modifiermed");
gtk_widget_show(win);gtk_widget_hide(winp);

}


void
on_retour_modiete_clicked              (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *win,*winp;
win=create_dieteticien();winp=lookup_widget(obj,"modifierdiete");
gtk_widget_show(win);gtk_widget_hide(winp);
}


void
on_modifier_dieteticien_clicked        (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *input1,*output1 , *output2 , *output3,*output4,*output5,*output6, *output7;
diet m;
char cinn[50];

input1=lookup_widget(obj,"entry68");
output1=lookup_widget(obj,"entry69");
output2=lookup_widget(obj,"entry70");
output3=lookup_widget(obj,"entry71");
output4=lookup_widget(obj,"entry72");
output5=lookup_widget(obj,"entry73");
output6=lookup_widget(obj,"entry74");
output7=lookup_widget(obj,"label126");

strcpy (cinn,gtk_entry_get_text(GTK_ENTRY(input1)));



FILE *f;
  f=fopen("/home/manel/Projects/project3/project3/src/dieteticien.txt","r"); 
   if (f!=NULL)
   {
    while (fscanf(f,"%s %s %s %s %s %s\n",m.nom,m.prenom,m.sexe,m.cin,m.numero,m.adresse)!=EOF)
    {
   if ((strcmp(m.cin,cinn))==0)
   {   
     gtk_entry_set_text (GTK_ENTRY (output1), m.nom);
     gtk_entry_set_text (GTK_ENTRY (output2), m.prenom);
     gtk_entry_set_text (GTK_ENTRY (output3), m.sexe);
     gtk_entry_set_text (GTK_ENTRY (output4), m.cin);
     gtk_entry_set_text (GTK_ENTRY (output5), m.numero);
     gtk_entry_set_text (GTK_ENTRY (output6), m.adresse);
     
     

     //break;  
   }
   
        
   }
   }
     fclose(f);    



}


void
on_modifier_coach_mod_clicked          (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *input1,*output1 , *output2 , *output3,*output4,*output5,*output6, *output7;
coach c;
char cinn[50];

input1=lookup_widget(obj,"entry75");
output1=lookup_widget(obj,"entry76");
output2=lookup_widget(obj,"entry77");
output3=lookup_widget(obj,"entry78");
output4=lookup_widget(obj,"entry79");
output5=lookup_widget(obj,"entry80");
output6=lookup_widget(obj,"entry81");
output7=lookup_widget(obj,"label134");


strcpy (cinn,gtk_entry_get_text(GTK_ENTRY(input1)));



FILE *f;
  f=fopen("/home/manel/Projects/project3/project3/src/coach.txt","r"); 
   if (f!=NULL)
   {
    while (fscanf(f,"%s %s %s %s %s %s\n",c.nom,c.prenom,c.sexe,c.cin,c.numero,c.specialite)!=EOF)
    {
   if ((strcmp(c.cin,cinn))==0)
   {   
     gtk_entry_set_text (GTK_ENTRY (output1), c.nom);
     gtk_entry_set_text (GTK_ENTRY (output2), c.prenom);
     gtk_entry_set_text (GTK_ENTRY (output3), c.sexe);
     gtk_entry_set_text (GTK_ENTRY (output4), c.cin);
     gtk_entry_set_text (GTK_ENTRY (output5), c.numero);
     gtk_entry_set_text (GTK_ENTRY (output6), c.specialite);
     
     

     //break;  
   }
   
        
   }
   }
     fclose(f);    




}


void
on_retour_modcoach_clicked             (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *win,*winp;
win=create_coach ();winp=lookup_widget(obj,"modifiercoach");
gtk_widget_show(win);gtk_widget_hide(winp);

}


void
on_valider_modadh_clicked              (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *input1,*input2 , *input3 , *input4,*input5,*input6,*input7, *output8;
ad a;
char cinn[50];

input1=lookup_widget(obj,"entry54");
input2=lookup_widget(obj,"entry55");
input3=lookup_widget(obj,"entry56");
input4=lookup_widget(obj,"entry57");
input5=lookup_widget(obj,"entry58");
input6=lookup_widget(obj,"entry59");
input7=lookup_widget(obj,"entry60");
output8=lookup_widget(obj,"label110");

strcpy (cinn,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy (a.nom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy (a.prenom,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy (a.sexe,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy (a.cin,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy (a.numero,gtk_entry_get_text(GTK_ENTRY(input6)));
strcpy (a.adresse,gtk_entry_get_text(GTK_ENTRY(input7)));

modifierr_adherent(a,cinn);
gtk_label_set_text(GTK_LABEL(output8),"modifié avec succés") ;
}


void
on_valider_modmed_clicked              (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *input1,*input2 , *input3 , *input4,*input5,*input6,*input7, *output8;
med m ;
char cinn[50];

input1=lookup_widget(obj,"entry61");
input2=lookup_widget(obj,"entry62");
input3=lookup_widget(obj,"entry63");
input4=lookup_widget(obj,"entry64");
input5=lookup_widget(obj,"entry65");
input6=lookup_widget(obj,"entry66");
input7=lookup_widget(obj,"entry67");
output8=lookup_widget(obj,"label118");

strcpy (cinn,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy (m.nom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy (m.prenom,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy (m.sexe,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy (m.cin,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy (m.numero,gtk_entry_get_text(GTK_ENTRY(input6)));
strcpy (m.adresse,gtk_entry_get_text(GTK_ENTRY(input7)));

modifierr_medecin(m,cinn);
gtk_label_set_text(GTK_LABEL(output8),"modifié avec succés") ;

}


void
on_valider_modiete_clicked             (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *input1,*input2 , *input3 , *input4,*input5,*input6,*input7, *output8;
diet a;
char cinn[50];

input1=lookup_widget(obj,"entry68");
input2=lookup_widget(obj,"entry69");
input3=lookup_widget(obj,"entry70");
input4=lookup_widget(obj,"entry71");
input5=lookup_widget(obj,"entry72");
input6=lookup_widget(obj,"entry73");
input7=lookup_widget(obj,"entry74");
output8=lookup_widget(obj,"label126");

strcpy (cinn,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy (a.nom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy (a.prenom,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy (a.sexe,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy (a.cin,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy (a.numero,gtk_entry_get_text(GTK_ENTRY(input6)));
strcpy (a.adresse,gtk_entry_get_text(GTK_ENTRY(input7)));

modifierr_dieteticien(a,cinn);
gtk_label_set_text(GTK_LABEL(output8),"modifié avec succés") ;

}


void
on_valider_modcoach_clicked            (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *input1,*input2 , *input3 , *input4,*input5,*input6,*input7, *output8;
coach c ;
char cinn[50];

input1=lookup_widget(obj,"entry75");
input2=lookup_widget(obj,"entry76");
input3=lookup_widget(obj,"entry77");
input4=lookup_widget(obj,"entry78");
input5=lookup_widget(obj,"entry79");
input6=lookup_widget(obj,"entry80");
input7=lookup_widget(obj,"entry81");
output8=lookup_widget(obj,"label134");

strcpy (cinn,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy (c.nom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy (c.prenom,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy (c.sexe,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy (c.cin,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy (c.numero,gtk_entry_get_text(GTK_ENTRY(input6)));
strcpy (c.specialite,gtk_entry_get_text(GTK_ENTRY(input7)));

modifierr_coach(c,cinn);
gtk_label_set_text(GTK_LABEL(output8),"modifié avec succés") ;


}


void
on_retour_suppadh_clicked              (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *win,*winp;
win=create_adherent ();winp=lookup_widget(obj,"supprimeradh");
gtk_widget_show(win);gtk_widget_hide(winp);
}


void
on_supp_adh_clicked                    (GtkWidget       *obj,
                                        gpointer         user_data)
{
char asupprimer[50];
int x;
GtkWidget *input1; GtkWidget *output1;

input1=lookup_widget(obj,"entry82");
output1=lookup_widget(obj,"label136");
strcpy (asupprimer,gtk_entry_get_text(GTK_ENTRY(input1)));
supprimer_adh(asupprimer);
x=existe_adh(asupprimer);
if(x!=1)
{
gtk_label_set_text(GTK_LABEL(output1),"Succès de suppression!");
}
else
{
gtk_label_set_text(GTK_LABEL(output1),"Erreur, reessayez!");
}

}


void
on_retour_suppmed_clicked              (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *win,*winp;
win=create_medecin ();winp=lookup_widget(obj,"supprimermed");
gtk_widget_show(win);gtk_widget_hide(winp);
}


void
on_supp_med_clicked                    (GtkWidget       *obj,
                                        gpointer         user_data)
{
char asupprimer[50];
int x;
GtkWidget *input1; GtkWidget *output1;

input1=lookup_widget(obj,"entry83");
output1=lookup_widget(obj,"label138");
strcpy (asupprimer,gtk_entry_get_text(GTK_ENTRY(input1)));
supprimer_med(asupprimer);
x=existe_med(asupprimer);
if(x!=1)
{
gtk_label_set_text(GTK_LABEL(output1),"Succès de suppression!");
}
else
{
gtk_label_set_text(GTK_LABEL(output1),"Erreur, reessayez!");
}


}


void
on_supp_diete_clicked                  (GtkWidget       *obj,
                                        gpointer         user_data)
{
char asupprimer[50];
int x;
GtkWidget *input1; GtkWidget *output1;

input1=lookup_widget(obj,"entry84");
output1=lookup_widget(obj,"label140");
strcpy (asupprimer,gtk_entry_get_text(GTK_ENTRY(input1)));
supprimer_diete(asupprimer);
x=existe_diet(asupprimer);
if(x!=1)
{
gtk_label_set_text(GTK_LABEL(output1),"Succès de suppression!");
}
else
{
gtk_label_set_text(GTK_LABEL(output1),"Erreur, reessayez!");
}

}


void
on_retour_suppdiete_clicked            (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *win,*winp;
win=create_dieteticien();winp=lookup_widget(obj,"supprimerdiete");
gtk_widget_show(win);gtk_widget_hide(winp);
}


void
on_supp_coach_clicked                  (GtkWidget       *obj,
                                        gpointer         user_data)
{
char asupprimer[50];
int x;
GtkWidget *input1; GtkWidget *output1;

input1=lookup_widget(obj,"entry85");
output1=lookup_widget(obj,"label142");
strcpy (asupprimer,gtk_entry_get_text(GTK_ENTRY(input1)));
supprimer_coach(asupprimer);
x=existe_coach(asupprimer);
if(x!=1)
{
gtk_label_set_text(GTK_LABEL(output1),"Succès de suppression!");
}
else
{
gtk_label_set_text(GTK_LABEL(output1),"Erreur, reessayez!");
}

}


void
on_retour_suppcoach_clicked            (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *win,*winp;
win=create_coach ();winp=lookup_widget(obj,"supprimercoach");
gtk_widget_show(win);gtk_widget_hide(winp);
}


void
on_med_tree_clicked                    (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *tree ; 
tree=lookup_widget(obj,"treeview2") ; 
affichermed(tree) ;
}


void
on_retour_tree_med_clicked             (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *win,*winp;
win=create_medecin ();winp=lookup_widget(obj,"medtree");
gtk_widget_show(win);gtk_widget_hide(winp);

}


void
on_retour_tree_diet_clicked            (GtkWidget       *obj,
                                        gpointer         user_data)
{GtkWidget *win,*winp;
win=create_dieteticien ();winp=lookup_widget(obj,"diettree");
gtk_widget_show(win);gtk_widget_hide(winp);

}


void
on_affiche_tree_coech_clicked          (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *tree ; 
tree=lookup_widget(obj,"treeview7") ; 
affichercoach(tree) ;
}


void
on_retour_tree_coech_clicked           (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *win,*winp;
win=create_coach ();winp=lookup_widget(obj,"coachtree");
gtk_widget_show(win);gtk_widget_hide(winp);
}

void
on_affiche_tree_diet_clicked           (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *tree ; 
tree=lookup_widget(obj,"treeview3") ; 
afficherdiete(tree) ;
}
//////////////////////////////////////////////////////////////////////

void
on_kine_clicked                        (GtkWidget       *obj,
                                        gpointer         user_data)
{GtkWidget *win,*winp;
win=create_kine ();winp=lookup_widget(obj,"admin");
gtk_widget_show(win);gtk_widget_hide(winp);

}



void
on_ajouter_kine_clicked                (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *win,*winp;
win=create_ajouterkine ();winp=lookup_widget(obj,"kine");
gtk_widget_show(win);gtk_widget_hide(winp);

}


void
on_modifier_kine_clicked               (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *win,*winp;
win=create_modifierkine ();winp=lookup_widget(obj,"kine");
gtk_widget_show(win);gtk_widget_hide(winp);
}


void
on_afficher_kine_clicked               (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *win,*winp;
win=create_treekine ();winp=lookup_widget(obj,"kine");
gtk_widget_show(win);gtk_widget_hide(winp);
}


void
on_retour_kine_admin_clicked           (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *win,*winp;
win=create_admin ();winp=lookup_widget(obj,"kine");
gtk_widget_show(win);gtk_widget_hide(winp);
}


void
on_val_ajoutkine_clicked               (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *input1 ,*combobox1 ,*input2 , *input3,*input4,*input5,*input6, *output1 ,*output2,*output3,*output4,*output5,*output6,*output7;
kine a;

int r,r1,test;

combobox1 = lookup_widget(obj,"combobox3");


input1 = lookup_widget (obj , "entry86");
input2 = lookup_widget (obj , "entry87");
input3 = lookup_widget (obj , "entry88");
input4 = lookup_widget (obj , "entry89");
input5 = lookup_widget (obj , "entry90");
input6 = lookup_widget (obj , "entry91");
output1 =lookup_widget (obj , "label151");
output2 =lookup_widget (obj , "label152");
output3 =lookup_widget (obj , "label153");
output4 =lookup_widget (obj , "label154");
output5 =lookup_widget (obj , "label155");
output6 =lookup_widget (obj , "label156");
output7 =lookup_widget (obj , "label157");

strcpy(a.sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));

strcpy (a.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy (a.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
//strcpy (a.sexe,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy (a.cin,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy (a.numero,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy (a.adresse,gtk_entry_get_text(GTK_ENTRY(input6)));

r=test_nombre(a.numero);
r1=test_nombre(a.cin);
test=existe_kine(a.cin) ;


if (strcmp(a.nom,"")==0 || strcmp(a.prenom,"")==0 || strcmp(a.sexe,"")==0 || strcmp(a.cin,"")==0 || strcmp(a.numero,"")==0 || strcmp(a.adresse,"")==0) 
{
gtk_label_set_text(GTK_LABEL(output1),"Remplir tous les champs!");
}

else if (strlen(a.nom)<3)
{
gtk_label_set_text(GTK_LABEL(output2),"Le nom doit contenir au moin 4 characteres  ");
}
else if (strlen(a.prenom)<3)
{
gtk_label_set_text(GTK_LABEL(output3),"Le prenom doit contenir au moin 4 characteres  ");
}
 else if((strlen(a.cin)!=8) || (r1==1))
      {
     gtk_label_set_text(GTK_LABEL(output5),"cin doit etre sur 8 chiffres");}
else if((strlen(a.numero)!=8) || (r==1))
      {
     gtk_label_set_text(GTK_LABEL(output6),"numero doit etre sur 8 chiffres");}
 else if (existe_kine(a.cin) ==1)
{
gtk_label_set_text(GTK_LABEL(output1)," echec kine existe deja ");
}


else  
{
ajouter_kine (a);
gtk_label_set_text(GTK_LABEL(output1),"succés d'ajout");
}


}


void
on_retour_ajout_kine_clicked           (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *win,*winp;
win=create_kine ();winp=lookup_widget(obj,"ajouterkine");
gtk_widget_show(win);gtk_widget_hide(winp);
}


void
on_val_cinmodkine_clicked              (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *input1,*output1 , *output2 , *output3,*output4,*output5,*output6, *output7;
kine m;
char cinn[50];

input1=lookup_widget(obj,"entry92");
output1=lookup_widget(obj,"entry93");
output2=lookup_widget(obj,"entry94");
output3=lookup_widget(obj,"entry95");
output4=lookup_widget(obj,"entry96");
output5=lookup_widget(obj,"entry97");
output6=lookup_widget(obj,"entry98");
output7=lookup_widget(obj,"label168");

strcpy (cinn,gtk_entry_get_text(GTK_ENTRY(input1)));



FILE *f;
  f=fopen("/home/manel/Projects/project3/project3/src/kine.txt","r"); 
   if (f!=NULL)
   {
    while (fscanf(f,"%s %s %s %s %s %s\n",m.nom,m.prenom,m.sexe,m.cin,m.numero,m.adresse)!=EOF)
    {
   if ((strcmp(m.cin,cinn))==0)
   {   
     gtk_entry_set_text (GTK_ENTRY (output1), m.nom);
     gtk_entry_set_text (GTK_ENTRY (output2), m.prenom);
     gtk_entry_set_text (GTK_ENTRY (output3), m.sexe);
     gtk_entry_set_text (GTK_ENTRY (output4), m.cin);
     gtk_entry_set_text (GTK_ENTRY (output5), m.numero);
     gtk_entry_set_text (GTK_ENTRY (output6), m.adresse);
     
     

     //break;  
   }
   
        
   }
   }
     fclose(f);    


}


void
on_val_modkine_clicked                 (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *input1,*input2 , *input3 , *input4,*input5,*input6,*input7, *output8;
kine m ;
char cinn[50];

input1=lookup_widget(obj,"entry92");
input2=lookup_widget(obj,"entry93");
input3=lookup_widget(obj,"entry94");
input4=lookup_widget(obj,"entry95");
input5=lookup_widget(obj,"entry96");
input6=lookup_widget(obj,"entry97");
input7=lookup_widget(obj,"entry98");
output8=lookup_widget(obj,"label168");

strcpy (cinn,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy (m.nom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy (m.prenom,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy (m.sexe,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy (m.cin,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy (m.numero,gtk_entry_get_text(GTK_ENTRY(input6)));
strcpy (m.adresse,gtk_entry_get_text(GTK_ENTRY(input7)));

modifierr_kine(m,cinn);
gtk_label_set_text(GTK_LABEL(output8),"modifié avec succés") ;


}


void
on_retour_modkine_kine_clicked         (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *win,*winp;
win=create_kine ();winp=lookup_widget(obj,"modifierkine");
gtk_widget_show(win);gtk_widget_hide(winp);
}


void
on_supprimer_cin_clicked               (GtkWidget       *obj,
                                        gpointer         user_data)
{
char asupprimer[50];
int x;
GtkWidget *input1; GtkWidget *output1;

input1=lookup_widget(obj,"entry99");
output1=lookup_widget(obj,"label170");
strcpy (asupprimer,gtk_entry_get_text(GTK_ENTRY(input1)));
supprimer_kine(asupprimer);
x=existe_kine(asupprimer);
if(x!=1)
{
gtk_label_set_text(GTK_LABEL(output1),"Succès de suppression!");
}
else
{
gtk_label_set_text(GTK_LABEL(output1),"Erreur, reessayez!");
}

}


void
on_retour_suppkine_kine_clicked        (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *win,*winp;
win=create_kine ();winp=lookup_widget(obj,"supprimerkine");
gtk_widget_show(win);gtk_widget_hide(winp);
}


void
on_retour_tree_kine_clicked            (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *win,*winp;
win=create_kine ();winp=lookup_widget(obj,"treekine");
gtk_widget_show(win);gtk_widget_hide(winp);
}


void
on_aff_treekine_clicked                (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *tree ; 
tree=lookup_widget(obj,"treeview5") ; 
afficherkine(tree) ;

}


void
on_supprimer_kine_clicked              (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *win,*winp;
win=create_supprimerkine ();winp=lookup_widget(obj,"kine");
gtk_widget_show(win);gtk_widget_hide(winp);
}

///////////////////////////////////////////////////////////////////////////
void
on_geration_clicked                    (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *win,*winp;
win=create_geration ();winp=lookup_widget(obj,"admin");
gtk_widget_show(win);gtk_widget_hide(winp);
}



void
on_retour_ajout_ges_clicked            (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *win,*winp;
win=create_geration ();winp=lookup_widget(obj,"ajoutgeration");
gtk_widget_show(win);gtk_widget_hide(winp);
}

void
on_retour_gest_admin_clicked           (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *win,*winp;
win=create_admin ();winp=lookup_widget(obj,"geration");
gtk_widget_show(win);gtk_widget_hide(winp);
}


void
on_supp_ges_clicked                    (GtkWidget       *obj,
                                        gpointer         user_data)
{

}


void
on_ajoutf_ges_clicked                  (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *input1  ,*input2 , *input3,*input5, *output1 ,*role;
geration g;

int test;




input1 = lookup_widget (obj , "entry102");
input2 = lookup_widget (obj , "entry103");
input3 = lookup_widget (obj , "entry104");
role = lookup_widget (obj , "spinbutton1");
input5 = lookup_widget (obj , "entry106");

output1 =lookup_widget (obj , "label179");



strcpy (g.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy (g.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy (g.cin,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy (g.role,gtk_entry_get_text(GTK_ENTRY(role)));
strcpy (g.moddepasse,gtk_entry_get_text(GTK_ENTRY(input5)));



test=existe_ger(g.cin) ;

/*
if (strcmp(g.nom,"")==0 || strcmp(g.prenom,"")==0 || strcmp(g.cin,"")==0 || strcmp(g.role,"")==0 || strcmp(g.moddepasse,"")==0 ) 
{
gtk_label_set_text(GTK_LABEL(output1),"Remplir tous les champs!");
}*/

if (existe_ger(g.cin) ==1)
{
gtk_label_set_text(GTK_LABEL(output1)," Echec CIN existe deja ");
}


else  
{
ajouter_ger (g);

gtk_label_set_text(GTK_LABEL(output1),"succés d'ajout");
}
}

void
on_ajout_gest_clicked                  (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *win,*winp;
win=create_ajoutgeration ();winp=lookup_widget(obj,"geration");
gtk_widget_show(win);gtk_widget_hide(winp);
}

void
on_aff_ges_clicked                     (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *win,*winp;
win=create_afftreegest ();winp=lookup_widget(obj,"geration");
gtk_widget_show(win);gtk_widget_hide(winp);
}


void
on_aff_tree_gest_clicked               (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *tree ; 
tree=lookup_widget(obj,"treeview6") ; 
affichergest(tree) ;
}


void
on_mod_ges_clicked                     (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *win,*winp;
win=create_modgest ();winp=lookup_widget(obj,"geration");
gtk_widget_show(win);gtk_widget_hide(winp);
}


void
on_modf_gest_clicked                   (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *input1,*input2 , *input3 , *input4,*input5,*input6, *output8;
geration g ;
char cinn[50];

input1=lookup_widget(obj,"entry119");
input2=lookup_widget(obj,"entry120");
input3=lookup_widget(obj,"entry121");
input4=lookup_widget(obj,"entry122");
input5=lookup_widget(obj,"entry123");
input6=lookup_widget(obj,"entry124");

output8=lookup_widget(obj,"label198");

strcpy (cinn,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy (g.nom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy (g.prenom,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy (g.cin,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy (g.role,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy (g.moddepasse,gtk_entry_get_text(GTK_ENTRY(input6)));


modifierr_gest(g,cinn);
gtk_label_set_text(GTK_LABEL(output8),"modifié avec succés") ;

}


void
on_val_cin_mod_clicked                 (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *input1,*output1 , *output2 , *output3,*output4,*output5,*output6;
geration g;
char cinn[50];

input1=lookup_widget(obj,"entry119");
output1=lookup_widget(obj,"entry120");
output2=lookup_widget(obj,"entry121");
output3=lookup_widget(obj,"entry122");
output4=lookup_widget(obj,"entry123");
output5=lookup_widget(obj,"entry124");

output6=lookup_widget(obj,"label198");

strcpy (cinn,gtk_entry_get_text(GTK_ENTRY(input1)));



FILE *f;
  f=fopen("/home/manel/Projects/project3/project3/src/users.txt","r"); 
   if (f!=NULL)
   {
    while (fscanf(f,"%s %s %s %s %s\n",g.nom,g.prenom,g.cin,g.role,g.moddepasse)!=EOF)
    {
   if ((strcmp(g.cin,cinn))==0)
   {   
     gtk_entry_set_text (GTK_ENTRY (output1), g.nom);
     gtk_entry_set_text (GTK_ENTRY (output2), g.prenom);
     gtk_entry_set_text (GTK_ENTRY (output3), g.cin);
     gtk_entry_set_text (GTK_ENTRY (output4), g.role);
     gtk_entry_set_text (GTK_ENTRY (output5), g.moddepasse);
     
     
     

     //break;  
   }
   
        
   }
   }
     fclose(f);    


}


void
on_retour_mod_gest_clicked             (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *win,*winp;
win=create_geration ();winp=lookup_widget(obj,"modgest");
gtk_widget_show(win);gtk_widget_hide(winp);
}


void
on_retour_gest_clicked                 (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *win,*winp;
win=create_geration ();winp=lookup_widget(obj,"afftreegest");
gtk_widget_show(win);gtk_widget_hide(winp);
}


void
on_retour_supp_gest_clicked            (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *win,*winp;
win=create_geration ();winp=lookup_widget(obj,"supgest");
gtk_widget_show(win);gtk_widget_hide(winp);
}


void
on_suppf_gest_clicked                  (GtkWidget       *obj,
                                        gpointer         user_data)
{
char asupprimer[50];
int x;
GtkWidget *input1; GtkWidget *output1;

input1=lookup_widget(obj,"entry125");
output1=lookup_widget(obj,"label200");
strcpy (asupprimer,gtk_entry_get_text(GTK_ENTRY(input1)));
supprimer_gest(asupprimer);
x=existe_ger(asupprimer);
if(x!=1)
{
gtk_label_set_text(GTK_LABEL(output1),"Succès de suppression!");
}
else
{
gtk_label_set_text(GTK_LABEL(output1),"Erreur, reessayez!");
}

}


void
on_supp_gest_clicked                   (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *win,*winp;
win=create_supgest ();winp=lookup_widget(obj,"geration");
gtk_widget_show(win);gtk_widget_hide(winp);
}


///////////////////////////page d'acceuil/////////////////////////////////


/*void
on_button3_clicked                     (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *win,*winp;
win=create_mygym ();winp=lookup_widget(obj,"admin");
gtk_widget_show(win);gtk_widget_hide(winp);
}
*/
void
on_button11_clicked                    (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *win,*winp;
win=create_acceuil ();winp=lookup_widget(obj,"admin");
gtk_widget_show(win);gtk_widget_hide(winp);
}


void
on_button12_clicked                    (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *win,*winp;
win=create_admin ();winp=lookup_widget(obj,"acceuil");
gtk_widget_show(win);gtk_widget_hide(winp);
}


void
on_button13_clicked                    (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *input1 , *input2 , *input3,*input4, *output1 ;
acceuil l;






input1 = lookup_widget (obj , "entry128");
input2 = lookup_widget (obj , "entry129");
input3 = lookup_widget (obj , "entry130");
input4 = lookup_widget (obj , "entry131");

output1 =lookup_widget (obj , "label215");




strcpy (l.adresse,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy (l.tel,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy (l.fax,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy (l.mail,gtk_entry_get_text(GTK_ENTRY(input4)));




if (strcmp(l.adresse,"")==0 || strcmp(l.tel,"")==0 || strcmp(l.fax,"")==0 || strcmp(l.mail,"")==0) 
{
gtk_label_set_text(GTK_LABEL(output1),"Remplir tous les champs!");
}


else  
{
ajouter_acceuil (l);
gtk_label_set_text(GTK_LABEL(output1),"succés d'ajout");
}



}


void
on_button10_clicked                    (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *tree ; 
tree=lookup_widget(obj,"treeview15") ; 
afficheracceuil(tree) ;
}


void
on_loginn_clicked                      (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *input1 , *input2 , *output1 ,*output2,*output3,*output4,*output5,*espacecoach,*admin,*mygym;
char l[50],p[50];
int r;
char ch1[50],ch2[50],ch3[50],ch4[50],nom[50],prenom[50];
espacecoach = create_espacecoach ();
admin=create_admin ();
mygym=lookup_widget(obj,"mygim");


input1 = lookup_widget (obj , "entry126");
input2 = lookup_widget (obj , "entry127");



output1 =lookup_widget (obj , "label210");
output2 =lookup_widget (espacecoach , "entry132");
output3 =lookup_widget (espacecoach , "entry133");
output4 =lookup_widget (admin , "entry134");
output5 =lookup_widget (admin , "entry135");
strcpy (l,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy (p,gtk_entry_get_text(GTK_ENTRY(input2)));
r=verifier(l,p);

if (r==2)
{
FILE * f ; 

f=fopen ("/home/manel/Projects/project3/project3/src/users.txt","r"); 


if (f!=NULL) { 

while(fscanf(f,"%s %s %s %d %s\n",ch1,ch2,ch3,&r,ch4)!=EOF ) {

if ((strcmp(ch3,l)==0) && (strcmp(ch4,p)==0))
strcpy(nom,ch1);
strcpy(prenom,ch2); 
}
}
fclose(f);
gtk_label_set_text(GTK_LABEL(output1),"succés login");
gtk_widget_show (espacecoach);
gtk_widget_hide(mygym);
gtk_entry_set_text (GTK_ENTRY (output2),nom );
gtk_entry_set_text (GTK_ENTRY (output3),prenom );
}
else if (r==1)
{
FILE * f ; 

f=fopen ("/home/manel/Projects/project3/project3/src/users.txt","r"); 


if (f!=NULL) { 

while(fscanf(f,"%s %s %s %d %s\n",ch1,ch2,ch3,&r,ch4)!=EOF ) {

if ((strcmp(ch3,l)==0) && (strcmp(ch4,p)==0))
strcpy(nom,ch1);
strcpy(prenom,ch2); 
}
}
fclose(f);
gtk_label_set_text(GTK_LABEL(output1),"succés login");
gtk_widget_show (admin);
gtk_widget_hide(mygym);
gtk_entry_set_text (GTK_ENTRY (output4),nom );
gtk_entry_set_text (GTK_ENTRY (output5),prenom );
}
else
{
gtk_label_set_text(GTK_LABEL(output1),"echec connexion ");
}



}


/*void
on_retour_mygim_admin_clicked          (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *win,*winp;
win=create_admin ();winp=lookup_widget(obj,"mygim");
gtk_widget_show(win);gtk_widget_hide(winp);

}*/


void
on_deconnection_admin_clicked          (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *win,*winp;
win=create_mygym ();winp=lookup_widget(obj,"admin");
gtk_widget_show(win);gtk_widget_hide(winp);

}




void
on_aff_plan_clicked                    (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *tree ; 
tree=lookup_widget(obj,"treeview13") ; 
afficherplanning(tree) ;
}


void
on_deconnection_coach_clicked          (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *win,*winp;
win=create_mygym ();winp=lookup_widget(obj,"espacecoach");
gtk_widget_show(win);gtk_widget_hide(winp);
}


void
on_affich_deal_clicked                 (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *tree ; 
tree=lookup_widget(obj,"treeview12") ; 
afficherdeal(tree) ;
}


void
on_aff_event_clicked                   (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *tree ; 
tree=lookup_widget(obj,"treeview14") ; 
afficherevent(tree);
}

