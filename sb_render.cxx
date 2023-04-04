#include "Menu.h"

namespace {

void sb_render(int& p) {
  std::cout << "Menu with " << p << std::endl;
}

Menu<int> sb(sb_render);
auto v2 = Menu<int>::root().declare("SB_RENDER", "submenu", sb);

}
