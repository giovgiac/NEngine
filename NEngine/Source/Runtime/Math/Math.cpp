/**
 * Math.cpp
 *
 * Copyright (c) Giovanni Giacomo. All Rights Reserved.
 *
 */

#include "Math.h"

namespace Newton {
	GLfloat ToRadians(GLfloat InAngle) {
		return (InAngle * PI / 180.0f);
	}

	GLfloat ToDegrees(GLfloat InAngle) {
		return (InAngle * 180.0f / PI);
	}
}