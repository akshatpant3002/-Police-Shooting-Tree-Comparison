


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
    Node* SplayHelper(Node* root,string state, string city);    //TODO
    void InOrderTraversal(Node* root);
public:
    void Insert(string state, string city, int deaths);         //TODO
    int Search(Node* node, string state, string city);
    vector<Node*> GetVector(Node* root);
    Node* GetRoot();
    void PostOrderDeletion(Node* root);
    ~SplayTree();

};



//Rotations
Node *SplayTree::LeftRotation(Node *node) { //Zig
    Node* newParent = node->right;
    Node* grandchild = newParent->left;
    newParent->left = node;
    node->right = grandchild;
    return newParent;
}
Node *SplayTree::RightRotation(Node *node) { //Zag
    Node* newParent = node->left;
    Node* grandchild = newParent->right;
    newParent->right = node;
    node->left = grandchild;
    return newParent;
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
    Node* tempNode = SplayHelper(root, state, city);
    return tempNode->deaths;
}
Node *SplayTree::SplayHelper(Node* root, string state, string city) {

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
Node* SplayTree::GetRoot() {
    return treeRoot;
}


#endif //POLICE_SHOOTING_TREE_COMPARISONN_SPLAYTREE_H
