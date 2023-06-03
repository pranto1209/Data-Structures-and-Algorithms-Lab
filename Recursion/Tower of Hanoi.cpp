#include<iostream>
using namespace std;

void TOH(int d, char tower1, char tower2, char tower3)
{
    if(d==1){
        cout<<"Shift top disk from tower "<<tower1<<" to tower "<<tower2<<endl;
        return;
    }
    TOH(d-1, tower1, tower3, tower2);
    cout<<"Shift top disk from tower "<<tower1<<" to tower "<<tower2<<endl;
    TOH(d-1, tower3, tower2, tower1);
}

int main()
{
    int disk;
    cout<<"Enter the number of disks: ";
    cin>>disk;

    if(disk<1) cout<<"There are no disk to shift\n";
    else cout<<"There are "<<disk<<" disks in tower 1\n";

    TOH(disk, '1', '2', '3');

    cout<<disk<<" disks in tower 1 shifted to tower2\n";
    return 0;
}
