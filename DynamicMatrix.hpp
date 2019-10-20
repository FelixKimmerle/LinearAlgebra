#pragma once

#include <vector>
#include <ostream>
#include <array>

template <class T>
class DynamicMatrix;
template <class T>

std::ostream &operator<<(std::ostream &out, const DynamicMatrix<T> &p_DynamicMatrix);

template <class T>
class DynamicVector;

template <class T>
class DynamicMatrix
{
private:
    std::vector<std::vector<T>> m_Data;

public:
    DynamicMatrix(const std::vector<std::vector<T>> &p_Data);
    DynamicMatrix(unsigned int x, unsigned int y);
    ~DynamicMatrix();
    std::vector<T> &operator[](unsigned int index);
    std::vector<T> operator[](unsigned int index) const;
    std::vector<T> &at(unsigned int index);
    std::vector<T> at(unsigned int index) const;
    unsigned int Width() const;
    unsigned int Height() const;

    void operator+=(T scalar);
    DynamicMatrix<T> operator+(T scalar) const;
    void add(T scalar, DynamicMatrix<T> &result) const;

    void operator-=(T scalar);
    DynamicMatrix<T> operator-(T scalar) const;
    void sub(T scalar, DynamicMatrix<T> &result) const;

    void operator*=(T scalar);
    DynamicMatrix<T> operator*(T scalar) const;
    void mul(T scalar, DynamicMatrix<T> &result) const;

    void operator/=(T scalar);
    DynamicMatrix<T> operator/(T scalar) const;
    void div(T scalar, DynamicMatrix<T> &result) const;

    DynamicMatrix<T> operator*(const DynamicMatrix<T> &other)const;
    void operator*=(const DynamicMatrix<T> &other);
    DynamicVector<T> operator*(const DynamicVector<T> &other)const;

    DynamicVector<T> cross(const DynamicVector<T> &other)const;

    friend std::ostream &operator<<<>(std::ostream &out, const DynamicMatrix<T> &p_Matrix);
};

#include "DynamicMatrix.tpp"