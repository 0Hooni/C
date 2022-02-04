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

char board[30][30];
int n;
int dx[] = {1,1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
bool search(int r, int c, char color){
    int Can = 0;
    for(int i=0; i<8; i++){
        int nx = r;
        int ny = c;

        nx += dx[i];
        ny += dy[i];
        vector<pair<int, int>> flag;
        while((1 <= nx && nx <= n) && (1 <= ny && ny <= n)){
            if(board[nx][ny] == ' ') break;
            else {
                if(board[nx][ny] != color)
                    flag.push_back(make_pair(nx, ny));
                else{
                    for(int j=0; j<flag.size(); j++){
                        board[flag[j].first][flag[j].second] = color;
                        break;
                    }
                    Can++;
                }
            }
            nx += dx[i];
            ny += dy[i];
        }
    }
    if(Can == 0) return false;
    else return true;
}
int win(){
    int inha = 0;
    int biryoung = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(board[i][j] == 'B') inha++;
            else if (board[i][j] == 'W') biryoung++;
        }
    }
    if(inha > biryoung) return 2;
    else if(inha < biryoung) return 1;
    else return 0;
}
int main(){
    init();
    int T; cin >> T;
    while (T--){
        memset(board, ' ', sizeof(board));
        int Q; cin >> n >> Q;
        board[n/2][n/2] = board[n/2+1][n/2+1] = 'B';  //1 : 인하
        board[n/2+1][n/2] = board[n/2][n/2+1] = 'W';  //2 : 비룔
        char color = 'B';
        int cant_W = 0;
        int cant_B = 0;
        for(int i=0; i<Q; i++){
            int r, c; cin >> r >> c;
            board[r][c] = color;
            if(search(r, c, color)){}
            else{
                board[r][c] = ' ';
            }
            if(color == 'B') color = 'W';
            else if(color == 'W') color = 'B';

        }
        cout << win() << "\n";
    }

    return 0;
}

/*
 * 가능하지 않는 출력에 대해서는 턴을 유지하여 다음 입력또한 같은 사람으로 취급한다.
 * 문제의 예외처리를 잘 처리해보고 제출해보자
 */
