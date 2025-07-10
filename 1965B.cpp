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
    vector<ll> pow_2(27, 1);
    for(ll i = 1; i < 27; i++){
        pow_2[i] = pow_2[i - 1] * 2;
    }
    while (tt--) {
        ll n, k;
        cin >> n >> k;
        ll sum = 0, i = 0, j = 0;
        vector<ll> vec;
        while(j < 25){
            if(sum < k && sum + pow_2[i] >= k){
                vec.push_back(k - sum - 1);
                vec.push_back(k + 1);
                sum = 2 * k;
                j += 2;
            }
            else{
                vec.push_back(sum + 1);
                sum += pow_2[i];
                i++;
                j++;
            }
        }
 
        cout << 25 << endl;
        for(ll i = 0; i < 25; i++){
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
