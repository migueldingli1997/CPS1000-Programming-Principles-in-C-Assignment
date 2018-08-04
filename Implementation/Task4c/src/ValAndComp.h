#ifndef VALANDCOMP_H_INCLUDED
#define VALANDCOMP_H_INCLUDED

/* operation: the infix expression 'express' is checked for   */
/*            mismatches in parantheses, illegal characters,  */
/*            and for the case where the user input an empty  */
/*            expression. Also, if expression size limit was  */
/*            reached, user is warned about incorrect results.*/
/* preconditions: array containing expression to be checked is*/
/*                passed to the function.                     */
/* postconditions: '0' is returned if the expression broke one*/
/*                 of the guidelines specified above; '1' is  */
/*                 returned if the expression is valid. Not   */
/*                 Note that if the size limit was exceeded,  */
/*                 expression is still considered to be valid.*/
int expressionVal(const char express[]);

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
