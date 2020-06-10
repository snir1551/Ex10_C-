#ifndef _ACCUMULATE_HPP
#define _ACCUMULATE_HPP
#include <iostream>

namespace itertools
{

    class plus
    {
        template<typename T>
        T operator()(T a, T b)
        {
            return a+b;
        }
    };

    class iterator1
    {
        private:
            int _data;
    
        public:
        iterator1(int data): _data(data)
        {

        }
        iterator1& operator++()
        {
            ++(this->_data);
            return *this;
        }
        const bool operator!=(const iterator1& it) const
        {
            return (it._data != _data);
        }
        const int operator*() const
        {
            return this->_data;
        }
        const std::ostream& operator<<(const iterator1& it) const
        {
            return std::cout << it._data;
        }
    
    };
 
    class accumulate
    {
        private:
            int _begin;
            int _end;
            int _num;

        public:


            template<typename Collection, typename Func = plus>
            accumulate(Collection collection, Func fun = plus()):_begin(*(collection.begin())), _end(*(collection.end()))
            {
                
            }


            iterator1 begin()
            {
                return iterator1(_begin);
            }
            iterator1 end()
            {
                return iterator1(_end);
            }
    };


}
#endif