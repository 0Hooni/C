#include<iostream>
#include<string>
#include<vector>
using namespace std;

int  B_paper, R_paper;
int p[1025][1025]; //종이의 최대크기
int red_area, blue_area;
bool test(int x, int y, int size, int color) {
    //주어진 시작 좌표가 하나의 영역으로 이루어 져있는지 확인하는 함수

    // p[i][j]에 다른색이 있으면 하나로 이루어진게 아니므로 false
    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (p[i][j] != color) return false;
        }
    }

    // true 일 경우 색종이의 넓이를 총 넓이에 더해준다
    if (color == 0) red_area += (size * size);
    else blue_area += (size * size);
    return true;
}
void paper(int x, int y, int size) { // x,y는 좌표의 x y size 는 test 할 종이 크기
    if (test(x, y, size, 0)) { //red_area 색종이로 이루어져있는지 test
        R_paper++; //true 일경우 red_area 종이 +1
        return;
    }
    if (test(x, y, size, 1)) { //blue_area 색종이로 이루어져있는지 test
        B_paper++; //true 일 경우 blue_area 종이 +1
        return;
    }

    //같은색으로 종이가 이루어지지 않았을 경우 색종이를 4등분
    paper(x, y, size / 2);
    paper(x + size / 2, y, size / 2);
    paper(x, y + size / 2, size / 2);
    paper(x + size / 2, y + size / 2, size / 2);
}

int main() {
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        R_paper = 0, B_paper = 0; //색종이 갯수
        red_area = 0, blue_area = 0; //색종이들 크기의 합

        //종이 한장의 색 구성을 받는 반복문
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                char tmp; cin >> tmp;
                if (tmp == 'R') //Red 색종이는 0
                    p[i][j] = 0;
                else
                    p[i][j] = 1; //Blue 색종이는 1
            }
        }

        //1, 1 에서부터 탐색 시작
        paper(1, 1, N);

        cout << R_paper << " " << red_area << " " << B_paper << " " << blue_area << "\n";
    }
}
