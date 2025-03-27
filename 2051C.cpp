#include <bits/stdc++.h>
 
using namespace std;
using ll = long long int;
 
ll n, m, k;
 
void testcase() {
    cin >> n >> m >> k;
 
    int lists[300010];
    set<int> q;
    q.clear();
 
    for(int i = 0; i < m; i++) cin >> lists[i];
    for(int i = 0; i < k; i++) {
        int qi;
        cin >> qi;
        q.insert(qi);
    }
 
    if(k == n) {
        for(int i = 0; i < m; i++) cout << 1;
    }
    else if(k == n-1) {
        for(int i = 0; i < m; i++) {
            if(q.count(lists[i]) == 0) cout << 1;
            else cout << 0;
        }
    }
    else {
        for(int i = 0; i < m; i++) cout << 0;
    }
 
    cout << endl;
}
 
int main() {
    int t;
    cin >> t;
 
    while(t--) testcase();
    
    return 0;
}