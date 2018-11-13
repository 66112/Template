#include <iostream>
#include <assert.h>
using namespace std;
//template <class T>      //ģ�庯��
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
//Vector����һ��������࣬���Ǳ��������ݱ�ʵ�������������ɾ������ģ��
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

template <class T>               //�����ⶨ��ʱ��Ҫ��ģ������б�
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