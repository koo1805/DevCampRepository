#include <iostream>

// 삽입 정렬
void InsertionSort(int* array,
	const int length,
	int* count
)
{
	// 예외 처리
	if (length <= 1)
	{
		return;
	}

	// 배열을 순회
	// 두 번째 원소부터 순회 > 첫 번째 원소는 정렬됐다고 가정하고 시작
	for (int ix = 0; ix < length; ++ix)
	{
		// 비교 값 | 삽입할 값을 저장
		int keyValue = array[ix];

		// 선택한 값의 왼쪽 값 인덱스
		int jx = ix - 1;

		// 선택한 값에서 왼쪽으로 이동하면서 비교
		// keyValue보다 큰 값들을 오른쪽으로 이동
		while (jx >= 0 && array[jx] > keyValue)
		{
			// 오른쪽으로 밀기
			array[jx + 1] = array[jx];

			// 추가로 비교를 위해 인덱스를 왼쪽으로 이동
			--jx;

			++*count;
		}

		// 적절한 위치에 값 삽입
		array[jx + 1] = keyValue;

		++*count;
	}
}

// 배열 출력 함수.
void PrintArray(int* array, const int length, int count)
{
	for (int ix = 0; ix < length; ++ix)
	{
		std::cout << array[ix];

		// 마지막이 아니면 콤마 출력.
		if (ix < length - 1)
		{
			std::cout << ", ";
		}
	}

	std::cout << "\n횟수: " << count << "\n";
}

int main()
{
	// 자료 집합.
	int array[] = { 5, 2, 8, 4, 1, 7, 3, 6, 9, 10, 15, 13, 14, 12, 17, 16 };

	// 데이터 수
	const int length = _countof(array);

	// 횟수
	int count = 0;

	// 출력
	std::cout << "정렬 전 출력";
	PrintArray(array, length, count);

	InsertionSort(array, length, &count);

	std::cout << "정렬 후 출력";
	PrintArray(array, length, count);
}