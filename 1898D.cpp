#include <bits/stdc++.h>
#include<vector>
using namespace std;
typedef long long ll;
 
ll mod(ll a, ll b){
    if(a > b) return a - b;
    return b - a;
}
 
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
        vector<ll> a(n), b(n);
        for(ll i = 0; i < n; i++){
            cin >> a[i];
        }
        ll sum = 0;
        ll ca = 0, cb = pow(10, 9), da = pow(10, 9), db = 0;
        for(ll i = 0; i < n; i++){
            cin >> b[i];
            sum += mod(a[i], b[i]);
            if(b[i] >= a[i]){
                ca = max(a[i], ca);
                cb = min(b[i], cb);
            }
            else{
                da = min(a[i], da);
                db = max(b[i], db);
            }
        }
        ll add_max = 0;
        add_max = max(add_max, ca - cb);
        add_max = max(add_max, db - da);
        add_max = max(add_max, db - cb);
        add_max = max(add_max, ca - da);
        cout << sum + 2 * add_max << endl;
    }
    return 0;
}
