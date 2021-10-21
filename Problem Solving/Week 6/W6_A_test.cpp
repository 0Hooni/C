#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <stack>
using namespace std;
int arr[1000001];
int N;
int M;
int check(int length) {
    int house = 1;
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (house <= arr[i]) {
            house = arr[i] + length;
            count += 1;
        }
        if (count == M) {
            return true; // M명 주민 모두 입주 성공
        }
    }
    return false;
}
int test(int first, int last) {
    int mid;
    if (first == last)
        return first;
    
    if (first + 1 == last) {
        if (check(last) == true) return last;
        else return first;
    }
    mid = (first + last) / 2;
    if (check(mid) == true) {
        return test(mid, last);
    }
    else {
        return test(first, mid - 1);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int result, h;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> h;
        arr[i] = h;
    }

    result = test(1, arr[N - 1] - 1);
    cout << result;
}