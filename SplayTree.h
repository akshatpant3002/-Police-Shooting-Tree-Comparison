


#ifndef POLICE_SHOOTING_TREE_COMPARISONN_SPLAYTREE_H
#define POLICE_SHOOTING_TREE_COMPARISONN_SPLAYTREE_H

#include <string>

struct Node {
    string state;
    string city;
    int deaths;
    Node* left;
    Node* right;
};

class SplayTree {
    Node* LeftRotation(Node* node);
    Node* RightRotation(Node* node);
    Node* SplayHelper();
public:
    void Insertion(string state, string city, int deaths);
    Node* SearchNode(string state, string city);
    ~SplayTree();

};


#endif //POLICE_SHOOTING_TREE_COMPARISONN_SPLAYTREE_H
