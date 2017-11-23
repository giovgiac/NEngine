/**
 * Matrix.cpp
 *
 * Copyright (c) Giovanni Giacomo. All Rights Reserved.
 *
 */

#include "Matrix.h"

namespace Newton {
	NMatrix::NMatrix(void) {
		memset(Elements, 0, 16 * sizeof(GLfloat));
	}

	NMatrix::NMatrix(GLfloat InDiagonal) {
		memset(Elements, 0, 16 * sizeof(GLfloat));

		// Set Main Diagonal Using [Row + Column * 4]
		Elements[0 + 0 * 4] = InDiagonal;
		Elements[1 + 1 * 4] = InDiagonal;
		Elements[2 + 2 * 4] = InDiagonal;
		Elements[3 + 3 * 4] = InDiagonal;
	}

	NMatrix& NMatrix::Multiply(const NMatrix& InOther) {
		GLfloat Result[16];

		for (GLuint y = 0; y < 4; y++) {
			for (GLuint x = 0; x < 4; x++) {
				GLfloat Sum = 0.0f;

				for (GLuint e = 0; e < 4; e++)
					Sum += Elements[x + e * 4] * InOther.Elements[e + y * 4];
				Result[x + y * 4] = Sum;
			}
		}

		memcpy(Elements, Result, 16 * sizeof(GLfloat));
		return *this;
	}

	NMatrix NMatrix::Identity(void) {
		return NMatrix(1.0f);
	}

	NMatrix NMatrix::Orthographic(GLfloat InLeft, GLfloat InRight, GLfloat InBottom, GLfloat InTop, GLfloat InNear, GLfloat InFar) {
		NMatrix Result = NMatrix::Identity();

		// Main Diagonal
		Result.Elements[0 + 0 * 4] = 2.0f / (InRight - InLeft);
		Result.Elements[1 + 1 * 4] = 2.0f / (InTop - InBottom);
		Result.Elements[2 + 2 * 4] = 2.0f / (InNear - InFar);

		// Last Column
		Result.Elements[0 + 3 * 4] = (InLeft + InRight) / (InLeft - InRight);
		Result.Elements[1 + 3 * 4] = (InBottom + InTop) / (InBottom - InTop);
		Result.Elements[2 + 3 * 4] = (InFar + InNear) / (InFar - InNear);

		return Result;
	}

	NMatrix NMatrix::LookAt(NVector3 Eye, NVector3 Center, NVector3 Up) {
		NMatrix Result = NMatrix::Identity();

		// Basic Vectors
		NVector3 A = Eye - Center;
		NVector3 B = Up;

		// Obtain Matrix Vectors
		NVector3 W = A / A.Length();
		NVector3 U = NVector3::Cross(B, W) / NVector3::Cross(B, W).Length();
		NVector3 V = NVector3::Cross(W, U);

		// First Column
		Result.Elements[0 + 0 * 4] = U.X;
		Result.Elements[1 + 0 * 4] = U.Y;
		Result.Elements[2 + 0 * 4] = U.Z;
		Result.Elements[3 + 0 * 4] = -U.Dot(Eye);

		// Second Column
		Result.Elements[0 + 1 * 4] = V.X;
		Result.Elements[1 + 1 * 4] = V.Y;
		Result.Elements[2 + 1 * 4] = V.Z;
		Result.Elements[3 + 1 * 4] = -V.Dot(Eye);

		// Third Column
		Result.Elements[0 + 2 * 4] = W.X;
		Result.Elements[1 + 2 * 4] = W.Y;
		Result.Elements[2 + 2 * 4] = W.Z;
		Result.Elements[3 + 2 * 4] = -W.Dot(Eye);

		return Result;
	}

	NMatrix NMatrix::Rotation(GLfloat InAngle, const NVector3& InAxis) {
		NMatrix Result = NMatrix::Identity();
		GLfloat Radian = ToRadians(InAngle);
		GLfloat Cosine = cosf(Radian);
		GLfloat Sine = sinf(Radian);
		GLfloat OMC = 1.0f - Cosine;

		// First Column
		Result.Elements[0 + 0 * 4] = InAxis.X * OMC + Cosine;
		Result.Elements[1 + 0 * 4] = InAxis.Y * InAxis.X * OMC + InAxis.Z * Sine;
		Result.Elements[2 + 0 * 4] = InAxis.X * InAxis.Z * OMC - InAxis.Y * Sine;

		// Second Column
		Result.Elements[0 + 1 * 4] = InAxis.X * InAxis.Y * OMC - InAxis.Z * Sine;
		Result.Elements[1 + 1 * 4] = InAxis.Y * OMC + Cosine;
		Result.Elements[2 + 1 * 4] = InAxis.Y * InAxis.Z * OMC + InAxis.X * Sine;

		// Third Column
		Result.Elements[0 + 2 * 4] = InAxis.X * InAxis.Z * OMC + InAxis.Y * Sine;
		Result.Elements[1 + 2 * 4] = InAxis.Y * InAxis.Z * OMC - InAxis.X * Sine;
		Result.Elements[2 + 2 * 4] = InAxis.Z * OMC + Cosine;

		return Result;
	}

	NMatrix NMatrix::Scale(const NVector3& InScale) {
		NMatrix Result = NMatrix::Identity();

		// Main Diagonal
		Result.Elements[0 + 0 * 4] = InScale.X;
		Result.Elements[1 + 1 * 4] = InScale.Y;
		Result.Elements[2 + 2 * 4] = InScale.Z;

		return Result;
	}

	NMatrix NMatrix::Translation(const NVector3& InTranslation) {
		NMatrix Result = NMatrix::Identity();

		// Last Column
		Result.Elements[0 + 3 * 4] = InTranslation.X;
		Result.Elements[1 + 3 * 4] = InTranslation.Y;
		Result.Elements[2 + 3 * 4] = InTranslation.Z;

		return Result;
	}

	NMatrix& NMatrix::operator*=(const NMatrix& InOther) { return Multiply(InOther); }
	NMatrix operator*(NMatrix InLeft, const NMatrix& InRight) { return InLeft.Multiply(InRight); }
}