#include "Dynamic.h"

Dynamic::Dynamic(std::string _Type)
{
	type = _Type;
}

Dynamic::~Dynamic()
{
}

float Dynamic::lerp(float a, float b, float t)
{
	return a + t * (b - a);
}
