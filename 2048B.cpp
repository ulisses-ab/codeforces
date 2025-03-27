
#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
int b[100010];
 
void testcase() {
    int n, k;
    cin >> n >> k;
 
    int current = 1;
    int i = k - 1;
 
    while(i < n) {
        b[i] = current;
        current++;
        i += k;
    }
    
    for(i = n - 1; i>=0; i--) {
        if((i + 1) % k != 0) {
            b[i] = current;
            current++;
        }
 
        cout << b[i] << " ";
    }
 
    cout << endl;
 
}
 
int main() {
    int t;
    cin >> t;
 
    while(t--) testcase();
    
    return 0;
}