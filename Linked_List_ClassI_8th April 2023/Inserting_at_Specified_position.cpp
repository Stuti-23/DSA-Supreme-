#include <iostream>
using namespace std;
class node{
  public:
  int data;
  node* next;
  
  node(){
    this->data =0;
    this->next=NULL;
  }

  node(int data){
    this->data =data;
    this->next =NULL;
  }
};
void display(node* head){
  node* temp=head;
  while(temp!=NULL){
    cout<<temp->data<<" ";
    temp=temp->next;
  }

}
void insertathead(node* &head,node* &last,int data){
  if(head==NULL){
    node* temp=new node(data);
    head=temp;
    last=temp;
    return;
   
  }
  node *temp=new node(data);
  temp->next=head;
  head=temp;

}
void insertatlast(node* &head,node* &last,int data){
  if(head==NULL){
    node* temp=new node(data);
    head=temp;
    last=temp;
    return;
  }
  node* temp=new node(data);
  
  last->next=temp;

 last=temp;
}

int length(node* &head){
  node* temp=head;
  int len=0;
  while(temp!=NULL){
    temp=temp->next;
    len++;
  }
  return len;
}
void insertatpos(int pos,int data,node* &head,node* &last){
  if(head==NULL){
    node* newnode=new node(data);
    head=newnode;
    last=newnode;
    return ;
  }
  if(pos==0){
    insertathead(head,last,data);
    return;
  }
  int len=length(head);
  if(pos>=len){
    insertatlast(head,last,data);
  }
  else{
  int i=1;
  node* prev=head;

  while(i<pos){
    prev = prev->next;
    i++;
  }
  node* curr=prev->next;

  node* newnode=new node(data);
 
  newnode->next=curr;
  prev->next=newnode;}
  

}
int main() {
  node *first=NULL;
  node* last=NULL;
  insertathead(first,last,20);
   insertathead(first,last,30);
    insertathead(first,last,40);
     insertathead(first,last,50);
     insertatlast(first,last,10);
     insertatlast(first,last,30);
     insertatlast(first,last,60);
  display(first);
  insertatpos(8,12,first,last);
  cout<<endl;
  display(first);
  return 0;
}
        

    
  
