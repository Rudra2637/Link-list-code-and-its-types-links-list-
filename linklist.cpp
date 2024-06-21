#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node *next;  
    node(int data){
        this->data=data;
        this->next=nullptr;
    }
};
    void insertathead(node* &head,int d){
        node* temp=new node(d);
        temp->next=head;
        head=temp;
    }
    void insertattail(node* &tail,int d){
        node* temp1=new node(d);
        tail->next=temp1;
        tail=temp1;
       
    }
    void insertatmid(node* &head,int position,int d){
        node* temp=head;
        int cnt=1;
        while(cnt<position-1){
            temp=temp->next;
            cnt++;
        }
        node* newnode=new node(d);
        
        newnode->next=temp->next;
        temp->next=newnode;
    }
    void del(int position,node* &head,node* &tail){
        
        if(position==1){
            node*temp= head;
            head=head->next;
            temp->next=NULL;
            delete temp;
            return;
        }
        node*temp1= head;
        int cnt=1;
        while(cnt<position-1){
            temp1=temp1->next;
            cnt++;
        }
        node* nodetodel=temp1->next;
        temp1->next=nodetodel->next;
        nodetodel->next=NULL;
        delete nodetodel;
        


    }
   

    
    void print(node* &head){
        node* temp=head;
        while(temp!=nullptr){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
int searchInLinkedList(node* &head, int k) {
    node* temp=head;
    while(temp!=NULL){
        if(temp->data==k){
            return 1;
        }
        else{
            temp=temp->next;
        }
    }
    return -1;
}
node *findMiddle(node *head) {
   //Tortoise & Hare Algorithm

    //pointers

    node* slow = head;

    node* fast = head;

    while(fast != NULL && fast -> next != NULL){

        //moves 1 step

        slow = slow -> next;

        //moves 2 steps

        fast = fast -> next -> next;

    }

    //slow will give mid node

    return slow;
}
    

int main(){
    

    node* node1=new node(10);
    node* head=node1;
    node* tail=node1;
    print(head);

    insertattail(tail,20);
    print(head);
    insertattail(tail,30);
    print(head);
    insertatmid(head,3,25);
    print(head);
    cout<<*findMiddle(head)<<endl;
    
    cout<<searchInLinkedList(head,34);

    return 0;
}