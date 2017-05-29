/**
 * Event.h
 *
 * Copyright (c) Giovanni Giacomo. All Rights Reserved.
 *
 */

#pragma once

namespace Newton {
	/**
	 * NEventHandler Class
	 *
	 * This class is responsible for creating delegate-style event handlers.
	 *
	 */
	template<typename... ParamType>
	class NEventHandler {
	private:
		/**
		 * NEventFather Class
		 *
		 * This helper class provides a general method without needing ClassType and ReturnType.
		 *
		 */
		template<typename... ParamType>
		class NEventFather {
		public:
			virtual void CallFunction(ParamType... InArgs) = 0;
		};

		/**
		 * NEvent Class
		 *
		 * This class stores the object and function to call.
		 *
		 */
		template<typename ClassType, typename ReturnType, typename... ParamType>
		class NEvent : public NEventFather<ParamType...> {
		public:
			ClassType* Object;
			ReturnType(ClassType::*Function)(ParamType...);

			inline virtual void CallFunction(ParamType... InArgs) override {
				(Object->*Function)(InArgs...);
			}
		};

	private:
		NEventFather<ParamType...>* Event;
		
	public:
		/**
		 * NEventHandler Constructor
		 *
		 * This constructor creates an event handler by receiving and object and a function to call on it.
		 *
		 */
		template<typename ClassType, typename ReturnType>
		inline explicit NEventHandler(ClassType* InObject, ReturnType(ClassType::*InFunction)(ParamType...)) {
			NEvent<ClassType, ReturnType, ParamType...>* EventTmp = new NEvent<ClassType, ReturnType, ParamType...>();

			// Set Stuff
			EventTmp->Object = InObject;
			EventTmp->Function = InFunction;

			// Set Event
			Event = EventTmp;
		}

		/**
		 * NEventHandler Destructor
		 *
		 * This destructor cleans up the memory used up by the event.
		 *
		 */
		inline ~NEventHandler(void) {
			if (Event)
				delete Event;
		}

		/**
		 * NEventHandler Call
		 *
		 * This method calls the function that is stored in the event handler.
		 *
		 */
		inline void Call(ParamType... InArgs) {
			Event->CallFunction(InArgs...);
		}
	};
}