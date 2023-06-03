#include<iostream>
using namespace std;

class Queue
{
public:
    int frnt, rear;
    int arr[100];

    Queue(){
        frnt=-1;
        rear=-1;
    }

    void push(int num)
    {
        rear++;
        arr[rear]=num;
    }

    void pop()
    {
        if(rear>frnt) frnt++;
    }

    int front()
    {
        return arr[frnt+1];
    }

    bool empty()
    {
        return frnt==rear;
    }
};

void show(Queue que)
{
    while(!que.empty())
    {
        cout<<que.front()<<" ";
        que.pop();
    }
    cout<<endl;
}

int main()
{
    int n, i, x;
    Queue q;
    cin>>n;
    for(i=0; i<n; i++){
        cin>>x;
        q.push(x);//push_back
    }
    show(q);

    cout<<q.front()<<endl;

    q.pop();//pop_front
    show(q);

    return 0;
}
