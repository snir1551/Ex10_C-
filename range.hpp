#ifndef _RANGE_HPP
#define _RANGE_HPP
#include <iostream>
namespace itertools
{

    class iterator
    {
        private:
            int _num;

        public:
        iterator(int num): _num(num)
        {

        }
        iterator& operator++()
        {
            ++(this->_num);
            return *this;
        }
        const bool operator!=(const iterator& it) const
        {
            return (it._num != _num);
        }
        const int operator*() const
        {
            return this->_num;
        }
        const std::ostream& operator<<(const iterator& it) const
        {
            return std::cout << it._num;
        }


    };
    class range
    {
        private:
            int _begin, _end;
        
        public:
            range(int begin,int end): _begin(begin), _end(end)
            {
                
            }
            
            iterator begin()
            {
                return iterator(_begin);
            }
            iterator end()
            {
                return iterator(_end);
            }
    };




}
#endif