#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
vector<pii>v;
bool cmp(pii a, pii b)
{
    return a.second*b.first>a.first*b.second;
}
int main()
{
    int n, w, weight, price;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>weight>>price;
        v.push_back({weight, price});
    }
    sort(v.begin(), v.end(), cmp);
    cin>>w;
    int sum=0;
    for(int i=0; i<n; i++){
        int z=min(w, v[i].first);
        w-=z;
        sum+=z*v[i].second;
    }
    cout<<"Maximum Cost: "<<sum<<"\n";
}
