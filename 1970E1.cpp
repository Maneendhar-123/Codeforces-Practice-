#include <bits/stdc++.h>
#include<vector>
using namespace std;
typedef long long ll;
 
ll N = pow(10, 9) + 7;
 
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    ll m, n;
    cin >> m >> n;
    ll s[m], l[m];
    for(ll i = 0; i < m; i++){
        cin >> s[i];
    }
    for(ll i = 0; i < m; i++){
        cin >> l[i];
    }
    vector<vector<ll>> vec(m, vector<ll>(m));
    for(ll i = 0; i < m; i++){
        for(ll j = 0; j < m; j++){
            vec[i][j] = s[i] * l[j] + s[i] * s[j] + l[i] * s[j];
        }
    }
    vector<vector<vector<ll>>> ans(n + 1, vector<vector<ll>>(m, vector<ll>(m)));
    vector<vector<ll>> v(n + 1, vector<ll>(m, 0));
    v[0][0] = 1;
    for(ll i = 1; i <= n; i++){
        for(ll j = 0; j < m; j++){
            for(ll k = 0; k < m; k++){
                ans[i][j][k] = v[i - 1][j] * vec[j][k];
                ans[i][j][k] %= N;
                v[i][k] += ans[i][j][k];
                v[i][j] %= N;
            }
        }
    }
    ll aa = 0;
    for(ll j = 0; j < m; j++){
        aa += v[n][j];
        aa %= N;
    }
    cout << aa << endl;
    return 0;
}
