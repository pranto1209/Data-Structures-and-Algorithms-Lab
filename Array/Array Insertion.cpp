#include<iostream>
using namespace std;
int a[100000];
int n, i;

void traverse()
{
    for(i=0; i<n; i++) cout<<a[i]<<" ";
    cout<<endl;
}

void insert_first(int item)
{
    for(i=n-1; i>=0; i--) a[i+1]=a[i];
    a[0]=item;
    n++;
}

void insert_last(int item)
{
    a[n]=item;
    n++;
}

void insert_before(int item)
{
    int search_item, r=-1;
    cout<<"Enter a number for inserting before it: ";
    cin>>search_item;
    for(i=0; i<n; i++)
    {
        if(a[i]==search_item)
        {
            r=i;
            for(i=n-1; i>=r; i--) a[i+1]=a[i];
            a[r]=item;
            n++;
            break;
        }
    }
    if(r==-1)
    {
        cout<<"The search item not found."<<endl;
    }
}

void insert_after(int item)
{
    int search_item, r=-1;
    cout<<"Enter a number for inserting after it: ";
    cin>>search_item;
    for(i=0; i<n; i++)
    {
        if(a[i]==search_item)
        {
            r=i+1;
            for(i=n-1; i>=r; i--) a[i+1]=a[i];
            a[r]=item;
            n++;
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
    for(i=0; i<n; i++) cin>>a[i];

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
    traverse();

    cout<<"Enter a data for insert after a given number: ";
    cin>>num;
    insert_after(num);
    traverse();

    return 0;
}
