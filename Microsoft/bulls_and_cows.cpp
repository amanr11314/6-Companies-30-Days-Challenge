#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string getHint(string secret, string guess) {
    int a = 0;
    int fs[10] = {0};
    int fg[10] = {0};
    for (int i = 0; i < secret.size(); ++i) {
      int x = secret[i] - '0';
      int y = guess[i] - '0';
      if (x == y)
        ++a;
      else {
        fs[x]++;
        fg[y]++;
      }
    }
    int b = 0;
    for (int i = 0; i < 10; ++i) {
      if (fs[i] && fg[i])
        b += min(fs[i], fg[i]);
    }
    string ans = to_string(a) + "A" + to_string(b) + "B";
    return ans;
  }
};