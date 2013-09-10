/*
 * gtk2.c
 *
 * Copyright (C) TuoAn
 *
 */

#include "gui.h"
#include "gtk/gtk.h"

void hello(GtkWidget *widget,gpointer *data) /*定义回调函数hello，单击按钮时系统自动调用*/
{
    g_print("button clicked and data = %s\n",(char *)data);
}
void destroy(GtkWidget *wiget,gpointer *data)/*定义回调函数destroy，关闭窗口时系统自动调用*/
{
    gtk_main_quit();
}

void    CAT_GuiStart(int argc, char **argv)
{
    GtkWidget *window;/*定义指向控件的指针*/
    GtkWidget *button;
    gtk_init(&argc,&argv);/*初始化图形显示环境*/
    window=gtk_window_new(GTK_WINDOW_TOPLEVEL);/*创建窗口*/

    /*设置当关闭窗口时，要执行的回调函数*/
    g_signal_connect(GTK_OBJECT(window),"destroy",GTK_SIGNAL_FUNC(destroy),NULL);
    gtk_container_border_width(GTK_CONTAINER(window),20);/*设置窗口属性*/
    button=gtk_button_new_with_label("hello world");/*创建按钮*/

    /*设置当单击按钮时，要执行的回调函数*/
    g_signal_connect(GTK_OBJECT(button),"clicked",GTK_SIGNAL_FUNC(hello),"I am from button");
    gtk_container_add(GTK_CONTAINER(window),button);/*将按钮加入到窗口中*/

    /*显示按钮和窗口*/
    gtk_widget_show(button);
    gtk_widget_show(window);

    /*进入消息处理循环*/
    gtk_main();

    return 0;
}

