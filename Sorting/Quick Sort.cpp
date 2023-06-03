#include<bits/stdc++.h>
using namespace std;

int partition(int *arr, int low, int high)
{
	int pivot=arr[high];
	int i=low;
	for(int j=low; j<high; j++){
		if(arr[j]<pivot){
			swap(arr[i], arr[j]);
			i++;
		}
	}
	swap(arr[i], arr[high]);
	return i;
}

void quick_sort(int *arr, int low, int high)
{
	if(low<high){
		int pi=partition(arr, low, high);
		quick_sort(arr, low, pi-1);
		quick_sort(arr, pi+1, high);
	}
}

int main()
{
    int n, i;
    cout<<"Enter number of item for Quick Sort: ";
    cin>>n;
    int a[n];
    cout<<"Enter items: ";
    for(i=0; i<n; i++) cin>>a[i];
    for(i=0; i<n; i++) cout<<a[i]<<" ";
    cout<<endl;

	quick_sort(a, 0, n-1);

	for(i=0; i<n; i++) cout<<a[i]<<" ";

	return 0;
}
