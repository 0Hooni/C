#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <math.h>
#include <utility>
using namespace std;
bool comp(const pair<pair<int, int>, float> &p1, const pair<pair<int, int>, float> &p2){
    if(p1.second == p2.second){
        if(p1.first.first == p2.first.first)
            return p1.first.second < p2.first.second;
        else
            return p1.first.first < p2.first.first;
    }
    else
        return p1.second < p2.second;
}
void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
float dist(int x, int y){
    float res = x*x + y*y;
    return sqrt(res);
}

int main(){
    init();
    int T; cin >> T;
    while (T--){
        int M, N, K; cin >> M >> N >> K;
        vector<pair<pair<int, int>, float>> v;

        for(int i=0; i<M; i++){
            int x, y; cin >> x >> y;
            v.push_back({{x, y}, dist(x, y)});
        }
        sort(v.begin(), v.end(), comp);

        for(int i=0; i<N; i++){
            int x, y; cin >> x >> y;
            v.push_back({{x, y}, dist(x, y)});
            sort(v.begin(), v.end(), comp);
            cout << v[K-1].first.first << " " << v[K-1].first.second << "\n";
        }
    }
    return 0;
}

/*
 * 정렬하여 3번쨰 인자를 뽑는 식으로 해봄
 * 결과는 TLE
 * sort 하는것에서 TLE를 풀 방법 생각해야될듯
 */
