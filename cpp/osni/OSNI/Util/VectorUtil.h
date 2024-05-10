#ifndef __CLC_VECTOR_UTIL_H__
#define __CLC_VECTOR_UTIL_H__

#include "../Common.h"

BEGIN_NAMESPACE

inline CL_Vec2f newVectorBySizeAndAngle(float size, float angle)
{
    return CL_Vec2f((float)cos(angle) * size,
                    (float)sin(angle) * size);
}

inline CL_Vec2f resizeVector(const CL_Vec2f &vector, float size)
{
    return CL_Vec2f(vector).normalize() * size;
}

inline CL_Vec2f truncateVector(const CL_Vec2f &vector, float size)
{
    return (vector.length() > size) ? resizeVector(vector, size) : vector;
}

inline float vectorDistance(const CL_Vec2f &vec1, const CL_Vec2f &vec2)
{
    return (vec1 - vec2).length();
}

END_NAMESPACE

#endif
