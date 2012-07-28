/*
 * fixed_step.cpp
 *
 *  Created on: 22 juil. 2012
 *      Author: blackpanther
 */

#include "bpipe/step/fixed_step.hpp"
#include "bpipe/step/impl/fixed_step_impl.hpp"

namespace bpipe {

FixedStep::FixedStep(const std::string& description, const CollectionInput& inputs, const CollectionOutput& outputs, const Functor& implementation)
	: Step(description, inputs, outputs)
	, impl( new BPIPE_IMPLEMENTATION(FixedStep)(implementation) )
{

}

FixedStep::~FixedStep( )
{
	delete impl;
}

bool FixedStep::doJob( const ParameterDatabase& inputs, ParameterDatabase& outputs ) const
{
	const auto implementation = impl->getImplementation();
	if( implementation )
	{
		return implementation(inputs, outputs);
	}
	else
	{
		return false;
	}
}

}  // namespace bpipe


