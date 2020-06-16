#ifndef _FILTERFALSE_HPP
#define _FILTERFALSE_HPP

namespace itertools
{ 
    template<typename Collection, typename Func>
    class Filterfalse
    {
        public:
            template <typename ArgumentIterator, typename ValueType> 
            class iterator
            {
                private:
                    ArgumentIterator _argIterator, _end;
                    Func _func;
                    bool _initialized;

                public:
                    iterator(const ArgumentIterator& begin, const ArgumentIterator& end, const Func& func)
                        : _argIterator(begin), _end(end), _func(func), _initialized(false)
                    {
                        ++(*this);
                    }
                    void operator++()
                    {      
                        if(_initialized)
                        {
                             ++_argIterator;
                        }
                        else
                        {
                            _initialized = true;
                        }
                        
                        while(_argIterator != _end && _func(*_argIterator))
                        {
                            ++_argIterator;
                        }
                    }

                    bool operator!=(const iterator& it) const
                    {
                        return (_argIterator != it._argIterator);
                    }

                    ValueType operator*()
                    {
                        return *_argIterator;
                    }
            };

        private:
            const Collection& collection;
            Func func;

        public:
            Filterfalse(const Collection& collection, const Func& func): collection(collection), func(func)
            {

            }

            iterator<decltype(collection.begin()), typename Collection::value_type> begin()
            {
                return iterator<decltype(collection.begin()), typename Collection::value_type>
                         (collection.begin(), collection.end(), func);
            }

            iterator<decltype(collection.end()), typename Collection::value_type> end()
            {
                return iterator<decltype(collection.end()), typename Collection::value_type>
                    (collection.end(), collection.end(), func);
            }
    };

    template <typename Collection, typename Func>
    Filterfalse<Collection, Func> filterfalse(const Func& func, const Collection& collection)
    {
        return Filterfalse<Collection, Func>(collection, func);
    }
}

#endif
