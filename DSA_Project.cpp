#include <iostream>
#include <cstdlib>
#include "Weather_get.h"
#include "Weather_Out.h"
#include <string>

using namespace std;

void show_vals(Weather_Out_list &wlist,double welem) {
    wlist.insertLast(welem);
    return;
}


void print_report(Weather_Out_list& wlist, string list_of_keywords[100],int i_k) {
    wlist.print_list();
    for (int i = 0;i < i_k;i++) {
        cout << list_of_keywords[i];
    };
}



int main()
{
    reading_file();
    string list_of_keywords[100];
    Weather_cluster weather_list;
    Weather_Out_list wlist;
    char choice='0';
    double welem = 0.0;
    string keyword;
    int i_k = 0;
    while (choice != NULL)
    {
        cout << "Enter the Character" << endl;
        cin >> choice;
        switch (choice) {
        case 't':
            keyword = "Temperature";
            welem = weather_list.temp;
            show_vals(wlist, welem);
            cout << "Temperature : "<< welem;
            break;
        case 's':
            keyword = "Wind Speed";
            welem = weather_list.wind_s;
            show_vals(wlist, welem);
            cout << "Wind Speed : " << welem;
            break;
        case 'd':
            keyword = "Wind Direction";
            welem = weather_list.wind_d;
            show_vals(wlist, welem);
            cout << "Wind Direction : " << welem;
            break;
        case 'h':
            keyword = "Humidity";
            welem = weather_list.hum;
            show_vals(wlist, welem);
            cout << "Humidity : " << welem;
            break;
        case 'v':
            keyword = "Visibility";
            welem = weather_list.vis;
            show_vals(wlist, welem);
            cout << "Visibility : " << welem;
            break;
        case 'b':
            keyword = "Barometric Pressure";
            welem = weather_list.pres;
            show_vals(wlist, welem);
            cout << "Barometric Pressure : " << welem;
            break;
        case 'l':
            wlist.deleteLast();
            cout << "Last Item Deleted ";
            break;
        };
        list_of_keywords[i_k] = keyword;
        i_k++;
    }
    print_report(wlist, list_of_keywords, i_k);
}
