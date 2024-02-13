//
// Created by 선주환 on 2/13/24.
// 파일설명 : 보드게임의 말을 보드 밑에 써져있는 숫자만큼 움직일수있을때 최대로 움직일수있는 거리
// Idea : dfs 와 dp를 동시에 활용한다.
//
//

#include <iostream>
#include <vector>

using namespace  std;
int dp[50][50];     //dfs시 방문 노드 처리를 위한 배열
char arr[50][50];   //게임판
static int chk[50][50];   //방문 여부 확인
int N,M;
int px[4]={0,0,1,-1};
int py[4]={1,-1,0,0};
void input()
{
    cin>>N>>M;
    for(int i=0;i<N;i++)
    {
        for(int t=0;t<M;t++)
        {
            cin>>arr[i][t];
            dp[i][t]=-1;
        }
    }
}
int dfs(int now_y,int now_x)
{
    if(chk[now_y][now_x]==1)
    {
        cout<<"-1";
        exit(0);
    }
    if(dp[now_y][now_x]!=-1)
    {
        return dp[now_y][now_x];
    }
    chk[now_y][now_x]=1;
    dp[now_y][now_x]=0;
    for(int i=0;i<4;i++)
    {
        int next_y=now_y+((arr[now_y][now_x]-'0') *py[i]);
        int next_x=now_x+((arr[now_y][now_x]-'0') *px[i]);
        if(next_y>=0&&next_y<N&&next_x>=0&&next_x<M)
        {
            if(arr[next_y][next_x]!='H')
            {

                dp[now_y][now_x]= max(dp[now_y][now_x],dfs(next_y,next_x)+1);   //dp와 dfs를 이용
            }
        }
    }
    chk[now_y][now_x]=0;
    return dp[now_y][now_x];
}
void solution()
{
    input();
    int answer= dfs(0,0);
    cout<<answer+1;
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solution();
    return 0;
}