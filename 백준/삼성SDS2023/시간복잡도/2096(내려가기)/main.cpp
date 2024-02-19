#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
static int dp[3];
static int min_dp[3];
int N;
void solution()
{
   cin>>N;
   for(int i=0;i<3;i++)
   {
       int num;
       cin>>num;
       dp[i]=num;
       min_dp[i]=num;
   }
   for(int i=1;i<N;i++)
   {
       int temp[3];
       for(int t=0;t<3;t++)
       {
          cin>>temp[t];
       }
        int first_pos=max(dp[0]+temp[0],dp[1]+temp[0]);
       int third_pos=max(dp[2]+temp[2],dp[1]+temp[2]);
       int second_pos=0;
       for(int t=0;t<3;t++)
       {
           if(dp[t]>second_pos)
           {
               second_pos=dp[t];
           }
       }
       dp[0]=first_pos;
       dp[1]=second_pos+temp[1];
       dp[2]=third_pos;
        int first_min_pos=min(min_dp[0]+temp[0],min_dp[1]+temp[0]) ;
        int this_min_pos=min(min_dp[2]+temp[2],min_dp[1]+temp[2]);
        int second_min_pos=100000000;
        for(int t=0;t<3;t++)
        {
            if(min_dp[t]<second_min_pos)
            {
                second_min_pos=min_dp[t];
            }
        }
        min_dp[0]=first_min_pos;
        min_dp[1]=second_min_pos+temp[1];
        min_dp[2]=this_min_pos;
   }
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solution();
    int min_answer=10000000;
    int max_answer=-1;
    for(int i=0;i<3;i++)
    {
       if(dp[i]>max_answer)
       {
           max_answer=dp[i];
       }
       if(min_dp[i]<min_answer)
       {
           min_answer=min_dp[i];
       }
    }
    cout<<max_answer<<" "<<min_answer;
}