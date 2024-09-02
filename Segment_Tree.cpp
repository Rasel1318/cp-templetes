#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using pii = pair<ll,ll>;
using vi = vector<ll>;
using vii = vector<pii>;

#define mod 1000000007
#define INF 1e9
#define all(x) x.begin(), x.end()
#define rep(i, j, n) for(int i=(j);i<(n);++i)
#define repA(i,j,n) for(ll i=(j);i<=(n);++i)
#define repD(i,j,n) for(ll i=(j);i>=(n);--i)
#define sz(x) ((ll)(x).size())
#define pb push_back
#define ff first
#define ss second

class sgTree{
    vi seg;
public:
    sgTree(int n){
        seg.resize(4*n+1);
    }
    void build(int ind, int low, int high, vi &arr){
        if(low==high){
            seg[ind]=arr[low];
            return;
        }
        int mid = (low+high)>>1;
        build(2*ind+1, low, mid, arr);
        build(2*ind+2, mid+1, high, arr);
        // Change it
        seg[ind] = min(seg[2*ind+1], seg[2*ind+2]);
    }
    int query(int ind, int low, int high, int l, int r){
        if(l>high || r<low) return INT_MAX;
        if(low>=l && high<=r) return seg[ind];

        int mid = (low+high)>>1;
        int lft = query(2*ind+1, low, mid, l, r);
        int rgt = query(2*ind+2, mid+1, high, l, r);
        return min(lft, rgt);
    }
    void update(int ind, int low, int high, int i, int val){
        if(low==high) {
            seg[ind] = val;
            return;
        }
        int mid = (low+high)>>1;
        if(i<=mid) update(2*ind+1, low, mid, i, val);
        else update(2*ind+2, mid+1, high, i, val);
        seg[ind] = min(seg[2*ind+1], seg[2*ind+2]);
    }
    void pr(void){
        for(auto i:seg) cout<<i<<" "; cout<<endl;
    }
};

void solve(){
    int n;
    cin >> n;
    vi arr(n);
    for(auto &i:arr) cin>>i;

    sgTree seg1 = sgTree(n);
    seg1.build(0, 0, n-1, arr);
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int _ = 1;
    cin >> _;
    while(_--){
        solve();
    }
    return 0;
}
