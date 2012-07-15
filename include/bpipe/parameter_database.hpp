#ifndef BPIPE_PARAMETER_DATABASE_H
#define BPIPE_PARAMETER_DATABASE_H

#include "bpipe/config.hpp"

#include <memory>
#include <algorithm>

#include "bpipe/parameter_description.hpp"
#include "bpipe/parameterfwd.hpp"

namespace bpipe {
    class BPIPE_IMPLEMENTATION(ParameterDatabase);
}

namespace bpipe {
    class ParameterDatabase {
        public:
            explicit ParameterDatabase ( );
            ParameterDatabase( const ParameterDatabase& rhs );
            ParameterDatabase( const ParameterDatabase&& rhs );
            ParameterDatabase& operator=( const ParameterDatabase& rhs );
            ParameterDatabase& operator=( const ParameterDatabase&& rhs );

            ~ParameterDatabase ( );

            template<typename T>
            std::shared_ptr<T> setParameter( const std::shared_ptr<T>& );

            template<typename T>
            std::weak_ptr<T>   getParameter( const ParameterDescription& );

            void swap(ParameterDatabase& rhs);
        private:
            std::unique_ptr<BPIPE_IMPLEMENTATION(ParameterDatabase)> impl;
    };
    
    template<> std::shared_ptr<ParameterScalar> ParameterDatabase::setParameter<ParameterScalar>( const std::shared_ptr<ParameterScalar>& );
    
    template<> std::weak_ptr<ParameterScalar> ParameterDatabase::getParameter<ParameterScalar>( const ParameterDescription& );

} /* bpipe */

namespace std
{
    template<>
    void swap(bpipe::ParameterDatabase& lhs, bpipe::ParameterDatabase& rhs)
    {
        lhs.swap(rhs);
    }
} /* std */

#endif
