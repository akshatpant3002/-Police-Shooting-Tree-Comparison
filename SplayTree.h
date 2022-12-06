


#ifndef POLICE_SHOOTING_TREE_COMPARISONN_SPLAYTREE_H
#define POLICE_SHOOTING_TREE_COMPARISONN_SPLAYTREE_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;

struct Node {
    Node();
    Node(string state, string city, int deaths, int unarmed, int armed);
    string state;
    string city;
    int deaths;
    int unarmed;
    int armed;
    Node* left;
    Node* right;
    Node* parent;
};

class SplayTree {
    Node* treeRoot;
    vector<Node*> inOrder;
    Node* LeftRotation(Node* node);
    Node* RightRotation(Node* node);
    Node* SplayHelper(Node* node, int deaths);
    void InOrderTraversal(Node* root);
    void PreOrderTraversal(Node* root, string state, string city, Node*& result); //root, right, left
public:
    SplayTree();
    void Insert(string state, string city, int deaths, int unarmed, int armed);
    Node* Search(string state, string city);
    vector<Node*> GetVector();
    Node* GetRoot();
    void PostOrderDeletion(Node* root);
    ~SplayTree();

};



//Constructors
Node::Node(string state, string city, int deaths, int unarmed, int armed) {
    this->state = state;
    this->city = city;
    this->deaths = deaths;
    this->unarmed = unarmed;
    this->armed = armed;
    left = nullptr;
    right = nullptr;
    parent = nullptr;
}
Node::Node() {
    state = "";
    city = "";
    deaths = -1;
    unarmed = -1;
    armed = -1;
    left = nullptr;
    right = nullptr;
    parent = nullptr;
}

SplayTree::SplayTree() {
    treeRoot = nullptr;
}



//Rotations
Node *SplayTree::LeftRotation(Node *node) { //Zag


    Node *newParent = node->right;
    newParent->parent = node;
    node->right = newParent->left;
    newParent->left = node;
    node->parent = newParent;
    return newParent;
}
Node *SplayTree::RightRotation(Node *node) { //Zig

    Node *newParent = node->left;
    newParent->parent = node;
    node->left = newParent->right;
    newParent->right = node;
    node->parent = newParent;
    return newParent;
}



//Insertion & Deletion
void SplayTree::Insert(std::string state, std::string city, int deaths, int unarmed, int armed) {
    //treeRoot = InsertHelper(treeRoot, state, city, deaths);
    Node* temp = treeRoot;
    if(treeRoot == nullptr) {
        treeRoot = new Node(state, city, deaths, unarmed, armed);
        return;
    }
    while(temp != nullptr) {
        if(temp->deaths > deaths) {    //for cases of less deaths (push to left)
            if(temp->left == nullptr) {
                Node* child = new Node(state, city, deaths, unarmed, armed);
                child->parent = temp;
                temp->left = child;
                return;
            }
            else
                temp = temp->left;
        }
        else {      //for cases of equal deaths or greater deaths (push to right)
            if(temp->right == nullptr) {
                Node* child = new Node(state, city, deaths, unarmed, armed);
                child->parent = temp;
                temp->right = child;
                return;
            }
            else
                temp = temp->right;
        }
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
Node* SplayTree::Search(string state, string city) {
    Node* result = nullptr;
    PreOrderTraversal(treeRoot, state, city, result);
   return SplayHelper(result, result->deaths);
}
void SplayTree::PreOrderTraversal(Node *root, std::string state, std::string city, Node*& result) {
    if(root == nullptr) {
        return;
    }
    else {
        if(root->state == state && root->city == city) {
            result = root;
            return;
        }
        PreOrderTraversal(root->right, state, city, result);
        PreOrderTraversal(root->left, state, city, result);

    }
}
Node* SplayTree::SplayHelper(Node* node, int deaths) {
    Node front;
    if (node == nullptr)
        return nullptr;
    front.left = nullptr;
    front.right = nullptr;
    Node* MaxofMin = &front;
    Node* MinofMax = &front;
    bool ihatemylife = true;
    while(ihatemylife == true) {   //we manually break from loop
        if(node->deaths > deaths) {
            if(node->left == nullptr)
                break;
            if(node->left->deaths > deaths){
                node = RightRotation(node);
                if(node->left == nullptr)
                    break;
            }
            MinofMax->left= node;
            MinofMax = MinofMax->left;
            node = node->left; //iterator
            MinofMax->left = nullptr;
        }
        else if (node->deaths < deaths) {
            if (node->right == nullptr)
                break;
            if (node->right->deaths < deaths) {
                node = LeftRotation(node);
                if(node->right == nullptr)
                    break;
            }
            MaxofMin->right = node;
            MaxofMin = MaxofMin->right;
            node = node->right; //iterator
            MaxofMin->right = nullptr;
        }
        else
            break;
    }
    MinofMax->left = node->right;
    MaxofMin->right = node->left;
    node->right = front.left;
    node->left = front.right;
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
vector<Node*> SplayTree::GetVector() {
    inOrder.clear();
    InOrderTraversal(treeRoot);
    return inOrder;
}
Node* SplayTree::GetRoot() {
    return treeRoot;
}


#endif //POLICE_SHOOTING_TREE_COMPARISONN_SPLAYTREE_H
