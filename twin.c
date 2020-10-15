/* check if two strings are anagrams or not */
#include <stdio.h>
#include <string.h>

int check_anagram(char *, char *);

int main()
{
  char *a, *b;

  a = "OutLOOk";
  b = "LooKOuT";

  if (check_anagram(a, b))
    printf("The strings are anagrams.\n");
  else
    printf("The strings aren't anagrams.\n");

  return 0;
}

int check_anagram(char *a, char *b)
{
  int first[26] = {0}, second[26] = {0}, c = 0;

  // Calculating frequency of characters of the first string

  while (a[c] != '\0') {
    if(a[c] >= 'A' && a[c] <= 'Z') {
        first[(a[c] + 32) - 'a']++;
    } else {
        first[a[c] - 'a']++;
    }
    c++;
  }

  c = 0;

  while (b[c] != '\0') {
    if(b[c] >= 'A' && b[c] <= 'Z') {
        second[(b[c] + 32) - 'a']++;
    } else {
        second[b[c] - 'a']++;
    }
    c++;
  }

  // Comparing the frequency of characters

  for (c = 0; c < 26; c++)
    if (first[c] != second[c])
      return 0;

  return 1;
}
