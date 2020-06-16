#ifndef _ACCUMULATE_HPP
#define _ACCUMULATE_HPP
#include <iostream>

namespace itertools
{

    struct add
    {
        template<typename T>
        T operator()(T a, T b)
        {
            return a+b;
        }
    };


    template<typename Collection, typename Func>
    class Accumulate
    {
        public:
            template <typename ArgumentIterator, typename ValueType> 
            class iterator
            {
                private:
                    ArgumentIterator _argIterator;
                    ValueType _accumulatedValue;
                    Func _func;
                    bool _valueInitialized;

                public:
                    iterator(const ArgumentIterator& argIterator, const Func& func)
                        : _argIterator(argIterator), _func(func), _valueInitialized(false)
                    {
                        
                    }
                    void operator++()
                    {      
                        if(!_valueInitialized)
                        {
                        
                            _valueInitialized = true;
                            _accumulatedValue = *_argIterator;
                        } 
                        else
                        {
                            _accumulatedValue = _func(_accumulatedValue, *_argIterator);
                        }
                          
                       ++_argIterator;
                    }

                    bool operator!=(const iterator& it) const
                    {
                        return (_argIterator != it._argIterator);
                    }

                    ValueType operator*()
                    {
                        return _valueInitialized 
                         ? _func(_accumulatedValue, *_argIterator)
                         : *_argIterator;
                    }
            };

        private:
            const Collection& collection;
            Func func;

        public:
            Accumulate(const Collection& collection, const Func& func): collection(collection), func(func)
            {

            }

            iterator<decltype(collection.begin()), typename Collection::value_type> begin()
            {
                return iterator<decltype(collection.begin()), typename Collection::value_type>
                         (collection.begin(), func);
            }

            iterator<decltype(collection.end()), typename Collection::value_type> end()
            {
                return iterator<decltype(collection.end()), typename Collection::value_type>(collection.end(), func);
            }
    };

    template <typename Collection, typename Func = add>
    Accumulate<Collection, Func> accumulate(const Collection& collection, const Func& func = add())
    {
        return Accumulate<Collection, Func>(collection, func);
    }
}
#endif