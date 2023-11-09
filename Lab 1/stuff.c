/* stuff.c --- 
 * 
 * Filename: stuff.c
 * Description: 
 * Author: Joseph
 * Maintainer: 
 * Created: Wed Sep 20 11:38:45 2023 (+0100)
 * Last-Updated: Wed Sep 20 11:46:34 2023 (+0100)
 *           By: Joseph
 *     Update #: 2
 * 
 */

/* Commentary: 
 * 
 * 
 * 
 */

/* This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or (at
 * your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with GNU Emacs.  If not, see <http://www.gnu.org/licenses/>.
 */

/* Code: */

/**
 * A brief history of JavaDoc-style (C-style) comments.A javadoc style comment for Doxygen
 *
 * This is the typical JavaDoc-style C-style comment. It starts with two
 * asterisks. This is a longer comment detailing algorithm (as required)
 *
 * @param N Integer input to function
 * @return the factorial of N
 *               
 */
int factorial(int N){
  if (N < 1) {
    return 1;
  }
 
  return N * factorial(N - 1);
}


/*******************************************************************************
 * A brief history of JavaDoc-style (C-style) banner comments.
 *
 * This is the typical JavaDoc-style C-style "banner" comment. It starts with
 * a forward slash followed by some number, n, of asterisks, where n > 2. It's
 * written this way to be more "visible" to developers who are reading the
 * source code.
 *
 * Often, developers are unaware that this is not (by default) a valid Doxygen
 * comment block!
 *
 * However, as long as JAVADOC_BLOCK = YES is added to the Doxyfile, it will
 * work as expected.
 *
 * This style of commenting behaves well with clang-format.
 *
 * @param theory Even if there is only one possible unified theory. it is just a
 *               set of rules and equations.
 ******************************************************************************/
int fibonacci(int N){
  int a = 0, b = 1, c, i;
  if (N <= 0)
    return a;
  for (i = 2; i <= N; i++) {
    c = a + b;
    a = b;
    b = c;
  }
  return b;
}
  



// MAIN && TESTS

 #include "minunit.h"
 
 int tests_run = 0;
 
 int foo = 7;
 int bar = 8;
 
 static char * test_fact() {
     mu_assert("error, foo != 5040", factorial(foo) == 5040);
     return 0;
 }

 static char * test_fact_edge() {
     mu_assert("error, foo edge case != 1", factorial(-20) == 1);
     return 0;
 }
 
 static char * test_fib() {
     mu_assert("error, bar != 21", fibonacci(bar) == 21);
     return 0;
 }

 static char * test_fib_edge() {
     mu_assert("error, bar edge case != 0", fibonacci(-20) == 0);
     return 0;
 }
 
 static char * all_tests() {
     mu_run_test(test_fact);
     mu_run_test(test_fib);
     mu_run_test(test_fact_edge);
     mu_run_test(test_fib_edge);
     return 0;
 }

int main(int argc, char **argv) {
    char *result = all_tests();
     if (result != 0) {
         printf("%s\n", result);
     }
     else {
         printf("ALL TESTS PASSED\n");
     }
     printf("Tests run: %d\n", tests_run);
 
     return result != 0;
 }

/* stuff.c ends here */
