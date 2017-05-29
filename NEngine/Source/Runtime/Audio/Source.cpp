/** 
 * Source.cpp
 *
 * Copyright (c) Giovanni Giacomo. All Rights Reserved.
 *
 */

#include "Source.h"

// Default FMOD system pointer to nullptr
FMOD_SYSTEM* FMODSystem = nullptr;

namespace Newton {
	NAudioSource::NAudioSource(void)
		: Sound(nullptr), Length(0) {}

	NAudioSource::~NAudioSource(void) {
		// Delete Event Handlers
		if (OnFinish)
			delete OnFinish;

		if (Sound)
			FMOD_Sound_Release(Sound);
	}

	NAudioSource::NAudioSource(const GLchar* InFilename, bool InLoop) {
		if (InLoop) {
			FMOD_System_CreateSound(FMODSystem, InFilename, FMOD_LOOP_NORMAL, nullptr, &Sound);
			FMOD_Sound_SetLoopCount(Sound, -1);
		} else {
			FMOD_System_CreateSound(FMODSystem, InFilename, FMOD_LOOP_OFF, nullptr, &Sound);
			FMOD_Sound_SetLoopCount(Sound, 0);
		}

		FMOD_Sound_GetLength(Sound, &Length, FMOD_TIMEUNIT_MS);
	}

	void NAudioSource::Play(void) {
		if (Sound) {
			FMOD_System_PlaySound(FMODSystem, Sound, nullptr, false, &Channel);
			FMOD_Channel_SetCallback(Channel, NAudioSource::Finish);
			FMOD_Channel_SetUserData(Channel, this);
		}
	}

	GLuint NAudioSource::GetLength(void) const {
		return Length;
	}

	FMOD_RESULT F_CALLBACK NAudioSource::Finish(FMOD_CHANNELCONTROL* InChannelControl, FMOD_CHANNELCONTROL_TYPE InControlType, FMOD_CHANNELCONTROL_CALLBACK_TYPE InCallbackType, void* InData1, void* InData2)
	{
		if (InControlType == FMOD_CHANNELCONTROL_CHANNEL && InCallbackType == FMOD_CHANNELCONTROL_CALLBACK_END) {
			NAudioSource* Audio;
			FMOD_CHANNEL* Channel;
			FMOD_SOUND* Sound;
			
			// Retrieve Sound from Channel
			Channel = (FMOD_CHANNEL*)InChannelControl;
			FMOD_Channel_GetCurrentSound(Channel, &Sound);

			// Get NAudioSource Instance
			FMOD_Channel_GetUserData(Channel, (void**)&Audio);

			// Call OnFinish Event
			if (Audio) {
				if (Audio->OnFinish)
					Audio->OnFinish->Call(Audio);
				delete Audio;
			}

			// Release Sound from Memory
			FMOD_Sound_Release(Sound);
		}

		return FMOD_OK;
	}
}