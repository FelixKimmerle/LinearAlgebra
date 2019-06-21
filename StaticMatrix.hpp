#pragma once

#include <array>

template <class T, unsigned int X, unsigned int Y>
class StaticMatrix;
template <class T, unsigned int X, unsigned int Y>
std::ostream &operator<<(std::ostream &out, const StaticMatrix<T, X, Y> &p_Matrix);

template <class T, unsigned int N>
class StaticVector;

template <class T, unsigned int X, unsigned int Y>
class StaticMatrix
{
private:
    std::array<std::array<T, Y>, X> m_Data;
    T determinant(const std::array<std::array<T, Y>, X> &A, unsigned int n) const;
    void getCofactor(const std::array<std::array<T, Y>, X> &A, std::array<std::array<T, Y>, X> &temp, unsigned int p, unsigned int q, unsigned n) const;

public:
    std::array<T, Y> &operator[](unsigned int index);
    std::array<T, Y> operator[](unsigned int index) const;
    std::array<T, Y> &at(unsigned int index);
    std::array<T, Y> at(unsigned int index) const;
    unsigned int Width() const;
    unsigned int Height() const;

    void operator+=(T scalar);
    StaticMatrix<T, X, Y> operator+(T scalar) const;
    void add(T scalar, StaticMatrix<T, X, Y> &result) const;

    void operator-=(T scalar);
    StaticMatrix<T, X, Y> operator-(T scalar) const;
    void sub(T scalar, StaticMatrix<T, X, Y> &result) const;

    void operator*=(T scalar);
    StaticMatrix<T, X, Y> operator*(T scalar) const;
    void mul(T scalar, StaticMatrix<T, X, Y> &result) const;

    void operator/=(T scalar);
    StaticMatrix<T, X, Y> operator/(T scalar) const;
    void div(T scalar, StaticMatrix<T, X, Y> &result) const;

    template <unsigned int OY>
    StaticMatrix<T, X, OY> operator*(const StaticMatrix<T, Y, OY> &other) const;

    StaticVector<T, X> operator*(const StaticVector<T, Y> &other) const;

    template <unsigned int OY>
    StaticMatrix<T, X, OY> cross(const StaticMatrix<T, Y, OY> &other) const;

    template <unsigned int OY>
    void cross(const StaticMatrix<T, Y, OY> &other, StaticMatrix<T, X, OY> &result) const;

    void cross(const StaticVector<T, Y> &other, StaticVector<T, X> &result) const;

    T det() const;

    void identity();

    StaticMatrix<T, Y, X> transpose() const;
    void transpose(StaticMatrix<T, Y, X> &result) const;

    StaticMatrix<T, X, Y> adjoint() const;
    void adjoint(StaticMatrix<T, X, Y> &result) const;
    void setadjoint();

    StaticMatrix<T, X, Y> inverse() const;
    void inverse(StaticMatrix<T, X, Y> &result) const;
    void setinverse();

    StaticVector<T, X> asvector() const;
    void asvector(StaticVector<T, X> &result) const;

    StaticMatrix<T, X, Y> &operator=(const std::array<std::array<T, Y>, X> &init);

    friend std::ostream &operator<<<>(std::ostream &out, const StaticMatrix<T, X, Y> &p_Matrix);

    StaticMatrix(bool init = true);
    StaticMatrix(const std::array<std::array<T, Y>, X> &init);
    StaticMatrix(const StaticMatrix<T, X, Y> &other);
    ~StaticMatrix();
};

#include "StaticMatrix.tpp"