#include <iostream>
 
using ll = long long;
using namespace std;
 
int n;
int c[26];
 
void testcase() {
    cin >> n;
    string s;
    cin >> s;
    
    for(int i = 0; i < 26; i++) c[i] = 0;
    
    for(int i = 0; i < n; i++) {
        c[s[i] - 'a']++;
    }
    
    int mx = 0;
    int mxi = -1;
    int mn = 10000000;
    int mni = -1;
    for(int i = 0; i < 26; i++) {
        if(c[i] > mx) {
            mx = c[i];
            mxi = i;
        }
        if(c[i] <= mn && c[i] != 0) {
            mn = c[i];
            mni = i;
        }
    }
    
 
    
    int ai = -1, bi = -1;
    for(int i = 0; i < n; i++) {
        if(s[i] - 'a' == mni) {
            ai = i;
            break;
        }
    }
 
    
    for(int i = 0; i < n; i++) {
        if(s[i] - 'a' == mxi) {
            bi = i;
            break;
        }
    }
    
    s[ai] = mxi + 'a';
    
    cout << s << endl;
}
 
int main() {
    int t;
    cin >> t;
    
    while(t--) testcase();
    return 0;
}
