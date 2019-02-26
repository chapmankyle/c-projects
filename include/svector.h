/*
 * @brief A Simple 2D Vector library for any C/C++ program.
 *    for license: see LICENSE
 *
 * @author Kyle Chapman
 * @date 03-02-2019
 */

#ifndef SVECTOR_H
#define SVECTOR_H

/* affects linkage */
#ifdef __cplusplus
extern "C" {
#endif

/* included so this header file can use the boolean type */
#include "smath.h"

/* define the 2D vector for integer values */
typedef struct {
	int x, y;
} sVec2i;

/* define the 2D vector for float values */
typedef struct {
	float x, y;
} sVec2f;

/* setting 0 vectors for the float and integer types */
const sVec2i iZERO = {0};
const sVec2f fZERO = {0};

/*
 * @brief Initializes a new integer vector
 *
 * @param x
 * 		Vector x value
 * @param y
 * 		Vector y value
 * @return New integer vector
 */
sVec2i sVec2iInit(int x, int y)
{
	sVec2i z = iZERO;
	z.x = x;
	z.y = y;
	return z;
}

/*
 * @brief Initializes a new float vector
 *
 * @param x
 * 		Vector x value
 * @param y
 * 		Vector y value
 * @return New float vector
 */
sVec2f sVec2fInit(float x, float y)
{
	sVec2f z = fZERO;
	z.x = x;
	z.y = y;
	return z;
}

/*
 * @brief Adds two integer vectors together
 *
 * @param a
 * 		First integer vector to add
 * @param b
 * 		Second integer vector to add
 * @return The integer vector addition of [a] and [b]
 */
sVec2i sVec2iAdd(sVec2i a, sVec2i b)
{
	sVec2i c = iZERO;
	c.x = a.x + b.x;
	c.y = a.y + b.y;
	return c;
}

/*
 * @brief Adds two float vectors together
 *
 * @param a
 * 		First float vector to add
 * @param b
 * 		Second float vector to add
 * @return The float vector addition of [a] and [b]
 */
sVec2f sVec2fAdd(sVec2f a, sVec2f b)
{
	sVec2f c = fZERO;
	c.x = a.x + b.x;
	c.y = a.y + b.y;
	return c;
}

/*
 * @brief Subtracts two integer vectors from each other
 *
 * @param a
 * 		First integer vector to subtract
 * @param b
 * 		Second integer vector to subtract
 * @return The integer vector subtraction of [a] and [b]
 */
sVec2i sVec2iSub(sVec2i a, sVec2i b)
{
	sVec2i c = iZERO;
	c.x = a.x - b.x;
	c.y = a.y - b.y;
	return c;
}

/*
 * @brief Subtracts two float vectors from each other
 *
 * @param a
 * 		First float vector to subtract
 * @param b
 * 		Second float vector to subtract
 * @return The float vector subtraction of [a] and [b]
 */
sVec2f sVec2fSub(sVec2f a, sVec2f b)
{
	sVec2f c = fZERO;
	c.x = a.x - b.x;
	c.y = a.y - b.y;
	return c;
}

/*
 * @brief Checks if two integer vectors are equal
 *
 * @param a
 * 		First integer vector to compare
 * @param b
 * 		Second integer vector to compare
 * @return [true] if a and b are equal, and [false] otherwise
 */
boolean sVec2iEqual(sVec2i a, sVec2i b)
{
	return (a.x == b.x && a.y == b.y);
}

/*
 * @brief Checks if two float vectors are equal
 *
 * @param a
 * 		First float vector to compare
 * @param b
 * 		Second float vector to compare
 * @return [true] if a and b are equal, and [false] otherwise
 */
boolean sVec2fEqual(sVec2f a, sVec2f b)
{
	return (a.x == b.x && a.y == b.y);
}

/*
 * @brief Computes the distance between two integer vectors
 *
 * @param a
 * 		First integer vector
 * @param b
 * 		Second integer vector
 * @return Integer value of distance between the two vectors
 */
uint32_t sVec2iDistance(sVec2i a, sVec2i b)
{
	return (uint32_t) (distance(a.x, a.y, b.x, b.y));
}

/*
 * @brief Computes the distance between two float vectors
 *
 * @param a
 * 		First float vector
 * @param b
 * 		Second float vector
 * @return Float value of distance between the two vectors
 */
float sVec2fDistance(sVec2f a, sVec2f b)
{
	return distance(a.x, a.y, b.x, b.y);
}

/*
 * @brief Computes the length of the integer vector
 *
 * @param a
 * 		Vector to measure length
 * @return Length of integer vector [a]
 */
float sVec2iLength(sVec2i a)
{
	return ssqrt((a.x * a.x) + (a.y * a.y));
}

/*
 * @brief Computes the length of the float vector
 *
 * @param a
 * 		Vector to measure length
 * @return Length of float vector [a]
 */
float sVec2fLength(sVec2f a)
{
	return ssqrt((a.x * a.x) + (a.y * a.y));
}

/*
 * @brief Normalize integer vector
 *
 * @param a
 * 		Integer vector to normalize
 * @return Normalized vector
 */
sVec2i sVec2iNormalize(sVec2i a)
{
	sVec2i b = iZERO;
	float len = sVec2iLength(a);
	b.x = a.x / len;
	b.y = a.y / len;
	return b;
}

/*
 * @brief Normalize float vector
 *
 * @param a
 * 		Float vector to normalize
 * @return Normalized vector
 */
sVec2f sVec2fNormalize(sVec2f a)
{
	sVec2f b = fZERO;
	float len = sVec2fLength(a);
	b.x = a.x / len;
	b.y = a.y / len;
	return b;
}

/*
 * @brief Computes the angle the integer vector is facing in radians
 *
 * @param a
 * 		Vector to compute angle of
 * @return Angle the vector is facing in radians
 */
float sVec2iAngle(sVec2i a)
{
	return sarctan((float)(a.y) / (float)(a.x));
}

/*
 * Computes the angle the float vector is facing in radians
 * @param a
 * 		Vector to compute angle of
 * @return Angle the vector is facing in radians
 */
float sVec2fAngle(sVec2f a)
{
	return sarctan(a.y / a.x);
}

#ifdef __cplusplus
}
#endif

#endif
