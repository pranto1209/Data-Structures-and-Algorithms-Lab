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
    for(srt=head; ; ){
        if(srt->link!=NULL){
            cout<<srt->info<<" ";
            srt=srt->link;
        }
        else{
            cout<<srt->info;
            break;
        }
    }
    cout<<endl;
}

void search_unsorted(int item)
{
    node *srt;
    for(srt=head; ; ){
        if(srt->info==item){
            tmp=srt;
            cout<<"The item has found at: "<<tmp<<endl;
            break;
        }
        else if(srt->link==NULL){
            cout<<"The item not found"<<endl;
            break;
        }
        else{
            srt=srt->link;
        }
    }
}

void search_sorted(int item)
{
    node *srt;
    for(srt=head; ; ){
        if(srt->info==item){
            tmp=srt;
            cout<<"The item has found at: "<<tmp<<endl;
            break;
        }
        else if(srt->info<item){
            srt=srt->link;
        }
        else{
            cout<<"The item not found."<<endl;
            break;
        }
    }
}

void sorting()
{
    for(node *i=head; i->link!=NULL; i=i->link){
        for(node *j=i->link; j!=NULL; j=j->link){
            if(i->info>j->info) swap(i->info, j->info);
        }
    }
}

void reversing(int n)
{
    node *srt=head;
    int m=n;
    for(int i=0; i<n; i++){
        for(int j=1; j<m; j++){
            swap(srt->info,srt->link->info);
            srt=srt->link;
        }
        m--;
        srt=head;
    }
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

    cout<<"Enter a data for unsorted search: "<<endl;
    cin>>num;
    search_unsorted(num);

    sorting();
    traverse();

    cout<<"Enter a data for sorted search: "<<endl;
    cin>>num;
    search_sorted(num);

    reversing(n);
    traverse();

    return 0;
}
