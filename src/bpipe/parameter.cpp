/*
 * parameter.cpp
 *
 *  Created on: Jul 15, 2012
 *      Author: blackpanth3r
 */

#include "bpipe/parameterfwd.hpp"
#include "bpipe/parameter.hpp"

namespace bpipe {

template class ValueParameter<float,       types::Scalar>;
template class ValueParameter<std::string, types::Text>;

}  // namespace bpipe




