#include <bits/stdc++.h>
 
using namespace std;
using ll = long long int;
 
void testcase() {
    string s;
    cin >> s;
 
    int total = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '1') total++;
    }
 
    cout << total << endl;
}
 
int main() {
    int t;
    cin >> t;
    
    while(t--) testcase();
    return 0;
}