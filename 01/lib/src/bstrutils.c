/**
 * @file string_utils.c
 * @brief Implementation of basic string utility functions:
 *        reverse, trim, and convert string to integer.
 *
 * This file provides simple utility functions for manipulating strings,
 * including reversing a string, trimming leading spaces, and converting
 * numeric strings to integers.
 */
#include <stdio.h>

/**
 * @brief Reverse a given string in-place.
 *
 * This function swaps characters symmetrically from the start and end
 * of the string until the middle is reached. The reversal is done in-place,
 * meaning the original string content is modified directly.
 *
 * @param[in,out] str Pointer to the string to be reversed.
 * @param[in] len Length of the string (excluding the null terminator).
 *
 * @note The string is assumed to be mutable (not a string literal).
 * @warning Behavior is undefined if @p str is NULL or @p len <= 0.
 *
 * @return None
 */
void str_reverse(char * str, long long int len)
{
    long long int index = 0;
    long long int index_reserve = 0;
    char str_temp = 0;

    for(index = 0, index_reserve = len - 1; \
        index < index_reserve;              \
        index ++, index_reserve --)
    {
        str_temp = str[index];
        str[index] = str[index_reserve];
        str[index_reserve] = str_temp;
    }
}

/**
 * @brief Trim leading spaces from a string in-place.
 *
 * This function removes all leading spaces (' ') from the input string
 * by shifting remaining characters to the left.
 *
 * @param[in,out] str Pointer to the string to be trimmed.
 * @param[in] len Length of the string (excluding the null terminator).
 *
 * @note Only leading spaces are removed; trailing spaces remain unchanged.
 * @warning Behavior is undefined if @p str is NULL.
 *
 * @return None
 */
void str_trim(char * str, long long int len)
{
    char str_trim_type = ' ';
    long long int index = 0;
    long long int index_remove = 0;

    for(index = 0; index < len; index ++)
    {
        for(; str[index] == str_trim_type; )
        {
            index_remove = index;
            for(; index_remove < len; index_remove ++)
            {
                str[index_remove] = str[index_remove + 1];
            }

            len --;
        }
    }
}

/**
 * @brief Convert a numeric string to an integer.
 *
 * This function parses each character in the input string and constructs
 * an integer value by accumulating digits ('0'–'9'). Non-digit characters
 * are ignored.
 *
 * @param[in] str Pointer to the numeric string.
 * @param[in] len Length of the string (excluding the null terminator).
 *
 * @return The integer value represented by the numeric part of the string.
 *
 * @note The function does not handle negative numbers or overflow.
 * @warning Behavior is undefined if @p str is NULL.
 */
int str_to_int(char * str, long long int len)
{
    long long int index = 0;
    int ret = 0;

    for(index = 0; index < len; index ++)
    {
        if(str[index] >= '0' && str[index] <= '9')
        {
            ret = (ret * 10) + (str[index] - '0');
        }
    }

    return ret;
}
