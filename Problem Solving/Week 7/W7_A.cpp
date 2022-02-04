#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
using namespace std;
//cin, cout 시간단축 함수
void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

vector<int> v[101]; //공의 무게를 유향그래프로 저장
bool check[101];
int size;

void dfs(int start){
    check[start] = true;
    for(int i=0; i<v[start].size(); i++){
        if(!check[v[start][i]]){
            dfs(v[start][i]);
            size++;
        }
    }
}

int main(){
    init();
    int T; cin >> T;
    while (T--){
        int N, M; cin >> N >> M;
        memset(v, NULL, sizeof(v));
        for(int i=0; i<M; i++){
            int A, B; cin >> A >> B;    //A > B
            v[A].push_back(B);
        }
        for(int j=1; j<=N; j++){
            memset(check, false, sizeof(check));
            size = 0;
            dfs(j);
            cout << size << " ";
        }
        cout << "\n";
    }
    return 0;
}

/*
 * 자신보다 무거운건 그래프 방향으로 표현
 *
 */
