/*
    Link - https://practice.geeksforgeeks.org/problems/job-sequencing-problem/0/?track=sp-greedy&batchId=152
    
    Problem - Job Sequencing Problem (Greedy Approach)
    
    Complexity - O(n)

    Sol - Using DSU. for explanantion read this 
            https://www.geeksforgeeks.org/job-sequencing-using-disjoint-set-union/

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
class Disjoint{
    int *parent;
public:
    Disjoint(int n){
        parent = new int[n + 1];
        for(int i = 0; i <= n; i++){
            parent[i] = i;
        }
    }
    int find(int s){
        if(s == parent[s]) return s;
        return parent[s] = find(parent[s]);
    }
    void merge(int u, int v){
        parent[v] = u;
    }
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
    int mxDeadline = 0;
    for(auto& x : v){
        mxDeadline = max(mxDeadline, x.deadline);
    }
    Disjoint ds(mxDeadline);
    int profit = 0;
    int jobDone = 0;
    for(int i = 0; i < n; i++){
        int availableSlot = ds.find(v[i].deadline);
        if(availableSlot > 0){
            ds.merge(ds.find(availableSlot - 1), availableSlot);
            jobDone++;
            profit += v[i].profit;

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
        cout << '\n';
    }
	return 0;
}
