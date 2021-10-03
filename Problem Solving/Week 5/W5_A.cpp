#include <iostream>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>

using namespace std;
void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

vector<int> hz;
int num[5001];

int main(){
    init();
    int t; cin >> t;
    while (t--){
        int n; cin >> n;

        for(int i=0; i<n; i++) cin >> num[i];

        int i=0;
        while (num[i] != hz.front()) hz.push_back(num[i++]);

        int hz_now = 0;
        for(int j=i; j<n; j++){
            if(num[j] == hz[hz_now]) {
                hz_now++;
                if(hz_now == hz.size()) hz_now = 0;
            }
            else {
                while (i != j){
                    hz.push_back(num[i++]);
                }
                hz_now = 0;
            }
        }

        for(int j=0; j<hz.size(); j++)
            cout << hz[j] << " ";
        cout << "\n";
    }

    return 0;
}
