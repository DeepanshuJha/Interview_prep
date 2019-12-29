#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 2;
const int M = 1e9 + 7;
string conv(int n){
    string res;
    if(n == 0) return "0";
    while(n > 0){
        int r = n % 10;
        char x = r + '0';
        res += x;
        n /= 10;
    }
    reverse(res.begin(), res.end());
    return res;
}
void solve(int n, int d){
    map<int, int> mp;

    int rem = n % d;
    string s;
    while(rem != 0 && mp.find(rem) == mp.end()){
        mp[rem] = s.length();
        rem *= 10;

        int res = rem / d;
        s += conv(res);

        rem = rem % d;
    }   
    if(rem != 0){
        if(mp[rem] != 0) cout << n / d << "." << s.substr(0, mp[rem]) << "(" << s.substr(mp[rem]) << ")";
        else cout << n / d << ".(" << s.substr(0) << ")";
    }
    else cout << n / d;
    cout << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, d;
        cin >> n >> d;
        solve(n, d);
    }
	return 0;
}
