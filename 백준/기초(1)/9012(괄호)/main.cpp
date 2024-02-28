//
// Created by antl on 2024-02-28.
//
#include <iostream>
#include <queue>
#include <vector>
#include <istream>
#include <string>
#include <map>
#include <stack>
using namespace std;


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        stack<char> stk;
        bool flag = 0;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == '(')
            {
                stk.push(str[i]);
            }
            else
            {
                if (stk.empty())
                {
                    flag = 1;
                    break;
                }
                else if (stk.top() == ')')
                {
                    cout << "NO" << "\n";
                    break;
                }
                else
                {
                    stk.pop();
                }
            }
        }
        if (!stk.empty()||flag==1)
        {
            cout << "NO" << "\n";
        }
        else
        {
            cout << "YES"<<"\n";
        }
    }
}