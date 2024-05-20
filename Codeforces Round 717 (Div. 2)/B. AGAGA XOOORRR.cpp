/**
 * Source: t.ly/boJYw
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


const int MX = 2e3+10;
ll presum[MX] = {0};

void solve() {
    ll n, total = 0;
    cin >> n;
    For(i,1,n) {
        ll j;
        cin >> j;
        total ^= j;
        presum[i] = presum[i-1] ^ j;
    }
    ll left = n+1, right = -1;
    For(i,1,n-1) {
        if (presum[i] == 0) right = i;
        if (presum[n-i] == total) left = n-i;
    }
    if (total == 0 || left < right) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
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