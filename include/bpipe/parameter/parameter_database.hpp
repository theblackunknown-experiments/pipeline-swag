#ifndef BPIPE_PARAMETER_DATABASE_H
#define BPIPE_PARAMETER_DATABASE_H

#include "bpipe/config.hpp"

#include <memory>
#include <vector>
#include <algorithm>

#include "bpipe/parameter/parameterfwd.hpp"

namespace bpipe {
	struct ParameterDescription;
    class BPIPE_IMPLEMENTATION(ParameterDatabase);
}

namespace bpipe {

	/*
	 * Storage class for parameters
	 * - enable retrieval by name for an expected type parameter
	 * - can query the database to discover available parameter and corresponding type
	 */
    class ParameterDatabase
    {
	public:
		typedef std::vector<ParameterDescription> CollectionDescription;

		BPIPE_API_ENTRY explicit ParameterDatabase ( );
		BPIPE_API_ENTRY ~ParameterDatabase ( );

		BPIPE_API_ENTRY CollectionDescription getParametersDescription( ) const;

		BPIPE_API_ENTRY SharedPointerParameterScalar           setParameter( const SharedPointerParameterScalar&           );
		BPIPE_API_ENTRY SharedPointerParameterText             setParameter( const SharedPointerParameterText&             );
		BPIPE_API_ENTRY SharedPointerParameterGPUTexture       setParameter( const SharedPointerParameterGPUTexture&       );
		BPIPE_API_ENTRY SharedPointerParameter8BitsCPUTexture  setParameter( const SharedPointerParameter8BitsCPUTexture&  );
		BPIPE_API_ENTRY SharedPointerParameter16BitsCPUTexture setParameter( const SharedPointerParameter16BitsCPUTexture& );
		BPIPE_API_ENTRY SharedPointerParameter32BitsCPUTexture setParameter( const SharedPointerParameter32BitsCPUTexture& );

		template<typename T>
		BPIPE_API_ENTRY std::weak_ptr<T>   getParameter( const ParameterDescription& ) const;

		BPIPE_API_ENTRY void insert(ParameterDatabase& rhs);
		BPIPE_API_ENTRY void swap(ParameterDatabase& rhs);
	private:
		ParameterDatabase ( const ParameterDatabase& );
		ParameterDatabase& operator= ( const ParameterDatabase& );

		std::unique_ptr<BPIPE_IMPLEMENTATION(ParameterDatabase)> impl;
    };

    template<> BPIPE_API_ENTRY WeakPointerParameterScalar             ParameterDatabase::getParameter<ParameterScalar>           ( const ParameterDescription& ) const;
    template<> BPIPE_API_ENTRY WeakPointerParameterText               ParameterDatabase::getParameter<ParameterText>             ( const ParameterDescription& ) const;
    template<> BPIPE_API_ENTRY WeakPointerParameterGPUTexture         ParameterDatabase::getParameter<ParameterGPUTexture>       ( const ParameterDescription& ) const;
    template<> BPIPE_API_ENTRY WeakPointerParameter8BitsCPUTexture    ParameterDatabase::getParameter<Parameter8BitsCPUTexture>  ( const ParameterDescription& ) const;
    template<> BPIPE_API_ENTRY WeakPointerParameter16BitsCPUTexture   ParameterDatabase::getParameter<Parameter16BitsCPUTexture> ( const ParameterDescription& ) const;
    template<> BPIPE_API_ENTRY WeakPointerParameter32BitsCPUTexture   ParameterDatabase::getParameter<Parameter32BitsCPUTexture> ( const ParameterDescription& ) const;

} /* bpipe */

namespace std
{
    template<> void swap<bpipe::ParameterDatabase>(bpipe::ParameterDatabase& lhs, bpipe::ParameterDatabase& rhs);
} /* std */

#endif
