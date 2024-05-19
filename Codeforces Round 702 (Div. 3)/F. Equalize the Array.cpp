/**
 * Source: t.ly/nnPBD
 * Date: 2024/5/19
 * Time:
 * Space:
 * Skill:
 * Constraints:
 *
 */


#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <numeric>
#include <tuple>
#include <stack>
#include <bitset>
#include <functional>
#include <list>


using namespace std;
#define ll long long
#define SZ(X) ((int)(X).size())
#define For(i, a, b) for (int i = (a); i <= (b); i++)
#define Rep(i, a, b) for (int i = (a); i >= (b); i--)
typedef pair<int, int> PII;
typedef pair<ll, int> PLI;


const int MX = 2e5+10;


void solve() {
    ll res=LLONG_MAX/2;
    ll n;
    cin>>n;
    map<int,int> mp;
    for (int i=0, j; i<n; i++) {
        cin>>j;
        mp[j]++;
    }
    vector<ll> v;
    for (auto &i: mp) v.push_back(i.second);
    ll sz = SZ(v);
    sort(begin(v), end(v));
    ll presum = 0, total = accumulate(begin(v), end(v), 0ll);
    for (int i = 0; i < sz; i++) {
        res = min(res, total - v[i] * (sz-i) + presum);
        total -= v[i];
        presum += v[i];
        while (i+1 < sz && v[i] == v[i+1]) {
            total -= v[i];
            presum += v[i];
            i++;
        }
    }
    cout << res << endl;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    for (cin>>t; t; t--) {
        solve();
    }
}