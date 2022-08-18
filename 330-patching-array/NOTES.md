​so let's say the smallest number missing from our sequence is "missing", now if we traverse the array and if we get any number which is smaller than or equal to it then we can add it to the sequence, if we get a number greater than our "missing" then we can be sure that missing would have to be added in our sequence so update the number of patches by 1,

- facts used
- if I can form all elements of (1,n) by some addition operations amongts those elements then addition of n+1 would enable me to build all elements in the range (0, sum of previous all elements+n+1) [this is a bit intuitive if you think about it].


--incase of further doubts - [go to the discuss section, the very first explanation by steffman ](https://leetcode.com/problems/patching-array/discuss/78488/Solution-%2B-explanation) . this is a great explanation!
