#include <bits/stdc++.h>
 
using namespace std;
using ll = long long int;
 
void testcase() {
    ll n, x, k;
    string s;
    cin >> n >> x >> k >> s;
    ll ox = x;
    
    ll firstTime = -1;
    for(ll i = 0; i < (ll)s.length(); i++) {
        if(s[i] == 'R') {
            x++;
        }
        else {
            x--;
        }
        
        if(x == 0) {
            firstTime = i + 1;
            break;
        }
    }
    if(ox == 0) {
        firstTime = 0;
        x = 0;
    }
    
    
    ll secondTime = -1;
    for(ll i = 0; i < (ll)s.length(); i++) {
        if(s[i] == 'R') {
            x++;
        }
        else {
            x--;
        }
        
        if(x == 0) {
            secondTime = i + 1;
            break;
        }
    }
    
    if(firstTime == -1 || k < firstTime) cout << 0 << endl;
    else if(secondTime == -1) cout << 1 << endl;
    else cout << (k - firstTime) / secondTime + 1 << endl;
}
 
int main()
{
    int t;
    cin >> t;
    while(t--) testcase();
 
    return 0;
}