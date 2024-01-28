/**
 * Source: jpeg.ly/ZPeg5
 * Date: 2023/11/17
 * Skill:
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
        ll min_idx = 0, min_val = nums[0];
        for (int j = 1; j < n; j++) {
            if (nums[j] < min_val) {
                min_val = nums[j];
                min_idx = j;
            }
        }
        for (int j = min_idx + 1; j < n; j++) {
            if (nums[j] < nums[j - 1]) {
                min_idx = -1;
                break;
            }
        }
        cout << min_idx << endl;
    }
}