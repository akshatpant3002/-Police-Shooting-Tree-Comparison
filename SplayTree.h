


#ifndef POLICE_SHOOTING_TREE_COMPARISONN_SPLAYTREE_H
#define POLICE_SHOOTING_TREE_COMPARISONN_SPLAYTREE_H

#include <string>
#include <vector>
using namespace std;

struct Node {
    string state;
    string city;
    int deaths;
    Node* left;
    Node* right;
};

class SplayTree {
    Node* treeRoot;
    vector<Node*> inOrder;
    Node* LeftRotation(Node* node);
    Node* RightRotation(Node* node);
    Node* SplayHelper();
    void InOrderTraversal(Node* root);
public:
    SplayTree();
    void Insert(string state, string city, int deaths);
    int Search(Node* node, string state, string city);
    vector<Node*> GetVector(Node* root);
    void PostOrderDeletion(Node* root);
    ~SplayTree();

};

//Constructor
SplayTree::SplayTree() {

}


//Rotations
Node *SplayTree::LeftRotation(Node *node) {

}
Node *SplayTree::RightRotation(Node *node) {

}
Node *SplayTree::SplayHelper() {

}


//Insertion & Deletion
void SplayTree::Insert(std::string state, std::string city, int deaths) {

}
void SplayTree::PostOrderDeletion(Node *root) {
    if(root == nullptr)
        return;
    else {
        PostOrderDeletion(root->left);
        PostOrderDeletion(root->right);
    }
    delete root;
}
SplayTree::~SplayTree() {
    PostOrderDeletion(treeRoot);
}


//Traversals and Accessors
int SplayTree::Search(Node* root, string state, string city ) {
    if(treeRoot == nullptr)
        return -1;
    return 0;
}
void SplayTree::InOrderTraversal(Node *root) {
    if(root == nullptr)
        return;
    else {
        InOrderTraversal(root->left);
        inOrder.push_back(root);
        InOrderTraversal(root->right);
    }
}
vector<Node*> SplayTree::GetVector(Node *root) {
    inOrder.clear();
    InOrderTraversal(treeRoot);
    return inOrder;
}


#endif //POLICE_SHOOTING_TREE_COMPARISONN_SPLAYTREE_H
