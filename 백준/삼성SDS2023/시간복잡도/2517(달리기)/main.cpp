//
// Created by 선주환 on 2/19/24.
//
#include <iostream>
#include <map>
#include <math.h>
using namespace std;
vector<pair<int,int> > input_vct;
vector<int> tree;
map<int,int> mp;
vector<int> result;
int N;
bool compare(pair<int,int> a,pair<int,int> b)
{
   return (a.second<b.second) ;
}
bool compare_first(pair<int,int> a,pair<int,int> b)
{
    return (a.first<b.first);
}
void input()
{
     cin>>N;

     for(int i=0;i<N;i++)
     {
         int number;
         cin>>number;
         input_vct.push_back(make_pair(i,number));
     }
     sort(input_vct.begin(),input_vct.end(), compare);
     for(int i=0;i<N;i++)
     {
         input_vct[i].second=i+1;
     }
     sort(input_vct.begin(),input_vct.end(), compare_first);
     int tree_height= ceil(log2(N));
     int tree_size=1<<(tree_height+1);
     tree.resize(tree_size,0);
}

void update_tree(int index)
{
    while(index>0)
    {
        index=index/2;
        tree[index]+=1;
    }
}

int find_sum(int start,int end)
{
    int sum=0;
    while(start<=end)
    {
        if(start%2!=0) //왼쪽이라면
        {
           sum+=tree[start];
        }
        if(end%2==0)
        {
            sum+=tree[end];
        }
        start=(start+1)/2;
        end=(end-1)/2;
    }
    return sum;
}

void input_tree()
{
    int tree_height=ceil(log2(N));
    int start_index=1<<tree_height;
    for(int i=0;i<N;i++)
    {
        int pos= start_index+input_vct[i].second-1;
        tree[pos]=1;
        update_tree(pos);
        result.push_back((i+1)- find_sum(start_index,pos-1));
    }
}

void solution()
{
    input();
    input_tree();
    for(auto temp:result)
    {
        cout<<temp<<"\n";
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solution();
}