/*
 * fixed_step_impl.hpp
 *
 *  Created on: 22 juil. 2012
 *      Author: blackpanther
 */

#ifndef FIXED_STEP_IMPL_H
#define FIXED_STEP_IMPL_H

#include "bpipe/config.hpp"

#include <functional>

#include "bpipe/parameter/parameter_database.hpp"

namespace bpipe {

class BPIPE_IMPLEMENTATION(FixedStep)
{
public:
	typedef std::function<bool (const ParameterDatabase&, ParameterDatabase&)> Functor;

	explicit BPIPE_IMPLEMENTATION(FixedStep)( const Functor& implementation );
	~BPIPE_IMPLEMENTATION(FixedStep)( );

	Functor getImplementation( ) const;

private:
	Functor mImplementation;
};

}  // namespace bpipe


#endif /* FIXED_STEP_IMPL_H */
