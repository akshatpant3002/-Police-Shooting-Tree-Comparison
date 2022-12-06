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
    input(string city, string state, int deaths);
};

input::input(string city, string state, int deaths){
    this->city = city;
    this->state = state;
    this->deaths = deaths;
}




#endif //POLICE_SHOOTING_TREE_COMPARISONN_INPUT_H
