//
// Created by 선주환 on 2/16/24.
//
#include <stack>
#include <algorithm>
#include <vector>
#include <queue>
#include<iostream>
#include <stdio.h>
#include <string>
#include <map>
#include <cmath>
#include <set>
using namespace std;
void start();
vector<long long> number;
vector<string> vct;

int main(void)
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while (1)
    {
        string str;
        cin >> str;

        if (str == "NUM")
        {
            long long num;
            cin >> num;
            vct.push_back(str);
            number.push_back(num);
        }
        else if (str == "END")
        {
            start();
            cout << "\n";
        }
        else if(str == "QUIT")
        {
            break;
        }
        else
        {
            vct.push_back(str);
        }
    }
}
void start()
{
    int num;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        long long a;
        stack<long long> stk;
        cin >> a;
        stk.push(a);
        int NUM_SIZE = 0;
        bool flag = 0;
        for (int i = 0; i < vct.size(); i++)
        {
            if (vct[i] == "NUM")
            {
                stk.push(number[NUM_SIZE]);
                NUM_SIZE += 1;
            }
            else if (vct[i] == "POP")
            {
                if (stk.empty())
                {
                    cout << "ERROR" << "\n";
                    flag = 1;
                    break;
                }
                stk.pop();
            }
            else if (vct[i] == "INV")
            {
                if (stk.empty())
                {
                    cout << "ERROR" << "\n";
                    flag = 1;
                    break;
                }
                else
                {
                    stk.top() = (stk.top() * -1);
                }
            }
            else if (vct[i] == "DUP")
            {
                if (stk.empty())
                {
                    cout << "ERROR" << "\n";

                    flag = 1;
                    break;
                }
                else
                {
                    long long N= stk.top();
                    stk.push(N);
                }
            }
            else if (vct[i] == "SWP")
            {
                if (stk.size() < 2)
                {
                    cout << "ERROR" << "\n";

                    flag = 1;
                    break;
                }
                else
                {
                    long long a = stk.top();
                    stk.pop();
                    long long b = stk.top();
                    stk.pop();
                    stk.push(a);
                    stk.push(b);
                }
            }
            else if (vct[i] == "ADD")
            {
                if (stk.size() < 2)
                {
                    cout << "ERROR" << "\n";

                    flag = 1;
                    break;
                }
                else
                {
                    long long a = stk.top();
                    stk.pop();
                    long long b = stk.top();
                    stk.pop();
                    long long add_num = a + b;
                    if (abs(add_num) > 1000000000)
                    {
                        flag = 1;
                        cout << "ERROR" << "\n";
                        break;
                    }
                    stk.push(add_num);
                }
            }
            else if (vct[i] == "SUB")
            {
                if (stk.size() < 2)
                {
                    cout << "ERROR" << "\n";
                    flag = 1;
                    break;
                }
                else
                {
                    long long a = stk.top(); //첫번째
                    stk.pop();
                    long long b = stk.top();  //두번째
                    stk.pop();
                    long long sub_num= b - a;
                    if (abs(sub_num) > 1000000000)
                    {
                        cout << "ERROR" << "\n";
                        flag = 1;
                        break;
                    }
                    stk.push(sub_num);
                }
            }
            else if (vct[i] == "MUL")
            {
                if (stk.size() < 2)
                {
                    cout << "ERROR" << "\n";

                    flag = 1;
                    break;
                }
                else
                {
                    long long a = stk.top(); //첫번째
                    stk.pop();
                    long long b = stk.top();  //두번째
                    stk.pop();
                    long long mul_num = a * b;
                    if (abs(mul_num) > 1000000000)
                    {
                        flag = 1;
                        cout << "ERROR" << "\n";
                        break;
                    }
                    stk.push(mul_num);
                }
            }
            else if (vct[i] == "DIV")
            {
                if (stk.size() < 2)
                {
                    cout << "ERROR" << "\n";

                    flag = 1;
                    break;
                }
                else
                {
                    long long a = stk.top(); //첫번째
                    stk.pop();
                    long long b = stk.top();  //두번째
                    stk.pop();
                    if (a == 0)
                    {
                        flag = 1;
                        cout << "ERROR" << "\n";
                        break;
                    }
                    long long DIV_num = b / a;
                    if (abs(DIV_num) > 1000000000)
                    {
                        flag = 1;
                        cout << "ERROR" << "\n";
                        break;
                    }
                    stk.push(DIV_num);
                }
            }
            else if (vct[i] == "MOD")
            {
                if (stk.size() < 2)
                {
                    cout << "ERROR" << "\n";
                    flag = 1;
                    break;

                }
                else
                {
                    long long a = stk.top();
                    stk.pop();
                    long long b = stk.top();
                    stk.pop();
                    if (a == 0)
                    {
                        cout << "ERROR" << "\n";
                        flag = 1;
                        break;
                    }
                    long long mod = abs(b % a);
                    if (b < 0)
                    {
                        mod = mod * -1;
                    }

                    stk.push(mod);
                }
            }
        }
        if (flag == 1)
        {
            continue;
        }
        else if (stk.size() != 1)
        {
            cout << "ERROR" << "\n";
        }
        else
        {
            cout << stk.top() << "\n";
        }
    }
    number.clear();
    vct.clear();
}