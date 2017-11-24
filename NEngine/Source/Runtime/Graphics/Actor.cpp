/**
 * Actor.cpp
 *
 * Copyright (c) Giovanni Giacomo. All Rights Reserved.
 *
 */

#include "Actor.h"

#include <Graphics/World.h>

namespace Newton
{
	void NActor::ConstructObject(void)
	{
		// Test
		GetWorld()->SpawnActor<NActor>(Transform);
	}
}