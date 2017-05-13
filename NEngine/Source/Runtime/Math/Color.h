/**
 * Color.h
 *
 * Copyright (c) Giovanni Giacomo. All Rights Reserved.
 *
 */

#pragma once

#include <glew.h>

namespace Newton {
	/**
	 * NColor Struct
	 *
	 * This data type is intended for hold RGBA colors. It uses OpenGL floating-point numbers to represent the channels.
	 *
	 */
	struct NColor {
		GLfloat Red;
		GLfloat Green;
		GLfloat Blue;
		GLfloat Alpha;

		/**
		 * NColor Constructor
		 *
		 * This default constructor initializes the color to the white color.
		 *
		 */
		inline NColor(void)
			: Red(1.0f), Green(1.0f), Blue(1.0f), Alpha(1.0f) {}

		/**
		 * NColor Constructor
		 *
		 * This constructor initializes a color given the individual values of the channels.
		 *
		 * @param GLfloat InRed: The value of the Red channel.
		 * @param GLfloat InGreen: The value of the Green channel.
		 * @param GLfloat InBlue: The value of the Blue channel.
		 * @param GLfloat InAlpha: The value of the Alpha channel.
		 *
		 */
		explicit inline NColor(GLfloat InRed, GLfloat InGreen, GLfloat InBlue, GLfloat InAlpha)
			: Red(InRed), Green(InGreen), Blue(InBlue), Alpha(InAlpha) {}

		/**
		 * NColor Black
		 *
		 * This static method returns the black color.
		 *
		 */
		static inline NColor Black() { return NColor(0.0f, 0.0f, 0.0f, 0.0f); }

		/** 
		 * NColor White
		 *
		 * This static method returns the white color.
		 *
		 */
		static inline NColor White() { return NColor(1.0f, 1.0f, 1.0f, 1.0f); }
	};
}
