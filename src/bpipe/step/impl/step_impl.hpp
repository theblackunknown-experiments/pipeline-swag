/*
 * step_impl.h
 *
 *  Created on: 22 juil. 2012
 *      Author: blackpanther
 */

#ifndef BPIPE_STEP_IMPL_H
#define BPIPE_STEP_IMPL_H

#include "bpipe/config.hpp"

#include <string>
#include <vector>

#include "bpipe/parameter/parameterfwd.hpp"

namespace bpipe {
    class ParameterDatabase;
} /* bpipe */

namespace bpipe {

	class BPIPE_IMPLEMENTATION(Step)
	{
	public:
        typedef std::vector<InputDescription>  CollectionInput;
        typedef std::vector<OutputDescription> CollectionOutput;

		BPIPE_IMPLEMENTATION(Step)(const std::string& description, const CollectionInput&, const CollectionOutput&);
		~BPIPE_IMPLEMENTATION(Step)();

        std::string      getDescription( ) const;                                                        //Step's description

        CollectionInput  getInputsDescription( ) const;                                                     //Interface to know what is expected inputs
        CollectionOutput getOutputsDescription( ) const;                                                    //Interface to know what is expected outputs

    private:
        std::string      mDescription;
        CollectionInput  mDescriptionInputs;
        CollectionOutput mDescriptionOutputs;
	};

} /* namespace bpipe */
#endif /* BPIPE_STEP_IMPL_H_ */
