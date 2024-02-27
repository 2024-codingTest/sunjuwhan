#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <stdio.h>
#include <stack>
using namespace std;
class Node
{
public:
	Node *left;
	Node *right;
	int number;
	Node()
	{
		left = NULL;
		right = NULL;
		number = -1;
	}
	void insert_number(int input_number)
	{
		if (this->number == -1)
		{
			this->number = input_number;
		}
		else
		{
			if (this->number < input_number) //input_number가 더크면 오른쪽 가야지
			{
				if (right == NULL)
				{
					right = new Node();
				}
				right->insert_number(input_number);
			}
			else
			{
				if (left == NULL)
				{
					left = new Node();
				}
				left->insert_number(input_number);
			}
		}
	}
	void find_number()
	{
		if (this->left != NULL)
		{
			this->left->find_number();
		}
		if (this->right != NULL)
		{
			this->right->find_number();
		}
		if (this->number != -1)
		{

		cout << this->number<<"\n";
		}
	}
};
void input()
{
	int number = 0;
	cin >> number;
	Node root;
	root.insert_number(number);
	while (cin>>number)
	{
		root.insert_number(number);
	}
	root.find_number();
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	input();
}
