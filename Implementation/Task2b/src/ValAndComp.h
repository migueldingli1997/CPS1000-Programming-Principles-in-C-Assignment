#ifndef VALANDCOMP_H_INCLUDED
#define VALANDCOMP_H_INCLUDED

/* operation: the parentheses, if any, in the expression found*/
/*            in 'express' are checked for mismatches.        */
/* preconditions: array containing expression to be checked is*/
/*                passed to the function.                     */
/* postconditions: '0' is returned in the case of a mismatch. */
/*                 '1' returned if the expression is valid.   */
int parenthesesVal(const char express[]);

/* operation: compares the precedence of two operators from   */
/*            '+', '-', '*', and '/'                          */
/* preconditions: characters 'a' and 'b' each contain an      */
/*                an operator. These will be compared together*/
/* postconditions: '1'  is returned if precedence of 'a' is   */
/*                      greater than that of 'b'              */
/*                 '0'  is returned if precedence of 'a' is   */
/*                      equal to that of 'b'                  */
/*                 '-1' is returned if precedence of 'a' is   */
/*                      less than that of 'b'                 */
int precedenceComp(const char a, const char b);

#endif // VALANDCOMP_H_INCLUDED
