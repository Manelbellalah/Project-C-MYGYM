#include <gtk/gtk.h>
#include "treeplanning.h"
#include "fonctionm.h"
enum
{

l8,l10,l14,l16,
 

	COLUMNS
};

void afficherplanning(GtkWidget *treeview)
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
		column = gtk_tree_view_column_new_with_attributes("8h=>10h", renderer,"text",l8, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);	
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("10h=>12h", renderer, "text",l10, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);
                

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("14h=>16h", renderer, "text",l14, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);
			

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("16h=>18h", renderer, "text",l16, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);
	
		
		
		

	}
		store=gtk_list_store_new (4, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING , G_TYPE_STRING);

	f = fopen("/home/manel/Projects/project3/project3/src/planning.txt", "r");
	
	if(f ==NULL)
	{

		return;
	}		
	else
	{
	
		while(fscanf(f,"%s %s %s %s ",ch1,ch2,ch3,ch4)!=EOF)
		{ 
			
			gtk_list_store_append (store, &iter);
			gtk_list_store_set (store, &iter,l8,ch1,l10,ch2,l14,ch3,l16,ch4,-1);}
		
		
		fclose(f);
		
	}
		
	gtk_tree_view_set_model (GTK_TREE_VIEW (treeview), GTK_TREE_MODEL (store));
	
	g_object_unref (store);
	
}

