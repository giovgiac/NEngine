/**
 * SpriteComponent.cpp
 *
 * Copyright (c) Giovanni Giacomo. All Rights Reserved.
 *
 */

#include "SpriteComponent.h"

#include <Graphics/Texture.h>

namespace Newton
{
	void NSpriteComponent::ConstructObject(void)
	{
		// Set Base Configuration
		Transform.Position = NVector(0.0f, 0.0f);
		Transform.Rotation = 0.0f;
		Transform.Scale = NVector(1.0f, 1.0f);
		Color = Colors::White;
		Sprite = nullptr;

		// Add Stock Vertices
		Vertices = NArray<NVertex>(4);
		Vertices[0] = { NVector(-1.0f,  1.0f), Color, NVector(0.0f, 1.0f) };
		Vertices[1] = { NVector(-1.0f, -1.0f), Color, NVector(0.0f, 0.0f) };
		Vertices[2] = { NVector( 1.0f, -1.0f), Color, NVector(1.0f, 0.0f) };
		Vertices[3] = { NVector( 1.0f,  1.0f), Color, NVector(1.0f, 1.0f) };
	}

	void NSpriteComponent::SetSprite(class NTexture* InSprite)
	{
		Sprite = InSprite;
	}

	NTexture* NSpriteComponent::GetSprite(void) const
	{
		return Sprite;
	}
}