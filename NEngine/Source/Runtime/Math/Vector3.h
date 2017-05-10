/**
 * Vector3.h
 *
 * Copyright (c) Giovanni Giacomo. All Rights Reserved.
 *
 */

#pragma once

#include <glew.h>

namespace Newton {
	/**
	 * NVector3 Struct
	 *
	 * This data type is for holding a vector in 3-D space. It uses OpenGL floating-point numbers for the coordinates.
	 *
	 */
	struct NVector3 {
		GLfloat X;
		GLfloat Y;
		GLfloat Z;

		/**
		 * NVector3 Constructor
		 *
		 * This default constructor initializes the vector to the zero vector.
		 *
		 */
		inline NVector3(void)
			: X(0.0f), Y(0.0f), Z(0.0f) {}

		/** 
		 * NVector3 Constructor
		 *
		 * This constructor initializes the coordinates of the vector to the same given floating-point number.
		 *
		 * @param GLfloat InF: The value to initialize the coordinates with.
		 *
		 */
		explicit inline NVector3(GLfloat InF)
			: X(InF), Y(InF), Z(InF) {}

		/**
		 * NVector3 Constructor
		 *
		 * This constructor initializes the coordinates of the vector to the given floating-point numbers.
		 *
		 * @param GLfloat InX: The value of the X coordinate.
		 * @param GLfloat InY: The value of the Y coordinate.
		 * @param GLfloat InZ: The value of the Z coordinate.
		 *
		 */
		explicit inline NVector3(GLfloat InX, GLfloat InY, GLfloat InZ)
			: X(InX), Y(InY), Z(InZ) {}
	};
}