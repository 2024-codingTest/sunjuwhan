//
// Created by 선주환 on 2/14/24.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<char> vct;
int L,C;
vector<char> chk_vct;
void input()
{
   cin>>L>>C;
   vct.resize(C,'0');
   for(int i=0;i<C;i++)
   {
       cin>>vct[i];
   }
   sort(vct.begin(),vct.end());
}
void dfs(int number)
{
    if(chk_vct.size()==L)
    {
        int count_first=0;
        int count_second=0;
        string str;
        //검사
        for(int i=0;i<L;i++)
        {
           if(chk_vct[i]=='a'||chk_vct[i]=='i'||chk_vct[i]=='e'||chk_vct[i]=='o'||chk_vct[i]=='u')
           {
               count_first+=1;
           }
           else
           {
               count_second+=1;
           }
           str+=chk_vct[i];
        }
        if(count_first>=1&&count_second>=2)
        {
            cout<<str<<"\n";
        }
    }
    for(int i=number;i<vct.size();i++)
    {
        chk_vct.push_back(vct[i]);
        dfs(i+1);
        chk_vct.pop_back();
    }
}
void solution()
{
    input();
    dfs(0);
}
int main(void)
{
   ios::sync_with_stdio(false) ;
   cin.tie(NULL);
   cout.tie(NULL);
   solution();
}