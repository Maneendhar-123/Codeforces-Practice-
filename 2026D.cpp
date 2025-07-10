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
 
    ll n;
    cin >> n;
    vector<ll> a(n + 1, 0), s(n + 1, 0), sum(n + 1, 0);
    for(ll i = 1; i <= n; i++){
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
        sum[i] = sum[i - 1] + s[i];
    }
 
    vector<ll> v(n + 1, 0), vec(n + 1, 0);
    for(ll i = 1; i <= n; i++){
        vec[i] = vec[i - 1] + (n + 1 - i);
        v[i] = v[i - 1] + ((n + 1 - i) * a[i]);
    }
 
    vector<ll> v_sum(n + 1, 0);
    for(ll i = 1; i <= n; i++){
        v_sum[i] = v_sum[i - 1] + (v[n] - v[i - 1]);
    }
 
    ll q;
    cin >> q;
    ll l, r;
    for(ll i = 0; i < q; i++){
        cin >> l >> r;
        ll i1 = binarysearch(vec, n + 1, l - 1);
        ll i2 = binarysearch(vec, n + 1, r);
        // cout << i1 << " " << i2 << endl;
        ll s1 = 0, s2 = 0;
        if(vec[i1] == l - 1){
            s1 = 0;
        }
        else{
            ll x = l - 1 - vec[i1];
            s1 = sum[x + i1] - sum[i1] - x * s[i1];
        }
        if(vec[i2] == r){
            s2 = 0;
        }
        else{
            ll x = r - vec[i2];
            s2 = sum[x + i2] - sum[i2] - x * s[i2];
        }
        cout << v_sum[i2] + s2 - v_sum[i1] - s1 << endl;
    }
    
    return 0;
}
