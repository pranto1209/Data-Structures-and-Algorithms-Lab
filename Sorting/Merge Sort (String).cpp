#include<bits/stdc++.h>
using namespace std;

void Merge(string *arr, int low, int mid, int high)
{
	int i, j, k;
	int nlow=mid-low+1;
	int nhigh=high-mid;
	string L[nlow], R[nhigh];

	for(i=0; i<nlow; i++) L[i]=arr[low+i];
	for(j=0; j<nhigh; j++) R[j]=arr[mid+1+j];
	i=0;
	j=0;
	k=low;
	while(i<nlow && j<nhigh){
		if(L[i].size()<=R[j].size() && L[i]<=R[j]){
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

void merge_sort(string *arr, int low, int high)
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
    string str[n];
    cout<<"Enter strings: ";
    for(i=0; i<n; i++) cin>>str[i];
    for(i=0; i<n; i++) cout<<str[i]<<" ";
    cout<<endl;

	merge_sort(str, 0, n-1);

	for(i=0; i<n; i++) cout<<str[i]<<" ";

	return 0;
}
