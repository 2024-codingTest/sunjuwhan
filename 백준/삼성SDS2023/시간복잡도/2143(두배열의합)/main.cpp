#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> a;
vector<int> b;
vector<int> sum_a;
vector<int> sum_b;
int K;
long long answer=0;
int my_upper(int find_number)
{
    int left=0;
    int right=sum_b.size()-1;
    int an=-1;
    while(left<=right)
    {
        int mid=(left+right)/2;
        if(sum_b[mid]>find_number)
        {
            right=mid-1;
        }
        else if(sum_b[mid]<=find_number)
        {
            an=mid;
            left=mid+1;
        }
    }
    return an;
}

int my_lower(int find_number)
{
    int left=0;
    int right=sum_b.size()-1;
    int an=-1;
    while(left<=right)
    {
        int mid=(left+right)/2;
        if(sum_b[mid]<find_number)
        {
            left=mid+1;
        }
        else if(sum_b[mid]>=find_number)
        {
            an=mid;
            right=mid-1;
        }
    }
    return an;
}

void input()
{
    cin>>K;
    int size_a;
    cin>>size_a;
    a.resize(size_a,0);
    for(int i=0;i<size_a;i++)
    {
        cin>>a[i];
    }
    int size_b;
    cin>>size_b;
    b.resize(size_b,0);
    for(int i=0;i<size_b;i++)
    {
        cin>>b[i];
    }
}
void add_sum()
{
    for(int i=0;i<a.size();i++)
    {
        int temp=a[i];
        sum_a.push_back(temp);
        for(int t=i+1;t<a.size();t++)
        {
           temp+=a[t] ;
           sum_a.push_back(temp);
        }
    }
    for(int i=0;i<b.size();i++)
    {
        int temp=b[i];
        sum_b.push_back(temp);
        for(int t=i+1;t<b.size();t++)
        {
           temp+=b[t] ;
           sum_b.push_back(temp);
        }
    }
    sort(sum_b.begin(),sum_b.end());
}
void find_answer()
{

   for(int i=0;i<sum_a.size();i++)
   {

       int find_num=K-sum_a[i];

       int up=my_upper(find_num);
       int low=my_lower(find_num);
       if(up==-1||low==-1)
       {
           continue;
       }
       else
       {
           answer+=(up-low+1);
       }
   }
   cout<<answer;
}
int main(void)
{
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   input();
   add_sum();
   find_answer();

}