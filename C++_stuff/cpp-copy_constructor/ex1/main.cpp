/**
 * C++ program copying a Cube class.
 * 
 * @author
 *   Wade Fagen-Ulmschneider <waf@illinois.edu>
 */

#include "../Cube.h"
using uiuc::Cube;

void foo(Cube cube) {
  // Nothing :)
}

int main() {
  Cube c;
  foo(c);  // here c is copied onto foo()'s stack frame, so c's copy constructor is called

  return 0;
}
