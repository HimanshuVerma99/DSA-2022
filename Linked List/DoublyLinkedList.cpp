#include<iostream>
using namespace std;

// Code for Traversing, inserting and deleting nodes in a Doubly Linked List (Language used: cpp).

class Node{                         
                                    
    public:                         
                                    
    int data;
    Node* next;
    Node* prev;

    Node(int d){
        this -> data = d;
        this -> next = NULL;
        this -> prev = NULL;
    }

};

void print(Node* &head){
    
    Node* temp = head;

    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp -> next;
    }
    cout<<endl;

}

void InsertAtHead(Node* &head, int d){
    
    Node* temp = new Node(d);

    temp -> next = head;
    head -> prev = temp;
    head = temp;

}

void InsertAtTail(Node* &tail, int d){

    Node* temp = new Node(d);

    tail -> next = temp;
    temp -> prev = tail;
    tail = temp;

}

void InsertAtPosition(Node* &head, Node* &tail, int d, int position){

    Node* previous = head;

    if(position == 1){
        InsertAtHead(head, d);
        return;
    }

    int count = 1;
    while(count < position - 1){
        previous = previous -> next;
        count++;
    }

    Node* NodeToInsert = new Node(d);

    if(previous -> next == NULL){
        InsertAtTail(tail, d);
        return;
    }

    previous -> next -> prev = NodeToInsert;
    NodeToInsert -> next = previous -> next;
    previous -> next = NodeToInsert;
    NodeToInsert -> prev = previous;

}

void DeleteNode(Node* &head, int position){

    Node* temp = head;

    if(position == 1){
        head = head -> next;
        temp -> next = NULL;
        head -> prev = NULL;
        delete(temp);
        return;
    }

    int count = 1;

    while(count < position - 1){
        temp = temp -> next;
        count++;
    }

    Node* NodeToDelete = temp -> next;

    if(NodeToDelete -> next == NULL){
        NodeToDelete -> prev -> next = NULL;
        NodeToDelete -> prev = NULL;
        delete(NodeToDelete);
        return;
    }

    temp -> next = NodeToDelete -> next;
    NodeToDelete -> next -> prev = temp;
    NodeToDelete -> next = NULL;
    NodeToDelete -> prev = NULL;
    delete(NodeToDelete);

}

int main(){

    Node* head = new Node(5);
    Node* tail = head;

    print(head);

    InsertAtHead(head, 4);
    print(head);

    InsertAtTail(tail, 7);
    print(head);

    InsertAtPosition(head, tail, 6, 3);
    print(head);

    DeleteNode(head, 2);
    print(head);
    
    return 0;
}