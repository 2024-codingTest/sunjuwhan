#include <iostream>
#include <queue>
#include <vector>
#include <istream>
#include <string>
#include <map>
using namespace std;
map<string, double> mp;
int count_tree = 0;
void input()
{
	string str;
	
	while (getline(cin, str))
	{
		if (mp.find(str) == mp.end())
		{
			mp.insert({ str, 1.0});
		}
		else
		{
			map<string, double> ::iterator itr = mp.find(str);
			itr->second += 1.0;
		}
		count_tree += 1;
	}
}
void cal()
{
	cout << fixed;
	cout.precision(4);
	for (auto temp : mp)
	{
		double avg = (temp.second / (double)count_tree) * 100.0;
		cout << temp.first << " " << avg << endl;
	}
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	input();
	cal();
}
