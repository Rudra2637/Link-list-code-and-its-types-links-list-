#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int d){
        this->data=d;
        this->next=NULL;
    }
};
void insertnode(node* &tail,int element,int d){
    
    if(tail==NULL){
        node* temp=new node(d);
        tail=temp;
        temp->next=temp;
    }
    else{
        node* curr=tail;
        while(curr->data!=element){
            curr=curr->next;
        }
        node* temp=new node(d);
        temp->next=curr->next;
        curr->next=temp;

    }
}
void del(node* &tail,int element){
    node* prev=tail;
    node* curr=tail->next;
    while(curr->data!=element){
        prev=curr;
        curr=curr->next;
    }
    prev->next=curr->next;
    curr->next=NULL;
    
}
void print(node* &tail){
    node* temp=tail;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    while(temp!=tail);
    cout<<endl;

    
}
int main(){
    node* tail=NULL;
    insertnode(tail,5,3);
    insertnode(tail,3,5);
    insertnode(tail,5,6);
    print(tail);
    del(tail,5);
    print(tail);
}