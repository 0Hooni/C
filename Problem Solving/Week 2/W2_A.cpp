#include <iostream>
#include <string.h>
#include <queue>
#include <stack>

using namespace std;

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){
    init();
    int T;
    cin >> T;

    while (T--){
        int n; int m;   //친구들의 수, 단어의 수
        cin >> n >> m;

        queue<string> ans;
        for(int i=0; i<m; i++) {
            string str = "";
            cin >> str;
            ans.push(str);
        }

        queue<string> student_word[20];
        for(int i=0; i<n; i++) {
            int k; cin >> k;
            for(int j=0; j<k; j++){
                string str = "";
                cin >> str;
                student_word[i].push(str);
            }
        }

        while (!ans.empty()){
            int cnt = 0;
            for(int i=0; i<n; i++){
                if(ans.front() == student_word[i].front()){
                    ans.pop(); student_word[i].pop();
                    cnt++;
                    break;
                }
            }
            if(cnt == 0){
                cout << 0 << "\n";
                break;
            }
        }
        if(ans.empty()) cout << 1 << "\n";
    }
    return 0;
}
