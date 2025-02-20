/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:06:02 by bfleitas          #+#    #+#             */
/*   Updated: 2025/02/19 18:54:52 by bfleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//Insertion operator overload
std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}

//CONSTRUCTORS
//Default constructor
Fixed::Fixed() : m_value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

//Copy constructor
Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

//Int constructor
Fixed::Fixed(const int n) : m_value(n << m_fractBits)
{
    std::cout << "Int constructor called" << std::endl;
}

//Float constructor
Fixed::Fixed(const float n) : m_value(roundf(n * (1 << m_fractBits)))
{
    std::cout << "Float constructor called" << std::endl;
}

//Copy assignment operator
Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if(this != &other)
        this->m_value = other.getRawBits();
    return *this;
}

//Destructor
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

//Getter
int Fixed::getRawBits(void) const
{
    return this->m_value;
}

//Setter
void Fixed::setRawBits(int const raw)
{
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