Average search time. 
Run empirical studies to compute the average and standard
deviation of the average length of a path to a random node (internal path length
divided by tree size, plus 1) in a BST built by insertion of N random keys into an initially
empty tree, for N from 100 to 10,000. Do 1,000 trials for each tree size. Plot the results in
a Tufte plot, like the one at the bottom of this page, fit with a curve plotting the function
1.39 lg N – 1.85

20.11.2017
- function that creates input;// int[] buildInput(int minValue, int MaxValue, int ntOfValues);
- fct. that computes IPL (internal path length);// float computeIPL(Node *root)
