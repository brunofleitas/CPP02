/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleitas <bfleitas@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:05:58 by bfleitas          #+#    #+#             */
/*   Updated: 2025/02/19 12:52:33 by bfleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
            int m_value;
            static const int m_fractBits =8;
    public:
            //Default constructor
            Fixed();
            //Copy constructor
            Fixed(const Fixed &other);
            //Copy assignment operator
            Fixed &operator=(const Fixed &other);
            //Destructor
            ~Fixed();
            //Getter
            int getRawBits(void) const;
            //Setter
            void setRawBits(int const raw);
};

#endif
