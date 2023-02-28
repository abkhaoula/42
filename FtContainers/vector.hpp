#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>
#include "iterator.hpp"
#include "reverse_iterator.hpp"


namespace ft {

    template<class T, class Allocator = std::allocator<T>>

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
			typedef typename iterator_traits<iterator>::difference_type		difference_type;

			//
			typedef ft::reverse_iterator<iterator>							reverse_iterator;

			//
			typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;

			//


			//
			vector(): _alloc(allocator_type()), _capacity(0) {}
			explicit vector( const Allocator& alloc ): _alloc(alloc), _capacity(0) { } // = Allocator()
			explicit vector( size_type count, const T& value = T(), const Allocator& alloc = Allocator()): _alloc(alloc), _capacity(count) {
				_data = _alloc.allocate(_capacity);
				for (size_type i = 0; i < _capacity; ++i) {
            		_alloc.construct(_data + i, value);
        		}
			}

			template< class InputIt >
			vector( InputIt first, InputIt last, const Allocator& alloc = Allocator() ){ // typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = u_nullptr
				difference_type num_elements = std::distance(first, last);
				_data = alloc.allocate(num_elements);
				std::copy(first, last, _data);
        		_capacity = num_elements;
			}

			vector( const vector& other ): _alloc(other._alloc), _capacity(other._capacity)
    		{
        		_data = _alloc.allocate(_capacity);
        		for (size_type i = 0; i < _capacity; ++i) {
            		_alloc.construct(_data + i, other._data[i]);
        		}
    		}

			//
			~vector() {
				//clear();
        		_alloc.deallocate(_data, _capacity);
			}

			//
			vector& operator=( const vector& other ) {
				if (this != &other) {
            		//clear();
            		_alloc.deallocate(_data, _capacity);
            		_alloc = other._alloc;
            		_capacity = other._capacity;
            		_data = _alloc.allocate(_capacity);
            		for (size_type i = 0; i < _capacity; ++i) {
                		_alloc.construct(_data + i, other._data[i]);
            		}
        		}
        		return *this;
			}

			//
			void assign(size_type count, const T& value)
			{
				if (count > _capacity) {
					T* new_data = _alloc.allocate(count);
					_alloc.deallocate(_data, _capacity);
					_data = new_data;
					_capacity = count;
				}

    			_capacity = count;

    			for (size_type i = 0; i < _capacity; i++) {
        			_data[i] = value;
    			}
			}

			
			template< class InputIt >
			void assign( InputIt first, InputIt last ) {
				difference_type num_elements = std::distance(first, last);
				if (num_elements > _capacity) {
					T* new_data = _alloc.allocate(num_elements);
					_alloc.deallocate(_data, _capacity);
					_data = new_data;
					_capacity = num_elements;
    			}
    			else if (num_elements <= _capacity) {
        			std::copy(first, last, _data);
        			_capacity = num_elements;
    			}
    			else {
        			std::copy(first, first + _capacity, _data);
        			std::fill(_data + _capacity, _data + num_elements, *(last - 1));
        			_capacity = num_elements;
    			}
			}	

			

			// //
			// allocator_type get_allocator() const;

			// //
			// reference at( size_type pos );
			// const_reference at( size_type pos ) const;

			// //
			// reference operator[]( size_type pos );
			// const_reference operator[]( size_type pos ) const;

			// //
			// reference front();
			// const_reference front() const;

			// //
			// reference back();
			// const_reference back() const;

			// //
			// T* data();
			// const T* data() const;

			// //
			// iterator begin();
			// const_iterator begin() const;

			// //
			// iterator end();
			// const_iterator end() const;

			// //
			// reverse_iterator rbegin();
			// const_reverse_iterator rbegin() const;

			// //
			// reverse_iterator rend();
			// const_reverse_iterator rend() const;

			// //
			// bool empty() const;

			// //
			// size_type size() const;

			// //
			// size_type max_size() const;

			// //
			// template< class InputIt >
        	// void reserve( size_type new_cap );

			// //
			// size_type capacity() const;

			// //
			// void clear();

			// //
        	// iterator insert( const_iterator pos, const T& value );
        	// iterator insert( const_iterator pos, size_type count, const T& value );
        	// template< class InputIt >
        	// iterator insert( const_iterator pos, InputIt first, InputIt last );

			// //
			// iterator erase( iterator pos );
        	// iterator erase( iterator first, iterator last );

			// //
			// void push_back( const T& value );

			// //
			// void pop_back();

			// //
			// void resize( size_type count, T value = T() );

			// //
			// void swap(vector& other);

        private :
			Allocator	_alloc;
			size_type	_capacity;
			T*			_data;
			

    };

    
	//
	// template< class T, class Alloc >
	// bool operator==( const std::vector<T, Alloc>& lhs,
    //              const std::vector<T, Alloc>& rhs );

	// //
	// template< class T, class Alloc >
	// bool operator!=( const std::vector<T, Alloc>& lhs,
    //              const std::vector<T, Alloc>& rhs );
	
	// //
	// template< class T, class Alloc >
	// bool operator<( const std::vector<T, Alloc>& lhs,
    //             const std::vector<T, Alloc>& rhs );
	
	// //
	// template< class T, class Alloc >
	// bool operator<=( const std::vector<T, Alloc>& lhs,
    //              const std::vector<T, Alloc>& rhs );

	// //
	// template< class T, class Alloc >
	// bool operator>( const std::vector<T, Alloc>& lhs,
    //             const std::vector<T, Alloc>& rhs );
	
	// //
	// template< class T, class Alloc >
	// bool operator>=( const std::vector<T, Alloc>& lhs,
    //              const std::vector<T, Alloc>& rhs );

	// //
	// template< class T >
    // void swap( T& a, T& b );

	//


}

# endif