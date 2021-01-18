#include <iostream>
#include <string>

#include "postfix.h"

int main() {
  std::string s1("(a + 20x) * (1 - 21 * (6 - 3.2))");
  std::string s2 = infix2postfix(s1);
  std::cout << s2 << std::endl;
  return 0;
}
