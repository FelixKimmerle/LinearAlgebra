#include <iostream>
#include "StaticVector.hpp"
#include "StaticMatrix.hpp"

int main()
{
    StaticMatrix<float, 3, 4> m({{{0, 1, 2, 3},
                                  {4, 5, 6, 7},
                                  {8, 9, 10, 11}}});

    StaticMatrix<float, 4, 3> m2({{{0, 1, 2},
                                   {4, 5, 6},
                                   {8, 9, 10},
                                   {8, 9, 10}}});

    std::cout << m * m2 << std::endl;

    std::cout << m << std::endl;

    StaticMatrix<float, 3, 2> m4({{
        {1, 2},
        {3, 4},
        {5, 6},
    }});

    std::cout << m4 << std::endl;
    std::cout << m4.transpose().transpose() << std::endl;

    StaticMatrix<float, 2, 2> m5({{{3, 0}, {0, 2}}});

    std::cout << m5 << std::endl;
    std::cout << m5.det() << std::endl;

    StaticVector<float, 3> sv({1, 0, 0});
    StaticVector<float, 3> sv2({0, 0, 1});
    StaticVector<float, 3> sv3(false);

    std::cout << "------------------" << std::endl;
    sv.cross(sv2, sv3);

    std::cout << sv3 << std::endl;

    StaticMatrix<float, 4, 3> id;
    id.identity();

    std::cout << id.transpose() << std::endl;

    StaticMatrix<float, 4, 4> madj({{{5, -2, 2, 7},
                                     {1, 0, 0, 3},
                                     {-3, 1, 5, 0},
                                     {3, -1, -9, 4}}});
    std::cout << madj.inverse() * madj << std::endl;

    StaticVector<float, 3> c({1, 0, 0});
    StaticVector<float, 3> c2({0, 1, 0});
    std::cout << c.cross(c2) / 100 << std::endl;

    StaticMatrix<float, 3, 3> mat({{{1, 1, -1},
                                    {0, 1, 3},
                                    {-1, 0, -2}}});
    StaticVector<float, 3> erg({9, 3, 2});

    std::cout << (mat.inverse() * erg) << std::endl;
    std::cout << sizeof(mat) << std::endl;
}
