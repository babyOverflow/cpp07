#include <exception>
#include <stdexcept>
template<class T>
class Array
{
public:
	Array()
		: arr(new T[0]), mReserved(0), mSize(0)
	{
	}

	Array(unsigned int v)
		: arr(new T[v]), mReserved(v), mSize(v)
	{
	}

	Array(const Array<T>& other)
		: arr(new T[other.mReserved]), mReserved(other.mReserved), mSize(other.mSize)
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
		mSize = other.mSize;
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

	// T operator[](unsigned int idx) const
	// {
	// 	if (idx >= mReserved)
	// 		throw std::exception();
	// 	else
	// 		return arr[idx];
	// }
private:
	T* arr;
	unsigned int mReserved;
	unsigned int mSize;
};