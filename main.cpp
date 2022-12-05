#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
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

    void add_death() {
        deaths++;
    }

};


bool contains(vector<City> vector1, City city);

int get_ind(vector<City> vector1, City city);

bool in_vector(vector<City> vector1, City city);

int main() {

    string filepath = "fatal-police-shootings-data.csv";
    ifstream reader(filepath);


    vector<City> cities;

    string line;
    getline(reader,line);


    while(getline(reader,line)) {

        istringstream inputString(line);

        string not_useful;
        string city_name;
        string state_name;

        getline(inputString,not_useful,',');
        getline(inputString,not_useful,',');
        getline(inputString,not_useful,',');
        getline(inputString,not_useful,',');
        getline(inputString,not_useful,',');
        getline(inputString,city_name,',');
        getline(inputString,not_useful,',');
        getline(inputString,state_name,',');


        City city(city_name,state_name);
        if(!in_vector(cities,city)) {
            cities.push_back(city);
            cities[cities.size()-1].add_death();
        }
        else {
            int index = get_ind(cities,city);
            cities.at(index).add_death();

        }
    }

    cout << cities.size() << endl;
    for(int i = 0; i < cities.size(); i++) {
        cout << cities[i].city_name << endl;
        cout << cities[i].state_name << endl;
        cout << cities[i].deaths << endl;
    }



    return 0;
}

bool in_vector(vector<City> vector1, City city) {
    for(int i = 0; i < vector1.size(); i++) {
        if(vector1[i].city_name == city.city_name && vector1[i].state_name == city.state_name){
            return true;
        }
    }
    return false;
}

int get_ind(vector<City> vector1, City city) {
    for(int i = 0; i < vector1.size(); i++) {
        if(vector1[i].city_name == city.city_name && vector1[i].state_name == city.state_name){
            return i;
        }
    }
    return 0;
}

