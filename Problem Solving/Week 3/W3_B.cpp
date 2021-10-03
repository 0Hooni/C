#include <iostream>
#include <string.h>
#include <queue>
#include <stack>

using namespace std;
void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

#define MAX_INDEX 2001
vector<pair<int, int>> house[MAX_INDEX];
bool visit[MAX_INDEX];
int _max[MAX_INDEX];

void bfs(int start){
    memset(_max, 0, sizeof(_max));
    memset(visit, false, sizeof(visit));

    queue<int> q;
    q.push(start);
    visit[start] = true;
    _max[start] = 0;

    while (!q.empty()){
        int now = q.front();
        q.pop();

        for(int i=0; i<house[now].size(); i++){
            int next = house[now][i].first;     //연결된 정점의 숫자
            int now_to_next = house[now][i].second;  //연결된 집까지 거리
            if(!visit[next]){
                q.push(next);
                _max[next] = _max[now] + now_to_next;
                visit[next] = true;
            }
        }
    }
}


int main(){
    init();
    int t; cin >> t;
    while (t--){
        memset(house, 0, sizeof(house));

        int n; cin >> n;
        for(int i=1; i<n; i++){
            int u, v; cin >> u >> v;
            int dist; cin >> dist;
            house[u].push_back(make_pair(v, dist));
            house[v].push_back(make_pair(u, dist));
        }
        int start = 1;
        bfs(start);

        int now_max = 0;
        for(int i=1; i<=n; i++){
            if(now_max < _max[i]) {
                now_max = _max[i];
                start = i;
            }
        }
        bfs(start);
        for(int i=1; i<=n; i++){
            if(now_max < _max[i])
                now_max = _max[i];
        }
        cout << now_max << "\n";
    }

    return 0;
}
