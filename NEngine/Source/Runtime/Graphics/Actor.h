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
		NTransform Transform;
		class NWorld* World;

	private:
		virtual void ConstructObject(void);

	protected:
		inline class NWorld* GetWorld(void) const { return World; }
	};
}