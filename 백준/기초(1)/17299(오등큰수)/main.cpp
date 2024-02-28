//
// Created by antl on 2024-02-28.
//
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

static int arr[1000001];
vector<int> vct;
int N;
stack<int> answer;
void input()
{
    cin>>N;
    for(int i=0;i<N;i++)
    {
        int number;
        cin>>number;
        arr[number]+=1;
        vct.push_back(number);
    }
}
void solution()
{
    stack<pair<int,int> > q;
    q.push(make_pair(arr[vct[N-1]],vct[N-1])) ;  //arr은 갯수 vct[N-1]은 숫자
    answer.push(-1);
    for(int i=N-2;i>=0;i--)
    {
        int now_number=vct[i];
        int now_count=arr[now_number];
        while(!q.empty()&&now_count>=q.top().first)
        {
            q.pop();
        }
        if(q.empty())
        {
            q.push(make_pair(now_count,now_number));
            answer.push(-1);
        }
        else
        {
            answer.push(q.top().second);
            q.push(make_pair(now_count,now_number));
        }
    }
    while(!answer.empty())
    {
        cout<<answer.top()<<" ";
        answer.pop();
    }
}
int main(void)
{
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   input();
   solution();
}