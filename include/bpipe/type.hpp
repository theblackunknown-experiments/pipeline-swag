#ifndef BPIPE_PARAMETER_TYPES_H
#define BPIPE_PARAMETER_TYPES_H

#include "bpipe/config.hpp"

namespace bpipe {
	namespace type {

enum class ParameterType : unsigned int
{
	Scalar,
	Texture,
	Text,
};

	}  // namespace types

} // namespace bpipe

#endif
