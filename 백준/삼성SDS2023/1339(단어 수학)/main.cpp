//
// Created by 선주환 on 2/15/24.
//
#include <iostream>
#include <vector>
#include <set>
using namespace std;
static int chk[10];    //0~9사용 여부
static int alphabet[26]; //각알파벳별 숫자가 얼마인지
vector<string> vct;
set<char> st;
vector<char> st_vct;
int N;
int answer=0;
void input()
{
   cin>>N;
   vct.resize(N,"");
   for(int i=0;i<N;i++)
   {
       cin>>vct[i];
       for(int t=0;t<vct[i].size();t++)
       {
           st.insert(vct[i][t]);
       }
   }
   for(set<char> ::iterator  itr= st.begin();itr!=st.end();itr++)
   {
       st_vct.push_back(*itr);
   }
}
void dfs(int depth)
{
    if(depth==st_vct.size())
    {
        int temp=0;
        for(int i=0;i<N;i++)
        {
            int count=1;
            for(int t=vct[i].size()-1;t>=0;t--)
            {

                temp+=alphabet[vct[i][t]-'A'] *count;
                count*=10;
            }
        }
        if(temp>answer)
        {
            answer=temp;
        }
        return;
    }
    int temp_size=(10-st_vct.size());
    if(temp_size<0)
    {
        temp_size=0;
    }
    for(int i=9;i>=temp_size;i--)
    {
        char now_temp=st_vct[depth];
        if(chk[i]==0)
        {
            chk[i]=1;
            alphabet[now_temp-'A']=i;
            dfs(depth+1);
            chk[i]=0;
            alphabet[now_temp-'A']=0;
        }
        else
        {
            continue;
        }
    }
    return;
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    input();
    dfs(0);
    cout<<answer;
}