/**
 * @file main.c
 * @brief Test program for the string utility library.
 *
 * This file demonstrates the usage of string manipulation functions
 * defined in @ref strutils.h, including:
 * - str_reverse()
 * - str_trim()
 * - str_to_int()
 *
 * The program runs a few basic test cases to verify correct behavior.
 *
 * @date 2025-10-06
 * @version 1.0
 */
#include <stdio.h>
#include "strutils.h"

/**
 * @brief Run a simple test case for str_reverse().
 */
void test_str_reverse(void)
{
    char test_str_reverse[] = "Hello123";
    long long int len_test_str_reverse = sizeof(test_str_reverse) - 1;

    str_reverse(test_str_reverse, len_test_str_reverse);

    printf("test_str_reverse: %s\n", test_str_reverse);
}

/**
 * @brief Run a simple test case for str_trim().
 */
void test_str_trim(void)
{
    char test_str_trim[] = "  Hello123  1";
    long long int len_test_str_trim = sizeof(test_str_trim) - 1;

    str_trim(test_str_trim, len_test_str_trim);

    printf("test_str_trim: %s\n", test_str_trim);
}

/**
 * @brief Run a simple test case for str_to_int().
 */
void test_str_to_int(void)
{
    char test_str_to_int[] = "123";
    long long int len_test_str_to_int = sizeof(test_str_to_int);

    printf("test_str_to_int: %d\n", str_to_int(test_str_to_int, len_test_str_to_int));
}

/**
 * @brief Entry point of the test application.
 *
 * Calls a set of test functions to verify that string utilities
 * work as expected.
 *
 * @return 0 on success.
 */
int main(void)
{
    test_str_reverse();
    test_str_trim();
    test_str_to_int();

    return 0;
}


