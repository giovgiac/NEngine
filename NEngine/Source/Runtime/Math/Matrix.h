/**
 * Matrix.h
 *
 * Copyright (c) Giovanni Giacomo. All Rights Reserved.
 *
 */

#pragma once

#include <glew.h>
#include <memory.h>

#include "Math.h"
#include "Vector3.h"
#include "Vector4.h"

namespace Newton {
	/** 
	 * NMatrix Struct
	 *
	 * This data type holds a 4x4 Matrix in column-major ordering and using as values OpenGL floating-point numbers.
	 *
	 */
	struct NMatrix {
		union {
			NVector4 Columns[4];
			GLfloat Elements[16];
			GLfloat Transpose[4][4];
		};

		/**
		 * NMatrix Constructor
		 *
		 * This default constructor initializes a matrix with all entries holding zero.
		 *
		 */
		inline NMatrix(void);

		/**
		 * NMatrix Constructor
		 *
		 * This constructor initializes a matrix with the main diagonal holding the given value and everywhere else holding zero.
		 *
		 * @param GLfloat InDiagonal: The value of the main diagonal entries.
		 *
		 */
		explicit inline NMatrix(GLfloat InDiagonal);

		/**
		 * NMatrix Multiply
		 *
		 * This method multiplies the current matrix by another given matrix.
		 *
		 * @param const NMatrix& InOther: The matrix to multiply by.
		 *
		 * @return NMatrix&: A reference to the current matrix.
		 *
		 */
		inline NMatrix& Multiply(const NMatrix& InOther);

		/**
		 * NMatrix Identity
		 *
		 * This static method initializes a matrix with the main diagonal holding one and everywhere else holding zero.
		 *
		 * @return NMatrix: A initialized identity matrix.
		 *
		 */
		static NMatrix Identity(void);

		/**
		 * NMatrix Orthographic
		 *
		 * This static method initializes a projection matrix of type Orthographic given the clip values.
		 *
		 * @param GLfloat InLeft: The value to clip at left.
		 * @param GLfloat InRight: The value to clip at right.
		 * @param GLfloat InBottom: The value to clip at bottom.
		 * @param GLfloat InTop: The value to clip at top.
		 * @param GLfloat InNear: The value to clip at near.
		 * @param GLfloat InFar: The value to clip at far.
		 *
		 * @return NMatrix: A initialized orthographic projection matrix.
		 *
		 */
		static NMatrix Orthographic(GLfloat InLeft, GLfloat InRight, GLfloat InBottom, GLfloat InTop, GLfloat InNear, GLfloat InFar);

		/**
		 * NMatrix LookAt
		 */
		static NMatrix LookAt(NVector3 Eye, NVector3 Center, NVector3 Up);

		/**
		 * NMatrix Rotation
		 *
		 * This static method initializes a rotation matrix given the angle and axis of rotation.
		 *
		 * @param GLfloat InAngle: The value of the angle to rotate by.
		 * @param const NVector3& InAxis: The axis to rotate around.
		 *
		 * @return NMatrix: A initialized rotation matrix.
		 *
		 */
		static NMatrix Rotation(GLfloat InAngle, const NVector3& InAxis);

		/**
		 * NMatrix Scale
		 *
		 * This static method initializes a scale matrix given the values to scale each component by.
		 *
		 * @param const NVector3& InScale: The values to scale each component by.
		 *
		 * @return NMatrix: A initialized scaling matrix.
		 *
		 */
		static NMatrix Scale(const NVector3& InScale);

		/**
		 * NMatrix Translation
		 *
		 * This static method initializes a translation matrix given the values to move each component by.
		 *
		 * @param const NVector3& InTranslation: The values to move each component by.
		 *
		 * @return NMatrix: A initialized translation matrix.
		 *
		 */
		static NMatrix Translation(const NVector3& InTranslation);

		inline NMatrix& operator*=(const NMatrix& InOther);
		friend NMatrix operator*(NMatrix InLeft, const NMatrix& InRight);
	};
}