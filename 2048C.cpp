#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
int b[100010];
 
void testcase() {
    string s;
    cin >> s;
 
    string mask;
    bool ok = false;
    for(unsigned int i = 1; i < s.length(); i++) {
        if(s[i] == '0') {
            mask = s.substr(i);
            ok = true;
            break;
        }
    }
 
    if(!ok) {
        cout << 1 << " " << s.length() << " " << 1 << " " << 1 << endl;
        return;
    }
 
    for(unsigned int i = 0; i < mask.length(); i++) {
        if(mask[i] == '0') mask[i] = '1';
        else mask[i] = '0';
    }
 
    unsigned int maxPref = 0;
    int maxStart = -1;
    for(unsigned int i = 0; i + mask.length() <= s.length(); i++) {
        unsigned int j;
        for(j = 0; j < mask.length(); j++) {
            if(s[i+j] != mask[j]) break;
        }
        if(j > maxPref) {
            maxPref = j;
            maxStart = i;
        }
    }
 
    cout << 1 << " " << s.length() << " " << maxStart + 1 << " " << maxStart + mask.length() << endl;
}
 
int main() {
    int t;
    cin >> t;
 
    while(t--) testcase();
    
    return 0;
}