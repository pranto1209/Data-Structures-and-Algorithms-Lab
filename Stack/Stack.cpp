#include<iostream>
using namespace std;

class Stack
{
public:
    int tp;
    int arr[100];

    Stack()
    {
        tp=-1;
    }

    void push(int num)
    {
        tp++;
        arr[tp]=num;
    }

    void pop()
    {
        if(tp>=0) tp--;
    }

    int top()
    {
        return arr[tp];
    }

    int size()
    {
        return tp+1;
    }

    bool empty()
	{
		if(tp==-1) return true;
		return false;
	}
};

void show(Stack stk)
{
    while(!stk.empty())
    {
        cout<<stk.top()<<" ";
        stk.pop();
    }
    cout<<endl;
}

int main()
{
    int n, i, x;
    Stack s;
    cin>>n;
    for(i=0; i<n; i++){
        cin>>x;
        s.push(x);//push_front
    }
    show(s);

    cout<<"Size: "<<s.size()<<endl;
    cout<<s.top()<<endl;

    s.pop();//pop_front
    show(s);

    return 0;
}

