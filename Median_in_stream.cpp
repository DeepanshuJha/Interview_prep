#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 2;
const int M = 1e9 + 7;
int left(int i){
    return (2 * i + 1);
}
int right(int i){
    return (2 * i + 2);
}
int parent(int i){
    return (i - 1) / 2;
}
void insert_max(vector<int> &v, int x){
    v.push_back(x);
    int n = v.size();
    int idx = n - 1;
    while(idx >= 0 && v[idx] > v[parent(idx)]){
        swap(v[idx], v[parent(idx)]);
        idx = parent(idx);
    }
}
void insert_min(vector<int> &v, int x){
    v.push_back(x);
    int n = v.size();
    int idx = n - 1;
    while(idx >= 0 && v[idx] < v[parent(idx)]){
        swap(v[idx], v[parent(idx)]);
        idx = parent(idx);
    }
}
void heapify_max(vector<int> &v, int idx){
    int n = v.size();

    int l = left(idx);
    int r = right(idx);
    int mx = idx;
    if(l < n && v[mx] < v[l]) mx = l;
    if(r < n && v[mx] < v[r]) mx = r;

    if(mx != idx){
        swap(v[idx], v[mx]);
        heapify_max(v, mx);
    }
}
void heapify_min(vector<int> &v, int idx){
    int n = v.size();

    int l = left(idx);
    int r = right(idx);
    int mn = idx;
    if(l < n && v[mn] > v[l]) mn = l;
    if(r < n && v[mn] > v[r]) mn = r;

    if(mn != idx){
        swap(v[mn], v[idx]);
        heapify_min(v, mn);
    }
}
int remove_max(vector<int> &v){
    int n = v.size();
    if(n == 0) return -1;

    int top = v[0];
    swap(v[0], v[n - 1]);
    v.pop_back();
    heapify_max(v, 0);
    return top;
}
int remove_min(vector<int> &v){
    int n = v.size();
    if(n == 0) return -1;

    int top = v[0];
    swap(v[0], v[n - 1]);
    v.pop_back();
    heapify_min(v, 0);
    return top;
}
inline void print(int x){
    cout << "Median : " << x << endl;
}
inline int sz(vector<int> &v){
    return v.size();
}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    vector<int> max_heap, min_heap;
    double median = 0;
    int n;
    cin >> n;
    cin >> median;
    print(median);
    insert_max(max_heap, median);
    for(int i = 0; i < n - 1; i++){
        double x;
        cin >> x;
        if(sz(max_heap) > sz(min_heap)){
            if(x < median){
                int top = remove_max(max_heap);
                insert_min(min_heap, top);
                insert_max(max_heap, x);
            }else{
                insert_min(min_heap, x);
            }
            median = (max_heap[0] + min_heap[0]) / 2.0;
            print(median);
        }else if(sz(max_heap) == sz(min_heap)){
            if(x < median){
                insert_max(max_heap, x);
                median = max_heap[0];
            }else{
                insert_min(min_heap, x);
                median = min_heap[0];
            }
            print(median);
        }else{
            if(x < median){
                insert_max(max_heap, x);
            }else{
                int top = remove_min(min_heap);
                insert_max(max_heap, top);
                insert_min(min_heap, x);
            }
            median = (max_heap[0] + min_heap[0]) / 2.0;
            print(median);
        }
    }
	return 0;
}
