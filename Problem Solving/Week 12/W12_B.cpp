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
void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool comp(pair<int, int> p1, pair<int, int> p2){
    if(p1.first == p2.first) return p1.second < p2.second;
    else return p1.first > p2.first;
}

int main(){
    init();
    int T; cin >> T;
    while (T--){
        int N; cin >> N;
        vector<pair<int, int>> v;
        for(int i=0; i<N; i++){
            int score, dist;
            cin >> score >> dist;
            v.push_back({score, dist});
        }
        sort(v.begin(), v.end(), comp);
        pair<int, int> best = v[0];
        vector<pair<int, int>> _list;
        _list.push_back(v[0]);

        for(int i=1; i<N; i++){
            if(best.first == v[i].first) continue;
            if(best.second > v[i].second){
                _list.push_back(v[i]);
                best = v[i];
            }

        }
        cout << _list.size() << "\n";
    }


    return 0;
}

/*
 */
