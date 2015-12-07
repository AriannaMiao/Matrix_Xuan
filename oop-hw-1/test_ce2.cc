#include <cstdlib>
#include <vector>
#include <sstream>
#include <iostream>

#include "matrix.h"

// CE TESTs
// Warning: The followings should cause you compilation error.
//          If it passes the compilation, think carefully!

int main() {
    const Matrix m1(4, 5), m2(4, 5);
    m1 += m2;
}
