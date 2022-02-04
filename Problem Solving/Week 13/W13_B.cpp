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


int main(){
    init();
    int T; cin >> T;
    while (T--){
        int N, M; cin >> N >> M;
        int Messenger[500001];
        int Answer[500001];
        for(int i=0; i<M; i++) cin >> Messenger[i];

        // vector 로 구현할 경우 Find 함수가 TLE 를 불러일으킴
        map<int, bool> Reader;

        for(int i=M-1; i>=0; i--){
            // Find 함수를 통해 해당 인자가 있는지 확인, 없으면 input
            // 아래 if 문의 조건은 존재하지 않는 case 조건문임
            if(Reader.find(Messenger[i]) == Reader.end())
                Reader.insert({Messenger[i], true});

            Answer[i] = N - Reader.size();
        }

        for(int i=0; i<M; i++)
            cout << Answer[i] << "\n";
    }
    return 0;
}

/*
 */
