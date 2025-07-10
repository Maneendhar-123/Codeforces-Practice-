#include <bits/stdc++.h>
#include<vector>
using namespace std;
typedef long long ll;
 
ll N = pow(10, 9) + 7;
 
void fill(vector<ll>& fact, ll n){
    for(ll i = 2; i < n; i++){
        fact[i] = (fact[i - 1] * i) % N;
    }
}
 
void fill1(vector<ll>& inv_fact, vector<ll>& fact, ll N1, ll n){
    for(ll i = 2; i < n; i++){
        ll a = fact[i], N2 = N1;
        while(N2 != 0){
            if(N2 & 1 != 0){
                inv_fact[i] = (inv_fact[i] * a) % N;
            }
            a = (a * a) % N;
            N2 /= 2;
        }
    }
}
 
void fill2(vector<vector<ll>>& vec, vector<ll>& fact, vector<ll>& inv_fact, ll n){
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < i; j++){
            vec[i][j] = (fact[i] * inv_fact[j]) % N;
            vec[i][j] = (vec[i][j] * inv_fact[i - j]) % N;
        }
        for(ll j = i + 1; j < n; j++){
            vec[i][j] = 0;
        }
    }
}
 
 
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    vector<ll> fact(5002, 1), inv_fact(5002, 1);
    fill(fact, 5002);
    fill1(inv_fact, fact, N - 2, 5002);
    // for(ll i = 1; i < 5002; i++){
    //     cout << fact[i] << " " << inv_fact[i] << endl;
    // }
    vector<vector<ll>> vec(5002, vector<ll>(5002, 1));
    fill2(vec, fact, inv_fact, 5002);
 
    ll tt;
    cin >> tt;
    while (tt--) {
        ll n;
        cin >> n;
        ll ans = 1, exp, ans1 = 1;
        for(ll i = 1; i <= n; i++){
            exp = 2 * i + 1;
            if(exp <= n){
                for(ll j = 0; j <= i; j++){
                    if(n - i < 1){
                        continue;
                    }
                    ans1 = (vec[exp - j - 1][i - j] * vec[n - exp + j][j]) % N;
                    ans1 = (ans1 * (exp - j)) % N;
                    // cout << ans1 << endl;
                    ans += ans1;
                    ans %= N;
                }
            }
            else{
                ans += (vec[n][i] * exp) % N;
                ans %= N;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
