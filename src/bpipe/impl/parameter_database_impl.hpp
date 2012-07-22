#ifndef BPIPE_IMPL_PARAMETER_DATABASE_H
#define BPIPE_IMPL_PARAMETER_DATABASE_H

#include "bpipe/config.hpp"

#include <memory>
#include <vector>
#include <map>

#include "bpipe/parameter_description.hpp"
#include "bpipe/parameterfwd.hpp"

namespace bpipe {
    struct ParameterDescription;
} /* bpipe */

namespace bpipe {

	/*
	 * Implementation class for 'ParameterDatabase'
	 */
    class BPIPE_IMPLEMENTATION(ParameterDatabase) {
        public:
			typedef std::vector<ParameterDescription>                             CollectionDescription;

			typedef std::map<std::string, SharedPointerParameterScalar>           CollectionParameterScalar;
			typedef std::map<std::string, SharedPointerParameterText>             CollectionParameterText;
			typedef std::map<std::string, SharedPointerParameterGPUTexture>       CollectionParameterGPUTexture;
			typedef std::map<std::string, SharedPointerParameter8BitsCPUTexture>  CollectionParameter8BitsCPUTexture;
			typedef std::map<std::string, SharedPointerParameter16BitsCPUTexture> CollectionParameter16BitsCPUTexture;
			typedef std::map<std::string, SharedPointerParameter32BitsCPUTexture> CollectionParameter32BitsCPUTexture;

            explicit BPIPE_IMPLEMENTATION(ParameterDatabase) ( );
            ~BPIPE_IMPLEMENTATION(ParameterDatabase) ();

    		CollectionDescription getParametersDescription( ) const;

            SharedPointerParameterScalar           setParameter( const SharedPointerParameterScalar&           );
            SharedPointerParameterText             setParameter( const SharedPointerParameterText&             );
            SharedPointerParameterGPUTexture       setParameter( const SharedPointerParameterGPUTexture&       );
            SharedPointerParameter8BitsCPUTexture  setParameter( const SharedPointerParameter8BitsCPUTexture&  );
            SharedPointerParameter16BitsCPUTexture setParameter( const SharedPointerParameter16BitsCPUTexture& );
            SharedPointerParameter32BitsCPUTexture setParameter( const SharedPointerParameter32BitsCPUTexture& );

            template<typename T>
            std::weak_ptr<T>   getParameter( const ParameterDescription& ) const;

        private:
            CollectionParameterScalar           mParameterScalars;
            CollectionParameterText             mParameterTexts;
            CollectionParameterGPUTexture       mParameterGPUTextures;
            CollectionParameter8BitsCPUTexture  mParameter8BitsCPUTextures;
            CollectionParameter16BitsCPUTexture mParameter16BitsCPUTextures;
            CollectionParameter32BitsCPUTexture mParameter32BitsCPUTextures;
    };

    template<> WeakPointerParameterScalar             BPIPE_IMPLEMENTATION(ParameterDatabase)::getParameter<ParameterScalar>           ( const ParameterDescription& ) const;
    template<> WeakPointerParameterText               BPIPE_IMPLEMENTATION(ParameterDatabase)::getParameter<ParameterText>             ( const ParameterDescription& ) const;
    template<> WeakPointerParameterGPUTexture         BPIPE_IMPLEMENTATION(ParameterDatabase)::getParameter<ParameterGPUTexture>       ( const ParameterDescription& ) const;
    template<> WeakPointerParameter8BitsCPUTexture    BPIPE_IMPLEMENTATION(ParameterDatabase)::getParameter<Parameter8BitsCPUTexture>  ( const ParameterDescription& ) const;
    template<> WeakPointerParameter16BitsCPUTexture   BPIPE_IMPLEMENTATION(ParameterDatabase)::getParameter<Parameter16BitsCPUTexture> ( const ParameterDescription& ) const;
    template<> WeakPointerParameter32BitsCPUTexture   BPIPE_IMPLEMENTATION(ParameterDatabase)::getParameter<Parameter32BitsCPUTexture> ( const ParameterDescription& ) const;

} /* bpipe */

#endif
