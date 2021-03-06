#ifndef BPIPE_PARAMETER_DESCRIPTION_H
#define BPIPE_PARAMETER_DESCRIPTION_H

#include "bpipe/config.hpp"

#include <string>

#include "bpipe/type.hpp"

namespace bpipe {

	/*
	 * Minimal description of a parameter
	 * - identifier: for retrieval
	 * - type: expected type for this parameter
	 */
    struct ParameterDescription {
    	BPIPE_API_ENTRY ParameterDescription( )
    		: identifier( ), type( )
    	{

    	}

    	BPIPE_API_ENTRY ParameterDescription(const std::string& id, type::ParameterType t)
    		: identifier(id), type(t)
    	{
    	}

        std::string         identifier;
        type::ParameterType type;
    };

} /* bpipe */

#endif
