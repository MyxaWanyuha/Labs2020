#pragma once
inline int max(const int a, const int b)
{
	return (a > b) * a + (b > a) * b;
}

inline int min(const int a, const int b)
{
	return (a < b) * a + (b < a) * b;
}