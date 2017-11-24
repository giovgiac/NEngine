/**
 * ActorComponent.h
 *
 * Copyright (c) Giovanni Giacomo. All Rights Reserved.
 *
 */

#pragma once

#include <Core/Object.h>

namespace Newton
{
	class NActorComponent : public NObject
	{
	public:
		virtual void Start(void);

		virtual void Tick(float DeltaTime);

	private:
		virtual void ConstructObject(void);
	};
}