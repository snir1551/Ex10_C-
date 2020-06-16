#ifndef _COMPRESS_HPP
#define _COMPRESS_HPP

namespace itertools
{
    template<typename Collection, typename Collection_Bool>
    class Compress
    {
        public:
            template <typename CollectionIterator, typename BoolIterator, typename ValueType> 
            class iterator
            {
                private:
                    CollectionIterator _collectionIterator, _end;
                    BoolIterator _boolIterator;
                    bool _initialized;
                    
                public:
                    iterator(const CollectionIterator& begin, const CollectionIterator& end, const BoolIterator& boolIterator)
                        : _collectionIterator(begin), _end(end), _boolIterator(boolIterator), _initialized(false)
                    {
                        ++(*this);
                    }

                    void operator++()
                    {   
                        if(_initialized)
                        {
                             ++_collectionIterator;
                             ++_boolIterator;
                        }
                        else
                        {
                            _initialized = true;
                        }
                        
                        while(_collectionIterator != _end && !(*_boolIterator))
                        {
                            ++_collectionIterator;
                            ++_boolIterator;
                        } 
                    }

                    bool operator!=(const iterator& it) const
                    {
                        return (_collectionIterator != it._collectionIterator);
                    }

                    ValueType operator*()
                    {
                        return *_collectionIterator;
                    }
            };

        private:
            const Collection& _collection;
            const Collection_Bool& _collection_bool;

        public:
            Compress(const Collection& collection, const Collection_Bool& collection_bool): _collection(collection), _collection_bool(collection_bool)
            {

            }

            iterator<decltype(_collection.begin()), decltype(_collection_bool.begin()), typename Collection::value_type> begin()
            {
                return iterator<decltype(_collection.begin()), decltype(_collection_bool.begin()), typename Collection::value_type>
                         (_collection.begin(), _collection.end(), _collection_bool.begin());
            }

            iterator<decltype(_collection.begin()), decltype(_collection_bool.begin()), typename Collection::value_type> end()
            {
                return iterator<decltype(_collection.begin()), decltype(_collection_bool.begin()), typename Collection::value_type>
                        (_collection.end(), _collection.end(), _collection_bool.end());
            }
    };

    template <typename Collection, typename Collection_Bool>
    Compress<Collection, Collection_Bool> compress(const Collection& collection, const Collection_Bool& collection_bool)
    {
        return Compress<Collection, Collection_Bool>(collection, collection_bool);
    }
}

#endif