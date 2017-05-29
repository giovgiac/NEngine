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
	class NPlayer : public NGameObject {
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
	};
}