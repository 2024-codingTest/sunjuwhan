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
    int count = 0;
    cin >> count;
    stack<int> stk;
    queue<char> result;
    int i = 1;
    while (i <= count)
    {
        int number;
        cin >> number;
        while (i <= number)
        {
            stk.push(i);
            result.push('+');
            i += 1;
        }
        if (!stk.empty()&&stk.top() == number)
        {
            stk.pop();
            result.push('-');
        }
    }
    while (!stk.empty())
    {
        int numbewr;
        cin >> numbewr;
        if (stk.top() == numbewr)
        {
            stk.pop();
            result.push('-');
        }
        else
        {
            break;
        }
    }
    if (stk.empty())
    {
        while (!result.empty())
        {
            cout << result.front() << "\n";
            result.pop();
        }
    }
    else
    {
        cout << "NO";
    }
}