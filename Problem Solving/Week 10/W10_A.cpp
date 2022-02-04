#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <utility>

using namespace std;
vector<int> road[10000];  // n번이 갈 수 있는 수들을 담아줌
int dist[10000];
int reverse(int n){
    int rev_num = 0;
    for (int i = 3; i >= 0; i--) {
        rev_num += (n%10) * pow(10, i);
    }
    return rev_num;
}
void bfs(int _start){
    memset(dist, 10000, sizeof(dist));    // 10000은 최대크기에서 비롯된 수
    queue<int> q;

    dist[_start] = 0; // 처음 _start 걸리는 시간은 0
    q.push(_start);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int i = 0; i < road[now].size();i++) {
            // 이미 저장된 거리가 나의 거리 + 1 보다 큰 경우
            // or 방문하지 않은 경우(값이 10000인 경우)
            if (dist[road[now][i]] > dist[now] + 1) {
                q.push(road[now][i]); //q에 push
                dist[road[now][i]] = dist[now] + 1; //현재시간에 +1
            }
        }
    }
}
int main() {
    for (int i = 0; i < 10000; i++) { //각 숫자마다 갈수있는 곳 미리 적어둠
        if (i != 0)
            road[i].push_back(i - 1); //현재 숫자에 -1
        if (i != 9999)
            road[i].push_back(i + 1); //현재 숫자에 +1

        road[i].push_back(reverse(i));  //현재 숫자의 역수
    }
    int T, start_room, end_room;    //T: 테스트케이스
    cin >> T;

    while (T--) {
        cin >> start_room >> end_room;
        bfs(start_room);
        cout << dist[end_room] << "\n";
    }
}
