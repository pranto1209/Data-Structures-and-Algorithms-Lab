#include<iostream>
using namespace std;

void insertion_sort(int *a, int n)
{
    int i, j, item;
    for(i=1; i<n; i++){
        item=a[i];
        j=i-1;
        while(j>=0 && a[j]>item){
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=item;
    }
}

int main()
{
    int n, i;
    cout<<"Enter number of item for Insertion Sort: ";
    cin>>n;
    int a[n];
    cout<<"Enter items: ";
    for(i=0; i<n; i++) cin>>a[i];
    for(i=0; i<n; i++) cout<<a[i]<<" ";
    cout<<endl;
    insertion_sort(a, n);
    for(i=0; i<n; i++) cout<<a[i]<<" ";

    return 0;
}
//O(n^2)
//O(1)
