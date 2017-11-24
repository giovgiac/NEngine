/**
 * PrimitiveComponent.h
 *
 * Copyright (c) Giovanni Giacomo. All Rights Reserved.
 *
 */

#pragma once

#include <Collections/Array.h>
#include <Components/SceneComponent.h>
#include <Graphics/Vertex.h>

namespace Newton
{
	class NPrimitiveComponent : public NSceneComponent
	{
	protected:
		NArray<NVertex> Vertices;
		NColor Color;

	public:
		NColor GetColor(void) const;

		const NArray<NVertex>& GetVertices(void) const;

	};
}