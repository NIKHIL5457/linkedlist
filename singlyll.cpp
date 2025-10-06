#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node*next;
    node(int x){
        data=x;
        next=NULL;
    }
};
node*insertdata(node*head,int x){
    if(head==NULL){
         head=new node(x);
         return head;
    }
    else{
       node*p1=head;
       while(p1->next!=NULL){
           p1=p1->next;
       }
       p1->next=new node(x);
       return head;
    }
}
node*insertfirst(node*head,int x){
    if(head==NULL){
        head=new node(x);
        return head;
    }else{
        node*p1=new node(x);
        p1->next=head;
        head=p1;
        return head;
        
    }
}
node*deletelast(node*head){
    if(head==NULL){
        cout<<"empty";
        return NULL;
    }else if(head->next==NULL){
        head=NULL;
        return head;
    }else{
        node*p1=head;
        while(p1->next->next!=NULL){
            p1=p1->next;
        }
        delete p1->next;
            p1->next=NULL;
            return head;
    }
}
node*deleteatfirst(node*head){
    if(head==NULL) return NULL;
    else{
        node*p1=head;
        head=head->next;
        delete p1;
        return head;
    }
}
void traverse(node*head){
    node*p1=head;
    while(p1){
        cout<<p1->data<<" ";
        p1=p1->next;
    }
}
int main(){
    int arr[]={2,4,6,8};
    node*head=NULL;
    for(int i=0;i<4;i++){
        head=insertfirst(head,arr[i]);
    }
    traverse(head);
}
