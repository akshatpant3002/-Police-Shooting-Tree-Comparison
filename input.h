//
// Created by Akshat Pant on 12/4/22.
//


#ifndef POLICE_SHOOTING_TREE_COMPARISONN_INPUT_H
#define POLICE_SHOOTING_TREE_COMPARISONN_INPUT_H

#include <iostream>
using namespace std;



class input {
public:
    string city;
    string state;
    int deaths;
    int unarmed;
    int armed;

    input();
    input(string c, string s);
    input(string c, string s, int d, int u, int a);

    void add_death() {
        deaths++;
    }
    void add_unarmed() {
        unarmed++;
    }
    void add_armed() {
        armed++;
    }



};

input::input() {
    city = "";
    state = "";
    deaths = 0;
    unarmed = 0;
    armed = 0;
}

input::input(string c, string s, int d, int u, int a) {
    city = c;
    state = s;
    deaths = d;
    unarmed = u;
    armed = a;

}

input::input(string c, string s) {
    city = c;
    state = s;
    deaths = 0;
    unarmed = 0;
    armed = 0;
}


#endif //POLICE_SHOOTING_TREE_COMPARISONN_INPUT_H
