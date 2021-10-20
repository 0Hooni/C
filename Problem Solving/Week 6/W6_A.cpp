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
vector<int> total_price;
int total_time;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
queue<pair<int, int>> user;
//first : 시간, second : 계산대 번호
//function area
void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){
    init();
    int n, m; cin >> n >> m;

    for(int i=0; i<m; i++){
        int time, price; cin >> time >> price;
        if(i<n){
            total_price.push_back(price);
            pq.push(make_pair(time, i));
        }
        else user.push(make_pair(time, price));
    }

    while (!pq.empty()){
        if(!user.empty()){
            int time = user.front().first;
            int price = user.front().second;
            user.pop();

            if(total_time == pq.top().first){ //최소시간 == 본인의 시간일때
                int cntr_num = pq.top().second;
                total_price[cntr_num] += price;

                pq.pop();
                pq.push(make_pair(time + total_time, cntr_num));

            }
            else{
                total_time = pq.top().first;
                int cntr_num = pq.top().second;
                total_price[cntr_num] += price;

                pq.pop();
                pq.push(make_pair(time+total_time, cntr_num));
            }
        }
        else{
            if(total_time == pq.top().first){ //최소시간 == 본인의 시간일때
                pq.pop();
            }
            else{
                total_time = pq.top().first;
                pq.pop();
            }
        }
    }

    cout << total_time << "\n";
    for(int i=0; i<n; i++)
        cout << total_price[i] << "\n";

    return 0;
}
