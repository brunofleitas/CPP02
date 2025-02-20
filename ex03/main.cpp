/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:57:07 by bfleitas          #+#    #+#             */
/*   Updated: 2025/02/20 15:51:24 by bfleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int main(void) {
    // Test cases
    Point a(0.0f, 0.0f);
    Point b(4.0f, 0.0f);
    Point c(2.0f, 4.0f);
    
    // Test points
    Point p1(2.0f, 2.0f);    // Inside
    Point p2(4.0f, 4.0f);    // Outside
    Point p3(2.0f, 0.0f);    // On edge (should return false)
    
    std::cout << "Point (2,2) is inside triangle: " << (bsp(a, b, c, p1) ? "true" : "false") << std::endl;
    std::cout << "Point (4,4) is inside triangle: " << (bsp(a, b, c, p2) ? "true" : "false") << std::endl;
    std::cout << "Point (2,0) is inside triangle: " << (bsp(a, b, c, p3) ? "true" : "false") << std::endl;
    
    return 0;
}