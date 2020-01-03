/*
    Link - https://practice.geeksforgeeks.org/problems/minimum-shift-for-longest-common-prefix/0/?track=sp-strings&batchId=152

    Problem - Find LCP

    Sol - Using Hashing (Rabin Karp) and Binary Search

    Complexity - O(n + m + nlog(m)) -> O(nlog(m))
    Space - O(n + m);
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 2;
const int M = 1e9 + 7;
const int K1 = 29;
ll po[N];
ll mul(ll a, ll b){
    return (a % M) * (b % M) % M;
}
ll sub(ll a, ll b){
    return ((a % M) - (b % M) + M) % M;
}
void pre(){
    po[0] = 1;
    for(int i = 1; i < N; i++){
        po[i] = po[i - 1] * K1 % M;
    }
}
bool check(int n, ll h[],ll ph[], int len){
    ll key = ph[len];
    if(h[len] == key) return true;
    for(int i = len + 1; i <= n; i++){
        ll x = sub(h[i], mul(h[i - len], po[len]));
        if(x == key) return true;
    }
    return false;
}
void solve(){
    string p, s;
    cin >> p >> s;
    int n = s.size();
    ll h[n + 1];
    h[0] = 0;
    for(int i = 1; i <= n; i++){
        h[i] = mul(h[i - 1], K1) + int(s[i - 1] - 'a') + 1;
        h[i] %= M;
    }
    int m = p.size();
    ll ph[m + 1];
    ph[0] = 0;
    for(int i = 1; i <= m; i++){
        ph[i] = mul(ph[i - 1], K1) + int(p[i - 1] - 'a') + 1;
        ph[i] %= M;
    }
    int lo = -1, hi = m + 1;
    while(hi - lo > 1){
        int mid = lo + hi >> 1;
        if(check(n, h, ph, mid)) lo = mid;
        else hi = mid;
    }
    if(lo > 0){ 
        string pre = p.substr(0, lo);
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(s.substr(i, lo) == pre){
                ans = i;
                break;
            }
        }
        cout << ans << ' ' << pre << '\n';
    }else cout << -1 << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    pre();
    int t;
    cin >> t;
    while(t--){
        solve();
    }
	return 0;
}
