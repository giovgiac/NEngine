/**
 * Vector.cpp
 *
 * Copyright (c) Giovanni Giacomo. All Rights Reserved.
 *
 */

#include "Vector.h"

namespace Newton {
	NVector::NVector(void)
		: X(0.0f), Y(0.0f) {}

	NVector::NVector(const GLfloat InF)
		: X(InF), Y(InF) {}

	NVector::NVector(const GLfloat InX, const GLfloat InY)
		: X(InX), Y(InY) {}

	NVector& NVector::Add(const NVector& InOther) {
		X += InOther.X;
		Y += InOther.Y;

		return *this;
	}

	NVector& NVector::Multiply(const GLfloat InScalar) {
		X *= InScalar;
		Y *= InScalar;

		return *this;
	}

	NVector& NVector::operator+=(const NVector& InOther) { return Add(InOther); }
	NVector& NVector::operator*=(const GLfloat InScalar) { return Multiply(InScalar); }

	NVector operator+(NVector InLeft, const NVector& InRight) { return InLeft.Add(InRight); }
	NVector operator*(NVector InVector, const GLfloat InScalar) { return InVector.Multiply(InScalar); }
}