#include <iostream>

// 두 수를 서로 교환하는 함수.
template<typename T>
void Swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

// 클래스 템플릿.
template<typename T, int size>
class Data
{
public:
	Data(const T& newData)
		: data(newData)
	{
	}

	T GetData() const { return data; }
	void SetData(const T& newData) { data = newData; }
	int GetSize() const { return size; }

private:
	T data = {};
};

int main()
{
	int a = 10;
	int b = 30;
	Swap<int>(a, b);

	Data<int, 100> intData(30);
	std::cout << intData.GetData() << "\n";
	std::cout 
		<< "Size: " << intData.GetSize() 
		<< ", Data: " << intData.GetData() 
		<< "\n";

	Data<float, 5> pi(3.141592f);
	std::cout << pi.GetData() << "\n";
	std::cout << pi.GetSize() << "\n";

	std::cin.get();
}