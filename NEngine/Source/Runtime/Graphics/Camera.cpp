/**
 * Camera.cpp
 *
 * Copyright (c) Giovanni Giacomo. All Rights Reserved.
 *
 */

#include "Camera.h"

namespace Newton {
	NCamera::NCamera(void)
		: Left(0.0f), Right(0.0f), Bottom(0.0f), Top(0.0f), Near(DefaultCameraNear), Far(DefaultCameraFar) {}

	NCamera::NCamera(const GLfloat InRight, const GLfloat InTop)
		: Left(0.0f), Right(InRight), Bottom(0.0f), Top(InTop), Near(DefaultCameraNear), Far(DefaultCameraFar) {}

	NCamera::NCamera(const GLfloat InLeft, const GLfloat InRight, const GLfloat InBottom, const GLfloat InTop, const GLfloat InNear, const GLfloat InFar)
		: Left(InLeft), Right(InRight), Bottom(InBottom), Top(InTop), Near(InNear), Far(InFar) {}

	void NCamera::SetCamera(const GLfloat InLeft, const GLfloat InRight, const GLfloat InBottom, const GLfloat InTop, const GLfloat InNear, const GLfloat InFar) {
		Left = InLeft;
		Right = InRight;
		Bottom = InBottom;
		Top = InTop;
		Near = InNear;
		Far = InFar;
	}

	NMatrix NCamera::GetView(void) const {
		return NMatrix::Identity();
	}

	NMatrix NCamera::GetProjection(void) const {
		return NMatrix::Orthographic(Left, Right, Bottom, Top, Near, Far);
	}
}