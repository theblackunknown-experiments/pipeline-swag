#include "bpipe/impl/parameter_database_impl.hpp"

#include <algorithm>

#include "bpipe/functors.hpp"
#include "bpipe/parameter_description.hpp"
#include "bpipe/parameter.hpp"

namespace bpipe {

    namespace {
        template<typename Container>
        typename Container::value_type setDataIntoContainer( Container& container, const typename Container::value_type& item )
        {
            if( item )
            {
                auto container_end = container.end( );
                auto finder = std::find_if(container.begin(), container_end, FindParameterByIdentifier<typename Container::value_type>( item->getIdentifier( ) ) );
                if( finder != container_end )
                {
                    auto old = item;
                    std::swap( *finder, old );
                    return old;
                }
                else
                {
                    container.insert( finder, item );
                }
            }
            return typename Container::value_type( );
        }
    }
    
    BPIPE_IMPLEMENTATION(ParameterDatabase)::BPIPE_IMPLEMENTATION(ParameterDatabase)( )
        : mParameterScalars( )
    {
    }

    
    BPIPE_IMPLEMENTATION(ParameterDatabase)::~BPIPE_IMPLEMENTATION(ParameterDatabase)( )
    {
    }

    template<>
    std::shared_ptr<ParameterScalar> BPIPE_IMPLEMENTATION(ParameterDatabase)::setParameter<ParameterScalar>( const std::shared_ptr<ParameterScalar>& parameter )
    {
        return setDataIntoContainer(mParameterScalars, parameter);
    }

    template<>
    std::weak_ptr<ParameterScalar> BPIPE_IMPLEMENTATION(ParameterDatabase)::getParameter<ParameterScalar>( const ParameterDescription& pdesc )
    {
        if( types::Scalar == pdesc.type )
        {
            auto container_end = mParameterScalars.end( );
            auto finder = std::find_if( mParameterScalars.begin(), container_end, FindParameterByIdentifier<CollectionParameterScalar::value_type>( pdesc.identifier ) );
            if( container_end != finder )
            {
                return *finder;
            }
        }
        return std::weak_ptr<ParameterScalar>( );
    }

} /* bpipe */
