#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node*right;
    node*left;
    node(int x){
        data=x;
        right=left=NULL;
    }
};
node*insertlast(node*head,int x){
    if(head==NULL){
         head=new node(x);
         return head;
    }
    else{
       node*p1=head;
       while(p1->right!=NULL){
           p1=p1->right;
       }
       p1->right=new node(x);
       p1->right->left=p1;
       return head;
    }
}
node*insertfirst(node*head,int x){
    if(head==NULL){
        head=new node(x);
        return head;
    }else{
        node*p1=new node(x);
        p1->right=head;
        p1->right->left=p1;
        head=p1;
        return head;
        
    }
}
node*deletelast(node*head){
    if(head==NULL){
        cout<<"empty";
        return NULL;
    }else if(head->right==NULL){
       delete head;
        return NULL;;
    }else{
        node*p1=head;
        while(p1->right->right!=NULL){
            p1=p1->right;
        }
        delete p1->right;
            p1->right=NULL;
            return head;
    }
}
node*deleteatfirst(node*head){
    if(head==NULL) return NULL;
    else{
        node*p1=head;
        head=head->right;
       if(head!=NULL)   head->left=NULL;
        delete p1;
        return head;
    }
}
void traverse(node*head){
    node*p1=head;
    while(p1->right!=NULL){
        cout<<p1->data<<" ";
        p1=p1->right;
    }
    while(p1){
        
        cout<<p1->data<<" ";
        p1=p1->left;
    }
    
}
int main(){
    int arr[]={2,4,6,8};
    node*head=NULL;
    for(int i=0;i<4;i++){
        head=insertlast(head,arr[i]);
    }
    traverse(head);
}
