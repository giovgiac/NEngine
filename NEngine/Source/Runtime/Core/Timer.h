/**
 * Timer.h
 *
 * Copyright (c) Giovanni Giacomo. All Rights Reserved.
 *
 */

#pragma once

#include <glew.h>
#include <time.h>

namespace Newton {
	/**
	 * NTimer Class
	 *
	 * This class is responsible for keeping time in any operating system that supports
	 * the C standard library.
	 *
	 */
	class NTimer {
	private:
		GLdouble SecsPerCount;
		GLdouble DeltaTime;
		GLulong BaseTime;
		GLulong CurrentTime;
		GLulong PausedTime;
		GLulong PreviousTime;
		GLulong StopTime;
		GLboolean Stopped;

	public:
		/**
		 * NTimer Constructor
		 *
		 * This constructor initializes the times to their default values
		 * and calculates the period and frequency of the timer.
		 *
		 */
		NTimer(void);

		/**
		 * NTimer Reset
		 *
		 * This method resets the timer, resetting it's baseTime to curTime.
		 *
		 */
		void Reset(void);

		/**
		 * NTimer Start
		 *
		 * This method starts the timer, if it was previously stopped, counting
		 * time normally, instead of to pausedTime.
		 *
		 */
		void Start(void);

		/**
		 * NTimer Stop
		 *
		 * This method stops the timer, adding future time differences to the 
		 * pausedTime.
		 *
		 */
		void Stop(void);

		/**
		 * NTimer Tick
		 *
		 * This method is supposed to be called every frame and is responsible
		 * for calculating the deltaTime between frames.
		 *
		 */
		void Tick(void);

		/**
		 * NTimer GetElapsedTime
		 *
		 * This method calculates the total elapsed time, since the start of the
		 * application or the last timer reset.
		 *
		 * @return GLfloat: A float with the total time elapsed in seconds.
		 *
		 */
		GLfloat GetElapsedTime(void) const;

		/**
		 * NTimer GetDeltaTime
		 *
		 * This method is a getter for the deltaTime between the current and 
		 * previous frames.
		 *
		 * @return GLfloat: A float with the delta time in seconds.
		 *
		 */
		inline GLfloat GetDeltaTime(void) const { return (GLfloat)DeltaTime; }
	};
}