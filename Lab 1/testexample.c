/* testexample.c --- 
 * 
 * Filename: testexample.c
 * Description: 
 * Author: Joseph
 * Maintainer: 
 * Created: Wed Sep 20 10:16:11 2023 (+0100)
 * Last-Updated: Wed Sep 20 10:19:50 2023 (+0100)
 *           By: Joseph
 *     Update #: 3
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

 /* file minunit_example.c */
 
 #include <stdio.h>
 #include "minunit.h"
 
 int tests_run = 0;
 
 int foo = 7;
 int bar = 4;
 
 static char * test_foo() {
     mu_assert("error, foo != 7", foo == 7);
     return 0;
 }
 
 static char * test_bar() {
     mu_assert("error, bar != 5", bar == 5);
     return 0;
 }
 
 static char * all_tests() {
     mu_run_test(test_foo);
     mu_run_test(test_bar);
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

/* testexample.c ends here */
