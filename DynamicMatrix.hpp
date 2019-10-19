#pragma once

#include <vector>
#include <ostream>
#include <array>

template <class T>
class DynamicMatrix;
template <class T>

std::ostream &operator<<(std::ostream &out, const DynamicMatrix<T> &p_DynamicMatrix);

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
    std::vector<T> operator[](unsigned int index)const;
    std::vector<T> &at(unsigned int index);
    std::vector<T> at(unsigned int index)const;
    unsigned int Width()const;
    unsigned int Height()const;
    
    friend std::ostream &operator<<<>(std::ostream &out, const DynamicMatrix<T> &p_Matrix);

};

#include "DynamicMatrix.tpp"