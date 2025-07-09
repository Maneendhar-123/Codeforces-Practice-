#include <bits/stdc++.h>
#include<vector>
using namespace std;
typedef long long ll;

ll DIV = 998244353;
ll MOD = pow(10, 9) + 7;

void solve(vector<vector<ll>>& vec, vector<vector<ll>>& adj, ll n, ll m){
    queue<pair<ll, ll>> que;
    que.push({1, 0});
    while(que.size() != 0){
        auto curr = que.front();
        ll x = curr.first, p = curr.second;
        que.pop();
        for(auto y : adj[x]){
            if(vec[y][(p + 1) % 2] > vec[x][p] + 1){
                vec[y][(p + 1) % 2] = vec[x][p] + 1;
                que.push({y, (p + 1) % 2});
            }
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

    ll tt;
    cin >> tt;
    while (tt--) {
        ll n, m, l;
        cin >> n >> m >> l;


        ll min_odd = INT64_MAX, min_even = INT64_MAX, sum = 0, A;
        for(ll i = 0; i < l; i++){
            cin >> A;
            sum += A;
            if(A % 2 == 0){
                min_even = min(min_even, A);
            }
            else{
                min_odd = min(min_odd, A);
            }
        }


        ll max_odd = -1, max_even = 0;
        if(sum % 2 == 0){
            max_even = sum;
            if(min_odd != INT64_MAX){
                max_odd = sum - min_odd;
            }
        }
        else{
            max_odd = sum;
            if(min_odd != INT64_MAX){
                max_even = sum - min_odd;
            }
        }


        ll a, b;
        vector<vector<ll>> adj(n + 1);
        for(ll i = 0; i < m; i++){
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }


        vector<vector<ll>> vec(n + 1, vector<ll>(2, INT64_MAX));
        vec[1][0] = 0;
        solve(vec, adj, n, m);

        cout << 1;
        for(ll i = 2; i < n + 1; i++){
            if(vec[i][0] <= max_even || vec[i][1] <= max_odd){
                cout << 1;
                continue;
            }
            cout << 0;
        }
        cout << endl;
    }
    return 0;
}
