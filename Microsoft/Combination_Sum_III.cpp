#include <bits/stdc++.h>
using namespace std;
/*
https://leetcode.com/problems/combination-sum-iii/description/
*/

class Solution {
public:
  // for storing all subsets
  vector<vector<int>> ans;

  // for storing unique subsets as the digits are used to obtain a sum in unique
  // patterns of 0's and 1's
  unordered_set<string> hs;

  // for storing current subset of digits which sum up to n
  vector<int> curr;

  // current sum in backtracking
  int sum = 0;

  // for keeping check of adding 1 digit once in a subset
  string used = string(9, '0');

  string num = "123456789";

  void util(int k, int n) {

    int i = curr.size();

    // if we used exact k digits
    if (i == k) {
      // check if exact sum found and this set of digits has not been stored
      if (n == sum and (hs.find(used) == hs.end())) {
        // insert this pattern of subsets as used
        hs.insert(used);
        // insert this subset
        ans.push_back(curr);
      }
      return;
    }
    for (auto c : num) {
      // extract a digit from 1-9
      int d = c - '0';
      // if digit is not used and current_sum + d does not exceed n
      if ((!(used[d - 1] - '0')) and (sum + d) <= n) {
        // we have two scenarios

        // 1. choose the digit
        used[d - 1] = '1'; // mark as used
        curr.push_back(d); // insert into current subset
        sum += d;          // update the sum
        util(k, n);        // backtrack

        // 2. not choose the digit
        used[d - 1] = '0'; // unmark the digit
        curr.pop_back();   // remove from current subset
        sum -= d;          // reset to old sum without current digit
      }
    }
  }
  vector<vector<int>> combinationSum3(int k, int n) {
    curr = {};
    util(k, n);
    return ans;
  }
};