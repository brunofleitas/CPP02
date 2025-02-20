/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:06:02 by bfleitas          #+#    #+#             */
/*   Updated: 2025/02/20 03:00:42 by bfleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//CONSTRUCTORS
//Default constructor
Fixed::Fixed() : m_value(0)
{
}

//Copy constructor
Fixed::Fixed(const Fixed &other)
{
    *this = other;
}

//Int constructor
Fixed::Fixed(const int n) : m_value(n << m_fractBits)
{
}

//Float constructor
Fixed::Fixed(const float n) : m_value(roundf(n * (1 << m_fractBits)))
{
}

//Copy assignment operator
Fixed &Fixed::operator=(const Fixed &other)
{
    if(this != &other)
        this->m_value = other.getRawBits();
    return *this;
}

//Destructor
Fixed::~Fixed()
{
}

//Getter
int Fixed::getRawBits(void) const
{
    //std::cout << "getRawBits member function called" << std::endl;
    return this->m_value;
}

//Setter
void Fixed::setRawBits(int const raw)
{
    //std::cout << "setRawBits member function called" << std::endl;
    this->m_value = raw;
}

//METHODS (CONVERTERS)
float Fixed::toFloat(void) const
{
    return (float)m_value / (1 << m_fractBits);
}

int Fixed::toInt(void) const
{
    return m_value >> m_fractBits;
}

//Comparison operators
bool Fixed::operator>(const Fixed &other) const
{
    return this->getRawBits() > other.getRawBits();
}

bool Fixed::operator<(const Fixed &other) const
{
    return this->getRawBits() < other.getRawBits();
}

bool Fixed::operator>=(const Fixed &other) const
{
    return this->getRawBits() >= other.getRawBits();
}

bool Fixed::operator<=(const Fixed &other) const
{
    return this->getRawBits() <= other.getRawBits();
}

bool Fixed::operator==(const Fixed &other) const
{
    return this->getRawBits() == other.getRawBits();
}

bool Fixed::operator!=(const Fixed &other) const
{
    return this->getRawBits() != other.getRawBits();
}

//Aritmetic operatos
Fixed Fixed::operator+(const Fixed &other) const
{
    Fixed result;
    result.setRawBits(this->getRawBits() + other.getRawBits());
    return result;
}

Fixed Fixed::operator-(const Fixed &other) const
{
    Fixed result;
    result.setRawBits(this->getRawBits() - other.getRawBits());
    return result;
}

Fixed Fixed::operator*(const Fixed &other) const
{
    Fixed result;
    long temp = (long)this->getRawBits() * (long)other.getRawBits();
    result.setRawBits(temp >> m_fractBits);
    return result;
}

Fixed Fixed::operator/(const Fixed &other) const
{
    Fixed result;
    long temp = ((long)this->getRawBits() << m_fractBits) / (long)other.getRawBits();
    result.setRawBits(temp);
    return result;
}

//Increment-Decrement operators
Fixed &Fixed::operator++(void)
{
    this->m_value += (1 << m_fractBits);
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    this->m_value += (1 << m_fractBits);
    return temp;
}

Fixed &Fixed::operator--(void)
{
    this->m_value -= (1 << m_fractBits);
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    this->m_value -= (1 << m_fractBits);
    return temp;
}

//Min-max
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a > b) ? a : b;
}

//Insertion operator overload
std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}