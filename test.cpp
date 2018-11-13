#include <iostream>
#include <assert.h>
using namespace std;
//template <class T>      //模板函数
//T Add(T left, T right)
//{
//	return left + right;
//}
//int main()
//{
//	int a1 = 10, a2 = 2;
//	double a3 = 2.3;
//	auto ret=Add<int>(a1,a3);
//	return 0;
//}

template<class T>
//Vector不是一个具体的类，而是编译器根据被实例化的类型生成具体类的模具
class Vector
{
public:
	Vector(size_t capacity = 10)
		:_pData(new T[capacity])
		,_size(0)
		, _capacity(capacity)
	{}
	~Vector();
	void Pushback(const T& data)
	{
		_pData[_size++] = data;
	}
	int Size()
	{
		return _size;
	}
	T& operator[](size_t i)
	{
		assert(i < _size);
		return _pData[i];
	}
	void Print();
private:
	T* _pData;
	size_t _size;
	size_t _capacity;
};

template <class T>               //在类外定义时，要加模板参数列表
Vector<T>::~Vector()
{
	if (_pData){
		delete _pData;
	}
}
template <class T>
void Vector<T>::Print()
{
	int i = _size;
	while (--i >= 0){
		cout << _pData[i] << endl;
	}
}
int main()
{
	Vector<int> s1;     
	s1.Pushback(1);
	s1.Pushback(6);
	s1.Pushback(8);
	s1.Pushback(9);
	//s1.Print();
	int i = s1.Size();
	while (--i >= 0){
		cout << s1[i] << endl;
	}
	Vector<double> s2;
	s2.Pushback(2);
	s2.Pushback(4);
	s2.Pushback(2);
	s2.Pushback(8);
	s2.Print();
	return 0;
}