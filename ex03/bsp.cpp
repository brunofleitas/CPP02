/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 03:03:02 by bfleitas          #+#    #+#             */
/*   Updated: 2025/02/20 16:18:12 by bfleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/*
    To check if a point is inside of a triangle we can calculate the area of the triangle
    and then after calculate the area of the triangle made with two points of the triangle
    and point, with all the posibilities (3) we can check if it is inside or not
    If some of the areas are 0 mean that the point is on the edge of the triangle
    Then after if the point is inside of triangle, the sum of the three areas are equal 
    to the total area.
*/

// Function to calculate the area of a triangle
static Fixed calculateArea(Point const p1, Point const p2, Point const p3)
{
    Fixed area = (p1.getX() * p2.getY() + p2.getX() * p3.getY() + p3.getX() * p1.getY() -
    p1.getY() * p2.getX() - p2.getY() * p3.getX() - p3.getY() * p1.getX()) / Fixed(2);
    return area < Fixed(0) ? area * Fixed(-1) : area;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed totalArea = calculateArea(a, b, c);

    Fixed area1 = calculateArea(point, b, c);
    Fixed area2 = calculateArea(a, point, c);
    Fixed area3 = calculateArea(a, b, point);
    
    if (area1 == Fixed(0) || area2 == Fixed(0) || area3 == Fixed(0))
        return false;
    
    return (totalArea == (area1 + area2 + area3));
}
