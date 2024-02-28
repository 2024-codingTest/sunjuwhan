//
// Created by antl on 2024-02-28.
//
#include <queue>
#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
    int N,K;
    cin>>N>>K;
    queue<int> q;
    for(int i=1;i<=N;i++)
    {
        q.push(i);
    }
    int count=1;
    vector<int> result;
    while(!q.empty())
    {
       if(count==K)
       {
           result.push_back(q.front());
           q.pop();
           count=1;
       }
       else
       {
           int number=q.front();
           q.pop();
           q.push(number);
           count+=1;
       }
    }
    cout<<"<";
    for(int i=0;i<result.size()-1;i++)
    {
        cout<<result[i]<<", ";
    }
    cout<<result[result.size()-1]<<">";
}