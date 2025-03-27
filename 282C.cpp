#include <bits/stdc++.h>
 
using namespace std;
using lli = unsigned long long int;
 
string s1, s2;
int n;
 
int main() {
    cin >> s1 >> s2;
 
    n = s1.size();
    
    if(s2.size() != n) {
        cout << "NO" << endl; 
        exit(0);
    }
 
    bool s1hasOne = false;
    for(char c : s1)  {
        if(c == '1') {
            s1hasOne = true;
            break;
        }
    }
 
    bool s2hasOne = false;
    for(char c : s2)  {
        if(c == '1') {
            s2hasOne = true;
            break;
        }
    }
 
    if((s1hasOne && s2hasOne) || (!s1hasOne && !s2hasOne)) cout << "YES" << endl;
    else cout << "NO" << endl;
 
    return 0;
}
