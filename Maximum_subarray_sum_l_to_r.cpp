#include <bits/stdc++.h>
#define ll long long
#define fprint(v) for(auto x : v) cout << x << ' ';
using namespace std;
const int M = 1e9 + 7;
const int N = 3e5 + 2;
struct yo{
    ll prefMax, sufMax, sum, ans;
};
yo tree[N << 2];
ll a[N];
void build(int node, int st, int end){
    if(st == end){
        tree[node].prefMax = tree[node].sufMax = tree[node].ans = max(0LL, a[st]);
        tree[node].sum = a[st];
        return;
    }
    int mid = st + end >> 1;
    build(node << 1, st, mid);
    build((node << 1) | 1, mid + 1, end);
    yo t;
    t.sum = tree[node << 1].sum + tree[(node << 1) | 1].sum;
    t.prefMax = max(tree[node << 1].prefMax, tree[node << 1].sum + tree[(node << 1) | 1].prefMax);
    t.sufMax = max(tree[node << 1].sufMax + tree[(node << 1) | 1].sum, tree[(node << 1) | 1].sufMax);
    t.ans = max({t.sum, t.prefMax, t.sufMax, tree[node << 1].sufMax + tree[(node << 1) | 1].prefMax, tree[node << 1].ans, tree[(node << 1) | 1].ans});
    tree[node] = t;
}

void update(int node, int st, int end, int val, int idx){
    if(st == end){
        tree[node].prefMax = tree[node].sufMax = tree[node].ans = max(0, val);
        tree[node].sum = val;
        return;
    }
    int mid = st + end >> 1;
    if(idx <= mid){
        update(node << 1, val, idx, st, mid);
    }else{
        update((node << 1) | 1, val, idx, mid + 1, end);
    }
    yo t;
    t.sum = tree[node << 1].sum + tree[(node << 1) | 1].sum;
    t.prefMax = max(tree[node << 1].prefMax, tree[node << 1].sum + tree[(node << 1) | 1].prefMax);
    t.sufMax = max(tree[node << 1].sufMax + tree[(node << 1) | 1].sum, tree[(node << 1) | 1].sufMax);
    t.ans = max({t.sum, t.prefMax, t.sufMax, tree[node << 1].sufMax + tree[(node << 1) | 1].prefMax, tree[node << 1].ans, tree[(node << 1) | 1].ans});
    tree[node] = t;
}

yo khali;

yo query(int node, int st, int end, int l, int r){
    if(st > end || r < st || l > end){
        return khali;
    }
    if(l <= st && r >= end){
        return tree[node];
    }
    int mid = st + end >> 1;
    yo lft = query(node << 1, st, mid, l, r);
    yo right = query((node << 1) | 1, mid + 1, end, l, r);
    yo t;
    t.sum = lft.sum + right.sum;
    t.prefMax = max(lft.prefMax, lft.sum + right.prefMax);
    t.sufMax = max(right.sufMax, lft.sufMax + right.sum);
    t.ans = max({t.sum, t.prefMax, t.sufMax, lft.sufMax + right.prefMax, lft.ans, right.ans});
    return t;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    build(1, 1, n);

    for(int i = 1; i <= 10; i++) cout << tree[i].ans << ' ';
    cout << endl;

    int q;
    cin >> q;
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int l, r;
            cin >> l >> r;
            yo q = query(1, 1, n, l, r);
            cout << q.ans << '\n';
        }else{
            int idx, val;
            cin >> idx >> val;
            update(1, 1, n, idx, val);
        }
    }
	return 0;
}
