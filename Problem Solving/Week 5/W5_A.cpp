#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
//global var area
vector<int> num;
vector<int> hz;
//function area
void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){
    init();
    int t; cin >> t;
    while (t--){
        hz.clear(); num.clear();
        int n; cin >> n;

        for(int i=0; i<n; i++) {
            int tmp; cin >> tmp;
            num.push_back(tmp);
        }

        hz.push_back(num[0]); int x = 1;  //예상주기
        for(int i=1; i<n; i++){
            if(hz.front() != num[i]) {
                hz.push_back(num[i]);
                x++;
            }
            else break;
        }
        int count_same = 0;
        for(int i=x; i<n; i++){
            if(num[i] == num[i-x]) {
                count_same++;
                if(count_same == x) count_same = 0;
            }
            else {
                hz.push_back(num[x++]); i=x-1;
            }
        }

        for(int i=0; i<hz.size(); i++)
            cout << hz[i] << " ";
        cout << "\n";
    }
    return 0;
}
