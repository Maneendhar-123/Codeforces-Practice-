#include <bits/stdc++.h>
#include<vector>
using namespace std;
typedef long long ll;
 
ll MOD = pow(10, 9) + 7;
 
ll check_valid(vector<ll>& p, vector<ll>& s, ll n, ll index, ll num){
    if(num != 1){
        return 0;
    }
    if(p[0] != 1 || s[0] != 1){
        return 0;
    }
    if(p[p.size() - 1] != index || s[s.size() - 1] != n + 1 - index){
        return 0;
    }
    return 1;
}
 
void fill(vector<ll>& fact, ll N){
    for(ll i = 2; i < N; i++){
        fact[i] = (fact[i - 1] * i) % MOD;
    }
}
 
void inv_fill(vector<ll>& inv_fact, vector<ll>& fact, ll N){
    for(ll i = 2; i < N; i++){
        ll ans = 1, a = fact[i], x = MOD - 2;
        while(x != 0){
            if(x & 1){
                ans = (ans * a) % MOD;
            }
            a = (a * a) % MOD;
            x /= 2;
        }
        inv_fact[i] = ans;
        // cout << inv_fact[i] << endl;
    }
}
 
ll npermutation(vector<ll>& inv_fact, vector<ll>& fact, ll n, ll x){
    if(x < 0 || n < x){
        return 1;
    }
    ll ans = 1;
    ans = (fact[n] * inv_fact[n - x]) % MOD;
    return ans;
}
 
ll permutation(vector<ll>& inv_fact, vector<ll>& fact, ll n, ll x){
    if(x < 0 || n < x){
        return 1;
    }
    ll ans = (fact[n] * inv_fact[x]) % MOD;
    ans = (ans * inv_fact[n - x]) % MOD;
    return ans;
}
 
ll solve(vector<ll>& p, vector<ll>& inv_fact, vector<ll>& fact, ll n, ll index){
    ll ans1 = 1, ma = index - 1, num = 0;
    for(ll i = p.size() - 1; i > 0; i--){
        num = p[i] - p[i - 1] - 1;
        ans1 = (ans1 * npermutation(inv_fact, fact, ma - 1, num)) % MOD;
        ma = ma - num - 1; 
    }
    return ans1;
}
 
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    ll tt, N = 2 * pow(10, 5) + 1;
    cin >> tt;
    vector<ll> fact(N, 1), inv_fact(N, 1);
    fill(fact, N);
    inv_fill(inv_fact, fact, N);
    while (tt--) {
        ll n, m1, m2;
        cin >> n >> m1 >> m2;
        vector<ll> vec(n + 1, 0), p(m1), s(m2);
        for(ll i = 0; i < m1; i++){
            cin >> p[i];
            vec[p[i]]++;
        }
        ll num = 0, index = -1;
        for(ll i = 0; i < m2; i++){
            cin >> s[i];
            vec[s[i]]++;
            if(vec[s[i]] == 2){
                num++;
                index = s[i];
            }
            s[i] = n + 1 - s[i];
        }
        sort(s.begin(), s.end());
        ll xx = check_valid(p, s, n, index, num);
        if(xx == 0){
            cout << 0 << endl;
            continue;
        }
        ll ansl = solve(p, inv_fact, fact, n, index);
        ll ansr = solve(s, inv_fact, fact, n, n - index + 1);
        ansl = (ansl * ansr) % MOD;
        ansr = permutation(inv_fact, fact, n - 1, index - 1);
        ansl = (ansl * ansr) % MOD;
        cout << ansl << endl;
    }
    return 0;
}
