#include<iostream>
using namespace std;

void selection_sort(int *a, int n)
{
    int min_index;
    for(int i=0; i<n-1; i++){
        min_index=i;
        for(int j=i+1; j<n; j++){
            if(a[min_index]>a[j]){
                min_index=j;
            }
        }
        if(min_index!=i){
            swap(a[i], a[min_index]);
        }
    }
}

int main()
{
    int n, i;
    cout<<"Enter number of item for selection sort: ";
    cin>>n;
    int a[n];
    cout<<"Enter items: ";
    for(i=0; i<n; i++) cin>>a[i];
    for(i=0; i<n; i++) cout<<a[i]<<" ";
    cout<<endl;
    selection_sort(a, n);
    for(i=0; i<n; i++) cout<<a[i]<<" ";

    return 0;
}
//O(n^2)
//O(1)
