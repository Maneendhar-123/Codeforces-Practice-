#include <bits/stdc++.h>
#include<vector>
using namespace std;
typedef long long ll;
 
void fill(vector<ll>& isprime, vector<ll>& primes, ll N){
    for(ll i = 2; i * i < N; i++){
        if(isprime[i] == 1){
            for(ll j = i * i; j < N; j += i){
                isprime[j] = 0;
            }
        }
    }
    for(ll i = 2; i < N; i++){
        if(isprime[i]){
            primes.push_back(i);
            // cout << i << " ";
        }
    }
}
 
ll check(vector<ll>& primes, ll n1, ll d, ll s){
    ll i1 = 0, x1 = 0;
    for(ll i = 0; i < primes.size(); i++){
        if(n1 % primes[i] == 0){
            ll n2 = n1 / primes[i];
            if((n1 - n2) * s <= d){
                i1 = 1;
                x1 = 1;
            }
            break;
        }
    }
    if(x1 == 0){
        if((n1 - 1) * s <= d){
            i1 = 1;
        }
    }
    return i1;
}
 
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    ll N = pow(10, 6) + 1;
    vector<ll> isprime(N, 1), primes;
    fill(isprime, primes, N);
    ll n, d, s;
    cin >> n >> d >> s;
    ll mi = min(2 * d, n);
    if(d < s){
        cout << s << endl;
    }
    else if(d == s){
        if(2 * s <= n){
            cout << 2 * s << endl;
        }
        else{
            cout << s << endl;
        }
    }
    else{
        ll n1;
        if(2 * d <= n){
            n1 = (2 * d) / s;
        }
        else{
            n1 = n / s;
        }
        ll ans = check(primes, n1, d, s);
        if(n1 == 1){
            ans = 1;
        }
        n1 *= s;
        if(ans == 1){
            cout << n1 << endl;
        }
        else{
            cout << n1 - s << endl;
        }
    }
    return 0;
}
