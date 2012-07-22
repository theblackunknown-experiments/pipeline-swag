/*
 * fixed_step_impl.cpp
 *
 *  Created on: 22 juil. 2012
 *      Author: blackpanther
 */

#include "bpipe/step/impl/fixed_step_impl.hpp"

namespace bpipe {

BPIPE_IMPLEMENTATION(FixedStep)::BPIPE_IMPLEMENTATION(FixedStep)( const Functor& implementation )
	: mImplementation( implementation )
{

}

BPIPE_IMPLEMENTATION(FixedStep)::~BPIPE_IMPLEMENTATION(FixedStep)( )
{

}

BPIPE_IMPLEMENTATION(FixedStep)::Functor BPIPE_IMPLEMENTATION(FixedStep)::getImplementation( ) const
{
	return mImplementation;
}

}  // namespace name


