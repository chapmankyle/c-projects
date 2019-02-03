/*
 * A Simple 2D Vector library for any C/C++ program.
 *    for license: see LICENSE.txt
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
 * Initializes a new integer vector
 * @param   x
 *      vector x value
 * @param   y
 *      vector y value
 * @return  new integer vector
 */
sVec2i sVec2iInit(int x, int y)
{
    sVec2i z = iZERO;
    z.x = x;
    z.y = y;
    return z;
}

/*
 * Initializes a new float vector
 * @param   x
 *      vector x value
 * @param   y
 *      vector y value
 * @return  new float vector
 */
sVec2f sVec2fInit(float x, float y)
{
    sVec2f z = fZERO;
    z.x = x;
    z.y = y;
    return z;
}

/*
 * Adds two integer vectors together
 * @param   a
 *      first integer vector to add
 * @param   b
 *      second integer vector to add
 * @return  the integer vector addition of [a] and [b]
 */
sVec2i sVec2iAdd(sVec2i a, sVec2i b)
{
    sVec2i c = iZERO;
    c.x = a.x + b.x;
    c.y = a.y + b.y;
    return c;
}

/*
 * Adds two float vectors together
 * @param   a
 *      first float vector to add
 * @param   b
 *      second float vector to add
 * @return  the float vector addition of [a] and [b]
 */
sVec2f sVec2fAdd(sVec2f a, sVec2f b)
{
    sVec2f c = fZERO;
    c.x = a.x + b.x;
    c.y = a.y + b.y;
    return c;
}

/*
 * Subtracts two integer vectors from each other
 * @param   a
 *      first integer vector to subtract
 * @param   b
 *      second integer vector to subtract
 * @return  the integer vector subtraction of [a] and [b]
 */
sVec2i sVec2iSub(sVec2i a, sVec2i b)
{
    sVec2i c = iZERO;
    c.x = a.x - b.x;
    c.y = a.y - b.y;
    return c;
}

/*
 * Subtracts two float vectors from each other
 * @param   a
 *      first float vector to subtract
 * @param   b
 *      second float vector to subtract
 * @return  the float vector subtraction of [a] and [b]
 */
sVec2f sVec2fSub(sVec2f a, sVec2f b)
{
    sVec2f c = fZERO;
    c.x = a.x - b.x;
    c.y = a.y - b.y;
    return c;
}

/*
 * Checks if two integer vectors are equal
 * @param   a
 *      first integer vector to compare
 * @param   b
 *      second integer vector to compare
 * @return  [true] (if a and b are equal), [false] otherwise
 */
boolean sVec2iEqual(sVec2i a, sVec2i b)
{
    return (a.x == b.x && a.y == b.y);
}

/*
 * Checks if two float vectors are equal
 * @param   a
 *      first float vector to compare
 * @param   b
 *      second float vector to compare
 * @return  [true] (if a and b are equal), [false] otherwise
 */
boolean sVec2fEqual(sVec2f a, sVec2f b)
{
    return (a.x == b.x && a.y == b.y);
}

/*
 * Computes the distance between two integer vectors
 * @param   a
 *      first integer vector
 * @param   b
 *      second integer vector
 * @return  integer value of distance between the two vectors
 */
uint32_t sVec2iDistance(sVec2i a, sVec2i b)
{
    return (uint32_t) (distance(a.x, a.y, b.x, b.y));
}

/*
 * Computes the distance between two float vectors
 * @param   a
 *      first float vector
 * @param   b
 *      second float vector
 * @return  float value of distance between the two vectors
 */
float sVec2fDistance(sVec2f a, sVec2f b)
{
    return distance(a.x, a.y, b.x, b.y);
}

/*
 * Computes the length of the integer vector
 * @param   a
 *      vector to measure length
 * @return  length of integer vector [a]
 */
float sVec2iLength(sVec2i a)
{
    return ssqrt((a.x * a.x) + (a.y * a.y));
}

/*
 * Computes the length of the float vector
 * @param   a
 *      vector to measure length
 * @return  length of float vector [a]
 */
float sVec2fLength(sVec2f a)
{
    return ssqrt((a.x * a.x) + (a.y * a.y));
}

/*
 * Normalize integer vector
 * @param   a
 *      integer vector to normalize
 * @return  normalized vector
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
 * Normalize float vector
 * @param   a
 *      float vector to normalize
 * @return  normalized vector
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
 * Computes the angle the integer vector is facing in radians
 * @param   a
 *      vector to compute angle of
 * @return  angle the vector is facing in radians
 */
float sVec2iAngle(sVec2i a)
{
    return sarctan((float)(a.y) / (float)(a.x));
}

/*
 * Computes the angle the float vector is facing in radians
 * @param   a
 *      vector to compute angle of
 * @return  angle the vector is facing in radians
 */
float sVec2fAngle(sVec2f a)
{
    return sarctan(a.y / a.x);
}

#ifdef __cplusplus
}
#endif

#endif
