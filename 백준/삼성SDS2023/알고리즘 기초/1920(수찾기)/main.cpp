//
// Created by 선주환 on 2/14/24.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> vct;
vector<int> find_vct;

int N,M;

void input()
{
    cin>>N;
    for(int i=0;i<N;i++)
    {
        int number;
        cin>>number;
        vct.push_back(number);
    }
    cin>>M;
    for(int i=0;i<M;i++)
    {
        int number;
        cin>>number;
        find_vct.push_back(number);
    }
}
void binary_search()
{
    for(int i=0;i<find_vct.size();i++)
    {
        int left=0;
        int right=N-1;
        int find_number=find_vct[i];
        bool flag=0;
        while(left<=right)
        {
            int mid=(left+right)/2;
            if(vct[mid]==find_number)
            {
                cout<<"1"<<"\n";
                flag=1;
                break;
            }
            else if(vct[mid]<find_number)
            {
                left=mid+1;
            }
            else
            {
                right=mid-1;
            }
        }
        if(flag!=1)
        {
            cout<<"0" <<"\n";
        }
    }
}
void solution()
{
    input();
    sort(vct.begin(),vct.end());
    binary_search();
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solution();
}