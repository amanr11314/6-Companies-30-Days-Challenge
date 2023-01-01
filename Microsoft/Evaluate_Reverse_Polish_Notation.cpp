#include <bits/stdc++.h>
using namespace std;
/*
https://leetcode.com/problems/evaluate-reverse-polish-notation/description/
*/
class Solution {
public:
  int evalRPN(vector<string> &tokens) {
    int result = 0;
    // use stack to keep track of operators and operands
    stack<string> s;
    string operations = "+-*/";
    for (auto &i : tokens) {
      // check if it is a operand then push directly to stack
      if (operations.find(i) == string::npos) {
        s.push(i);
      } else {
        // otherwise handle operations by taking two operands from stack
        int b = stoi(s.top());
        s.pop();
        // pre multiply by -1 in case of - for unary operation edge case
        if (i == "-") {
          b = b * -1;
        }
        // again check for empty stack
        if (s.size()) {
          int a = stoi(s.top());
          s.pop();
          // already applied if - so we do + here in both + and - case
          if (i == "+" || i == "-") {
            result = a + b;
          } else if (i == "*") {
            result = a * b;
          } else {
            result = a / b;
          }
        }
        // push again by converting operand into string
        s.push(to_string(result));
      }
    }
    // return integer form of result as reuired
    return stoi(s.top());
  }
};