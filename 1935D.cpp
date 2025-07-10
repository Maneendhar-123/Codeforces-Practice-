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
        ll n, c;
        cin >> n >> c;
        vector<ll> s(n);
        ll eve = 0, odd = 0, eve1 = 0, odd1 = 0, eve2 = 0, odd2 = 0;
        for(ll i = 0; i < n; i++){
            cin >> s[i];
            if(s[i] % 2 == 0){
                eve++;
                eve1 += (c + 1 - s[i]);
                eve2 += (s[i] / 2 + 1);
            }
            else{
                odd++;
                odd1 += (c + 1 - s[i]);
                odd2 += (s[i] / 2 + 1);
            }
        }
        ll ans = 0, tot = ((c + 1) * (c + 2)) / 2;
        ll ee = ((eve + 1) * eve) / 2, oo = ((odd + 1) * odd) / 2;
        ans = tot + ee + oo - eve1 - eve2 - odd1 - odd2;
        cout << ans << endl;
    }
    return 0;
}
