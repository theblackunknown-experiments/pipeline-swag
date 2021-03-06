#ifndef BPIPE_PARAMETER_H
#define BPIPE_PARAMETER_H

#include "bpipe/config.hpp"

#include <string>
#include <memory>

#include "bpipe/type.hpp"

namespace bpipe {

	/*
	 * Parameter class
	 * A parameter is identified (like a name)
	 * It is a storage for a computed value, used for a step's input or step's output
	 * A parameter may has its value depend on another parameter
	 */
    template<
        typename             DataType,
        type::ParameterType ApplicationType>
    class ValueParameter
    {
        public:
		typedef DataType                                                 ValueType;              //Contained value type
		typedef std::weak_ptr<ValueParameter<DataType, ApplicationType>> WeakPointerDependency;  //Pointer on dependency (does not own ownership on dependency)

            /*
             * Build a Parameter by identifier and value
             */
			BPIPE_API_ENTRY explicit ValueParameter (
                    const std::string& identifier,
                    const ValueType& default_value = ValueType())
                : mIdentifier( identifier )
                , mDependency( )
            	, mValue( default_value )
            {
            }

			BPIPE_API_ENTRY ValueParameter ( const ValueParameter& rhs )
				: mIdentifier( rhs.mIdentifier )
				, mDependency( rhs.mDependency )
				, mValue     ( rhs.mValue )
			{

			}

			BPIPE_API_ENTRY ValueParameter& operator=( const ValueParameter& rhs )
			{
				mIdentifier = rhs.mIdentifier;
				mDependency = rhs.mDependency;
				mValue      = rhs.mValue;
				return *this;
			}

			BPIPE_API_ENTRY virtual ~ValueParameter ()
			{

			}

			BPIPE_API_ENTRY std::string getIdentifier( ) const
            {
                return mIdentifier;
            }

			BPIPE_API_ENTRY type::ParameterType getType( ) const
            {
                return ApplicationType;
            }

            /*
             * Set embedded value
             * @note : call to this method will break any existing dependency
             */
			BPIPE_API_ENTRY ValueType setValue( const ValueType&& newValue )
            {
                ValueType old( std::move(newValue) );
                std::swap(old, mValue);
                mDependency.reset( );
                return std::move(old);
            }

			BPIPE_API_ENTRY ValueType setValue( const ValueType& newValue )
            {
                ValueType old( newValue );
                std::swap(old, mValue);
                return std::move(old);
            }

            /*
             * Request embedded value
             */
			BPIPE_API_ENTRY ValueType getValue( ) const
            {
                return mValue;
            }

            /*
             * Set this parameter's dependency
             */
			BPIPE_API_ENTRY WeakPointerDependency setDependency( const WeakPointerDependency& dep )
            {
                WeakPointerDependency old( dep );
                std::swap( old, mDependency );
                return std::move( old );
            }

            /*
             * Request embedded value by resolving dependency, if not dependent on any parameter embedded value is given
             */
			BPIPE_API_ENTRY ValueType resolveValueByDependency( ) const
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
