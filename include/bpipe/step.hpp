#ifndef BPIPE_STEP_H
#define BPIPE_STEP_H

#include "bpipe/config.hpp"

#include <string>

#include <memory>

namespace bpipe {
    struct InputDescription;
    struct OutputDescription;

    class ParameterDatabase;
    class BPIPE_IMPLEMENTATION(Step);
} /* bpipe */

namespace bpipe {
    class Step {
        public:
            typedef std::vector<InputDescription>  CollectionInput;
            typedef std::vector<OutputDescription> CollectionOutput;

            explicit Step ();
            virtual ~Step ();

            std::string              getDescription( ) const;                                                        //Step's description

            virtual CollectionInput  getExpectedInputs( ) const = 0;                                                 //Interface to know what is expected inputs
            virtual CollectionOutput getExpectedOutputs( ) const = 0;                                                //Interface to know what is expected outputs

            virtual bool             doJob( const ParameterDatabase& inputs, ParameterDatabase& outputs ) const = 0; //Let this step performs its job, true on success (outputs filled), false on error (outptus untouched)

        private:
            std::unique_ptr<BPIPE_IMPLEMENTATION(Step)> impl;
    };
} /* bpipe */

#endif
