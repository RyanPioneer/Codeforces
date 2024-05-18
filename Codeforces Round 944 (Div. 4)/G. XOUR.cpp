/**
 * Source: ibit.ly/nnh2u
 * Date: 2024/5/14
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
#define SZ(X) ((int)(X).size())
#define ll long long
typedef pair<int, int> PII;
typedef pair<ll, int> PLI;

const int MX = 2e5+2;
ll arr[MX];
map<int, vector<int>> mp;


void solve() {
    mp.clear();
    ll n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        mp[(arr[i] >> 2) << 2].push_back(arr[i]);
    }
    for (auto &i: mp) {
        vector<int> &v = i.second;
        sort(begin(v), end(v), [](const int a, const int b) {
            return a > b;
        });
    }
    for (int i = 0; i < n; i++) {
        cout << mp[(arr[i] >> 2) << 2].back() << " ";
        mp[(arr[i] >> 2) << 2].pop_back();
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    for (cin >> t; t; t--) {
        solve();
    }
}