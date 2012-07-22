#include "bpipe/parameter/parameter_database.hpp"
#include "bpipe/parameter/impl/parameter_database_impl.hpp"

namespace bpipe {

ParameterDatabase::ParameterDatabase( )
	: impl( new BPIPE_IMPLEMENTATION(ParameterDatabase) )
{

}

ParameterDatabase::~ParameterDatabase( )
{

}

ParameterDatabase::CollectionDescription ParameterDatabase::getParametersDescription( ) const
{
	return impl->getParametersDescription( );
}

SharedPointerParameterScalar ParameterDatabase::setParameter( const SharedPointerParameterScalar& parameter)
{
	return impl->setParameter(parameter);
}

SharedPointerParameterText ParameterDatabase::setParameter( const SharedPointerParameterText& parameter)
{
	return impl->setParameter(parameter);
}

SharedPointerParameterGPUTexture ParameterDatabase::setParameter( const SharedPointerParameterGPUTexture& parameter)
{
	return impl->setParameter(parameter);
}

SharedPointerParameter8BitsCPUTexture ParameterDatabase::setParameter( const SharedPointerParameter8BitsCPUTexture& parameter)
{
	return impl->setParameter(parameter);
}

SharedPointerParameter16BitsCPUTexture ParameterDatabase::setParameter( const SharedPointerParameter16BitsCPUTexture& parameter)
{
	return impl->setParameter(parameter);
}

SharedPointerParameter32BitsCPUTexture ParameterDatabase::setParameter( const SharedPointerParameter32BitsCPUTexture& parameter)
{
	return impl->setParameter(parameter);
}

template<>
WeakPointerParameterScalar ParameterDatabase::getParameter<ParameterScalar> ( const ParameterDescription&  description ) const
{
	if( type::Scalar == description.type )
	{
		return impl->getParameter<ParameterScalar>(description);
	}
	else
	{
		return WeakPointerParameterScalar();
	}
}

template<>
WeakPointerParameterText ParameterDatabase::getParameter<ParameterText> ( const ParameterDescription&  description ) const
{
	if( type::Text == description.type )
	{
		return impl->getParameter<ParameterText>(description);
	}
	else
	{
		return WeakPointerParameterText();
	}
}

template<>
WeakPointerParameterGPUTexture ParameterDatabase::getParameter<ParameterGPUTexture> ( const ParameterDescription&  description ) const
{
	if( type::Texture == description.type )
	{
		return impl->getParameter<ParameterGPUTexture>(description);
	}
	else
	{
		return WeakPointerParameterGPUTexture();
	}
}

template<>
WeakPointerParameter8BitsCPUTexture ParameterDatabase::getParameter<Parameter8BitsCPUTexture> ( const ParameterDescription&  description ) const
{
	if( type::Texture == description.type )
	{
		return impl->getParameter<Parameter8BitsCPUTexture>(description);
	}
	else
	{
		return WeakPointerParameter8BitsCPUTexture();
	}
}

template<>
WeakPointerParameter16BitsCPUTexture ParameterDatabase::getParameter<Parameter16BitsCPUTexture> ( const ParameterDescription&  description ) const
{
	if( type::Texture == description.type )
	{
		return impl->getParameter<Parameter16BitsCPUTexture>(description);
	}
	else
	{
		return WeakPointerParameter16BitsCPUTexture();
	}
}

template<>
WeakPointerParameter32BitsCPUTexture ParameterDatabase::getParameter<Parameter32BitsCPUTexture> ( const ParameterDescription&  description ) const
{
	if( type::Texture == description.type )
	{
		return impl->getParameter<Parameter32BitsCPUTexture>(description);
	}
	else
	{
		return WeakPointerParameter32BitsCPUTexture();
	}
}

void ParameterDatabase::swap( ParameterDatabase& rhs )
{
	std::swap( this->impl, rhs.impl );
}

}  // namespace bpipe

namespace std
{
    template<>
    void swap<bpipe::ParameterDatabase>(bpipe::ParameterDatabase& lhs, bpipe::ParameterDatabase& rhs)
    {
        lhs.swap(rhs);
    }
} /* std */



