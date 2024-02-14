//
// Created by 선주환 on 2/14/24.
//

#include <iostream>
#include <vector>

using namespace std;

int dp[1000001][11];
string str;
int k;

void input()
{
   cin>>str;
   cin>>k;

   for(int i=0;i<=1000000;i++)
   {
       for(int t=0;t<=10;t++)
       {
           dp[i][t]=-1;
       }
   }

}

int dfs(int depth,string number)
{

    if(depth==k)
    {
        return stoi(number);
    }

    if(dp[stoi(number)][depth]!=-1)
    {
        return dp[stoi(number)][depth];
    }

    int now_number=stoi(number);

    for(int i=0;i<number.size();i++)
    {

        for(int t=i+1;t<number.size();t++)
        {

            if(i==0&&number[t]=='0')
            {
                continue;
            }

            char temp=number[i];
            number[i]=number[t];
            number[t]=temp;
            dp[now_number][depth]=max(dp[now_number][depth],dfs(depth+1,number));
            temp=number[i];
            number[i]=number[t];
            number[t]=temp;
        }
    }

    return dp[now_number][depth];

}
void solution()
{

    input();
    cout<<dfs(0,str)<<endl;

}
int main(void)
{

   ios::sync_with_stdio(false) ;
   cin.tie(NULL);
   cout.tie(NULL);
   solution();

}