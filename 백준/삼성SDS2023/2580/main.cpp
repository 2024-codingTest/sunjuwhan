//
// Created by 선주환 on 2/14/24.
//


#include <iostream>
#include <vector>
using namespace std;
int arr[9][9];
vector<pair<int,int> > blank;
bool end_flag=false;
void input()
{
    for(int i=0;i<9;i++)
    {
        for(int t=0;t<9;t++)
        {
            cin>>arr[i][t];
            if(arr[i][t]==0)
            {
                blank.push_back(make_pair(i,t));
            }
        }
    }
}
bool chk_sudokoo(pair<int,int> pos,int number)
{
    for(int i=0;i<9;i++)
    {
        if(arr[pos.first][i]==number&&i!=pos.second)
        {
            return false;
        }
    }
    for(int i=0;i<9;i++)
    {
        if(arr[i][pos.second]==number&&i!=pos.first)
        {
            return false;
        }
    }
    int start_y=(pos.first/3) *3;
    int end_y=start_y+3;
    int start_x=(pos.second/3)*3;
    int end_x=start_x+3;
    for(int i=start_y;i<end_y;i++)
    {
        for(int t=start_x;t<end_x;t++)
        {
            if(arr[i][t]==number&&i!=pos.first&&t!=pos.second)
            {
                return false;
            }
        }
    }
    return true;
}
void dfs(int count)
{
    if(count==blank.size())
    {
        for(int i=0;i<9;i++)
        {
            for(int t=0;t<9;t++)
            {
                cout<<arr[i][t]<<" ";
            }
            cout<<"\n";
        }
        exit(0);

    }
    for(int i=1;i<=9;i++)
    {
       arr[blank[count].first][blank[count].second]=i;
       if(chk_sudokoo(blank[count],i))
       {
           dfs(count+1);
       }
       arr[blank[count].first][blank[count].second]=0;
    }
}
void solution()
{
    input();
    dfs(0);
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solution();
}