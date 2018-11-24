/*!
 * \file
 * \brief A simple program for checking if a word is a palindrome
 *
 * Call this program using as only argument the word to check.
 * E.g:
 *	> ./palindrome madam
 */

#include <stdio.h>
#include <string.h>

int isPalindrome(char str[]);

/*!
 * \brief Entry of program
 */
int main(int argc, char *argv[]) {
    printf("%s is %s palindrome\n",
           argv[1], isPalindrome(argv[1]) ? "a" : "not a");
    return 0;
}

/*!
 * \param str[] C-string to check
 * \return 1 if str[] represents a palindrome
 *
 * The function calls itself recursively on substrings.
 * An empty string is considered a palindrome.
 */
int isPalindrome(char str[]) {
    if (strlen(str))
		// check first and last character
        if (str[0] != str[strlen(str)])
            return 0;
        else {
			// call again on substring
            str[strlen(str)] = "\0";
            return isPalindrome(str[1]);
        }
    else
        return 1;
}
