/*
 * gtk2.c
 *
 * Copyright (C) TuoAn
 *
 */

#include "test.h"

#include "gui.h"
#include "gtk/gtk.h"

void startTest(GtkWidget *widget,gpointer *data)
{
    CAT_TestStartAll();
}


void destroy(GtkWidget *wiget,gpointer *data)
{
    gtk_main_quit();
}

void gtkRoutine(int argc, char **argv)
{
    GtkWidget *window;
    GtkWidget *button;

    gtk_init(&argc,&argv);

    window=gtk_window_new(GTK_WINDOW_TOPLEVEL);

    g_signal_connect(GTK_OBJECT(window),"destroy",GTK_SIGNAL_FUNC(destroy),NULL);

    gtk_container_border_width(GTK_CONTAINER(window),20);
    button=gtk_button_new_with_label("StartTest");

    g_signal_connect(GTK_OBJECT(button),"clicked",GTK_SIGNAL_FUNC(startTest),NULL);
    gtk_container_add(GTK_CONTAINER(window),button);

    gtk_widget_show(button);
    gtk_widget_show(window);

    gtk_main();

}


void    CAT_GuiStart(int argc, char **argv)
{

    gtkRoutine(argc, argv); 
    
    return;
}

