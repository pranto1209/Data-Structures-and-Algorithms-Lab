#include<bits/stdc++.h>
using namespace std;

int partition(string *arr, int low, int high)
{
	string pivot=arr[high];
	int i=low;
	for(int j=low; j<high; j++){
		if(arr[j].size()<pivot.size() || (arr[j].size()==pivot.size() && arr[j]<pivot)){
			swap(arr[i], arr[j]);
			i++;
		}
	}
	swap(arr[i], arr[high]);
	return i;
}

void quick_sort(string *arr, int low, int high)
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
    string str[n];
    cout<<"Enter strings: ";
    for(i=0; i<n; i++) cin>>str[i];
    for(i=0; i<n; i++) cout<<str[i]<<" ";
    cout<<endl;

	quick_sort(str, 0, n-1);

	for(i=0; i<n; i++) cout<<str[i]<<" ";

	return 0;
}