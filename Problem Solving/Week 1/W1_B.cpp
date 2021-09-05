#include <iostream>
#include <stack>

using namespace std;

void init(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main(){
    init();
    int t;
    cin >> t;
    while (t--){
        int n; cin >> n;
        stack<int> s;
        stack<int> now_max;
        stack<int> now_min;
        while (n--){
            int q = 0; cin >> q;
            if(q == 1){
                int x = 0; cin >> x;
                if(now_min.empty()) now_min.push(x);
                else if(x <= now_min.top()) now_min.push(x);

                if(now_max.empty()) now_max.push(x);
                else if(x >= now_max.top()) now_max.push(x);

                s.push(x);

                cout << now_min.top() << " " << now_max.top() << "\n";
            }
            else if(q==2 && !s.empty()){
                int tmp = s.top();
                s.pop();

                if(now_max.top() == tmp) now_max.pop();
                if(now_min.top() == tmp) now_min.pop();
            }
        }
    }

    return 0;
}