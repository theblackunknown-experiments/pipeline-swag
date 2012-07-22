#ifndef BPIPE_PARAMETER_DATABASE_H
#define BPIPE_PARAMETER_DATABASE_H

#include "bpipe/config.hpp"

#include <memory>
#include <vector>
#include <algorithm>

#include "bpipe/parameter_description.hpp"
#include "bpipe/parameterfwd.hpp"

namespace bpipe {
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

		explicit ParameterDatabase ( );
		~ParameterDatabase ( );

		CollectionDescription getParametersDescription( ) const;

		SharedPointerParameterScalar           setParameter( const SharedPointerParameterScalar&           );
		SharedPointerParameterText             setParameter( const SharedPointerParameterText&             );
		SharedPointerParameterGPUTexture       setParameter( const SharedPointerParameterGPUTexture&       );
		SharedPointerParameter8BitsCPUTexture  setParameter( const SharedPointerParameter8BitsCPUTexture&  );
		SharedPointerParameter16BitsCPUTexture setParameter( const SharedPointerParameter16BitsCPUTexture& );
		SharedPointerParameter32BitsCPUTexture setParameter( const SharedPointerParameter32BitsCPUTexture& );

		template<typename T>
		std::weak_ptr<T>   getParameter( const ParameterDescription& ) const;

		void swap(ParameterDatabase& rhs);
	private:
		std::unique_ptr<BPIPE_IMPLEMENTATION(ParameterDatabase)> impl;
    };

    template<> WeakPointerParameterScalar             ParameterDatabase::getParameter<ParameterScalar>           ( const ParameterDescription& ) const;
    template<> WeakPointerParameterText               ParameterDatabase::getParameter<ParameterText>             ( const ParameterDescription& ) const;
    template<> WeakPointerParameterGPUTexture         ParameterDatabase::getParameter<ParameterGPUTexture>       ( const ParameterDescription& ) const;
    template<> WeakPointerParameter8BitsCPUTexture    ParameterDatabase::getParameter<Parameter8BitsCPUTexture>  ( const ParameterDescription& ) const;
    template<> WeakPointerParameter16BitsCPUTexture   ParameterDatabase::getParameter<Parameter16BitsCPUTexture> ( const ParameterDescription& ) const;
    template<> WeakPointerParameter32BitsCPUTexture   ParameterDatabase::getParameter<Parameter32BitsCPUTexture> ( const ParameterDescription& ) const;

} /* bpipe */

namespace std
{
    template<> void swap<bpipe::ParameterDatabase>(bpipe::ParameterDatabase& lhs, bpipe::ParameterDatabase& rhs);
} /* std */

#endif
