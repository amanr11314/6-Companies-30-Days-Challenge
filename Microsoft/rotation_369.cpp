#include <bits/stdc++.h>
using namespace std;
/*
    https://leetcode.com/problems/rotate-function/description/
    F[0] = 0*A[0] + 1*A[1] + .... + (n-1)*A[n-1]
    sum = A[0] + A[1] + .... + A[n-1]
    F[i] = F[i-1] + sum - n*A[n-i]
*/
class Solution {
public:
  int maxRotateFunction(vector<int> &nums) {

    int f = 0;
    int sum = 0;
    int n = nums.size();
    // computer F[0]  and sum
    for (int i = 0; i < n; ++i) {
      sum += nums[i];
      f += (nums[i] * i);
    }
    int ans = f;
    // compute further values of F[i]
    // and update the ans as max value of f
    for (int i = 1; i < n; ++i) {
      f = (f + sum - (n * nums[n - i]));
      ans = max(ans, f);
    }
    return ans;
  }
};