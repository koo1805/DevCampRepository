#include <iostream>
#include <ctime>
#include <cstdlib>
#include <Windows.h>


#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

// 스탯 타이머 예시.
class StatTimer
{
public:
	StatTimer(const std::string& tag)
		: tag(tag)
	{
	}

	void CheckStartStat()
	{
		LARGE_INTEGER counter;
		QueryPerformanceCounter(&counter);
		start = counter.QuadPart;
	}

	void CheckEndStat()
	{
		LARGE_INTEGER counter;
		QueryPerformanceCounter(&counter);
		end = counter.QuadPart;
	}

	void Reset()
	{
		start = end = 0;
	}

	void PrintResult()
	{
		std::cout << "[" << tag << "] elapsed: " << GetElapsed() << "\n";
	}

private:
	float GetElapsed()
	{
		LARGE_INTEGER frequency;
		QueryPerformanceFrequency(&frequency);
		return static_cast<float>(end - start)
			/ static_cast<float>(frequency.QuadPart);
	}

private:
	std::string tag;
	int64_t start = 0;
	int64_t end = 0;
};

// 비교로직 전달을 위한 함수 포인터
typedef bool (*Comparer)(int, int);

bool LessEqual(int a, int b) { return a <= b; }
bool GreaterEqual(int a, int b) { return a >= b; }


// 분할된 배열을 병합하면서 정렬하는 함수
void Merge(
	int* array,
	int* leftArray, int leftArrayLength,
	int* rightArray, int rightArrayLength,
	Comparer comparer)
{
	// 병합처리를 위한 인덱스
	int leftIndex = 0;
	int rightIndex = 0;
	int mergedIndex = 0;

	// 오름차순 정렬로 구현
	// 두 배열 각각의 현재 인덱스의 값을 비교해 작은 값을 array에 저장
	while (leftIndex < leftArrayLength && rightIndex < rightArrayLength)
	{
		// 왼쪽 인덱스 기준으로 처리 - 왼쪽 배열의 값이 더 작은 경우
		//if (leftArray[leftIndex] <= rightArray[rightIndex])
		if (comparer(leftArray[leftIndex], rightArray[rightIndex]))
		{
			array[mergedIndex] = leftArray[leftIndex];
			++leftIndex;
		}
		// 오른쪽 배열의 값이 더 작은 경우
		else
		{
			array[mergedIndex] = rightArray[rightIndex];
			++rightIndex;
		}

		// 병합된 배열의 인덱스 증가 처리
		++mergedIndex;
	}

	// 왼쪽 배열에서 남은 원소를 복사
	while (leftIndex < leftArrayLength)
	{
		array[mergedIndex] = leftArray[leftIndex];
		++leftIndex;
		++mergedIndex;
	}
	
	// 오른쪽 배열에서 남은 원소를 복사
	while (rightIndex < rightArrayLength)
	{
		array[mergedIndex] = leftArray[rightIndex];
		++rightIndex;
		++mergedIndex;
	}
}

// 병합 정렬 함수
void MergeSort(int* array, int length, Comparer comparer = LessEqual)
{
	// 종료 조건
	if (length <= 1)
	{
		return;
	}

	// 반으로 나누면서 분할 진행
	// 중간 인덱스
	int middle = length / 2;

	// 왼쪽으로 나눌 배열 크기
	int leftArrayLength = middle;

	// 오른쪽으로 나눌 배열 크기 (전체 크기에서 왼쪽 배열 크기를 뺌)
	int rightArrayLength = length - middle;

	// 분할된 배열 선언(동적 할당)
	int* leftArray = new int[leftArrayLength] {};
	int* rightArray = new int[rightArrayLength] {};

	// 분할된 왼쪽 배열에 값 복사
	//for (int ix = 0; ix < length; ++ix)
	//{
	//	leftArray[ix] = array[ix];
	//}

	// 분할된 왼쪽 배열에 값 복사
	memcpy(leftArray, array, sizeof(int) * leftArrayLength);

	// 분할된 오른쪽 배열에 값 복사
	memcpy(rightArray, array + middle, sizeof(int) * rightArrayLength);

	// 병합을 이어서 진행 (재귀)
	MergeSort(leftArray, leftArrayLength, comparer);
	MergeSort(rightArray, rightArrayLength, comparer);

	// 분할이 재귀적으로 모두 끝나면 병합을 진행
	Merge(array, leftArray, leftArrayLength, rightArray, rightArrayLength, comparer);

	// 사용한 배열 해제
	delete[] leftArray;
	leftArray = nullptr;

	delete[] rightArray;
	rightArray = nullptr;

}

// 랜덤에 시드 값 적용하는 함수
void SRand()
{
	srand(static_cast<uint32_t>(time(nullptr)));
}

int RandomRange(int min, int max)
{
	// 범위 구하기
	int diff = (max - min) + 1;
	return ((diff * rand()) / (RAND_MAX + 1)) + min;
}

int main()
{
	// 배열
	const int length = 10000;

	// 정렬할 배열 선언
	int* orignal = new int[length] {};

	// 랜덤을 활용해서 배열에 값 저장
	for (int ix = 0; ix < length; ++ix)
	{
		orignal[ix] = RandomRange(1, length);
	}

	// 정렬에 사용할 배열
	int* array = new int[length] {};

	// 메모리 통복사
	memcpy(array, orignal, sizeof(int) * length);

	// 출력
	auto PrintArray =
		[](int* array, int length)
		{
			for (int ix = 0; ix < length; ++ix)
			{
				std::cout << array[ix];

				if (ix < length - 1)
				{
					std::cout << ", ";
				}
			}

			std::cout << "\n\n";
		};

	//// 배열 원소 출력
	//std::cout << "정렬 전: ";
	//PrintArray(array, length);

	// 경과 시간
	StatTimer mergeSortTimer("MergSort");

	// 시작 시간 기록
	mergeSortTimer.CheckStartStat();

	// 정렬
	MergeSort(array, length, GreaterEqual);

	// 종료 시간 기록
	mergeSortTimer.CheckEndStat();

	// 기록 출력
	mergeSortTimer.PrintResult();

	// 배열 원소 출력
	//std::cout << "정렬 후: ";
	//PrintArray(array, length);

	delete[] orignal;
	orignal = nullptr;
	
	delete[] array;
	array = nullptr;
}