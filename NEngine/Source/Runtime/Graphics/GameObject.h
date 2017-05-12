/**
 * GameObject.h
 *
 * Copyright (c) Giovanni Giacomo. All Rights Reserved.
 *
 */

#pragma once

#include <Collections/Array.h>
#include <Graphics/Texture.h>
#include <Graphics/Vertex.h>
#include <Math/Vector.h>

namespace Newton {
	/**
	 * NGameObject Class
	 *
	 * This class is for creating game objects that can be placed in the 2D world.
	 *
	 */
	class NGameObject {
	private:
		NArray<Vertex> Vertices;

	protected:
		NColor Color;
		NVector Position;
		GLfloat Rotation;
		NVector Size;
		NTexture* Texture;

	public:
		/**
		 * NGameObject Constructor
		 *
		 * This default constructor creates an empty game object.
		 *
		 */
		inline NGameObject(void);

		/**
		 * NGameObject Constructor
		 *
		 * This constructor creates a new game object with the given position, rotation, size, color and texture.
		 *
		 * @param const NVector& InPosition: The position of the object.
		 * @param const GLfloat InRotation: The rotation of the object.
		 * @param const NVector& InSize: The size of the object.
		 * @param const NColor& InColor: The color of the object (multiplies the texture).
		 * @param NTexture* InTexture: The texture of the object.
		 *
		 */
		explicit inline NGameObject(const NVector& InPosition, const GLfloat InRotation, const NVector& InSize, const NColor& InColor, NTexture* InTexture = nullptr);

		/**
		 * NGameObject Start
		 *
		 * This method is called once when the game starts.
		 *
		 */
		inline virtual void Start(void) = 0;

		/**
		 * NGameObject Tick
		 *
		 * This method is called every frame.
		 *
		 */
		inline virtual void Tick(void) = 0;

		/**
		 * NGameObject Translate
		 *
		 * This method translates the object by a given amount.
		 *
		 * @param const NVector& InTranslation: The amount to translate the object by.
		 *
		 */
		inline void Translate(const NVector& InTranslation);

		/**
		 * NGameObject Rotate
		 *
		 * This method rotates the object by a given angle.
		 *
		 * @param const GLfloat InRotation: The angle, in degrees, to rotate the object by.
		 *
		 */
		inline void Rotate(const GLfloat InRotation);

		/**
		 * NGameObject Scale
		 *
		 * This method scales the object by a given amount.
		 *
		 * @param const NVector& InSize: The amount to scale the object by.
		 *
		 */
		inline void Scale(const NVector& InSize);

		/**
		 * NGameObject GetTexture
		 *
		 * This method gets the texture of a particular game object.
		 *
		 * @return const NTexture*: A pointer to the texture of the object.
		 *
		 */
		inline const NTexture* GetTexture(void) const;

		/**
		 * NGameObject GetVertices
		 *
		 * This method gets the vertices of a particular game object.
		 *
		 * @return const NArray<Vertex>&: A reference to the array of vertices of the object.
		 *
		 */
		inline const NArray<Vertex>& GetVertices(void) const;

	private:
		/**
		 * NGameObject AddStockVertices
		 *
		 * This method adds the stock vertices that form a square to the game object.
		 *
		 * @param const NColor& InColor: The color of the vertices.
		 *
		 */
		inline void AddStockVertices(const NColor& InColor);
	};
}