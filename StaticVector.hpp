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

    template <class TT, unsigned int NO>
    friend class StaticVector;

public:
    T &operator[](unsigned int index);
    T operator[](unsigned int index) const;
    T &at(unsigned int index);
    T at(unsigned int index) const;
    unsigned int Size() const;
    T Length() const;

    StaticVector<T, N> operator+(T scalar) const;
    StaticVector<T, N> operator-(T scalar) const;
    StaticVector<T, N> operator*(T scalar) const;
    StaticVector<T, N> operator/(T scalar) const;

    StaticVector<T, N> operator+(const StaticVector<T, N> &other) const;
    StaticVector<T, N> operator-(const StaticVector<T, N> &other) const;
    StaticVector<T, N> operator*(const StaticVector<T, N> &other) const; //not dot
    StaticVector<T, N> operator/(const StaticVector<T, N> &other) const;

    StaticVector<T, 3> cross(const StaticVector<T, 3> &other) const;
    StaticMatrix<T, N, 1> transpose() const;
    StaticVector<T, N> normalized() const;
    T dot(const StaticVector<T, N> &other) const;

    void operator+=(T scalar);
    void operator-=(T scalar);
    void operator*=(T scalar);
    void operator/=(T scalar);

    void operator+=(const StaticVector<T, N> &other);
    void operator-=(const StaticVector<T, N> &other);
    void operator*=(const StaticVector<T, N> &other);
    void operator/=(const StaticVector<T, N> &other);

    void normalize();

    void add(T scalar, StaticVector<T, N> &result) const;
    void sub(T scalar, StaticVector<T, N> &result) const;
    void mul(T scalar, StaticVector<T, N> &result) const;
    void div(T scalar, StaticVector<T, N> &result) const;

    void cross(const StaticVector<T, 3> &other, StaticVector<T, 3> &result) const;
    void transpose(StaticMatrix<T, N, 1> &result) const;
    void normalize(StaticVector<T, N> &result) const;

    template <unsigned int NO>
    StaticVector<T, N + NO> Combine(const StaticVector<T, NO> &other);

    StaticVector<T, N> &operator=(const std::array<T, N> &init);
    bool operator==(const StaticVector<T, N> &other) const;

    friend std::ostream &operator<<<>(std::ostream &out, const StaticVector<T, N> &p_Vector);

    StaticVector(bool init = true);
    StaticVector(const std::array<T, N> &init);
    StaticVector(const StaticVector<T, N> &other);
    ~StaticVector();
};

#include "StaticVector.tpp"