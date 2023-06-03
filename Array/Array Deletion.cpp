#include<iostream>
using namespace std;
int a[100000];
int n, i;

void traverse()
{
    for(i=0; i<n; i++) cout<<a[i]<<" ";
    cout<<endl;
}

void delete_first()
{
    for(i=0; i<n-1; i++) a[i]=a[i+1];
    a[n]=0;
    n--;
}

void delete_last()
{
    a[n]=0;
    n--;
}

void delete_given()
{
    int search_item, r=-1;
    cout<<"Enter a data for delete it: ";
    cin>>search_item;
    for(i=0; i<n; i++)
    {
        if(a[i]==search_item)
        {
            r=i;
            for(i=r; i<n-1; i++) a[i]=a[i+1];
            a[n]=0;
            n--;
            break;
        }
    }
    if(r==-1)
    {
        cout<<"The search item not found."<<endl;
    }
}

void delete_before()
{
    int search_item, r=-1;
    cout<<"Enter a data for delete before it: "<<endl;
    cin>>search_item;
    for(i=0; i<n; i++)
    {
        if(a[i]==search_item)
        {
            r=i-1;
            for(i=r; i<n-1; i++) a[i]=a[i+1];
            a[n]=0;
            n--;
            break;
        }
    }
    if(r==-1)
    {
        cout<<"The search item not found."<<endl;
    }
}

void delete_after()
{
    int search_item, r=-1;
    cout<<"Enter a data for delete after it: "<<endl;
    cin>>search_item;
    for(i=0; i<n; i++)
    {
        if(a[i]==search_item)
        {
            r=i+1;
            for(i=r; i<n-1; i++) a[i]=a[i+1];
            a[n]=0;
            n--;
            break;
        }
    }
    if(r==-1)
    {
        cout<<"The search item not found."<<endl;
    }
}

int main()
{
    cout<<"Enter number of item: ";
    cin>>n;
    cout<<"Enter items: ";
    for(int i=0; i<n; i++) cin>>a[i];

    traverse();

    char ch;

    cout<<"Enter a character 'f' for delete first item: ";
    cin>>ch;
    if(ch=='f')
    {
        delete_first();
        traverse();
        cout<<"First item deleted"<<endl;
    }

    cout<<"Enter a character 'l' for delete last item: ";
    cin>>ch;
    if(ch=='l')
    {
        delete_last();
        traverse();
        cout<<"Last item deleted"<<endl;
    }

    delete_given();
    traverse();
    cout<<"Given item deleted"<<endl;

    delete_before();
    traverse();
    cout<<"Before a given item deleted"<<endl;

    delete_after();
    traverse();
    cout<<"Afer a given item deleted"<<endl;

    return 0;
}
