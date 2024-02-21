#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;
static int point[50][50];
char arr[50][50];
bool chk[50][50];
int N;
int px[8] = { 1,1,1,0,0,-1,-1,-1 };
int py[8] = { -1,0,1,-1,1,-1,0,1 };
pair<int, int> start;
set<int> st;
int num_of_house = 0;
int answer_min = 0;
int answer_max = 0;
void input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int t = 0; t < N; t++)
        {
            cin >> arr[i][t];
            if (arr[i][t] == 'P')
            {
                start.first = i;
                start.second = t;
            }
            else if (arr[i][t] == 'K')
            {
                num_of_house += 1;
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int t = 0; t < N; t++)
        {
            cin >> point[i][t];
            st.insert(point[i][t]);
        }
    }
}
void reset()
{
    for (int i = 0; i < 50; i++)
    {
        for (int t = 0; t < 50; t++)
        {
            chk[i][t] = false;
        }
    }
}
bool bfs(int min_point, int max_point)
{
    if (!(point[start.first][start.second] >= min_point && point[start.first][start.second] <= max_point))
    {
        return false;
    }
    queue<pair<int, int> > q;
    reset();
    chk[start.first][start.second] = true;
    q.push(start);
    int count = 0;
    bool flag = false;
    while (!q.empty())
    {
        int now_y = q.front().first;
        int now_x = q.front().second;
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            int next_y = now_y + py[i];
            int next_x = now_x + px[i];
            if (0 <= next_y && next_y < N && 0 <= next_x && next_x < N && !chk[next_y][next_x])
            {
                if (point[next_y][next_x] >= min_point && point[next_y][next_x] <= max_point)
                {
                    if (arr[next_y][next_x] == 'K')
                    {
                        count += 1;
                    }
                    q.push(make_pair(next_y, next_x));
                    chk[next_y][next_x] = 1;
                }
            }
        }
    }
    if (count == num_of_house)
    {
        return true;
    }
    return false;
}
void two_pointer()
{
    int left = 0;
    int right = 0;
    vector<int> vct;
    for (auto temp : st)
    {
        vct.push_back(temp);
    }

    sort(vct.begin(), vct.end());
    int answer = 1000000000;
    while (left < vct.size())
    {
        int min_point = vct[left];
        int max_point = vct[right];
        if (bfs(min_point, max_point))
        {
            answer_min = min_point;
            answer_max = max_point;
            if (answer > (answer_max - answer_min))
            {
                answer = answer_max - answer_min;
            }
            left += 1;
        }
        else
        {
            if (right < vct.size()-1)
            {
                right += 1;
            }
            else
            {
                break;
            }
        }
    }
    cout << answer;
}
void solution()
{
    input();
    two_pointer();
}
int main(void)
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cout.tie(NULL);
    solution();
}