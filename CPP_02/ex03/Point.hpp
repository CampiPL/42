/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <jdepka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 19:06:40 by jdepka            #+#    #+#             */
/*   Updated: 2024/08/21 19:06:41 by jdepka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
    const Fixed _x;
    const Fixed _y;

public:
    Point();
    Point( const float x, const float y );
    Point( const Point &src );
    ~Point();

    Point&  operator=( const Point &rhs );

    Fixed getX( void ) const ;
    Fixed getY( void ) const ;
    
};

bool bsp( Point const a, Point const b, Point const c, Point const point );


#endif // POINT_HPP