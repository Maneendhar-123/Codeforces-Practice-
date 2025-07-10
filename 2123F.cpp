#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
ll DIV = 998244353;
ll MOD = pow(10, 9) + 7;
 
ll solve(vector<ll>& primes, ll i){
    for(ll j = 0; j < primes.size(); j++){
        if(primes[j] * primes[j] > i){
            break;
        }
        else{
            if(i % primes[j] == 0){
                return primes[j];
            }
        }
    }
}
 
void fill1(vector<ll>& primes, vector<ll>& isprime, ll N){
    for(ll i = 2; i * i < N; i++){
        if(isprime[i]){
            for(ll j = i * i; j < N; j += i){
                isprime[j] = 0;
            }
        }
    }
    for(ll i = 2; i < N; i++){
        if(isprime[i]){
            primes.push_back(i);
            // cout << i << endl;
        }
    }
}
 
void solve1(map<ll, vector<ll>>& mymap, vector<ll>& vec, ll n){
    for(auto p : mymap){
        ll si = p.second.size();
        ll n1 = vec[mymap[p.first][si - 1]];
        for(ll i = si - 1; i > 0; i--){
            vec[mymap[p.first][i]] = vec[mymap[p.first][i - 1]];
        }
        vec[mymap[p.first][0]] = n1;
    }
}
 
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    ll tt, N = pow(10, 5) + 1;
    cin >> tt;
    vector<ll> primes, isprime(N, 1);
    fill1(primes, isprime, N);
    while (tt--) {
        ll n;
        cin >> n;
        vector<ll> vec(n + 1);
        set<ll> s;
        for(ll i = 1; i <= n; i++){
            vec[i] = i;
            s.insert(i);
        }
        s.erase(1);
        map<ll, vector<ll>> mymap;
        for(ll i = 2; i <= n; i++){
            if(isprime[i]){
                mymap[i].push_back(i);
                s.erase(i);
                if(2 * i <= n){
                    mymap[i].push_back(2 * i);
                    s.erase(2 * i);
                }
            }
        }
        while(s.size() != 0){
            auto it = s.begin();
            ll x = solve(primes, *it);
            mymap[x].push_back(*it);
            s.erase(*it);
        }
        solve1(mymap, vec, n);
        for(ll i = 1; i <= n; i++){
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
