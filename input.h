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

    input();
    input(string c, string s, int d);


};

input::input() {
    city = "";
    state = "";
    deaths = 0;
}

input::input(string c, string s, int d) {
    city = c;
    state = s;
    deaths = d;
}







#endif //POLICE_SHOOTING_TREE_COMPARISONN_INPUT_H
