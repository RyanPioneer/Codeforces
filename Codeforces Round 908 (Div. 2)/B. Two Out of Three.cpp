/**
 * Source: is.gd/2DlSAR
 * Date: 2024/2/25
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
    int n, time = 0;
    unordered_map<int, int> cnt, used;
    cin >> n;
    vector<int> nums(n);
    for (auto &i: nums) {
        cin >> i;
        cnt[i]++;
        if (cnt[i] == 2) {
            time++;
        }
    }
    if (time < 2 || n <= 3) {
        cout << -1 << endl;
        return;
    }
    time = 2;
    for (int i = 0; i < n; i++) {
        if (cnt[nums[i]] == 1 || time == 0) {
            cout << 1 << " ";
        } else if (used[nums[i]] == 0 && time == 2) {
            cout << 3 << " ";
            time--;
        } else if (used[nums[i]] == 0 && time == 1) {
            cout << 2 << " ";
            time--;
        } else {
            cout << 1 << " ";
        }
        used[nums[i]]++;
    }
    cout << endl;
}

int main() {
    int t;
    for (cin >> t; t--;) {
        solve();
    }
}