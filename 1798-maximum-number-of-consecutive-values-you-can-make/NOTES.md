​so let's say the smallest number missing from our sequence is "missing", now if we traverse the array and if we get any number which is smaller than or equal to it then we can add it to the sequence, else there's no point in adding it as we won't be able to construct all the elements till this element i.

facts used
if I can form all elements of (1,n) by some addition operations amongts those elements then addition of n+1 would enable me to build all elements in the range (0, sum of previous all elements+n+1) [this is a bit intuitive if you think about it].
--incase of further doubts - go to the discuss section, the very first explanation by steffman [although this is a solution to a harder question]. this is a great explanation!
