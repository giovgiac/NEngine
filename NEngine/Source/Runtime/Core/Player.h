/**
 * Player.h
 *
 * Copyright (c) Giovanni Giacomo. All Rights Reserved.
 *
 */

#pragma once

#include <Graphics/GameObject.h>
#include <Graphics/Window.h>

namespace Newton {
	/**
	 * NPlayer Class
	 *
	 * This class is responsible for creating the players and handling their inputs.
	 *
	 */
	class NPlayer abstract : public NGameObject {
	public:
		/**
		 * NPlayer Constructor
		 *
		 * This default constructor initializes the player with the default configurations.
		 *
		 */
		NPlayer(void);

		/**
		 * NPlayer Constructor
		 *
		 * This constructor initializes the player with the given values.
		 *
		 * @param const NVector& InPosition: The position of the player.
		 * @param const GLfloat InRotation: The rotation of the player.
		 * @param const NVector& InSize: The size of the player.
		 * @param const NColor& InColor: The color of the player.
		 * @param NTexture* InTexture: The texture of the player.
		 *
		 */
		explicit NPlayer(const NVector& InPosition, const GLfloat InRotation, const NVector& InSize, const NColor& InColor, NTexture* InTexture = nullptr);

		/**
		 * NPlayer OnKeyDown
		 *
		 * This method is called whenever a key is clicked by the player.
		 *
		 * @param GLint InKey: The key that is down.
		 * @param GLint InScancode: The scancode of the key.
		 * @param GLint InAction: The action of the event.
		 * @param GLint InMods: The modifier keys that were involved.
		 *
		 */
		virtual void OnKeyDown(GLint InKey, GLint InScancode, GLint InAction, GLint InMods) = 0;

		/**
		 * NPlayer OnMouseDown
		 *
		 * This method is called whenever a mouse button is clicked by the player.
		 *
		 * @param GLint InButton: The mouse button that is down.
		 * @param GLint InAction: The action of the event.
		 * @param GLint InMods: The modifier keys that were involved.
		 *
		 */
		virtual void OnMouseDown(GLint InButton, GLint InAction, GLint InMods) = 0;

		/**
		 * NPlayer OnMouseMove
		 *
		 * This method is called whenever the mouse moves.
		 *
		 * @param GLdouble InX: The X coordinate of the mouse.
		 * @param GLdouble InY: The Y coordinate of the mouse.
		 *
		 */
		virtual void OnMouseMove(GLdouble InX, GLdouble InY) = 0;
	};
}