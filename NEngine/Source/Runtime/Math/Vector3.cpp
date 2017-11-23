/**
 * Vector3.cpp
 *
 * Copyright (c) Giovanni Giacomo. All Rights Reserved.
 *
 */

#include "Vector3.h"

#include <math.h>

namespace Newton {
	NVector3& NVector3::Add(const NVector3& InOther) {
		X += InOther.X;
		Y += InOther.Y;
		Z += InOther.Z;

		return *this;
	}

	NVector3& NVector3::Cross(const NVector3& InOther) {
		X = Y * InOther.Z - Z * InOther.Y;
		Y = Z * InOther.X - X * InOther.Z;
		Z = X * InOther.Y - Y * InOther.X;

		return *this;
	}

	GLfloat NVector3::Dot(const NVector3& InOther) const {
		return (X * InOther.X + Y * InOther.Y + Z * InOther.Z);
	}

	NVector3& NVector3::Divide(const GLfloat InScalar) {
		X /= InScalar;
		Y /= InScalar;
		Z /= InScalar;

		return *this;
	}

	GLfloat NVector3::Length(void) const {
		return sqrtf(powf(X, 2) + powf(Y, 2) + powf(Z, 2));
	}

	NVector3& NVector3::Normalize(void) {
		GLfloat Magnitude = Length();

		X /= Magnitude;
		Y /= Magnitude;
		Z /= Magnitude;

		return *this;
	}

	NVector3& NVector3::Multiply(const GLfloat InScalar) {
		X *= InScalar;
		Y *= InScalar;
		Z *= InScalar;

		return *this;
	}

	NVector3& NVector3::Subtract(const NVector3& InOther) {
		X -= InOther.X;
		Y -= InOther.Y;
		Z -= InOther.Z;

		return *this;
	}

	NVector3 NVector3::Cross(const NVector3& InLeft, const NVector3& InRight) {
		return NVector3(InLeft.Y * InRight.Z - InLeft.Z * InRight.Y, InLeft.Z * InRight.X - InLeft.X * InRight.Z, InLeft.X * InRight.Y - InLeft.Y * InRight.X);
	}

	NVector3& NVector3::operator+=(const NVector3& InOther) { return Add(InOther); }
	NVector3& NVector3::operator-=(const NVector3& InOther) { return Subtract(InOther); }
	NVector3& NVector3::operator*=(const GLfloat InScalar) { return Multiply(InScalar); }
	NVector3& NVector3::operator/=(const GLfloat InScalar) { return Divide(InScalar); }

	NVector3 operator+(NVector3 InLeft, const NVector3& InRight) { return InLeft.Add(InRight); }
	NVector3 operator-(NVector3 InLeft, const NVector3& InRight) { return InLeft.Subtract(InRight); }
	NVector3 operator*(NVector3 InVector, const GLfloat InScalar) { return InVector.Multiply(InScalar); }
	NVector3 operator/(NVector3 InVector, const GLfloat InScalar) { return InVector.Divide(InScalar); }
}