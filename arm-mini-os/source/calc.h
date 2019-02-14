#ifndef CALC_H_
#define CALC_H_

#include "utils.h"

// Represents an expression, including:
//   - operand 'a'
//   - operand 'b'
//   - operator 'op'
//
// Examples:
//   1 + 2
//   -12 / 8
typedef struct {
  int a;
  int b;
  unsigned char op;
} calculator_expression_t;

calculator_expression_t parse_calc_expr(const char *const expression);

// ARM assembly-implemented functions
extern int add(int a, int b),  // --> a + b
    sub(int a, int b),         // --> a - b
    mul(int a, int b),         // --> a * b
    divide(int a, int b),      // Richard's division a/b
    remainder(int a, int b);   // Richard's modulus a%b
    // TODO: add assembly function for this
//    div_remainder(int a, int b,
//                  int *remainder);  // --> a / b, remainder=(a % b)

// calculate the result with the given mathematic operator
int calculate(const calculator_expression_t *expr, int *const remainder);

int calculator(int (*print_fn)(const char *, ...), char (*scan_char)());

#endif  // CALC_H_
