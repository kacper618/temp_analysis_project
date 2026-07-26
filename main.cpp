#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <vector>
#include <random>
#include <iomanip>

using namespace std;

struct Measurement_data
{
    int id;
    string city;
    string time;
    float temp;
    int humidity;
};

int main()
{
    random_device rd;
    mt19937 gen(rd());

    uniform_real_distribution<float> rand_temp(-15.0, 35.0);
    uniform_int_distribution<int> rand_city(0, 4);
    uniform_int_distribution<int> rand_hum(0, 99);
    uniform_int_distribution<int> rand_error(1, 100);

    vector<string> cities = {"Gdansk", "Krakow", "Poznan", "Warszawa", "Olsztyn"};
    Measurement_data current_data;

    time_t current_time = time(0);

    ofstream file("data.csv");

    if(!file.is_open())
    {
        cout << "ERROR! Couldn't open the data file.\n";
    }

    file << "id,city,timestamp,temperature,humidity\n";

    for(int i = 0; i < 100000; i++)
    {
        current_time += 60;
        tm *ltm = localtime(&current_time);
        char buffer[100];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", ltm);

        current_data.id = i + 1;
        current_data.city = cities[rand_city(gen)];
        current_data.temp = rand_temp(gen);
        current_data.humidity = rand_hum(gen);
        current_data.time = string(buffer);

        //INTENTIONALLY INSERTING ERRORS TO CLEAN DATASET LATER IN PYTHON

        int error_roll = rand_error(gen);

        if(error_roll <= 2)
        {
            current_data.temp = -999;
        }
        else if(error_roll == 100)
        {
            current_data.city = "ERROR";
        }

        file << current_data.id << "," 
             << current_data.city << "," 
             << current_data.time << "," 
             << fixed << setprecision(1) << current_data.temp << "," 
             << current_data.humidity << "\n";
    }

    file.close();

    cout << "Data file generated successfully.\n";

    return 0;
}
