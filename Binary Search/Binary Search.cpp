#include<bits/stdc++.h>
using namespace std;

int binarysearch(int *a, int n, int x)
{
    int left=0, right=n-1, index=-1, mid;
    while(left<=right){
        mid=(left+right)/2;
        if(x==a[mid]){
            index=mid;
            break;
        }
        else if(x>a[mid]) left=mid+1;
        else right=mid-1;
    }
    return index;
}

int main()
{
    int n, x;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++) cin>>a[i];
    sort(a, a+n);
    for(int i=0; i<n; i++) cout<<a[i]<<" ";
    cout<<endl;
    cout<<"Enter a number for search: ";
    cin>>x;
    if(binarysearch(a, n, x)!=-1) cout<<"Found at position: "<<binarysearch(a, n, x);
    else cout<<"Not found";
}
//O(log2^n)
//O(1)
