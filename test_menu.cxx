#include "Menu.h"

namespace {

void print_cmd(const std::string& cmd, int& p) {
  std::cout << " Ran command " << cmd << " with " << p << std::endl;
}

void increment(int& p) {
  std::cout << " " << p << " -> ";
  p++;
  std::cout << p << std::endl;
}

auto v0 = Menu<int>::root().declare("INC", "increment the target", increment);
auto v1 = Menu<int>::root().declare("ONE", "one command", print_cmd);

}

/**
 * test-menu executable
 *
 * A light executable that is useful for developing
 * the Menu apparatus. You can compile this executable
 * without the rest of pflib by executing the compiler
 * directly. In the tool directory,
 * ```
 * g++ -o test-menu test_menu.cxx Menu.cc -lreadline
 * ```
 */
int main(int argc, char* argv[]) {
  Menu<int>::root().render();
  try {
    int i = 3;
    Menu<int>::root().steer(i);
  } catch (std::exception& e) {
    fprintf(stderr, "Exception!  %s\n",e.what());
    return 1;
  }
  return 0;
}
