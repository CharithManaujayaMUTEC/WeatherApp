#pragma once
#include <iostream>
#include <stdio.h>


using namespace std;

struct Weather_cluster
{
    char district[25];
    double temp;
    double wind_s;
    double wind_d;
    double hum;
    double vis;
    double pres;
} ;

Weather_cluster reading_file() {
    FILE* weather_file=nullptr;
    fopen_s(&weather_file,"weather_file.txt","r");
    Weather_cluster weather_list;
    weather_list = { };
    string list_of_districts = ("Colombo", "Gampaha", "Kalutara", "Kandy", "Matale", "Nuwara Eliya", "Galle", "Matara", "Hambantota", "Jaffna", "Kilinochchi", "Mannar", "Vavuniya", "Mullaitivu", "Batticaloa", "Ampara", "Trincomalee", "Kurunegala", "Puttalam", "Anuradhapura", "Polonnaruwa", "Badulla", "Monaragala", "Ratnapura", "Kegalle");
    cout << "Enter the district you want to search(all letters should be simple)" << endl;
    int read_line = 0;
    char district[25];
    char input_d[25] = { '0' };
    cin >> district;
    for (int read_line = 0;read_line < 25;read_line++) {
        list_of_districts[read_line]= *input_d;
        if (district == input_d) {
            break;
        };
    }
    do
    {
        
        int i = 0;
        while (i<=read_line)
        {
            if (weather_file != NULL) {
                fscanf_s(weather_file, "%c25 [^|],%f,%f,%f,%f,%f,%f",
                    weather_list.district,
                    &weather_list.temp,
                    &weather_list.wind_s,
                    &weather_list.wind_d,
                    &weather_list.hum,
                    &weather_list.pres,
                    &weather_list.vis);

                if (ferror(weather_file)) {
                    cout << "Error while reading!" << endl;
                };
            }
            else return weather_list ;

        }
        return weather_list;


    } while (!feof(weather_file));
    fclose(weather_file);

    
}



