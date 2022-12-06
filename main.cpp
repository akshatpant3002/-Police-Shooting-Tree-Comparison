#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include "maxBinaryHeap.h"
#include "input.h"
#include <chrono>
using namespace std;






int get_ind(vector<input> vector1, input city);

bool in_vector(vector<input> vector1, input city);

int main() {

    string filepath = "fatal-police-shootings-data.csv";
    ifstream reader(filepath);


    vector<input> cities;

    string line;
    getline(reader,line);


    while(getline(reader,line)) {

        istringstream inputString(line);

        string not_useful;
        string city_name;
        string state_name;
        string armed_status;

        getline(inputString,not_useful,',');
        getline(inputString,not_useful,',');
        getline(inputString,not_useful,',');
        getline(inputString,not_useful,',');
        getline(inputString,armed_status,',');
        getline(inputString,city_name,',');
        getline(inputString,not_useful,',');
        getline(inputString,state_name,',');

        armed_status = armed_status.substr(1,armed_status.size()-2);
        city_name = city_name.substr(1,city_name.size()-2);
        state_name = state_name.substr(1,state_name.size()-2);
        input city(city_name,state_name);
        if(!in_vector(cities,city)) {
            cities.push_back(city);
            cities[cities.size()-1].add_death();
            if(armed_status == "unarmed" || armed_status == "undetermined")
                cities[cities.size()-1].add_unarmed();
            else {
                cities[cities.size()-1].add_armed();
            }
        }
        else {
            int index = get_ind(cities,city);
            cities.at(index).add_death();
            if(armed_status == "unarmed" || armed_status == "undetermined")
                cities.at(index).add_unarmed();
            else {
                cities.at(index).add_armed();
            }

        }
    }

    cout << cities.size() << endl;

    for(int i = 0; i < cities.size(); i++) {
        //cout << cities[i].city << endl;
        //cout << cities[i].state << endl;
        //cout << cities[i].deaths << endl;
    }

    maxBinaryHeap heap(cities.size());
    for(int i = 0; i < cities.size(); i++) {
        input pushed(cities[i].city,cities[i].state,cities[i].deaths,cities[i].unarmed,cities[i].armed);
        heap.addVal(pushed);
    }
    string city_input;
    string state_input;
    cout << "Type \"exit\" to leave the search!" << endl;
    cout << "Write a city name to get number of deaths in the city!" << endl;
    getline(cin, city_input);
    vector<input> pulled;

    while(city_input != "exit") {


        //getline(cin, city_input);
        cout << "Write a state name to accompany!" << endl;
        getline(cin, state_input);
        //cout << city_input << endl;
        input inputted(city_input, state_input);
        while (!in_vector(cities, inputted)) {
            cout << "Error! That city is not contained in this dataset. It either doesn't exist, or it does not contain any police shootings :)" << endl;
            cout << "Write a city name to get number of deaths in the city!" << endl;
            getline(cin, city_input);
            cout << "Write a state name to accompany!" << endl;
            getline(cin, state_input);
            //cout << city_input << endl;

            inputted = input(city_input, state_input);
        }

        auto start = chrono::high_resolution_clock::now();
        input x = heap.pullTop();
        pulled.push_back(x);
        //cout << x.city << endl;
        //cout << city_input << endl;
        //cout << state_input << endl;


        while (!(x.city == city_input && x.state == state_input)) {
            //cout << x.city << endl;
            x = heap.pullTop();
            pulled.push_back(x);
        }



        for (int i = 0; i < pulled.size(); i++) {
            //cout << pulled[i].city << endl;
            heap.addVal(pulled[i]);
        }
        pulled.clear();

        auto stop = chrono::high_resolution_clock::now();
        cout << "----------------------------------" << endl;
        cout << "(Max Heap Implementation)" << endl;
        auto time_taken = chrono::duration_cast<chrono::microseconds>(stop - start);
        cout << "Time taken to execute the search within the Max Heap!: " << time_taken.count() << " microseconds" << endl;
        cout << "Total Number of Deaths: " << x.deaths << endl;
        cout << "Number of Unarmed/Unknown Deaths (deaths when the civilian was unarmed): " << x.unarmed << endl;
        cout << "Number of Armed Deaths (deaths when the civilian was armed): " << x.armed << endl;
        cout << "----------------------------------" << endl;

        cout << "Write a city name to get number of deaths in the city!" << endl;
        getline(cin, city_input);
    }


        return 0;

}

bool in_vector(vector<input> vector1, input city) {
    for(int i = 0; i < vector1.size(); i++) {
        if(vector1[i].city == city.city && vector1[i].state == city.state){
            return true;
        }
    }
    return false;
}

int get_ind(vector<input> vector1, input city) {
    for(int i = 0; i < vector1.size(); i++) {
        if(vector1[i].city == city.city && vector1[i].state == city.state){
            return i;
        }
    }
    return 0;
}

