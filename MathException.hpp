#pragma once
#include <exception>
#include <string>
class MathException : public std::exception
{
private:
    const std::string m_Message;

public:
    MathException(const std::string p_Message);
    ~MathException();
    const char *what() const throw();
};
