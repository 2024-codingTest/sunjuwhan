#include <iostream>
#include <stack>
using namespace std;
static double alpha[27];

string str;
void input()
{
   int N;
   cin>>N;
   cin>>str;
   for(int i=0;i<N;i++)
   {
       double num;
       cin>>num;
       alpha[i]=num;
   }
}
void back_word()
{
    stack<double> stk;
    for(int i=0;i<str.size();i++)
    {
       if(str[i]>='A'&&str[i]<='Z')
       {
           stk.push(alpha[str[i]-'A']);
       }
       else if(str[i]=='+')
       {
          double second=stk.top();
          stk.pop();
          double first=stk.top();
          stk.pop();
          double answer=first+second;
          stk.push(answer);
       }
       else if(str[i]=='-')
       {
           double second=stk.top();
           stk.pop();
           double first=stk.top();
           stk.pop();
           double answer=first-second;
           stk.push(answer);
       }
       else if(str[i]=='/')
       {
           double second=stk.top();
           stk.pop();
           double first=stk.top();
           stk.pop();
           double answer=first/second;
           stk.push(answer);
       }
       else if(str[i]=='*')
       {
           double second=stk.top();
           stk.pop();
           double first=stk.top();
           stk.pop();
           double answer=first*second;
           stk.push(answer);
       }
    }
    cout<<stk.top();
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<fixed;
    cout.precision(2);
    input();
    back_word();
}