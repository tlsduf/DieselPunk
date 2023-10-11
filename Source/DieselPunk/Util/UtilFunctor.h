


#pragma once


// 랜덤 int 값을 반환
FORCEINLINE int GetRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (RAND_MAX + 1.0);  // static used for efficiency, so we only calculate this value once
	// evenly distribute the random number across our range
	return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
}

// 입력한 확률(0 ~ 1)로 bool 반환
FORCEINLINE bool CalPercentage(float inPercentage)
{
	bool success = (GetRandomNumber(0 , 100000) <= 100000 * inPercentage);
	
	return success;
}