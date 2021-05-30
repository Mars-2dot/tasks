#ifndef RANDOM_H
#define RANDOM_H
#include <random>
#include <iostream>
#include <list>

#include "mylist.h"

namespace details
{
template<class T>
struct is_uniform_int {
    static constexpr bool value =
        std::is_same<T,              short>::value ||
        std::is_same<T,                int>::value ||
        std::is_same<T,               long>::value ||
        std::is_same<T,          long long>::value ||
        std::is_same<T,     unsigned short>::value ||
        std::is_same<T,       unsigned int>::value ||
        std::is_same<T,      unsigned long>::value ||
        std::is_same<T, unsigned long long>::value;
};

template<class T>
struct is_uniform_real {
    static constexpr bool value =
        std::is_same<T,       float>::value ||
        std::is_same<T,      double>::value ||
        std::is_same<T, long double>::value;
};

template<class T>
struct is_uniform_pointer {
    static constexpr bool value =
        std::is_same<T,              short*>::value ||
        std::is_same<T,                int*>::value ||
        std::is_same<T,               long*>::value ||
        std::is_same<T,          long long*>::value ||
        std::is_same<T,     unsigned short*>::value ||
        std::is_same<T,       unsigned int*>::value ||
        std::is_same<T,      unsigned long*>::value ||
        std::is_same<T, unsigned long long*>::value;
};

template<class T>
struct is_uniform_list {
    static constexpr bool value =
        std::is_same<T,                        myList*>::value ||
        std::is_same<T,              std::list<short>*>::value ||
        std::is_same<T,                std::list<int>*>::value ||
        std::is_same<T,               std::list<long>*>::value ||
        std::is_same<T,          std::list<long long>*>::value ||
        std::is_same<T,     std::list<unsigned short>*>::value ||
        std::is_same<T,       std::list<unsigned int>*>::value ||
        std::is_same<T,      std::list<unsigned long>*>::value ||
        std::is_same<T, std::list<unsigned long long>*>::value;
};
}

class Random
{
    template <class T> using IntDist = std::uniform_int_distribution<T>;
    template <class T> using RealDist = std::uniform_real_distribution<T>;

public:
    template <class T>
    static typename std::enable_if<details::is_uniform_int<T>::value, T>::type get( T from = std::numeric_limits<T>::min(),
                                                                                    T to = std::numeric_limits<T>::max() )
    {
        if ( from > to ) {
            std::swap( from, to );
        }

        IntDist<T> dist{from, to};
        return dist( instance().engine() );
    }

    template <class T>
    static typename std::enable_if<details::is_uniform_real<T>::value, T>::type get( T from = std::numeric_limits<T>::min(),
                                                                                     T to = std::numeric_limits<T>::max() )
    {
        if ( from > to ) {
            std::swap( from, to );
        }

        RealDist<T> dist{from, to};
        return dist( instance().engine() );
    }

    template <class T1, typename  T2>
    static typename std::enable_if<details::is_uniform_pointer<T2>::value, T2>::type array(
        T2 array,
        int size,
        T1 from = std::numeric_limits<T1>::min(),
        T1 to = std::numeric_limits<T1>::max() )
    {
        for ( int i = 0; i < size; i++ ) {
            array[i] = get( from, to );
        }

        return array;
    }

    template <class T1, typename  T2>
    static typename std::enable_if<details::is_uniform_list<T2>::value, T2>::type list(
        T2 list,
        int size,
        T1 from = std::numeric_limits<T1>::min(),
        T1 to = std::numeric_limits<T1>::max() )
    {
        for ( int i = 0; i < size; i++ ) {
            list->push_back( get( from, to ) );
        }

        return list;
    }

    template <class T1, typename  T2>
    static typename std::enable_if<details::is_uniform_list<T2>::value, T2>::type list_recurent(
        T2 list,
        int size,
        T1 from = std::numeric_limits<T1>::min(),
        T1 to = std::numeric_limits<T1>::max() )
    {
        int recurrent = get( 0, size );
        T1 temp_g = ( T1 )0;

        for ( int i = 0; i < size; i++ ) {
            T1 temp = get( from, to );
            list->push_back( temp );

            if ( recurrent == i ) {
                if ( temp_g == ( T1 )0 ) {
                    temp_g = temp;
                } else {
                    list->push_back( temp_g );
                    temp_g = ( T1 )0;
                }

                recurrent = get( i, size );
            }
        }

        return list;
    }

    std::mt19937& engine()
    {
        return mt;
    }

protected:
    static Random& instance()
    {
        static Random instance;
        return instance;
    }

private:
    std::random_device randomDevice;
    std::mt19937 mt;

    Random() : mt( randomDevice() ) {}
    ~Random() {}
    Random( const Random& ) = delete;
    Random& operator = ( const Random& ) = delete;
};

#endif // RANDOM_H
