#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string.h>
#include <queue>
using namespace std;
int visit[110][110];
int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

pair<int, int> point[4];
int n;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
bool _out_of_range(int x, int y){
    if((0 < x && x <= n) && (0 < y && y <= n)) return false;
    return true;
}
void check_gun_range(int x, int y){
    visit[x][y] = true;

    for(int i=0; i<8; i++){
        int nx = x;
        int ny = y;
        while (1){
            nx += dx[i];
            ny += dy[i];
            if(nx == point[2].first && ny == point[2].second){
                while (!(nx == point[3].first && ny == point[3].second)){
                    visit[nx][ny] = 0;
                    nx -= dx[i];
                    ny -= dy[i];
                }
                break;
            }

            if(_out_of_range(nx, ny)) break;
            else visit[nx][ny] = -1;
        }
    }
}
void bfs(int x, int y){
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    visit[x][y] = 1;

    while (!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int i=0; i<8; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(_out_of_range(nx, ny)) continue;
            else{
                if(!visit[nx][ny]){
                    q.push(make_pair(nx, ny));
                    visit[nx][ny] = visit[x][y] + 1;
                }
            }
        }
    }
}

int main() {
    init();
    int t; cin >> t;
    while (t--){
        cin >> n;

        for(int i=0; i<4; i++){
            int x, y; cin >> x >> y;
            point[i] = make_pair(x, y);
        }   //1 : 인하, 2: 세이프, 3:검사, 4:소총수
        check_gun_range(point[3].first, point[3].second);
        for(int i=0; i<8; i++){
            int nsx = point[2].first + dx[i];
            int nsy = point[2].second + dy[i];
            if(_out_of_range(nsx, nsy)) break;
            else{
                if(!visit[nsx][nsy]) visit[nsx][nsy] = -1;
            }
        }
        visit[point[2].first][point[2].second] = 0;
        visit[point[3].first][point[3].second] = 0;

        bfs(point[0].first, point[0].second);
        if(visit[point[1].first][point[1].second] == 0 ||
        visit[point[1].first][point[1].second] == -1) cout << 0 << "\n";
        else
            cout << visit[point[1].first][point[1].second] - 1 << "\n";

        memset(visit, 0, sizeof(visit));
    }
    return 0;
}

/*
 */
