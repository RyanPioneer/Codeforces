/**
 * Source: is.gd/NWNgPP
 * Date: 2024/2/12
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


#define SZ(X) ((int)(X).size())
#define ll long long
using namespace std;


void solve() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (auto &i: nums) cin >> i;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        stack<int> st;
        for (int j = i; j < n; j++) {
            int mx = nums[j];
            while (!st.empty() && nums[j] < st.top()) {
                mx = max(mx, st.top());
                st.pop();
            }
            st.push(mx);
            ans += j - i + 1 - SZ(st);
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    for (cin >> t; t--;) solve();
}