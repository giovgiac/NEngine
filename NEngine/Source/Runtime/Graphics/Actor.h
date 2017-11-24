/**
 * Actor.h
 *
 * Copyright (c) Giovanni Giacomo. All Rights Reserved.
 *
 */

#pragma once

#include <Core/Object.h>
#include <Collections/Array.h>
#include <Math/Transform.h>

namespace Newton
{
	class NActor : public NObject
	{
	private:
		NArray<class NActorComponent*> Components;
		NTransform Transform;
		class NWorld* World;

	private:
		virtual void ConstructObject(void);

	protected:
		inline class NWorld* GetWorld(void) const { return World; }

	public:
		NActor(void);

		template<typename T>
		NArray<T*> GetComponentsByClass(void)
		{
			NArray<T*> Result;

			for (uint32 i = 0; i < Components.GetSize(); i++)
			{
				T* Component = Cast<T>(Components[i]);
				if (Component)
					Result.Append(Component);
			}

			return Result;
		}
	};
}