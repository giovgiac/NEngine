/**
 * Math.h
 *
 * Copyright (c) Giovanni Giacomo. All Rights Reserved.
 *
 */

#pragma once

#include <glew.h>
#include <math.h>

namespace Newton {
	const GLfloat PI = 3.141592654f;

	/**
	 * ToRadians Function
	 *
	 * This function converts an angle value from degrees to radians.
	 *
	 * @param GLfloat InAngle: The value of the angle in degrees.
	 *
	 * @return GLfloat: The value of the angle in radians.
	 *
	 */
	extern GLfloat ToRadians(GLfloat InAngle);

	/**
	 * ToDegrees Function
	 *
	 * This function converts an angle value from radians to degrees.
	 *
	 * @param GLfloat InAngle: The value of the angle in radians.
	 *
	 * @return GLfloat: The value of the angle in degrees.
	 *
	 */
	extern GLfloat ToDegrees(GLfloat InAngle);
}