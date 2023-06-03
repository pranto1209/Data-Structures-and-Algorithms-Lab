#include<iostream>
using namespace std;

class node
{
public:
    int data;
    node *next, *prev;
};
node *head=NULL, *tmp;

void creation(int item)
{
    node *ptr=new node();
    ptr->data=item;
    ptr->prev=NULL;
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
            cout<<srt->data<<" ";
            srt=srt->next;
        }
        else{
            cout<<srt->data;
            break;
        }
    }
    cout<<endl;
}

void delete_first()
{
    node *srt;
    head=head->next;
    srt=head;
    srt->prev=NULL;
}

void delete_last()
{
    node *srt;
    for(srt=head; ; ){
        if(srt->next==NULL){
            tmp->next=NULL;
            break;
        }
        else{
            tmp=srt;
            srt=srt->next;
        }
    }
}

void delete_given()
{
    node *ptr, *srt;
    int search_item;
    cout<<"Enter a data for delete it: ";
    cin>>search_item;
    for(srt=head; ; ){
        if(srt->data==search_item){
            if(srt==head){
                delete_first();
                break;
            }
            else if(srt->next==NULL){
                delete_last();
                break;
            }
            else{
                tmp->next=ptr;
                ptr->prev=tmp;
                break;
            }
        }
        else{
            tmp=srt;
            srt=srt->next;
            ptr=srt->next;
        }
    }
    traverse();
}

void delete_before()
{
    node *ptr, *srt;
    int search_item;
    cout<<"Enter a data for delete before it: ";
    cin>>search_item;
    for(srt=head;;){
        if(srt->data==search_item){
            if(tmp==head){
                delete_first();
                break;
            }
            else{
                ptr->next=srt;
                srt->prev=ptr;
                break;
            }
        }
        else{
            ptr=tmp;
            tmp=srt;
            srt=srt->next;
        }
    }
    traverse();
}

void delete_after()
{
    node *ptr, *srt;
    int search_item;
    cout<<"Enter a data for delete after it: ";
    cin>>search_item;
    for(srt=head; ; ){
        if(srt->data==search_item){
            tmp=srt->next;
            if(tmp->next==NULL){
                delete_last();
                break;
            }
            else{
                ptr=tmp->next;
                srt->next=ptr;
                ptr->prev=srt;
                break;
            }
        }
        else{
            srt=srt->next;
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
