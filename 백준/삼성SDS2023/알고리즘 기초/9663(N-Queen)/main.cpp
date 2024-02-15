//
// Created by 선주환 on 2/14/24.
//
#include <iostream>

using namespace std;
int answer=0;
int N;
int px[4]={-1,1,1,-1};
int py[4]={-1,1,-1,1};
static int arr[15][15];
bool chk_chess(pair<int,int> pos)
{
    for(int i=0;i<N;i++)
    {
        if(arr[i][pos.second]==1&&i!=pos.first)
        {
           return false;
        }
    }

    for(int i=0;i<4;i++)
    {
        int next_y=pos.first+py[i];
        int next_x=pos.second+px[i];
        while(1)
        {
            if(0<=next_y&&next_y<N&&0<=next_x&&next_x<N)
            {
                if(arr[next_y][next_x]==1)
                {
                    return false;
                }
                else
                {
                    next_y+=py[i];
                    next_x+=px[i];
                }
            }
            else
            {
                break;
            }
        }
    }
    return true;
}
void dfs(int count)
{

    if(count==N)
    {
        answer+=1;
        return ;
    }
    for(int i=0;i<N;i++)
    {
        arr[count][i]=1;
        if(chk_chess(make_pair(count,i)))
        {

            dfs(count+1);
        }
        arr[count][i]=0;
    }
    return ;
}
void solution()
{
    cin>>N;
    if(N%2==0)
    {
        for(int i=0;i<N/2;i++)
        {
            arr[0][i]=1;
            dfs(1);
            arr[0][i]=0;
        }
        cout<<answer*2;
    }
    else
    {
        for(int i=0;i<N/2;i++)
        {
            arr[0][i]=1;
            dfs(1);
            arr[0][i]=0;
        }
        int temp=answer*2;
        answer=0;
        arr[0][N/2]=1;
        dfs(1);
        cout<<temp+answer;
    }
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solution();
}