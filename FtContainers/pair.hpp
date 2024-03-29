#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft
{
    template < typename T1, typename T2 >
    class pair
    {
        public:
            //
            typedef T1 first_type;
            //
            typedef T2 second_type;

            //
            T1 first;
            T2 second;
            //
            
            ///CONSTRUCTOR///
            //
            pair() {}
            //
            pair( const T1& x, const T2& y ): first(x), second(y) {}
            //
            template< class U1, class U2 >
            pair( const pair<U1, U2>& p ):	first(p.first), second(p.second) {}
            ///END_CONSTRUCTOR///

            ///OPERATOR///
			//
            pair& operator=( const pair& other )
            {
                if ( this != &other )
                {
                    first = other.first;
					second = other.second;
				}
				return *this;
            }
            ///END_OPERATOR///

			~pair() {};
    };
	//
	template< class T1, class T2 >
	std::pair<T1, T2> make_pair( T1 t, T2 u )
	{
		return pair< T1, T2 >( t, u );
	}
	//
	template< class T1, class T2, class U1, class U2 >
	bool operator==( const std::pair<T1, T2>& lhs, const std::pair<U1, U2>& rhs )
	{
		return lhs.first == rhs.first && lhs.second == rhs.second;
	}
	//
	template< class T1, class T2, class U1, class U2 >
	bool operator!=( const std::pair<T1, T2>& lhs, const std::pair<U1, U2>& rhs )
	{
		return !(lhs == rhs);
	}
	//
	template< class T1, class T2, class U1, class U2 >
	bool operator<( const std::pair<T1, T2>& lhs, const std::pair<U1, U2>& rhs )
	{
		return lhs.first < rhs.first || ((lhs.first <= rhs.first) && lhs.second < rhs.second);
	}
	//
	template< class T1, class T2, class U1, class U2 >
	bool operator<=( const std::pair<T1, T2>& lhs, const std::pair<U1, U2>& rhs )
	{
		return !(rhs < lhs);
	}
	//
	template< class T1, class T2, class U1, class U2 >
	bool operator>( const std::pair<T1, T2>& lhs, const std::pair<U1, U2>& rhs )
	{
		return rhs < lhs;
	}
	//
	template< class T1, class T2, class U1, class U2 >
	bool operator>=( const std::pair<T1, T2>& lhs, const std::pair<U1, U2>& rhs )
	{
		return !(lhs < rhs);
	}

}

# endif