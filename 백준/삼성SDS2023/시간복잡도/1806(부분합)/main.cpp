//
// Created by 선주환 on 2/19/24.
//
#include <iostream>
#include <vector>

using namespace std;

int N,S;
vector<int> vct;
int answer=1000001;
void input()
{
    cin>>N>>S;
    vct.resize(N+1,0);
    for(int i=0;i<N;i++)
    {
        cin>>vct[i];
    }
}
void tow_pointer()
{
   int left=0;
   int right=0;
   long long sum=vct[left];
   while(right<vct.size())
   {
        if(sum>=S)
        {
            if((right-left)<answer)
            {
                answer=(right-left);
            }
            sum-=vct[left] ;
            left+=1;
        }
        else
        {
            right+=1;
            sum+=vct[right];
        }
   }
}
void solution()
{
    input();
    tow_pointer();
    if(answer==1000001)
    {
        cout<<"0";
        return ;
    }
    cout<<answer+1;
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solution();
}