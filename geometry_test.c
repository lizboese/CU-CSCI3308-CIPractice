/*
 * geometry_test.c
 * Andy Sayler
 * CSCI 3308
 * Summer 2014
 *
 * This file containsunit tests for geometry.c
 *
 * Requires http://check.sourceforge.net/
 *
 */

#include <stdlib.h>
#include <check.h>

#include "geometry.h"

/* coord_2d_eq Test */
START_TEST(test_2d_eq)
{
    coord_2d_t a;
    coord_2d_t b;

    a.x = b.x = 0;
    a.y = b.y = 0;
    ck_assert(coord_2d_eq(&a, &b));

    a.x = b.x = 9.99;
    a.y = b.y = 9.99;
    ck_assert(coord_2d_eq(&a, &b));

    a.x = b.x = 3.33;
    a.y = b.y = 9.99;
    ck_assert(coord_2d_eq(&a, &b));

    a.x = 3.33;
    a.y = 9.99;
    b.x = 3.33;
    b.y = 10.99;
    ck_assert(!coord_2d_eq(&a, &b));

    a.x = 3.33;
    a.y = 9.99;
    b.x = 2.33;
    b.y = 9.99;
    ck_assert(!coord_2d_eq(&a, &b));

    a.x = 1.11;
    a.y = 2.22;
    b.x = 7.77;
    b.y = 8.88;
    ck_assert(!coord_2d_eq(&a, &b));

}
END_TEST

/* coord_2d_dist Test */
START_TEST(test_2d_dist)
{
    coord_2d_t a;
    coord_2d_t b;

    a.x = b.x = 0;
    a.y = b.y = 0;
    ck_assert(coord_2d_dist(&a, &b) == 0.0);

    a.x = 0;
    a.y = 0;
    b.x = 3;
    b.y = 0;
    ck_assert(coord_2d_dist(&a, &b) == 3.0);

    a.x = 0;
    a.y = 0;
    b.x = 0;
    b.y = 3;
    ck_assert(coord_2d_dist(&a, &b) == 3.0);

    a.x = 0;
    a.y = 0;
    b.x = 3;
    b.y = 4;
    ck_assert(coord_2d_dist(&a, &b) == 5.0);

    a.x = 1;
    a.y = 2;
    b.x = 4;
    b.y = 6;
    ck_assert(coord_2d_dist(&a, &b) == 5.0);

}
END_TEST

/* coord_2d_midpoint Test */
START_TEST(test_2d_midpoint)
{
    coord_2d_t a;
    coord_2d_t b;
    coord_2d_t mid;
    coord_2d_t exp;

    a.x = b.x = 0;
    a.y = b.y = 0;
    coord_2d_midpoint(&mid, &a, &b);
    exp.x = 0;
    exp.y = 0;
    ck_assert(coord_2d_eq(&mid, &exp));

    a.x = 0;
    a.y = 0;
    b.x = 3;
    b.y = 0;
    coord_2d_midpoint(&mid, &a, &b);
    exp.x = 1.5;
    exp.y = 0;
    ck_assert(coord_2d_eq(&mid, &exp));

    a.x = 0;
    a.y = 0;
    b.x = 0;
    b.y = 3;
    coord_2d_midpoint(&mid, &a, &b);
    exp.x = 0;
    exp.y = 1.5;
    ck_assert(coord_2d_eq(&mid, &exp));

    a.x = 0;
    a.y = 0;
    b.x = 3;
    b.y = 3;
    coord_2d_midpoint(&mid, &a, &b);
    exp.x = 1.5;
    exp.y = 1.5;
    ck_assert(coord_2d_eq(&mid, &exp));

    a.x = 1;
    a.y = 2;
    b.x = 3;
    b.y = 4;
    coord_2d_midpoint(&mid, &a, &b);
    exp.x = 2;
    exp.y = 3;
    ck_assert(coord_2d_eq(&mid, &exp));

}
END_TEST

/* coord_2d Test Suite */
Suite* coord_2d_suite(void)
{

    /* Create Suite */
    Suite* s = suite_create("coord_2d");

    /* Setup Test Cases */
    TCase* tc_2d_eq = tcase_create("coord_2d_eq");
    tcase_add_test(tc_2d_eq, test_2d_eq);

    TCase* tc_2d_dist = tcase_create("coord_2d_dist");
    tcase_add_test(tc_2d_dist, test_2d_dist);

    TCase* tc_2d_midpoint = tcase_create("coord_2d_midpoint");
    tcase_add_test(tc_2d_midpoint, test_2d_midpoint);

    /* Add Cases to Suite */
    suite_add_tcase(s, tc_2d_eq);
    suite_add_tcase(s, tc_2d_dist);
    suite_add_tcase(s, tc_2d_midpoint);

    /* Return Suite */
    return s;

}

/* main: run test suites and set exit status */
int main(void){

    int failed = 0;
    Suite* s = coord_2d_suite();
    SRunner* sr = srunner_create(s);
    srunner_run_all(sr, CK_VERBOSE);
    failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (failed ? EXIT_FAILURE : EXIT_SUCCESS);

}
