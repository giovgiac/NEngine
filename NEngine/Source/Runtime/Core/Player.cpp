/**
 * Player.cpp
 *
 * Copyright (c) Giovanni Giacomo. All Rights Reserved.
 *
 */

#include "Player.h"

namespace Newton {
	NPlayer::NPlayer(void)
		: NGameObject() {}

	NPlayer::NPlayer(const NVector& InPosition, const GLfloat InRotation, const NVector& InSize, const NColor& InColor, NTexture* InTexture)
		: NGameObject(InPosition, InRotation, InSize, InColor, InTexture) {}
}