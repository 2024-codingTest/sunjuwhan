//
// Created by antl on 2024-02-28.
//
#include <stack>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num;
    cin>>num;
    vector<int> vct;
    priority_queue<int,vector<int>,greater<int> > pq;
    vct.resize(num,0);
    for(int i=0;i<num;i++)
    {
       cin>>vct[i] ;
    }
    stack<int> answer;
    pq.push(vct[num-1]);
    answer.push(-1);

    for(int i=num-2;i>=0;i--)
    {
        int now_number=vct[i];
        while(!pq.empty()&&now_number>=pq.top()) //현재 넘버가 pq.top보다 크면 멈춰
        {
           pq.pop();
        }
        if(pq.empty())
        {
            answer.push(-1);
            pq.push(now_number);
        }
        else
        {
            answer.push(pq.top());
            pq.push(now_number);
        }

    }
    while(!answer.empty())
    {
        cout<<answer.top()<<" ";
        answer.pop();
    }

}