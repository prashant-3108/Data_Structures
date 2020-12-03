#include <iostream>
#include <cstring>
#include <stack>

using namespace std;
 
int isOperand(char x)
{
    if(!isalpha(x) && !isdigit(x))
    {
        return 0;
    }
    return 1;
}
 
int outPrecedence(char x){
    if (x == '+' || x == '-'){
        return 1;
    } else if (x == '*' || x == '/'){
        return 3;
    } else if (x == '^'){
        return 6;
    } else if (x == '('){
        return 7;
    } else if (x == ')'){
        return 0;
    }
    return -1;
}
 
int inPrecedence(char x){
    if (x == '+' || x == '-'){
        return 2;
    } else if (x == '*' || x == '/'){
        return 4;
    } else if (x == '^'){
        return 5;
    } else if (x == '('){
        return 0;
    }
    return -1;
}

void PrintStack(stack<int> s)
{
    if (s.empty()) 
        return;
     
 
    int x = s.top();

    s.pop();

    PrintStack(s);
    cout << x << " ";
    s.push(x);
}
 
char* convert(char* infix)
{
    char* postfix = new char [strlen(infix) + 1];
 
    stack<char> stk;
 
    int i = 0;
    int j = 0;
 
    while (infix[i] != '\0')
    {
        if (isOperand(infix[i]))
        {
            postfix[j++] = infix[i++];
        } 
        else 
        {
            if (stk.empty() || outPrecedence(infix[i]) > inPrecedence(stk.top()))
            {
                stk.push(infix[i++]);
            } 
            else if (outPrecedence(infix[i]) == inPrecedence(stk.top()))
            {
                stk.pop();
            }
            else if(outPrecedence(infix[i]) < inPrecedence(stk.top()))
            {
                postfix[j++] = stk.top();
                stk.pop();
            }
        }
    }
    while (! stk.empty() && stk.top() != ')')
    {
        postfix[j++] = stk.top();
        stk.pop();
    }
 
    postfix[j] = '\0';
 
    return postfix;
 
}

int evaluate(char *s)
{
    stack<int> st;
    int i = 0;
    while(s[i]!='\0')
    {
        if(st.empty() || isdigit(s[i]))
        {
            st.push(s[i]-'0');
        }
        else
        {
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();
            if(s[i]=='/')
            {
                st.push(a/b);
            }
            else if(s[i]=='*')
            {
                st.push(a*b);
            }
            else if(s[i]=='+')
            {
                st.push(a+b);
            }
            else if(s[i]=='-')
            {
                st.push(a-b);
            }
        }
        i++;
    }
    return st.top();
    return 0;
}
 
 
int main() 
{
 
    char infix[] = "3*5+6/2-4";
    char *s = convert(infix);
    // cout<<s<<endl;
    cout << evaluate(s) << endl;
 
}
