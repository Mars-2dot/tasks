// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#ifndef RANDOM_H
#define RANDOM_H
#include <random>
#include <iostream>

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
