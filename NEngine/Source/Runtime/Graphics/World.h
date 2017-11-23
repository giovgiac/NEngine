/**
 * World.h
 *
 * Copyright (c) Giovanni Giacomo. All Rights Reserved.
 *
 */

#pragma once

#include <Collections/Array.h>
#include <Graphics/Actor.h>
#include <Graphics/Renderer.h>
#include <Graphics/Scene.h>

namespace Newton {
	/**
	 * NWorld
	 *
	 * This class is responsible for creating a world, the entity that renders a scene.
	 *
	 */
	class NWorld {
	private:
		NArray<GLuint> Arrays;
		NArray<GLuint> Buffers;
		NRenderer Renderer;
		NScene Scene;

	public:
		/**
		 * NWorld Constructor
		 *
		 * This default constructor initializes a new world.
		 *
		 */
		NWorld(void);

		/**
		 * NWorld Draw
		 *
		 * This method calls upon the renderer to draw the current scene.
		 *
		 */
		void Draw(void) const;

		/**
		 * NWorld LoadScene
		 *
		 * This method loads a new scene into the world and the GPU.
		 *
		 * @param NScene& InScene: The scene to load.
		 *
		 */
		void LoadScene(const NScene& InScene);

		/**
		 * NWorld UnloadScene
		 *
		 * This method unloads the previously loaded scene from world and GPU.
		 *
		 */
		void UnloadScene(void);

		/**
		 * NWorld GetScene
		 *
		 * This method returns the current scene.
		 *
		 * @return const NScene&: The current scene.
		 *
		 */
		inline const NScene& GetScene() const { return Scene; }

		template<typename T>
		T* SpawnActor(NTransform Transform)
		{
			return nullptr;
		}
	};
}