#ifndef _FILTERFALSE_HPP
#define _FILTERFALSE_HPP

namespace itertools
{ 
    class filterfalse
    {
        public:
            template<typename T,typename Collection>
            filterfalse(T t,Collection collection);

            int* begin()
            {
                return nullptr;
            }
            int* end()
            {
                return nullptr;
            }

    };
    template<typename T,typename Collection>
    filterfalse::filterfalse(T t,Collection collection)
    {

    }

}
#endif
