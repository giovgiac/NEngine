/**
 * Transform.h
 *
 * Copyright (c) Giovanni Giacomo. All Rights Reserved.
 *
 */

#pragma once

#include <Math/Vector.h>

namespace Newton
{
	struct NTransform
	{
		NVector Position;
		float Rotation;
		NVector Scale;
	};
}