


#ifndef POLICE_SHOOTING_TREE_COMPARISONN_SPLAYTREE_H
#define POLICE_SHOOTING_TREE_COMPARISONN_SPLAYTREE_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;

struct Node {
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
    Node* InsertHelper(Node* root, string state, string city, int deaths, int unarmed, int armed);
    Node* SplayHelper(Node* node);
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

SplayTree::SplayTree() {
    treeRoot = nullptr;
}



//Rotations
Node *SplayTree::LeftRotation(Node *node) { //Zag

    cout << "LRotation\n" <<endl;
    Node* newParent = node->right;
    newParent->parent = node->parent;
    Node* grandchild = newParent->left;
    newParent->left = node;
    node->parent = newParent;
    node->right = grandchild;
    if(grandchild != nullptr)
        grandchild->parent = node;
    cout << "T6\n" <<endl;
    return newParent;
}
Node *SplayTree::RightRotation(Node *node) { //Zig
    cout << "RRotation\n" <<endl;
    Node* newParent = node->left;
    if(newParent->parent != nullptr)
        newParent->parent = node->parent;
    Node* grandchild = newParent->right;
    newParent->right = node;
    node->parent = newParent;
    node->left = grandchild;
    if(grandchild != nullptr)
        grandchild->parent = node;
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
                temp->left = child;     //splay here
                SplayHelper(child);
                return;
            }
            else
                temp = temp->left;
        }
        else {      //for cases of equal deaths or greater deaths (push to right)
            if(temp->right == nullptr) {
                Node* child = new Node(state, city, deaths, unarmed, armed);
                child->parent = temp;
                temp->right = child;     //splay here
                SplayHelper(child);
                return;
            }
            else
                temp = temp->right;
        }
    }

}
//Node* SplayTree::InsertHelper(Node *root, std::string state, std::string city, int deaths, int unarmed, int armed) {
//    if(root == nullptr) {
//        Node* tempNode = new Node(state, city, deaths);
//        return tempNode;
//    }
//    else if(root->deaths > deaths) {
//        root->left = InsertHelper(root->left, state, city, deaths);
//    }
//    else { //if they are equal push to right
//        root->right = InsertHelper(root->right, state, city, deaths);
//    }
//}
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
    SplayHelper(result);
    return result;
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
Node *SplayTree::SplayHelper(Node* node) {
    if(treeRoot == nullptr)
        return nullptr;
    cout << "Made it to SplayHelper" << endl;
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
            LeftRotation(node->parent);
            RightRotation(node->parent);
        }
        else (node->parent->left == node && node->parent->parent->right == node->parent){
            RightRotation(node->parent);
            LeftRotation(node->parent);
        }
    }
    treeRoot = node;
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
