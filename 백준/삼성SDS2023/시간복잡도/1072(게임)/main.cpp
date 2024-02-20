//
// Created by 선주환 on 2/20/24.
//
#include <iostream>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long X,Y;
    cin>>X>>Y;
    long long left=0;
    long long right=1000000000;
    long long temp=(Y*100/X);
    long long answer=-1;
    while(left<=right)
    {
        long long mid=(left+right)/2;
        long long mid_num=((Y+mid)*100/(X+mid));
        if(mid_num<=temp)
        {
            answer=mid;
            left=mid+1;
        }
        else if(mid_num>temp)
        {
            right=mid-1;
        }//
// Created by 선주환 on 2/20/24.
//
#include <iostream>
        using namespace std;

        int main(void)
        {
            ios::sync_with_stdio(false);
            cin.tie(NULL);
            cout.tie(NULL);
            long long X,Y;
            cin>>X>>Y;
            long long left=0;
            long long right=1000000000;
            long long temp=(Y*100/X);
            long long answer=-1;
            while(left<=right)
            {
                long long mid=(left+right)/2;
                long long mid_num=((Y+mid)*100/(X+mid));
                if(mid_num<=temp)
                {
                    answer=mid;
                    left=mid+1;
                }
                else if(mid_num>temp)
                {
                    right=mid-1;
                }
            }
            if(answer==1000000000)
            {
                cout<<"-1";
                return 0;
            }
            else
            {
                cout<<answer+1;
            }
        }
    }
    if(answer==1000000000)
    {
        cout<<"-1";
        return 0;
    }
    else
    {
        cout<<answer+1;
    }
}