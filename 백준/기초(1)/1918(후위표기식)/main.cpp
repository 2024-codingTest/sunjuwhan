//
// Created by antl on 2024-02-28.
//
#include <iostream>
#include <stack>
#include <queue>
using namespace std;
string str;
void input()
{
    cin>>str;
    stack<char> alpha;
    stack<char> giho;
    queue<char> answer;

    for(int i=0;i<str.size();i++)
    {
        if(str[i]>='A'&&str[i]<='Z')
        {
            answer.push(str[i]);
        }
        else if(str[i]==')')
        {
            while(giho.top()!='(')
            {
                answer.push(giho.top());
                giho.pop();
            }
           giho.pop();
        }
        else if(str[i]=='(')
        {
            giho.push(str[i]);
        }
        else if(str[i]=='*'||str[i]=='/')
        {
            while(!giho.empty()&&(giho.top()=='*'||giho.top()=='/'))
            {
                   answer.push(giho.top());
                   giho.pop();
            }
            giho.push(str[i]);
        }
        else
        {
            while(!giho.empty()&&giho.top()!='(')
            {
              answer.push(giho.top()) ;
              giho.pop();
            }
            giho.push(str[i]);
        }
    }
    while(!giho.empty())
    {
        answer.push(giho.top());
        giho.pop();
    }
    while(!answer.empty())
    {
        cout<<answer.front();
        answer.pop();
    }
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    input();
}