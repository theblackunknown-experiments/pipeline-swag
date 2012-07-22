#ifndef BPIPE_PARAMETER_FWD_H
#define BPIPE_PARAMETER_FWD_H

#include <string>
#include <vector>
#include <cinttypes>
#include <memory>

#include "bpipe/config.hpp"

#include "bpipe/type.hpp"

namespace bpipe {
	template<typename DataType, type::ParameterType type> class ValueParameter;
	template<typename DataContainer>                       class TextureParameter;

    typedef ValueParameter<float,       type::Scalar>                ParameterScalar;
    typedef ValueParameter<std::string, type::Text>                  ParameterText;
    typedef TextureParameter<uint32_t>                               ParameterGPUTexture;
    typedef TextureParameter<std::shared_ptr<std::vector<uint8_t>>>  Parameter8BitsCPUTexture;
    typedef TextureParameter<std::shared_ptr<std::vector<uint16_t>>> Parameter16BitsCPUTexture;
    typedef TextureParameter<std::shared_ptr<std::vector<uint32_t>>> Parameter32BitsCPUTexture;

    typedef std::shared_ptr<ParameterScalar>                         SharedPointerParameterScalar;
    typedef std::shared_ptr<ParameterText>                           SharedPointerParameterText;
    typedef std::shared_ptr<ParameterGPUTexture>                     SharedPointerParameterGPUTexture;
    typedef std::shared_ptr<Parameter8BitsCPUTexture>                SharedPointerParameter8BitsCPUTexture;
    typedef std::shared_ptr<Parameter16BitsCPUTexture>               SharedPointerParameter16BitsCPUTexture;
    typedef std::shared_ptr<Parameter32BitsCPUTexture>               SharedPointerParameter32BitsCPUTexture;

    typedef std::weak_ptr<ParameterScalar>                           WeakPointerParameterScalar;
    typedef std::weak_ptr<ParameterText>                             WeakPointerParameterText;
    typedef std::weak_ptr<ParameterGPUTexture>                       WeakPointerParameterGPUTexture;
    typedef std::weak_ptr<Parameter8BitsCPUTexture>                  WeakPointerParameter8BitsCPUTexture;
    typedef std::weak_ptr<Parameter16BitsCPUTexture>                 WeakPointerParameter16BitsCPUTexture;
    typedef std::weak_ptr<Parameter32BitsCPUTexture>                 WeakPointerParameter32BitsCPUTexture;

} /* bpipe */

#endif
