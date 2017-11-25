/**
 * ActorComponent.h
 *
 * Copyright (c) Giovanni Giacomo. All Rights Reserved.
 *
 */

#pragma once

#include <Core/Object.h>
#include <Collections/Array.h>

namespace Newton
{
	class NActorComponent : public NObject
	{
	private:
		NArray<NActorComponent*> Components;

	public:
		virtual void Start(void);

		virtual void Tick(float DeltaTime);

		inline const NArray<NActorComponent*>& GetComponents(void) const { return Components; }
	private:
		virtual void ConstructObject(void);
	};
}