#include<bits/stdc++.h>
#define int long long
#define ms(v) memset(v, -1, sizeof v)
#define pb push_back
#define mp make_pair
#define sz size
#define ll long long int
#define pi pair <int,int>
#define itn int
#define fr first
#define sc second
#define srt(v) sort(v.begin(), v.end())
#define rvs(v) reverse(v.begin(), v.end())
#define mod 1000000007
#define INF 1e18
#define N 200010
 
using namespace std;
 
int n;
int v[N];
int dp[N];
vector <pi> sorted;
 
struct Segtree{
    int tree[4*N];
 
    int join(int a, int b){
        return max(a, b);
    }
 
    void build(int node, int l, int r){
        if(l == r){
            tree[node] = dp[l];
            return;
        }
 
        int mid = (l+r) >> 1;
        build(2*node, l, mid);
        build(2*node+1, mid+1, r);
 
        return;
    }
 
    void update(int node, int l, int r, int pos, int val){
        if(l == r){
            tree[node] = val;
            return;
        }
 
        int mid = (l+r) >> 1;
 
        if(l <= pos and pos <= mid) update(2*node, l, mid, pos, val);
        else update(2*node+1, mid+1, r, pos, val);
 
        tree[node] = join(tree[2*node], tree[2*node+1]);
 
        return;
    }
 
    int query(int node, int l, int r, int tl, int tr){
        if(l > r) return 0;
        if(l <= tl and r >= tr) return tree[node];
        if(tl > r or tr < l) return -INF;
 
        int mid = (tl+tr) >> 1;
 
        return join(query(2*node, l, r, tl, mid), query(2*node+1, l, r, mid+1, tr));
    }
 
} seg;
 
int32_t main(){
    ios::sync_with_stdio(false); cin.tie(0);
    
    cin >> n;
 
    for(int i = 1;i <= n;i++){
        cin >> v[i];
        sorted.pb({v[i], i});
    }
 
    map <int, int> m;
 
    srt(sorted);
 
    for(int i = 0;i < sorted.size();i++){
        m[sorted[i].fr] = i+1;
    }
 
    for(int i = 1;i <= n;i++){
        v[i] = m[v[i]];
    }
 
    seg.build(1, 1, n);
 
        // for(int i = 1;i <= n;i++){
        //     cout << v[i] << " ";
        // }
 
    for(int i = 1;i <= n;i++){
        dp[v[i]] = seg.query(1, 1, v[i]-1, 1, n)+1;
        seg.update(1, 1, n, v[i], dp[v[i]]);
    }
 
    cout << seg.query(1, 1, n, 1, n) << "\n";
 
    return 0;
}