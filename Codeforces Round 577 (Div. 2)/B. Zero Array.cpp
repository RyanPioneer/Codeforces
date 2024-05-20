/**
 * Source: t.ly/gsVlf
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
#include <cstdint>


using namespace std;
#define ll long long
#define SZ(X) ((int)(X).size())
#define For(i, a, b) for (int i = (a); i <= (b); i++)
#define Rep(i, a, b) for (int i = (a); i >= (b); i--)
typedef pair<int, int> PII;
typedef pair<ll, int> PLI;


const int MX = 1e5+10;
ll arr[MX];

void solve() {
    int n;
    ll total = 0, mx = 0;
    cin>>n;
    For(i,1,n) {
        cin>>arr[i];
        total += arr[i];
        mx = max(mx, arr[i]);
    }
    if (total % 2 || mx * 2 > total) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
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