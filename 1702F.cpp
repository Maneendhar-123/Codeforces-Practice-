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
        multiset<ll> a, b;
        ll a1, b1;
        for(ll i = 0; i < n; i++){
            cin >> a1;
            a.insert(a1);
        }
        for(ll i = 0; i < n; i++){
            cin >> b1;
            b.insert(b1);
        }
 
        ll i = n, j = n, ans = 1;
        while(i != 0 && j != 0){
            auto it = a.end();
            it--;
            auto it1 = b.end();
            it1--;
            ll aa = *it, bb = *it1;
            if(aa > bb && aa % 2 != 0){
                ans = 0;
                break;
            }
            else if(aa > bb && aa % 2 == 0){
                a.erase(a.find(aa));
                a.insert(aa / 2);
            }
            else if(aa == bb){
                i--;
                j--;
                a.erase(a.find(aa));
                b.erase(b.find(bb));
            }
            else if(aa < bb){
                b.erase(b.find(bb));
                b.insert(bb / 2);
            }
        }
        if(ans == 1){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}
