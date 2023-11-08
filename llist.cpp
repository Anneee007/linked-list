#include<iostream>
using namespace std;
struct node{
    int info;
    struct node *next;
};
typedef struct node node;

node* insertAtFirst(node *head,int value){
    node *temp;
    temp=(node*)malloc(sizeof(node));
    if(head==NULL){
        head=temp;
        head->info=value;
        head->next=NULL;
    }
    else{
        temp->next=head;
        temp->info=value;
        head=temp;
    }
    return head;
}
node* insertAtLast(node *head,int value){
    node *temp;
    temp=(node*)malloc(sizeof(node));
    temp->info=value;
    temp->next=NULL;
    if(head==NULL){
        head=temp;
    }
    else{
        node *temp2=head;
        while(temp2->next!=NULL){
            temp2=temp2->next;
        }
        temp2->next=temp;
    }
    return head;
}
node* insertAtGivenPosition(node *head,int value,int p){
    node *temp;
    temp=(node*)malloc(sizeof(node*));
    temp->info=value;
    temp->next=NULL;
    if(p==1){
        temp->next=head;
        head=temp;
    }
    else{
        node *temp2=head;
        while((p-1)!=1 && temp2!=NULL){
            temp2=temp2->next;
            p--;
        }
        temp->next=temp2->next;
        temp2->next=temp;
    }
    return head;
    
}
void display(node *head){
    node *temp=head;
    while(temp!=NULL){
        cout<<temp->info<<" ";
        temp=temp->next;
    }
    cout<<endl;
    
}

int main(){
    node *head=NULL;
    head=insertAtFirst(head,2);
    display(head);
    int ch;
    do{
        cout<<"Enter Choice 0/1: \n";
        cin>>ch;
        int value,p;
        cin>>value>>p;
        head=insertAtGivenPosition(head,value,p);
        display(head);
    }while(ch==1);
    return 0;
}