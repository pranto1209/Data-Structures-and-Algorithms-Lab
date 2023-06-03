#include<iostream>
using namespace std;

class node
{
public:
    int info;
    node *next, *prev;
};
node *head=NULL, *tmp;

void creation(int item)
{
    node *ptr=new node();
    ptr->prev=NULL;
    ptr->info=item;
    ptr->next=NULL;
    if(head==NULL){
        head=ptr;
        tmp=ptr;
    }
    else{
        tmp->next=ptr;
        ptr->prev=tmp;
        tmp=ptr;
    }
}

void traverse()
{
    node *srt;
    for(srt=head; ; ){
        if(srt->next!=NULL){
            cout<<srt->info<<" ";
            srt=srt->next;
        }
        else{
            cout<<srt->info;
            break;
        }
    }
    cout<<endl;
}

void insert_first(int item)
{
    node *ptr=new node();
    ptr->prev=NULL;
    ptr->info=item;
    ptr->next=head;
    head->prev=ptr;
    head=ptr;
}

void insert_last(int item)
{
    node *ptr=new node();
    ptr->prev=tmp;
    ptr->info=item;
    ptr->next=NULL;
    tmp->next=ptr;
    tmp=ptr;
}

void insert_before(int item)
{
    node *srt;
    int search_item;
    cout<<"Enter a number for inserting before it: ";
    cin>>search_item;
    for(srt=head; ; ){
        if(srt->info==search_item){
            if(srt==head){
                insert_first(item);
                break;
            }
            else{
                node *ptr=new node();
                ptr->prev=tmp;
                ptr->info=item;
                ptr->next=srt;
                srt->prev=ptr;
                tmp->next=ptr;
                break;
            }
        }
        else{
            tmp=srt;
            srt=srt->next;
        }
        if(srt==NULL){
            cout<<"The search item not found."<<endl;
            break;
        }
    }
    traverse();
}

void insert_after(int item)
{
    node *srt;
    int search_item;
    cout<<"Enter a number for inserting after it: ";
    cin>>search_item;
    for(srt=head; ; ){
        if(srt->info==search_item){
            tmp=srt->next;
            if(tmp==NULL){
                insert_last(item);
                break;
            }
            else{
                node *ptr=new node();
                ptr->prev=srt;
                ptr->info=item;
                ptr->next=tmp;
                srt->next=ptr;
                tmp->prev=ptr;
                break;
            }
        }
        else{
            srt=srt->next;
        }
        if(srt==NULL){
            cout<<"The search item not found."<<endl;
            break;
        }
    }
    traverse();
}

int main()
{
    int n, data;
    cout<<"Enter number of item: ";
    cin>>n;
    cout<<"Enter items: ";
    for(int i=0; i<n; i++)
    {
        cin>>data;
        creation(data);
    }

    traverse();

    int num;

    cout<<"Enter a data for insert first: ";
    cin>>num;
    insert_first(num);
    traverse();

    cout<<"Enter a data for insert last: ";
    cin>>num;
    insert_last(num);
    traverse();

    cout<<"Enter a data for insert before a given number: ";
    cin>>num;
    insert_before(num);

    cout<<"Enter a data for insert after a given number: ";
    cin>>num;
    insert_after(num);

    return 0;
}
