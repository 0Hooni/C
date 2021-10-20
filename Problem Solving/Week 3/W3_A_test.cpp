#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string.h>
#include <queue>

using namespace std;
#define MAX_INDEX 50001
vector<int> my_chi[MAX_INDEX];
bool visit[MAX_INDEX];
int len_of_Dir[MAX_INDEX];
void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void bfs()
{
    queue<int> q;
    q.push(1);
    visit[1] = true;

    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i = 0; i < my_chi[x].size(); i++)
        {
            int next = my_chi[x][i];
            if (!visit[next])
            {
                visit[next] = true;
                len_of_Dir[next] += len_of_Dir[x] + 1;
                q.push(next);
            }
        }
    }
}

int main()
{
    init();
    int t;
    cin >> t;
    while (t--)
    {
        memset(my_chi, NULL, sizeof(my_chi));
        memset(visit, false, sizeof(visit));
        memset(len_of_Dir, 0, sizeof(len_of_Dir));
        int n;
        cin >> n;
        for (int i = 1; i < n; i++)
        {
            int par, chi;
            cin >> par >> chi;
            my_chi[par].push_back(chi);
        }
        for (int i = 1; i <= n; i++)
        {
            string tmp;
            cin >> tmp;
            len_of_Dir[i] = tmp.size();
        }
        bfs();

        for (int i = 1; i <= n; i++)
            cout << len_of_Dir[i] << "\n";
    }
    return 0;
}

/*
 * bfs적인 사고로 문제 접근
 * 자기 자식에 대한 정보를 담을 vector 필요
 * bfs를 통해 자기 자식들을 탐색(시작은 root)
 * 각자의 단어길이는 단어를 입력시 dp[i]에 저장, 탐색중에 이전길이와 합침(+1)
 * Compile_error : memset 사용시, 헤더파일 추가(string.h)
 */