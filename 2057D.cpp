#include <bits/stdc++.h>
 
using namespace std;
using ll = long long int;
 
ll a[200010];
 
 
struct Seg {
    ll best, maxLeft, maxLeftDist, minLeft, minLeftDist, maxRight, maxRightDist, minRight, minRightDist, size;
};
 
Seg tree[800010];
 
Seg merge(Seg s1, Seg s2) {
    if(s1.size == -1) return s2;
    if(s2.size == -1) return s1;
    
    Seg s;
    
    s.best = max(   
                    max(    
                        s1.maxRight - s2.minLeft - (s1.maxRightDist + s2.minLeftDist) + 1,
                        s2.maxLeft - s1.minRight - (s1.minRightDist + s2.maxLeftDist) + 1
                    ), 
                    max(s1.best, s2.best)
             );
    
    if(s2.maxLeft - s1.maxLeft > s1.size - s1.maxLeftDist + s2.maxLeftDist) {
        s.maxLeft = s2.maxLeft;
        s.maxLeftDist = s2.maxLeftDist + s1.size;
    }
    else {
        s.maxLeft = s1.maxLeft;
        s.maxLeftDist = s1.maxLeftDist;
    }
    
    if(s1.minLeft - s2.minLeft > s1.size - s1.minLeftDist + s2.minLeftDist) {
        s.minLeft = s2.minLeft;
        s.minLeftDist = s2.minLeftDist + s1.size;
    }
    else {
        s.minLeft = s1.minLeft;
        s.minLeftDist = s1.minLeftDist;
    }
    
    if(s2.minRight - s1.minRight > s2.size - s2.minRightDist + s1.minRightDist) {
        s.minRight = s1.minRight;
        s.minRightDist = s1.minRightDist + s2.size;
    }
    else {
        s.minRight = s2.minRight;
        s.minRightDist = s2.minRightDist;
    }
    
    if(s1.maxRight - s2.maxRight > s2.size - s2.maxRightDist + s1.maxRightDist) {
        s.maxRight = s1.maxRight;
        s.maxRightDist = s1.maxRightDist + s2.size;
    }
    else {
        s.maxRight = s2.maxRight;
        s.maxRightDist = s2.maxRightDist;
    }
    
    s.size = s1.size + s2.size;
    
    return s;
}
 
Seg build(ll p, ll l, ll r) {
    if(l == r) return tree[p] = {0, a[l], 1, a[l], 1, a[l], 1, a[l], 1, 1};
    
    ll m = (l + r) / 2;
    
    Seg s1 = build((2 * p) + 1, l, m);
    Seg s2 = build((2 * p) + 2, m + 1, r);
 
    return tree[p] = merge(s1, s2);
}
 
Seg update(ll p, ll l, ll r, ll d, ll v) {
    if(d < l || r < d) return tree[p];
    if(l == r) {
        a[l] = v;
        return tree[p] = {0, a[l], 1, a[l], 1, a[l], 1, a[l], 1, 1};
    }
    
    ll m = (l + r) / 2;
    
    Seg s1 = update((2 * p) + 1, l, m, d, v);
    Seg s2 = update((2 * p) + 2, m + 1, r, d, v);
    
    return tree[p] = merge(s1, s2);
}
 
Seg query(ll p, ll l, ll r, ll a, ll b) {
    if(b < l || r < a) {
        Seg s;
        s.size = -1;
        return s;
    }
    
    if(a <= l && r <= b) return tree[p];
    
    ll m = (l + r) / 2;
    
    Seg s1 = query((2 * p) + 1, l, m, a, b);
    Seg s2 = query((2 * p) + 2 , m + 1, r, a, b);
    
    return merge(s1, s2);
}
 
void print() {
    ll p = 0;
    for(ll i = 1; i <= 8; i *= 2) {
        for(ll j = 0; j < i; j++) {
            cout << tree[p].best << "/" << tree[p].maxRight << "/" << tree[p].minRight << 
            "/" << tree[p].maxLeft << "/" << tree[p].minLeft << "/" << tree[p].size << "   ";
            p++;
        }
        cout << endl;
    }
}
 
void testcase() {
    ll n, q;
    cin >> n >> q;
    
    for(ll i = 0; i < n; i++) cin >> a[i];
    
    cout << build(0, 0, n - 1).best << endl;
    
 
    while(q--) {
        ll p, x;
        cin >> p >> x;
        p--;
        cout << update(0, 0, n - 1, p, x).best << endl;
    }
}
 
int main()
{
    ll t;
    cin >> t;
    while(t--) testcase();
 
    return 0;
}