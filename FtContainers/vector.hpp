namespace ft {

    template<class T, class Allocator = std::allocator<T>>

    class vector
    {
        public :

            //
            typedef T										value_type;

            //
            typedef Allocator								allocator_type;

            //
            typedef std::size_t								size_type;  //hum typename allocator_type::size_type

			//
			typedef std::ptrdiff_t							difference_type; //humm typename ft::iterator_traits<iterator>::difference_type

			//
			typedef value_type& 							reference; //humm typename allocator_type::reference

			//
			typedef const value_type&						const_reference; //humm typename allocator_type::const_reference

			//
			typedef Allocator::pointer						pointer;

			//
			typedef Allocator::const_pointer				const_pointer;

			//
			typedef T*										iterator; //humm ft::random_access_iterator<value_type>

			//
			typedef const T*								const_iterator; //humm ft::random_access_iterator<const value_type>

			//
			typedef std::reverse_iterator<iterator>			reverse_iterator;

			//
			typedef std::reverse_iterator<const_iterator>	const_reverse_iterator;

			//


			//
			vector() {}
			explicit vector( const Allocator& alloc ): _alloc(alloc) {  // = Allocator()

			}
			explicit vector( size_type count, const T& value = T(), const Allocator& alloc = Allocator()): _alloc(alloc), _size(count) {

			}
			template< class InputIt >
			vector( InputIt first, InputIt last, const Allocator& alloc = Allocator() ); // typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = u_nullptr
			vector( const vector& other );

			//
			~vector();

			//
			vector& operator=( const vector& other );

			//
			void assign( size_type count, const T& value );
			void assign( InputIt first, InputIt last );

			//
			allocator_type get_allocator() const;

			//
			reference at( size_type pos );
			const_reference at( size_type pos ) const;

			//
			reference operator[]( size_type pos );
			const_reference operator[]( size_type pos ) const;

			//
			reference front();
			const_reference front() const;

			//
			reference back();
			const_reference back() const;

			//
			T* data();
			const T* data() const;

			//
			iterator begin();
			const_iterator begin() const;

			//
			iterator end();
			const_iterator end() const;

			//
			reverse_iterator rbegin();
			const_reverse_iterator rbegin() const;

			//
			reverse_iterator rend();
			const_reverse_iterator rend() const;

			//
			bool empty() const;

			//
			size_type size() const;

			//
			size_type max_size() const;

			//
			template< class InputIt >
        	void reserve( size_type new_cap );

			//
			size_type capacity() const;

			//
			void clear();

			//
        	iterator insert( const_iterator pos, const T& value );
        	iterator insert( const_iterator pos, size_type count, const T& value );
        	template< class InputIt >
        	iterator insert( const_iterator pos, InputIt first, InputIt last );

			//
			iterator erase( iterator pos );
        	iterator erase( iterator first, iterator last );

			//
			void push_back( const T& value );

			//
			void pop_back();

			//
			void resize( size_type count, T value = T() );

			//
			void swap(vector& other);

        private :
			Allocator _alloc;

    }

    
	//
	template< class T, class Alloc >
	bool operator==( const std::vector<T, Alloc>& lhs,
                 const std::vector<T, Alloc>& rhs );

	//
	template< class T, class Alloc >
	bool operator!=( const std::vector<T, Alloc>& lhs,
                 const std::vector<T, Alloc>& rhs );
	
	//
	template< class T, class Alloc >
	bool operator<( const std::vector<T, Alloc>& lhs,
                const std::vector<T, Alloc>& rhs );
	
	//
	template< class T, class Alloc >
	bool operator<=( const std::vector<T, Alloc>& lhs,
                 const std::vector<T, Alloc>& rhs );

	//
	template< class T, class Alloc >
	bool operator>( const std::vector<T, Alloc>& lhs,
                const std::vector<T, Alloc>& rhs );
	
	//
	template< class T, class Alloc >
	bool operator>=( const std::vector<T, Alloc>& lhs,
                 const std::vector<T, Alloc>& rhs );

	//
	template< class T >
    void swap( T& a, T& b );

	//


}