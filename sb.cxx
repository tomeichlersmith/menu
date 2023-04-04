#include "Menu.h"

namespace {

void print_cmd(const std::string& cmd, int& p) {
  std::cout << " SB print cmd " << cmd << " with " << p << std::endl;
}

void increment(int& p) {
  std::cout << " " << p << " -> ";
  p++;
  p++;
  std::cout << p << std::endl;
}

Menu<int> sb;
auto s0 = sb.declare("THREE", "third command", print_cmd);
auto s1 = sb.declare("INC", "increment the target", increment);
auto v2 = Menu<int>::root().declare("SB", "submenu", sb);

}
