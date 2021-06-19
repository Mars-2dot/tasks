#ifndef GENERATE_H
#define GENERATE_H
#include <iostream>
#include <list>

#include "random.h"

class Generate : public Random
{
public:
    template <class T1>
    static typename T1* array(
        int row,
        int cal,
        T1 from = std::numeric_limits<T1>::min(),
        T1 to = std::numeric_limits<T1>::max() )
    {
        T1* array = new T1( row * cal );

        for ( int i = 0; i < row; i++ ) {
            for ( int j = 0; j < cal; j++ ) {
                array[i * ( row * cal ) + j] = get( from, to );
            }
        }

        return array;
    }

    template <class T1>
    static typename std::list<T1>* list(
        int size,
        T1 from = std::numeric_limits<T1>::min(),
        T1 to = std::numeric_limits<T1>::max() )
    {
        std::list<T1>* m_data = new std::list<T1>;

        for ( int i = 0; i < size; i++ ) {
            m_data->push_back( get( from, to ) );
        }

        return m_data;
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
    ~Generate();
};

#endif // GENERATE_H
