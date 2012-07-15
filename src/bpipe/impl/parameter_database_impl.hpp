#ifndef BPIPE_IMPL_PARAMETER_DATABASE_H
#define BPIPE_IMPL_PARAMETER_DATABASE_H

#include "bpipe/config.hpp"

#include <vector>
#include <memory>

#include "bpipe/parameterfwd.hpp"

namespace bpipe {
    struct ParameterDescription;
} /* bpipe */

namespace bpipe {
    class BPIPE_IMPLEMENTATION(ParameterDatabase) {
        public:
            typedef std::vector<std::shared_ptr<ParameterScalar>> CollectionParameterScalar;

            explicit BPIPE_IMPLEMENTATION(ParameterDatabase) ( );
            ~BPIPE_IMPLEMENTATION(ParameterDatabase) ();

            template<typename T>
            std::shared_ptr<T> setParameter( const std::shared_ptr<T>& );

            template<typename T>
            std::weak_ptr<T>   getParameter( const ParameterDescription& );
        private:
            CollectionParameterScalar mParameterScalars;
    };

    template<> std::shared_ptr<ParameterScalar> BPIPE_IMPLEMENTATION(ParameterDatabase)::setParameter<ParameterScalar>( const std::shared_ptr<ParameterScalar>& );
    
    template<> std::weak_ptr<ParameterScalar> BPIPE_IMPLEMENTATION(ParameterDatabase)::getParameter<ParameterScalar>( const ParameterDescription& );
} /* bpipe */
#endif
