#include <iostream>
#include <string.h>
#include <queue>
#include <stack>

using namespace std;
typedef long long ll;
void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int ccw(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
    int op = a.first*b.second + b.first*c.second + c.first*a.second;
    op -= (a.second*b.first + b.second*c.first + c.second*a.first);
    if (op > 0)return 1;
    else if (op == 0)return 0;
    else return -1;
}

int main(){
    init();
    int t; cin >> t;
    int x[5], y[5];
    pair<int, int> point[5];
    while (t--){
        for(int i=1; i<5; i++){
            cin >> x[i] >> y[i];
            point[i] = make_pair(x[i], y[i]);
        }
        if(ccw(point[1], point[2], point[3]) * ccw(point[1],point[2], point[4]) != 0){
            if(ccw(point[1], point[2], point[3]) * ccw(point[1],point[2], point[4]) <= 0
            && ccw(point[3], point[4], point[1]) * ccw(point[3],point[4], point[2]) <= 0){
                cout << "1\n";
            } else cout << "2\n";
        }
        else {
            if(point[1].first <= point[3].first && point[2].first <= point[4].first)
                cout << "4\n";
            else cout << "3\n";
        }

    }
    return 0;
}
