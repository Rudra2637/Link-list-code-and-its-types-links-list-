#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node* prev;
    node(int data){
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }
};
void insertathead(node* &head,int d){
    node* temp=new node(d);
    temp->next=head;
    head->prev=temp;
   
    head=temp;
  

}
void insertatmid(node* &head,int pos,int d){
    node*temp=head;
    int cnt=1;
    while(cnt<pos-1){
        temp=temp->next;
        cnt++;
    }
    node* newnode=new node(d);
    newnode->next=temp->next;
   
    temp->next=newnode;
    newnode->prev=temp;

}
void insertattail(node* &tail,int d){
    
    node* newnode=new node(d); 
    
    tail->next=newnode;
    newnode->prev=tail;
    tail=newnode;

}
void del(node* &head,node* &tail,int pos){
    if(pos==1){
        head=head->next;
        head->prev=NULL;
        
    }
    else{
        node*temp=head;
        node*temp2=NULL;
        int cnt=1;
        while(cnt!=pos){
            temp2=temp;
            temp=temp->next;
            
            cnt++;
        }

        temp2->next=temp->next;
        
        temp->next=NULL;
        temp->prev=NULL;
        delete temp;
    }
}
void print(node* &head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int getlength(node* &head){
    node* temp=head;
    int len=0;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    return len;
}
int main(){
    node* node1=new node(10);
    node* head=node1;
    node* tail=node1;
    print(head);
    insertathead(head,20);
    print(head);
    insertathead(head,30);
    print(head);
    insertattail(tail,5);
    print(head);
    insertatmid(head,3,15);
    print(head);
    del(head,tail,4);
    print(head);
    cout<<getlength(head)<<endl;
}
