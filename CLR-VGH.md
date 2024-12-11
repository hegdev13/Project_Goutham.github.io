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


--# design principles
--# heirarchical data - tree data structures
--# array query algorithms
--# trees and graphs
--# sorting and searching algo
--# graph algo and min span tree
--# algo desgin techniques
