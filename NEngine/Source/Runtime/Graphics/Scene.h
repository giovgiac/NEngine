/**
 * Scene.h
 *
 * Copyright (c) Giovanni Giacomo. All Rights Reserved.
 *
 */

#pragma once

#include <Core/Config.h>
#include <Graphics/Camera.h>
#include <Graphics/GameObject.h>

namespace Newton {
	/**
	 * NScene Class
	 *
	 * This class is responsible for creating the scenes, also called maps or levels.
	 *
	 */
	class NScene {
	private:
		NCamera Camera;
		NArray<NGameObject*> GameObjects;
		NVector Size;

	public:
		/**
		 * NScene Constructor
		 *
		 * This default constructor initializes a scene with default width and height.
		 *
		 */
		inline NScene(void);

		/**
		 * NScene Constructor
		 *
		 * This constructor initializes a scene with the given size.
		 *
		 * @param const NVector& InSize: The size of the scene.
		 *
		 */
		explicit inline NScene(const NVector& InSize);

		/**
		 * NScene Destructor
		 *
		 * This destructor cleans up by deleting each individual game object contained in the map.
		 *
		 */
		inline ~NScene(void);

		/**
		 * NScene AddObject
		 *
		 * This method adds a new game object to the scene.
		 *
		 * @param NGameObject* InObject: The object to add to the scene.
		 *
		 */
		inline void AddObject(NGameObject* InObject);

		/**
		 * NScene GetCamera
		 *
		 * This method gets the camera of the scene.
		 *
		 * @return const NCamera&: A reference to the camera.
		 *
		 */
		inline const NCamera& GetCamera(void) const;

		/**
		 * NScene GetObjects
		 *
		 * This method gets the game objects of the scene.
		 *
		 * @return const NArray<NGameObject*>&: A reference to the array of game objects.
		 *
		 */
		inline const NArray<NGameObject*>& GetObjects(void) const;
	};
}