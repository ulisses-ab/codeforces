#include <bits/stdc++.h>
 
using namespace std;
using ll = long long int;
 
void testcase() {
    ll n, m;
    cin >> n >> m;
    
    cout << max(n, m) + 1 << endl;
}
 
int main()
{
    ll t;
    cin >> t;
    while(t--) testcase();
 
    return 0;
}