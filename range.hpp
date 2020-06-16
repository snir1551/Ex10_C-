#ifndef _RANGE_HPP
#define _RANGE_HPP
#include <iostream>
namespace itertools
{
    //iterator class
    class iterator
    {
        private:
            int _num; //parameter

        public:
        iterator(int num): _num(num)
        {

        }
        void operator++()
        {
            ++(this->_num);
        }
        bool operator!=(const iterator& it) const
        {
            return (it._num != _num);
        }
        int operator*() const
        {
            return this->_num;
        }


    };
    class range
    {
        private:
            int _begin, _end;
        
        public:
            typedef int value_type;

            range(int begin,int end): _begin(begin), _end(end)
            {
                
            }
            
            iterator begin() const
            {
                return iterator(_begin);
            }
            iterator end() const
            {
                return iterator(_end);
            }
    };




}
#endif