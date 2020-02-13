#pragma once

namespace rs
{
	template <class T>
	class Array
	{
	private:
		int size;
		T* data;
	public:
		Array(int);
		~Array();
	};
}
