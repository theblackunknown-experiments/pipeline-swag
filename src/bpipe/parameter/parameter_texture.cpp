/*
 * parameter_texture.cpp
 *
 *  Created on: Jul 15, 2012
 *      Author: blackpanth3r
 */

#include "bpipe/parameter/parameter_texture.hpp"
#include "bpipe/parameter/parameterfwd.hpp"

namespace bpipe {

template class TextureParameter<uint32_t>              ;
template class TextureParameter<std::vector<uint8_t>>  ;
template class TextureParameter<std::vector<uint16_t>> ;
template class TextureParameter<std::vector<uint32_t>> ;

}  // namespace bpipe


