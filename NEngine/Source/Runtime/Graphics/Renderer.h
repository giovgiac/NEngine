/**
 * Renderer.h
 *
 * Copyright (c) Giovanni Giacomo. All Rights Reserved.
 *
 */

#pragma once

#include <Collections/Array.h>
#include <Graphics/Scene.h>
#include <Graphics/Shader.h>

namespace Newton {
	/**
	 * NRenderer Class
	 *
	 * This class is responsible for rendering game scenes.
	 *
	 */
	class NRenderer {
	private:
		NShader Shader;
		GLuint Color;
		GLuint Model;
		GLuint Position;
		GLuint Projection;
		GLuint TextureCoordinate;
		GLuint View;

	public:
		/**
		 * NRenderer Constructor
		 *
		 * This default constructor initializes the renderer with the default shader.
		 *
		 */
		inline NRenderer(void);

		/**
		 * NRenderer Constructor
		 *
		 * This constructor initializes the renderer with the given shader.
		 *
		 * @param const NShader& InShader: The shader to use in the renderer.
		 *
		 */
		explicit inline NRenderer(const NShader& InShader);

		/**
		 * NRenderer Render
		 *
		 * This method renders (draws) a scene in the game, given the scene and it's vertex arrays.
		 *
		 * @param const NScene& InScene: The scene to render.
		 * @param const NArray<GLuint>& Arrays: The vertex arrays of the objects.
		 *
		 */
		inline void Render(const NScene& InScene, const NArray<GLuint>& InArrays) const;

		/**
		 * NRenderer GetColorID
		 *
		 * This method gets the ID of the color parameter from the shaders.
		 *
		 * @return const GLuint: The ID of the color parameter in the shader.
		 *
		 */
		inline const GLuint GetColorID(void) const;

		/**
		 * NRenderer GetModelID
		 *
		 * This method gets the ID of the model parameter from the shaders.
		 *
		 * @return const GLuint: The ID of the model parameter in the shader.
		 *
		 */
		inline const GLuint GetModelID(void) const;

		/**
		 * NRenderer GetPositionID
		 *
		 * This method gets the ID of the position parameter from the shaders.
		 *
		 * @return const GLuint: The ID of the position parameter in the shader.
		 *
		 */
		inline const GLuint GetPositionID(void) const;

		/**
		 * NRenderer GetProjectionID
		 *
		 * This method gets the ID of the projection parameter from the shaders.
		 *
		 * @return const GLuint: The ID of the projection parameter in the shader.
		 *
		 */
		inline const GLuint GetProjectionID(void) const;

		/**
		 * NRenderer GetTextureCoordinateID
		 *
		 * This method gets the ID of the texture coordinate parameter from the shaders.
		 *
		 * @return const GLuint: The ID of the texture coordinate parameter in the shader.
		 *
		 */
		inline const GLuint GetTextureCoordinateID(void) const;

		/**
		 * NRenderer GetViewID
		 *
		 * This method gets the ID of the view parameter from the shaders.
		 *
		 * @return const GLuint: The ID of the view parameter in the shader.
		 *
		 */
		inline const GLuint GetViewID(void) const;

	private:
		/**
		 * NRenderer SetupShader
		 *
		 * This method setups the shader by getting all the IDs from the currently set shader.
		 *
		 */
		inline void SetupShader(void);
	};
}