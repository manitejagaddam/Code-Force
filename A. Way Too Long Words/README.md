### problem Link: https://codeforces.com/problemset/problem/71/A


# Problem: Abbreviating Long Words

## Problem Statement

Sometimes some words like "localization" or "internationalization" are so long that writing them many times in one text is quite tiresome. We need to replace these long words with abbreviations.

A word is considered **too long** if its length is strictly more than 10 characters. If a word is too long, it should be replaced with an abbreviation. The abbreviation is formed as follows:
- Take the first letter of the word.
- Take the last letter of the word.
- In between the first and the last letter, write the number of characters between them (i.e., the length of the word minus 2).

For example:
- "localization" → "l10n"
- "internationalization" → "i18n"
- "pneumonoultramicroscopicsilicovolcanoconiosis" → "p43s"

Words that are not too long should remain unchanged.

## Input

- The first line contains an integer `n` (1 ≤ n ≤ 100) — the number of words.
- The next `n` lines each contain one word, consisting of lowercase Latin letters. Each word has a length between 1 and 100 characters.

## Output

- Print `n` lines. For each word, print its abbreviation if it's too long, or print the word as is if it's not too long.
