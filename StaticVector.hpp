#pragma once

#include <array>

template <class T, unsigned int N>
class StaticVector;
template <class T, unsigned int N>
std::ostream &operator<<(std::ostream &out, const StaticVector<T, N> &p_Vector);

template <class T, unsigned int X, unsigned int Y>
class StaticMatrix;

template <class T, unsigned int N>
class StaticVector
{
private:
    std::array<T, N> m_Data;

public:
    T &operator[](unsigned int index);
    T operator[](unsigned int index) const;
    T &at(unsigned int index);
    T at(unsigned int index) const;
    unsigned int Size() const;
    T Length() const;
    void normalize();
    T dot(const StaticVector<T, N> &other) const;
    StaticVector<T, 3> cross(const StaticVector<T, 3> &other) const;

    void operator+=(T scalar);
    StaticVector<T, N> operator+(T scalar) const;

    void operator-=(T scalar);
    StaticVector<T, N> operator-(T scalar) const;

    void operator*=(T scalar);
    StaticVector<T, N> operator*(T scalar) const;
    T operator*(const StaticVector<T, N> &other) const; //dot product

    void operator/=(T scalar);
    StaticVector<T, N> operator/(T scalar) const;

    StaticMatrix<T, N, 1> transpose() const;

    StaticVector<T, N> &
    operator=(const std::array<T, N> &init);

    friend std::ostream &operator<<<>(std::ostream &out, const StaticVector<T, N> &p_Vector);

    StaticVector(bool init = true);
    StaticVector(const std::array<T, N> &init);
    ~StaticVector();
};

#include "StaticVector.tpp"