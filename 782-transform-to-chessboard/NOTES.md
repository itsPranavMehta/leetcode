In this question we'll firstly check whether solution could exist or not- for this we can do the 2 checks
1. the number of 0s and 1s in all rows and columns should be equal or differ by 1(in case of odd), just performing this check on first row and col would suffice because of the 2nd condition.
2. all the rows should belong to 2 types- one of the type of the first row and other exactly inverse also the number of same and inverse rows should differ by atmost 1. Same logic goes for the cols as well.

If the above 2 checks succeed we can find min number else we return -1

now since the first cell (0,0) could either be a 0 or a 1. hence we need to check for both the scenarios and checking on the first row and first column would suffice as all other rows and columns are either same or inverted so they'll also get manipulated accordingly!
Say the number of cells in the wrong position  in 1st row are row1 and in 1st col are col1 [considering 0 as the first cell].
now similarly row2 and col2 are the numbers considering 1 as the first cell.
then if row1 or row2 is odd then use the other since it can't be used owing to the fact that odd number of swaps won't make a sequence right!
else use the minimum one.
same shall be done in case of columns






--- inuition-
In these kinds of questions it becomes easier to think in a top down fashion say having a good chessboard and jumbling it up, this way we are able to see the patterns that would appear.
