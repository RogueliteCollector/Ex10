#include "postfix.h"

#include <limits>
#include <stack>

#include "MyStack.h"

const unsigned char MAX_PRIORITY = std::numeric_limits<unsigned char>::max();

unsigned char priority(char c) {
  switch (c) {
    case '(':
      return 0;
    case ')':
      return 1;
    case '+':
    case '-':
      return 2;
    case '*':
    case '/':
      return 3;
    default:
      return MAX_PRIORITY;
  }
}

std::string infix2postfix(std::string infix) {
  std::string postfix;
  std::stack<char> ops;

  for (char c : infix) {
    if (priority(c) == MAX_PRIORITY) {
      if (!std::isspace(c)) {
        postfix.push_back(c);
      }
    } else if (c == '(') {
      ops.push(c);
    } else {
      if (!std::isspace(postfix.back())) {  // I hate spaces
        postfix.push_back(' ');
      }
      while (!ops.empty() && priority(ops.top()) >= priority(c)) {
        postfix.push_back(ops.top());
        postfix.push_back(' ');  // another space
        ops.pop();
      }
      if (c == ')') {
        ops.pop();
      } else {
        ops.push(c);
      }
    }
  }

  if (!std::isspace(postfix.back())) {  // I really hate spaces
    postfix.push_back(' ');
  }
  while (!ops.empty()) {
    postfix.push_back(ops.top());
    postfix.push_back(' ');  // half the program is special cases for spaces
    ops.pop();
  }
  postfix.pop_back();  // those spaces...

  return postfix;
}
