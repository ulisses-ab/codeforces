#include <bits/stdc++.h>
 
using namespace std;
using ll = long long int;
 
int n, k, l;
 
int scarecrows[200010];
 
struct Instant {
    int time, pos;
};
 
Instant meet(Instant instant, int pos) {
    if(pos < instant.pos) {
        pos = min(instant.pos, pos += instant.time);
        return {instant.time, max(instant.pos, pos + k)};
    }
 
    pos -= instant.time;
 
    if(pos <= instant.pos) return {instant.time, instant.pos + k};
 
    int time = (pos - instant.pos) / 2;
    return {instant.time + time, instant.pos + time + k};
}
 
void testcase() {
    cin >> n >> k >> l;
    k*= 2; l *= 2;
 
    for(int i = 0; i < n; i++) {
        cin >> scarecrows[i];
        scarecrows[i] *= 2;
    }
 
    Instant current = {scarecrows[0], k};
    int minTime = 1000000000;
    for(int i = 1; i < n; i++) {
        //cout << current.time << "/" << current.pos << endl;
        current = meet(current, scarecrows[i]);
        minTime = min(minTime, current.time + max((l - current.pos), 0));
    } 
    //cout << current.time << "/" << current.pos << endl;
 
    cout << min(minTime, current.time + max((l - current.pos), 0)) << endl;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); std::cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) testcase();
}
