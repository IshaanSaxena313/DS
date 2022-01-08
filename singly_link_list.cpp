#include<iostream>
using namespace std;
struct node{
    int info;
    node* next;
};
void addlast(node* &,int);
void display(node* );
void addfirst(node* &,int);
void count(node* );
void addafter(node* &,int,int);
void addbefore(node* &,int,int);
void delnode(node* &,int);
void freeall(node* &);
void minimum(node* &);
void sort(node* &);
void reverse(node* &);
int main(){
    node *start=NULL;
    int element,number,choice;
    cout<<"MENU\n";
    while(1){
        //system("cls");
        cout<<"1. Add-First\n"<<"2. Add-Last\n"<<"3. Add-after\n"<<"4. Add-before\n";
        cout<<"5. Delete node\n"<<"6. Traverse\n"<<"7. Count\n"<<"8. Minimum\n"<<"9. SORT\n"<<"10. Reverse\n"<<"11. EXIt\n"<<endl;
        cout<<"Enter yout choice :\t";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter the element to be added at first :\t";
                cin>>element;
                addfirst(start,element);
                display(start);
                break;
            case 2:
                cout<<"Enter the element to be added at last :\t";
                cin>>element;
                addlast(start,element);
                display(start);
                break;
            case 3:
                cout<<"Enter the element to be inserted :\t";
                cin>>element;
                cout<<"Enter the element after which new element is to be inserted :\t";
                cin>>number;
                addafter(start,number,element);
                display(start);
                break;
            case 4:
                cout<<"Enter the element to be inserted :\t";
                cin>>element;
                cout<<"Enter the element before which new element is to be inserted :\t";
                cin>>number;
                addbefore(start,number,element);
                display(start);
                break;
            case 5:
                cout<<"Enter the element you want to delete :\t";
                cin>>element;
                delnode(start,element);
                display(start);
                break;
            case 6:
                cout<<"The Linked List is:-"<<endl;
                display(start);
                break;
            case 7:
                count(start);
                break;
            case 8:
                minimum(start);
                break;
            case 9:
                sort(start);
                break;
            case 10:
                cout<<"Reversed Linked lIst is:- "<<endl;
                reverse(start);
                display(start);
                break;
            case 11:
                exit(1);
                freeall(start);
                break;
            default:
                cout<<"Invalid input!"<<endl;
        }
    }
    return 0;
}
void addfirst(node* &start,int n){
    node* newnode;
    newnode=new node;
    newnode->info=n;
    newnode->next=start;
    start=newnode;
}
void addlast(node* &start,int n){
    node* newnode,*ptr;
    newnode=new node;
    newnode->info=n;
    newnode->next=NULL;
    if(start==NULL)
        start=newnode;
    else{
        ptr=start;
        while(ptr->next!=NULL)
            ptr=ptr->next;
        ptr->next=newnode;
    }
}
void display(node* ptr){
    node* p=ptr;
    while(p!=NULL){
        cout<<p->info<<"\t";
        p=p->next;
    }
    cout<<endl;
}
void addafter(node* &start,int n,int value){
    node* newnode,*ptr;
    ptr=start;
    newnode=new node;
    newnode->info=value;
    while(ptr->info!=n && ptr!=NULL)
        ptr=ptr->next;
    if(ptr==NULL)
        cout<<"Element not found"<<endl;
    else{
        newnode->next=ptr->next;
        ptr->next=newnode;
    }
}
void addbefore(node* &start,int n,int value){
    node* newnode,*ptr,*preptr;
    preptr=NULL;
    ptr=start;
    newnode=new node;
    newnode->info=value;
    while(ptr->info!=n && ptr!=NULL){
        preptr=ptr;
        ptr=ptr->next;
    }
    if(ptr==NULL)
        cout<<"Element not found"<<endl;
    if(ptr==start){
        newnode->next=start;
        start=newnode;
    }
    else{
        preptr->next=newnode;
        newnode->next=ptr;
    }
}
void count(node* start){
    node* ptr=start;
    int count=0;
    while(ptr!=NULL){
        ptr=ptr->next;
        count++;
    }    
    cout<<"\nTotal number of elements are "<<count<<endl;
}
void delnode(node* &start,int n){
    node* ptr,*preptr;
    preptr=NULL;
    ptr=start;
    while(ptr->info!=n && ptr!=NULL){
        preptr=ptr;
        ptr=ptr->next;
    }
    if(ptr==NULL)
        cout<<"Element not found"<<endl;
    if(ptr==start)
        start=ptr->next;
    else
        preptr->next=ptr->next;
    delete (ptr);
}
void freeall(node* &start){
    while(start!=NULL){\
        node* ptr=start;
        start=start->next;
        delete (ptr);
    }
}
void minimum(node* &start){
    int min=0;
    node* ptr;
    ptr=start;
    min=ptr->info;
    while(ptr!=NULL){
        if(min>ptr->info)
            min=ptr->info;
        else
            ptr=ptr->next;
    }
    cout<<"Minimum is :\t"<<min<<endl;
}
void sort(node* &start){
    node* p1,*p2;
    for(p1=start;p1->next!=NULL;p1=p1->next)
        for(p2=p1->next;p2!=NULL;p2=p2->next){
            if(p1->info>p2->info){
                int temp=p1->info;
                p1->info=p2->info;
                p2->info=temp;
            }
        }
}
void reverse(node* &start){
    node* p1,* p2=NULL,* p3=start;
    while(p3!=NULL){
        p1=p2;
        p2=p3;
        p3=p3->next;
        p2->next=p1;
    }
    start=p2;
}