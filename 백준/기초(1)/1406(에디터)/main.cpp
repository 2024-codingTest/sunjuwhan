//
// Created by antl on 2024-02-28.
//
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void solution()
{
    stack<char> left;
    stack<char> right;
    string str;
    cin>>str;
    int num;
    cin>>num;
    for(int i=0;i<str.size();i++)
    {
        left.push(str[i]);
    }
    for(int i=0;i<num;i++)
    {
        char first;
        cin>>first;
        if(first=='P')
        {
            char second;
            cin>>second;
            left.push(second);
        }
        else if(first=='L')
        {
            if(!left.empty())
            {
                right.push(left.top()) ;
                left.pop();
            }
        }
        else if(first=='D')
        {
            if(!right.empty())
            {
                left.push(right.top());
                right.pop();
            }
        }
        else if(first=='B')
        {
            if(!left.empty())
            {
                left.pop();
            }
        }
    }
    vector<char> result;
    while(!right.empty())
    {
        left.push(right.top());
        right.pop();
    }
    while(!left.empty())
    {
       result.push_back(left.top());
       left.pop();
    }
    for(int i=result.size()-1;i>=0;i--)
    {
        cout<<result[i];
    }
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solution();
}