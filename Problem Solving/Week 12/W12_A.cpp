#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int tri[101][101];

int main(){
    init();

    int t; cin >> t;
    while (t--){
        memset(tri, 0, sizeof(tri));
        int n; cin >> n;
        for(int i=0;i < n; i++)
            for(int j=0; j<=i; j++) {
                int tmp; cin >> tmp;
                tri[i][j] = tmp;
                int _min = 0;

                if(j == 0) _min = tri[i-1][j];
                else if(j == i)  _min = tri[i-1][j-1];
                else
                    _min = (tri[i-1][j-1] < tri[i-1][j]) ? tri[i-1][j-1] : tri[i-1][j];

                tri[i][j] += _min;
            }

        int res = tri[n-1][0];
        for(int i=1; i<n; i++)
            res = (tri[n-1][i] < res) ? tri[n-1][i] : res;

        cout << res << "\n";

    }

    return 0;
}
/*
 * 맨 마지막 열에서 가장 작은걸 가져가는 dp
 * 맨 마지막 열에 결과들을 저장해서 가장 작은것 출력
 * 22 23 17 19 21
 * 선택 가능한 영역은 본인이 (i, j)일때 (i-1, j-1), (i-1, j)
 */
