Hibbard deletion degradation. Write a program that takes an integer N from the
command line, builds a random BST of size N, then enters into a loop where it deletes
a random key (using the code delete(select(StdRandom.uniform(N)))) and then
inserts a random key, iterating the loop N 2 times. After the loop, measure and print the
average length of a path in the tree (the internal path length divided by N, plus 1). Run
your program for N = 10^2, 10^3, and 10^4 to test the somewhat counterintuitive hypothesis
that this process increases the average path length of the tree to be proportional to
the square root of N. Run the same experiments for a delete() implementation that
makes a random choice whether to use the predecessor or the successor node.