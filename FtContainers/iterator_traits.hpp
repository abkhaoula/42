#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

#include "enable_if.hpp"

	namespace ft {
		template < class iterator >
		struct iterator_traits
		{
			typedef typename iterator::difference_type		difference_type;
			typedef typename iterator::value_type			value_type;
			typedef typename iterator::pointer				pointer;
			typedef typename iterator::reference			reference;
			typedef typename iterator::iterator_category	iterator_category;
		};

		template < class T >
		struct iterator_traits< T* >
		{
			typedef std::ptrdiff_t							difference_type;
			typedef T										value_type;
			typedef T*										pointer;
			typedef T&										reference;
			typedef std::random_access_iterator_tag			iterator_category;
		};

		template <class T>
		struct iterator_traits<const T*>
		{
			typedef std::ptrdiff_t							difference_type;
			typedef T										value_type;
			typedef const T*								pointer;
			typedef const T&								reference;
			typedef std::random_access_iterator_tag			iterator_category;
		};

		template<typename InputIt>
		typename iterator_traits<InputIt>::difference_type distance(InputIt first, InputIt last, typename ft::enable_if<!ft::is_integral<InputIt>::value>::type* = 0)
		{
			typename iterator_traits<InputIt>::difference_type n = 0;

			while ((first + n) != last)
			{
				n++;
				first++;
			}
			return n;
		}
	}

# endif