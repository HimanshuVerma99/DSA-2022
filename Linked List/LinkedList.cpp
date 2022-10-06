#include<iostream>
using namespace std;

// Code for Singly Linked List Data Structure including Traversing, Inserting and deleting Nodes.

class Node{

    public:
    int data;
    Node* next;

    Node(int d){
        this -> data = d;
        this -> next = NULL;
    }

};

void print(Node* head){

    Node* temp = head;

    while(temp != NULL){
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<endl;

}

void InsertAtHead(Node* &head, int d){

    Node* temp = new Node(d);                   
    
    temp -> next = head;                       

    head = temp;                               

}

void InsertAtTail(Node* &tail, int d){          
    
    Node* temp = new Node(d);

    tail -> next  = temp;                       
    tail = temp;                                

}

void InsertAtPosition(Node* &head, int d, int position){

    if(position == 1){                 
        InsertAtHead(head, d);         
        return;
    }

    Node* temp = head;

    int count = 1;

    while(count < position-1){              
        temp = temp -> next;                
        count++;
    }

    Node* NodeToInsert = new Node(d);       

    NodeToInsert -> next = temp -> next;    
    temp -> next = NodeToInsert;

}

void DeleteNode(Node* &head, int position){

    Node* prev = head;                  
    if(position == 1){                  
        head = head -> next;            
        prev -> next = NULL;            
        delete(prev);                   
        return;                         
    }

    int count = 1;

    while(count < position - 1){        
        prev = prev -> next;
        count++;
    }

    Node* NodeToDelete = prev -> next;  

    prev -> next = NodeToDelete -> next;    
    NodeToDelete -> next = NULL;            
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

    InsertAtPosition(head, 6, 3);
    print(head);

    DeleteNode(head, 2);
    print(head);
    
    return 0;
}