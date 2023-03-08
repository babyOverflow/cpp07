#include <exception>
#include <stdexcept>
template<class T>
class Array
{
public:
	Array()
		: arr(new T[0]), mReserved(0)
	{
	}

	Array(unsigned int v)
		: arr(new T[v]), mReserved(v)
	{
	}

	Array(const Array<T>& other)
		: arr(new T[other.mReserved]), mReserved(other.mReserved)
	{
		for (unsigned int i = 0; i < mReserved; ++i)
		{
			arr[i] = other.arr[i];
		}
	}

	Array<T>& operator=(const Array<T>& other)
	{
		delete [] arr;
		arr = new T[other.mReserved];
		mReserved = other.mReserved;
		for (unsigned int i = 0; i < mReserved; ++i)
		{
			arr[i] = other.arr[i];
		}
	}

	~Array()
	{
		delete [] arr;
	}

	T& operator[](unsigned int idx)
	{
		if (idx >= mReserved)
			throw std::out_of_range("Array: out of range");
		else
			return arr[idx];
	}

	unsigned int size()
	{
		return mReserved;
	}
private:
	T* arr;
	unsigned int mReserved;
};