#include<iostream>
using namespace std;

class node
{
public:
    int info;
    node *link;
};
node *head=NULL, *tmp;

void creation(int item)
{
    node *ptr=new node();
    ptr->info=item;
    ptr->link=NULL;
    if(head==NULL){
        head=ptr;
        tmp=ptr;
    }
    else{
        tmp->link=ptr;
        tmp=ptr;
    }
}

void traverse()
{
    node *srt;
    for(srt=head; srt!=NULL; srt=srt->link){
        cout<<srt->info<<" ";
    }
    cout<<endl;
}

void insert_first(int item)
{
    node *ptr=new node();
    ptr->info=item;
    ptr->link=head;
    head=ptr;
}

void insert_last(int item)
{
    node *srt;
    node *ptr=new node();
    ptr->info=item;
    ptr->link=NULL;
    for(srt=head; ;srt=srt->link){
        if(srt->link==NULL){
            srt->link=ptr;
            break;
        }
    }
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
                ptr->info=item;
                ptr->link=srt;
                tmp->link=ptr;
                break;
            }
        }
        else{
            tmp=srt;
            srt=srt->link;
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
            if(srt->link==NULL){
                insert_last(item);
                break;
            }
            else{
                node *ptr=new node();
                ptr->info=item;
                ptr->link=srt->link;
                srt->link=ptr;
                break;
            }
        }
        else{
            srt=srt->link;
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
    for(int i=0; i<n; i++){
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
