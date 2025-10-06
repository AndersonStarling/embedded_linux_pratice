#ifndef STRULTIS_H
#define STRULTIS_H

/**
 * @brief Reverse a given string in-place.
 * @param[in,out] str Pointer to the string buffer to reverse.
 * @param[in] len Length of the string.
 */
void str_reverse(char * str, long long int len);

/**
 * @brief Trim leading spaces from the input string.
 * @param[in,out] str Pointer to the string to trim.
 * @param[in] len Length of the string.
 */
void str_trim(char * str, long long int len);

/**
 * @brief Convert numeric string to integer.
 * @param[in] str Pointer to the numeric string.
 * @param[in] len Length of the string.
 * @return Integer value parsed from the string.
 */
int str_to_int(char * str, long long int len);

#endif /* STRULTIS_H */
