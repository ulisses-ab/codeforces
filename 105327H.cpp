#include <bits/stdc++.h>
 
using namespace std;
 
string m_, n_;
bool m[500];
int n;
int twoToThirtyModN;
 
 
void printInt(int x) {
    if(x == 0) {
        cout << 0 << endl;
        return;
    }
    string s = "";
    for(int i = 0; x >> i > 0; i++) {
        s += ((x >> i) & 1) + '0';
    }
    
    for(int i = s.size()-1; i >= 0; i--) {
        cout << s[i];
    }
    
    cout << endl;
}
 
int makeInt(int a, int b) {
    if(a > b) return 0;
    int x = 0;
    for(int i = 0; i <= b-a; i++) {
        x <<= 1;
        x += m[a + i];
    }
    
    return x;
}
 
int power(int x, int a) {
    int p = 1;
    for(int i = 0; i < a; i++) {
        p *= x;
        p %= n;
    }
    
    return p;
}
 
void checkDivisibility() {
    int a, b;
    
    int r = 0;
    for(a = 0, b = 14; b < m_.size(); a+= 15, b += 15) {
        r = (makeInt(a, b) + (r << 15)) % n;
    }
    
    r = (makeInt(a, m_.size() - 1) + (r << (m_.size() - a))) % n;
    
    if(r == 0) {
        for(int i = 0; i < m_.size(); i++) {
            cout << m[i];
        }
        cout << endl;
        exit(0);
    }
}
 
void checkN(int place) {
    if(place == n_.size()) {
        checkDivisibility();
        return;
    }
    if(n_[place] == '1') {
        n <<= 1;
        n += 1;
        checkN(place + 1);
        n >>= 1;
    }
    else if(n_[place] == '0') {
        n <<= 1;
        checkN(place + 1);
        n >>= 1;
    }
    else {
        n <<= 1;
        checkN(place + 1);
        n += 1;
        checkN(place + 1);
        n>>=1;
    }
}
 
void checkM(int place) {
    if(place == m_.size()) {
        checkN(0);
        return;
    }
    if(m_[place] == '1') {
        m[place] = true;
        checkM(place + 1);
    }
    else if(m_[place] == '0') {
        m[place] = false;
        checkM(place + 1);
    }
    else {
        m[place] = true;
        checkM(place + 1);
        m[place] = false;
        checkM(place + 1);
    }
}
 
int main()
{
    cin >> m_ >> n_;
    n = 0;
 
    checkM(0);
 
    return 0;
}