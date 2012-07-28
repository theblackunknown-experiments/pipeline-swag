/*
 * fixed_step.hpp
 *
 *  Created on: 22 juil. 2012
 *      Author: blackpanther
 */

#ifndef BPIPE_FIXED_STEP_H
#define BPIPE_FIXED_STEP_H

#include "bpipe/config.hpp"

#include "bpipe/step/step.hpp"

namespace bpipe {
    class ParameterDatabase;
    class BPIPE_IMPLEMENTATION(FixedStep);
} /* bpipe */

namespace bpipe {
	class FixedStep : public Step
	{
	public:
		BPIPE_API_ENTRY explicit FixedStep(const std::string& description, const CollectionInput&, const CollectionOutput&, const Functor& implementation);
		BPIPE_API_ENTRY ~FixedStep();

	private:
        BPIPE_API_ENTRY bool doJob( const ParameterDatabase& inputs, ParameterDatabase& outputs ) const; //Let this step performs its job, true on success (outputs filled), false on error (outputs untouched)

        BPIPE_IMPLEMENTATION(FixedStep)* impl;
	};

}  // namespace bpipe


#endif /* BPIPE_FIXED_STEP_H */
