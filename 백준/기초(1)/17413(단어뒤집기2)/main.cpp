//
// Created by antl on 2024-02-28.
//
#include <queue>
#include <stack>
#include <iostream>
using namespace std;
int main(void)
{
    string str;
    getline(cin,str);
    queue<char> q;
    stack<char> stk;
    bool flag= false;
    for(int i=0;i<str.size();i++)
    {
        if(str[i]=='<')
        {
            while(!stk.empty())
            {
                cout<<stk.top();
                stk.pop();
            }
            q.push(str[i]);
            flag= true;
        }
        else if(str[i]==' ')
        {
            if(flag==0)
            {
                while(!stk.empty())
                {
                    cout<<stk.top();
                    stk.pop();
                }
                cout<<" ";
            }
            else
            {
                q.push(' ');
            }

        }
        else if(str[i]=='>')
        {
            q.push('>');
            while(!q.empty())
            {
                cout<<q.front();
                q.pop();
            }
            flag=0;
        }
        else if(!flag)
        {
            stk.push(str[i]);
        }
        else if(flag)
        {
            q.push(str[i]);
        }
    }
    if(!stk.empty())
    {
        while(!stk.empty())
        {
            cout<<stk.top();
            stk.pop();
        }
    }
}