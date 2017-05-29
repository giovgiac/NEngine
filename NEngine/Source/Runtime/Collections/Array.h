/**
 * Array.h
 *
 * Copyright (c) Giovanni Giacomo. All Rights Reserved.
 *
 */

#pragma once

#include <glew.h>
#include <memory.h>

namespace Newton {
	/**
	 * NArray Class
	 *
	 * This class is for creating dynamic arrays of any class. It keeps an array and a size that can change.
	 *
	 */
	template<typename ElementType>
	class NArray {
	private:
		ElementType* Data;
		GLuint Size;

	public:
		/**
		 * NArray Constructor
		 *
		 * This default constructor creates an empty array of size zero.
		 *
		 */
		inline NArray(void)
			: Data(nullptr), Size(0) {}

		/**
		 * NArray Constructor
		 *
		 * This constructor creates an array with the given number of elements. They can be immediately accessed through index.
		 *
		 * @param GLuint InSize: The size to make the array.
		 *
		 */
		explicit inline NArray(GLuint InSize)
			: Size(InSize) 
		{
			Data = (InSize > 0) ? new ElementType[InSize] : nullptr;
		}

		/**
		 * NArray Append
		 *
		 * This method adds an element to the end of the array. It accomplishes that by recreating the array with an additional element.
		 *
		 * @param const ElementType& InEntry: The element to add to the end of the array.
		 *
		 */
		inline void Append(const ElementType& InEntry) {
			ElementType* NewData = new ElementType[Size + 1];

			memcpy(NewData, Data, Size * sizeof(ElementType));
			NewData[Size] = InEntry;
			Size++;
			delete[] Data;
			Data = NewData;
		}
		
		/**
		 * NArray GetData
		 *
		 * This method returns a pointer to the array in memory being kept by the class.
		 *
		 * @return ElementType*: A pointer to the array in memory.
		 *
		 */
		inline ElementType* GetData() const { return Data; }

		/**
		 * NArray GetSize
		 *
		 * This method returns the current size of the array.
		 *
		 * @return GLuint: The value of the current size of the array.
		 *
		 */
		inline GLuint GetSize() const { return Size; }

		inline ElementType& operator[](GLuint InIndex) const { return Data[InIndex]; }
	};
}