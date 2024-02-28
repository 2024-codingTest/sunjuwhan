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
    cin.ignore();
    string str;
    for (int i = 0; i <N; i++)
    {
        getline(cin, str);
        stack<char> stk;
        for (int t = 0; t < str.size(); t++)
        {
            if (str[t] != ' ')
            {
                stk.push(str[t]);
            }
            else
            {
                while (!stk.empty())
                {
                    cout << stk.top();
                    stk.pop();
                }
                cout << " ";
            }
        }
        if (!stk.empty())
        {
            while (!stk.empty())
            {
                cout << stk.top();
                stk.pop();
            }
        }

        cout << "\n";
    }
}
