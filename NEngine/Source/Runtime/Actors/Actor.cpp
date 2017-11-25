/**
 * Actor.cpp
 *
 * Copyright (c) Giovanni Giacomo. All Rights Reserved.
 *
 */

#include "Actor.h"

#include <Components/SpriteComponent.h>
#include <Graphics/World.h>

namespace Newton
{
	NActor::NActor(void)
	{
		NTexture* GokuTexture = new NTexture("goku.png");

		NTransform NewTransform;
		NewTransform.Position = NVector(0.0f, 0.0f);
		NewTransform.Rotation = 0.0f;
		NewTransform.Scale = NVector(0.25f, 0.25f);

		NSpriteComponent* SpriteComponent = CreateDefaultSubobject<NSpriteComponent>("Test");
		SpriteComponent->SetSprite(GokuTexture);
		SpriteComponent->SetComponentTransform(NewTransform);
		Components.Append(SpriteComponent);
	}

	void NActor::Start(void)
	{

	}

	void NActor::Tick(float DeltaTime)
	{

	}

	void NActor::ConstructObject(void)
	{
		
	}
}