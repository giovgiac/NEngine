/**
 * Renderer.cpp
 *
 * Copyright (c) Giovanni Giacomo. All Rights Reserved.
 *
 */

#include "Renderer.h"

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

	void NRenderer::Render(const NScene& InScene, const NArray<GLuint>& InArrays) const {
		NCamera Camera = InScene.GetCamera();
		NArray<NGameObject*> GameObjects = InScene.GetObjects();

		if (GameObjects.GetSize() != InArrays.GetSize())
			return;

		// Add Transparency to Alpha Channel
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glEnable(GL_BLEND);

		glClearColor(0.1f, 0.1f, 0.1f, 1);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Set Default View and Projection
		NMatrix ViewMatrix = Camera.GetView();
		NMatrix ProjMatrix = Camera.GetProjection();

		Shader.Bind();
		for (GLuint i = 0; i < GameObjects.GetSize(); i++) {
			glBindVertexArray(InArrays[i]);

			if (GameObjects[i]->GetTexture())
				GameObjects[i]->GetTexture()->Bind();

			NMatrix Translate = NMatrix::Translation(NVector3(GameObjects[i]->GetPosition().X, GameObjects[i]->GetPosition().Y, 0.0f));
			NMatrix Rotate = NMatrix::Rotation(GameObjects[i]->GetRotation(), NVector3(0.0f, 0.0f, 1.0f));
			NMatrix Scale = NMatrix::Scale(NVector3(GameObjects[i]->GetSize().X, GameObjects[i]->GetSize().Y, 1.0f));
			NMatrix ModelMatrix = Translate * Rotate * Scale;

			glUniformMatrix4fv(Model, 1, GL_FALSE, ModelMatrix.Elements);
			glUniformMatrix4fv(View, 1, GL_FALSE, ViewMatrix.Elements);
			glUniformMatrix4fv(Projection, 1, GL_FALSE, ProjMatrix.Elements);

			glDrawArrays(GL_TRIANGLES, 0, GameObjects[i]->GetVertices().GetSize());

			if (GameObjects[i]->GetTexture())
				GameObjects[i]->GetTexture()->Unbind();

			glBindVertexArray(0);
		}
		Shader.Unbind();
	}

	void NRenderer::SetupShader(void) {
		Shader.Bind();
		Position = Shader.GetAttributeLocation("position");
		Color = Shader.GetAttributeLocation("color");
		TextureCoordinate = Shader.GetAttributeLocation("textureCoordinate");
		Model = Shader.GetUniformLocation("model");
		View = Shader.GetUniformLocation("view");
		Projection = Shader.GetUniformLocation("projection");
		Shader.Unbind();
	}
}