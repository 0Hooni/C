#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;
void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    init();
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        vector<int> hz;
        int hz_len = 0;
        bool check_hz = false;
        for(int i=0; i<n; i++){
            int tmp; cin >> tmp;
            hz.push_back(tmp);
        }
        while (hz[hz_len++] != hz[0]);

        int isCorrect = 0;
        for(int i=hz_len; i<n; i++){
            if(hz[i] == hz[i-hz_len]){//예상 주기가 맞을때
                isCorrect++;
                if(isCorrect == hz_len) isCorrect = 0;
            }
            else {
                isCorrect = 0;
                i = hz_len;
                hz_len++;
            }
        }
        for(int i=0; i<hz_len; i++){
            cout << hz[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

/*
 * hz입력을 받은 뒤 hz의 맨 앞 원소와 일치하는 다음원소가 나오는 길이를 예상주기로 체크
 * 이 때 예상주기가 너무 짧을때는 인식이 안되는 부분을 생각(n=2같은 case)
 * 예상 주기부터(i) 이전에 있는원소(i-hz_len)와 비교하면서 체크
 * 한 주기를 다 돌면 체크를 초기화해서 다시 체크
 * 중간에 주기가 예상과 다르면 hz_len++
 * 비교연산을 하는 for문 탐색을 마치고 탈출하면 그때 hz_len까지 hz[]을 출력
 */
