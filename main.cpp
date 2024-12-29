#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using lld = long double;
using pii = pair<int,int>;
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
    ll n, k;
    cin>>n>>k;

    int l = INT_MAX, r = INT_MIN;

    vector<pair<int, pii>> a(n);
    for(auto &i:a){
        cin>>i.ff>>i.ss.ff>>i.ss.ss;
        l = min(l, i.ff);
        r = max(l, i.ff);
    }

    auto check = [&](int x)->bool{
        multimap<int,int> recive;
        for(auto i:a) recive.insert({i.ss.ss, i.ff}); // Recive_cost , numberOfBattires 
        ll cost = 0;

        auto it = recive.begin();

        auto find_Recive = [&](int need)->bool{
            while(it!=recive.end() && need>0){
                if(it->ss>=x) it++;

                int find_min = min(x-it->ss, need);
                need -= find_min;
                it->ss += find_min;
                cost += find_min*1ll*it->ff;
            }
            return need==0;
        };

        for(auto i:a){
            if(i.ff>x){
                cost += (i.ff-x)*1ll*i.ss.ff;
                // auto its = recive.find({i.ss.ss, i.ff});
                // its.ss = x;
                bool f = find_Recive(i.ff-x);
                if(!f) return false;
            }
        }
        return cost<=k;
    };

    int ans = INT_MAX; // Find the smallest M.

    while(l<=r){
        int mid = l+(r-l)/2;
        if(check(mid)){
            ans = mid;
            r = mid-1;
        }else l = mid+1;
    }
    cout<<ans<<endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
    // cout<<std::setprecision(35);
    
    int _ = 1;
    while(_--){
        solve();
    }
    return 0;
}
