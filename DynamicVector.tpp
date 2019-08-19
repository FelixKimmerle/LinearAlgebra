#include "DynamicVector.hpp"

template <class T>
DynamicVector<T>::DynamicVector(unsigned int p_uiSize, bool doinit) : m_uiSize(p_uiSize)
{
    if (doinit)
    {
        m_Data.resize(m_uiSize, 0);
    }
    else
    {
        m_Data.resize(m_uiSize);
    }
}

template <class T>
DynamicVector<T>::DynamicVector(const std::vector<T> &p_Data) : m_Data(p_Data), m_uiSize(p_Data.size())
{
}

template <class T>
DynamicVector<T>::~DynamicVector()
{
}

template <class T>
T &DynamicVector<T>::operator[](unsigned int index)
{
    return m_Data[index];
}

template <class T>
T DynamicVector<T>::operator[](unsigned int index) const
{
    return m_Data[index];
}

template <class T>
T &DynamicVector<T>::at(unsigned int index)
{
    return m_Data.at(index);
}

template <class T>
T DynamicVector<T>::at(unsigned int index) const
{
    return m_Data.at(index);
}

template <class T>
unsigned int DynamicVector<T>::Size() const
{
    return m_uiSize;
}

template <class T>
T DynamicVector<T>::Length() const
{
    T sum = T(0);
    for (auto &&item : m_Data)
    {
        sum += item * item;
    }
    return std::sqrt(sum);
}

template <class T>
void DynamicVector<T>::normalize()
{
    T factor = T(1) / Length();
    for (auto &&item : m_Data)
    {
        item *= factor;
    }
}

template <class T>
DynamicVector<T> DynamicVector<T>::cross(const DynamicVector<T> &other) const
{
    DynamicVector<T> result(3);
    result.m_Data[0] = m_Data[1] * other.m_Data[2] - m_Data[2] * other.m_Data[0];
    result.m_Data[1] = m_Data[2] * other.m_Data[0] - m_Data[0] * other.m_Data[2];
    result.m_Data[2] = m_Data[0] * other.m_Data[1] - m_Data[1] * other.m_Data[0];
    return result;
}

template <class T>
void DynamicVector<T>::cross(const DynamicVector<T> &other, DynamicVector<T> &result) const
{
    result.m_Data[0] = m_Data[1] * other.m_Data[2] - m_Data[2] * other.m_Data[0];
    result.m_Data[1] = m_Data[2] * other.m_Data[0] - m_Data[0] * other.m_Data[2];
    result.m_Data[2] = m_Data[0] * other.m_Data[1] - m_Data[1] * other.m_Data[0];
}

template <class T>
void DynamicVector<T>::operator+=(T scalar)
{
    for (auto &&item : m_Data)
    {
        item += scalar;
    }
}

template <class T>
DynamicVector<T> DynamicVector<T>::operator+(T scalar) const
{
    DynamicVector<T> result(m_uiSize);
    for (size_t i = 0; i < m_uiSize; i++)
    {
        result.m_Data[i] = m_Data[i] + scalar;
    }

    return result;
}

template <class T>
void DynamicVector<T>::add(T scalar, DynamicVector<T> &result) const
{
    for (size_t i = 0; i < m_uiSize; i++)
    {
        result.m_Data[i] = m_Data[i] + scalar;
    }
}

template <class T>
void DynamicVector<T>::operator-=(T scalar)
{
    for (auto &&item : m_Data)
    {
        item -= scalar;
    }
}
template <class T>
DynamicVector<T> DynamicVector<T>::operator-(T scalar) const
{
    DynamicVector<T> result(m_uiSize);
    for (size_t i = 0; i < m_uiSize; i++)
    {
        result.m_Data[i] = m_Data[i] - scalar;
    }

    return result;
}

template <class T>
void DynamicVector<T>::sub(T scalar, DynamicVector<T> &result) const
{
    for (size_t i = 0; i < m_uiSize; i++)
    {
        result.m_Data[i] = m_Data[i] - scalar;
    }
}

template <class T>
void DynamicVector<T>::operator*=(T scalar)
{
    for (auto &&item : m_Data)
    {
        item *= scalar;
    }
}
template <class T>
DynamicVector<T> DynamicVector<T>::operator*(T scalar) const
{
    DynamicVector<T> result(m_uiSize);
    for (size_t i = 0; i < m_uiSize; i++)
    {
        result.m_Data[i] = m_Data[i] * scalar;
    }

    return result;
}

template <class T>
void DynamicVector<T>::mul(T scalar, DynamicVector<T> &result) const
{
    for (size_t i = 0; i < m_uiSize; i++)
    {
        result.m_Data[i] = m_Data[i] * scalar;
    }
}

template <class T>
T DynamicVector<T>::dot(const DynamicVector<T> &other) const
{
    T sum = T(0);

    for (size_t i = 0; i < m_uiSize; i++)
    {
        sum += m_Data[i] * other.m_Data[i];
    }
    return sum;
}

template <class T>
T DynamicVector<T>::operator*(const DynamicVector<T> &other) const
{
    T sum = T(0);

    for (size_t i = 0; i < m_uiSize; i++)
    {
        sum += m_Data[i] * other.m_Data[i];
    }
    return sum;
}

template <class T>
void DynamicVector<T>::operator/=(T scalar)
{
    T factor = T(1) / scalar;
    for (auto &&item : m_Data)
    {
        item *= factor;
    }
}

template <class T>
DynamicVector<T> DynamicVector<T>::operator/(T scalar) const
{
    T factor = T(1) / scalar;
    DynamicVector<T> result(m_uiSize, false);
    for (size_t i = 0; i < m_uiSize; i++)
    {
        result.m_Data[i] = m_Data[i] * factor;
    }

    return result;
}

template <class T>
void DynamicVector<T>::div(T scalar, DynamicVector<T> &result) const
{
    T factor = T(1) / scalar;
    for (size_t i = 0; i < m_uiSize; i++)
    {
        result.m_Data[i] = m_Data[i] * factor;
    }
}
/*
template <class T, unsigned int N>
StaticMatrix<T, N, 1> StaticVector<T, N>::transpose() const
{
    StaticMatrix<T, N, 1> result(false);
    for (size_t i = 0; i < N; i++)
    {
        result.m_Data[0][i] = m_Data[i];
    }
    return result;
}

template <class T, unsigned int N>
void StaticVector<T, N>::transpose(StaticMatrix<T, N, 1> &result) const
{
    for (size_t i = 0; i < N; i++)
    {
        result.m_Data[0][i] = m_Data[i];
    }
}
*/

template <class T>
DynamicVector<T> &DynamicVector<T>::operator=(const std::vector<T> &init)
{
    m_Data = init;
    m_uiSize = init.size();
    return *this;
}

template <class T>
std::ostream &operator<<(std::ostream &out, const DynamicVector<T> &p_DynamicVector)
{
    out << "[DynamicVector " << p_DynamicVector.m_uiSize << "]" << std::endl;

    unsigned int maxsize = 0;
    bool fl = false;
    for (auto &&column : p_DynamicVector.m_Data)
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

    for (auto &&column : p_DynamicVector.m_Data)
    {
        out << std::setfill(' ') << std::setw(maxsize) << column << std::endl;
    }
    return out;
}