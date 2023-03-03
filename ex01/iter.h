template <class T, class U>
void iter(T* arr, int length, U (*f)(T))
{
	for (int i = 0; i < length; ++i)
	{
		f(arr[i]);
	}
}