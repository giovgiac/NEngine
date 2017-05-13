/**
 * GameObject.cpp
 *
 * Copyright (c) Giovanni Giacomo. All Rights Reserved.
 *
 */

#include "GameObject.h"

namespace Newton {
	NGameObject::NGameObject(void)
		: Position(0.0f), Rotation(0.0f), Size(0.0f), Color(), Texture(nullptr), Vertices(6)
	{
		AddStockVertices(Color);
	}

	NGameObject::NGameObject(const NVector& InPosition, const GLfloat InRotation, const NVector& InSize, const NColor& InColor, NTexture* InTexture)
		: Position(InPosition), Rotation(InRotation), Size(InSize), Color(InColor), Texture(InTexture), Vertices(6)
	{
		AddStockVertices(Color);
	}

	void NGameObject::Start(void) {}

	void NGameObject::Tick(void) {}

	void NGameObject::Translate(const NVector& InTranslation) {
		Position += InTranslation;
	}

	void NGameObject::Rotate(const GLfloat InRotation) {
		Rotation += InRotation;
	}

	void NGameObject::Scale(const NVector& InSize) {
		Size += InSize;
	}

	void NGameObject::AddStockVertices(const NColor& InColor) {
		Vertices[0] = { NVector(-1.0f,  1.0f), InColor, NVector(0.0f, 1.0f) };
		Vertices[1] = { NVector(-1.0f, -1.0f), InColor, NVector(0.0f, 0.0f) };
		Vertices[2] = { NVector( 1.0f, -1.0f), InColor, NVector(1.0f, 0.0f) };
		Vertices[3] = { NVector(-1.0f,  1.0f), InColor, NVector(0.0f, 1.0f) };
		Vertices[4] = { NVector( 1.0f, -1.0f), InColor, NVector(1.0f, 0.0f) };
		Vertices[5] = { NVector( 1.0f,  1.0f), InColor, NVector(1.0f, 1.0f) };
	}
}