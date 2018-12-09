#include <gtk/gtk.h>
#include "treeevent.h"
#include "fonctionm.h"
enum
{

nomevent,date,infoevent,
 

	COLUMNS
};

void afficherevent(GtkWidget *treeview)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;
	 char ch1[50],ch2[50],ch3[50];
 	
 	char c;
 
 
	FILE *f;
	
	
	
	

	store=NULL;
	
	//creat the colomns if they dont alredy exist
	store=gtk_tree_view_get_model(treeview);	
	if (store==NULL)
	{

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Nom de Evenement", renderer,"text",nomevent, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);	
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Date de l'evenement", renderer, "text",date, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);
                

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("INFO sur l'evenement", renderer, "text",infoevent, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);
			

		

	}
		store=gtk_list_store_new (3 , G_TYPE_STRING, G_TYPE_STRING , G_TYPE_STRING);

	f = fopen("/home/manel/Projects/project3/project3/src/event.txt", "r");
	
	if(f ==NULL)
	{

		return;
	}		
	else
	{
	
		while(fscanf(f,"%s %s %s ",ch1,ch2,ch3)!=EOF)
		{ 
			
			gtk_list_store_append (store, &iter);
			gtk_list_store_set (store, &iter,nomevent,ch1,date,ch2,infoevent,ch3,-1);}
		
		
		fclose(f);
		
	}
		
	gtk_tree_view_set_model (GTK_TREE_VIEW (treeview), GTK_TREE_MODEL (store));
	
	g_object_unref (store);
	
}

