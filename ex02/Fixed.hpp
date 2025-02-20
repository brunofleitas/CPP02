/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:05:58 by bfleitas          #+#    #+#             */
/*   Updated: 2025/02/20 02:52:35 by bfleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>


class Fixed
{
    private:
	    int m_value;
	    static const int m_fractBits =8;
    public:
		//CONSTRUCTORS
	    //Default constructor
	    Fixed();
	    //Copy constructor
	    Fixed(const Fixed &other);
		//Int constructor
		Fixed(const int n);
		//Float constructor
		Fixed(const float n);
	    
		//COPY ASSIGNMENT OPERATOR
	    Fixed &operator=(const Fixed &other);
	    
		//DESTRUCTOR
	    ~Fixed();
	    
		//GETTERS
	    int getRawBits(void) const;
	    
		//SETTERS
	    void setRawBits(int const raw);

		//METHODS (CONVERTERS)
		float toFloat(void) const;
		int toInt(void) const;

		//Comparison operators
		bool operator>(const Fixed &other) const;
        bool operator<(const Fixed &other) const;
        bool operator>=(const Fixed &other) const;
        bool operator<=(const Fixed &other) const;
        bool operator==(const Fixed &other) const;
        bool operator!=(const Fixed &other) const;

		//Arithmetic operators
		Fixed operator+(const Fixed &other) const;
        Fixed operator-(const Fixed &other) const;
        Fixed operator*(const Fixed &other) const;
        Fixed operator/(const Fixed &other) const;

		// Increment-Decrement operators
        Fixed &operator++(void);
        Fixed operator++(int);
        Fixed &operator--(void);
        Fixed operator--(int);

		//Min-Max
		static Fixed &min(Fixed &a, Fixed &b);
        static const Fixed &min(const Fixed &a, const Fixed &b);
        static Fixed &max(Fixed &a, Fixed &b);
        static const Fixed &max(const Fixed &a, const Fixed &b);
};


//Insertion operator overload
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
