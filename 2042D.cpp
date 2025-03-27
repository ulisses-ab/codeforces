#include <bits/stdc++.h>
 
using namespace std;
 
int n;
int maxLeft[200010];
int minRight[200010];
int rsize[200010];
 
struct user {
    int i, left, right;
};
 
bool cmp(user u1, user u2) {
    if(u1.left == u2.left) return u1.right > u2.right;
    return u1.left < u2.left;
}
 
void mergesort(vector<user>& v, int l, int r) {
    if(l == r) return;
    
    int m = (l + r) / 2;
    
    mergesort(v, l, m);
    mergesort(v, m + 1, r);
    
    vector<user> v1(m - l + 1), v2(r - m);
    for(int i = l, j = 0; i <= m; i++, j++) v1[j] = v[i];
    for(int i = m + 1, j = 0; i <= r; i++, j++) v2[j] = v[i];
    
    vector<int> lv(m - l + 1), rv(m - l + 1);
    lv[m - l] = v1[m - l].left;
    rv[m - l] = v1[m - l].right;
    for(int i = m - l - 1; i >= 0; i--) {
        lv[i] = max(v1[i].left, lv[i + 1]);
        rv[i] = min(v1[i].right, rv[i + 1]);
    }
    
    int p1 = 0, p2 = 0, p = l;
    while(p1 < v1.size() && p2 < v2.size()) {
        if(v1[p1].right < v2[p2].right) {
            v[p] = v1[p1];
            p1++;
        }
        else {
            v[p] = v2[p2];
            maxLeft[v2[p2].i] = max(maxLeft[v2[p2].i], lv[p1]);
            minRight[v2[p2].i] = min(minRight[v2[p2].i], rv[p1]);
            
            if(v1[p1].left == v2[p2].left && v1[p1].right == v2[p2].right) {
                maxLeft[v2[p2].i] = max(maxLeft[v1[p1].i], maxLeft[v2[p2].i]);
                minRight[v2[p2].i] = min(minRight[v1[p1].i], minRight[v2[p2].i]);
                
                maxLeft[v1[p1].i] = maxLeft[v2[p2].i];
                minRight[v1[p1].i] =  minRight[v2[p2].i];
            }
            
            p2++;
        }
        
        p++;
    }
    
    while(p1 < v1.size()) {
        v[p] = v1[p1];
        p1++;
        p++;
    }
    
    while(p2 < v2.size()) {
        v[p] = v2[p2];
        p2++;
        p++;
    }
}
 
void solve() {
    cin >> n;
    
    vector<user> v(n);
    for(int i = 0; i < n; i++) {
        v[i].i = i;
        cin >> v[i].left >> v[i].right;
        rsize[i] = v[i].right - v[i].left;
    }
    
    sort(v.begin(), v.end(), cmp);
    
    for(int i = 0; i < n; i++) {
        maxLeft[i] = -2000000000;
        minRight[i] = 2000000000;
    }
    
    mergesort(v, 0, n - 1);
    
    for(int i = 0; i < n; i++) {
        if(maxLeft[i] == -2000000000) cout << 0 << endl;
        else cout << minRight[i] - maxLeft[i] - rsize[i] << endl;
    }
}
 
int main() {
    int t;
    cin >> t;
    
    while(t--) solve();
    
    return 0;
}