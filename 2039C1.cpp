#include <bits/stdc++.h>
 
using namespace std;
using lli = unsigned long long int;
 
int main() {
    int t;
    cin >> t;
 
    while(t--) {
        lli x, m;
        cin >> x >> m;
        lli count = 0;
        for(lli i = 1; i < (3 * x) && i <= m; i++) {
            lli a = (x ^ i);
            if(a == 0) continue;
            if(x % a == 0 || i % a == 0) count++;
        }
 
        cout << count << endl;
    }
    return 0;
}
