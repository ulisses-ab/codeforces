#include <bits/stdc++.h>
using namespace std;
 
string n;
 
void solve() {
    cin >> n;
    
    int sum = 0;
    int twos = 0;
    int threes = 0;
    
    for(int i = 0; i < n.size(); i++) {
        sum += n[i] - '0';
        if(n[i] == '2') twos++;
        if(n[i] == '3') threes++;
        sum %= 9;
    }
    
    //cout << sum << " " << twos << " " << threes << endl;
    
    int needed = sum;
    int twosneeded;
    if(needed == 2) twosneeded = 8;
    else if(needed == 4) twosneeded = 7;
    else if(needed == 6) twosneeded = 6;
    else if(needed == 8) twosneeded = 5;
    else if(needed == 1) twosneeded = 4;
    else if(needed == 3) twosneeded = 3;
    else if(needed == 5) twosneeded = 2;
    else if(needed == 7) twosneeded = 1;
    else twosneeded = 0;
    
    while(threes > 0 && twosneeded >= 3) {
        twosneeded -= 3;
        threes--;
    }
    
    if(twosneeded == 0) {
        cout << "YES" << endl;
        return;
    }
    
    if(twosneeded <= twos) {
        cout << "YES" << endl;
        return;
    }
    
    cout << "NO" << endl;
    
}
 
int main() {
    int t;
    cin >> t;
    
    while(t--) solve();
 
    return 0;
}