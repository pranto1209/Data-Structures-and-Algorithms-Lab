#include<bits/stdc++.h>
using namespace std;

int PerformOperation(char operation, int operand1, int operand2)
{
	if(operation=='+') return operand1 +operand2;
	else if(operation=='-') return operand1 - operand2;
	else if(operation=='*') return operand1 * operand2;
	else if(operation=='/') return operand1 / operand2;
	else if(operation=='^') return pow(operand1, operand2);
	return -1;
}

bool IsOperator(char ch)
{
	if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^') return true;
	return false;
}

bool IsNumericDigit(char ch)
{
	if(ch>='0' && ch<='9') return true;
	return false;
}

int EvaluatePostfix(string expression)
{
	stack<int>s;
	for(int i=0; i<expression.size(); i++){
		if(expression[i]==' ' || expression[i]==',') continue;
		else if(IsOperator(expression[i])){
			int operand2=s.top();s.pop();
			int operand1=s.top();s.pop();
			int result=PerformOperation(expression[i], operand1, operand2);
			s.push(result);
		}
		else if(IsNumericDigit(expression[i])){
			int operand=0;
			while(i<expression.size() && IsNumericDigit(expression[i])){
				operand=(operand*10)+(expression[i]-'0');
				i++;
			}
			i--;
			s.push(operand);
		}
	}
	return s.top();
}

int main()
{
	string expression;
	cout<<"Enter Postfix Expression: ";
	getline(cin, expression);
	int ans=EvaluatePostfix(expression);
	cout<<"Answer: "<<ans;

	return 0;
}
