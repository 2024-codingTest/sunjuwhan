//
// Created by antl on 2024-02-28.
//
#include <iostream>
#include <stack>
using namespace std;
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string str;
    cin>>str;
    stack<char> stk;
    char before;
    int answer=0;
    for(int i=0;i<str.size();i++)
    {
        if(str[i]=='(')
        {
            before='(';
            stk.push('(');
        }
        else if(str[i]==')')
        {
            if(stk.top()=='(') //razer를 쏴야하는데
            {
               stk.pop();
               if(before=='(')
               {
                   answer+=stk.size();
               }
               else
               {
                   answer+=1;
               }
               before=')';
            }
        }
    }
    cout<<answer;
}