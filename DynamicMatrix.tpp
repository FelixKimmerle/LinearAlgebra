#include "DynamicMatrix.hpp"
#include <iomanip>

template <class T>
DynamicMatrix<T>::~DynamicMatrix()
{
}

template <class T>
DynamicMatrix<T>::DynamicMatrix(const std::vector<std::vector<T>> &p_Data)
{
    m_Data = p_Data;
}

template <class T>
DynamicMatrix<T>::DynamicMatrix(unsigned int x, unsigned int y)
{
    m_Data.resize(x);
    for (auto &&data : m_Data)
    {
        data.resize(y);
    }
}

template <class T>
void DynamicMatrix<T>::operator+=(T scalar)
{
    for (auto &&row : m_Data)
    {
        for (auto &&item : row)
        {
            item += scalar;
        }
    }
}
template <class T>
DynamicMatrix<T> DynamicMatrix<T>::operator+(T scalar) const
{
    DynamicMatrix<T> result;
    for (size_t x = 0; x < X; x++)
    {
        for (size_t y = 0; y < Y; y++)
        {
            result.m_Data[x][y] = m_Data[x][y] + scalar;
        }
    }

    return result;
}

template <class T>
void DynamicMatrix<T>::add(T scalar, DynamicMatrix<T> &result) const
{
    for (size_t x = 0; x < X; x++)
    {
        for (size_t y = 0; y < Y; y++)
        {
            result.m_Data[x][y] = m_Data[x][y] + scalar;
        }
    }
}

template <class T>
void DynamicMatrix<T>::operator-=(T scalar)
{
    for (auto &&row : m_Data)
    {
        for (auto &&item : row)
        {
            item -= scalar;
        }
    }
}

template <class T>
DynamicMatrix<T> DynamicMatrix<T>::operator-(T scalar) const
{
    DynamicMatrix<T> result;
    for (size_t x = 0; x < X; x++)
    {
        for (size_t y = 0; y < Y; y++)
        {
            result.m_Data[x][y] = m_Data[x][y] - scalar;
        }
    }
    return result;
}

template <class T>
void DynamicMatrix<T>::sub(T scalar, DynamicMatrix<T> &result) const
{
    for (size_t x = 0; x < X; x++)
    {
        for (size_t y = 0; y < Y; y++)
        {
            result.m_Data[x][y] = m_Data[x][y] - scalar;
        }
    }
}
template <class T>
void DynamicMatrix<T>::operator*=(T scalar)
{
    for (auto &&row : m_Data)
    {
        for (auto &&item : row)
        {
            item *= scalar;
        }
    }
}
template <class T>
DynamicMatrix<T> DynamicMatrix<T>::operator*(T scalar) const
{
    DynamicMatrix<T> result;
    for (size_t x = 0; x < X; x++)
    {
        for (size_t y = 0; y < Y; y++)
        {
            result.m_Data[x][y] = m_Data[x][y] * scalar;
        }
    }

    return result;
}
template <class T>
void DynamicMatrix<T>::mul(T scalar, DynamicMatrix<T> &result) const
{
    for (size_t x = 0; x < X; x++)
    {
        for (size_t y = 0; y < Y; y++)
        {
            result.m_Data[x][y] = m_Data[x][y] * scalar;
        }
    }
}

template <class T>
void DynamicMatrix<T>::operator/=(T scalar)
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
template <class T>
DynamicMatrix<T> DynamicMatrix<T>::operator/(T scalar) const
{
    T factor = T(1) / scalar;
    DynamicMatrix<T> result;
    for (size_t x = 0; x < X; x++)
    {
        for (size_t y = 0; y < Y; y++)
        {
            result.m_Data[x][y] = m_Data[x][y] * factor;
        }
    }

    return result;
}
template <class T>
void DynamicMatrix<T>::div(T scalar, DynamicMatrix<T> &result) const
{
    T factor = T(1) / scalar;
    for (size_t x = 0; x < X; x++)
    {
        for (size_t y = 0; y < Y; y++)
        {
            result.m_Data[x][y] = m_Data[x][y] * factor;
        }
    }
}

template <class T>
DynamicMatrix<T> DynamicMatrix<T>::operator*(const DynamicMatrix<T> &other) const
{
    DynamicMatrix<T> result;
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
template <class T>
void DynamicMatrix<T>::operator*=(const DynamicMatrix<T> &other)
{
    
}
template <class T>
DynamicVector<T> DynamicMatrix<T>::operator*(const DynamicVector<T> &other) const
{
    DynamicMatrix<T> result;
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

template <class T>
DynamicVector<T> DynamicMatrix<T>::cross(const DynamicVector<T> &other) const
{
    DynamicMatrix<T> result;
    for (unsigned int x = 0; x < X; x++)
    {
        for (unsigned int k = 0; k < Y; k++)
        {
            result[x] += m_Data[x][k] * other[k];
        }
    }
    return result;
}

template <class T>
std::ostream &operator<<(std::ostream &out, const DynamicMatrix<T> &p_Matrix)
{
    out << "[Matrix " << p_Matrix.m_Data.size() << "x" << p_Matrix.m_Data[0].size() << "]" << std::endl;

    unsigned int maxsize = 0;
    bool fl = false;
    for (auto &&row : p_Matrix.m_Data)
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

    for (auto &&row : p_Matrix.m_Data)
    {
        for (auto column = row.begin(); column != row.end(); column++)
        {
            out << std::setfill(' ') << std::setw(maxsize) << *column << (column == (row.end() - 1) ? "" : ", ");
        }
        out << std::endl;
    }
    return out;
}