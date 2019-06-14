#include "MathException.hpp"

MathException::MathException(const std::string p_Message) : m_Message(p_Message)
{
}

MathException::~MathException()
{
}

const char *MathException::what() const throw()
{
    return m_Message.c_str();
}