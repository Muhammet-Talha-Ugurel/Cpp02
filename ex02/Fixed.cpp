/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugurel <mugurel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 04:55:09 by mugurel           #+#    #+#             */
/*   Updated: 2024/03/24 18:16:32 by mugurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() {
    this->variable = 0;   
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &nbr) {
    this->variable = nbr.variable;
    std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed:: operator=(const Fixed& fixed) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this == &fixed) // Kendi nesnesine atama kontrolü
        return *this;
    this->variable = fixed.variable;
    return *this;
}

int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->variable;
}

void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    this->variable = raw;
}

Fixed::Fixed( const int nbr ) {
    std::cout << "Int constructor called" << std::endl;
    this->variable = nbr << Fixed::bit8;
}

Fixed::Fixed( const float nbr ) {
    std::cout << "Float constructor called" << std::endl;
    this->variable = (int)roundf(nbr * (1 << Fixed::bit8));
}

float Fixed::toFloat( void ) const {
    return (float)this->variable / (1 << Fixed::bit8);
}

int Fixed::toInt( void ) const {
    return this->variable >> Fixed::bit8;
}

std::ostream& operator<<( std::ostream &out, const Fixed &nbr ) {
    out << nbr.toFloat();
    return out;
}

bool Fixed::operator>( const Fixed &nbr ) const {
    return this->variable > nbr.variable;
}

bool Fixed::operator<( const Fixed &nbr ) const {
    return this->variable < nbr.variable;
}

bool Fixed::operator>=( const Fixed &nbr ) const {
    return this->variable >= nbr.variable;
}

bool Fixed::operator<=( const Fixed &nbr ) const {
    return this->variable <= nbr.variable;
}

bool Fixed::operator==( const Fixed &nbr ) const {
    return this->variable == nbr.variable;
}

bool Fixed::operator!=( const Fixed &nbr ) const {
    return this->variable != nbr.variable;
}

Fixed Fixed::operator+( const Fixed &nbr ) const {
    return Fixed(this->toFloat() + nbr.toFloat());
}

Fixed Fixed::operator-( const Fixed &nbr ) const {
    return Fixed(this->toFloat() - nbr.toFloat());
}

Fixed Fixed::operator*( const Fixed &nbr ) const {
    return Fixed(this->toFloat() * nbr.toFloat());
}

Fixed Fixed::operator/( const Fixed &nbr ) const {
    return Fixed(this->toFloat() / nbr.toFloat());
}

Fixed& Fixed::operator++( void ) {
    this->variable++;
    return *this;
}

Fixed Fixed::operator++( int ) {
    Fixed temp = *this;
    this->variable++;
    return temp;
}

Fixed& Fixed::operator--( void ) {
    this->variable--;
    return *this;
}

Fixed Fixed::operator--( int ) {
    Fixed temp = *this;
    this->variable--;
    return temp;
}

Fixed& Fixed::min( Fixed &a, Fixed &b ) {
    return a < b ? a : b;
}

const Fixed& Fixed::min( const Fixed &a, const Fixed &b ) {
    return a < b ? a : b;
}

Fixed& Fixed::max( Fixed &a, Fixed &b ) {
    return a > b ? a : b;
}

const Fixed& Fixed::max( const Fixed &a, const Fixed &b ) {
    return a > b ? a : b;
}

