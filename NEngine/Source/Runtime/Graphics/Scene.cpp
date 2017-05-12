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

	NScene::~NScene(void) {
		for (GLuint i = 0; i < GameObjects.GetSize(); i++)
			delete GameObjects[i];
	}

	void NScene::AddObject(NGameObject* InObject) {
		GameObjects.Append(InObject);
	}

	const NCamera& NScene::GetCamera(void) const {
		return Camera;
	}

	const NArray<NGameObject*>& NScene::GetObjects(void) const {
		return GameObjects;
	}
}