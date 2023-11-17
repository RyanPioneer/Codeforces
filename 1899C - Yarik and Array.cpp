/**
 * Source: jpeg.ly/P-Cpe
 * Date: 2023/11/17
 * Skill:
 *
 *
 */


#include <vector>
#include <iostream>
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
#include <cmath>


using namespace std;


#define ll long long

const int MX = 1e4;


int main() {
    int t, n, m;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        vector<ll> nums;
        for (int j = 0; j < n; j++) {
            cin >> m;
            nums.push_back(m);
        }
        ll res = nums[0], prev = nums[0];
        for (int j = 1; j < n; j++) {
            if ((nums[j] + MX) % 2 != (nums[j - 1] + MX) % 2 && prev > 0) prev += nums[j];
            else prev = nums[j];
            res = max(res, prev);
        }
        cout << res << endl;
    }
}