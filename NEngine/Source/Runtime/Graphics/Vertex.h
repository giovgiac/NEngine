/**
 * Vertex.h
 *
 * Copyright (c) Giovanni Giacomo. All Rights Reserved.
 *
 */

#pragma once

#include <Math/Color.h>
#include <Math/Vector.h>

namespace Newton {
	/**
	 * Vertex Struct
	 *
	 * This data type is understood by the GPU and contains the properties necessary to draw a vertex.
	 *
	 */
	struct Vertex {
		NVector Position;
		NColor Color;
		NVector TexCoord;
	};
}