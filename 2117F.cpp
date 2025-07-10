#include <bits/stdc++.h>
#include<vector>
using namespace std;
typedef long long ll;

pair<ll, ll> solve(vector<vector<ll>> adj, vector<ll> degree, ll n){
    vector<ll> visited(n + 1, 0);
    visited[1] = 1;
    queue<ll> myque;
    myque.push(1);
    ll n1 = 1, n2 = 0, x1 = 0;
    if(degree[1] == 2){
        x1 = 1;
    }
    while(myque.size() != 0){
        ll x = myque.front();
        myque.pop();
        for(auto y : adj[x]){
            if(visited[y]){
                continue;
            }
            if(x1 == 0){
                myque.push(y);
                n1++;
                visited[y] = 1;
            }
            if(x1 == 1){
                myque.push(y);
                n2++;
                visited[y] = 1;
                break;
            }
            if(degree[y] == 3){
                x1 = 1;
            }
        }
    }
    pair<ll, ll> p = {n1, n2};
    return p;
}
 
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    ll tt, N1 = 2 * pow(10, 5) + 1, N = pow(10, 9) + 7;
    cin >> tt;
    vector<ll> pow_2(N1, 1);
    for(ll i = 1; i < N1; i++){
        pow_2[i] = pow_2[i - 1] * 2;
        pow_2[i] %= N;
    }
    while (tt--) {
        ll n;
        cin >> n;
        vector<ll> degree(n + 1, 0), vec(n + 1, 0);
        vector<vector<ll>> adj(n + 1); 
        ll a, b;
        for(ll i = 0; i < n - 1; i++){
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
            degree[a]++;
            degree[b]++;
        }
        ll leafs = 0, ans = 1;
        if(degree[1] >= 3){
            ans = 0;
        }
        for(ll i = 2; i <= n; i++){
            if(degree[i] == 1){
                leafs++;
            }
            if(degree[i] > 3){
                ans = 0;
            }
        }
        if(leafs > 2){
            ans = 0;
        }
        if(ans == 0){
            cout << 0 << endl;
        }
        else{
            auto [l1, l2] = solve(adj, degree, n);
            ll prod = pow_2[l1];
            ll l3 = max(l2, n - l2 - l1) - min(l2, n - l2 - l1);
            if(l2 == 0){
                prod %= N;
            }
            else if(l3 == 0){
                prod *= 2;
                prod %= N;
            }
            else{
                prod *= 3;
                prod %= N;
                prod *= pow_2[l3 - 1];
                prod %= N;
            }
            cout << prod << endl;
        }
    }
    return 0;
}
