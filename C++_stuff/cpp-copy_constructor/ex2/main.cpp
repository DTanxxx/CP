/**
 * C++ program copying a Cube class.
 * 
 * @author
 *   Wade Fagen-Ulmschneider <waf@illinois.edu>
 */

#include "../Cube.h"
using uiuc::Cube;

Cube foo() {
  Cube c;
  return c;  // copy constructor called -> c copied onto main stack frame
}

int main() {
  Cube c2 = foo();  // copy constructor called -> c copied from main stack frame into variable c2 
  return 0;
}
