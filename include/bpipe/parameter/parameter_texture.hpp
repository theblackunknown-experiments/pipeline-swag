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

#include "bpipe/type.hpp"

#include "bpipe/parameter/parameter.hpp"

namespace bpipe {

	/*
	 * TextureParameter class
	 * Superset of ValueParameter class, with all additional (meta)data for a texture
	 * - Type      : 1D, 2D, RECT, etc
	 * - Channels  : RGB, RGBA, L, (NOTE: Contained existing channels AND channel order information)
	 * - ByteDepth : Precision range used for channel storage (8, 16, 32 bits)
	 */
	template< typename DataContainer >
	class TextureParameter : public ValueParameter< DataContainer, type::Texture>
	{
	public:
		typedef std::pair<std::size_t, std::size_t> Dimension;
		typedef uint32_t                            Type;
		typedef uint32_t                            Channels;
		typedef std::size_t                         ByteDepth;

		BPIPE_API_ENTRY explicit TextureParameter(
				const std::string& identifier,
				const std::size_t width, const std::size_t height,
				const Type type, const Channels channels, const ByteDepth byte_depth,
				const DataContainer& data)
		  : ValueParameter<DataContainer, type::Texture>(identifier, data)
		  , mDimension( std::make_pair(width, height) )
		  , mType( type )
		  , mChannels( channels )
		  , mByteDepth( byte_depth )
		  {
		  }

		BPIPE_API_ENTRY ~TextureParameter( ) = default;

		BPIPE_API_ENTRY std::size_t getWidth( ) const
		{
			return mDimension.first;
		}

		BPIPE_API_ENTRY std::size_t getHeight( ) const
		{
			return mDimension.second;
		}

		BPIPE_API_ENTRY Type getType( ) const
		{
			return mType;
		}

		BPIPE_API_ENTRY Type getChannels( ) const
		{
			return mChannels;
		}

		BPIPE_API_ENTRY ByteDepth getByteDepth( ) const
		{
			return mByteDepth;
		}

		BPIPE_API_ENTRY std::string getSourceFilepath() const
		{
			return mSourceFilepath;
		}

		BPIPE_API_ENTRY void setSourceFilepath(const std::string& sourceFilepath)
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
