#include <iostream>
#include <vector>
#include <string.h>
#include <stack>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;

//def area
//global var area
int t;
char _map[101][1001];
//function area
void init(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    init();
    cin >> t;

    while (t--){
        string str = ""; int k;
        cin >> str >> k;
        memset(_map,NULL,sizeof(_map));

        int now_idx = 0;
        while (now_idx != str.length()){
            int tmp = now_idx/k;

            if(tmp%2 == 0)
                _map[now_idx%k][tmp] = str[now_idx];
            else
                _map[(k-1)-(now_idx%k)][tmp] = str[now_idx];
            now_idx++;
        }

        for(int i=0; i<k; i++){
            cout << _map[i];
        }
        cout << "\n";
    }

    return 0;
}

/*
 */
