/**
 * Object.h
 * 
 * Copyright (c) Giovanni Giacomo. All Rights Reserved.
 *
 */

#pragma once

#include <Core/Types.h>

namespace Newton
{
	class NObject
	{
	private:
		utf8* Name;

	private:
		virtual void ConstructObject(void) = 0;

	protected:
		template<typename T>
		T* Cast(NObject* InObject)
		{
			return dynamic_cast<T*>(InObject);
		}

		template<typename T>
		T* CreateDefaultSubobject(const utf8* InName)
		{
			T* Result = new T();

			NObject* Object = Cast<NObject>(Result);
			Object->ConstructObject();

			return Result;
		}
	};
}