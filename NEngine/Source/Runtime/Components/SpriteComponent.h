/**
 * SpriteComponent.h
 *
 * Copyright (c) Giovanni Giacomo. All Rights Reserved.
 *
 */

#pragma once

#include <Components/PrimitiveComponent.h>

namespace Newton
{
	class NSpriteComponent : public NPrimitiveComponent
	{
	protected:
		class NTexture* Sprite;

	private:
		virtual void ConstructObject(void);

	public:
		void SetSprite(class NTexture* InSprite);

		class NTexture* GetSprite(void) const;
	};
}