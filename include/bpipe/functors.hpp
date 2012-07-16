#ifndef BPIPE_FUNCTORS_H
#define BPIPE_FUNCTORS_H

#include "bpipe/config.hpp"

#include <string>

#include "bpipe/parameter_description.hpp"

namespace bpipe {

    template<typename TypedParameterPointer>
    class MatcherParameterPointerByIdentifier : public std::unary_function<TypedParameterPointer, bool>
    {
    private:
        std::string filter;
    public:
        explicit MatcherParameterPointerByIdentifier(const std::string& f)
            : filter( f )
        {
        }

        bool operator()(const TypedParameterPointer& pParameter) const
        {
            return pParameter && pParameter->getIdentifier( ) == filter;
        }
    };

    template<types::ParameterType Type, typename TypedParameterPointer>
    struct BuilderParameterDescriptionFromParameterEntry : public std::unary_function< std::pair<std::string, TypedParameterPointer>, ParameterDescription>
    {
    	ParameterDescription operator()( const std::pair<std::string, TypedParameterPointer>& pentry ) const
    	{
			ParameterDescription description;
    		if( pentry.second )
    		{
    			description.identifier = pentry.second->getIdentifier( );
    			description.type       = Type;
    		}
    		return description;
    	}
    };

    template<types::ParameterType Type, typename TypedParameterPointer>
    struct BuilderParameterDescriptionFromParameterPointer : public std::unary_function<TypedParameterPointer, ParameterDescription>
    {
    	ParameterDescription operator()( const TypedParameterPointer& ppointer ) const
    	{
    		if( ppointer )
    		{
        		return {
        				ppointer->getIdentifier( ),
        				Type
        		};
    		}
    		else
    		{
    			return ParameterDescription( );
    		}
    	}
    };

} /* bpipe */

#endif
