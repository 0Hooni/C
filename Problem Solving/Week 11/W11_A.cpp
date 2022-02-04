#include <iostream>
#include <vector>

using namespace std;


int c_count[27];
int M;

int grade = 0;
int MAX = 0;

vector<pair<string, int>> v;

bool able(int* a, int* b) {
    
    for(int i = 1; i < 27; i++) {
        if(a[i] < b[i])
            return false;
    }
    
    return true;
}

void set_unset(int * a, int* b, bool k) {
    
    if(k) {
        for(int i = 1; i < 27; i++) {
            a[i] -= b[i];
        }
    } else {
        for(int i = 1; i < 27; i++) {
            a[i] += b[i];
        }
        
    }
    
}


void dfs(int start) {
    
    if(start == M) {
        
        if(MAX < grade)
            MAX = grade;
        return;
    }
    int temp[27];
    
    for(int i = start; i < M; i++) {
        
        fill_n(temp, 27, 0);
        
        string t = v[i].first;
        
        for(int i = 0; i < t.length(); i++) {
            temp[t[i] - 'a' + 1]++;
            
            int a = t[i] - 'a';
            int b = 10;
        }
        
        if(able(c_count, temp)) {
            
            set_unset(c_count, temp, true);
            grade += v[i].second;
            
            dfs(i + 1);
            
            set_unset(c_count, temp, false);
            grade -= v[i].second;

            
        }
        
    }
    
}

int main() {
    
    string temps;
    int tempi;
    
    for(int i = 1; i < 27; i++) {
        
        cin >> c_count[i];
    }
    
    cin >> M;
    
    for(int i = 0; i < M; i++) {
        
        cin >> temps >> tempi;
        
        v.push_back(make_pair(temps, tempi));
        
    }
    
    dfs(0);
    
    cout << MAX << "\n";
}

/*
3 1 0 0 2 0 0 0 0 0 0 0 0 2 0 0 0 0 2 0 0 0 0 0 0 0
3
banana 5
bane 4
nas 4
*/
