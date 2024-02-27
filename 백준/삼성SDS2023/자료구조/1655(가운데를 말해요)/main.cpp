#include <iostream>
#include <queue>

using namespace std;
struct cmp
{
	bool operator() (int a, int b)
	{
		return a > b;
	}
};
void solution()
{
	priority_queue<int, vector<int>, cmp>right; //작은게 맨위로 
	priority_queue<int> left; //큰게 맨위로

	int N;
	cin >> N;
	if (N == 1)
	{
		int number;
		cin >> number;
		cout << number;
		exit(0);
	}
	else
	{
		int a, b;
		cin >> a;
		cout << a << "\n";
		cin >> b;
		if (a > b)
		{
			cout << b << "\n";
			left.push(b);
			right.push(a);
		}
		else
		{
			cout << a << "\n";
			left.push(a);
			right.push(b);
		}
		for (int i = 3; i <= N; i++)
		{
			int number;
			cin >> number;
			if (left.top() < number && number < right.top())
			{
				if (left.size() > right.size())
				{
					right.push(number);
				}
				else
				{
					left.push(number);
				}
			}
			else if (left.top() > number)
			{
				left.push(number);
			}
			else
			{
				right.push(number);
			}
			if (left.size() - right.size() == 2)
			{
				int temp= left.top();
				left.pop();
				right.push(temp);
			}
			else if (right.size() - left.size() == 2)
			{
				int temp = right.top();
				right.pop();
				left.push(temp);
			}

			if (i % 2 == 0)
			{
				cout << left.top() << "\n";
			}
			else
			{
				if (left.size() > right.size())
				{
					cout << left.top() << "\n";
				}
				else
				{
					cout << right.top() << "\n";
				}
			}
		}
	
	}
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solution();
}
