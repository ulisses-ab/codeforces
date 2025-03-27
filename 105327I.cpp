#include <bits/stdc++.h>
 
using namespace std;
using lli = unsigned long long int;
 
int n, q;
unordered_map<int, int> m;
int twoToThe[1000010];
vector<int> vfactor[1000010];
 
void count2(int c, const vector<int> &v, int pos, int amount, int& conf) {
    if(pos == v.size()) {
        if(c == 1) return;
        if(amount % 2 == 0) {
            conf -= m[c];
        }
        else {
            conf += m[c];
        }
        return;
    }
 
    count2(c * v[pos], v, pos + 1, amount + 1, conf);
    count2(c, v, pos + 1, amount, conf);
}
 
void count(int c, const vector<int> &v, int pos) {
    if(pos == v.size()) {
        m[c]++;
        return;
    }
    count(c * v[pos], v, pos + 1);
    count(c, v, pos + 1);
}
 
vector<int> factor(int x) {
    if(x == 1) return {};
    if(vfactor[x].size() > 0) return vfactor[x];
 
    int ox = x;
 
    if(x % 2 == 0) vfactor[ox].push_back(2);
    while(x % 2 == 0) {
        x /= 2;
    }   
    for(int i = 3; i * i <= x; i+= 2) {
        if(x % i == 0) vfactor[ox].push_back(i);
        while(x % i == 0) {
            x /= i;
        }
    }
 
    if(x != 1) vfactor[ox].push_back(x);
 
    return vfactor[ox];
}
 
int main() {
    cin >> n;
 
    twoToThe[0] = 1;
    lli total = 1;
    for(int i = 1; i <= n; i++) {
        twoToThe[i] = (2 * twoToThe[i - 1]) % 1000000007;
    }
 
    for(int i = 0; i < n; i++) {
        int ai;
        cin >> ai;
 
        vector<int> v = factor(ai);
 
        count(1, v, 0);
    }
 
    cin >> q;
 
    for(int i = 0; i < q; i++) {
        int qi;
        cin >> qi;
 
        vector<int> v = factor(qi);
        int conf = 0;
 
        count2(1, v, 0, 0, conf);
 
        int valid = n - conf;
        if(valid == 0) {
            cout << 1 << endl;
            continue;
        }
 
        cout << twoToThe[valid] << endl;
    }
    return 0;
}