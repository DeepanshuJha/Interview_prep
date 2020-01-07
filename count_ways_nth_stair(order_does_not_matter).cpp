/*
    Link - https://practice.geeksforgeeks.org/problems/count-ways-to-nth-stairorder-does-not-matter/0/?track=sp-dynamic-programming&batchId=152

    Problem - There are N stairs, and a person standing at the bottom wants to 
            reach the top. The person can climb either 1 stair or 2 stairs at a time. 
            Count the number of ways, the person can reach the top (order does not matter).

    Approach - dp[0] = 1; means no stairs
                dp[1] = 1; means reach first stair
                
                dp[i] = min(dp[i - 1], dp[i - 2]) + 1;

                either using 1 jumps or using 2 jumps + 1 reach ith stair
            
    Complexity - O(n);

*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 2;
const int M = 1e9 + 7;
int dp[N];
void pre(){
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i <= N; i++){
        dp[i] = min(dp[i - 1], dp[i - 2]) + 1;
    }
}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    pre();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << dp[n] << '\n';
    }
	return 0;
}