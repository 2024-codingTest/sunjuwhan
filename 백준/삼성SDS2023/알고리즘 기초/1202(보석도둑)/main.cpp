#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
int N, K;
struct comp
{
	bool operator()(pair<int, int> a, pair<int, int> b)
	{
		if (a.first == b.first)
		{
			return a.second < b.second;
		}
		else
		{
			return a.first > b.first;
		}
	}
};
priority_queue<pair<int, int>,vector<pair<int,int>> ,comp> pq;
vector<int> vct;
void input()
{
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		int weight, cost;
		cin >> weight >> cost;
		pq.push(make_pair(weight, cost));
	}
	for (int i = 0; i < K; i++)
	{
		int num;
		cin >> num;
		vct.push_back(num);
	}
	sort(vct.begin(), vct.end());
}
void solve()
{
	priority_queue<int> cost_q;
 //가방이 가장 작은 순으로 들어오니까
	int i = 0;
	long long result = 0;
	for (int i = 0; i < vct.size(); i++)
	{
		while (!pq.empty()&&vct[i] >= pq.top().first )
		{
			cost_q.push(pq.top().second);
			pq.pop();
		}
		if (!cost_q.empty())
		{
			result += cost_q.top();
			cost_q.pop();

		}
	}
	cout << result;
}
int main(void)
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	input();
	solve();
}
