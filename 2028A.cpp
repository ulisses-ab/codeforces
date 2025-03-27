#include <bits/stdc++.h>
 
using namespace std;
using lli = long long int;
 
int n, a, b;
string s;
 
int main() {
    int t;
    cin >> t;
 
    while(t--) {
        cin >> n >> a >> b;
        cin >> s;
 
        int x = 0, y = 0;
        bool ok = false;
        for(int i = 0; i < 10000 && ok == false; i++) {
            for(int i = 0; i < s.length(); i++) {
                if(s[i] == 'N') y++;
                else if(s[i] == 'S') y--;
                else if(s[i] == 'E') x++;
                else x--; 
 
                if(x == a && y == b) {
                    cout << "YES" << endl;
                    ok = true;
                    break;
                }
            }
        }
 
        if(!ok) cout << "NO" << endl;
    }
    
 
}