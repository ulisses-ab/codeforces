#include <bits/stdc++.h>
 
using namespace std;
using ll = long long int;
 
ll column[1010], row[1010], grid[1010][1010];
 
 
void testcase() {
    ll n, m;
    string s;
    cin >> n >> m >> s;
 
    for(ll i = 0; i < n; i++) row[i] = 0;
    for(ll i = 0; i < m; i++) column[i] = 0;
 
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < m; j++) {
            cin >> grid[i][j];
 
            row[i] += grid[i][j];
            column[j] += grid[i][j];
        }
    }
 
    ll i = 0, j = 0;
    for(ll k = 0; k < s.size(); k++) {
        if(s[k] == 'D') {
            grid[i][j] = -row[i];
            column[j] += grid[i][j];
            row[i] = 0;
            i++;
        }
        else {
            grid[i][j] = -column[j];
            row[i] += grid[i][j];
            column[j] = 0;
            j++;
        }
    }
 
    grid[n-1][m-1] = -column[m-1];
 
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < m; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); std::cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) testcase();
}
