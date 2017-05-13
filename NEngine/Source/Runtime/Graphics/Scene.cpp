/**
 * Scene.cpp
 *
 * Copyright (c) Giovanni Giacomo. All Rights Reserved.
 *
 */

#include "Scene.h"

namespace Newton {
	NScene::NScene(void)
		: Camera(DefaultSceneWidth, DefaultSceneHeight), Size(DefaultSceneWidth, DefaultSceneHeight) {}

	NScene::NScene(const NVector& InSize)
		: Camera(InSize.X, InSize.Y), Size(InSize) {}
}