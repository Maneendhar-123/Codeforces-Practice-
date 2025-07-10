#include <bits/stdc++.h>
#include<vector>
using namespace std;
typedef long long ll;
 
ll DIV = 998244353;
ll MOD = pow(10, 9) + 7;
 
void fill(vector<ll>& fact, ll N){
    for(ll i = 2; i < N; i++){
        fact[i] = (fact[i - 1] * i) % DIV;
    }
}
 
void inv_fill(vector<ll>& inv_fact, vector<ll>& fact, ll N){
    for(ll i = 2; i < N; i++){
        ll a = fact[i], ans = 1, x = DIV - 2;
        while(x != 0){
            if(x & 1){
                ans = (ans * a) % DIV;
            }
            a = (a * a) % DIV;
            x /= 2;
        }
        inv_fact[i] = ans;
    }
}
 
ll permutation(vector<ll>& inv_fact, vector<ll>& fact, ll n, ll x){
    ll ans = 1;
    ans = (fact[n] * inv_fact[x]) % DIV;
    ans = (ans * inv_fact[n - x]) % DIV;
    return ans;
}
 
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    ll tt, N = 5 * pow(10, 5) + 1;
    cin >> tt;
    vector<ll> fact(N, 1), inv_fact(N, 1);
    fill(fact, N);
    inv_fill(inv_fact, fact, N);
    while (tt--) {
        vector<ll> a(26, 0);
        ll sum = 0;
        for(ll i = 0; i < 26; i++){
            cin >> a[i];
            sum += a[i];
        }
        sort(a.begin(), a.end(), greater<ll>());
        ll sum1 = 0, odd = (sum + 1) / 2, eve = sum / 2;
        vector<ll> vec(odd + 1, 0);
        vec[0] = 1;
        for(ll j = 0; j < 26; j++){
            if(a[j] == 0){
                break;
            }
            for(ll i = odd; i >= 0; i--){
                if(vec[i] != 0){
                    if(i + a[j] <= odd){
                        vec[i + a[j]] += (vec[i] * permutation(inv_fact, fact, odd - i, a[j])) % DIV;
                    }
                    if(eve - sum1 + i >= a[j]){
                        vec[i] = (vec[i] * permutation(inv_fact, fact, eve - sum1 + i, a[j])) % DIV;
                    }
                }
            }   
            sum1 += a[j];    
        }
        cout << vec[odd] % DIV << endl;
    }   
    return 0;
}
