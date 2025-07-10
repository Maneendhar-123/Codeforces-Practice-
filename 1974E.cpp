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
        ll m, x;
        cin >> m >> x;
        vector<ll> c(m), h(m);
        ll max_h = 0;
        for(ll i = 0; i < m; i++){
            cin >> c[i] >> h[i];
            max_h += h[i];
        }
        max_h -= h[0];
        ll sum = x;
        vector<ll> vec(max_h + 1, INT64_MAX);
        vec[0] = 0;
        for(ll i = 1; i < m; i++){
            for(ll j = max_h; j >= 0; j--){
                if(vec[j] + c[i] <= sum && vec[j] != INT64_MAX){
                    vec[j + h[i]] = min(vec[j + h[i]], vec[j] + c[i]);
                }
            }
            sum += x;
        }
        ll ans = 0;
        for(ll i = max_h; i >= 0; i--){
            if(vec[i] != INT64_MAX){
                ans = i;
                break;
            }
        }
        if(c[0] == 0){
            ans += h[0];
        }
        cout << ans << endl;
    }
    return 0;
}
