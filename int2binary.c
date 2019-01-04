#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 9

char *int2bin(int a, char *buffer, int buff_size);

/*
 * Main function
 */
int main()
{
	int val = 0;
	char buffer[BUF_SIZE];
	buffer[BUF_SIZE - 1] = '\0';

	val = 14;
	int2bin(val, buffer, BUF_SIZE - 1);
	printf("%d in binary is :\t%s\n", val, buffer);

	return EXIT_SUCCESS;
}

/* @brief Converts integer to binary string
 *
 * @param[in]	a
 * 		integer to be converted to binary
 * @param[out]	buffer
 * 		string representation of binary of integer
 * @param[in]	buf_size
 * 		size of buffer
 * @return		binary string representation of integer
 */
char *int2bin(int a, char *buffer, int buf_size) {
	int i;
    buffer += (buf_size - 1);

    for (i = buf_size - 1; i >= 0; i--) {
        *buffer-- = (a & 1) + '0';

		a >>= 1;
    }

    return buffer;
}
