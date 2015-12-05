#include <ctime>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <iostream>

#include "matrix.h"

typedef std::vector< std::vector<int> > VMatrix;

void contentCheck(const VMatrix& v, const Matrix& mat) {
    const int n = mat.nRow();
    const int m = mat.nCol();
    bool valid = v.size() == static_cast<size_t>(n);
    valid = valid && v[0].size() == static_cast<size_t>(m);
    for (int i = 1; i <= n && valid; ++i)
        for (int j = 1; j <= m && valid; ++j)
            valid = valid && v[i-1][j-1] == mat(i, j);
    if (!valid) {
        puts("    content check fail");
        exit(1);
    }
}

void test1(const VMatrix& v, const Matrix& m) {
    puts("Test 1: constructors");
    contentCheck(v, m);
    puts("    PASS");
}

void test2(const VMatrix& v, const Matrix m) {
    puts("Test 2: constructors");
    contentCheck(v, m);
    puts("    PASS");
}

void test3(const VMatrix& v, Matrix& m) {
    puts("Test 3: constructors");
    contentCheck(v, m);
    puts("    PASS");
}

void test4(const VMatrix& v, Matrix m) {
    puts("Test 4: constructors");
    contentCheck(v, m);
    puts("    PASS");
}

void test5(const VMatrix& v, const Matrix& m) {
    puts("Test 5: operator=");
    Matrix mat(m.nRow(), m.nCol());
    mat = m;
    contentCheck(v, mat);
    puts("    PASS");
}

void test6(const VMatrix& v, const Matrix& m) {
    puts("Test 6: operator<< & operator>>");
    std::stringstream ss;
    ss << m;
    Matrix mat(m.nRow(), m.nCol());
    ss >> mat;
    contentCheck(v, mat);
    puts("    PASS");
}

void test7(VMatrix& v, Matrix& m) {
    puts("Test 7: operator()");
    const int x = 2, y = 3;
    v[x-1][y-1] = rand() % 100;
    m(x, y) = v[x-1][y-1];
    contentCheck(v, m);
    puts("    PASS");
}

void test8(const Matrix& m) {
    puts("Test 8: operator[][] const");
    const int r = m.nRow();
    const int c = m.nCol();
    for (int i = 1; i <= r; ++i)
        for (int j = 1; j <= c; ++j)
            if (m(i, j) != m[i][j]) {
                puts("    FAIL");
                exit(1);
            }
    puts("    PASS");
}

void test9(const Matrix& m) {
    puts("Test 9: operator[][]");
    const int r = m.nRow();
    const int c = m.nCol();
    Matrix mat(r, c);
    for (int i = 1; i <= r; ++i)
        for (int j = 1; j <= c; ++j) {
            mat[i][j] = m(i, j);
            if (mat(i, j) != m(i, j)) {
                puts("    FAIL");
                exit(1);
            }
        }
    puts("    PASS");
}

void test10(const VMatrix& v, Matrix m) {
    puts("Test 10: operator= self assignment");
    m = m;
    contentCheck(v, m);
    puts("    PASS");
}

void test11(const Matrix& m1) {
    puts("Test 11: operator==");
    bool valid = m1 == m1;
    if (valid) {
        Matrix m2(m1);
        ++m2(1, 1);
        valid = valid && !(m1 == m2);
    }
    if (!valid) {
        puts("    FAIL");
        exit(1);
    }
    puts("    PASS");
}

void test12(const Matrix& m) {
    puts("Test 12: operator+= self assignment");
    const int r = m.nRow();
    const int c = m.nCol();
    Matrix m2(m);
    m2 += m2;
    for (int i = 1; i <= r; ++i)
        for (int j = 1; j <= c; ++j)
            if (m2(i, j) != 2*m(i,j)) {
                puts("    FAIL");
                exit(1);
            }
    puts("    PASS");
}

void test13(const Matrix& m1, const Matrix& m2) {
    puts("Test 13: operator+ & operator+=");
    Matrix m(m1);
    m += m2;
    if (m == m1+m2) {
        puts("    PASS");
    } else {
        puts("    FAIL");
        exit(1);
    }
}

void test14(const Matrix& m1, const Matrix& m2) {
    puts("Test 14: operator+ chain");
    Matrix m = m1 + m2 + m2 + m1 + m1;
    const int r = m.nRow();
    const int c = m.nCol();
    for (int i = 1; i <= r; ++i)
        for (int j = 1; j <= c; ++j)
            if (m(i, j) != m1(i,j)*3 + m2(i,j)*2) {
                puts("    FAIL");
                exit(1);
            }
    puts("    PASS");
}

void test15(const Matrix& m1, const Matrix& m2) {
    puts("Test 15: operator+= chain");
    Matrix m(m1);
    (((m += m2) += m2) += m1) += m1;
    const int r = m.nRow();
    const int c = m.nCol();
    for (int i = 1; i <= r; ++i)
        for (int j = 1; j <= c; ++j)
            if (m(i, j) != m1(i,j)*3 + m2(i,j)*2) {
                puts("    FAIL");
                exit(1);
            }
    puts("    PASS");
}

void test16(const Matrix& mat) {
    puts("Test 15: operator= chain");
    const int r = mat.nRow();
    const int c = mat.nCol();
    Matrix m1(r, c);
    Matrix m2(r, c);
    Matrix m3(r, c);

    m1 = m2 = m3 = mat;

    bool valid = m1 == mat && m2 == mat && m3 == mat;
    if (valid) {
        ++m3(1, 1);
        valid = valid && !(m2 == m3);
    }
    if (valid) {
        puts("    PASS");
    } else {
        puts("    FAIL");
        exit(1);
    }
}

void test17() {
    puts("Test 17: heap storage");
    const int r = 8000;
    const int c = 12000;
    Matrix mat(r, c);
    for (int i = 1; i <= r; ++i)
        for (int j = 1; j <= c; ++j)
            mat(i, j) = rand();
    puts("    PASS");
}

void test18(const Matrix& m1, const Matrix& m2) {
    puts("Test 18: operator<< chain & operator>> chain");
    std::stringstream ss;
    ss << m1 << m2;
    Matrix mat1(m1.nRow(), m1.nCol());
    Matrix mat2(m2.nRow(), m2.nCol());
    ss >> mat1 >> mat2;
    if (m1 == mat1 && m2 == mat2) {
        puts("    PASS");
    } else {
        puts("    FAIL");
        exit(1);
    }
}

struct Foo {
    Matrix mat;
    Foo(): mat(8000, 10000) {}
};

bool test19_a(const Foo& foo, const Matrix& mat) {
    return foo.mat == mat;
}

bool test19_b(Foo& foo, const Matrix& mat) {
    return foo.mat == mat;
}

bool test19_c(Foo foo, const Matrix& mat) {
    return foo.mat == mat;
}

void test19() {
    puts("Test 19: user worry-free");
    Foo bar;
    Matrix mat(8000, 10000);
    for (int i = 1; i <= 8000; ++i)
        for (int j = 1; j <= 10000; ++j)
            bar.mat(i, j) = mat(i, j) = rand() % 10;
    if (!test19_a(bar, mat) || !test19_b(bar, mat) || !test19_c(bar, mat)) {
        puts("    FAIL");
        exit(1);
    }
    puts("    PASS");
}

void test20() {
    puts("Test 20: sizeof");
    Matrix m2(10000, 10000);
    if (sizeof m2 >= 100) {
        puts("    FAIL");
        exit(1);
    }
    puts("    PASS");
}

int main() {
    srand(static_cast<unsigned>(time(NULL)));

    const int n = 5, m = 7;
    VMatrix v(n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            v[i].push_back(rand() % 100);

    Matrix mat1(n, m);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            mat1(i, j) = v[i-1][j-1];
    Matrix mat2(n, m);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            mat2(i, j) = rand() % 100;


    test1(v, mat1);
    test2(v, mat1);
    test3(v, mat1);
    test4(v, mat1);
    test5(v, mat1);
    test6(v, mat1);
    test7(v, mat1);
    test8(mat1);
    test9(mat1);
    test10(v, mat1);
    test11(mat1);
    test12(mat1);
    test13(mat1, mat2);
    test14(mat1, mat2);
    test15(mat1, mat2);
    test16(mat1);
    test17();
    test18(mat1, mat2);
    test19();
    test20();

    puts("---------- Congratulations! ----------");
    puts("    You have passed all tests.");
    puts("    Watch out for CE TESTs");
    puts("                & Memory Leaks");


    // CE TESTs
    // Warning: The followings should cause you compilation error.
    //          If it passes the compilation, think carefully!
    //ce1(mat1);
    //ce2(mat1, mat2);
}

// CE TESTs
// Warning: The followings should cause you compilation error.
//          If it passes the compilation, think carefully!

//void ce1(const Matrix& m) {
//    puts("Compilation Error 1: operator[][]");
//    const int r = m.nRow();
//    const int c = m.nCol();
//    const Matrix mat(r, c);
//    for (int i = 1; i <= r; ++i)
//        for (int j = 1; j <= c; ++j) {
//            mat[i][j] = m(i, j);
//            if (mat(i, j) != m(i, j)) {
//                puts("    FAIL");
//                exit(1);
//            }
//        }
//    puts("    PASS");
//}
//
//void ce2(const Matrix& m1, const Matrix& m2) {
//    puts("Compilation Error 2: const operator+=");
//    m1 += m2;
//}
