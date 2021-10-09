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
vector<pair<int, int>> counter;
vector<int> total_price;
vector<int> total_time;
queue<pair<int, int>> customer;

//function area
void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){
    init();
    int counter_size, customer_size;
    cin >> counter_size >> customer_size;

    int max_time = 0;
    for(int i=0; i<customer_size; i++){
        int time, price;
        cin >> time >> price;
        customer.push(make_pair(time, price));
        max_time += time;
    }

    int next_time = max_time;
    for(int i=0; i<counter_size; i++){
        counter.push_back(customer.front());
        customer.pop();
        total_time.push_back(counter[i].first);
        next_time = min(next_time, counter[i].first);
        total_price.push_back(counter[i].second);   //초기화
    }

    while (!customer.empty()){
        for(int i=0; i<counter_size; i++){
            if(next_time == total_time[i] && !customer.empty()){
                counter[i] = customer.front();
                customer.pop();
                total_time[i] += counter[i].first;
                total_price[i] += counter[i].second;
            }
        }
        next_time = max_time;
        for(int i=0; i<counter_size; i++){
            next_time = min(next_time, total_time[i]);
        }
    }
    for(int i=0; i<counter_size; i++){
        next_time = max(next_time, total_time[i]);
    }

    cout << next_time << "\n";
    for(int i=0; i<counter_size; i++) cout << total_price[i] << "\n";

    return 0;
}

/*
 *
 */
