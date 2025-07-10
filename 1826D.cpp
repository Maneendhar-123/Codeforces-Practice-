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
        vector<ll> a(n + 1);
        for(ll i = 1; i <= n; i++){
            cin >> a[i];
        }
        vector<ll> v1(n + 1, 0), v2(n + 1, 0), v3(n + 1, 0);
        ll m1 = 0, m2 = 0, m3 = 0;
        for(ll i = 1; i <= n; i++){
            v1[i] = max(v1[i - 1], a[i] + i);
        }
        for(ll i = 2; i <= n; i++){
            v2[i] = max(v2[i - 1], v1[i - 1] + a[i]);
        }
        for(ll i = 3; i <= n; i++){
            v3[i] = max(v3[i - 1], v2[i - 1] + a[i] - i);
        }
 
        cout << v3[n] << endl;
    }
    return 0;
}
