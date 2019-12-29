#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 1;
const int M = 1e9 + 7;
void heapify(vector<int>& v, int sz, int parent){
    int left = 2 * parent + 1;
    int right = 2 * parent + 2;
    int mmax = parent;

    if(left < sz && v[mmax] < v[left]) mmax = left;
    if(right < sz && v[mmax] < v[right]) mmax = right;

    if(mmax != parent){
        swap(v[mmax], v[parent]);
        heapify(v, sz, mmax);
    }
}
void heap_sort(vector<int>& v){
    int n = v.size();
    for(int i = n / 2 - 1; i >= 0; i--){
        heapify(v, n, i);
    }
    
    for(int i = n - 1; i >= 0; i--){
        swap(v[0], v[i]);
        heapify(v, i, 0);
    }
}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    heap_sort(v);
    for(auto x : v) cout << x << ' ';
	return 0;
}
