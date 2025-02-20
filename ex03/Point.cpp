/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 03:02:42 by bfleitas          #+#    #+#             */
/*   Updated: 2025/02/20 15:38:31 by bfleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

//Default constructor
Point::Point() : m_x(0), m_y(0)
{
}

//Float constructor
Point::Point(float const x, float const y) : m_x(x), m_y(y)
{
}

//Copy constructor
Point::Point(const Point& other) : m_x(other.m_x), m_y(other.m_y)
{
}

//Destructor
Point::~Point()
{
}

//Assignment operator (It's not possible to modify cons member variables)
Point& Point::operator=(const Point& other)
{
    (void)other;
    return *this;
}

//Getters
Fixed Point::getX() const
{
    return m_x;
}

Fixed Point::getY() const
{
    return m_y;
}