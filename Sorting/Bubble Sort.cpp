#include <bits/stdc++.h>
using namespace std;

void bubble_sort(int a[], int n)
{
    for(int i=0; i<n; i++) {
        for(int j=0; j < n-i-1; j++) {
            if(a[j] > a[j+1]) {
                swap(a[j], a[j+1]);
            }
        }
    }
}

int main()
{
    int n, i;
    cout<<"Enter number of item for Bubble Sort: ";
    cin>>n;
    int a[n];
    cout<<"Enter items: ";
    for(i=0; i<n; i++) cin>>a[i];
    for(i=0; i<n; i++) cout<<a[i]<<" ";
    cout<<endl;
    bubble_sort(a, n);
    for(i=0; i<n; i++) cout<<a[i]<<" ";

    return 0;
}
//O(n^2)
//O(1)
