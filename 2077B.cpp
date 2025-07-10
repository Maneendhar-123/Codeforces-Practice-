#include <bits/stdc++.h>
#include<vector>
using namespace std;
typedef long long ll;

void fill(vector<ll>& pow_2, ll& l1, ll& l2){
    for(ll i = 1; i < 31; i++){
        pow_2[i] = pow_2[i - 1] * 2;
        if(i % 2 == 0 && i != 30){
            l2 += pow_2[i];
        }
        else if(i % 2 == 1){
            l1 += pow_2[i];
        }
    }
}
 
void convert(ll n1, vector<ll>& vec, vector<ll>& pow_2){
    for(ll i = 30; i >= 0; i--){
        if(n1 >= pow_2[i]){
            if(i % 2 == 1){
                vec[i - 1] = pow_2[i];
            }
            else{
                vec[i] = pow_2[i];
            }
            n1 -= pow_2[i];
        }
    }
}
 
void convert2(ll n2, vector<ll>& vec, vector<ll>& pow_2){
    for(ll i = 30; i >= 0; i--){
        if(n2 >= pow_2[i]){
            if(i % 2 == 0){
                vec[i - 1] = pow_2[i];
            }
            else{
                vec[i] = pow_2[i];
            }
            n2 -= pow_2[i];
        }
    }
}
 
void convert1(ll m, vector<ll>& vec1, vector<ll>& pow_2, ll& si){
    for(ll i = 30; i >= 0; i--){
        if(m >= pow_2[i]){
            si = max(si, i + 1);
            m -= pow_2[i];
            vec1[i] = 1;
        }
    }
}
 
void find_size(vector<ll>& vec, ll& sii){
    for(ll i = 29; i >= 0; i--){
        if(vec[i] != 0){
            sii = max(sii, i + 1);
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
    vector<ll> pow_2(31, 1);
    ll l1 = 0, l2 = 1;
    fill(pow_2, l1, l2);
    while (tt--) {
        ll n1, n2, m, ans = 0;
        cout << l1 << endl;
        cout.flush();
        cin >> n1;
        n1 -= 2 * l1;
        cout << l2 << endl;
        cout.flush();
        cin >> n2;
        n2 -= 2 * l2;
        vector<ll> vec(30, 0), vec1(30, 0);
        convert(n1, vec, pow_2);
        convert2(n2, vec, pow_2);
        cout << "!" << endl;
        cout.flush();
        cin >> m;
        ans = 2 * m;
        ll si = 0, sii = 0;
        find_size(vec, sii);
        convert1(m, vec1, pow_2, si);
        for(ll i = 0; i < max(si, sii); i++){
            if(vec1[i] == 0){
                ans += vec[i];
            }
        }
        cout << ans << endl;
        cout.flush();
    }
    return 0;
}
