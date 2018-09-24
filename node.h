#ifndef NODE_H
#define NODE_H

#include <iostream>

template <typename T>
struct Node {
    T data;
    struct Node* next;
    void killSelf(){
        if(next!=nullptr)
            next->killSelf();
        delete this;
    };
};

#endif
