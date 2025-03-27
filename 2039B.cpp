#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int t;
    cin >> t;
 
    while(t--) {
        string s;
        cin >> s;
        int n = s.size();
        bool found = false;
 
        for(int i = 0; i + 1 < n; i++) {
            if(s[i] == s[i+1]) {
                cout << s.substr(i, 2) << endl;
                found = true;
                break;
            }
        }
        if(found) continue;
 
        for(int i = 0; i + 2 < n; i++) {
            if(s[i] != s[i+2]) {
                cout << s.substr(i, 3) << endl;
                found = true;
                break;
            }
        }
        if(found) continue;
 
        cout << -1 << endl;
    }
    return 0;
}