/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 03:02:30 by bfleitas          #+#    #+#             */
/*   Updated: 2025/02/20 15:26:18 by bfleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
    private:
        const Fixed m_x;
        const Fixed m_y;
    public:
        //Default constructor
        Point();
        //Float constructor
        Point(float const x, float const y);
        //Copy constructor
        Point(const Point& other);
        //Destructor
        ~Point();
        //Assignment operator
        Point& operator=(const Point& other);
        //Getters
        Fixed getX() const;
        Fixed getY() const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif