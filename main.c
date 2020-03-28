/*

#include <gtk/gtk.h>
#include "vector.h"

static void
print_hello (GtkWidget *widget,
             gpointer   data)
{
    g_print ("Hello World\n");
}

static void
activate (GtkApplication *app,
          gpointer        user_data)
{
    GtkWidget *window;
    GtkWidget *button;
    GtkWidget *button_box;

    window = gtk_application_window_new (app);
    gtk_window_set_title (GTK_WINDOW (window), "Window");
    gtk_window_set_default_size (GTK_WINDOW (window), 200, 200);

    button_box = gtk_button_box_new (GTK_ORIENTATION_HORIZONTAL);
    gtk_container_add (GTK_CONTAINER (window), button_box);

    button = gtk_button_new_with_label ("Hello World");
    g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);
    g_signal_connect_swapped (button, "clicked", G_CALLBACK (gtk_widget_destroy), window);
    gtk_container_add (GTK_CONTAINER (button_box), button);

    gtk_widget_show_all (window);
}

int
main (int    argc,
      char **argv)
{
    vec_t v;
    vector_push_back(&v, 5);
    vector_push_back(&v, 500);
    vector_push_back(&v, 1);
    vector_push_back(&v, 3);
    vector_push_back(&v, 4);
    vector_push_back(&v, 5);
    vector_push_back(&v, 6);
    vector_push_back(&v, 7);
    vector_push_back(&v, 8);
    vector_push_back(&v, 9);
    vector_push_back(&v, 10);
    vector_push_back(&v, 11);
    vector_push_back(&v, 12);
    vector_push_back(&v, 13);

    vector_resize(&v, 5);

    for (int i = 0; i < v.vec_size; ++i) {
        printf("%i\n",v.t[i]);
    }

    GtkApplication *app;
    int status;

    app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
    g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
    status = g_application_run (G_APPLICATION (app), argc, argv);
    g_object_unref (app);

    return status;
}*/

#include "FileTree.h"
#include <stdio.h>

const int mx_char = 255;


int main(int argc, char **argv) {

    FileTree X;
    FileTree_init(&X,".");
    //FileTree_calculateSizes(&X); Obsolete
    printf("%lli", X.root->size);
    FileTree_destruct(&X);

    return 0;
}
