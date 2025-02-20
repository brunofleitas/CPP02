/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:57:07 by bfleitas          #+#    #+#             */
/*   Updated: 2025/02/20 02:52:56 by bfleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
    std::cout << "\n[MANDATORY PART TESTS]" << std::endl;
    {
        Fixed a;
        Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
        std::cout << a << std::endl;
        std::cout << ++a << std::endl;
        std::cout << a << std::endl;
        std::cout << a++ << std::endl;
        std::cout << a << std::endl;
        std::cout << b << std::endl;
        std::cout << Fixed::max( a, b ) << std::endl;
    }

    std::cout << "\n[CONSTRUCTOR TESTS]" << std::endl;
    {
        Fixed a;
        Fixed b(10);
        Fixed c(42.42f);
        Fixed d(b);
        Fixed e;
        e = c;
        std::cout << "a: " << a << std::endl;
        std::cout << "b: " << b << std::endl;
        std::cout << "c: " << c << std::endl;
        std::cout << "d: " << d << std::endl;
        std::cout << "e: " << e << std::endl;
    }

    std::cout << "\n[COMPARISON OPERATORS TESTS]" << std::endl;
    {
        Fixed a(5);
        Fixed b(10);
        Fixed c(5);
        std::cout << "a = " << a << ", b = " << b << ", c = " << a << std::endl;
        std::cout << "a > b: " << (a > b) << std::endl;
        std::cout << "a < b: " << (a < b) << std::endl;
        std::cout << "a >= c: " << (a >= c) << std::endl;
        std::cout << "a <= b: " << (a <= b) << std::endl;
        std::cout << "a == c: " << (a == c) << std::endl;
        std::cout << "a != b: " << (a != b) << std::endl;
    }

    std::cout << "\n[ARITHMETIC OPERATORS TESTS]" << std::endl;
    {
        Fixed a(10);
        Fixed b(3);
        std::cout << "a = " << a << ", b = " << b << std::endl;
        std::cout << "a + b = " << (a + b) << std::endl;
        std::cout << "a - b = " << (a - b) << std::endl;
        std::cout << "a * b = " << (a * b) << std::endl;
        std::cout << "a / b = " << (a / b) << std::endl;
    }

    std::cout << "\n[INCREMENT DECREMENT TESTS]" << std::endl;
    {
        // Fixed a(5);
        Fixed a(5.5f);
        std::cout << "a = " << a << std::endl;
        std::cout << "++a = " << ++a << std::endl;
        std::cout << "a = " << a << std::endl;
        std::cout << "a++ = " << a++ << std::endl;
        std::cout << "a = " << a << std::endl;
        std::cout << "--a = " << --a << std::endl;
        std::cout << "a = " << a << std::endl;
        std::cout << "a-- = " << a-- << std::endl;
        std::cout << "a = " << a << std::endl;
    }

    std::cout << "\n[MIN MAX TESTS]" << std::endl;
    {
        Fixed a(10);
        Fixed b(20);
        Fixed const c(30);
        Fixed const d(40);
        std::cout << "a = " << a << ", b = " << b << std::endl;
        std::cout << "min(a,b) = " << Fixed::min(a, b) << std::endl;
        std::cout << "max(a,b) = " << Fixed::max(a, b) << std::endl;
        std::cout << "c = " << c << ", d = " << d << std::endl;
        std::cout << "min(c,d) = " << Fixed::min(c, d) << std::endl;
        std::cout << "max(c,d) = " << Fixed::max(c, d) << std::endl;
    }

    std::cout << "\n[SPECIAL CASES TESTS]" << std::endl;
    {
        Fixed a(0);
        Fixed b(0.0f);
        Fixed c(-42.42f);
        Fixed d(-42);
        std::cout << "Zero int: " << a << std::endl;
        std::cout << "Zero float: " << b << std::endl;
        std::cout << "Negative float: " << c << std::endl;
        std::cout << "Negative int: " << d << std::endl;
        Fixed small(0.00390625f);
        std::cout << "Smallest representable: " << small << std::endl;
        Fixed big(1234.4321f);
        std::cout << "Big number: " << big << std::endl;
    }

    return 0;
}