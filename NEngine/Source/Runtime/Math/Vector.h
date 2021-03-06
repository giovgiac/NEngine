/**
 * Vector.h
 *
 * Copyright (c) Giovanni Giacomo. All Rights Reserved.
 *
 */

#pragma once

#include <glew.h>

namespace Newton {
	/**
	 * NVector Struct
	 *
	 * This data type is for holding a vector in 2-D space, using OpenGL floating-point coordinates.
	 *
	 */
	struct NVector {
		GLfloat X;
		GLfloat Y;

		/**
		 * NVector Constructor
		 *
		 * The default constructor which initializes the vector to the zero vector.
		 *
		 */
		NVector(void);

		/**
		 * NVector Constructor
		 * 
		 * This constructor initializes the vector with components equal to the same floating-point number.
		 *
		 * @param GLfloat InF: The value to initialize the components to.
		 *
		 */
		explicit NVector(const GLfloat InF);

		/**
		 * NVector Constructor
		 *
		 * This constructor initializes the vector to given floating-point values.
		 *
		 * @param GLfloat InX: The value of the X coordinate.
		 * @param GLfloat InY: The value of the Y coordinate.
		 *
		 */
		explicit NVector(const GLfloat InX, const GLfloat InY);

		/** 
		 * NVector Add
		 *
		 * This method adds two vectors together, the current one with the given one.
		 *
		 * @param const NVector& InOther: The vector add with the current one.
		 *
		 * @return NVector&: A reference to self.
		 *
		 */
		NVector& Add(const NVector& InOther);

		/**
		 * NVector Divide
		 *
		 * This method divides a vector by a scalar.
		 *
		 * @param const GLfloat InScalar: The scalar to divide the vector by.
		 *
		 * @return NVector&: A reference to self.
		 *
		 */
		NVector& Divide(const GLfloat InScalar);

		/**
		 * NVector Multiply
		 *
		 * This method multiplies a vector and a scalar.
		 *
		 * @param const GLfloat InScalar: The scalar to multiply the vector by.
		 *
		 * @return NVector&: A reference to self.
		 *
		 */
		NVector& Multiply(const GLfloat InScalar);

		/**
		 * NVector Zero
		 *
		 * This method returns the zero vector.
		 *
		 * @return NVector: A copy of the zero vector.
		 *
		 */
		inline static NVector Zero(void) { return NVector(0.0f); }

		bool operator==(const NVector& InOther);

		NVector& operator+=(const NVector& InOther);
		NVector& operator*=(const GLfloat InScalar);
		NVector& operator/=(const GLfloat InScalar);

		friend NVector operator+(NVector InLeft, const NVector& InRight);
		friend NVector operator*(NVector InVector, const GLfloat InScalar);
		friend NVector operator/(NVector InVector, const GLfloat InScalar);
	};
}