#ifndef BPIPE_PARAMETER_H
#define BPIPE_PARAMETER_H

#include "bpipe/config.hpp"

#include <string>
#include <memory>

#include "bpipe/types.hpp"

namespace bpipe {

	/*
	 * Parameter class
	 * A parameter is identified (like a name)
	 * It is a storage for a computed value, used for a step's input or step's output
	 * A parameter may has its value depend on another parameter
	 */
    template<
        typename             DataType,
        types::ParameterType ApplicationType>
    class ValueParameter
    {
        public:
		typedef DataType                                                 ValueType;              //Contained value type
		typedef std::weak_ptr<ValueParameter<DataType, ApplicationType>> WeakPointerDependency;  //Pointer on dependency (does not own ownership on dependency)

            /*
             * Build a Parameter by identifier and value
             */
            ValueParameter (
                    const std::string& identifier,
                    const ValueType& default_value = ValueType())
                : mIdentifier( identifier )
                , mDependency( )
            	, mValue( default_value )
            {
            }

            ValueParameter ( const ValueParameter& rhs ) = default;

            ValueParameter& operator=( const ValueParameter& rhs ) = default;

            virtual ~ValueParameter () { };

            std::string getIdentifier( ) const
            {
                return mIdentifier;
            }

            types::ParameterType getType( ) const
            {
                return ApplicationType;
            }

            /*
             * Set embedded value
             * @note : call to this method will break any existing dependency
             */
            ValueType setValue( const ValueType&& newValue )
            {
                ValueType old( std::move(newValue) );
                std::swap(old, mValue);
                mDependency.reset( );
                return std::move(old);
            }

            ValueType setValue( const ValueType& newValue )
            {
                ValueType old( newValue );
                std::swap(old, mValue);
                return std::move(old);
            }

            /*
             * Request embedded value
             */
            ValueType getValue( ) const
            {
                return mValue;
            }

            /*
             * Set this parameter's dependency
             */
            WeakPointerDependency setDependency( const WeakPointerDependency& dep )
            {
                WeakPointerDependency old( dep );
                std::swap( old, mDependency );
                return std::move( old );
            }

            /*
             * Request embedded value by resolving dependency, if not dependent on any parameter embedded value is given
             */
            ValueType resolveValueByDependency( ) const
            {
            	if( auto pDependency = mDependency.lock() )
            	{
            		return pDependency->resolveValueByDependency( );
            	}
            	else
            	{
            		return getValue( );
            	}
            }

        private:
            std::string           mIdentifier;
            WeakPointerDependency mDependency;
            ValueType             mValue;
    };
} /* bpipe */

#endif
