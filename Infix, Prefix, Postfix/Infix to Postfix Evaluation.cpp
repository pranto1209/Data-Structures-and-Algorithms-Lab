#include<bits/stdc++.h>
using namespace std;

bool IsInfixOperator(char ch)
{
	if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^') return true;
	return false;
}

bool IsInfixOperand(char ch)
{
	if(ch>='0' && ch<='9') return true;
	if(ch>='a' && ch<='z') return true;
	if(ch>='A' && ch<='Z') return true;
	return false;
}

int Precidence(char c)
{
    if(c=='-' || c=='+') return 1;
    else if(c=='*'||c=='/') return 2;
    else if(c=='^') return 3;
    else return -1;
}

string InfixToPostfix(string expression)
{
	stack<char>s;
	string postfix;
	for(int i=0; i<expression.size(); i++){
		if(expression[i]==' ' || expression[i]==',') continue;
		else if(IsInfixOperator(expression[i])){
            postfix+=" ";
            if(s.empty() || Precidence(expression[i]) > Precidence(s.top())) s.push(expression[i]);
            else{
                while(!s.empty() && s.top()!='(' && Precidence(expression[i]) <= Precidence(s.top())){
                    postfix+=s.top();
                    s.pop();
                }
                s.push(expression[i]);
            }
		}
		else if(IsInfixOperand(expression[i])){
			postfix+=expression[i];
		}
		else if(expression[i]=='('){
			s.push(expression[i]);
		}
		else if(expression[i]==')'){
			while(!s.empty() && s.top()!= '('){
				postfix+=s.top();
				s.pop();
			}
			s.pop();
		}
	}
	while(!s.empty()){
		postfix+=s.top();
		s.pop();
	}

	return postfix;
}


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
	cout<<"Enter Infix Expression: ";
	getline(cin, expression);
    string postfix=InfixToPostfix(expression);
    cout<<"Postfix Expression: "<<postfix<<endl;
    cout<<"Answer: "<<EvaluatePostfix(postfix);
}
