#ifndef BPIPE_PARAMETER_DESCRIPTION_H
#define BPIPE_PARAMETER_DESCRIPTION_H

#include "bpipe/config.hpp"

#include <string>

#include "bpipe/types.hpp"

namespace bpipe {

	/*
	 * Minimal description of a parameter
	 * - identifier: for retrieval
	 * - type: expected type for this parameter
	 */
    struct ParameterDescription {
    	ParameterDescription( ) = default;
    	ParameterDescription(const std::string& id, types::ParameterType t)
    		: identifier(id), type(t)
    	{
    	}

        std::string          identifier;
        types::ParameterType type;
    };

    typedef ParameterDescription InputDescription;
    typedef ParameterDescription OutputDescription;
} /* bpipe */

#endif
