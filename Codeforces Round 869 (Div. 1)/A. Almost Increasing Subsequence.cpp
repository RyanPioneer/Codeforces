/**
 * Source: t.ly/ZYWbc
 * Date: 2024/5/20
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
ll arr[MX], presum[MX] = {0};


void solve() {
    ll n, q;
    cin >> n >> q;
    For(i,1,n) cin>>arr[i];
    For(i,2,n-1) {
        presum[i] = presum[i-1] + (arr[i-1] >= arr[i] && arr[i] >= arr[i+1]);
    }
    presum[n] = presum[n-1];
    while (q--) {
        ll l, r;
        cin >> l >> r;
        if (l + 1 >= r) {
            cout << r-l+1 << endl;
            continue;
        }
        ll res = r - l + 1 - (presum[r-1] - presum[l]);
        cout << res << endl;
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    for (t=1; t; t--) {
        solve();
    }
}