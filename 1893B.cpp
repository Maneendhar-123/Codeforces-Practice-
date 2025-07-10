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
        ll n, m;
        cin >> n >> m;
        vector<ll> a(n), b(m);
        for(ll i = 0; i < n; i++){
            cin >> a[i];
        }
        for(ll i = 0; i < m; i++){
            cin >> b[i];
        }
        sort(b.begin(), b.end());
        ll i = 0, j = m - 1;
        while(i != n || j != -1){
            if(i == n){
                cout << b[j] << " ";
                j--;
            }
            else if(j == -1){
                cout << a[i] << " ";
                i++;
            }
            else if(a[i] <= b[j]){
                cout << b[j] << " ";
                j--;
            }
            else{
                cout << a[i] << " ";
                i++;
            }
        }
        cout << endl;
    }
    return 0;
}
