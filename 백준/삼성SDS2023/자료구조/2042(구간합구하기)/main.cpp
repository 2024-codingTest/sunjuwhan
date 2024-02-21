#include <iostream>

#include <math.h>

#include <vector>

using namespace std;

int N,M,K;
vector<long long> tree;
void update(long long pos,long long number)
{
    while(pos>1)
    {
        pos=pos/2;
        tree[pos]+=number;
    }
}
long long sum_range(long long start,long long end)
{
    long long sum=0;
    while(start<=end)
    {
        if(start%2==1) //더해줘야함
        {
           sum+=tree[start] ;
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
void change(long long pos,long long number)
{
    long long  change_number=number-tree[pos];  //기존 수에서 바뀐만큼
    tree[pos]=number;
    while(pos>1)
    {
        pos=pos/2;
        tree[pos]+= change_number;
    }
}
void input()
{
    cin>>N>>M>>K;
    int tree_height=ceil(log2(N)) ;
    int tree_size=1<<(tree_height+1);
    tree.resize(tree_size);
    for(long long i=1;i<=N;i++)

    {
        long long input_space=i-1+(tree_size/2);
        cin>>tree[input_space];
        update(input_space,tree[input_space]);
    }
    for(int i=0;i<M+K;i++)
    {
        int a,b;
        long long c;
        cin>>a>>b>>c;
        int start_pos=b+(tree_size/2)-1;
        if(a==1)
        {
            change(start_pos,c) ;
        }
        else
        {
           int end_pos=c+(tree_size/2) -1;
            cout<<sum_range(start_pos,end_pos)<<"\n";
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    input();
}
