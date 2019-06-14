#include "StaticMatrix.hpp"
#include "MathException.hpp"
#include <cmath>
#include <iomanip>

template <class T, unsigned int X, unsigned int Y>
T StaticMatrix<T, X, Y>::determinant(const std::array<std::array<T, Y>, X> &A, unsigned int n) const
{
    T D = T(0);
    if (n == 1)
    {
        return A[0][0];
    }
    std::array<std::array<T, Y>, X> temp;
    T sign = T(1);
    for (unsigned int f = 0; f < n; f++)
    {
        getCofactor(A, temp, 0, f, n);
        D += sign * A[0][f] * determinant(temp, n - 1);
        sign = -sign;
    }
    return D;
}

template <class T, unsigned int X, unsigned int Y>
void StaticMatrix<T, X, Y>::getCofactor(const std::array<std::array<T, Y>, X> &A, std::array<std::array<T, Y>, X> &temp, unsigned int p, unsigned int q, unsigned n) const
{
    unsigned int i = 0, j = 0;

    for (unsigned int row = 0; row < n; row++)
    {
        for (unsigned int col = 0; col < n; col++)
        {
            if (row != p && col != q)
            {
                temp[i][j++] = A[row][col];

                if (j == n - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

template <class T, unsigned int X, unsigned int Y>
std::array<T, Y> &StaticMatrix<T, X, Y>::operator[](unsigned int index)
{
    return m_Data[index];
}

template <class T, unsigned int X, unsigned int Y>
std::array<T, Y> StaticMatrix<T, X, Y>::operator[](unsigned int index) const
{
    return m_Data[index];
}

template <class T, unsigned int X, unsigned int Y>
std::array<T, Y> &StaticMatrix<T, X, Y>::at(unsigned int index)
{
    return m_Data.at(index);
}

template <class T, unsigned int X, unsigned int Y>
std::array<T, Y> StaticMatrix<T, X, Y>::at(unsigned int index) const
{
    return m_Data.at(index);
}

template <class T, unsigned int X, unsigned int Y>
unsigned int StaticMatrix<T, X, Y>::Width() const
{
    return X;
}

template <class T, unsigned int X, unsigned int Y>
unsigned int StaticMatrix<T, X, Y>::Height() const
{
    return Y;
}

template <class T, unsigned int X, unsigned int Y>
void StaticMatrix<T, X, Y>::operator+=(T scalar)
{
    for (auto &&row : m_Data)
    {
        for (auto &&item : row)
        {
            item += scalar;
        }
    }
}
template <class T, unsigned int X, unsigned int Y>
StaticMatrix<T, X, Y> StaticMatrix<T, X, Y>::operator+(T scalar) const
{
    StaticMatrix<T, X, Y> result;
    for (size_t x = 0; x < X; x++)
    {
        for (size_t y = 0; y < Y; y++)
        {
            result.m_Data[x][y] = m_Data[x][y] + scalar;
        }
    }

    return result;
}

template <class T, unsigned int X, unsigned int Y>
void StaticMatrix<T, X, Y>::operator-=(T scalar)
{
    for (auto &&row : m_Data)
    {
        for (auto &&item : row)
        {
            item -= scalar;
        }
    }
}
template <class T, unsigned int X, unsigned int Y>
StaticMatrix<T, X, Y> StaticMatrix<T, X, Y>::operator-(T scalar) const
{

    StaticMatrix<T, X, Y> result;
    for (size_t x = 0; x < X; x++)
    {
        for (size_t y = 0; y < Y; y++)
        {
            result.m_Data[x][y] = m_Data[x][y] - scalar;
        }
    }

    return result;
}

template <class T, unsigned int X, unsigned int Y>
void StaticMatrix<T, X, Y>::operator*=(T scalar)
{
    for (auto &&row : m_Data)
    {
        for (auto &&item : row)
        {
            item *= scalar;
        }
    }
}
template <class T, unsigned int X, unsigned int Y>
StaticMatrix<T, X, Y> StaticMatrix<T, X, Y>::operator*(T scalar) const
{
    StaticMatrix<T, X, Y> result;
    for (size_t x = 0; x < X; x++)
    {
        for (size_t y = 0; y < Y; y++)
        {
            result.m_Data[x][y] = m_Data[x][y] * scalar;
        }
    }

    return result;
}

template <class T, unsigned int X, unsigned int Y>
template <unsigned int OY>
StaticMatrix<T, X, OY> StaticMatrix<T, X, Y>::operator*(const StaticMatrix<T, Y, OY> &other) const
{
    StaticMatrix<T, X, OY> result;
    for (unsigned int x = 0; x < X; x++)
    {
        for (unsigned int y = 0; y < OY; y++)
        {
            for (unsigned int k = 0; k < Y; k++)
            {
                result[x][y] += m_Data[x][k] * other[k][y];
            }
        }
    }
    return result;
}

template <class T, unsigned int X, unsigned int Y>
StaticVector<T, X> StaticMatrix<T, X, Y>::operator*(const StaticVector<T, Y> &other) const
{
    StaticVector<T, X> result;
    for (unsigned int x = 0; x < X; x++)
    {
        for (unsigned int k = 0; k < Y; k++)
        {
            result[x] += m_Data[x][k] * other[k];
        }
    }
    return result;
}

template <class T, unsigned int X, unsigned int Y>
void StaticMatrix<T, X, Y>::operator/=(T scalar)
{
    T factor = T(1) / scalar;
    for (auto &&row : m_Data)
    {
        for (auto &&item : row)
        {
            item *= factor;
        }
    }
}
template <class T, unsigned int X, unsigned int Y>
StaticMatrix<T, X, Y> StaticMatrix<T, X, Y>::operator/(T scalar) const
{
    T factor = T(1) / scalar;
    StaticMatrix<T, X, Y> result;
    for (size_t x = 0; x < X; x++)
    {
        for (size_t y = 0; y < Y; y++)
        {
            result.m_Data[x][y] = m_Data[x][y] * factor;
        }
    }

    return result;
}
template <class T, unsigned int X, unsigned int Y>
template <unsigned int OY>
StaticMatrix<T, X, OY> StaticMatrix<T, X, Y>::cross(const StaticMatrix<T, Y, OY> &other) const
{
    StaticMatrix<T, X, OY> result;
    for (unsigned int x = 0; x < X; x++)
    {
        for (unsigned int y = 0; y < OY; y++)
        {
            for (unsigned int k = 0; k < Y; k++)
            {
                result[x][y] += m_Data[x][k] * other[k][y];
            }
        }
    }
    return result;
}

template <class T, unsigned int X, unsigned int Y>
T StaticMatrix<T, X, Y>::det() const
{
    if (X != Y)
    {
        throw MathException("Determinant is only defined for square matrices.");
    }
    else
    {
        T num1, num2, det = T(1), total = T(1); // Initialize result
        unsigned int index;

        // temporary array for storing row
        std::array<T, X> temp;
        std::array<std::array<T, Y>, X> mat = m_Data;

        //loop for traversing the diagonal elements
        for (unsigned int i = 0; i < X; i++)
        {
            index = i; // intialize the index

            //finding the index which has non zero value
            while (mat[index][i] == 0 && index < X)
            {
                index++;
            }
            if (index == X) // if there is non zero element
            {
                // the determinat of matrix as zero
                continue;
            }
            if (index != i)
            {
                //loop for swaping the diagonal element row and index row
                for (unsigned int j = 0; j < X; j++)
                {
                    std::swap(mat[index][j], mat[i][j]);

                    //determinant sign changes when we shift rows
                    //go through determinant properties
                    det = det * pow(-1, index - i);
                }
            }

            //storing the values of diagonal row elements
            for (unsigned int j = 0; j < X; j++)
            {
                temp[j] = mat[i][j];
            }
            //traversing every row below the diagonal element
            for (unsigned int j = i + 1; j < X; j++)
            {
                num1 = temp[i];   //value of diagonal element
                num2 = mat[j][i]; //value of next row element

                //traversing every column of row
                // and multiplying to every row
                for (unsigned int k = 0; k < X; k++)
                {
                    //multiplying to make the diagonal
                    // element and next row element equal
                    mat[j][k] = (num1 * mat[j][k]) - (num2 * temp[k]);
                }
                total = total * num1; // Det(kA)=kDet(A);
            }
        }

        //mulitplying the diagonal elements to get determinant
        for (unsigned int i = 0; i < X; i++)
        {
            det = det * mat[i][i];
        }

        return (det / total); //Det(kA)/k=Det(A);
    }
}
template <class T, unsigned int X, unsigned int Y>
void StaticMatrix<T, X, Y>::identity()
{
    unsigned int max = std::min(X, Y);
    for (size_t i = 0; i < max; i++)
    {
        m_Data[i][i] = T(1);
    }
}
template <class T, unsigned int X, unsigned int Y>
StaticMatrix<T, Y, X> StaticMatrix<T, X, Y>::transpose() const
{
    StaticMatrix<T, Y, X> result(false);
    for (size_t x = 0; x < X; x++)
    {
        for (size_t y = 0; y < Y; y++)
        {
            result[y][x] = m_Data[x][y];
        }
    }
    return result;
}

template <class T, unsigned int X, unsigned int Y>
StaticMatrix<T, X, Y> StaticMatrix<T, X, Y>::adjoint() const
{
    if (X != Y)
    {
        throw MathException("Adjoint is only defined for square matrices.");
    }
    else
    {
        StaticMatrix<T, X, Y> result;
        if (X == 1)
        {
            result[0][0] = 1;
        }
        else
        {
            T sign = T(1);
            std::array<std::array<T, Y>, X> temp;

            for (unsigned int i = 0; i < X; i++)
            {
                for (unsigned int j = 0; j < X; j++)
                {
                    getCofactor(m_Data, temp, i, j, X);
                    sign = ((i + j) % 2 == 0) ? T(1) : T(-1);
                    result[j][i] = sign * determinant(temp, X - 1);
                }
            }
        }
        return result;
    }
}

template <class T, unsigned int X, unsigned int Y>
void StaticMatrix<T, X, Y>::setadjoint()
{
    if (X != Y)
    {
        throw MathException("Adjoint is only defined for square matrices.");
    }
    else
    {
        std::array<std::array<T, Y>, X> result;
        if (X == 1)
        {
            result[0][0] = 1;
        }
        else
        {
            T sign = T(1);
            std::array<std::array<T, Y>, X> temp;

            for (unsigned int i = 0; i < X; i++)
            {
                for (unsigned int j = 0; j < X; j++)
                {
                    getCofactor(m_Data, temp, i, j, X);
                    sign = ((i + j) % 2 == 0) ? T(1) : T(-1);
                    result[j][i] = sign * determinant(temp, X - 1);
                }
            }
        }
        m_Data = result;
    }
}
template <class T, unsigned int X, unsigned int Y>
StaticMatrix<T, X, Y> StaticMatrix<T, X, Y>::inverse() const
{
    T d = det();
    if (d == T(0))
    {
        throw MathException("Singular matrix, can't find its inverse");
    }
    StaticMatrix<T, X, Y> adj = adjoint();
    return adj / d;
}

template <class T, unsigned int X, unsigned int Y>
void StaticMatrix<T, X, Y>::setinverse()
{
    T d = det();
    if (d == T(0))
    {
        throw MathException("Singular matrix, can't find its inverse");
    }
    m_Data = adjoint() / d;
}

template <class T, unsigned int X, unsigned int Y>
StaticVector<T, X> StaticMatrix<T, X, Y>::asvector() const
{
    if (Y != 1)
    {
        throw MathException("Matrix is not a vector.");
    }
    StaticVector<T, X> result(false);
    for (size_t i = 0; i < X; i++)
    {
        result[i] = m_Data[i][0];
    }
    return result;
}

template <class T, unsigned int X, unsigned int Y>
StaticMatrix<T, X, Y> &StaticMatrix<T, X, Y>::operator=(const std::array<std::array<T, Y>, X> &init)
{
    m_Data = init;
    return *this;
}

template <class T, unsigned int X, unsigned int Y>
std::ostream &operator<<(std::ostream &out, const StaticMatrix<T, X, Y> &p_Vector)
{
    out << "[Matrix " << X << "x" << Y << "]" << std::endl;

    unsigned int maxsize = 0;
    bool fl = false;
    for (auto &&row : p_Vector.m_Data)
    {
        for (auto &&column : row)
        {
            unsigned int size = ((int)column) > 0 ? (int)std::log10((int)std::abs(column)) + 1 : 1;
            if (column < 0)
            {
                size += 1;
            }
            if (size > maxsize)
            {
                maxsize = size;
            }
            fl = T((int)column) != column || fl;
        }
    }
    if (fl)
    {
        out << std::fixed << std::setprecision(3);
        maxsize += 4;
    }
    else
    {
        out << std::defaultfloat;
    }

    for (auto &&row : p_Vector.m_Data)
    {
        for (auto column = row.begin(); column != row.end(); column++)
        {
            out << std::setfill(' ') << std::setw(maxsize) << *column << (column == (row.end() - 1) ? "" : ", ");
        }
        out << std::endl;
    }
    return out;
}

template <class T, unsigned int X, unsigned int Y>
StaticMatrix<T, X, Y>::StaticMatrix(bool init)
{
    if (init)
    {
        for (size_t i = 0; i < X; i++)
        {
            std::fill(m_Data[i].begin(), m_Data[i].end(), T(0));
        }
    }
}

template <class T, unsigned int X, unsigned int Y>
StaticMatrix<T, X, Y>::StaticMatrix(const std::array<std::array<T, Y>, X> &init) : m_Data(init)
{
}

template <class T, unsigned int X, unsigned int Y>
StaticMatrix<T, X, Y>::~StaticMatrix()
{
}
