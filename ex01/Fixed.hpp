/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:05:58 by bfleitas          #+#    #+#             */
/*   Updated: 2025/02/19 18:33:17 by bfleitas         ###   ########.fr       */
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
};


//Insertion operator overload
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
