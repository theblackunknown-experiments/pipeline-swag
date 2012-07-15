#ifndef BPIPE_PARAMETER_FWD_H
#define BPIPE_PARAMETER_FWD_H

#include <string>
#include <vector>
#include <cinttypes>

#include "bpipe/config.hpp"

#include "bpipe/types.hpp"

namespace bpipe {
	template<typename DataType, types::ParameterType type> class ValueParameter;
	template<typename DataContainer>                       class TextureParameter;

    typedef ValueParameter<float,       types::Scalar> ParameterScalar;
    typedef ValueParameter<std::string, types::Text>   ParameterText;
    typedef TextureParameter<uint32_t>                 ParameterGPUTexture;
    typedef TextureParameter<std::vector<uint8_t>>     Parameter8BitsCPUTexture;
    typedef TextureParameter<std::vector<uint16_t>>    Parameter16BitsCPUTexture;
    typedef TextureParameter<std::vector<uint32_t>>    Parameter32BitsCPUTexture;
} /* bpipe */

#endif
