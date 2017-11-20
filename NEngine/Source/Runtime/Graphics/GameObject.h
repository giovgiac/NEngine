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
		NArray<NVertex> Vertices;

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
		NGameObject(void);

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
		explicit NGameObject(const NVector& InPosition, const GLfloat InRotation, const NVector& InSize, const NColor& InColor, NTexture* InTexture = nullptr);

		/**
		 * NGameObject Start
		 *
		 * This method is called once when the game starts.
		 *
		 */
		virtual void Start(void);

		/**
		 * NGameObject Tick
		 *
		 * This method is called every frame.
		 *
		 * @param GLfloat DeltaTime: The difference, in seconds, between frames.
		 *
		 */
		virtual void Tick(GLfloat DeltaTime);

		/**
		 * NGameObject Translate
		 *
		 * This method translates the object by a given amount.
		 *
		 * @param const NVector& InTranslation: The amount to translate the object by.
		 *
		 */
		void Translate(const NVector& InTranslation);

		/**
		 * NGameObject Rotate
		 *
		 * This method rotates the object by a given angle.
		 *
		 * @param const GLfloat InRotation: The angle, in degrees, to rotate the object by.
		 *
		 */
		void Rotate(const GLfloat InRotation);

		/**
		 * NGameObject Scale
		 *
		 * This method scales the object by a given amount.
		 *
		 * @param const NVector& InSize: The amount to scale the object by.
		 *
		 */
		void Scale(const NVector& InSize);

		/** 
		 * NGameObject GetPosition
		 *
		 * This method gets the position of the game object.
		 *
		 * @return const NVector&: The position of the object.
		 *
		 */
		inline const NVector& GetPosition(void) const { return Position; }

		/**
		 * NGameObject GetRotation
		 *
		 * This method gets the rotation of the game object.
		 *
		 * @return const GLfloat: The rotation of the object.
		 *
		 */
		inline const GLfloat GetRotation(void) const { return Rotation; }

		/**
		 * NGameObject GetSize
		 *
		 * This method gets the size of the game object.
		 *
		 * @return const NVector&: The size of the object.
		 *
		 */
		inline const NVector& GetSize(void) const { return Size; }

		/**
		 * NGameObject GetTexture
		 *
		 * This method gets the texture of a particular game object.
		 *
		 * @return const NTexture*: A pointer to the texture of the object.
		 *
		 */
		inline NTexture* GetTexture(void) const { return Texture; }

		/**
		 * NGameObject GetVertices
		 *
		 * This method gets the vertices of a particular game object.
		 *
		 * @return const NArray<NVertex>&: A reference to the array of vertices of the object.
		 *
		 */
		inline const NArray<NVertex>& GetVertices(void) const { return Vertices; }

	private:
		/**
		 * NGameObject AddStockVertices
		 *
		 * This method adds the stock vertices that form a square to the game object.
		 *
		 * @param const NColor& InColor: The color of the vertices.
		 *
		 */
		void AddStockVertices(const NColor& InColor);
	};
}