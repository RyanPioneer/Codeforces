/**
 * Source: t.ly/3QsfI
 * Date: 2024/5/18
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


const int MX = 3e5+10;
ll arr[MX];


void solve() {
    ll res = 0;
    ll n, mx = 0;
    cin>>n;
    cin>>n;
    For(i,1,n) {
        cin>>arr[i];
        mx = max(mx, arr[i]);
    }
    ll one = 0, two = 0;
    For(i,1,n) {
        res += (mx - arr[i]) / 3 * 2;
        if ((mx - arr[i]) % 3 == 1) one++;
        if ((mx - arr[i]) % 3 == 2) two++;
    }
    ll mi = min(one, two);
    res += mi * 2;
    one -= mi;
    two -= mi;
    if (one > 0) {
        res += one * 2 - 1;
    } else {
        res += two * 2;
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