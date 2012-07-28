/*
 * step.cpp
 *
 *  Created on: 22 juil. 2012
 *      Author: blackpanther
 */

#include "bpipe/step/step.hpp"
#include "bpipe/step/impl/step_impl.hpp"

#include "bpipe/parameter/parameter_description.hpp"

namespace bpipe {

Step::Step(const std::string& description, const CollectionInput& inputs, const CollectionOutput& outputs)
	: impl( new BPIPE_IMPLEMENTATION(Step)( description, inputs, outputs ) )
{
}

Step::~Step( )
{
	delete impl;
}

std::string Step::getDescription( ) const
{
	return impl->getDescription( );
}

Step::CollectionInput Step::getExpectedInputs( ) const
{
	return impl->getInputsDescription( );
}

Step::CollectionOutput Step::getExpectedOutputs( ) const
{
	return impl->getOutputsDescription( );
}

bool Step::operator()(const ParameterDatabase& inputs, ParameterDatabase& outputs) const
{
	return doJob(inputs, outputs);
}

}  // namespace bpipe



