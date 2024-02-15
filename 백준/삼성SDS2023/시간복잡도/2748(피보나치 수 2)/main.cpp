//
// Created by 선주환 on 2/15/24.
//
#include <iostream>
using namespace std;
int N;
static long long arr[91];
void input()
{
    cin>>N;
}
long long fibo(int a)
{
    if(a<0)
    {
        return 0;
    }
    if(a==0)
    {
        return 0;
    }
    else if(a==1)
    {
        return 1;
    }
    else if(arr[a]!=0)
    {
       return arr[a] ;
    }
    else
    {
        return arr[a]=fibo(a-1)+fibo(a-2);
    }
}
void solution()
{
    input();
    arr[1]=1;
    fibo(N);
    cout<<arr[N];
}
int main(void)
{
    solution();
}
