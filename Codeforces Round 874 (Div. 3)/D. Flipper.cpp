/**
 * Source: is.gd/MdaXdH
 * Date: 2024/2/14
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


void solve() {
    int n, back = 0;
    cin >> n;
    vector<int> nums(n);
    for (auto &i: nums) cin >> i;
    if (n == 1) {
        cout << 1 << endl;
        return;
    }
    int mx = n - (nums[0] == n);
    while (nums[back + 1] != mx) back++;
    if (back == n - 2) back++;
    int front = back - 1;
    while (front > 0 && nums[front] > nums[0]) front--;
    for (int i = back + 1; i < n; i++) cout << nums[i] << " ";
    for (int i = back; i > front; i--) cout << nums[i] << " ";
    for (int i = 0; i <= front; i++) cout << nums[i] << " ";
    cout << endl;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    for (cin >> t; t--;) solve();
}