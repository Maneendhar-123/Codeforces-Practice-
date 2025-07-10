#include <bits/stdc++.h>
#include<vector>
using namespace std;
typedef long long ll;
 
ll N = pow(10, 9) + 7;
 
void fill(vector<vector<ll>>& walk, vector<vector<ll>>& identity, ll m, vector<ll>& s, vector<ll>& l){
    for(ll i = 0; i < m; i++){
        for(ll j = 0; j < m; j++){
            walk[i][j] = l[i] * s[j] + s[i] * l[j] + s[i] * s[j];
            walk[i][j] %= N;
        }
    }
 
    for(ll i = 0; i < m; i++){
        identity[i][i] = 1;
    }
    return;
}
 
void print(vector<vector<ll>> walk, ll m){
    for(ll i = 0; i < m; i++){
        for(ll j = 0; j < m; j++){
            cout << walk[i][j] << " ";
        }
        cout << endl;
    }
}
 
void print_sum(vector<vector<ll>> identity, ll m){
    ll sum = 0;
    for(ll i = 0; i < m; i++){
        sum += identity[0][i];
        sum %= N;
    }
    cout << sum << endl;
}
 
void reset(vector<vector<ll>>& extra, ll m){
    for(ll i = 0; i < m; i++){
        for(ll j = 0; j < m; j++){
            extra[i][j] = 0;
        }
    }
}
 
void copy(vector<vector<ll>>& identity, vector<vector<ll>>& walk, ll m){
    for(ll i = 0; i < m; i++){
        for(ll j = 0; j < m; j++){
            identity[i][j] = walk[i][j];
        }
    }
}
 
void matrixmult(vector<vector<ll>>& walk, vector<vector<ll>>& walk1, vector<vector<ll>>& extra, ll m){
    for(ll i = 0; i < m; i++){
        for(ll j = 0; j < m; j++){
            for(ll k = 0; k < m; k++){
                extra[i][j] += walk[i][k] * walk1[k][j];
                extra[i][j] %= N;
            }
        }
    }
}
 
void solve(vector<vector<ll>>& walk, vector<vector<ll>>& extra, vector<vector<ll>>& identity, vector<ll> nuse, ll m){
    if(nuse[0] == 1){
        copy(identity, walk, m);
    }
    for(ll i = 1; i < 32; i++){
        reset(extra, m);
        matrixmult(walk, walk, extra, m);
        copy(walk, extra, m);
        if(nuse[i] == 1){
            reset(extra, m);
            matrixmult(identity, walk, extra, m);
            copy(identity, extra, m);
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
 
    ll m, n;
    cin >> m >> n;
    vector<ll> s(m), l(m);
    for(ll i = 0; i < m; i++){
        cin >> s[i];
    }
    for(ll i = 0; i < m; i++){
        cin >> l[i];
    }
 
    vector<vector<ll>> walk(m, vector<ll>(m, 0)), identity(m, vector<ll>(m, 0)), extra(m, vector<ll>(m, 0));
    fill(walk, identity, m, s, l);
    // print(walk, m);
    // print(identity, m);
 
    ll n1 = n;
    vector<ll> pow_2(32, 1), nuse(32, 0);
    for(ll i = 1; i < 32; i++){
        pow_2[i] = pow_2[i - 1] * 2;
    }
    for(ll i = 31; i >= 0; i--){
        if(n1 >= pow_2[i]){
            n1 -= pow_2[i];
            nuse[i] = 1;
        }
        // cout << nuse[i] << " ";
    }
    // cout << endl;
 
    solve(walk, extra, identity, nuse, m);
    // print(identity, m);
    print_sum(identity, m);
}
