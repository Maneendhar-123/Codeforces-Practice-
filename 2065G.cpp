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
 
    ll N = 2 * pow(10, 5) + 1;
    vector<ll> isprime(N, 1);
    for(ll i = 2; i * i < N; i++){
        if(isprime[i] == 1){
            for(ll j = i * i; j < N; j += i){
                isprime[j] = 0;
            }
        }
    }
 
    ll tt;
    cin >> tt;
    while (tt--) {
        ll n;
        cin >> n;
        vector<ll> a(n), vec;
        map<ll, ll> mymap;
        ll primes = 0;
        for(ll i = 0; i < n; i++){
            cin >> a[i];
            if(mymap[a[i]] == 0){
                vec.push_back(a[i]);
            }
            if(isprime[a[i]]){
                primes++;
            }
            mymap[a[i]]++;
        }
 
        ll ans = 0;
        for(ll i = 0; i < vec.size(); i++){
            if(isprime[vec[i]]){
                ans += mymap[vec[i]] * (primes - mymap[vec[i]]);
            }
        }
        ans /= 2;
        // cout << ans << " ";
 
        map<ll, pair<ll, ll>> primers;
        for(ll i = 0; i < vec.size(); i++){
            ll n1 = sqrt(vec[i]), n2 = 0;
            for(ll j = 2; j <= n1; j++){
                if(vec[i] % j == 0){
                    n2 = j;
                    break;
                }
            }
 
            if(n2 != 0){
                if(isprime[n2] == 1 && isprime[vec[i] / n2] == 1){
                    primers[vec[i]] = {n2, vec[i] / n2};
                }
            }
        }
 
        for(ll i = 0; i < vec.size(); i++){
            if(primers[vec[i]].first >= 2 && primers[vec[i]].second >= 2){
                if(primers[vec[i]].first == primers[vec[i]].second){
                    ans += mymap[vec[i]] * mymap[primers[vec[i]].first];
                }
                else{
                    ans += mymap[vec[i]] * mymap[primers[vec[i]].first];
                    ans += mymap[vec[i]] * mymap[primers[vec[i]].second];
                }
                ans += (mymap[vec[i]] * (mymap[vec[i]] + 1)) / 2;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
