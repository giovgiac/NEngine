/**
 * PrimitiveComponent.cpp
 *
 * Copyright (c) Giovanni Giacomo. All Rights Reserved.
 *
 */

#include "PrimitiveComponent.h"

namespace Newton
{
	NColor NPrimitiveComponent::GetColor(void) const
	{
		return Color;
	}

	const NArray<NVertex>& NPrimitiveComponent::GetVertices(void) const
	{
		return Vertices;
	}
}