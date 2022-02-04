#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int main(){
    init();
    int T; cin >> T;
    while (T--){
        vector<int> mato;
        int N; cin >> N;
        // 마토료시카 크기 입력, vector로 저장
        for(int i=0; i<N; i++){
            int tmp; cin >> tmp;
            mato.push_back(tmp);
        }

        int dp[10000];  //i번 까지 최대 증가한 수를 저장해줌
        fill_n(dp, 1, sizeof(dp));

        int _max = 0;
        for(int i=1; i<N; i++){
            int now_mato = mato[i];
            for(int j=0; j<i; j++){ //now 보다 앞에있는 마토들과 비교
                if(now_mato > mato[j])  //now 보다 작은 moto
                    // 원래와 담았을때중 큰 값을 넣어줌
                    dp[i] = max(dp[i], dp[j]+1);
            }
            _max = max(_max, dp[i]);
        }
        cout << _max << "\n";
    }
    return 0;
}

/*
 * 자기 자신과 그 앞에 자신보다 큰 인자가 있는지 확인
 * 있다면 dp[i] 와 dp[j] + 1을 비교
 */
