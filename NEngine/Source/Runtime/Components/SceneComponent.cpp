/**
 * SceneComponent.cpp
 *
 * Copyright (c) Giovanni Giacomo. All Rights Reserved.
 *
 */

#include "SceneComponent.h"

namespace Newton
{
	void NSceneComponent::ConstructObject(void)
	{
		// Set Base Values
		Transform.Position = NVector(0.0f, 0.0f);
		Transform.Rotation = 0.0f;
		Transform.Scale = NVector(1.0f, 1.0f);
	}

	NVector NSceneComponent::GetComponentPosition(void) const
	{
		return Transform.Position;
	}

	float NSceneComponent::GetComponentRotation(void) const
	{
		return Transform.Rotation;
	}

	NVector NSceneComponent::GetComponentScale(void) const
	{
		return Transform.Scale;
	}

	NTransform NSceneComponent::GetComponentTransform(void) const
	{
		return Transform;
	}
}