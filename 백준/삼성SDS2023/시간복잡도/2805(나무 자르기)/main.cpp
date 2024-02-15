//
// Created by 선주환 on 2/15/24.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N,K;
int answer=0;
vector<int> vct;
void input()
{
   cin>>N>>K;
    vct.resize(N,0);
    for(int i=0;i<N;i++)
    {
        cin>>vct[i];
    }
    sort(vct.begin(),vct.end());
}
void binary_search()
{
    long long left=0;
    long long right=vct[vct.size()-1];
    while(left<=right)
    {
        long long mid=(left+right)/2;
       long long temp=0;
       for(int i=0;i<vct.size();i++)
       {
            if(vct[i]-mid>0)
            {
                temp+=(vct[i]-mid);
            }
       }
       if(temp>=K)
       {
          answer=mid;
          left=mid+1;
       }
       else
       {
           right=mid-1;
       }
    }
}
void solution()
{
    input();
    binary_search();
    cout<<answer;
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solution();
}
