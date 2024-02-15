//
// Created by 선주환 on 2/15/24.
//
#include <iostream>
#include <vector>

using namespace std;
static int arr[50][50];
vector<pair<int,int> > house;
vector<pair<int,int> > chicken;
vector<pair<int,int> > select_chicken;
int answer=1000000;
int N,K;
void input()
{
    cin>>N>>K;
    for(int i=0;i<N;i++)
    {
        for(int t=0;t<N;t++)
        {
           cin>>arr[i][t];
           if(arr[i][t]==2)
           {
               chicken.push_back(make_pair(i,t));
           }
           else if(arr[i][t]==1)
           {
               house.push_back(make_pair(i,t));
           }
        }
    }
}
void dfs(int count)
{
    if(select_chicken.size()==K)
    {
        int total_dist=0;
        int min_dist=3000;
        for(int i=0;i<house.size();i++)
        {
            min_dist=3000;
            for(int t=0;t<select_chicken.size();t++)
            {
               int x_dist=abs(house[i].second-select_chicken[t].second);
               int y_dist=abs(house[i].first-select_chicken[t].first);
               if(min_dist>(x_dist+y_dist))
               {
                   min_dist=x_dist+y_dist;
               }
            }
            total_dist+=min_dist;
        }
        if(total_dist<answer)
        {
            answer=total_dist;
        }
        return;
    }
    for(int i=count;i<chicken.size();i++)
    {
        select_chicken.push_back(chicken[i]);
        dfs(i+1);
        select_chicken.pop_back();
    }
    return;
}
void solution()
{
    input();
    dfs(0);
    cout<<answer;
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solution();
}