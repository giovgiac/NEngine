/**
 * World.h
 *
 * Copyright (c) Giovanni Giacomo. All Rights Reserved.
 *
 */

#pragma once

#include <Collections/Array.h>
#include <Graphics/Renderer.h>
#include <Graphics/Scene.h>

namespace Newton {
	/**
	 * NWorld
	 *
	 * ...
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
		 * ...
		 *
		 */
		inline NWorld(void);

		/**
		 * NWorld Draw
		 *
		 * ...
		 *
		 */
		inline void Draw(void) const;

		/**
		 * NWorld LoadScene
		 *
		 * ...
		 *
		 * @param const NScene& InScene: ...
		 *
		 */
		inline void LoadScene(const NScene& InScene);

		/**
		 * NWorld GetScene
		 *
		 * ...
		 *
		 * @return const NScene&: ...
		 *
		 */
		inline const NScene& GetScene() const;
	};
}