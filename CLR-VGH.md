# Course Learning Reflections
###### Vishruth G H
###### 01FE23BCS250
<hr>

## Problems of Nature
The core aspect of the course is understanding the intuition behind the problem-solving approach. Who better to learn about problem-solving approaches than Mother Nature?
Nature's most significant problem is of sustaining life to that end, it solves all problems that threaten the quality of life. Learning the way these problems are structured and how natural elements solve these problems builds intuition for identifying and optimizing solutions. 
The vast number of natural phenomena can be classified into 3 patterns: iteration, recursion and backtracking. 
### Iteration
Iteration involves the repetition of a set of certain actions to fulfil a condition. 
This method can be observed in nature across several instances:
1. Bees Foraging: Bees seek nectar from flowers repeatedly until they fulfil their requirement.
2. Cat cleaning: A cat repeatedly licks its fur until a threshold of cleanliness is reached

Inspired by such instances, we develop iterative approaches for solving problems such as sequential search, lock-picking, etc.

### Recursion
Recursion is a process that a procedure goes through where one of the steps reduces the problem by applying the same procedure over a smaller instance of the problem.
Recursion in math and computer science is defined by 2 properties:
(i)base case: The terminating procedure that has a definite solution. i.e, the smallest instance of the problem
(ii) recursive case: The procedure that boils all other cases to the base case
With this definition, recursion could be interpreted as a form of decrease-and-conquer design principle. (design principles are discussed later)

below are a couple of examples of how recursion is observed in nature, :
1. Weathering of rocks: rocks are broken down into their smaller versions - smaller rocks, then stones, then finally, dust and sand (the base case).
2. Snowflake pattern: A snowflakes have repeating patterns which form each of its branches and are limited by physical conditions which case be considered as the base case.

Recursion is applied in math and computer science wherever a problem can be defined as a smaller instance of itself. for example, Factorials, Fibonacci sequence, etc.


### Backtracking
Backtracking is a problem-solving approach which involves exploring a possible solution to a dead end, then tracing back to the previous choice and then explore the alternative.
below are a couple of examples of how backtracking in nature is observed:
1. Ants finding food: Ants explore possible trails where food can be found and then trace back and explore an alternate path.
2. Birds building nests: Birds attempt building a nest by placing twigs and dry grass in a certain way and if the structure becomes unstable, they adjust it by tracing back to the previous stable structure and exploring alternate possibilities.

Backtracking has inspired algorithms which solve problems like the N-queens problem, Maze, etc.

## Analysis of problem-solving approaches
Once you figure out a way to solve a problem, the next step to be considered is the resources that the solution takes, and how well it performs. 
An algorithm can be assessed on 2 things: 
1. Step count: The number of steps (actions) it performs throughout the execution of the algorithm. It measures the no.of clock cycles and depends on the system architecture, hardware, and other properties of a system, which doesn't give an accurate estimate of the performance of an algorithm. Hence, we employ Basic Count.
2. Basic count:  It is the number of times the most crucial, resource-heavy part of the algorithm (Basic Operation) is executed. This gives a more accurate estimate of the performance of the algorithms with the help of asymptotic notations.

### Space and Time Efficiency
Time efficiency: The time that an algorithm takes to run considering input. It is directly related to Basic Operation and Basic count.
Space efficiency: The extra space that an algorithm requires for the algorithm to execute considering the input. 

#### Asymptotic notations
Asymptotic Notations: Mathematical notations that describe the limiting behaviour of a function when arguments tend towards a particular value (or infinity). 
We borrow the notations of Omega (Ω), Theta(𝜭) and Big-Oh (O) to describe the best, average and worst cases of performance of an algorithm. These 3 notations satisfactorily describe the efficiency of an algorithm in terms of orders of growth. 

#### Orders of Growth:
Orders of Growth classify the algorithms on the output of their efficiency judged by the asymptotic notation.
Below is a list of the most common orders of growth: 
- O(1): Constant Time
- O(log n): Logarithmic Time
- O(n): Linear Time
- O(n log n): Linearithmic Time
- O(n²): Quadratic Time
- O(n³): Cubic Time
- O(2ⁿ): Exponential Time
- O(n!): Factorial Time


## Design Principles
Design principles are a set of guidelines that form the basis of intuition for a problem-solver. In this unit, we discussed 20 design principles. Correlating solutions to design principles facilitates collaboration (as design principles are standard) and thoroughly exploring a solution space.

Design principles are as follows: 
1. Decomposition: Breaking down a large problem into sub-problems and then focusing on each subproblem. Makes it easier to tackle the problem instead as a whole.
2. Pattern Recognition: Pattern recognition helps in generalization and predictions, finding the common element across the problem can help optimize the solution.
3. Abstraction: Ignoring irrelevant details. Keeping the essential bits focuses and gives weights to different parts of the problem.
4. Brave and Cautious Travel: 2 methods to travel a structure that involves multiple choices at a node.
5. Pruning: The process of eliminating unnecessary or irrelevant parts of a problem or data set to improve efficiency. If a trial doesn't meet the constraints required by the solution, pruning it allows efficient use of resources.
6. Lazy Propagation / Evaluation: Lazy propagation, a performance optimization technique for segment trees and related
  data structures, efficiently handles range queries and updates. It also helps efficient use of a system's resources.
7. Sliding Window: Similar to abstraction and decomposition, it helps us work in a small view of the entire problem, and then 'slide' that view over the whole data.
8. Level Order Traversal: Systematic method of creating the nodes of a tree. It is a standard. 
9. Hierarchical Data: A data set with a hierarchical relationship between elements, usually represented using trees.
10. Edge Relaxation: Edge relaxation is a systematic approach to build a solution, when we relax an edge, it becomes part of the solution. 
11. Balancing and Rotations
12. Kleene Closure
13. Pre-Computing
14. Parental Dominance
15. Prefix and Suffix
16. Partitioning
17. Bit Manipulations
18. Memoization
19. Invariants
20. Shortest Path Trees

## Heirarchical Data
Hierarchical data is a type of data structure that represents information in a tree-like structure, where each element has a parent and can have multiple children.
Some data such as family trees, Web pages, and classification systems can be naturally represented in this form. 

### Nary Trees
Naray trees dictate that hierarchical data has a level order traversal design and each parent node as at most 'n' children. example, Binary trees.

### Binary Search Trees
Binary Search Trees expands on binary trees but brings in the concept of binary search. Binary Search Tree operates with a constraint that the left child of a node is smaller than the parent and the right child of a node is larger than the parent. This helps arrange the data beautifully (which results in sorting the data when traversing the BST inorder).
However, depending on the input, BSTs can become skewed, which affects the efficiency of operations performed on the tree.
To counter it, several measures can be taken
### 2-3 Trees
2-3 Trees counter the possibility of skew, by introducing more than one element in a node and promoting(converting) certain siblings to be parent nodes. However, this can be complex to implement and it does not remove the possibility of skew entirely. 

### AVL Trees
using the principles of balancing and rotations, we balance(reduce the skew in) BSTs. Although, this method efficiently countered the problem of skew, some redundant rotations could be avoided. We then go for Red-Black Trees.

### Red-Black Trees
Red-Black trees are not as rigid when balancing as compared to AVL trees, but they are faster when performing insertion/deletion operations on the nodes. 

### Other ways to represent hierarchical data
1. **Trie**: Trie is derived from the word 'retrieval' and trades (consuming less)space for faster look-up. This is used in submission throttling, word prediction, etc.
2. **Heap**: Heap is a binary tree that fulfils the conditions of tree shape, and parental dominance. Once built, it can operate in log(n) efficiency. 

## Array Queries
Array queries  enable efficient manipulation, searching, sorting, and traversal of huge data stored as arrays.  Efficient array query algorithms can reduce the time and space complexities associated with data manipulation, making them essential for applications that require fast and efficient data processing. For example, finding minimum/maximum/sum of a range in an array. This is similar to filters/sort-by functions on e-commerce websites.
### Look-up table 
Matrix representation of data. Works well on small static data. precomputes the result of an expected query across a range. it's based on the principle of sliding window. 

### Segment Trees
Segment trees are built bottom but the queries are handled top-down. Works well with larger dynamic data. It's based on the principle of hierarchical data.

### Fenwick Trees (BIT)
Binary Indexed Trees, or Fenwick Trees, works on bit manipulation and performs range queries and updates efficiently. They are simpler to build compared to segment trees.

### Sparse Table
Sparse tables incorporate the ideas of range-overlapping in segment trees and the '2' obsession of Fenwick trees which results in faster updations. Unlike segment trees which computes result of every range size, sparse table computes for every range of power-of-two elements. 

## Graphs
Graphs are defined by vertices and edges. They can also be crudely called cyclic trees. Traversal on graphs hence becoems difficult compared to trees due to existing cycles. 
Graphs can be represented as a Matrix called an Adjacency Matrix or a Linked List called an Adjacency Linked List, depending on the density of the graph. Density of a graph is determined by the number of edges per vertice.
BFS(Cautious travel) and DFS(Brave travel) can be applied on graphs as on trees, by storing the visited nodes separately (possibly in an array).

## Sorting
Sorting fulfils the human tendency of putting things in order. Sorted data is very useful. There are many techniques to sort

### Brute-force approach
The Brute force approach to sorting yeilds **bubble sort** and **selection sort**, both with an efficiency of O(n). 

### Divide-and-Conquer
The divide and conquer approach gives rise to **Merge sort**. Merge sort divdes data to its atomic bits and then puts the bits in order while merging them back. 
Efficiency: O(n log n)

One more divide and Conquer approach which incorporates binary search into a sorting algorithm yeilds **Quick Sort**. Quick sort picks an element (called 'Pivot') and divides the data into 'greater than pivot' and 'lesser than pivot' piles on either side of the pivot i.e, the pivot finds it's place. 
Efficiency: O(n log n)


### Decrease-and-Conquer
Inspired by the world of gambling and cards, **Insertion sort** can be correlated to the way a person puts in order the cards dealt to him, by inserting them in their proper places. Insertion sort works by putting atleast one element in its place in each pass, and then in the next pass it will repeat the same operatoin for one less element. 
Insertion sort works great for nearly-sorted data giving a best case efficienly analysis of Ω(n), however the worst and average cases leads to an efficency of O(n²).

### Transform-and-conquer
Using the design principle of Transform and conquer gives us **Heap sort**, which transforms the given data into a heap and then performs root deletion on the heap to obtain the sorted data. 
Efficiency: O(n log n)

## Graph Algorithms and Minimum Spanning Trees


--# algo desgin techniques
