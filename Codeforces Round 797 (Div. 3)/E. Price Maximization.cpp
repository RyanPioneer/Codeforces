/**
 * Source: t.ly/ASjYh
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
ll arr[MX];


void solve() {
    ll n, k, res=0;
    cin >> n >> k;
    For(i,1,n) {
        cin>>arr[i];
        res += arr[i] / k;
        arr[i] %= k;
    }
    sort(arr+1, arr+n+1);
    int left = 1;
    for (int right = n; left < right; right--) {
        while (left < right && arr[left] + arr[right] < k) left++;
        res += left++ < right;
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