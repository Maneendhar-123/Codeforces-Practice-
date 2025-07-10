#include <bits/stdc++.h>
#include<vector>
using namespace std;
typedef long long ll;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    ll tt;
    cin >> tt;
    while (tt--) {
        ll n;
        cin >> n;
        ll a[n], b[n], sum_sq = 0, sum_tot = 0;
        for(ll i = 0; i < n; i++){
            cin >> a[i];
            sum_tot += a[i];
            sum_sq += a[i] * a[i];
        }
        for(ll i = 0; i < n; i++){
            cin >> b[i];
            sum_tot += b[i];
            sum_sq += b[i] * b[i];
        }
 
        vector<ll> vec(sum_tot + 1, -1);
        vec[0] = 0;
        for(ll i = 0; i < n; i++){
            for(ll j = sum_tot; j >= 0; j--){
                if(vec[j] == i){
                    vec[j + a[i]] = i + 1;
                    vec[j + b[i]] = i + 1;
                }
            }
        }
 
        ll ma = 0, mi = 0;
        for(ll i = sum_tot / 2; i >= 0; i--){
            if(vec[i] == n){
                mi = i;
                break;
            }
        }
        for(ll i = sum_tot / 2; i <= sum_tot; i++){
            if(vec[i] == n){
                ma = i;
                break;
            }
        }
        
        ll m1 = (mi * mi) + ((sum_tot - mi) * (sum_tot - mi));
        ll m2 = (ma * ma) + ((sum_tot - ma) * (sum_tot - ma));
        ll ans = ((n - 2) * sum_sq) + min(m1, m2);
        cout << ans << endl;
    }
    return 0;
}
