//
// Created by Akshat Pant on 12/4/22.
//

#ifndef POLICE_SHOOTING_TREE_COMPARISONN_MAXBINARYHEAP_H
#define POLICE_SHOOTING_TREE_COMPARISONN_MAXBINARYHEAP_H
#include "input.h"

class maxBinaryHeap {
    int maxHeapCap;
    int currHeapCap;
    input *node;
public:
    maxBinaryHeap(int arb);
    input pullTop();
    void deleteAll();
    void recursiveMax(int l1);
    void addVal(input val);



};

void maxBinaryHeap::deleteAll() {
    delete[] node;
}

maxBinaryHeap::maxBinaryHeap(int arb){
    this->maxHeapCap = arb;
    this->currHeapCap = 0;
    node = new input[arb];
}



//search by extracting value
void maxBinaryHeap::addVal(input val){
    node[currHeapCap] = val;
    int i;
    i = currHeapCap;
    int prnt;
    prnt = (i - 1)/2;
    while(node[prnt].deaths < node[i].deaths){
        input arb;
        arb = node[i];
        node[i] = node[prnt];
        node[prnt] = arb;
        i = (i - 1)/2;
        prnt = (i - 1)/2;


    }
    currHeapCap += 1;
}

input maxBinaryHeap::pullTop(){
    input top;
    top = node[0];
    node[0] = node[--currHeapCap];
    recursiveMax(0);
    return top;


}

void maxBinaryHeap::recursiveMax(int l1){
    if((l1 <= currHeapCap) && (currHeapCap / 2) < l1){
        return;
    }
    int lchild = 1 + (2 * l1);
    int rchild = 2 + (2 * l1);
    if(node[l1].deaths < node[rchild].deaths || node[l1].deaths < node[lchild].deaths){
        if(node[lchild].deaths <= node[rchild].deaths){
            input arb;
            arb = node[l1];
            node[l1] = node[rchild];
            node[rchild] = arb;
            recursiveMax(rchild);
        }else{
            input arb;
            arb = node[l1];
            node[l1] = node[lchild];
            node[lchild] = arb;
            recursiveMax(lchild);
        }

    }
}










#endif //POLICE_SHOOTING_TREE_COMPARISONN_MAXBINARYHEAP_H
