#ifndef BPIPE_STEP_H
#define BPIPE_STEP_H

#include "bpipe/config.hpp"

#include <string>
#include <vector>
#include <functional>

#include <memory>

#include "bpipe/parameter/parameterfwd.hpp"

namespace bpipe {
    class ParameterDatabase;
    class BPIPE_IMPLEMENTATION(Step);
} /* bpipe */

namespace bpipe {
    class Step : public std::binary_function<bool, ParameterDatabase, ParameterDatabase>
    {
        public:
    		typedef std::function<bool (const ParameterDatabase&, ParameterDatabase&)> Functor;

            typedef std::vector<InputDescription>                                            CollectionInput;
            typedef std::vector<OutputDescription>                                           CollectionOutput;

            BPIPE_API_ENTRY explicit Step (const std::string& description, const CollectionInput&, const CollectionOutput&);
            BPIPE_API_ENTRY virtual ~Step ();

            BPIPE_API_ENTRY std::string      getDescription( ) const;                                                        //Step's description

            BPIPE_API_ENTRY CollectionInput  getExpectedInputs( ) const;                                                     //Interface to know what is expected inputs
            BPIPE_API_ENTRY CollectionOutput getExpectedOutputs( ) const;                                                    //Interface to know what is expected outputs

            BPIPE_API_ENTRY bool             operator()(const ParameterDatabase& inputs, ParameterDatabase& outputs ) const;

        private:
            BPIPE_API_ENTRY virtual bool     doJob( const ParameterDatabase& inputs, ParameterDatabase& outputs ) const = 0; //Let this step performs its job, true on success (outputs filled), false on error (outputs untouched)

            BPIPE_IMPLEMENTATION(Step)* impl;
    };
} /* bpipe */

#endif
