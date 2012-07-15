#ifndef BPIPE_PARAMETER_DESCRIPTION_H
#define BPIPE_PARAMETER_DESCRIPTION_H

#include "bpipe/config.hpp"

#include <string>

#include "bpipe/types.hpp"

namespace bpipe {
    struct ParameterDescription {
        std::string          identifier;
        types::ParameterType type;
    };

    typedef ParameterDescription InputDescription;
    typedef ParameterDescription OutputDescription;
} /* bpipe */

#endif
