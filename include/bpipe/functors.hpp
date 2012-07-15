#ifndef BPIPE_FUNCTORS_H
#define BPIPE_FUNCTORS_H

#include "bpipe/config.hpp"

#include <string>

namespace bpipe {

    template<typename TParameter> 
    class FindParameterByIdentifier : public std::unary_function<TParameter, bool>  
    {
    private:
        std::string name_filter;
    public:
        explicit FindParameterByIdentifier(const std::string& filter)
            : name_filter( filter )
        {
        }

        bool operator()(const TParameter& pParameter) const
        {
            return pParameter && pParameter->getIdentifier( ) == name_filter;
        }
    };
} /* bpipe */
#endif
