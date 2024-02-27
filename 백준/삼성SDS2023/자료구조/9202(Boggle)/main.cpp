#include <iostream>
#include <map>
using namespace std;
char board[4][4];
bool chk[4][4];
map<string, int> mp;  //결과 map이라고 생각하자
int px[8] = {-1,-1,-1,0,0,1,1,1};
int py[8] = { -1,0,1,-1,1,-1,0,1 };

class Node
{
public:
	Node* next[26];
	bool end_flag;

	Node()
	{
		for (int i = 0; i < 26; i++)
		{
			next[i] = nullptr;
		}
		end_flag = false;
	}
	void insert(const char* key)
	{

		int now_pos = *key - 'A';
		if (*key== NULL)
		{
			end_flag = true;
			return;
		}
		if (next[now_pos] == nullptr)
		{
			next[now_pos] = new Node();
		}
		next[now_pos]->insert(key + 1);
		
	}

	int find(string str,int index)
	{
		char key = str[index];
		if (key == NULL)
		{
			if (end_flag == true)  //다 찾은거니까 map <string,int> 에 저장해준다.  
			{
				mp.insert(make_pair(str, 1));
				return 1;  //끝까지 다찾은경우
			}
			else
			{
				return 0;  //그다음 단어로 넘어갈 경우 
			}
		}
		int now_pos =key - 'A';

		if (next[now_pos] == nullptr)
		{
			return -1;
		}
		else
		{
			return next[now_pos]->find(str,index+1);
		}
	};
};
Node* root = new Node();

void dfs(int y, int x,string str,int depth)
{

	if (depth > 8)
	{
		return;
	}
	int find_result = root->find(str, 0);
	if (find_result==0||find_result==1)  //찾으면 다음 단어로 찾아간다
	{
		for (int i = 0; i < 8; i++)
		{
			int next_y = y + py[i];
			int next_x = x + px[i];
			if (next_y >= 0 && next_y < 4 && next_x >= 0 && next_x < 4&&chk[next_y][next_x]==0)
			{
				chk[next_y][next_x] = 1;
				str+= board[next_y][next_x];
				dfs(next_y, next_x, str, depth + 1);
				str.pop_back();
				chk[next_y][next_x] = 0;
			}
		}
		if (find_result == 1)
		{
			mp.insert(make_pair(str, 1));
		}
	}
	else
	{
		return;
	}

}
void input()
{
	int N;
	cin >> N;
	char c[9];
	for (int i = 0; i < N; i++)
	{
		cin >> c;
		root->insert(c);
	}
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		mp.clear();
		for (int t = 0; t < 4; t++)
		{
			for (int z = 0; z < 4; z++)
			{
				cin >> board[t][z];
				chk[t][z] = false;
			}
		}
		for (int t = 0; t < 4; t++)
		{
			for (int z = 0; z < 4; z++)
			{
				chk[t][z] = 1;
				string temp;
				temp += board[t][z];
				dfs(t, z, temp,1);
				chk[t][z] = 0;
				temp.pop_back();
			}
		}
		int answer = 0;
		int answer_count = mp.size();
		string answer_str = "";
		for (auto temp : mp)
		{
			if (temp.first.size() == 3 || temp.first.size() == 4)
			{
				answer += 1;
			}
			else if (temp.first.size() == 5)
			{
				answer += 2;
			}
			else if (temp.first.size() == 6)
			{
				answer += 3;
			}
			else if (temp.first.size() == 7)
			{
				answer += 5;
			}
			else if (temp.first.size() == 8)
			{
				answer += 11;
			}
			if (answer_str.size() <=temp.first.size())
			{
				if (answer_str.size() == temp.first.size())
				{
					if (answer_str > temp.first)
					{
						answer_str = temp.first;
					}
				}
				else
				{
					answer_str = temp.first;
				}
			}
		}
		if (answer_str == "")
		{
			cout << answer << " " << answer_count << endl;
		}
		else
		{
			cout << answer << " " << answer_str << " " << answer_count << endl;
		}
	}
}

void solution()
{
	input();
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solution();
}
