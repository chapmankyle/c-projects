/*
 * @brief A Simple Math library for any C/C++ program.
 *    for license: see LICENSE
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
#define smax(a, b)		(a > b ? a : b)
#define smin(a, b)		(a < b ? a : b)
#define sabs(a)			(a >= 0 ? a : -a)
#define ssquare(a)		(a * a)

#define sfloor(a)		((int) a)
#define ceil_pos(a)		((a - (int) a) > 0 ? (int) (a + 1) : (int) a)
#define ceil_neg(a)		((a - (int) a) < 0 ? (int) (a - 1) : (int) a)
#define sceil(a)		(a > 0 ? ceil_pos(a) : ceil_neg(a))

/* type definitions for convenience */
typedef signed int			int32_t;
typedef unsigned int		uint32_t;
typedef signed long int		int64_t;
typedef unsigned long int	uint64_t;

typedef enum { 
	false = 0, 
	true = 1 
} boolean;

/*
 * @brief Rounds [f] to the nearest 1.
 * 
 * @param f
 * 		The float to round
 * @return Rounded float to nearest 1
 */
int32_t sround(float f)
{
	return (int32_t) (f + 0.5f);
}

/*
 * @brief Rounds [f] to nearest integer [nearest].
 * 
 * @param f
 * 		The float to round to nearest integer
 * @param nearest
 * 		The nearest number to round to
 * @return f rounded to the nearest integer [nearest]
 */
int32_t sround_nearest(float f, int32_t nearest)
{
	return sround(f / nearest) * nearest;
}

/*
 * @brief Computes the power of function (base ^ expo).
 *
 * @param base
 *      The base number
 * @param expo
 *      The exponent
 * @return  [base] to-the-power-of [expo]
 */
float spow(float base, uint32_t expo)
{
	float result = 1.0;

	/* infinite for loop */
	for (;;) {
		if (expo & 1) { 
			result *= base; 
		}

		expo >>= 1;

		if (!expo) { 
			break; 
		}

		base *= base;
	}

	return result;
}

/*
 * @brief Computes the power function for integers only.
 *
 * @param base
 * 		The base number
 * @param expo
 * 		The exponent
 * @return [base] to-the-power-of [expo]
 */
uint64_t spowd(uint32_t base, uint32_t expo)
{
	return (uint32_t) (spow((float) base, expo));
}

/*
 * @brief Computes the exponent function (S_E ^ expo).
 *
 * @param expo
 * 		The exponent
 * @return [S_E] to-the-power-of [expo]
 */
float sexp(uint32_t expo)
{
	return spow(S_E, expo);
}

/*
 * @brief Computes the square root using the fast, inverse square root method.
 *
 * @param f
 *      Float to compute square root of
 * @return square root of [f]
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

/*
 * @brief Computes the sine of angle [theta] using Taylor Series expansion
 *
 * @param theta
 * 		Angle to find sine of
 * @return Approximation of sine of angle [theta] in radians
 */
float ssin(float theta)
{
	return (theta - (spow(theta, 3) / 6) + (spow(theta, 5) / 120) -
			(spow(theta, 7) / 5040));
}

/*
 * @brief Computes the cosine of angle [theta] using Taylor Series expansion
 *
 * @param theta
 * 		Angle to find cosine of
 * @return Approximation of cosine of angle [theta] in radians
 */
float scos(float theta)
{
	return (1 - (spow(theta, 2) / 2) + (spow(theta, 4) / 24) -
			(spow(theta, 6) / 720));
}

/*
 * @brief Computes the arc-tan of angle [theta] using Taylor Series expansion
 *
 * @param theta
 * 		Angle to find arc-tan of
 * @return Approximation of arc-tan of angle [theta]
 */
float sarctan(float theta)
{
	return (theta - (spow(theta, 3) / 3) + (spow(theta, 5) / 5) -
			(spow(theta, 7) / 7));
}

/* define at bottom so it can use functions above */
#define distance(ax, ay, bx, by) ssqrt(ssquare((float)bx - (float)ax) + \
			ssquare((float)by - (float)ay))

#ifdef __cplusplus
}
#endif

#endif
