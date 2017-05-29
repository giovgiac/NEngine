/**
 * Source.h
 *
 * Copyright (c) Giovanni Giacomo. All Rights Reserved.
 *
 */

#pragma once

#include <Core/Event.h>

#include <fmod.h>
#include <glew.h>

namespace Newton {
	/**
	 * NAudioSource Class
	 *
	 * This class is responsible for creating and playing audio files.
	 *
	 */
	class NAudioSource {
	private:
		FMOD_CHANNEL* Channel;
		FMOD_SOUND* Sound;
		GLuint Length;

	public:
		NEventHandler<NAudioSource*>* OnFinish;
		
	public:
		/**
		 * NAudioSource Constructor
		 *
		 * This default constructor creates an empty audio source.
		 *
		 */
		NAudioSource(void);

		/**
		 * NAudioSource Constructor
		 *
		 * This constructor creates an audio source based on a file and whether the sound should loop or not.
		 *
		 * @param const GLchar* InFilename: The audio file to load.
		 * @param bool InLoop: Whether to loop the audio.
		 *
		 */
		explicit NAudioSource(const GLchar* InFilename, bool InLoop);

		/**
		 * NAudioSource Destructor
		 *
		 * This destructor cleans up the memory used by the audio source.
		 *
		 */
		~NAudioSource(void);

		/**
		 * NAudioSource Play
		 *
		 * This method starts playing the audio source.
		 *
		 */
		void Play(void);

		/** 
		 * NAudioSource GetLength
		 *
		 * This method gets the length of the audio source file.
		 *
		 * @return GLuint: The length of the audio source file.
		 *
		 */
		GLuint GetLength(void) const;

		/**
		 * NAudioSource Finish
		 *
		 * This static method is a callback and is called by FMOD everytime an audio source stops playing (for cleaning up purposes).
		 *
		 */
		static FMOD_RESULT F_CALLBACK Finish(FMOD_CHANNELCONTROL* InChannelControl, FMOD_CHANNELCONTROL_TYPE InControlType, FMOD_CHANNELCONTROL_CALLBACK_TYPE InCallbackType, void* InData1, void* InData2);
	};
}

// Externs the pointer to the FMOD system
extern FMOD_SYSTEM* FMODSystem;