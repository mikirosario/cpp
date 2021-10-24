/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 22:55:32 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/24 21:51:13 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_H
# define ITER_H

#define GRN "\e[1;32m"
#define RST "\e[0m"

/*
** En la primera prueba supuse que la función pasada a iter devolvería una
** referencia a la variable tipo T, pero esperan que sea void.
**
** También me lié declarando el puntero al array (se me olvidó poner el
** asterisco, vamos xD), y creé un iter muy sui géneris que no solo aplicaba
** la función pasada sino que además hacía pruebas dentro para ahorrarme líneas
** en el main. O sea, un bicho que solo rulaba con mis funciones.
**
** Tampoco en el subject especificaban cómo tiene que ser la función que se
** pasa a iter, así que lo hice a la ventura pensando que era libre, y me
** devolvía una referencia de tipo T. Pues no, es de tipo void. :P
**
** Total, no casaba con la función print de la prueba de la escuela, y
** no supe arreglarlo durante la evaluación porque todavía me lío con los
** templates, y con las referencias a arrays - o sea se juntaron el hambre con
** las ganas de comer. xD Encima dan por sentado que la función recibe T const,
** pero ya lo hice con la idea de modificar lo que recibía. :p
**
** En fin. Para hacerlo funcionar tanto con mis funciones de prueba como con las
** de la escuela, he hecho una sobrecarga del template con y sin const.
*/

template<typename T, typename S>
void	iter(T * arr_ptr, S const arr_len, void (*fun)(T & a))
{
	for (S i = 0; i < arr_len; ++i)
		fun(arr_ptr[i]);
}

template<typename T, typename S>
void	iter(T * arr_ptr, S const arr_len, void (*fun)(T const & a))
{
	for (S i = 0; i < arr_len; ++i)
		fun(arr_ptr[i]);
}

template<typename T>
void	funky_func(T & a)
{
	a += 1;
}

template<typename T>
void	halve(T & a)
{
	a /= 2;
}

#endif
