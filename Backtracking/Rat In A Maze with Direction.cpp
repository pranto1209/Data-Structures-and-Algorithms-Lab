#include<bits/stdc++.h>
using namespace std;
int n, dir, a[100][100], sol[100][100];
int r, l, u, d;
void path()
{
    cout<<"The Path is: \n";
    for (int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<sol[i][j]<<" ";
        }
        cout<<"\n";
    }
}
bool backtrack(int x, int y)
{
    if(x==n-1 && y==n-1){
        sol[x][y]=1;
        return true;
    }
    if(x>=0 && x<n && y>=0 && y<n && a[x][y]==1){
        sol[x][y]=1;
        if(d) if(backtrack(x+1, y)) return true;
        if(u) if(backtrack(x-1, y)) return true;
        if(r) if(backtrack(x, y+1)) return true;
        if(l) if(backtrack(x, y-1)) return true;
        sol[x][y]=0;
        return false;

    }
    return false;
}

int main()
{
    string s;
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>a[i][j];
        }
    }

    memset(sol, 0, sizeof(sol));

    cin>>dir;
    for(int i=0; i<dir; i++){
        cin>>s;
        if(s=="up") u=1;
        if(s=="down") d=1;
        if(s=="left") l=1;
        if(s=="right") r=1;
    }

    if(backtrack(0, 0)) path();
    else cout<<"There have no Path\n";
}

/*

4
1 1 0 0
1 1 0 1
0 1 0 0
1 1 1 1
2
down right

*/

