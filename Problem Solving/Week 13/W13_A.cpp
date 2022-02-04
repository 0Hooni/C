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

int N, M;
string puzzle[3001];
int F[3001];

void FailFunc(string p){
    memset(F,0, sizeof(F));
    int i=1, j=0;
    while (i < p.size()){
        if (p[i] == p[j]) {
            F[i] = j+1;
            i++; j++;
        }
        else if (j>0) j = F[j-1];
        else F[i++] = 0;
    }
}
bool KMP(string T, string P){
    int i=0, j=0;
    while (i < T.size()){
        if (T[i] == P[j]){
            if(j == P.size()-1) return true;    //검색에 성공
            i++; j++;
        }
        else if(j>0) j = F[j-1];
        else i++;
    }
    return false;
}
int main(){
    init();
    cin >> N >> M;    //N : 격자판의 크기 M : 단어의 개수
    for(int i=0; i<N; i++){
        cin >> puzzle[i];
    }
    string text ="", word;

    for(int i=0; i<N; i++){ //가로로 읽은 문자열들
        text += puzzle[i];
        text += "$";    // 다음 행을 의미
    }
    for(int i=0; i<N; i++){ //세로로 읽은 문자열들
        for(int j=0; j<N; j++){
            text += puzzle[j][i];
        }
        text += "$";
    }
    for(int i=0; i<N; i++){ //대각선으로 윗부분 대각 문자열들
        for(int j=0; j<N-i; j++)
            text += puzzle[j][i + j];
        text += "$";
    }
    for(int i=1; i<N; i++){ //대각선으로 아랫부분 대각 문자열들
        for(int j=0; j<N-i; j++)
            text += puzzle[i + j][j];
        text += "$";
    }

    while(M--) {
        cin >> word;
        FailFunc(word);
        if(KMP(text, word) == true) cout << "1\n";
        else cout << "0\n";
    }
    return 0;
}

/*
 */
