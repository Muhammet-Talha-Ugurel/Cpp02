/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugurel <mugurel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 04:53:41 by mugurel           #+#    #+#             */
/*   Updated: 2024/03/24 17:34:42 by mugurel          ###   ########.fr       */
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

		bool operator>( const Fixed &nbr ) const;
		bool operator<( const Fixed &nbr ) const;
		bool operator>=( const Fixed &nbr ) const;
		bool operator<=( const Fixed &nbr ) const;
		bool operator==( const Fixed &nbr ) const;
		bool operator!=( const Fixed &nbr ) const;

		Fixed operator+( const Fixed &nbr ) const;
		Fixed operator-( const Fixed &nbr ) const;
		Fixed operator*( const Fixed &nbr ) const;
		Fixed operator/( const Fixed &nbr ) const;

		Fixed& operator++( void );
		Fixed operator++( int );
		Fixed& operator--( void );
		Fixed operator--( int );

		static Fixed& min( Fixed &a, Fixed &b );
		static const Fixed& min( const Fixed &a, const Fixed &b );
		static Fixed& max( Fixed &a, Fixed &b );
		static const Fixed& max( const Fixed &a, const Fixed &b );
};

std::ostream& operator<<( std::ostream &out, const Fixed &nbr );
