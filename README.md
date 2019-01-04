# C Projects
Public repo for all C projects I *attempt* or actually finish.

## Current files include:

### int2binary
Program that converts any `integer` into the `binary char *` representation of the integer.

*Let's look at an example:*

Using the integer `14`, the output should be
```
14 in binary is: 00001110
```

Click [here](https://github.com/chapmankyle/c-projects/blob/master/int2binary.c) to go directly to the file.

### degree_sum
Program that takes 2 numbers as input, `n` and `m`, and computes the sum of the degree.

Okay, that sounds complicated, here's an **example**:

*Let's use `5` and `3` as the inputs `n` and `m`, respectively.*

*Output should be as follows:*
```
1 + 2 + 3 + 4 + 5 = 15
1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10 + 11 + 12 + 13 + 14 + 15 = 120
1 + 2 + ... + 119 + 120 = 7260
sum(5, 3) = 7260
```
As you can see, `n` is used as a starting point to count up to and `m` is used to tell the program how many iterations to do.

*Let's now use `6` and `2` as the inputs `n` and `m`, respectively.*
```
1 + 2 + 3 + 4 + 5 + 6 = 21
1 + 2 + ... + 20 + 21 = 231
sum(6, 2) = 231
```
Click [here](https://github.com/chapmankyle/c-projects/blob/master/degree_sum.c) to test it out for yourself.
