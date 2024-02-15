//
// Created by 선주환 on 2/15/24.
//

#include <iostream>
#include <vector>
using namespace std;

int N,K;
int answer=0;
vector<int> vct;

void input()
{

   cin>>N>>K;
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
    int sum=vct[0];
    while(right<N)
    {
        if(sum<K)
        {
            right+=1;
            sum+=vct[right];

        }
        else if(sum>K)
        {
            sum-=vct[left] ;
            left+=1;
        }
        else if(sum==K)
        {
            sum-=vct[left];
            left+=1;
            right+=1;
            sum+=vct[right];
           answer+=1;

        }
    }
}
void solution()
{
    input();
    tow_pointer();
    cout<<answer;
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solution();
}