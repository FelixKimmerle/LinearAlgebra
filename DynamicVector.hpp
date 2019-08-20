#pragma once

#include <vector>
#include <ostream>

template <class T>
class DynamicVector;
template <class T>
std::ostream &operator<<(std::ostream &out, const DynamicVector<T> &p_DynamicVector);

template <class T>
class DynamicVector
{
private:
    std::vector<T> m_Data;
    unsigned int m_uiSize;

public:
    DynamicVector(unsigned int p_uiSize, bool doinit = true);
    DynamicVector(const std::vector<T> &p_Data);
    ~DynamicVector();

    T &operator[](unsigned int index);
    T operator[](unsigned int index) const;
    T &at(unsigned int index);
    T at(unsigned int index) const;
    unsigned int Size() const;
    T Length() const;
    void normalize();

    DynamicVector<T> cross(const DynamicVector<T> &other) const;
    void cross(const DynamicVector<T> &other, DynamicVector<T> &result) const;

    void operator+=(T scalar);
    DynamicVector<T> operator+(T scalar) const;
    void add(T scalar, DynamicVector<T> &result) const;

    void operator-=(T scalar);
    DynamicVector<T> operator-(T scalar) const;
    void sub(T scalar, DynamicVector<T> &result) const;

    void operator*=(T scalar);
    DynamicVector<T> operator*(T scalar) const;
    void mul(T scalar, DynamicVector<T> &result) const;

    T dot(const DynamicVector<T> &other) const;
    T operator*(const DynamicVector<T> &other) const; //dot

    void operator/=(T scalar);
    DynamicVector<T> operator/(T scalar) const;
    void div(T scalar, DynamicVector<T> &result) const;

    //StaticMatrix<T, N, 1> transpose() const;
    //void transpose(StaticMatrix<T, N, 1> &result) const;

    void push_back(T p_Value);
    void pop_back();

    void Append(const DynamicVector<T> &other);
    DynamicVector Combine(const DynamicVector<T> &other);

    DynamicVector<T> &operator=(const std::vector<T> &init);

    friend std::ostream &operator<<<>(std::ostream &out, const DynamicVector<T> &p_DynamicVector);
};

#include "DynamicVector.tpp"