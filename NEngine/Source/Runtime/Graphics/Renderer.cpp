/**
 * Renderer.cpp
 *
 * Copyright (c) Giovanni Giacomo. All Rights Reserved.
 *
 */

#include "Renderer.h"

#include <Actors/Actor.h>
#include <Components/PrimitiveComponent.h>
#include <Components/SpriteComponent.h>

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