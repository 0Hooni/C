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

#define MAX_INDEX 50001
vector<int> tree[MAX_INDEX];
int dp[MAX_INDEX];
bool visit[MAX_INDEX];

void bfs(){
    memset(visit, false, sizeof(visit));

    queue<int> q;
    q.push(1);
    visit[1] = true;

    while (!q.empty()){
        int par = q.front();
        q.pop();
        for(int i=0; i<tree[par].size(); i++){
            int child = tree[par][i];
            if(!visit[child]){
                q.push(child);
                visit[child] = true;
                dp[child] += dp[par] + 1;
            }
        }
    }
}

int main(){
    init();
    int t; cin >> t;
    while (t--){
        memset(tree, 0, sizeof(tree));

        int n; cin >> n;
        for(int i=1; i<n; i++){
            int par, child;
            cin >> par >> child;
            tree[par].push_back(child); //자식들로 배열을 구성
        }

        for(int i=1; i<=n; i++){
            string str;
            cin >> str;
            dp[i] = str.length();   //dp[i]에 자기 자신의 길이를 저장
        }
        bfs();  //bfs 탐색을 통해 dp를 완성

        for(int i=1; i<=n; i++) cout << dp[i] << "\n";
    }
    return 0;
}
