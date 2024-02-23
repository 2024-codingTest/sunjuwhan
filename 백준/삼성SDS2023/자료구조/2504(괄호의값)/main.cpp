#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <stack>
using namespace std;

string str;
//   ( -> -1    ) -> -2   [ -> -3  ] -> -4
void input()
{
	cin >> str;
}
void solution()
{
	stack<int> stk;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '(')
		{
			stk.push(-1);
		}
		else if (str[i] == '[')
		{
			stk.push(-3);
		}
		else if (str[i] == ')')
		{
			if (stk.empty())
			{
				cout << "0";
				exit(0);
			}
			if (stk.top() == -1)   // (일때
			{
				stk.pop();
				if (stk.empty())  //stk 비어있으면 숫자 2넣고 
				{
					stk.push(2);
				}
				else if (stk.top() > 0)
				{
					int number = stk.top();
					stk.pop();
					stk.push(number + 2);
				}
				else  // 즉 앞에 다른 기호가 남아있다는 뜻 
				{
					stk.push(2);
				}
			}
			else if (stk.top() > 0)//즉 현재 숫자를 감싸고있음 (3) 인상황 ((3))
			{
				int number = stk.top();
				stk.pop();
				if (stk.empty() || stk.top() != -1)
				{
					cout << "0";
					exit(0);
					
				}
				else if (stk.top() == -1)
				{
					stk.pop();
					if (stk.empty())
					{
						stk.push(number * 2);
					}
					else if (stk.top() > 0)
					{
						int second_number = stk.top();
						stk.pop();
						stk.push(second_number + number*2);
					}
					else  //기호가 앞에있다면
					{
						stk.push(number * 2);
					}
				}
			}
		}
	
		else if (str[i] == ']')
		{
			if (stk.empty())
			{
				cout << "0";
				exit(0);
			}
			if (stk.top() == -3)   // (일때
			{
				stk.pop();
				if (stk.empty())  //stk 비어있으면 숫자 2넣고 
				{
					stk.push(3);
				}
				else if (stk.top() > 0)
				{
					int number = stk.top();
					stk.pop();
					stk.push(number + 3);
				}
				else  // 즉 앞에 다른 기호가 남아있다는 뜻 
				{
					stk.push(3);
				}
			}
			else if (stk.top() > 0)//즉 현재 숫자를 감싸고있음 (3) 인상황 ((3))
			{
				int number = stk.top();
				stk.pop();
				if (stk.empty() || stk.top() != -3)
				{
					cout << "0";
					exit(0);
					
				}
				else if (stk.top() == -3)
				{
					stk.pop();
					if (stk.empty())
					{
						stk.push(number * 3);
					}
					else if (stk.top() > 0)
					{
						int second_number = stk.top();
						stk.pop();
						stk.push(second_number + number*3);
					}
					else  //기호가 앞에있다면
					{
						stk.push(number * 3);
					}
				}
			}
		}
	}
	if (stk.size() != 1 || stk.top() < 0)
	{
		cout << "0";
		exit(0);
	}
	cout << stk.top();
	//  ( () (()) ) ()
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	input();
	solution();
}
