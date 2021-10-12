# Longest-Common-String
In this algorimn homework, I use two different algorimn method to find LCS.

1. The original ones is using nested iteration to find common characters, whose time complex is **O(n^2)**

2. The improved one is converting LCS to LIS problem, whose time complex is **O(nlogn)**


For example:
 s1[] = “abcabc”, s2[] = “abbcad”
 
1. Saving each char's index in s1
 a: 0,3
 b: 1,4 
 c: 2,5
 
 2.  converting s2 into a list of number.
    Note that if there are two different index of one char, it should be sorted from big to small, in case of repetive counting.
--> {3,0,4,1,4,1,5,2,3,0} 

 Doing LIS: {0,1,2,3}，length=4  ，and we can know the correspond string is ”abca”.
