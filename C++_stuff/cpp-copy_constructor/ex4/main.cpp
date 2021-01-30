/**
 * C++ program copying a Cube class. 
 * 
 * @author
 *   Wade Fagen-Ulmschneider <waf@illinois.edu>
 */

#include "../Cube.h"
using uiuc::Cube;

int main() {
  Cube c;
  Cube myCube;

  myCube = c;  // NO copy constructor called, because no construction takes place -> both myCube and c already constructed

  return 0;
}
