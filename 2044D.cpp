
#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
void testcase() {
    int n, a[200010];
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
 
    set<int> used;
 
    int unused = 1;
    for(int i = 0; i < n; i++) {
        if(used.count(a[i]) == 0) {
            cout << a[i] << " ";
            used.insert(a[i]);
        }
        else {
            while(used.count(unused) != 0) unused++;
            cout << unused << " ";
            used.insert(unused);
        }
    }
 
    cout << endl;
}
 
int main() {
    int t;
    cin >> t;
 
    while(t--) testcase();
    
    return 0;
}