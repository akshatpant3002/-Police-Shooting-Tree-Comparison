#include <iostream>
#include <string>
#include <fstream>
using namespace std;


struct City {
    string city_name;
    string state_name;
    int deaths;

    City() {
        city_name = "";
        state_name = "";
        deaths = 0;
    }

    City(string city, string state) {
        city_name = city;
        state_name = state;
        deaths = 0;
    }

};
int main() {

    string filepath = "fatal-police-shootings-data.csv";
    ifstream reader;

    reader.open(filepath);

    vector<City> cities;
    if(reader.fail()) {
        cout << "Unable to open csv data from " << filepath << endl;
    }


    return 0;
}

