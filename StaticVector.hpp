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
    StaticVector<T, 3> cross(const StaticVector<T, 3> &other) const;
    void cross(const StaticVector<T, 3> &other, StaticVector<T, 3> &result) const;

    void operator+=(T scalar);
    StaticVector<T, N> operator+(T scalar) const;
    void add(T scalar, StaticVector<T, N> &result) const;

    void operator-=(T scalar);
    StaticVector<T, N> operator-(T scalar) const;
    void sub(T scalar, StaticVector<T, N> &result) const;

    void operator*=(T scalar);
    StaticVector<T, N> operator*(T scalar) const;
    void mul(T scalar, StaticVector<T, N> &result) const;

    T dot(const StaticVector<T, N> &other) const;
    T operator*(const StaticVector<T, N> &other) const; //dot

    void operator/=(T scalar);
    StaticVector<T, N> operator/(T scalar) const;
    void div(T scalar, StaticVector<T, N> &result) const;

    StaticMatrix<T, N, 1> transpose() const;
    void transpose(StaticMatrix<T, N, 1> &result) const;

    StaticVector<T, N> &operator=(const std::array<T, N> &init);

    friend std::ostream &operator<<<>(std::ostream &out, const StaticVector<T, N> &p_Vector);

    StaticVector(bool init = true);
    StaticVector(const std::array<T, N> &init);
    ~StaticVector();
};

#include "StaticVector.tpp"