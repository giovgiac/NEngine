/**
 * SceneComponent.h
 *
 * Copyright (c) Giovanni Giacomo. All Rights Reserved.
 *
 */

#pragma once

#include <Components/ActorComponent.h>
#include <Math/Transform.h>

namespace Newton
{
	class NSceneComponent : public NActorComponent
	{
	protected:
		NTransform Transform;

	private:
		virtual void ConstructObject(void);

	public:
		NVector GetComponentPosition(void) const;

		float GetComponentRotation(void) const;

		NVector GetComponentScale(void) const;

		NTransform GetComponentTransform(void) const;
	};
}