/*
 * A Simple Math library for any C/C++ program.
 *    for license: see LICENSE.txt
 *
 * @author Kyle Chapman
 * @date 01-02-2019
 */

#ifndef SMATH_H
#define SMATH_H

/* affects linkage */
#ifdef __cplusplus
extern "C" {
#endif

/* define all constants */
#define S_E     2.7182818284590452354
#define S_PI    3.1415926535897932385

/* define all inline functions */
#define smax(a, b)      (a > b ? a : b)
#define smin(a, b)      (a < b ? a : b)
#define sabs(a)         (a >= 0 ? a : -a)
#define ssquare(a)      (a * a)

#define sfloor(a)       ((int) a)
#define ceil_pos(a)     ((a - (int) a) > 0 ? (int) (a + 1) : (int) a)
#define ceil_neg(a)     ((a - (int) a) < 0 ? (int) (a - 1) : (int) a)
#define sceil(a)        (a > 0 ? ceil_pos(a) : ceil_neg(a))

/* type definitions for convenience */
typedef signed int          int32_t;
typedef unsigned int        uint32_t;
typedef signed long int     int64_t;
typedef unsigned long int   uint64_t;

typedef enum { false = 0, true = 1 } boolean;

/*
 * Rounds [f] to the nearest 1.
 * @param   f
 *      float to round
 * @return  rounded float to nearest 1
 */
int32_t sround(float f)
{
    return (int32_t) (f + 0.5f);
}

/*
 * Rounds [f] to nearest integer [nearest].
 * @param   f
 *      float to round
 * @param   nearest
 *      nearest number to round to
 * @return  [f] rounded to the nearest integer [nearest]
 */
int32_t sround_nearest(float f, int32_t nearest)
{
    return sround(f / nearest) * nearest;
}

/*
 * Computes the power of function (base ^ expo).
 * @param   base
 *      base number
 * @param   expo
 *      exponent
 * @return  [base] to-the-power-of [expo]
 */
float spow(float base, uint32_t expo)
{
    float result = 1.0;

    for (;;) {
        if (expo & 1) { result *= base; }
        expo >>= 1;
        if (!expo) { break; }
        base *= base;
    }

    return result;
}

/*
 * Computes the power function for integers only.
 * @param   base
 *      base number
 * @param   expo
 *      exponent
 * @return  [base] to-the-power-of [expo]
 */
uint64_t spowd(uint32_t base, uint32_t expo)
{
    return (uint32_t) (spow((float) base, expo));
}

/*
 * Computes the exponent function (S_E ^ expo).
 * @param   expo
 *      exponent
 * @return  [S_E] to-the-power-of [expo]
 */
float sexp(uint32_t expo)
{
    return spow(S_E, expo);
}

/*
 * Computes the square root using the fast, inverse square root method.
 * @param   f
 *      float to compute square root of
 * @return  square root of [f]
 */
float ssqrt(float f)
{
    long i;
    float x, y;
    const float threehalfs = 1.5;
    x = f * 0.5;
    y = f;
    i = *(long *) &y;
    i = 0x5f3759df - (i >> 1);
    y = *(float *) &i;
    y = y * (threehalfs - (x * y * y));
    return 1.0 / y;
}

/* define at bottom so it can use functions above */
#define distance(ax, ay, bx, by)    ssqrt(ssquare((float)bx - (float)ax) + ssquare((float)by - (float)ay))

#ifdef __cplusplus
}
#endif

#endif
