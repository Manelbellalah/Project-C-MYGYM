#include <gtk/gtk.h>
#include "treeacceuil.h"
#include "fonctionm.h"
enum
{

adresse,tel,fax,mail,
 

	COLUMNS
};

void afficheracceuil(GtkWidget *treeview)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;
	 char ch1[50],ch2[50],ch3[50],ch4[50];
 	
 	char c;
 
 
	FILE *f;
	
	
	
	

	store=NULL;
	
	//creat the colomns if they dont alredy exist
	store=gtk_tree_view_get_model(treeview);	
	if (store==NULL)
	{

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Adresse", renderer,"text",adresse, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);	
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Tel", renderer, "text",tel, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);
                

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Fax", renderer, "text",fax, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);
			

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Mail", renderer, "text",mail, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);
	
	}
		store=gtk_list_store_new (4, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING , G_TYPE_STRING);

	f = fopen("/home/manel/Projects/project3/project3/src/acceuil.txt", "r");
	
	if(f ==NULL)
	{

		return;
	}		
	else
	{
	
		while(fscanf(f,"%s %s %s %s ",ch1,ch2,ch3,ch4)!=EOF)
		{ 
			
			gtk_list_store_append (store, &iter);
			gtk_list_store_set (store, &iter,adresse,ch1,tel,ch2,fax,ch3,mail,ch4,-1);}
		
		
		fclose(f);
		
	}
		
	gtk_tree_view_set_model (GTK_TREE_VIEW (treeview), GTK_TREE_MODEL (store));
	
	g_object_unref (store);
	
}

