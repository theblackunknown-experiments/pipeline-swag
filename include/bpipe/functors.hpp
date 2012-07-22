#ifndef BPIPE_FUNCTORS_H
#define BPIPE_FUNCTORS_H

#include "bpipe/config.hpp"

#include <string>

#include "bpipe/parameter/parameter_description.hpp"

namespace bpipe {

    template<typename TypedParameterPointer>
    class MatcherParameterPointerByIdentifier : public std::unary_function<TypedParameterPointer, bool>
    {
    private:
        std::string filter;
    public:
        PIPE_API_ENTRY explicit MatcherParameterPointerByIdentifier(const std::string& f)
            : filter( f )
        {
        }

        PIPE_API_ENTRY bool operator()(const TypedParameterPointer& pParameter) const
        {
            return pParameter && pParameter->getIdentifier( ) == filter;
        }
    };

    template<type::ParameterType Type, typename TypedParameterPointer>
    struct BuilderParameterDescriptionFromParameterEntry : public std::unary_function< std::pair<std::string, TypedParameterPointer>, ParameterDescription>
    {
    	PIPE_API_ENTRY ParameterDescription operator()( const std::pair<std::string, TypedParameterPointer>& pentry ) const
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

    template<type::ParameterType Type, typename TypedParameterPointer>
    struct BuilderParameterDescriptionFromParameterPointer : public std::unary_function<TypedParameterPointer, ParameterDescription>
    {
    	PIPE_API_ENTRY ParameterDescription operator()( const TypedParameterPointer& ppointer ) const
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
