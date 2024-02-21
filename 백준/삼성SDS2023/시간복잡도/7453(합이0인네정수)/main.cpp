//
// Created by 선주환 on 2/20/24.
//
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> a;
vector<int> b;
vector<int> c;
vector<int> d;
vector<int> sum_ab;
vector<int> sum_cd;
int N;
long long answer=0;
void input()
{
    cin>>N;
    for(int i=0;i<N;i++)
    {
        for(int t=0;t<4;t++)
        {
            int number;
            cin>>number;
            if(t==0)
            {
                a.push_back(number);
            }
            else if(t==1)
            {
                b.push_back(number);
            }
            else if(t==2)
            {
                c.push_back(number);
            }
            else
            {
                d.push_back(number);
            }
        }
    }
}
void sum()
{
    for(int i=0;i<a.size();i++)
    {
        for(int t=0;t<b.size();t++)
        {
            int temp=a[i]+b[t];
            sum_ab.push_back(temp);
        }
    }
    for(int i=0;i<c.size();i++)
    {
        for(int t=0;t<d.size();t++)
        {
            int temp=c[i]+d[t];
            sum_cd.push_back(temp);
        }
    }
    sort(sum_cd.begin(),sum_cd.end());
}
int my_upper(int find_number)
{
   int left=0;
   int right=sum_cd.size()-1;
   int answer=-1;
   while(left<=right)
   {
       int mid=(left+right)/2;
       if(sum_cd[mid]>find_number)
       {
          right=mid-1;
       }
       else if(sum_cd[mid]<find_number)
       {
           left=mid+1;
       }
       else
       {
           answer=mid;
           left=mid+1;
       }
   }
   return answer;
}
int my_lower(int find_number)
{
    int left=0;
    int right=sum_cd.size()-1;
    int answer=-1;
    while(left<=right)
    {
        int mid=(left+right)/2;
        if(sum_cd[mid]>find_number)
        {
            right=mid-1;
        }
        else if(sum_cd[mid]<find_number)
        {
            left=mid+1;
        }
        else
        {
            answer=mid;
            right=mid-1;
        }
    }
    return answer;
}
void solution()
{
    input();
    sum();
    for(int i=0;i<sum_ab.size();i++)
    {
        int find_upper= my_upper(0-sum_ab[i]);
        int find_lower= my_lower(0-sum_ab[i]);
        if(find_lower==-1||find_upper==-1)
        {
            continue;
        }
        else
        {
             answer+=(find_upper-find_lower+1);
        }
    }
    cout<<answer;
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solution();

}
