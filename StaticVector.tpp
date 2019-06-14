#include "StaticVector.hpp"
#include "MathException.hpp"
#include "StaticMatrix.hpp"
#include <iomanip>
#include <cmath>

template <class T, unsigned int N>
T &StaticVector<T, N>::operator[](unsigned int index)
{
    return m_Data[index];
}

template <class T, unsigned int N>
T StaticVector<T, N>::operator[](unsigned int index) const
{
    return m_Data[index];
}

template <class T, unsigned int N>
T &StaticVector<T, N>::at(unsigned int index)
{
    return m_Data.at(index);
}

template <class T, unsigned int N>
T StaticVector<T, N>::at(unsigned int index) const
{
    return m_Data.at(index);
}

template <class T, unsigned int N>
unsigned int StaticVector<T, N>::Size() const
{
    return N;
}

template <class T, unsigned int N>
T StaticVector<T, N>::Length() const
{
    T sum = T(0);
    for (auto &&item : m_Data)
    {
        sum += item * item;
    }
    return std::sqrt(sum);
}

template <class T, unsigned int N>
void StaticVector<T, N>::normalize()
{
    T factor = T(1) / Length();
    for (auto &&item : m_Data)
    {
        item *= factor;
    }
}
template <class T, unsigned int N>
T StaticVector<T, N>::dot(const StaticVector<T, N> &other) const
{
    T sum = T(0);

    for (size_t i = 0; i < N; i++)
    {
        sum += m_Data[i] * other.m_Data[i];
    }
    return sum;
}
template <class T, unsigned int N>
StaticVector<T, 3> StaticVector<T, N>::cross(const StaticVector<T, 3> &other) const
{
    StaticVector<T, 3> result;
    result.m_Data[0] = m_Data[1] * other.m_Data[2] - m_Data[2] * other.m_Data[0];
    result.m_Data[1] = m_Data[2] * other.m_Data[0] - m_Data[0] * other.m_Data[2];
    result.m_Data[2] = m_Data[0] * other.m_Data[1] - m_Data[1] * other.m_Data[0];
    return result;
}

template <class T, unsigned int N>
void StaticVector<T, N>::operator+=(T scalar)
{
    for (auto &&item : m_Data)
    {
        item += scalar;
    }
}
template <class T, unsigned int N>
StaticVector<T, N> StaticVector<T, N>::operator+(T scalar) const
{
    StaticVector<T, N> result;
    for (size_t i = 0; i < N; i++)
    {
        result.m_Data[i] = m_Data[i] + scalar;
    }

    return result;
}

template <class T, unsigned int N>
void StaticVector<T, N>::operator-=(T scalar)
{
    for (auto &&item : m_Data)
    {
        item -= scalar;
    }
}
template <class T, unsigned int N>
StaticVector<T, N> StaticVector<T, N>::operator-(T scalar) const
{

    StaticVector<T, N> result;
    for (size_t i = 0; i < N; i++)
    {
        result.m_Data[i] = m_Data[i] - scalar;
    }

    return result;
}

template <class T, unsigned int N>
void StaticVector<T, N>::operator*=(T scalar)
{
    for (auto &&item : m_Data)
    {
        item *= scalar;
    }
}
template <class T, unsigned int N>
StaticVector<T, N> StaticVector<T, N>::operator*(T scalar) const
{
    StaticVector<T, N> result;
    for (size_t i = 0; i < N; i++)
    {
        result.m_Data[i] = m_Data[i] * scalar;
    }

    return result;
}

template <class T, unsigned int N>
T StaticVector<T, N>::operator*(const StaticVector<T, N> &other) const
{
    T sum = T(0);

    for (size_t i = 0; i < N; i++)
    {
        sum += m_Data[i] * other.m_Data[i];
    }
    return sum;
}

template <class T, unsigned int N>
void StaticVector<T, N>::operator/=(T scalar)
{
    T factor = T(1) / scalar;
    for (auto &&item : m_Data)
    {
        item *= factor;
    }
}
template <class T, unsigned int N>
StaticVector<T, N> StaticVector<T, N>::operator/(T scalar) const
{
    T factor = T(1) / scalar;
    StaticVector<T, N> result(false);
    for (size_t i = 0; i < N; i++)
    {
        result.m_Data[i] = m_Data[i] * factor;
    }

    return result;
}

template <class T, unsigned int N>
StaticMatrix<T, N, 1> StaticVector<T, N>::transpose() const
{
    StaticMatrix<T, N, 1> result(false);
    for (size_t i = 0; i < N; i++)
    {
        result[0][i] = m_Data[i];
    }
    return result;
}

template <class T, unsigned int N>
StaticVector<T, N> &StaticVector<T, N>::operator=(const std::array<T, N> &init)
{
    m_Data = init;
    return *this;
}

template <class T, unsigned int N>
std::ostream &operator<<(std::ostream &out, const StaticVector<T, N> &p_Vector)
{
    out << "[Vector " << N << "]" << std::endl;

    unsigned int maxsize = 0;
    bool fl = false;
    for (auto &&column : p_Vector.m_Data)
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
    if (fl)
    {
        out << std::fixed << std::setprecision(3);
        maxsize += 4;
    }
    else
    {
        out << std::defaultfloat;
    }

    for (auto &&column : p_Vector.m_Data)
    {
        out << std::setfill(' ') << std::setw(maxsize) << column << std::endl;
    }
    return out;
}

template <class T, unsigned int N>
StaticVector<T, N>::StaticVector(bool init)
{
    if (init)
    {
        std::fill(m_Data.begin(), m_Data.end(), T(0));
    }
}

template <class T, unsigned int N>
StaticVector<T, N>::StaticVector(const std::array<T, N> &init) : m_Data(init)
{
}

template <class T, unsigned int N>
StaticVector<T, N>::~StaticVector()
{
}
