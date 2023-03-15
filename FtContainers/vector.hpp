#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>
#include <stdexcept>
#include <iostream>
#include "iterator.hpp"
#include "reverse_iterator.hpp"
#include "enable_if.hpp"
#include "equal_compare.hpp"


namespace ft {

    template< class T, class Allocator = std::allocator<T> >

    class vector
    {
        public :

            //
            typedef T														value_type;
            //
            typedef Allocator												allocator_type;
            //
            typedef size_t													size_type;
			//
			typedef typename allocator_type::reference 						reference;
			//
			typedef typename allocator_type::const_reference				const_reference;
			//
			typedef typename allocator_type::pointer						pointer;
			//
			typedef typename allocator_type::const_pointer					const_pointer;
			//
			typedef ft::iterator< T >										iterator;
			//
			typedef ft::iterator< const T >									const_iterator;
			//
			typedef typename ft::iterator_traits<iterator>::difference_type		difference_type;
			//
			typedef ft::reverse_iterator<iterator>							reverse_iterator;
			//
			typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;


			///CONSTRUCTOR///
			//
			vector(): _alloc(allocator_type()), _capacity(0), _size(0), _data(NULL) {}
			//
			explicit vector( const Allocator& alloc ): _alloc(alloc), _capacity(0), _size(0), _data(NULL) {}
			//
			explicit vector( size_type count, const T& value = T(), const Allocator& alloc = Allocator()): _alloc(alloc), _capacity(count), _size(count), _data(NULL)
			{
				if (_capacity > max_size())
					throw std::length_error("allocation capacity exceeded");
				if (_capacity)
					_data = _alloc.allocate(_capacity);
				for (size_type i = 0; i < _size; ++i) {
            		_alloc.construct(_data + i, value);
        		}
			}
			//
			template< class InputIt >
			vector( InputIt first, InputIt last, const Allocator& alloc = Allocator(), typename ft::enable_if<!ft::is_integral<InputIt>::value>::type* = 0 ) : _alloc(alloc)
			{
    			while (first != last) {
        			push_back(*first);
        			++first;
    			}
			}
			//
			vector( const vector& other ): _alloc(other._alloc), _capacity(other._capacity), _size(other._size), _data(NULL)
    		{
        		if (_capacity)
					_data = _alloc.allocate(_capacity);
        		for (size_type i = 0; i < _capacity; ++i) {
            		_alloc.construct(_data + i, other._data[i]);
        		}
    		}
			///END_CONSTRUCTOR///

			///DESTRUCTOR///
			//
			~vector()
			{
				if (_capacity)
				{
					clear();
					_alloc.deallocate(_data, _capacity);
				}
			}
			///END_DESTRUCTOR///

			///OPERATOR///
			//
			vector& operator=( const vector& other )
			{
				if (this != &other) {
					for (size_type i = 0 ; i < _size ; i++)
						_alloc.destroy(_data + i);

					if (other._size > _capacity)
					{
						if (_data)
							_alloc.deallocate(_data, _capacity);
						_capacity = other._size;
						_data = _alloc.allocate(_capacity);
					}

					_size = other._size;
					for (size_type i = 0 ; i < _size ; i++)
						_alloc.construct(_data + i, other[i]);
        		}
        		return *this;
			}
			///END_OPERATOR///

			///ASSIGN///
			//
			void assign(size_type count, const T& value)
			{
				if (count > max_size())
					throw std::length_error("allocation capacity exceeded");
				clear();
				if (count > _capacity) {
					T* new_data = _alloc.allocate(count);
					if (_data)
						_alloc.deallocate(_data, _capacity);
					_data = new_data;
					_capacity = count;
				}

    			for (size_type i = 0; i < count; i++) {
        			_alloc.construct(_data + i, value);
    			}
				_size = count;
			}

			//
			template< class InputIt >
			void assign( InputIt first, InputIt last, typename ft::enable_if<!ft::is_integral<InputIt>::value>::type* = 0) {
				clear();
				
    			while (first != last) {
        			push_back(*first);
        			++first;
    			}
			}	
			///END_ASSIGN///
			
			///GETTER///
			//
			allocator_type get_allocator() const
			{
				return _alloc;
			};
			//
			reference at( size_type pos )
			{
				if (pos < _size) 
					return _data[pos];
				throw std::out_of_range("out ranged element");
			};
			//
			const_reference at( size_type pos ) const
			{
				if (pos < _size) 
					return _data[pos];
				throw std::out_of_range("out ranged element");
			}
			//
			reference operator[]( size_type pos )
			{
				return _data[pos];
			}
			const_reference operator[]( size_type pos ) const
			{
				return _data[pos];
			}
			//
			reference front()
			{
				return _data[0];
			}
			//
			const_reference front() const
			{
				return _data[0];
			}
			//
			reference back()
			{
				return _data[_size-1];
			}
			//
			const_reference back() const
			{
				return _data[_size-1];
			}
			//
			T* data()
			{
				return _data;
			}
			//
			const T* data() const
			{
				return _data;
			}
			//
			iterator begin()
			{
				return iterator(_data); 
			}
			//
			const_iterator begin() const
			{
				return const_iterator(_data); 
			}
			//
			iterator end()
			{
				return iterator(_data + _size);
			}
			//
			const_iterator end() const
			{
				return const_iterator(_data + _size);
			}
			//
			reverse_iterator rbegin()
			{
				return reverse_iterator(end());
			}
			//
			const_reverse_iterator rbegin() const
			{
				return const_reverse_iterator(end());
			}
			//
			reverse_iterator rend()
			{
				return reverse_iterator(begin());
			}
			//
			const_reverse_iterator rend() const
			{
				return const_reverse_iterator(begin());
			}
			//
			bool empty() const
			{
				return ( _size == 0 ); 
			}
			//
			size_type size() const
			{
				return _size;
			}
			//
			size_type max_size() const
			{
				return _alloc.max_size();
			}
			//
			size_type capacity() const
			{
				return _capacity;
			}
			///END_GETTER///
			
		
			

			

			///ALLOC_OP///
			//
        	void reserve( size_type new_cap )
			{
				if (new_cap <= _capacity)
					return ;
				if (new_cap > max_size())
					throw std::length_error("allocation capacity exceeded");
				T	*new_data = _alloc.allocate(new_cap);
				for (size_type i = 0; i < _size; i++)
				{
					_alloc.construct(&new_data[i], _data[i]);
					_alloc.destroy(&_data[i]);
				}
				if (_data)
					_alloc.deallocate(_data, _capacity);
				_data = new_data;
				_capacity = new_cap;
			}
			//
			iterator erase( iterator pos )
			{
				size_type index = pos - begin();

				_size --;
				_alloc.destroy(&_data[index]);
				for (size_type i = index; i < _size; i++)
				{
					_alloc.construct(&_data[i], _data[i + 1]);
					_alloc.destroy(&_data[i + 1]);
				}
				return iterator(&_data[index]);
			}
        	//
			iterator erase( iterator first, iterator last )
			{
				size_type l = last - first;

				while (first != end() - l)
				{
					(*first) = *(first + l);
					++first;
				}
				while (first != end())
				{
					_alloc.destroy(&(*first));
					++first;
				}
				_size -= l;
				return last - l;
			}
			//
			void clear()
			{
				erase(begin(), end());
			}
        	//
			iterator insert( const_iterator pos, size_type count, const T& value )
			{
				size_type i = pos - begin();

				if ((_size + count) > _capacity)
				{
					if ((_size + count) > max_size())
						throw std::length_error("allocation capacity exceeded");
					T	*new_data = _alloc.allocate(_size + count);
					for (size_type i = 0; i < _size; i++)
					{
						_alloc.construct(&new_data[i], _data[i]);
						_alloc.destroy(&_data[i]);
					}
					if(_data)
						_alloc.deallocate(_data, _capacity);
					_data = new_data;
					_capacity = _size + count;
				}
				for (size_type j = count + _size - 1; j > i + count - 1; j--)
				{
					_alloc.construct(&_data[j], _data[j - count]);
					_alloc.destroy(&_data[j - count]);
				}
				for (size_type k = i; k < i + count; k++)
				{
					_alloc.construct(&_data[k], value);
					_size++;
				}
				return begin() + i;
			}
        	//
			iterator insert( const_iterator pos, const T& value )
			{
				return (insert(pos, 1, value));
			}
        	//
			template< class InputIt >
        	iterator insert( const_iterator pos, InputIt first, InputIt last, typename ft::enable_if<!ft::is_integral<InputIt>::value>::type* = 0)
			{
				difference_type offset = pos - begin();
    
    			for (; first != last; ++first) {
        			insert(begin() + offset, *first);
        		++offset;
    			}
    
    			return begin() + offset;
			}
			//
			void push_back( const T& value )
			{
				if (_size == _capacity)
				{
					if (_size + 1 > max_size())
						throw std::length_error("allocation capacity exceeded");
					T	*new_data = _alloc.allocate(_size + 1);
					for (size_type i = 0; i < _size; i++)
					{
						_alloc.construct(&new_data[i], _data[i]);
						_alloc.destroy(&_data[i]);
					}
					if  (_data)
						_alloc.deallocate(_data, _capacity);
					_data = new_data;
					_capacity = _size + 1 ;
				}
				_size++;
				_alloc.construct(_data + _size - 1, value);
			}
			//
			void pop_back()
			{
				_alloc.destroy(&_data[_size - 1]);
				_size--;
			}
			//
			void resize( size_type count, T value = T())
			{
				while (count < _size)
					pop_back();
				while (count > _size)
					push_back(value);
			}
			//
			void swap(vector& other)
			{
				size_type	tmp;
				Allocator	tmp_a;
				T*			tmp_d;

				tmp_a = _alloc;
				_alloc = other._alloc;
				other._alloc = tmp_a;

				tmp = _capacity;
				_capacity = other._capacity;
				other._capacity = tmp;

				tmp = _size;
				_size = other._size;
				other._size = tmp;

				tmp_d = _data;
				_data = other._data;
				other._data = tmp_d;
			}
			///END_ALLOC_OP///

        private :
			Allocator	_alloc;
			size_type	_capacity;
			size_type	_size;
			T*			_data;
			

    };

    ///OPERATOR///
	//
	template< class T, class Alloc >
	bool operator==( const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs )
	{
		if (lhs.size() != rhs.size())
			return false;
		return ( ft::equal(lhs.begin(), lhs.end(), rhs.begin()) );
	}
	//
	template< class T, class Alloc >
	bool operator!=( const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs )
	{
		return !( lhs == rhs );
	}
	//
	template< class T, class Alloc >
	bool operator<( const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs )
	{
		return ( ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()) );
	}
	//
	template< class T, class Alloc >
	bool operator<=( const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs )
	{
		return !( lhs > rhs );
	}
	//
	template< class T, class Alloc >
	bool operator>( const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs )
	{
		return ( rhs < lhs );
	}
	//
	template< class T, class Alloc >
	bool operator>=( const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs )
	{
		return !( lhs < rhs );
	}
	//
	template< class T >
    void swap( T& a, T& b )
	{
		a.swap(b);
	}

	//


}

# endif