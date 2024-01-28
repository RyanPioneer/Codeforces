/**
 * Source: jpeg.ly/KJdlu
 * Date: 2023/11/17
 * Skill:
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
        vector<ll> presum(n + 1, 0);
        ll res = LLONG_MIN, cur_min = LLONG_MAX, cur_max = LLONG_MIN;
        for (int i = 0; i < n; i++) {
            presum[i + 1] = presum[i] + nums[i];
            cur_max = max(cur_max, nums[i]);
            cur_min = min(cur_min, nums[i]);
            res = max(res, cur_max - cur_min);
        }
        for (int k = 2; k <= sqrt(n); k++) {
            if (n % k == 0) {
                vector<int> cand = {k, n / k};
                for (auto &i: cand) {
                    ll ans = LLONG_MIN;
                    cur_min = LLONG_MAX, cur_max = LLONG_MIN;
                    for (int j = 0; j < n; j += i) {
                        ll num = presum[j + i] - presum[j];
                        cur_max = max(cur_max, num);
                        cur_min = min(cur_min, num);
                        ans = max(ans, cur_max - cur_min);
                    }
                    res = max(res, ans);
                }
            }
        }
        cout << res << endl;
    }
}