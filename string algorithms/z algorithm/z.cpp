/*
Problem: Match/find the occurrence of pattern P in given string T
         Find minimum number of characters to be inserted at end to make it palindrome
Similar to KMP Algorithm,
Z Algorithm -> what is the length of the longest match forward at i which is also a prefix of the string

Example 1: Match/find the occurrence of pattern P in given string T
        T="a a b a b a c" given string T
        P="a b a" pattern to match
        S=(P+"#"+T) create new string, insert character which is not present in T, b/w P and T
        S="a b a # a a b a b a c"
        Z: 0 0 1 0 1 3 0 3 0 1 0
        Wherever there is 3-> is the starting index of the pattern P

Example 2: Find minimum number of characters to be inserted at end to make it palindrome
        S="a c e b e c __"
        z[]-> find longest suffix which is a palindrome, then add remaining characters to balance it
        S'= reverse(S) + "#" + S
        Find i such that i+z[i]=S'.length() ->points at last
        can be done using lps[] also
*/