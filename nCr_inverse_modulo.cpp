#include <bits/stdc++.h>
#define ll long long
#define fprint(v) for(auto x : v) cout << x << ' ';
using namespace std;
const int N = 1e5 + 2;
const int M = 1e9 + 7;
ll mul(ll a, ll b){
    return ((a % M) * (b % M)) % M;
}
ll fact[N];
ll inv[N];
void pre(){
    fact[0] = fact[1] = 1;
    inv[0] = inv[1] = 1;
    for(int i = 2; i < N; i++) fact[i] = (fact[i - 1] * i) % M;
    for(int i = 2; i < N; i++) inv[i] = (M - (M / i) * inv[M % i] % M) % M;
    for(int i = 2; i < N; i++) inv[i] = (inv[i] * inv[i - 1]) % M;
}
ll nCr(int n, int r){
    return mul(fact[n], mul(inv[r], inv[n - r]));
}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    pre();
    int n, r;
    cin >> n >> r;
    cout << nCr(n, r);
	return 0;
}
