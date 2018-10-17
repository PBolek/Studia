//Piotr Bolek Lista 10 Zadanie 1
#include <string.h>
#include <gtk/gtk.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

static struct przycisk
{
    char *opis, *wyjscie;
    int posX, lenX, posY, lenY;
};

//Klawiatura dla kalkulatora o systemie 10
struct przycisk tab[] =
{
    {"Cos","Cos",0,1,0,1}, {"Sin","Sin",1,1,0,1}, {"Tg","Tg",2,1,0,1}, {"Ctg","Ctg",3,1,0,1},
    {"10/16","",0,1,1,1}, {"/","/",1,1,1,1}, {"*","*",2,1,1,1}, {"-","-",3,1,1,1},
    {"7","7",0,1,2,1}, {"8","8",1,1,2,1}, {"9","9",2,1,2,1}, {"+","+",3,1,2,2},
    {"4","4",0,1,3,1}, {"5","5",1,1,3,1}, {"6","6",2,1,3,1}, {"=","=",3,1,4,2},
    {"1","1",0,1,4,1}, {"2","2",1,1,4,1}, {"3","3",2,1,4,1},
    {".",".",0,1,5,1}, {"0","0",1,2,5,1}
};

//Klawiatura dla kalkulatora o systemie 16
struct przycisk tab2[] =
{
    {"Cos","Cos",0,1,0,1}, {"Sin","Sin",1,1,0,1}, {"Tg","Tg",2,1,0,1}, {"Ctg","Ctg",3,1,0,1},
    {"16/10","",0,1,1,1}, {"/","/",1,1,1,1}, {"*","*",2,1,1,1}, {"-","-",3,1,1,1},
    {"D","D",0,1,2,1}, {"E","E",1,1,2,1}, {"F","F",2,1,2,1}, {"+","+",3,1,2,2},
    {"A","A",0,1,3,1}, {"B","B",1,1,3,1}, {"C","C",2,1,3,1}, {"=","=",3,1,4,2},
    {"7","7",0,1,4,1}, {"8","8",1,1,4,1}, {"9","9",2,1,4,1},
    {"4","4",0,1,5,1}, {"5","5",1,1,5,1}, {"6","6",2,1,5,1},
    {"1","1",0,1,6,1}, {"2","2",1,1,6,1}, {"3","3",2,1,6,1},
    {"0","0",3,1,6,1}
};

static GtkWidget *window, *box1, *text, *grid, *grid1;
int sys = 0;

int priorytet(char c)
{
    if(c == '+' || c == '-')
    {
        return 0;
    }
    else
        return 1;
}

int liczba(char z)
{
    if(z >= '0' && z <= '9')
    {
        return 0;
    }
    return 1;
}

int liczba16(char z)
{
    return z - 'A' + 10;
}

gchar *sinus(const gchar *text)
{
    int licz = 0, mn = 10, s;
    s = strlen(text);
    double wynik;
    if(sys == 0)
        mn = 10;
    else
        mn = 16;
    for(int i = 0; i < s; i++)
    {
        if(text[i] >= 'A' && text[i] <= 'F')
            licz = licz * mn + liczba16(text[i]);
        else if(liczba(text[i]) == 0)
            licz = licz * mn + text[i] - '0';
    }
    wynik = sin(licz);
    char *res = (char *)malloc(50 * sizeof(char));
    if(sys == 0)
        sprintf(res, "%d", wynik);
    else
        sprintf(res, "%x", wynik);
    return res;
}

gchar *cosinus(const gchar *text)
{
    int licz = 0, mn = 10, s;
    s = strlen(text);
    double wynik;
    if(sys == 0)
        mn = 10;
    else
        mn = 16;
    for(int i = 0; i < s; i++)
    {
        if(text[i] >= 'A' && text[i] <= 'F')
            licz = licz * mn + liczba16(text[i]);
        else if(liczba(text[i]) == 0)
            licz =  licz * mn + text[i] - '0';
    }
    printf("%d\n", licz);
    wynik = cos(licz);
    char *res = (char *)malloc(50 * sizeof(char));
    if(sys == 0)
        sprintf(res, "%d", wynik);
    else
        sprintf(res, "%x", wynik);
    return res;
}

gchar *tg(const gchar *text)
{
    int licz = 0, mn = 10, s;
    s = strlen(text);
    double wynik;
    if(sys == 0)
    {
        mn = 10;
    }
    else if(sys == 1)
    {
        mn = 16;
    }
    for(int i = 0; i < s; i++)
    {
        if(text[i] >= 'A' && text[i] <= 'F')
        {
            licz = licz * mn + liczba16(text[i]);
        }
        else if(liczba(text[i]) == 0)
        {
            licz = licz * mn + text[i] - '0';
        }
    }
    wynik = sin(licz) / cos(licz);
    char *res = (char *)malloc(50*sizeof(char));
    if(sys == 0)
        sprintf(res, "%d", wynik);
    else
        sprintf(res, "%x", wynik);
    return res;
}

gchar *ctg(const gchar *text)
{
    int licz = 0, mn = 10, s;
    s = strlen(text);
    double wynik;
    if(sys == 0)
    {
        mn = 10;
    }
    else if(sys  == 1)
    {
        mn = 16;
    }
    for(int i = 0; i < s; i++)
    {
        if(text[i] >= 'A' && text[i] <= 'F')
        {
            licz = licz * mn + liczba16(text[i]);
        }
        else if(liczba(text[i]) == 0)
        {
            licz = licz * mn + text[i] - '0';
        }
    }
    wynik = cos(licz) / sin(licz);
    char *res = (char *)malloc(50*sizeof(char));
    if(sys == 0)
        sprintf(res, "%d", wynik);
    else
        sprintf(res, "%x", wynik);
    return res;
}

gchar *oblicz(const gchar *text) // funkcja obliczajaca dzialanie wpisane na ekranie kalkulatora
{
    //Zamiana na ONP
    int s = strlen(text), b = 0, a = 0, wejscie[50], mn = 10, licz = 0;
    char stos[50];
    if(sys == 0)
    {
        mn = 10;
    }
    else if(sys == 1)
    {
        mn = 16;
    }
    printf("%ds\n", s);
    for(int i = 0; i < s; i++)
    {
        if(text[i] >= 'A' && text[i] <= 'F')
        {
            licz = mn * licz + liczba16(text[i]);
        }
        else if(liczba(text[i]) == 0)
        {
            licz = mn * licz + (text[i] - '0');
        }
        else
        {
            wejscie[b++] = licz;
            licz = 0;
            while(a != 0 && priorytet(text[i]) <= priorytet(stos[a - 1]))
            {
                wejscie[b++] = -stos[--a];
            }
            stos[a++] = text[i];
        }
    }
    wejscie[b++] = licz;
    while(a != 0)
    {
        wejscie[b++] = -stos[--a];
    }
    for(int i = 0; i < b;i++)
    {
        if(wejscie[i] >= 0)
            printf("%d ", wejscie[i]);
        else
            printf("%c ", -wejscie[i]);
    }

    //Obliczanie ONP
    a = 0;
    int stos2[50], wynik = 0, x = 0, y = 0;
    for(int i = 0; i < s; i++)
    {
        if(-wejscie[i] == '+')
        {
            x = stos2[--a];
            y = stos2[--a];
            wynik = x + y;
            stos2[a++] = wynik;
        }
        else if(-wejscie[i] == '-')
        {
            x = stos2[--a];
            y = stos2[--a];
            wynik = y - x;
            stos2[a++] = wynik;
        }
        else if(-wejscie[i] == '*')
        {
            x = stos2[--a];
            y = stos2[--a];
            wynik = x * y;
            stos2[a++] = wynik;
        }
        else if(-wejscie[i] == '/')
        {
            x = stos2[--a];
            y = stos2[--a];
            wynik = y / x;
            stos2[a++] = wynik;
        }
        else if(wejscie[i] >= 0)
        {
            stos2[a++] = wejscie[i];
        }
    }
    char *res = (char *)malloc(50 * sizeof(char));
    if(sys == 0)
    {
        sprintf(res, "%d", stos2[0]);
    }
    else
    {
        sprintf(res, "%x", stos2[0]);
    }
    return res;
}

static void test_nacisniecia(GtkWidget *widget, gpointer data)
{
    g_print("GTK-test - %s zastal nacisniety\n", (gchar *) data);
}

static void wyjscie_przyciskiem(GtkWidget *widget, gpointer data)
{
    gtk_main_quit();
}

static void wypisz_wprowadzony_tekst(GtkWidget *widget,GtkWidget *text)
{
    const gchar *wejscie;
    wejscie = gtk_entry_get_text (GTK_ENTRY (text));
    g_print ("GTK-test wprowadzono: %s\n", wejscie);
}

static void dodaj_do_text(GtkWidget *widget, gpointer data)
{
    gint tmp_pos = gtk_entry_get_text_length(GTK_ENTRY(text));
    const gchar *a;
    a = gtk_entry_get_text(GTK_ENTRY(text));
    if(strcmp((gchar*)data, "\n") == 0)
        gtk_entry_set_text(GTK_ENTRY(text), oblicz(a));
    else if(strcmp((gchar*)data, "=") == 0)
        gtk_entry_set_text(GTK_ENTRY(text), oblicz(a));
    else if(strcmp((gchar*)data, "Cos") == 0)
        gtk_entry_set_text(GTK_ENTRY(text), cosinus(a));
    else if(strcmp((gchar*)data, "Sin") == 0)
        gtk_entry_set_text(GTK_ENTRY(text), sinus(a));
    else if(strcmp((gchar*)data, "Tg") == 0)
        gtk_entry_set_text(GTK_ENTRY(text), tg(a));
    else if(strcmp((gchar*)data, "Ctg") == 0)
        gtk_entry_set_text(GTK_ENTRY(text), ctg(a));
    else
        gtk_editable_insert_text(GTK_EDITABLE(text), (gchar*)data, -1, &tmp_pos);
}

static void zamien_system(GtkWidget *widget, gpointer data)
{
    if(data == 0)
    {
        gtk_container_remove(GTK_CONTAINER(box1), g_object_ref(grid));
        gtk_box_pack_start(GTK_BOX(box1),grid1, TRUE, TRUE, 0);
        gtk_widget_show_all(window);
        sys = 1;
    }
    else if(data == 1)
    {
        gtk_container_remove(GTK_CONTAINER(box1), g_object_ref(grid1));
        gtk_box_pack_start(GTK_BOX(box1), grid, TRUE, TRUE, 0);
        gtk_widget_show_all(window);
        sys = 0;
    }
}

int main( int argc,char *argv[] )
{
    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window),"GTK - Kalkulator");
    gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER);
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);

    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    box1 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_container_add(GTK_CONTAINER(window), box1);

    GtkWidget *button = gtk_button_new_with_label("Kliknij tu");
    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(test_nacisniecia), (gpointer)"Przycisk");
    gtk_box_pack_start(GTK_BOX(box1), button, TRUE, TRUE, 0);

    text = gtk_entry_new();
    gtk_entry_set_max_length(GTK_ENTRY(text), 50);
    g_signal_connect(G_OBJECT(text), "activate", G_CALLBACK(wypisz_wprowadzony_tekst), (gpointer)text);
    gtk_entry_set_text(GTK_ENTRY(text), "Wprowadz");
    gint tmp_pos = gtk_entry_get_text_length(GTK_ENTRY(text));
    gtk_editable_insert_text(GTK_EDITABLE(text), " jakis tekst", -1, &tmp_pos);
    gtk_editable_select_region(GTK_EDITABLE(text), 0, gtk_entry_get_text_length(GTK_ENTRY(text)));
    gtk_box_pack_start(GTK_BOX(box1), text, TRUE, TRUE, 0);

    grid = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid), 6);
    gtk_grid_set_row_homogeneous(GTK_GRID(grid), TRUE);
    gtk_grid_set_column_spacing(GTK_GRID(grid), 6);
    gtk_grid_set_column_homogeneous(GTK_GRID(grid), TRUE);
    gtk_box_pack_start(GTK_BOX(box1), grid, TRUE, TRUE, 0);

    button  = gtk_button_new_with_label(tab[4].opis);
    gtk_grid_attach(GTK_GRID(grid), button, tab[4].posX, tab[4].posY, tab[4].lenX, tab[4].lenY);
    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(zamien_system), (gpointer)0);

    for(int i = 0; i < 21; i++)
    {
        button = gtk_button_new_with_label(tab[i].opis);
        if(i != 4)
        {
            g_signal_connect(G_OBJECT(button), "clicked",G_CALLBACK(dodaj_do_text),
                         (gpointer) tab[i].wyjscie);
                         gtk_grid_attach(GTK_GRID(grid), button, tab[i].posX, tab[i].posY, tab[i].lenX, tab[i].lenY);
        }
    }

    grid1 = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid1), 7);
    gtk_grid_set_row_homogeneous(GTK_GRID(grid1), TRUE);
    gtk_grid_set_column_spacing(GTK_GRID(grid1), 7);
    gtk_grid_set_column_homogeneous(GTK_GRID(grid1), TRUE);

    button = gtk_button_new_with_label(tab2[4].opis);
    gtk_grid_attach(GTK_GRID(grid1), button, tab2[4].posX, tab2[4].posY, tab2[4].lenX, tab2[4].lenY);
    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(zamien_system), (gpointer)1);

    for(int i = 0; i < 27; i++)
    {
        button = gtk_button_new_with_label(tab2[i].opis);
        if(i != 4)
        {
            g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(dodaj_do_text),(gpointer)tab2[i].wyjscie);
            gtk_grid_attach(GTK_GRID(grid1), button, tab2[i].posX, tab2[i].posY, tab2[i].lenX, tab2[i].lenY);
        }
    }

    GtkWidget *box2 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    button = gtk_button_new_with_label("Koniec");
    g_signal_connect(G_OBJECT(button), "clicked",G_CALLBACK(wyjscie_przyciskiem), NULL);
    gtk_box_pack_start(GTK_BOX(box2), button, TRUE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box1), box2, TRUE, TRUE, 0);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}
