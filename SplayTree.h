


#ifndef POLICE_SHOOTING_TREE_COMPARISONN_SPLAYTREE_H
#define POLICE_SHOOTING_TREE_COMPARISONN_SPLAYTREE_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;

struct Node {
    Node(string state, string city, int deaths);
    string state;
    string city;
    int deaths;
    Node* left;
    Node* right;
    Node* parent;
};

class SplayTree {
    Node* treeRoot;
    vector<Node*> inOrder;
    Node* LeftRotation(Node* node);
    Node* RightRotation(Node* node);
    Node* InsertHelper(Node* root, string state, string city, int deaths);
    Node* SplayHelper(Node* node, string state, string city);
    void InOrderTraversal(Node* root);
    void PreOrderTraversal(Node* root, string state, string city, int &result); //root, right, left
public:
    SplayTree();
    void Insert(string state, string city, int deaths);
    int Search(Node* node, string state, string city);
    vector<Node*> GetVector(Node* root);
    Node* GetRoot();
    void PostOrderDeletion(Node* root);
    ~SplayTree();

};




//Constructors
Node::Node(string state, string city, int deaths) {
    this->state = state;
    this->city = city;
    this->deaths = deaths;
    left = nullptr;
    right = nullptr;
    parent = nullptr;
}

SplayTree::SplayTree() {
    treeRoot = nullptr;
}



//Rotations
Node *SplayTree::LeftRotation(Node *node) { //Zag
    Node* newParent = node->right;
    newParent->parent = node->parent;
    Node* grandchild = newParent->left;
    newParent->left = node;
    node->parent = newParent;
    node->right = grandchild;
    grandchild->parent = node;

    return newParent;
}
Node *SplayTree::RightRotation(Node *node) { //Zig
    Node* newParent = node->left;
    newParent->parent = node->parent;
    Node* grandchild = newParent->right;
    newParent->right = node;
    node->parent = newParent;
    node->left = grandchild;
    grandchild->parent = node;

    return newParent;
}



//Insertion & Deletion
void SplayTree::Insert(std::string state, std::string city, int deaths) {
    treeRoot = InsertHelper(treeRoot, state, city, deaths);
}
Node* SplayTree::InsertHelper(Node *root, std::string state, std::string city, int deaths) {
    if(root == nullptr) {
        return new Node(state, city, deaths);
    }
    else if(root->deaths > deaths) {
        treeRoot->left = InsertHelper(root->left, state, city, deaths);
    }
    else {
        treeRoot->right = InsertHelper(root->right, state, city, deaths);
    }
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
int SplayTree::Search(Node* root, string state, string city) {
    int result = -1;
    PreOrderTraversal(root, state, city, result);
    return result;
}
void SplayTree::PreOrderTraversal(Node *root, std::string state, std::string city, int &result) {
    if(root != nullptr) {
        if(root->state == state && root->city == city) {
            result = root->deaths;
            return;
        }
        PreOrderTraversal(root->right, state, city, result);
        PreOrderTraversal(root->left, state, city, result);

    }
}
Node *SplayTree::SplayHelper(Node* node, string state, string city) {
    if(treeRoot == nullptr)
        return nullptr;
    while(node->parent != nullptr) {
        if(node->parent->parent == nullptr) {
            if(node->parent->left == node)
                RightRotation(node->parent);
            else
                LeftRotation(node->parent);
        }
        else if(node->parent->left == node && node->parent->parent->left == node->parent) {
            RightRotation(node->parent->parent);
            RightRotation(node->parent);
        }
        else if(node->parent->right == node && node->parent->parent->right == node->parent) {
            LeftRotation(node->parent->parent);
            LeftRotation(node->parent);
        }
        else if(node->parent->right == node && node->parent->parent->left == node->parent) {
            LeftRotation(node->parent->parent);
            RightRotation(node->parent);
        }
        else {
            RightRotation(node->parent);
            LeftRotation(node->parent);
        }
    }
    if(treeRoot == node) {
        cout << "successfully moved to root" << endl;
        return node;
    }
    else
        cout << "failed to move to root" << endl;
    return node;

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
