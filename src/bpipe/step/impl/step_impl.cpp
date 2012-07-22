/*
 * step_impl.cpp
 *
 *  Created on: 22 juil. 2012
 *      Author: blackpanther
 */

#include "bpipe/step/impl/step_impl.hpp"

#include "bpipe/parameter/parameter_description.hpp"

namespace bpipe {

BPIPE_IMPLEMENTATION(Step)::BPIPE_IMPLEMENTATION(Step)(const std::string& description, const CollectionInput& inputs_desc, const CollectionOutput& outputs_desc)
		: mDescription        ( description )
		, mDescriptionInputs  ( inputs_desc )
		, mDescriptionOutputs ( outputs_desc )
{
}

BPIPE_IMPLEMENTATION(Step)::~BPIPE_IMPLEMENTATION(Step)()
{
}

std::string BPIPE_IMPLEMENTATION(Step)::getDescription( ) const
{
	return mDescription;
}

BPIPE_IMPLEMENTATION(Step)::CollectionInput BPIPE_IMPLEMENTATION(Step)::getInputsDescription( ) const
{
	return mDescriptionInputs;
}

BPIPE_IMPLEMENTATION(Step)::CollectionOutput BPIPE_IMPLEMENTATION(Step)::getOutputsDescription( ) const
{
	return mDescriptionOutputs;
}

} /* namespace bpipe */
