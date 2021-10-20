#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string.h>
#include <queue>

using namespace std;
#define MAX_INDEX 2001
vector<pair<int, int>> graph[MAX_INDEX];
bool visit[MAX_INDEX];
int max_d[MAX_INDEX];
void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void bfs(int start)
{
    memset(visit, false, sizeof(visit));
    memset(max_d, 0, sizeof(max_d));

    visit[start] = true;
    queue<int> q;
    q.push(start);

    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        for (int i = 0; i < graph[now].size(); i++)
        {
            int next = graph[now][i].first;
            int now_to_next = graph[now][i].second;
            if (!visit[next])
            {
                q.push(next);
                max_d[next] = max_d[now] + now_to_next;
                visit[next] = true;
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
        int n;
        cin >> n;
        for (int i = 1; i < n; i++)
        {
            int u, v, d;
            cin >> u >> v >> d;
            graph[u].push_back(make_pair(v, d));
            graph[v].push_back(make_pair(u, d));
        }
        int start = 1;
        bfs(start);
        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            if (res < max_d[i])
            {
                res = max_d[i];
                start = i;
            }
        }

        bfs(start);
        for (int i = 1; i <= n; i++)
            if (res < max_d[i])
                res = max_d[i];

        cout << res << "\n";
    }
    return 0;
}

/*
 * well known 문제, 트리의 지름찾기
 * pair로 그래프를 구성
 * bfs를 두번 통하면 해당 트리에서 가장 긴 지름을 알 수 있음
 *
 * Error : 반복될때 memset에 대하여 민감하게 생각
 */