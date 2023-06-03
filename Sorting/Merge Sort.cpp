#include<bits/stdc++.h>
using namespace std;

void Merge(int *arr, int low, int mid, int high)
{
	int i, j, k;
	int nlow=mid-low+1;
	int nhigh=high-mid;
	int L[nlow], R[nhigh];

	for(i=0; i<nlow; i++) L[i]=arr[low+i];
	for(j=0; j<nhigh; j++) R[j]=arr[mid+1+j];
	i=0;
	j=0;
	k=low;
	while(i<nlow && j<nhigh){
		if(L[i]<=R[j]){
			arr[k]=L[i];
			i++;
		}
		else{
			arr[k]=R[j];
			j++;
		}
		k++;
	}
	while(i<nlow){
		arr[k]=L[i];
		i++;
		k++;
	}

	while(j<nhigh){
		arr[k]=R[j];
		j++;
		k++;
	}
}

void merge_sort(int *arr, int low, int high)
{
	if(low<high){
        int mid=low+(high-low)/2;
		merge_sort(arr, low, mid);
		merge_sort(arr, mid+1, high);
		Merge(arr, low, mid, high);
	}
}

int main()
{
    int n, i;
    cout<<"Enter number of item for Merge Sort: ";
    cin>>n;
    int a[n];
    cout<<"Enter items: ";
    for(i=0; i<n; i++) cin>>a[i];
    for(i=0; i<n; i++) cout<<a[i]<<" ";
    cout<<endl;

	merge_sort(a, 0, n-1);

	for(i=0; i<n; i++) cout<<a[i]<<" ";

	return 0;
}
