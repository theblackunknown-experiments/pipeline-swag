/*
 * parameter_database.cpp
 *
 *  Created on: Jul 16, 2012
 *      Author: blackpanth3r
 */

#include <gtest/gtest.h>

#include "bpipe/parameter_database.hpp"
#include "bpipe/parameterfwd.hpp"
#include "bpipe/parameter.hpp"
#include "bpipe/parameter_texture.hpp"

using namespace bpipe;

void fillWithDummyData(ParameterDatabase& db)
{
	SharedPointerParameterScalar           pscalar ( new ParameterScalar           ("scalar"        , 13.37f) );
	SharedPointerParameterText             ptext   ( new ParameterText             ("text"          , "I'm a string parameter") );
	SharedPointerParameterGPUTexture       ptexgpu ( new ParameterGPUTexture       ("texture-gpu"   , 0u, 0u, 0u, 0u, 0u, 0u) );
	SharedPointerParameter8BitsCPUTexture  ptex8   ( new Parameter8BitsCPUTexture  ("texture-8bits" , 0u, 0u, 0u, 0u, 0u, Parameter8BitsCPUTexture::ValueType() ) );
	SharedPointerParameter16BitsCPUTexture ptex16  ( new Parameter16BitsCPUTexture ("texture-16bits", 0u, 0u, 0u, 0u, 0u, Parameter16BitsCPUTexture::ValueType() ) );
	SharedPointerParameter32BitsCPUTexture ptex32  ( new Parameter32BitsCPUTexture ("texture-32bits", 0u, 0u, 0u, 0u, 0u, Parameter32BitsCPUTexture::ValueType() ) );

	db.setParameter( pscalar );
	db.setParameter( ptext   );
	db.setParameter( ptexgpu );
	db.setParameter( ptex8   );
	db.setParameter( ptex16  );
	db.setParameter( ptex32  );
}

TEST(ParameterDatabaseTesting, NoParameterAvailablesAtConstruction)
{
	ParameterDatabase new_database;
	auto descriptions = new_database.getParametersDescription( );
	EXPECT_EQ(0u, descriptions.size());
}

TEST(ParameterDatabaseTesting, ParameterInsertion)
{
	ParameterDatabase db;

	fillWithDummyData( db );

	auto descriptions = db.getParametersDescription( );

	EXPECT_EQ(6u, descriptions.size());

	auto scalar_description = descriptions.at(0);
	auto text_description = descriptions.at(1);
	auto texturegpu_description = descriptions.at(2);
	auto texture8_description = descriptions.at(3);
	auto texture16_description = descriptions.at(4);
	auto texture32_description = descriptions.at(5);


	EXPECT_EQ("scalar", scalar_description.identifier);
	EXPECT_EQ(types::Scalar, scalar_description.type);

	EXPECT_EQ("text", text_description.identifier);
	EXPECT_EQ(types::Text, text_description.type);

	EXPECT_EQ("texture-gpu", texturegpu_description.identifier);
	EXPECT_EQ(types::Texture, texturegpu_description.type);

	EXPECT_EQ("texture-8bits", texture8_description.identifier);
	EXPECT_EQ(types::Texture, texture8_description.type);

	EXPECT_EQ("texture-16bits", texture16_description.identifier);
	EXPECT_EQ(types::Texture, texture16_description.type);

	EXPECT_EQ("texture-32bits", texture32_description.identifier);
	EXPECT_EQ(types::Texture, texture32_description.type);
}

TEST(ParameterDatabaseTesting, ParameterRetrieval)
{
	ParameterDatabase db;

	fillWithDummyData( db );

	ParameterDescription valid_scalar             ("scalar", types::Scalar);
	ParameterDescription mistype_name_scalar      ("saclar", types::Scalar);
	ParameterDescription mismatch_type_scalar     ("scalar", types::Text);

	ParameterDescription valid_text               ("text", types::Text);
	ParameterDescription mistype_name_text        ("txet", types::Text);
	ParameterDescription mismatch_type_text       ("text", types::Scalar);

	ParameterDescription valid_texture_gpu        ("texture-gpu", types::Texture);
	ParameterDescription mistype_name_texture_gpu ("texture-pgu", types::Texture);
	ParameterDescription mismatch_type_texture_gpu("texture-gpu", types::Scalar);

	ParameterDescription valid_texture8           ("texture-8bits", types::Texture);
	ParameterDescription mistype_name_texture8    ("textuer-8bits", types::Texture);
	ParameterDescription mismatch_type_texture8   ("texture-8bits", types::Scalar);

	ParameterDescription valid_texture16          ("texture-16bits", types::Texture);
	ParameterDescription mistype_name_texture16   ("textrue-16bits", types::Texture);
	ParameterDescription mismatch_type_texture16  ("texture-16bits", types::Scalar);

	ParameterDescription valid_texture32          ("texture-32bits", types::Texture);
	ParameterDescription mistype_name_texture32   ("tetxure-32bits", types::Texture);
	ParameterDescription mismatch_type_texture32  ("texture-32bits", types::Scalar);

	EXPECT_EQ(1u, db.getParameter<ParameterScalar>          ( valid_scalar         ).use_count());
	EXPECT_EQ(0u, db.getParameter<ParameterScalar>          ( mistype_name_scalar  ).use_count());
	EXPECT_EQ(0u, db.getParameter<ParameterScalar>          ( mismatch_type_scalar ).use_count());

	EXPECT_EQ(1u, db.getParameter<ParameterText>            ( valid_text         ).use_count());
	EXPECT_EQ(0u, db.getParameter<ParameterText>            ( mistype_name_text  ).use_count());
	EXPECT_EQ(0u, db.getParameter<ParameterText>            ( mismatch_type_text ).use_count());

	EXPECT_EQ(1u, db.getParameter<ParameterGPUTexture>      ( valid_texture_gpu         ).use_count());
	EXPECT_EQ(0u, db.getParameter<ParameterGPUTexture>      ( mistype_name_texture_gpu  ).use_count());
	EXPECT_EQ(0u, db.getParameter<ParameterGPUTexture>      ( mismatch_type_texture_gpu ).use_count());

	EXPECT_EQ(1u, db.getParameter<Parameter8BitsCPUTexture> ( valid_texture8         ).use_count());
	EXPECT_EQ(0u, db.getParameter<Parameter8BitsCPUTexture> ( mistype_name_texture8  ).use_count());
	EXPECT_EQ(0u, db.getParameter<Parameter8BitsCPUTexture> ( mismatch_type_texture8 ).use_count());

	EXPECT_EQ(1u, db.getParameter<Parameter16BitsCPUTexture>( valid_texture16         ).use_count());
	EXPECT_EQ(0u, db.getParameter<Parameter16BitsCPUTexture>( mistype_name_texture16  ).use_count());
	EXPECT_EQ(0u, db.getParameter<Parameter16BitsCPUTexture>( mismatch_type_texture16 ).use_count());

	EXPECT_EQ(1u, db.getParameter<Parameter32BitsCPUTexture>( valid_texture32         ).use_count());
	EXPECT_EQ(0u, db.getParameter<Parameter32BitsCPUTexture>( mistype_name_texture32  ).use_count());
	EXPECT_EQ(0u, db.getParameter<Parameter32BitsCPUTexture>( mismatch_type_texture32 ).use_count());
}
