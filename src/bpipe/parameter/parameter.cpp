/*
 * parameter.cpp
 *
 *  Created on: Jul 15, 2012
 *      Author: blackpanth3r
 */

#include "bpipe/parameter/parameterfwd.hpp"
#include "bpipe/parameter/parameter.hpp"

namespace bpipe {

template class ValueParameter<float,       type::Scalar>;
template class ValueParameter<std::string, type::Text>;

}  // namespace bpipe




