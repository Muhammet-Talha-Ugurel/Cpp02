/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugurel <mugurel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 04:53:41 by mugurel           #+#    #+#             */
/*   Updated: 2024/03/24 20:45:36 by mugurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Fixed {
	private:
		int variable;
		static const int bit8 = 8;
	public:
		Fixed();
		Fixed( const int nbr );
		Fixed( const Fixed &nbr );
		Fixed& operator=( const Fixed &);
		~Fixed();
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		Fixed( const float nbr );
		int toInt( void ) const;
		float toFloat( void ) const;
};

std::ostream& operator<<( std::ostream &out, const Fixed &nbr );
