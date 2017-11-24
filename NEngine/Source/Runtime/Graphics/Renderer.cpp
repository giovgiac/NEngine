/**
 * Renderer.cpp
 *
 * Copyright (c) Giovanni Giacomo. All Rights Reserved.
 *
 */

#include "Renderer.h"

#include <Components/PrimitiveComponent.h>
#include <Components/SpriteComponent.h>
#include <Graphics/Actor.h>

namespace Newton {
	NRenderer::NRenderer(void)
		: Shader()
	{
		SetupShader();
	}

	NRenderer::NRenderer(const NShader& InShader)
		: Shader(InShader)
	{
		SetupShader();
	}

	//void NRenderer::Render(const NScene& InScene, const NArray<GLuint>& InArrays) const {
	//	NCamera Camera = InScene.GetCamera();
	//	NArray<NGameObject*> GameObjects = InScene.GetObjects();

	//	if (GameObjects.GetSize() != InArrays.GetSize())
	//		return;

	//	// Add Transparency to Alpha Channel
	//	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//	glEnable(GL_BLEND);

	//	glClearColor(0.1f, 0.1f, 0.1f, 1);
	//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//	// Set Default View and Projection
	//	NMatrix View = Camera.GetView();
	//	NMatrix Projection = Camera.GetProjection();

	//	Shader.Bind();
	//	for (GLuint i = 0; i < GameObjects.GetSize(); i++) {
	//		glBindVertexArray(InArrays[i]);

	//		if (GameObjects[i]->GetTexture())
	//			GameObjects[i]->GetTexture()->Bind();

	//		NMatrix Translate = NMatrix::Translation(NVector3(GameObjects[i]->GetPosition().X, GameObjects[i]->GetPosition().Y, 0.0f));
	//		NMatrix Rotate = NMatrix::Rotation(GameObjects[i]->GetRotation(), NVector3(0.0f, 0.0f, 1.0f));
	//		NMatrix Scale = NMatrix::Scale(NVector3(GameObjects[i]->GetSize().X, GameObjects[i]->GetSize().Y, 1.0f));
	//		NMatrix World = Translate * Rotate * Scale;

	//		NMatrix TransformMatrix = Projection * View * World;

	//		glUniformMatrix4fv(Transform, 1, GL_FALSE, TransformMatrix.Elements);
	//		glDrawArrays(GL_QUADS, 0, GameObjects[i]->GetVertices().GetSize());

	//		if (GameObjects[i]->GetTexture())
	//			GameObjects[i]->GetTexture()->Unbind();

	//		glBindVertexArray(0);
	//	}
	//	Shader.Unbind();
	//}

	void NRenderer::Render(const NScene& InScene, const NArray<NRenderable>& InRenderables)
	{
		NCamera Camera = InScene.GetCamera();
		NArray<NActor*> Actors = InScene.GetActors();

		// Set OpenGL Properties
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glEnable(GL_BLEND);
		glClearColor(0.1f, 0.1f, 0.1f, 1);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Set View And Projection Matrices
		NMatrix View = Camera.GetView();
		NMatrix Projection = Camera.GetProjection();

		Shader.Bind();
		for (uint32 i = 0; i < InRenderables.GetSize(); i++)
		{
			glBindVertexArray(InRenderables[i].Array);

			NTransform Trans = InRenderables[i].Component->GetComponentTransform();
			NSpriteComponent* SpriteComponent = Cast<NSpriteComponent>(InRenderables[i].Component);
			if (SpriteComponent)
			{
				if (SpriteComponent->GetSprite())
				{
					SpriteComponent->GetSprite()->Bind();
				}
			}

			NMatrix Translate = NMatrix::Translation(NVector3(Trans.Position.X, Trans.Position.Y, 0.0f));
			NMatrix Rotate = NMatrix::Rotation(Trans.Rotation, NVector3(0.0f, 0.0f, 1.0f));
			NMatrix Scale = NMatrix::Scale(NVector3(Trans.Scale.X, Trans.Scale.Y, 1.0f));
			NMatrix World = Translate * Rotate * Scale;
			NMatrix Final = Projection * View * World;

			glUniformMatrix4fv(Transform, 1, GL_FALSE, Final.Elements);
			glDrawArrays(GL_QUADS, 0, InRenderables[i].Component->GetVertices().GetSize());

			if (SpriteComponent)
			{
				if (SpriteComponent->GetSprite())
				{
					SpriteComponent->GetSprite()->Unbind();
				}
			}

			glBindVertexArray(0);
		}
		Shader.Unbind();
	}

	void NRenderer::SetupShader(void) {
		Shader.Bind();
		Position = Shader.GetAttributeLocation("position");
		Color = Shader.GetAttributeLocation("color");
		TextureCoordinate = Shader.GetAttributeLocation("textureCoordinate");
		Transform = Shader.GetUniformLocation("transform");
		Shader.Unbind();
	}
}