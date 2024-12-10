#include <bits/stdc++.h>
// /opt/lampp
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

void solve(){
    int n, m, st, lft, speed;
    cin >> n>>m>>st>>lft>>speed;
    vector<int> stair(st), lift(lft);
    for(auto &i:stair) cin>>i;
    for(auto &i:lift) cin>>i;

    sort(all(stair));
    sort(all(lift));


    auto check_left = [&](vector<int> &v, int x) -> ll{
        if(v.empty()) return -1;
        ll l = 0, r = v.size()-1, ans = -1;
        while(l<=r){
            ll mid = l+(r-l)/2;
            if(v[mid]<=x){
                ans = mid;
                l = mid+1;
            }else r = mid-1;
        }
        return (ans!=-1)?v[ans]:-1;
    };

    auto check_right = [&](vector<int> &v, int x) -> ll{
        if(v.empty()) return -1;
        ll l = 0, r = v.size()-1, ans = -1;
        while(l<=r){
            ll mid = l+(r-l)/2;
            if(v[mid]>=x){
                ans = mid;
                r = mid-1;
            }else l = mid+1;
        }
        return (ans!=-1)?v[ans]:-1;
    };

    auto time_st = [&](int x1, int y1, int x2, int y2) -> ll{
        ll left = check_left(stair, y1);
        ll right = check_right(stair, y1);

        ll ans = INT_MAX;
        if(left!=-1){
            ans = min(ans, abs(y1-left)+abs(x2-x1)+abs(y2-left));
        }if(right != -1){
            ans = min(ans, abs(y1-right)+abs(x2-x1)+abs(y2-right));
        }
        return ans;
    };

    auto time_lift = [&](int x1, int y1, int x2, int y2) -> ll{
        ll left = check_left(lift, y1);
        ll right = check_right(lift, y1);

        ll ans = INT_MAX;
        if(left!=-1){
            ans = min(ans, abs(y1-left)+(ll)ceil((double)(abs(x2-x1))/(double)speed)+abs(y2-left));
        }if(right != -1){
            ans = min(ans, abs(y1-right)+(ll)ceil((double)(abs(x2-x1))/(double)speed)+abs(y2-right));
        }
        return ans;
    };

    int q; cin>>q;
    while(q--){
        int x1, y1, x2, y2;
        cin>>x1>>y1>>x2>>y2;

        cout<<min(time_st(x1, y1, x2, y2), time_lift(x1, y1, x2, y2))<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int _ = 1;
    while(_--){
        solve();
    }
    return 0;
}
