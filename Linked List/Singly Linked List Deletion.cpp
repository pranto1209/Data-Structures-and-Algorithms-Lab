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

void delete_first()
{
    node *srt=head;
    head=srt->link;
}

void delete_last()
{
    node *srt;
    for(srt=head; ; ){
        if(srt->link==NULL){
            tmp->link=NULL;
            break;
        }
        else{
            tmp=srt;
            srt=srt->link;
        }
    }
}

void delete_given()
{
    node *srt;
    int search_item;
    cout<<"Enter a data for delete it: ";
    cin>>search_item;
    for(srt=head; ; ){
        if(srt->info==search_item){
            if(srt==head){
                delete_first();
                break;
            }
            else if(srt->link==NULL){
                delete_last();
                break;
            }
            else{
                tmp->link=srt->link;
                break;
            }
        }
        else{
             tmp=srt;
             srt=srt->link;
        }
        if(srt==NULL){
            cout<<"The search item not found"<<endl;
            break;
        }
    }
    traverse();
}

void delete_before()
{
    node *srt, *prev;
    int search_item;
    cout<<"Enter a data for delete before it: ";
    cin>>search_item;
    for(srt=head; ; ){
        if(srt->info==search_item){
            if(tmp==head){
                delete_first();
                break;
            }
            else{
                prev->link=tmp->link;
                break;
            }
        }
        else{
            prev=tmp;
            tmp=srt;
            srt=srt->link;
        }
        if(srt==NULL){
            cout<<"The search item not found"<<endl;
            break;
        }
    }
    traverse();
}

void delete_after()
{
    node *srt;
    int search_item;
    cout<<"Enter a data for delete after it: ";
    cin>>search_item;
    for(srt=head; ; ){
        if(srt->info==search_item){
            tmp=srt->link;
            if(tmp->link==NULL){
                delete_last();
                break;
            }
            else{
                srt->link=tmp->link;
                break;
            }
        }
        else{
            srt=srt->link;
        }
        if(srt==NULL){
            cout<<"The search item not found"<<endl;
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

    char ch;

    cout<<"Enter a character 'f' for delete first item: ";
    cin>>ch;
    if(ch=='f'){
        delete_first();
        traverse();
        cout<<"First item deleted."<<endl;
    }
    cout<<endl;

    cout<<"Enter a character 'l' for delete last item: ";
    cin>>ch;
    if(ch=='l'){
        delete_last();
        traverse();
        cout<<"Last item deleted."<<endl;
    }
    cout<<endl;

    delete_given();
    cout<<"Given item deleted."<<endl;
    cout<<endl;

    delete_before();
    cout<<"Before a given item deleted."<<endl;
    cout<<endl;

    delete_after();
    cout<<"Afer a given item deleted."<<endl;

    return 0;
}
