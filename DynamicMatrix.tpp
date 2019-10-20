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