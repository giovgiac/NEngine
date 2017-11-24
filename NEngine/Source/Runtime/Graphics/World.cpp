/**
 * World.cpp
 *
 * Copyright (c) Giovanni Giacomo. All Rights Reserved.
 *
 */

#include "World.h"

#include <Components/PrimitiveComponent.h>
#include <Graphics/Actor.h>

namespace Newton {
	NWorld::NWorld(void)
		: Scene(), Renderer() {}

	void NWorld::Draw(void) {
		//Renderer.Render(Scene, Arrays);
		Renderer.Render(Scene, Renderables);
	}

	//void NWorld::LoadScene(const NScene& InScene) {
	//	UnloadScene();
	//	GLuint Size = InScene.GetObjects().GetSize();
	//	
	//	// Setup Class Attributes
	//	Arrays = NArray<GLuint>(Size);
	//	Buffers = NArray<GLuint>(Size);
	//	Scene = InScene;

	//	// Create Arrays and Buffers on GPU
	//	glGenVertexArrays(Size, Arrays.GetData());
	//	glGenBuffers(Size, Buffers.GetData());

	//	for (GLuint i = 0; i < Size; i++) {
	//		glBindVertexArray(Arrays[i]);
	//		glBindBuffer(GL_ARRAY_BUFFER, Buffers[i]);
	//		glBufferData(GL_ARRAY_BUFFER, InScene.GetObjects()[i]->GetVertices().GetSize() * sizeof(NVertex), InScene.GetObjects()[i]->GetVertices().GetData(), GL_STATIC_DRAW);

	//		// Enable Attributes
	//		glEnableVertexAttribArray(Renderer.GetPositionID());
	//		glEnableVertexAttribArray(Renderer.GetColorID());
	//		glEnableVertexAttribArray(Renderer.GetTextureCoordinateID());

	//		glVertexAttribPointer(Renderer.GetPositionID(), 2, GL_FLOAT, GL_FALSE, sizeof(NVertex), 0);
	//		glVertexAttribPointer(Renderer.GetColorID(), 4, GL_FLOAT, GL_FALSE, sizeof(NVertex), (void*)sizeof(NVector));
	//		glVertexAttribPointer(Renderer.GetTextureCoordinateID(), 2, GL_FLOAT, GL_FALSE, sizeof(NVertex), (void*)(sizeof(NVector) + sizeof(NColor)));

	//		glBindBuffer(GL_ARRAY_BUFFER, 0);
	//		glBindVertexArray(0);
	//	}
	//}

	void NWorld::LoadScene(const NScene& InScene)
	{
		UnloadScene();
		uint32 Size = InScene.GetActors().GetSize();

		// Setup Class Attributes
		Actors = NArray<NActor*>();
		Arrays = NArray<uint32>();
		Buffers = NArray<uint32>();

		for (uint32 i = 0; i < Size; i++)
		{
			AddActor(InScene.GetActors()[i]);
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

	void NWorld::AddActor(NActor* InActor)
	{
		NArray<NPrimitiveComponent*> PrimitiveComponents = InActor->GetComponentsByClass<NPrimitiveComponent>();

		// Buffer Actor Geometry to GPU
		for (uint32 i = 0; i < PrimitiveComponents.GetSize(); i++)
		{
			NRenderable Renderable;

			// Increase Arrays and Buffers Size
			Arrays.Append(0);
			Buffers.Append(0);
			
			uint32 ArrayIndex = Arrays.GetSize() - 1;
			uint32 BufferIndex = Buffers.GetSize() - 1;

			// Create GPU Arrays and Buffers
			glGenVertexArrays(1, &Renderable.Array);
			glGenBuffers(1, &Renderable.Buffer);

			glBindVertexArray(Renderable.Array);
			glBindBuffer(GL_ARRAY_BUFFER, Renderable.Buffer);
			glBufferData(GL_ARRAY_BUFFER, PrimitiveComponents[i]->GetVertices().GetSize() * sizeof(NVertex), PrimitiveComponents[i]->GetVertices().GetData(), GL_STATIC_DRAW);
			
			// Enable Attributes
			glEnableVertexAttribArray(Renderer.GetPositionID());
			glEnableVertexAttribArray(Renderer.GetColorID());
			glEnableVertexAttribArray(Renderer.GetTextureCoordinateID());

			glVertexAttribPointer(Renderer.GetPositionID(), 2, GL_FLOAT, GL_FALSE, sizeof(NVertex), 0);
			glVertexAttribPointer(Renderer.GetColorID(), 4, GL_FLOAT, GL_FALSE, sizeof(NVertex), (void*)sizeof(NVector));
			glVertexAttribPointer(Renderer.GetTextureCoordinateID(), 2, GL_FLOAT, GL_FALSE, sizeof(NVertex), (void*)(sizeof(NVector) + sizeof(NColor)));

			glBindBuffer(GL_ARRAY_BUFFER, 0);
			glBindVertexArray(0);

			Renderable.Component = PrimitiveComponents[i];
			Renderables.Append(Renderable);
		}

		Actors.Append(InActor);
	}
}