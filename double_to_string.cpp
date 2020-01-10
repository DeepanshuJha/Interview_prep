#include <bits/stdc++.h>
#define ll long long
#define fprint(v) for(auto x : v) cout << x << ' ';
using namespace std;
const int N = 1e5 + 2;
const int M = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    double x = 22.0 / 7.0;
    stringstream ret;
    ret << fixed << setprecision(9) << x; // specify precision value in place of 9
    string retString;
    while(ret >> retString);
    cout << retString;
	return 0;
}
