#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft
{
	template <typename iterator>
	class reverse_iterator
	{
		public:
			typedef iterator												iterator_type;
			typedef typename iterator_traits<iterator>::iterator_category	iterator_category;
			typedef typename iterator_traits<iterator>::value_type			value_type;
			typedef typename iterator_traits<iterator>::difference_type		difference_type;
			typedef typename iterator_traits<iterator>::pointer				pointer;
			typedef typename iterator_traits<iterator>::reference			reference;

			reverse_iterator()										:	_iter() 				{};
			reverse_iterator(iterator_type iter)					:	_iter(iter) 		    {};
			template <typename IT>
			reverse_iterator(const reverse_iterator<IT> & iter)		:	_iter(iter.base()) 		{};
            ~reverse_iterator()																    {};

            iterator_type	    base() const 	{ return _iter; };

			template <typename IT>
			reverse_iterator&	operator = (const reverse_iterator<IT>& other)  {	_iter = other.base(); return  *this;				};
			reverse_iterator	operator + (difference_type n) const 			{ 	return  reverse_iterator(_iter - n); 				};
			reverse_iterator&	operator ++ ()									{	--_iter;	return  *this;							};
			reverse_iterator	operator ++ (int)								{	reverse_iterator tmp = *this; --_iter; return  tmp;	};
			reverse_iterator&	operator += (difference_type n)					{	_iter -= n;	return  *this;							};
			reverse_iterator	operator - (difference_type n) const 			{	return  reverse_iterator(_iter + n); 				};
			reverse_iterator&	operator -- ()									{	++_iter;	return  *this;							};
			reverse_iterator	operator -- (int)								{	reverse_iterator tmp = *this; ++_iter; return  tmp;	};
			reverse_iterator	operator -= (difference_type n)					{	_iter += n;	return  *this;							};
			reference			operator*() const								{	iterator_type	tmp = _iter;	return *(--tmp);	};
			pointer				operator->() const 								{	return &(operator*());								};
			reference			operator[] (difference_type n) const 			{	return  base()[-n - 1];								};
        
        private:
			iterator _iter;
	};

	template <typename Iter1, typename Iter2>
	bool	operator == ( const reverse_iterator<Iter1>& l_iter, const reverse_iterator<Iter2>& r_iter )											{	return  l_iter.base() == r_iter.base();		};

	template <typename Iter1, typename Iter2>
	bool	operator != ( const reverse_iterator<Iter1>& l_iter, const reverse_iterator<Iter2>& r_iter )											{	return  l_iter.base() != r_iter.base();		};

	template <typename Iter1, typename Iter2>
	bool	operator < ( const reverse_iterator<Iter1>& l_iter, const reverse_iterator<Iter2>& r_iter )												{	return  l_iter.base() > r_iter.base();		};

	template <typename Iter1, typename Iter2>
	bool	operator <= ( const reverse_iterator<Iter1>& l_iter, const reverse_iterator<Iter2>& r_iter )											{	return  l_iter.base() >= r_iter.base();		};

	template <typename Iter1, typename Iter2>
	bool	operator > ( const reverse_iterator<Iter1>& l_iter, const reverse_iterator<Iter2>& r_iter )												{	return  l_iter.base() < r_iter.base();		};

	template <typename Iter1, typename Iter2>
	bool 	operator >= ( const reverse_iterator<Iter1>& l_iter, const reverse_iterator<Iter2>& r_iter )											{	return  l_iter.base() <= r_iter.base();		};

	template <typename Iter>
	reverse_iterator<Iter>	operator + ( typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter>& iter)					{	return  iter + n;				};

	template <typename Iter1, typename Iter2>
	typename reverse_iterator<Iter1>::difference_type operator- ( const reverse_iterator<Iter1>& l_iter, const reverse_iterator<Iter2>& r_iter )	{	return  r_iter.base() - l_iter.base();	};

}

# endif