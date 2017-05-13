/**
 * World.cpp
 *
 * Copyright (c) Giovanni Giacomo. All Rights Reserved.
 *
 */

#include "World.h"

namespace Newton {
	NWorld::NWorld(void)
		: Scene(), Renderer() {}

	void NWorld::Draw(void) const {
		Renderer.Render(Scene, Arrays);
	}

	void NWorld::LoadScene(const NScene& InScene) {
		UnloadScene();
		GLuint Size = InScene.GetObjects().GetSize();

		// Setup Class Attributes
		Arrays = NArray<GLuint>(Size);
		Buffers = NArray<GLuint>(Size);
		Scene = InScene;

		// Create Arrays and Buffers on GPU
		glGenVertexArrays(Size, Arrays.GetData());
		glGenBuffers(Size, Buffers.GetData());

		for (GLuint i = 0; i < Size; i++) {
			glBindVertexArray(Arrays[i]);
			glBindBuffer(GL_ARRAY_BUFFER, Buffers[i]);
			glBufferData(GL_ARRAY_BUFFER, InScene.GetObjects()[i]->GetVertices().GetSize() * sizeof(NVertex), InScene.GetObjects()[i]->GetVertices().GetData(), GL_STATIC_DRAW);

			// Enable Attributes
			glEnableVertexAttribArray(Renderer.GetPositionID());
			glEnableVertexAttribArray(Renderer.GetColorID());
			glEnableVertexAttribArray(Renderer.GetTextureCoordinateID());

			glVertexAttribPointer(Renderer.GetPositionID(), 2, GL_FLOAT, GL_FALSE, sizeof(NVertex), 0);
			glVertexAttribPointer(Renderer.GetColorID(), 4, GL_FLOAT, GL_FALSE, sizeof(NVertex), (void*)sizeof(NVector));
			glVertexAttribPointer(Renderer.GetTextureCoordinateID(), 2, GL_FLOAT, GL_FALSE, sizeof(NVertex), (void*)(sizeof(NVector) + sizeof(NColor)));

			glBindBuffer(GL_ARRAY_BUFFER, 0);
			glBindVertexArray(0);
		}
	}

	void NWorld::UnloadScene(void) {
		if (Scene.GetObjects().GetSize() > 0) {
			glDeleteVertexArrays(Arrays.GetSize(), Arrays.GetData());
			glDeleteBuffers(Buffers.GetSize(), Buffers.GetData());
			
			for (GLuint i = 0; i < Scene.GetObjects().GetSize(); i++)
				delete Scene.GetObjects()[i];
		}
	}
}