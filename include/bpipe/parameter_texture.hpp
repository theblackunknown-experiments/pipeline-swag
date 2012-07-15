/*
 * parameter_texture.hpp
 *
 *  Created on: Jul 15, 2012
 *      Author: blackpanth3r
 */

#ifndef BPIPE_PARAMETER_TEXTURE_H
#define BPIPE_PARAMETER_TEXTURE_H

#include "bpipe/config.hpp"

#include <cinttypes>
#include <string>
#include <utility>
#include <memory>

#include "bpipe/types.hpp"

#include "bpipe/parameter.hpp"

namespace bpipe {

	/*
	 * TextureParameter class
	 * Superset of ValueParameter class, with all additional (meta)data for a texture
	 * - Type      : 1D, 2D, RECT, etc
	 * - Channels  : RGB, RGBA, L, (NOTE: Contained existing channels AND channel order information)
	 * - ByteDepth : Precision range used for channel storage (8, 16, 32 bits)
	 */
	template< typename DataContainer >
	class TextureParameter : public ValueParameter< std::shared_ptr<DataContainer>, types::Texture>
	{
	public:
		typedef std::shared_ptr<DataContainer>      PointerData;
		typedef std::pair<std::size_t, std::size_t> Dimension;
		typedef uint32_t                            Type;
		typedef uint32_t                            Channels;
		typedef std::size_t                         ByteDepth;

		TextureParameter(
				const std::string& identifier,
				const std::size_t width, const std::size_t height,
				const Type type, const Channels channels, const ByteDepth byte_depth,
				const PointerData& data)
		  : ValueParameter<PointerData, types::Texture>(identifier, data)
		  , mDimension( std::make_pair(width, height) )
		  , mType( type )
		  , mChannels( channels )
		  , mByteDepth( byte_depth )
		  {
		  }

		~TextureParameter( ) = default;

		std::size_t getWidth( ) const
		{
			return mDimension.first;
		}

		std::size_t getHeight( ) const
		{
			return mDimension.second;
		}

		Type getType( ) const
		{
			return mType;
		}

		Type getChannels( ) const
		{
			return mChannels;
		}

		ByteDepth getByteDepth( ) const
		{
			return mByteDepth;
		}

		std::string getSourceFilepath() const
		{
			return mSourceFilepath;
		}

		void setSourceFilepath(const std::string& sourceFilepath)
		{
			mSourceFilepath = sourceFilepath;
		}

	private:
		std::string                                   mSourceFilepath;
		Dimension                                     mDimension;
		Type                                          mType;
		Channels                                      mChannels;
		ByteDepth                                     mByteDepth;
	};

}  // namespace bpipe


#endif /* BPIPE_PARAMETER_TEXTURE_H */
