#ifndef VALANDCOMP_H_INCLUDED
#define VALANDCOMP_H_INCLUDED

/* operation: the parentheses, if any, in the expression found*/
/*            in 'express' are checked for mismatches.        */
/* preconditions: array containing expression to be checked is*/
/*                passed to the function.                     */
/* postconditions: '0' is returned in the case of a mismatch. */
/*                 '1' returned if the expression is valid.   */
int parenthesesVal(const char express[]);

#endif // VALANDCOMP_H_INCLUDED
