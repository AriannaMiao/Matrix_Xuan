#include <cstdlib>
#include <vector>
#include <sstream>
#include <iostream>

#include "matrix.h"

// CE TESTs
// Warning: The followings should cause you compilation error.
//          If it passes the compilation, think carefully!

int main() {
    const Matrix mat(4, 5);
    mat(1, 1) = 0;
}
