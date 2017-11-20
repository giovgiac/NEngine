/**
 * Timer.cpp
 *
 * Copyright (c) Giovanni Giacomo. All Rights Reserved.
 *
 */

#include "Timer.h"

namespace Newton {
	NTimer::NTimer(void)
		: BaseTime(0), CurrentTime(0), DeltaTime(-1.0), PausedTime(0), PreviousTime(0), StopTime(0), Stopped(GL_FALSE)
	{
		GLulong CountsPerSec = CLOCKS_PER_SEC;

		// Calculate Period
		SecsPerCount = 1.0 / (GLdouble)CountsPerSec;
	}

	void NTimer::Reset(void) {
		// Get Current Time
		CurrentTime = clock();

		// Set Times
		BaseTime = CurrentTime;
		PreviousTime = CurrentTime;
		StopTime = 0;
		Stopped = GL_FALSE;
	}

	void NTimer::Start(void) {
		GLulong StartTime;

		// Get Current Time
		StartTime = clock();

		if (Stopped) {
			// Set Paused Time
			PausedTime += StartTime - StopTime;

			// Set Previous Time
			PreviousTime = StartTime;

			// Reset Stop Time and Stopped
			StopTime = 0;
			Stopped = GL_FALSE;
		}
	}

	void NTimer::Stop(void) {
		if (!Stopped) {
			// Get Current Time
			CurrentTime = clock();

			// Set Stop Time and Stopped
			StopTime = CurrentTime;
			Stopped = GL_TRUE;
		}
	}

	void NTimer::Tick(void) {
		if (Stopped) {
			DeltaTime = 0.0;
			return;
		}

		// Get Current Time
		CurrentTime = clock();

		// Compute Delta Time
		DeltaTime = (CurrentTime - PreviousTime) * SecsPerCount;

		// Set Previous Time
		PreviousTime = CurrentTime;

		// Ensure Non-Negative Delta Time
		if (DeltaTime < 0.0)
			DeltaTime = 0.0;
	}

	GLfloat NTimer::GetElapsedTime(void) const {
		if (Stopped)
			return (GLfloat)(((StopTime - PausedTime) - BaseTime) * SecsPerCount);
		else
			return (GLfloat)(((CurrentTime - PausedTime) - BaseTime) * SecsPerCount);
	}
}