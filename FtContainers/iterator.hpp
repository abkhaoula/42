#ifndef ITERATOR_HPP
# define ITERATOR_HPP

namespace ft
{
	template < typename T >
	class iterator
	{
		public:

			typedef std::ptrdiff_t							difference_type;
			typedef T										value_type;
			typedef T*										pointer;
			typedef const T*								const_pointer;
			typedef T&										reference;
			typedef const T&								const_reference;
			typedef std::random_access_iterator_tag			iterator_category;
			typedef iterator< const T >						const_iterator;

			iterator(void)					:	_iter()				{};
			iterator(pointer iter)			:	_iter(iter)			{};
			iterator(const iterator& iter)	:	_iter(iter._iter)	{};
			~iterator(void)											{};

			pointer		base() const 			{	return  _iter;					};
			operator 	const_iterator () const	{	return const_iterator(_iter);	};

			iterator		operator = (const iterator& iter)									{	_iter = iter.base();	return  *this;	        		};
			iterator		operator + (difference_type n) const								{	return  iterator(base() + n);		            		};
			iterator&		operator ++ ()														{	_iter += 1;	return  *this;			            		};
			iterator		operator ++ (int)													{	iterator(tmp) = *this; _iter += 1; return  tmp;			};
			iterator&		operator += (difference_type n)										{	_iter += n;	return  *this;			            		};
			iterator		operator - (difference_type n) const 								{ 	return  iterator(base() - n); 		            		};
			iterator&		operator -- ()														{	_iter -= 1; return  *this;			            		};
			iterator		operator -- (int)													{	iterator(tmp) = *this; _iter--; return  tmp;			};
			iterator		operator-=(difference_type n)										{	_iter -= n;	return  *this;			            		};
			reference		operator*() 							                			{	return  *_iter;						            		};
			const_reference	operator*() const 						                			{	return  *_iter;						            		};
			pointer			operator->() 							                			{	return &(operator*());				            		};
			const_pointer	operator->() const 						                			{	return &(operator*());				            		};
			reference		operator[] (difference_type n) 										{	return  base()[n];					            		};
			const_reference	operator[] (difference_type n) const 								{ 	return  base()[n];	                            		};
			friend bool		operator == (const iterator& l_iter, const iterator& r_iter)		{	return  l_iter.base() == r_iter.base();	                };
			friend bool		operator != (const iterator& l_iter, const iterator& r_iter)		{	return  l_iter.base() != r_iter.base();	                };
			friend bool		operator > (const iterator& l_iter, const iterator& r_iter)			{	return  l_iter.base() > r_iter.base();	                };
			friend bool		operator <= (const iterator& l_iter, const iterator& r_iter)		{	return  l_iter.base() <= r_iter.base();	                };
			friend bool		operator < (const iterator& l_iter, const iterator& r_iter)			{	return  l_iter.base() < r_iter.base();	                };
			friend bool		operator >= (const iterator& l_iter, const iterator& r_iter)		{	return  l_iter.base() >= r_iter.base();	                };

		private:
			pointer	_iter;
	};

	template <typename U>
	iterator<U>	operator + ( typename iterator<U>::difference_type n, const iterator<U>& iter ){
    	return  iter + n;
    };

	template <typename U1, typename U2>
	typename iterator<U1>::difference_type operator - ( const iterator<U1>& l_iter,const iterator<U2>& r_iter ){
        return  l_iter.base() - r_iter.base();
    };
}

# endif