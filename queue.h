#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include "node.h"
//first in first out
using namespace std;

template <typename T>
class Queue{
private:
    Node<T>* head;
    Node<T>* tail;
    int nodes;
public:
    Queue(){
        head= nullptr;
        tail= nullptr;
        nodes=0;
    };
    T get(){
        if(!head){
            throw "Lista Vacia";
        } else{
            return head->data;
        }
    };
    void push(T value){//back
        auto* temp= new Node<T>{value, nullptr};
        if (head==nullptr) {
            head=temp;
            tail=temp;

        }else{
            tail->next=temp;
            tail=temp;
        }
        nodes++;
    };
    void pop(){ //front
        auto* temp=head;
        if(!head)
            throw "Lista vacia";
        if(nodes==1)
            head=tail=nullptr;
        else{
            head=temp->next;
        }
        delete temp;
        nodes--;
    };
    T get(int position){
        if(!head){
            throw "Vacio";
        }
        auto* temp=head;
        for (int i = 1; i < position; i++) {
            temp=temp->next;
        }
        return temp->data;
    };
    void print(){
        Node<T>* actual=head;
        while(actual!=tail){
            cout<<actual->data<<" ";
            actual=actual->next;
        }
        cout<<tail->data<<endl;

    };
    bool empty(){
        return head == nullptr;
    };
    int size(){
        return nodes;
    };
    void clear(){
        head=nullptr;
        tail=nullptr;
        nodes=0;
    };
    ~Queue(){
        if(head){
            head->killSelf();
        }
        //delete  head;
        // delete  tail;
    };
};
#endif
