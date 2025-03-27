#include <bits/stdc++.h>
 
using namespace std;
using ll = long long int;
 
void testcase() {
    int n, a, b;
    cin >> n >> a >> b;
 
    if(abs(b - a) % 2 == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); std::cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) testcase();
}