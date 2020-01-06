/*
    Link - https://practice.geeksforgeeks.org/problems/job-sequencing-problem/0/?track=sp-greedy&batchId=152

    Problem - Job Sequencing Problem (Greedy Approach)

    Complexity - O(n^2)

    Sol - In this we sort the jobs according to their profit value and then we pick job 
          and put them in latest free slot.

          There is another approach also DSU.
*/
#include <bits/stdc++.h>
#define ll long long
#define fprint(v) for(auto x : v) cout << x << ' ';
using namespace std;
const int N = 1e5 + 2;
const int M = 1e9 + 7;
struct job{
    int id;
    int deadline;
    int profit;
};
void solve(){
    int n;
    cin >> n;
    vector<job> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i].id >> v[i].deadline >> v[i].profit;
    }

    sort(v.begin(), v.end(), [](const struct job &j1, const struct job &j2){
        return j1.profit > j2.profit;
    });

    vector<bool> slot(n, false);
    vector<int> result(n, 0);

    for(int i = 0; i < n; i++){
        for(int j = min(n, v[i].deadline) - 1; j >= 0; j--){
            if(!slot[j]){
                slot[j] = true;
                result[j] = i;
                break;
            }
        }
    }

    int profit = 0;
    int jobDone = 0;
    for(int i = 0; i < n; i++){
        if(slot[i]){
            jobDone++;
            profit += v[result[i]].profit;
        }
    }
    cout << jobDone << ' ' << profit;
}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
	return 0;
}
