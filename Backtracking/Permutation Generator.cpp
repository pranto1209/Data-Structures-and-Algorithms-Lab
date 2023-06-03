#include<bits/stdc++.h>
using namespace std;
bool taken[1000];
int n, pos[1000];
void backtrack(int idx)
{
    if(idx==n){
        for(int i=0; i<n; i++) cout<<pos[i]<<" ";
        cout<<"\n";
        return;
    }
    for(int i=0; i<n; i++){
        if(taken[i]==false){
            taken[i]=true;
            pos[idx]=i;
            backtrack(idx+1);
            taken[i]=false;
        }
    }
}

int main()
{
    cin>>n;
    backtrack(0);
}
