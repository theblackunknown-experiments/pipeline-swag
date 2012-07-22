#include "bpipe/parameter/impl/parameter_database_impl.hpp"

#include <algorithm>

#include "bpipe/functors.hpp"
#include "bpipe/parameter/parameter_description.hpp"
#include "bpipe/parameter/parameter.hpp"
#include "bpipe/parameter/parameter_texture.hpp"

namespace bpipe {

    namespace {

    template<typename Container>
    typename Container::mapped_type insertDataIntoContainer( Container& container, const typename Container::mapped_type& item )
    {
        if( item )
        {
            auto finder = container.find( item->getIdentifier( ) );
            if( finder != container.end( ) )
            {
                auto old = item;
                std::swap( (*finder).second, old );
                return old;
            }
            else
            {
                container.insert( finder, std::make_pair(item->getIdentifier( ), item) );
            }
        }
        return typename Container::mapped_type( );
    }

    template<typename Container>
    typename Container::mapped_type typeCheckedDataRetrieval( Container& container, type::ParameterType expected_type, const ParameterDescription& description )
    {
        if( expected_type == description.type )
        {
            auto finder = container.find( description.identifier );
            if( finder != container.end( ) )
            {
                return (*finder).second;
            }
        }
        return typename Container::mapped_type( );
    }

    }
    
    BPIPE_IMPLEMENTATION(ParameterDatabase)::BPIPE_IMPLEMENTATION(ParameterDatabase)( )
        : mParameterScalars( )
        , mParameterTexts( )
        , mParameterGPUTextures( )
        , mParameter8BitsCPUTextures( )
        , mParameter16BitsCPUTextures( )
        , mParameter32BitsCPUTextures( )
    {
    }
    
    BPIPE_IMPLEMENTATION(ParameterDatabase)::~BPIPE_IMPLEMENTATION(ParameterDatabase)( )
    {
    }

    BPIPE_IMPLEMENTATION(ParameterDatabase)::CollectionDescription BPIPE_IMPLEMENTATION(ParameterDatabase)::getParametersDescription( ) const
	{
    	CollectionDescription pdescriptions( mParameterScalars.size() + mParameterTexts.size() + mParameterGPUTextures.size() + mParameter8BitsCPUTextures.size() + mParameter16BitsCPUTextures.size() + mParameter32BitsCPUTextures.size() );
    	auto description_iterator = pdescriptions.begin();
    	std::transform(mParameterScalars.begin(), mParameterScalars.end(), description_iterator, BuilderParameterDescriptionFromParameterEntry<type::Scalar, CollectionParameterScalar::mapped_type>());
    	std::advance(description_iterator, mParameterScalars.size());
    	std::transform(mParameterTexts.begin(), mParameterTexts.end(), description_iterator, BuilderParameterDescriptionFromParameterEntry<type::Text, CollectionParameterText::mapped_type>());
    	std::advance(description_iterator, mParameterTexts.size());
    	std::transform(mParameterGPUTextures.begin(), mParameterGPUTextures.end(), description_iterator, BuilderParameterDescriptionFromParameterEntry<type::Texture, CollectionParameterGPUTexture::mapped_type>());
    	std::advance(description_iterator, mParameterGPUTextures.size());
    	std::transform(mParameter8BitsCPUTextures.begin(), mParameter8BitsCPUTextures.end(), description_iterator, BuilderParameterDescriptionFromParameterEntry<type::Texture, CollectionParameter8BitsCPUTexture::mapped_type>());
    	std::advance(description_iterator, mParameter8BitsCPUTextures.size());
    	std::transform(mParameter16BitsCPUTextures.begin(), mParameter16BitsCPUTextures.end(), description_iterator, BuilderParameterDescriptionFromParameterEntry<type::Texture, CollectionParameter16BitsCPUTexture::mapped_type>());
    	std::advance(description_iterator, mParameter16BitsCPUTextures.size());
    	std::transform(mParameter32BitsCPUTextures.begin(), mParameter32BitsCPUTextures.end(), description_iterator, BuilderParameterDescriptionFromParameterEntry<type::Texture, CollectionParameter32BitsCPUTexture::mapped_type>());
    	return pdescriptions;
	}

    SharedPointerParameterScalar BPIPE_IMPLEMENTATION(ParameterDatabase)::setParameter( const SharedPointerParameterScalar& parameter )
    {
        return insertDataIntoContainer(mParameterScalars, parameter);
    }

    SharedPointerParameterText BPIPE_IMPLEMENTATION(ParameterDatabase)::setParameter( const SharedPointerParameterText& parameter )
    {
        return insertDataIntoContainer(mParameterTexts, parameter);
    }

    SharedPointerParameterGPUTexture BPIPE_IMPLEMENTATION(ParameterDatabase)::setParameter( const SharedPointerParameterGPUTexture& parameter )
    {
        return insertDataIntoContainer(mParameterGPUTextures, parameter);
    }

    SharedPointerParameter8BitsCPUTexture BPIPE_IMPLEMENTATION(ParameterDatabase)::setParameter( const SharedPointerParameter8BitsCPUTexture& parameter )
    {
        return insertDataIntoContainer(mParameter8BitsCPUTextures, parameter);
    }

    SharedPointerParameter16BitsCPUTexture BPIPE_IMPLEMENTATION(ParameterDatabase)::setParameter( const SharedPointerParameter16BitsCPUTexture& parameter )
    {
        return insertDataIntoContainer(mParameter16BitsCPUTextures, parameter);
    }

    SharedPointerParameter32BitsCPUTexture BPIPE_IMPLEMENTATION(ParameterDatabase)::setParameter( const SharedPointerParameter32BitsCPUTexture& parameter )
    {
        return insertDataIntoContainer(mParameter32BitsCPUTextures, parameter);
    }

    template<>
    WeakPointerParameterScalar BPIPE_IMPLEMENTATION(ParameterDatabase)::getParameter<ParameterScalar>( const ParameterDescription& pdesc ) const
    {
        return typeCheckedDataRetrieval(mParameterScalars, type::Scalar, pdesc);
    }

    template<>
    WeakPointerParameterText BPIPE_IMPLEMENTATION(ParameterDatabase)::getParameter<ParameterText>( const ParameterDescription& pdesc ) const
    {
        return typeCheckedDataRetrieval(mParameterTexts, type::Text, pdesc);
    }

    template<>
    WeakPointerParameterGPUTexture BPIPE_IMPLEMENTATION(ParameterDatabase)::getParameter<ParameterGPUTexture>( const ParameterDescription& pdesc ) const
    {
        return typeCheckedDataRetrieval(mParameterGPUTextures, type::Texture, pdesc);
    }

    template<>
    WeakPointerParameter8BitsCPUTexture BPIPE_IMPLEMENTATION(ParameterDatabase)::getParameter<Parameter8BitsCPUTexture>( const ParameterDescription& pdesc ) const
    {
        return typeCheckedDataRetrieval(mParameter8BitsCPUTextures, type::Texture, pdesc);
    }

    template<>
    WeakPointerParameter16BitsCPUTexture BPIPE_IMPLEMENTATION(ParameterDatabase)::getParameter<Parameter16BitsCPUTexture>( const ParameterDescription& pdesc ) const
    {
        return typeCheckedDataRetrieval(mParameter16BitsCPUTextures, type::Texture, pdesc);
    }

    template<>
    WeakPointerParameter32BitsCPUTexture BPIPE_IMPLEMENTATION(ParameterDatabase)::getParameter<Parameter32BitsCPUTexture>( const ParameterDescription& pdesc ) const
    {
        return typeCheckedDataRetrieval(mParameter32BitsCPUTextures, type::Texture, pdesc);
    }

} /* bpipe */
