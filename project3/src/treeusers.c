#include <gtk/gtk.h>
#include "treeusers.h"
#include "fonctionm.h"
enum
{

nom,prenom,cin,role,moddepasse,
 

	COLUMNS
};

void affichergest(GtkWidget *treeview)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;
	 char ch1[50],ch2[50],ch3[50],ch4[50],ch5[50];
 	
 	char c;
 
 
	FILE *f;
	
	
	
	

	store=NULL;
	
	//creat the colomns if they dont alredy exist
	store=gtk_tree_view_get_model(treeview);	
	if (store==NULL)
	{

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("nom", renderer,"text",nom, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);	
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("prenom", renderer, "text",prenom, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);
                

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("cin", renderer, "text",cin, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);
			

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("role", renderer, "text",role, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("moddepasse", renderer, "text",moddepasse, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);

		/*renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("adresse", renderer, "text",adresse, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);
		*/
		

	}
		store=gtk_list_store_new (5, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING , G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

	f = fopen("/home/manel/Projects/project3/project3/src/users.txt", "r");
	
	if(f ==NULL)
	{

		return;
	}		
	else
	{
	
		while(fscanf(f,"%s %s %s %s %s ",ch1,ch2,ch3,ch4,ch5)!=EOF)
		{ 
			
			gtk_list_store_append (store, &iter);
			gtk_list_store_set (store, &iter,nom,ch1,prenom,ch2,cin,ch3,role,ch4,moddepasse,ch5,-1);}
		
		
		fclose(f);
		
	}
		
	gtk_tree_view_set_model (GTK_TREE_VIEW (treeview), GTK_TREE_MODEL (store));
	
	g_object_unref (store);
	
}

