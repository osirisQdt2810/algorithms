## CSES - Weird Algorithm
<div class="md"><div class="md"><p>Consider an algorithm that takes as input a positive integer <span class="math inline">n</span>. If <span class="math inline">n</span> is even, the algorithm divides it by two, and if <span class="math inline">n</span> is odd, the algorithm multiplies it by three and adds one. The algorithm repeats this, until <span class="math inline">n</span> is one. For example, the sequence for <span class="math inline">n=3</span> is as follows:
<span class="math display"> 3 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1</span>
Your task is to simulate the execution of the algorithm for a given value of <span class="math inline">n</span>.</p>
<h1 id="input">Input</h1>
<p>The only input line contains an integer <span class="math inline">n</span>.</p>
<h1 id="output">Output</h1>
<p>Print a line that contains all values of <span class="math inline">n</span> during the algorithm.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 10^6</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>3
</pre>
<p>Output:</p>
<pre>3 10 5 16 8 4 2 1
</pre></div></div>

## CSES - Missing Number
<div class="md"><div class="md"><p>You are given all numbers between <span class="math inline">1,2,...,n</span> except one. Your task is to find the missing number.</p>
<h1 id="input">Input</h1>
<p>The first input line contains an integer <span class="math inline">n</span>.</p>
<p>The second line contains <span class="math inline">n-1</span> numbers. Each number is distinct and between <span class="math inline">1</span> and <span class="math inline">n</span> (inclusive).</p>
<h1 id="output">Output</h1>
<p>Print the missing number.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">2 <= n <= 2 . 10^5</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5
2 3 1 5
</pre>
<p>Output:</p>
<pre>4
</pre></div></div>

## CSES - Repetitions
<div class="md"><div class="md"><p>You are given a DNA sequence: a string consisting of characters A, C, G, and T. Your task is to find the longest repetition in the sequence. This is a maximum-length substring containing only one type of character.</p>
<h1 id="input">Input</h1>
<p>The only input line contains a string of <span class="math inline">n</span> characters.</p>
<h1 id="output">Output</h1>
<p>Print one integer: the length of the longest repetition.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 10^6</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>ATTCGGGA
</pre>
<p>Output:</p>
<pre>3
</pre></div></div>

## CSES - Increasing Array
<div class="md"><div class="md"><p>You are given an array of <span class="math inline">n</span> integers. You want to modify the array so that it is increasing, i.e., every element is at least as large as the previous element.</p>
<p>On each move, you may increase the value of any element by one. What is the minimum number of moves required?</p>
<h1 id="input">Input</h1>
<p>The first input line contains an integer <span class="math inline">n</span>: the size of the array.</p>
<p>Then, the second line contains <span class="math inline">n</span> integers <span class="math inline">x_1,x_2,...,x_n</span>: the contents of the array.</p>
<h1 id="output">Output</h1>
<p>Print the minimum number of moves.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= x_i <= 10^9</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5
3 2 5 1 7
</pre>
<p>Output:</p>
<pre>5
</pre></div></div>

## CSES - Permutations
<div class="md"><div class="md"><p>A permutation of integers <span class="math inline">1,2,...,n</span> is called <em>beautiful</em> if there are no adjacent elements whose difference is <span class="math inline">1</span>.</p>
<p>Given <span class="math inline">n</span>, construct a beautiful permutation if such a permutation exists.</p>
<h1 id="input">Input</h1>
<p>The only input line contains an integer <span class="math inline">n</span>.</p>
<h1 id="output">Output</h1>
<p>Print a beautiful permutation of integers <span class="math inline">1,2,...,n</span>. If there are several solutions, you may print any of them. If there are no solutions, print "NO SOLUTION".</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 10^6</span></li>
</ul>
<h1 id="example1">Example 1</h1>
<p>Input:</p>
<pre>5
</pre>
<p>Output:</p>
<pre>4 2 5 3 1
</pre><h1 id="example2">Example 2</h1>
<p>Input:</p>
<pre>3
</pre>
<p>Output:</p>
<pre>NO SOLUTION
</pre></div></div>

## CSES - Number Spiral
<div class="md"><div class="md"><p>A number spiral is an infinite grid whose upper-left square has number 1. Here are the first five layers of the spiral:
<center><img alt="" class="invertible" src="/file/bba36f2601b99c7edc15865aa2a49e680a271075f30e86aa0e4e18d00a779c21"/></center>
Your task is to find out the number in row <span class="math inline">y</span> and column <span class="math inline">x</span>.</p>
<h1 id="input">Input</h1>
<p>The first input line contains an integer <span class="math inline">t</span>: the number of tests.</p>
<p>After this, there are <span class="math inline">t</span> lines, each containing integers <span class="math inline">y</span> and <span class="math inline">x</span>.</p>
<h1 id="output">Output</h1>
<p>For each test, print the number in row <span class="math inline">y</span> and column <span class="math inline">x</span>.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= t <= 10^5</span></li>
<li><span class="math inline">1 <= y,x <= 10^9</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>3
2 3
1 1
4 2
</pre>
<p>Output:</p>
<pre>8
1
15
</pre></div></div>

## CSES - Two Knights
<div class="md"><div class="md"><p>Your task is to count for <span class="math inline">k=1,2,...,n</span> the number of ways two knights can be placed on a <span class="math inline">k x k</span> chessboard so that they do not attack each other.</p>
<h1 id="input">Input</h1>
<p>The only input line contains an integer <span class="math inline">n</span>.</p>
<h1 id="output">Output</h1>
<p>Print <span class="math inline">n</span> integers: the results.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 10000</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>8
</pre>
<p>Output:</p>
<pre>0
6
28
96
252
550
1056
1848
</pre></div></div>

## CSES - Two Sets
<div class="md"><div class="md"><p>Your task is to divide the numbers <span class="math inline">1,2,...,n</span> into two sets of equal sum.</p>
<h1 id="input">Input</h1>
<p>The only input line contains an integer <span class="math inline">n</span>.</p>
<h1 id="output">Output</h1>
<p>Print "YES", if the division is possible, and "NO" otherwise.</p>
<p>After this, if the division is possible, print an example of how to create the sets. First, print the number of elements in the first set followed by the elements themselves in a separate line, and then, print the second set in a similar way.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 10^6</span></li>
</ul>
<h1 id="example1">Example 1</h1>
<p>Input:</p>
<pre>7
</pre>
<p>Output:</p>
<pre>YES
4
1 2 4 7
3
3 5 6
</pre><h1 id="example2">Example 2</h1>
<p>Input:</p>
<pre>6
</pre>
<p>Output:</p>
<pre>NO
</pre></div></div>

## CSES - Bit Strings
<div class="md"><div class="md"><p>Your task is to calculate the number of bit strings of length <span class="math inline">n</span>.</p>
<p>For example, if <span class="math inline">n=3</span>, the correct answer is <span class="math inline">8</span>, because the possible bit strings are 000, 001, 010, 011, 100, 101, 110, and 111.</p>
<h1 id="input">Input</h1>
<p>The only input line has an integer <span class="math inline">n</span>.</p>
<h1 id="output">Output</h1>
<p>Print the result modulo <span class="math inline">10^9+7</span>.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 10^6</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>3
</pre>
<p>Output:</p>
<pre>8
</pre></div></div>

## CSES - Trailing Zeros
<div class="md"><div class="md"><p>Your task is to calculate the number of trailing zeros in the factorial <span class="math inline">n!</span>.</p>
<p>For example, <span class="math inline">20!=2432902008176640000</span> and it has <span class="math inline">4</span> trailing zeros.</p>
<h1 id="input">Input</h1>
<p>The only input line has an integer <span class="math inline">n</span>.</p>
<h1 id="output">Output</h1>
<p>Print the number of trailing zeros in <span class="math inline">n!</span>.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 10^9</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>20
</pre>
<p>Output:</p>
<pre>4
</pre></div></div>

## CSES - Coin Piles
<div class="md"><div class="md"><p>You have two coin piles containing <span class="math inline">a</span> and <span class="math inline">b</span> coins. On each move, you can either remove one coin from the left pile and two coins from the right pile, or two coins from the left pile and one coin from the right pile.</p>
<p>Your task is to efficiently find out if you can empty both the piles.</p>
<h1 id="input">Input</h1>
<p>The first input line has an integer <span class="math inline">t</span>: the number of tests.</p>
<p>After this, there are <span class="math inline">t</span> lines, each of which has two integers <span class="math inline">a</span> and <span class="math inline">b</span>: the numbers of coins in the piles.</p>
<h1 id="output">Output</h1>
<p>For each test, print "YES" if you can empty the piles and "NO" otherwise.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= t <= 10^5</span></li>
<li><span class="math inline">0 <= a, b <= 10^9</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>3
2 1
2 2
3 3
</pre>
<p>Output:</p>
<pre>YES
NO
YES
</pre></div></div>

## CSES - Palindrome Reorder
<div class="md"><div class="md"><p>Given a string, your task is to reorder its letters in such a way that it becomes a palindrome (i.e., it reads the same forwards and backwards).</p>
<h1 id="input">Input</h1>
<p>The only input line has a string of length <span class="math inline">n</span> consisting of characters A–Z.</p>
<h1 id="output">Output</h1>
<p>Print a palindrome consisting of the characters of the original string. You may print any valid solution. If there are no solutions, print "NO SOLUTION".</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 10^6</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>AAAACACBA
</pre>
<p>Output:</p>
<pre>AACABACAA
</pre></div></div>

## CSES - Gray Code
<div class="md"><div class="md"><p>A Gray code is a list of all <span class="math inline">2^n</span> bit strings of length <span class="math inline">n</span>, where any two successive strings differ in exactly one bit (i.e., their Hamming distance is one).</p>
<p>Your task is to create a Gray code for a given length <span class="math inline">n</span>.</p>
<h1 id="input">Input</h1>
<p>The only input line has an integer <span class="math inline">n</span>.</p>
<h1 id="output">Output</h1>
<p>Print <span class="math inline">2^n</span> lines that describe the Gray code. You can print any valid solution.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 16</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>2
</pre>
<p>Output:</p>
<pre>00
01
11
10
</pre></div></div>

## CSES - Tower of Hanoi
<div class="md"><div class="md"><p>The Tower of Hanoi game consists of three stacks (left, middle and right) and <span class="math inline">n</span> round disks of different sizes. Initially, the left stack has all the disks, in increasing order of size from top to bottom. </p>
<p>The goal is to move all the disks to the right stack using the middle stack. On each move you can move the uppermost disk from a stack to another stack. In addition, it is not allowed to place a larger disk on a smaller disk.</p>
<p>Your task is to find a solution that minimizes the number of moves.</p>
<h1 id="input">Input</h1>
<p>The only input line has an integer <span class="math inline">n</span>: the number of disks.</p>
<h1 id="output">Output</h1>
<p>First print an integer <span class="math inline">k</span>: the minimum number of moves.</p>
<p>After this, print <span class="math inline">k</span> lines that describe the moves. Each line has two integers <span class="math inline">a</span> and <span class="math inline">b</span>: you move a disk from stack <span class="math inline">a</span> to stack <span class="math inline">b</span>.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 16</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>2
</pre>
<p>Output:</p>
<pre>3
1 2
1 3
2 3
</pre></div></div>

## CSES - Creating Strings
<div class="md"><div class="md"><p>Given a string, your task is to generate all different strings that can be created using its characters.</p>
<h1 id="input">Input</h1>
<p>The only input line has a string of length <span class="math inline">n</span>. Each character is between a–z.</p>
<h1 id="output">Output</h1>
<p>First print an integer <span class="math inline">k</span>: the number of strings. Then print <span class="math inline">k</span> lines: the strings in alphabetical order.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 8</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>aabac
</pre>
<p>Output:</p>
<pre>20
aaabc
aaacb
aabac
aabca
aacab
aacba
abaac
abaca
abcaa
acaab
acaba
acbaa
baaac
baaca
bacaa
bcaaa
caaab
caaba
cabaa
cbaaa
</pre></div></div>

## CSES - Apple Division
<div class="md"><div class="md"><p>There are <span class="math inline">n</span> apples with known weights. Your task is to divide the apples into two groups so that the difference between the weights of the groups is minimal.</p>
<h1 id="input">Input</h1>
<p>The first input line has an integer <span class="math inline">n</span>: the number of apples.</p>
<p>The next line has <span class="math inline">n</span> integers <span class="math inline">p_1,p_2,\dots,p_n</span>: the weight of each apple.</p>
<h1 id="output">Output</h1>
<p>Print one integer: the minimum difference between the weights of the groups.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 20</span></li>
<li><span class="math inline">1 <= p_i <= 10^9</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5
3 2 7 4 1
</pre>
<p>Output:</p>
<pre>1
</pre>
<p>Explanation: Group 1 has weights 2, 3 and 4 (total weight 9), and group 2 has weights 1 and 7 (total weight 8).</p>
</div></div>

## CSES - Chessboard and Queens
<div class="md"><div class="md"><p>Your task is to place eight queens on a chessboard so that no two queens are attacking each other. As an additional challenge, each square is either free or reserved, and you can only place queens on the free squares. However, the reserved squares do not prevent queens from attacking each other.</p>
<p>How many possible ways are there to place the queens?</p>
<h1 id="input">Input</h1>
<p>The input has eight lines, and each of them has eight characters. Each square is either free (<code>.</code>) or reserved (<code>*</code>).</p>
<h1 id="output">Output</h1>
<p>Print one integer: the number of ways you can place the queens.</p>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>........
........
..*.....
........
........
.....**.
...*....
........
</pre>
<p>Output:</p>
<pre>65
</pre></div></div>

## CSES - Digit Queries
<div class="md"><div class="md"><p>Consider an infinite string that consists of all positive integers in increasing order:</p>
<pre>12345678910111213141516171819202122232425...
</pre>
<p>Your task is to process <span class="math inline">q</span> queries of the form: what is the digit at position <span class="math inline">k</span> in the string?</p>
<h1 id="input">Input</h1>
<p>The first input line has an integer <span class="math inline">q</span>: the number of queries.</p>
<p>After this, there are <span class="math inline">q</span> lines that describe the queries. Each line has an integer <span class="math inline">k</span>: a <span class="math inline">1</span>-indexed position in the string.</p>
<h1 id="output">Output</h1>
<p>For each query, print the corresponding digit.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= q <= 1000</span></li>
<li><span class="math inline">1 <= k <= 10^{18}</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>3
7
19
12
</pre>
<p>Output:</p>
<pre>7
4
1
</pre></div></div>

## CSES - Grid Paths
<div class="md"><div class="md"><p>There are <span class="math inline">88418</span> paths in a <span class="math inline">7 x 7</span> grid from the upper-left square to the lower-left square. Each path corresponds to a <span class="math inline">48</span>-character description consisting of characters <code>D</code> (down), <code>U</code> (up), <code>L</code> (left) and <code>R</code> (right).</p>
<p>For example, the path
<center><img alt="" class="invertible" src="/file/3624b569007eb03818b6611755f1bdbe4cdbd0a8334baf9fedc5365914bdd661"/></center>
corresponds to the description <code>DRURRRRRDDDLUULDDDLDRRURDDLLLLLURULURRUULDLLDDDD</code>.</p>
<p>You are given a description of a path which may also contain characters <code>?</code> (any direction). Your task is to calculate the number of paths that match the description.</p>
<h1 id="input">Input</h1>
<p>The only input line has a <span class="math inline">48</span>-character string of characters <code>?</code>, <code>D</code>, <code>U</code>, <code>L</code> and <code>R</code>.</p>
<h1 id="output">Output</h1>
<p>Print one integer: the total number of paths.</p>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>??????R??????U??????????????????????????LD????D?
</pre>
<p>Output:</p>
<pre>201
</pre></div></div>

## CSES - Distinct Numbers
<div class="md"><div class="md"><p>You are given a list of <span class="math inline">n</span> integers, and your task is to calculate the number of <em>distinct</em> values in the list.</p>
<h1 id="input">Input</h1>
<p>The first input line has an integer <span class="math inline">n</span>: the number of values.</p>
<p>The second line has <span class="math inline">n</span> integers <span class="math inline">x_1,x_2,\dots,x_n</span>.</p>
<h1 id="output">Output</h1>
<p>Print one integers: the number of distinct values.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= x_i <= 10^9</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5
2 3 2 2 3
</pre>
<p>Output:</p>
<pre>2
</pre></div></div>

## CSES - Apartments
<div class="md"><div class="md"><p>There are <span class="math inline">n</span> applicants and <span class="math inline">m</span> free apartments. Your task is to distribute the apartments so that as many applicants as possible will get an apartment.</p>
<p>Each applicant has a desired apartment size, and they will accept any apartment whose size is close enough to the desired size.</p>
<h1 id="input">Input</h1>
<p>The first input line has three integers <span class="math inline">n</span>, <span class="math inline">m</span>, and <span class="math inline">k</span>: the number of applicants, the number of apartments, and the maximum allowed difference.</p>
<p>The next line contains <span class="math inline">n</span> integers <span class="math inline">a_1, a_2, ..., a_n</span>: the desired apartment size of each applicant. If the desired size of an applicant is <span class="math inline">x</span>, he or she will accept any apartment whose size is between <span class="math inline">x-k</span> and <span class="math inline">x+k</span>.</p>
<p>The last line contains <span class="math inline">m</span> integers <span class="math inline">b_1, b_2, ..., b_m</span>: the size of each apartment.</p>
<h1 id="output">Output</h1>
<p>Print one integer: the number of applicants who will get an apartment.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n, m <= 2 . 10^5</span></li>
<li><span class="math inline">0 <= k <= 10^9</span></li>
<li><span class="math inline">1 <= a_i, b_i <= 10^9</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>4 3 5
60 45 80 60
30 60 75
</pre>
<p>Output:</p>
<pre>2
</pre></div></div>

## CSES - Ferris Wheel
<div class="md"><div class="md"><p>There are <span class="math inline">n</span> children who want to go to a Ferris wheel, and your task is to find a gondola for each child.</p>
<p>Each gondola may have one or two children in it, and in addition, the total weight in a gondola may not exceed <span class="math inline">x</span>. You know the weight of every child.</p>
<p>What is the minimum number of gondolas needed for the children?</p>
<h1 id="input">Input</h1>
<p>The first input line contains two integers <span class="math inline">n</span> and <span class="math inline">x</span>: the number of children and the maximum allowed weight.</p>
<p>The next line contains <span class="math inline">n</span> integers <span class="math inline">p_1,p_2,...,p_n</span>: the weight of each child.</p>
<h1 id="output">Output</h1>
<p>Print one integer: the minimum number of gondolas.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= x <= 10^9</span></li>
<li><span class="math inline">1 <= p_i <= x</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>4 10
7 2 3 9
</pre>
<p>Output:</p>
<pre>3
</pre></div></div>

## CSES - Concert Tickets
<div class="md"><div class="md"><p>There are <span class="math inline">n</span> concert tickets available, each with a certain price. Then, <span class="math inline">m</span> customers arrive, one after another.</p>
<p>Each customer announces the maximum price they are willing to pay for a ticket, and after this, they will get a ticket with the nearest possible price such that it does not exceed the maximum price.</p>
<h1 id="input">Input</h1>
<p>The first input line contains integers <span class="math inline">n</span> and <span class="math inline">m</span>: the number of tickets and the number of customers.</p>
<p>The next line contains <span class="math inline">n</span> integers <span class="math inline">h_1,h_2,...,h_n</span>: the price of each ticket.</p>
<p>The last line contains <span class="math inline">m</span> integers <span class="math inline">t_1,t_2,...,t_m</span>: the maximum price for each customer in the order they arrive.</p>
<h1 id="output">Output</h1>
<p>Print, for each customer, the price that they will pay for their ticket. After this, the ticket cannot be purchased again.</p>
<p>If a customer cannot get any ticket, print <span class="math inline">-1</span>.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n, m <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= h_i, t_i <= 10^9</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5 3
5 3 7 8 5
4 8 3
</pre>
<p>Output:</p>
<pre>3
8
-1
</pre></div></div>

## CSES - Restaurant Customers
<div class="md"><div class="md"><p>You are given the arrival and leaving times of <span class="math inline">n</span> customers in a restaurant.</p>
<p>What was the maximum number of customers in the restaurant at any time?</p>
<h1 id="input">Input</h1>
<p>The first input line has an integer <span class="math inline">n</span>: the number of customers.</p>
<p>After this, there are <span class="math inline">n</span> lines that describe the customers. Each line has two integers <span class="math inline">a</span> and <span class="math inline">b</span>: the arrival and leaving times of a customer.</p>
<p>You may assume that all arrival and leaving times are distinct.</p>
<h1 id="output">Output</h1>
<p>Print one integer: the maximum number of customers.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= a &lt; b <= 10^9</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>3
5 8
2 4
3 9
</pre>
<p>Output:</p>
<pre>2
</pre></div></div>

## CSES - Movie Festival
<div class="md"><div class="md"><p>In a movie festival <span class="math inline">n</span> movies will be shown. You know the starting and ending time of each movie. What is the maximum number of movies you can watch entirely?</p>
<h1 id="input">Input</h1>
<p>The first input line has an integer <span class="math inline">n</span>: the number of movies.</p>
<p>After this, there are <span class="math inline">n</span> lines that describe the movies. Each line has two integers <span class="math inline">a</span> and <span class="math inline">b</span>: the starting and ending times of a movie.</p>
<h1 id="output">Output</h1>
<p>Print one integer: the maximum number of movies.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= a &lt; b <= 10^9</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>3
3 5
4 9
5 8
</pre>
<p>Output:</p>
<pre>2
</pre></div></div>

## CSES - Sum of Two Values
<div class="md"><div class="md"><p>You are given an array of <span class="math inline">n</span> integers, and your task is to find two values (at distinct positions) whose sum is <span class="math inline">x</span>.</p>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">n</span> and <span class="math inline">x</span>: the array size and the target sum.</p>
<p>The second line has <span class="math inline">n</span> integers <span class="math inline">a_1,a_2,\dots,a_n</span>: the array values.</p>
<h1 id="output">Output</h1>
<p>Print two integers: the positions of the values. If there are several solutions, you may print any of them. If there are no solutions, print <code>IMPOSSIBLE</code>.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= x,a_i <= 10^9</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>4 8
2 7 5 1
</pre>
<p>Output:</p>
<pre>2 4
</pre></div></div>

## CSES - Maximum Subarray Sum
<div class="md"><div class="md"><p>Given an array of <span class="math inline">n</span> integers, your task is to find the maximum sum of values in a contiguous, nonempty subarray.</p>
<h1 id="input">Input</h1>
<p>The first input line has an integer <span class="math inline">n</span>: the size of the array.</p>
<p>The second line has <span class="math inline">n</span> integers <span class="math inline">x_1,x_2,\dots,x_n</span>: the array values.</p>
<h1 id="output">Output</h1>
<p>Print one integer: the maximum subarray sum.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 2 . 10^5</span></li>
<li><span class="math inline">-10^9 <= x_i <= 10^9</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>8
-1 3 -2 5 3 -5 2 2
</pre>
<p>Output:</p>
<pre>9
</pre></div></div>

## CSES - Stick Lengths
<div class="md"><div class="md"><p>There are <span class="math inline">n</span> sticks with some lengths. Your task is to modify the sticks so that each stick has the same length.</p>
<p>You can either lengthen and shorten each stick. Both operations cost <span class="math inline">x</span> where <span class="math inline">x</span> is the difference between the new and original length.</p>
<p>What is the minimum total cost?</p>
<h1 id="input">Input</h1>
<p>The first input line contains an integer <span class="math inline">n</span>: the number of sticks.</p>
<p>Then there are <span class="math inline">n</span> integers: <span class="math inline">p_1,p_2,...,p_n</span>: the lengths of the sticks.</p>
<h1 id="output">Output</h1>
<p>Print one integer: the minimum total cost.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= p_i <= 10^9</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5
2 3 1 5 2
</pre>
<p>Output:</p>
<pre>5
</pre></div></div>

## CSES - Missing Coin Sum
<div class="md"><div class="md"><p>You have <span class="math inline">n</span> coins with positive integer values. What is the smallest sum you cannot create using a subset of the coins?</p>
<h1 id="input">Input</h1>
<p>The first input line has an integer <span class="math inline">n</span>: the number of coins.</p>
<p>The second line has <span class="math inline">n</span> integers <span class="math inline">x_1,x_2,\dots,x_n</span>: the value of each coin.</p>
<h1 id="output">Output</h1>
<p>Print one integer: the smallest coin sum.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= x_i <= 10^9</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5
2 9 1 2 7
</pre>
<p>Output:</p>
<pre>6
</pre></div></div>

## CSES - Collecting Numbers
<div class="md"><div class="md"><p>You are given an array that contains each number between <span class="math inline">1 \dots n</span> exactly once. Your task is to collect the numbers from <span class="math inline">1</span> to <span class="math inline">n</span> in increasing order.</p>
<p>On each round, you go through the array from left to right and collect as many numbers as possible. What will be the total number of rounds?</p>
<h1 id="input">Input</h1>
<p>The first line has an integer <span class="math inline">n</span>: the array size.</p>
<p>The next line has <span class="math inline">n</span> integers <span class="math inline">x_1,x_2,\dots,x_n</span>: the numbers in the array.</p>
<h1 id="output">Output</h1>
<p>Print one integer: the number of rounds.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 2 . 10^5</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5
4 2 1 5 3
</pre>
<p>Output:</p>
<pre>3
</pre></div></div>

## CSES - Collecting Numbers II
<div class="md"><div class="md"><p>You are given an array that contains each number between <span class="math inline">1 \dots n</span> exactly once. Your task is to collect the numbers from <span class="math inline">1</span> to <span class="math inline">n</span> in increasing order.</p>
<p>On each round, you go through the array from left to right and collect as many numbers as possible.</p>
<p>Given <span class="math inline">m</span> operations that swap two numbers in the array, your task is to report the number of rounds after each operation.</p>
<h1 id="input">Input</h1>
<p>The first line has two integers <span class="math inline">n</span> and <span class="math inline">m</span>: the array size and the number of operations.</p>
<p>The next line has <span class="math inline">n</span> integers <span class="math inline">x_1,x_2,\dots,x_n</span>: the numbers in the array.</p>
<p>Finally, there are <span class="math inline">m</span> lines that describe the operations. Each line has two integers <span class="math inline">a</span> and <span class="math inline">b</span>: the numbers at positions <span class="math inline">a</span> and <span class="math inline">b</span> are swapped.</p>
<h1 id="output">Output</h1>
<p>Print <span class="math inline">m</span> integers: the number of rounds after each swap.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n, m <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= a,b <= n</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5 3
4 2 1 5 3
2 3
1 5
2 3
</pre>
<p>Output:</p>
<pre>2
3
4
</pre></div></div>

## CSES - Playlist
<div class="md"><div class="md"><p>You are given a playlist of a radio station since its establishment. The playlist has a total of <span class="math inline">n</span> songs.</p>
<p>What is the longest sequence of successive songs where each song is unique?</p>
<h1 id="input">Input</h1>
<p>The first input line contains an integer <span class="math inline">n</span>: the number of songs.</p>
<p>The next line has <span class="math inline">n</span> integers <span class="math inline">k_1,k_2,...,k_n</span>: the id number of each song.</p>
<h1 id="output">Output</h1>
<p>Print the length of the longest sequence of unique songs.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= k_i <= 10^9</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>8
1 2 1 3 2 7 4 2
</pre>
<p>Output:</p>
<pre>5
</pre></div></div>

## CSES - Towers
<div class="md"><div class="md"><p>You are given <span class="math inline">n</span> cubes in a certain order, and your task is to build towers using them. Whenever two cubes are one on top of the other, the upper cube must be smaller than the lower cube.</p>
<p>You must process the cubes in the given order. You can always either place the cube on top of an existing tower, or begin a new tower. What is the minimum possible number of towers?</p>
<h1 id="input">Input</h1>
<p>The first input line contains an integer <span class="math inline">n</span>: the number of cubes.</p>
<p>The next line contains <span class="math inline">n</span> integers <span class="math inline">k_1,k_2,...,k_n</span>: the sizes of the cubes.</p>
<h1 id="output">Output</h1>
<p>Print one integer: the minimum number of towers.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= k_i <= 10^9</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5
3 8 2 1 5
</pre>
<p>Output:</p>
<pre>2
</pre></div></div>

## CSES - Traffic Lights
<div class="md"><div class="md"><p>There is a street of length <span class="math inline">x</span> whose positions are numbered <span class="math inline">0,1,...,x</span>. Initially there are no traffic lights, but <span class="math inline">n</span> sets of traffic lights are added to the street one after another.</p>
<p>Your task is to calculate the length of the longest passage without traffic lights after each addition.</p>
<h1 id="input">Input</h1>
<p>The first input line contains two integers <span class="math inline">x</span> and <span class="math inline">n</span>: the length of the street and the number of sets of traffic lights.</p>
<p>Then, the next line contains <span class="math inline">n</span> integers <span class="math inline">p_1,p_2,...,p_n</span>: the position of each set of traffic lights. Each position is distinct.</p>
<h1 id="output">Output</h1>
<p>Print the length of the longest passage without traffic lights after each addition.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= x <= 10^9</span></li>
<li><span class="math inline">1 <= n <= 2 . 10^5</span></li>
<li><span class="math inline">0 &lt; p_i &lt; x</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>8 3
3 6 2
</pre>
<p>Output:</p>
<pre>5 3 3
</pre></div></div>

## CSES - Josephus Problem I
<div class="md"><div class="md"><p>Consider a game where there are <span class="math inline">n</span> children (numbered <span class="math inline">1,2,\dots,n</span>) in a circle. During the game, every other child is removed from the circle until there are no children left. In which order will the children be removed?</p>
<h1 id="input">Input</h1>
<p>The only input line has an integer <span class="math inline">n</span>.</p>
<h1 id="output">Output</h1>
<p>Print <span class="math inline">n</span> integers: the removal order.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 2 . 10^5</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>7
</pre>
<p>Output:</p>
<pre>2 4 6 1 5 3 7
</pre></div></div>

## CSES - Josephus Problem II
<div class="md"><div class="md"><p>Consider a game where there are <span class="math inline">n</span> children (numbered <span class="math inline">1,2,\dots,n</span>) in a circle. During the game, repeatedly <span class="math inline">k</span> children are skipped and one child is removed from the circle. In which order will the children be removed?</p>
<h1 id="input">Input</h1>
<p>The only input line has two integers <span class="math inline">n</span> and <span class="math inline">k</span>.</p>
<h1 id="output">Output</h1>
<p>Print <span class="math inline">n</span> integers: the removal order.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 2 . 10^5</span></li>
<li><span class="math inline">0 <= k <= 10^9</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>7 2
</pre>
<p>Output:</p>
<pre>3 6 2 7 5 1 4
</pre></div></div>

## CSES - Nested Ranges Check
<div class="md"><div class="md"><p>Given <span class="math inline">n</span> ranges, your task is to determine for each range if it contains some other range and if some other range contains it.</p>
<p>Range <span class="math inline">[a,b]</span> contains range <span class="math inline">[c,d]</span> if <span class="math inline">a <= c</span> and <span class="math inline">d <= b</span>.</p>
<h1 id="input">Input</h1>
<p>The first input line has an integer <span class="math inline">n</span>: the number of ranges.</p>
<p>After this, there are <span class="math inline">n</span> lines that describe the ranges. Each line has two integers <span class="math inline">x</span> and <span class="math inline">y</span>: the range is <span class="math inline">[x,y]</span>.</p>
<p>You may assume that no range appears more than once in the input.</p>
<h1 id="output">Output</h1>
<p>First print a line that describes for each range (in the input order) if it contains some other range (1) or not (0).</p>
<p>Then print a line that describes for each range (in the input order) if some other range contains it (1) or not (0).</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= x &lt; y <= 10^9</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>4
1 6
2 4
4 8
3 6
</pre>
<p>Output:</p>
<pre>1 0 0 0
0 1 0 1
</pre></div></div>

## CSES - Nested Ranges Count
<div class="md"><div class="md"><p>Given <span class="math inline">n</span> ranges, your task is to count for each range how many other ranges it contains and how many other ranges contain it.</p>
<p>Range <span class="math inline">[a,b]</span> contains range <span class="math inline">[c,d]</span> if <span class="math inline">a <= c</span> and <span class="math inline">d <= b</span>.</p>
<h1 id="input">Input</h1>
<p>The first input line has an integer <span class="math inline">n</span>: the number of ranges.</p>
<p>After this, there are <span class="math inline">n</span> lines that describe the ranges. Each line has two integers <span class="math inline">x</span> and <span class="math inline">y</span>: the range is <span class="math inline">[x,y]</span>.</p>
<p>You may assume that no range appears more than once in the input.</p>
<h1 id="output">Output</h1>
<p>First print a line that describes for each range (in the input order) how many other ranges it contains.</p>
<p>Then print a line that describes for each range (in the input order) how many other ranges contain it.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= x &lt; y <= 10^9</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>4
1 6
2 4
4 8
3 6
</pre>
<p>Output:</p>
<pre>2 0 0 0
0 1 0 1
</pre></div></div>

## CSES - Room Allocation
<div class="md"><div class="md"><p>There is a large hotel, and <span class="math inline">n</span> customers will arrive soon. Each customer wants to have a single room.</p>
<p>You know each customer's arrival and departure day. Two customers can stay in the same room if the departure day of the first customer is earlier than the arrival day of the second customer.</p>
<p>What is the minimum number of rooms that are needed to accommodate all customers? And how can the rooms be allocated?</p>
<h1 id="input">Input</h1>
<p>The first input line contains an integer <span class="math inline">n</span>: the number of customers.</p>
<p>Then there are <span class="math inline">n</span> lines, each of which describes one customer. Each line has two integers <span class="math inline">a</span> and <span class="math inline">b</span>: the arrival and departure day.</p>
<h1 id="output">Output</h1>
<p>Print first an integer <span class="math inline">k</span>: the minimum number of rooms required.</p>
<p>After that, print a line that contains the room number of each customer in the same order as in the input. The rooms are numbered <span class="math inline">1,2,...,k</span>. You can print any valid solution.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= a <= b <= 10^9</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>3
1 2
2 4
4 4
</pre>
<p>Output:</p>
<pre>2
1 2 1
</pre></div></div>

## CSES - Factory Machines
<div class="md"><div class="md"><p>A factory has <span class="math inline">n</span> machines which can be used to make products. Your goal is to make a total of <span class="math inline">t</span> products.</p>
<p>For each machine, you know the number of seconds it needs to make a single product. The machines can work simultaneously, and you can freely decide their schedule.</p>
<p>What is the shortest time needed to make <span class="math inline">t</span> products?</p>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">n</span> and <span class="math inline">t</span>: the number of machines and products.</p>
<p>The next line has <span class="math inline">n</span> integers <span class="math inline">k_1,k_2,\dots,k_n</span>: the time needed to make a product using each machine.</p>
<h1 id="output">Output</h1>
<p>Print one integer: the minimum time needed to make <span class="math inline">t</span> products.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= t <= 10^9</span></li>
<li><span class="math inline">1 <= k_i <= 10^9</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>3 7
3 2 5
</pre>
<p>Output:</p>
<pre>8
</pre>
<p>Explanation: Machine 1 makes two products, machine 2 makes four products and machine 3 makes one product.</p>
</div></div>

## CSES - Tasks and Deadlines
<div class="md"><div class="md"><p>You have to process <span class="math inline">n</span> tasks. Each task has a duration and a deadline, and you will process the tasks in some order one after another. Your reward for a task is <span class="math inline">d-f</span> where <span class="math inline">d</span> is its deadline and <span class="math inline">f</span> is your finishing time. (The starting time is <span class="math inline">0</span>, and you have to process all tasks even if a task would yield negative reward.)</p>
<p>What is your maximum reward if you act optimally?</p>
<h1 id="input">Input</h1>
<p>The first input line has an integer <span class="math inline">n</span>: the number of tasks.</p>
<p>After this, there are <span class="math inline">n</span> lines that describe the tasks. Each line has two integers <span class="math inline">a</span> and <span class="math inline">d</span>: the duration and deadline of the task.</p>
<h1 id="output">Output</h1>
<p>Print one integer: the maximum reward.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= a,d <= 10^6</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>3
6 10
8 15
5 12
</pre>
<p>Output:</p>
<pre>2
</pre></div></div>

## CSES - Reading Books
<div class="md"><div class="md"><p>There are <span class="math inline">n</span> books, and Kotivalo and Justiina are going to read them all. For each book, you know the time it takes to read it.</p>
<p>They both read each book from beginning to end, and they cannot read a book at the same time. What is the minimum total time required?</p>
<h1 id="input">Input</h1>
<p>The first input line has an integer <span class="math inline">n</span>: the number of books.</p>
<p>The second line has <span class="math inline">n</span> integers <span class="math inline">t_1,t_2,\dots,t_n</span>: the time required to read each book.</p>
<h1 id="output">Output</h1>
<p>Print one integer: the minimum total time.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= t_i <= 10^9</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>3
2 8 3
</pre>
<p>Output:</p>
<pre>16
</pre></div></div>

## CSES - Sum of Three Values
<div class="md"><div class="md"><p>You are given an array of <span class="math inline">n</span> integers, and your task is to find three values (at distinct positions) whose sum is <span class="math inline">x</span>.</p>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">n</span> and <span class="math inline">x</span>: the array size and the target sum.</p>
<p>The second line has <span class="math inline">n</span> integers <span class="math inline">a_1,a_2,\dots,a_n</span>: the array values.</p>
<h1 id="output">Output</h1>
<p>Print three integers: the positions of the values. If there are several solutions, you may print any of them. If there are no solutions, print <code>IMPOSSIBLE</code>.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 5000</span></li>
<li><span class="math inline">1 <= x,a_i <= 10^9</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>4 8
2 7 5 1
</pre>
<p>Output:</p>
<pre>1 3 4
</pre></div></div>

## CSES - Sum of Four Values
<div class="md"><div class="md"><p>You are given an array of <span class="math inline">n</span> integers, and your task is to find four values (at distinct positions) whose sum is <span class="math inline">x</span>.</p>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">n</span> and <span class="math inline">x</span>: the array size and the target sum.</p>
<p>The second line has <span class="math inline">n</span> integers <span class="math inline">a_1,a_2,\dots,a_n</span>: the array values.</p>
<h1 id="output">Output</h1>
<p>Print four integers: the positions of the values. If there are several solutions, you may print any of them. If there are no solutions, print <code>IMPOSSIBLE</code>.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 1000</span></li>
<li><span class="math inline">1 <= x,a_i <= 10^9</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>8 15
3 2 5 8 1 3 2 3
</pre>
<p>Output:</p>
<pre>2 4 6 7
</pre></div></div>

## CSES - Nearest Smaller Values
<div class="md"><div class="md"><p>Given an array of <span class="math inline">n</span> integers, your task is to find for each array position the nearest position to its left having a smaller value.</p>
<h1 id="input">Input</h1>
<p>The first input line has an integer <span class="math inline">n</span>: the size of the array.</p>
<p>The second line has <span class="math inline">n</span> integers <span class="math inline">x_1,x_2,\dots,x_n</span>: the array values.</p>
<h1 id="output">Output</h1>
<p>Print <span class="math inline">n</span> integers: for each array position the nearest position with a smaller value. If there is no such position, print <span class="math inline">0</span>.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= x_i <= 10^9</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>8
2 5 1 4 8 3 2 5
</pre>
<p>Output:</p>
<pre>0 1 0 3 4 3 3 7
</pre></div></div>

## CSES - Subarray Sums I
<div class="md"><div class="md"><p>Given an array of <span class="math inline">n</span> positive integers, your task is to count the number of subarrays having sum <span class="math inline">x</span>.</p>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">n</span> and <span class="math inline">x</span>: the size of the array and the target sum <span class="math inline">x</span>.</p>
<p>The next line has <span class="math inline">n</span> integers <span class="math inline">a_1,a_2,\dots,a_n</span>: the contents of the array.</p>
<h1 id="output">Output</h1>
<p>Print one integer: the required number of subarrays.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= x,a_i <= 10^9</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5 7
2 4 1 2 7
</pre>
<p>Output:</p>
<pre>3
</pre></div></div>

## CSES - Subarray Sums II
<div class="md"><div class="md"><p>Given an array of <span class="math inline">n</span> integers, your task is to count the number of subarrays having sum <span class="math inline">x</span>.</p>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">n</span> and <span class="math inline">x</span>: the size of the array and the target sum <span class="math inline">x</span>.</p>
<p>The next line has <span class="math inline">n</span> integers <span class="math inline">a_1,a_2,\dots,a_n</span>: the contents of the array.</p>
<h1 id="output">Output</h1>
<p>Print one integer: the required number of subarrays.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 2 . 10^5</span></li>
<li><span class="math inline">-10^9 <= x,a_i <= 10^9</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5 7
2 -1 3 5 -2
</pre>
<p>Output:</p>
<pre>2
</pre></div></div>

## CSES - Subarray Divisibility
<div class="md"><div class="md"><p>Given an array of <span class="math inline">n</span> integers, your task is to count the number of subarrays where the sum of values is divisible by <span class="math inline">n</span>.</p>
<h1 id="input">Input</h1>
<p>The first input line has an integer <span class="math inline">n</span>: the size of the array.</p>
<p>The next line has <span class="math inline">n</span> integers <span class="math inline">a_1,a_2,\dots,a_n</span>: the contents of the array.</p>
<h1 id="output">Output</h1>
<p>Print one integer: the required number of subarrays.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 2 . 10^5</span></li>
<li><span class="math inline">-10^9 <= a_i <= 10^9</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5
3 1 2 7 4
</pre>
<p>Output:</p>
<pre>1
</pre></div></div>

## CSES - Subarray Distinct Values
<div class="md"><div class="md"><p>Given an array of <span class="math inline">n</span> integers, your task is to calculate the number of subarrays that have at most <span class="math inline">k</span> distinct values.</p>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">n</span> and <span class="math inline">k</span>.</p>
<p>The next line has <span class="math inline">n</span> integers <span class="math inline">x_1,x_2,\dots,x_n</span>: the contents of the array.</p>
<h1 id="output">Output</h1>
<p>Print one integer: the number of subarrays.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= k <= n <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= x_i <= 10^9</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5 2
1 2 3 1 1
</pre>
<p>Output:</p>
<pre>10
</pre></div></div>

## CSES - Array Division
<div class="md"><div class="md"><p>You are given an array containing <span class="math inline">n</span> positive integers.</p>
<p>Your task is to divide the array into <span class="math inline">k</span> subarrays so that the maximum sum in a subarray is as small as possible.</p>
<h1 id="input">Input</h1>
<p>The first input line contains two integers <span class="math inline">n</span> and <span class="math inline">k</span>: the size of the array and the number of subarrays in the division.</p>
<p>The next line contains <span class="math inline">n</span> integers <span class="math inline">x_1,x_2,...,x_n</span>: the contents of the array.</p>
<h1 id="output">Output</h1>
<p>Print one integer: the maximum sum in a subarray in the optimal division.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= k <= n</span></li>
<li><span class="math inline">1 <= x_i <= 10^9</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5 3
2 4 7 3 5
</pre>
<p>Output:</p>
<pre>8
</pre>
<p>Explanation: An optimal division is <span class="math inline">[2,4],[7],[3,5]</span> where the sums of the subarrays are <span class="math inline">6,7,8</span>. The largest sum is the last sum <span class="math inline">8</span>.</p>
</div></div>

## CSES - Sliding Window Median
<div class="md"><div class="md"><p>You are given an array of <span class="math inline">n</span> integers. Your task is to calculate the median of each window of <span class="math inline">k</span> elements, from left to right.</p>
<p>The median is the middle element when the elements are sorted. If the number of elements is even, there are two possible medians and we assume that the median is the smaller of them.</p>
<h1 id="input">Input</h1>
<p>The first input line contains two integers <span class="math inline">n</span> and <span class="math inline">k</span>: the number of elements and the size of the window.</p>
<p>Then there are <span class="math inline">n</span> integers <span class="math inline">x_1,x_2,...,x_n</span>: the contents of the array.</p>
<h1 id="output">Output</h1>
<p>Print <span class="math inline">n-k+1</span> values: the medians.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= k <= n <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= x_i <= 10^9</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>8 3
2 4 3 5 8 1 2 1
</pre>
<p>Output:</p>
<pre>3 4 5 5 2 1
</pre></div></div>

## CSES - Sliding Window Cost
<div class="md"><div class="md"><p>You are given an array of <span class="math inline">n</span> integers. Your task is to calculate for each window of <span class="math inline">k</span> elements, from left to right, the minimum total cost of making all elements equal.</p>
<p>You can increase or decrease each element with cost <span class="math inline">x</span> where <span class="math inline">x</span> is the difference between the new and the original value. The total cost is the sum of such costs.</p>
<h1 id="input">Input</h1>
<p>The first input line contains two integers <span class="math inline">n</span> and <span class="math inline">k</span>: the number of elements and the size of the window.</p>
<p>Then there are <span class="math inline">n</span> integers <span class="math inline">x_1,x_2,...,x_n</span>: the contents of the array.</p>
<h1 id="output">Output</h1>
<p>Output <span class="math inline">n-k+1</span> values: the costs.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= k <= n <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= x_i <= 10^9</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>8 3
2 4 3 5 8 1 2 1
</pre>
<p>Output:</p>
<pre>2 2 5 7 7 1
</pre></div></div>

## CSES - Movie Festival II
<div class="md"><div class="md"><p>In a movie festival, <span class="math inline">n</span> movies will be shown. Syrjälä's movie club consists of <span class="math inline">k</span> members, who will be all attending the festival.</p>
<p>You know the starting and ending time of each movie. What is the maximum total number of movies the club members can watch entirely if they act optimally?</p>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">n</span> and <span class="math inline">k</span>: the number of movies and club members.</p>
<p>After this, there are <span class="math inline">n</span> lines that describe the movies. Each line has two integers <span class="math inline">a</span> and <span class="math inline">b</span>: the starting and ending time of a movie.</p>
<h1 id="output">Output</h1>
<p>Print one integer: the maximum total number of movies.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= k <= n <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= a &lt; b <= 10^9</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5 2
1 5
8 10
3 6
2 5
6 9
</pre>
<p>Output:</p>
<pre>4
</pre></div></div>

## CSES - Maximum Subarray Sum II
<div class="md"><div class="md"><p>Given an array of <span class="math inline">n</span> integers, your task is to find the maximum sum of values in a contiguous subarray with length between <span class="math inline">a</span> and <span class="math inline">b</span>.</p>
<h1 id="input">Input</h1>
<p>The first input line has three integers <span class="math inline">n</span>, <span class="math inline">a</span> and <span class="math inline">b</span>: the size of the array and the minimum and maximum subarray length.</p>
<p>The second line has <span class="math inline">n</span> integers <span class="math inline">x_1,x_2,\dots,x_n</span>: the array values.</p>
<h1 id="output">Output</h1>
<p>Print one integer: the maximum subarray sum.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= a <= b <= n</span></li>
<li><span class="math inline">-10^9 <= x_i <= 10^9</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>8 1 2
-1 3 -2 5 3 -5 2 2
</pre>
<p>Output:</p>
<pre>8
</pre></div></div>

## CSES - Dice Combinations
<div class="md"><div class="md"><p>Your task is to count the number of ways to construct sum <span class="math inline">n</span> by throwing a dice one or more times. Each throw produces an outcome between <span class="math inline">1</span> and  <span class="math inline">6</span>.</p>
<p>For example, if <span class="math inline">n=3</span>, there are <span class="math inline">4</span> ways:</p>
<ul>
<li><span class="math inline">1+1+1</span></li>
<li><span class="math inline">1+2</span></li>
<li><span class="math inline">2+1</span></li>
<li><span class="math inline">3</span></li>
</ul>
<h1 id="input">Input</h1>
<p>The only input line has an integer <span class="math inline">n</span>.</p>
<h1 id="output">Output</h1>
<p>Print the number of ways modulo <span class="math inline">10^9+7</span>.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 10^6</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>3
</pre>
<p>Output:</p>
<pre>4
</pre></div></div>

## CSES - Minimizing Coins
<div class="md"><div class="md"><p>Consider a money system consisting of <span class="math inline">n</span> coins. Each coin has a positive integer value. Your task is to produce a sum of money <span class="math inline">x</span> using the available coins in such a way that the number of coins is minimal.</p>
<p>For example, if the coins are <span class="math inline">\{1,5,7\}</span> and the desired sum is <span class="math inline">11</span>, an optimal solution is <span class="math inline">5+5+1</span> which requires <span class="math inline">3</span> coins.</p>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">n</span> and <span class="math inline">x</span>: the number of coins and the desired sum of money.</p>
<p>The second line has <span class="math inline">n</span> distinct integers <span class="math inline">c_1,c_2,\dots,c_n</span>: the value of each coin.</p>
<h1 id="output">Output</h1>
<p>Print one integer: the minimum number of coins. If it is not possible to produce the desired sum, print <span class="math inline">-1</span>.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 100</span></li>
<li><span class="math inline">1 <= x <= 10^6</span></li>
<li><span class="math inline">1 <= c_i <= 10^6</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>3 11
1 5 7
</pre>
<p>Output:</p>
<pre>3
</pre></div></div>

## CSES - Coin Combinations I
<div class="md"><div class="md"><p>Consider a money system consisting of <span class="math inline">n</span> coins. Each coin has a positive integer value. Your task is to calculate the number of distinct ways you can produce a money sum <span class="math inline">x</span> using the available coins.</p>
<p>For example, if the coins are <span class="math inline">\{2,3,5\}</span> and the desired sum is <span class="math inline">9</span>, there are <span class="math inline">8</span> ways:</p>
<ul>
<li><span class="math inline">2+2+5</span></li>
<li><span class="math inline">2+5+2</span></li>
<li><span class="math inline">5+2+2</span></li>
<li><span class="math inline">3+3+3</span></li>
<li><span class="math inline">2+2+2+3</span></li>
<li><span class="math inline">2+2+3+2</span></li>
<li><span class="math inline">2+3+2+2</span></li>
<li><span class="math inline">3+2+2+2</span></li>
</ul>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">n</span> and <span class="math inline">x</span>: the number of coins and the desired sum of money.</p>
<p>The second line has <span class="math inline">n</span> distinct integers <span class="math inline">c_1,c_2,\dots,c_n</span>: the value of each coin.</p>
<h1 id="output">Output</h1>
<p>Print one integer: the number of ways modulo <span class="math inline">10^9+7</span>.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 100</span></li>
<li><span class="math inline">1 <= x <= 10^6</span></li>
<li><span class="math inline">1 <= c_i <= 10^6</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>3 9
2 3 5
</pre>
<p>Output:</p>
<pre>8
</pre></div></div>

## CSES - Coin Combinations II
<div class="md"><div class="md"><p>Consider a money system consisting of <span class="math inline">n</span> coins. Each coin has a positive integer value. Your task is to calculate the number of distinct <em>ordered</em> ways you can produce a money sum <span class="math inline">x</span> using the available coins.</p>
<p>For example, if the coins are <span class="math inline">\{2,3,5\}</span> and the desired sum is <span class="math inline">9</span>, there are <span class="math inline">3</span> ways:</p>
<ul>
<li><span class="math inline">2+2+5</span></li>
<li><span class="math inline">3+3+3</span></li>
<li><span class="math inline">2+2+2+3</span></li>
</ul>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">n</span> and <span class="math inline">x</span>: the number of coins and the desired sum of money.</p>
<p>The second line has <span class="math inline">n</span> distinct integers <span class="math inline">c_1,c_2,\dots,c_n</span>: the value of each coin.</p>
<h1 id="output">Output</h1>
<p>Print one integer: the number of ways modulo <span class="math inline">10^9+7</span>.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 100</span></li>
<li><span class="math inline">1 <= x <= 10^6</span></li>
<li><span class="math inline">1 <= c_i <= 10^6</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>3 9
2 3 5
</pre>
<p>Output:</p>
<pre>3
</pre></div></div>

## CSES - Removing Digits
<div class="md"><div class="md"><p>You are given an integer <span class="math inline">n</span>. On each step, you may subtract one of the digits from the number.</p>
<p>How many steps are required to make the number equal to <span class="math inline">0</span>?</p>
<h1 id="input">Input</h1>
<p>The only input line has an integer <span class="math inline">n</span>.</p>
<h1 id="output">Output</h1>
<p>Print one integer: the minimum number of steps.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 10^6</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>27
</pre>
<p>Output:</p>
<pre>5
</pre>
<p>Explanation: An optimal solution is <span class="math inline">27 -> 20 -> 18 -> 10 -> 9 -> 0</span>.</p>
</div></div>

## CSES - Grid Paths
<div class="md"><div class="md"><p>Consider an <span class="math inline">n x n</span> grid whose squares may have traps. It is not allowed to move to a square with a trap.</p>
<p>Your task is to calculate the number of paths from the upper-left square to the lower-right square. You can only move right or down.</p>
<h1 id="input">Input</h1>
<p>The first input line has an integer <span class="math inline">n</span>: the size of the grid.</p>
<p>After this, there are <span class="math inline">n</span> lines that describe the grid. Each line has <span class="math inline">n</span> characters: <code>.</code> denotes an empty cell, and <code>*</code> denotes a trap.</p>
<h1 id="output">Output</h1>
<p>Print the number of paths modulo <span class="math inline">10^9+7</span>.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 1000</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>4
....
.*..
...*
*...
</pre>
<p>Output:</p>
<pre>3
</pre></div></div>

## CSES - Book Shop
<div class="md"><div class="md"><p>You are in a book shop which sells <span class="math inline">n</span> different books. You know the price and number of pages of each book.</p>
<p>You have decided that the total price of your purchases will be at most <span class="math inline">x</span>. What is the maximum number of pages you can buy? You can buy each book at most once.</p>
<h1 id="input">Input</h1>
<p>The first input line contains two integers <span class="math inline">n</span> and <span class="math inline">x</span>: the number of books and the maximum total price.</p>
<p>The next line contains <span class="math inline">n</span> integers <span class="math inline">h_1,h_2,...,h_n</span>: the price of each book.</p>
<p>The last line contains <span class="math inline">n</span> integers <span class="math inline">s_1,s_2,...,s_n</span>: the number of pages of each book.</p>
<h1 id="output">Output</h1>
<p>Print one integer: the maximum number of pages.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 1000</span></li>
<li><span class="math inline">1 <= x <= 10^5</span></li>
<li><span class="math inline">1 <= h_i, s_i <= 1000</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>4 10
4 8 5 3
5 12 8 1
</pre>
<p>Output:</p>
<pre>13
</pre>
<p>Explanation: You can buy books 1 and 3. Their price is <span class="math inline">4+5=9</span> and the number of pages is <span class="math inline">5+8=13</span>.</p>
</div></div>

## CSES - Array Description
<div class="md"><div class="md"><p>You know that an array has <span class="math inline">n</span> integers between <span class="math inline">1</span> and  <span class="math inline">m</span>, and the absolute difference between two adjacent values is at most <span class="math inline">1</span>.</p>
<p>Given a description of the array where some values may be unknown, your task is to count the number of arrays that match the description.</p>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">n</span> and <span class="math inline">m</span>: the array size and the upper bound for each value.</p>
<p>The next line has <span class="math inline">n</span> integers <span class="math inline">x_1,x_2,\dots,x_n</span>: the contents of the array. Value <span class="math inline">0</span> denotes an unknown value.</p>
<h1 id="output">Output</h1>
<p>Print one integer: the number of arrays modulo <span class="math inline">10^9+7</span>.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 10^5</span></li>
<li><span class="math inline">1 <= m <= 100</span></li>
<li><span class="math inline">0 <= x_i <= m</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>3 5
2 0 2
</pre>
<p>Output:</p>
<pre>3
</pre>
<p>Explanation: The arrays <span class="math inline">[2,1,2]</span>, <span class="math inline">[2,2,2]</span> and <span class="math inline">[2,3,2]</span> match the description.</p>
</div></div>

## CSES - Counting Towers
<div class="md"><div class="md"><p>Your task is to build a tower whose width is <span class="math inline">2</span> and height is <span class="math inline">n</span>. You have an unlimited supply of blocks whose width and height are integers.</p>
<p>For example, here are some possible solutions for <span class="math inline">n=6</span>:
<center><img alt="" class="invertible" height="" src="/file/a2fc04205fb57157bd28c9a6041601fc284681929941470fdfb15fcd4a14b4f2" width="300"/></center>
Given <span class="math inline">n</span>, how many different towers can you build? Mirrored and rotated towers are counted separately if they look different.</p>
<h1 id="input">Input</h1>
<p>The first input line contains an integer <span class="math inline">t</span>: the number of tests.</p>
<p>After this, there are <span class="math inline">t</span> lines, and each line contains an integer <span class="math inline">n</span>: the height of the tower.</p>
<h1 id="output">Output</h1>
<p>For each test, print the number of towers modulo <span class="math inline">10^9+7</span>.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= t <= 100</span></li>
<li><span class="math inline">1 <= n <= 10^6</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>3
2
6
1337
</pre>
<p>Output:</p>
<pre>8
2864
640403945
</pre></div></div>

## CSES - Edit Distance
<div class="md"><div class="md"><p>The <em>edit distance</em> between two strings is the minimum number of operations required to transform one string into the other.</p>
<p>The allowed operations are:</p>
<ul>
<li>Add one character to the string.</li>
<li>Remove one character from the string.</li>
<li>Replace one character in the string.</li>
</ul>
<p>For example, the edit distance between LOVE and MOVIE is 2, because you can first replace L with M, and then add I.</p>
<p>Your task is to calculate the edit distance between two strings.</p>
<h1 id="input">Input</h1>
<p>The first input line has a string that contains <span class="math inline">n</span> characters between A–Z.</p>
<p>The second input line has a string that contains <span class="math inline">m</span> characters between A–Z.</p>
<h1 id="output">Output</h1>
<p>Print one integer: the edit distance between the strings.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n,m <= 5000</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>LOVE
MOVIE
</pre>
<p>Output:</p>
<pre>2
</pre></div></div>

## CSES - Rectangle Cutting
<div class="md"><div class="md"><p>Given an <span class="math inline">a x b</span> rectangle, your task is to cut it into squares. On each move you can select a rectangle and cut it into two rectangles in such a way that all side lengths remain integers. What is the minimum possible number of moves?</p>
<h1 id="input">Input</h1>
<p>The only input line has two integers <span class="math inline">a</span> and <span class="math inline">b</span>.</p>
<h1 id="output">Output</h1>
<p>Print one integer: the minimum number of moves.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= a,b <= 500</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>3 5
</pre>
<p>Output:</p>
<pre>3
</pre></div></div>

## CSES - Money Sums
<div class="md"><div class="md"><p>You have <span class="math inline">n</span> coins with certain values. Your task is to find all money sums you can create using these coins.</p>
<h1 id="input">Input</h1>
<p>The first input line has an integer <span class="math inline">n</span>: the number of coins.</p>
<p>The next line has <span class="math inline">n</span> integers <span class="math inline">x_1,x_2,\dots,x_n</span>: the values of the coins.</p>
<h1 id="output">Output</h1>
<p>First print an integer <span class="math inline">k</span>: the number of distinct money sums. After this, print all possible sums in increasing order.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 100</span></li>
<li><span class="math inline">1 <= x_i <= 1000</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>4
4 2 5 2
</pre>
<p>Output:</p>
<pre>9
2 4 5 6 7 8 9 11 13
</pre></div></div>

## CSES - Removal Game
<div class="md"><div class="md"><p>There is a list of <span class="math inline">n</span> numbers and two players who move alternately. On each move, a player removes either the first or last number from the list, and their score increases by that number. Both players try to maximize their scores.</p>
<p>What is the maximum possible score for the first player when both players play optimally?</p>
<h1 id="input">Input</h1>
<p>The first input line contains an integer <span class="math inline">n</span>: the size of the list.</p>
<p>The next line has <span class="math inline">n</span> integers <span class="math inline">x_1,x_2,...,x_n</span>: the contents of the list.</p>
<h1 id="output">Output</h1>
<p>Print the maximum possible score for the first player.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 5000</span></li>
<li><span class="math inline">-10^9 <= x_i <= 10^9</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>4
4 5 1 3
</pre>
<p>Output:</p>
<pre>8
</pre></div></div>

## CSES - Two Sets II
<div class="md"><div class="md"><p>Your task is to count the number of ways numbers <span class="math inline">1,2,...,n</span> can be divided into two sets of equal sum.</p>
<p>For example, if <span class="math inline">n=7</span>, there are four solutions:</p>
<ul>
<li><span class="math inline">\{1,3,4,6\}</span> and <span class="math inline">\{2,5,7\}</span></li>
<li><span class="math inline">\{1,2,5,6\}</span> and <span class="math inline">\{3,4,7\}</span></li>
<li><span class="math inline">\{1,2,4,7\}</span> and <span class="math inline">\{3,5,6\}</span></li>
<li><span class="math inline">\{1,6,7\}</span> and <span class="math inline">\{2,3,4,5\}</span></li>
</ul>
<h1 id="input">Input</h1>
<p>The only input line contains an integer <span class="math inline">n</span>.</p>
<h1 id="output">Output</h1>
<p>Print the answer modulo <span class="math inline">10^9+7</span>.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 500</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>7
</pre>
<p>Output:</p>
<pre>4
</pre></div></div>

## CSES - Increasing Subsequence
<div class="md"><div class="md"><p>You are given an array containing <span class="math inline">n</span> integers. Your task is to determine the longest increasing subsequence in the array, i.e., the longest subsequence where every element is larger than the previous one.</p>
<p>A subsequence is a sequence that can be derived from the array by deleting some elements without changing the order of the remaining elements. </p>
<h1 id="input">Input</h1>
<p>The first line contains an integer <span class="math inline">n</span>: the size of the array.</p>
<p>After this there are <span class="math inline">n</span> integers <span class="math inline">x_1,x_2,...,x_n</span>: the contents of the array.</p>
<h1 id="output">Output</h1>
<p>Print the length of the longest increasing subsequence.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= x_i <= 10^9</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>8
7 3 5 3 6 2 9 8
</pre>
<p>Output:</p>
<pre>4
</pre></div></div>

## CSES - Projects
<div class="md"><div class="md"><p>There are <span class="math inline">n</span> projects you can attend. For each project, you know its starting and ending days and the amount of money you would get as reward. You can only attend one project during a day.</p>
<p>What is the maximum amount of money you can earn?</p>
<h1 id="input">Input</h1>
<p>The first input line contains an integer <span class="math inline">n</span>: the number of projects.</p>
<p>After this, there are <span class="math inline">n</span> lines. Each such line has three integers <span class="math inline">a_i</span>, <span class="math inline">b_i</span>, and <span class="math inline">p_i</span>: the starting day, the ending day, and the reward.</p>
<h1 id="output">Output</h1>
<p>Print one integer: the maximum amount of money you can earn.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= a_i <= b_i <= 10^9</span></li>
<li><span class="math inline">1 <= p_i <= 10^9</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>4
2 4 4
3 6 6
6 8 2
5 7 3
</pre>
<p>Output:</p>
<pre>7
</pre></div></div>

## CSES - Elevator Rides
<div class="md"><div class="md"><p>There are <span class="math inline">n</span> people who want to get to the top of a building which has only one elevator. You know the weight of each person and the maximum allowed weight in the elevator. What is the minimum number of elevator rides?</p>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">n</span> and <span class="math inline">x</span>: the number of people and the maximum allowed weight in the elevator.</p>
<p>The second line has <span class="math inline">n</span> integers <span class="math inline">w_1,w_2,\dots,w_n</span>: the weight of each person.</p>
<h1 id="output">Output</h1>
<p>Print one integer: the minimum number of rides.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 20</span></li>
<li><span class="math inline">1 <= x <= 10^9</span></li>
<li><span class="math inline">1 <= w_i <= x</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>4 10
4 8 6 1
</pre>
<p>Output:</p>
<pre>2
</pre></div></div>

## CSES - Counting Tilings
<div class="md"><div class="md"><p>Your task is to count the number of ways you can fill an <span class="math inline">n x m</span> grid using <span class="math inline">1 x 2</span> and <span class="math inline">2 x 1</span> tiles.</p>
<h1 id="input">Input</h1>
<p>The only input line has two integers <span class="math inline">n</span> and <span class="math inline">m</span>.</p>
<h1 id="output">Output</h1>
<p>Print one integer: the number of ways modulo <span class="math inline">10^9+7</span>.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 10</span></li>
<li><span class="math inline">1 <= m <= 1000</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>4 7
</pre>
<p>Output:</p>
<pre>781
</pre></div></div>

## CSES - Counting Numbers
<div class="md"><div class="md"><p>Your task is to count the number of integers between <span class="math inline">a</span> and <span class="math inline">b</span> where no two adjacent digits are the same.</p>
<h1 id="input">Input</h1>
<p>The only input line has two integers <span class="math inline">a</span> and <span class="math inline">b</span>.</p>
<h1 id="output">Output</h1>
<p>Print one integer: the answer to the problem.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">0 <= a <= b <= 10^{18}</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>123 321
</pre>
<p>Output:</p>
<pre>171
</pre></div></div>

## CSES - Counting Rooms
<div class="md"><div class="md"><p>You are given a map of a building, and your task is to count the number of its rooms. The size of the map is <span class="math inline">n x m</span> squares, and each square is either floor or wall. You can walk left, right, up, and down through the floor squares.</p>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">n</span> and <span class="math inline">m</span>: the height and width of the map.</p>
<p>Then there are <span class="math inline">n</span> lines of <span class="math inline">m</span> characters describing the map. Each character is either <code>.</code> (floor) or <code>#</code> (wall).</p>
<h1 id="output">Output</h1>
<p>Print one integer: the number of rooms.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n,m <= 1000</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5 8
########
#..#...#
####.#.#
#..#...#
########
</pre>
<p>Output:</p>
<pre>3
</pre></div></div>

## CSES - Labyrinth
<div class="md"><div class="md"><p>You are given a map of a labyrinth, and your task is to find a path from start to end. You can walk left, right, up and down.</p>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">n</span> and <span class="math inline">m</span>: the height and width of the map.</p>
<p>Then there are <span class="math inline">n</span> lines of <span class="math inline">m</span> characters describing the labyrinth. Each character is <code>.</code> (floor), <code>#</code> (wall), <code>A</code> (start), or <code>B</code> (end). There is exactly one <code>A</code> and one <code>B</code> in the input.</p>
<h1 id="output">Output</h1>
<p>First print "YES", if there is a path, and "NO" otherwise.</p>
<p>If there is a path, print the length of the shortest such path and its description as a string consisting of characters <code>L</code> (left), <code>R</code> (right), <code>U</code> (up), and <code>D</code> (down). You can print any valid solution.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n,m <= 1000</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5 8
########
#.A#...#
#.##.#B#
#......#
########
</pre>
<p>Output:</p>
<pre>YES
9
LDDRRRRRU
</pre></div></div>

## CSES - Building Roads
<div class="md"><div class="md"><p>Byteland has <span class="math inline">n</span> cities, and <span class="math inline">m</span> roads between them. The goal is to construct new roads so that there is a route between any two cities.</p>
<p>Your task is to find out the minimum number of roads required, and also determine which roads should be built.</p>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">n</span> and <span class="math inline">m</span>: the number of cities and roads. The cities are numbered <span class="math inline">1,2,\dots,n</span>.</p>
<p>After that, there are <span class="math inline">m</span> lines describing the roads. Each line has two integers <span class="math inline">a</span> and <span class="math inline">b</span>: there is a road between those cities.</p>
<p>A road always connects two different cities, and there is at most one road between any two cities.</p>
<h1 id="output">Output</h1>
<p>First print an integer <span class="math inline">k</span>: the number of required roads.</p>
<p>Then, print <span class="math inline">k</span> lines that describe the new roads. You can print any valid solution.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 10^5</span></li>
<li><span class="math inline">1 <= m <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= a,b <= n</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>4 2
1 2
3 4
</pre>
<p>Output:</p>
<pre>1
2 3
</pre></div></div>

## CSES - Message Route
<div class="md"><div class="md"><p>Syrjälä's network has <span class="math inline">n</span> computers and <span class="math inline">m</span> connections. Your task is to find out if Uolevi can send a message to Maija, and if it is possible, what is the minimum number of computers on such a route.</p>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">n</span> and <span class="math inline">m</span>: the number of computers and connections. The computers are numbered <span class="math inline">1,2,\dots,n</span>. Uolevi's computer is <span class="math inline">1</span> and Maija's computer is <span class="math inline">n</span>.</p>
<p>Then, there are <span class="math inline">m</span> lines describing the connections. Each line has two integers <span class="math inline">a</span> and <span class="math inline">b</span>: there is a connection between those computers.</p>
<p>Every connection is between two different computers, and there is at most one connection between any two computers.</p>
<h1 id="output">Output</h1>
<p>If it is possible to send a message, first print <span class="math inline">k</span>: the minimum number of computers on a valid route. After this, print an example of such a route. You can print any valid solution.</p>
<p>If there are no routes, print "IMPOSSIBLE".</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">2 <= n <= 10^5</span></li>
<li><span class="math inline">1 <= m <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= a,b <= n</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5 5
1 2
1 3
1 4
2 3
5 4
</pre>
<p>Output:</p>
<pre>3
1 4 5
</pre></div></div>

## CSES - Building Teams
<div class="md"><div class="md"><p>There are <span class="math inline">n</span> pupils in Uolevi's class, and <span class="math inline">m</span> friendships between them. Your task is to divide the pupils into two teams in such a way that no two pupils in a team are friends. You can freely choose the sizes of the teams.</p>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">n</span> and <span class="math inline">m</span>: the number of pupils and friendships. The pupils are numbered <span class="math inline">1,2,\dots,n</span>.</p>
<p>Then, there are <span class="math inline">m</span> lines describing the friendships. Each line has two integers <span class="math inline">a</span> and <span class="math inline">b</span>: pupils <span class="math inline">a</span> and <span class="math inline">b</span> are friends.</p>
<p>Every friendship is between two different pupils. You can assume that there is at most one friendship between any two pupils.</p>
<h1 id="output">Output</h1>
<p>Print an example of how to build the teams. For each pupil, print "1" or "2" depending on to which team the pupil will be assigned. You can print any valid team.</p>
<p>If there are no solutions, print "IMPOSSIBLE".</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 10^5</span></li>
<li><span class="math inline">1 <= m <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= a,b <= n</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5 3
1 2
1 3
4 5
</pre>
<p>Output:</p>
<pre>1 2 2 1 2
</pre></div></div>

## CSES - Round Trip
<div class="md"><div class="md"><p>Byteland has <span class="math inline">n</span> cities and <span class="math inline">m</span> roads between them. Your task is to design a round trip that begins in a city, goes through two or more other cities, and finally returns to the starting city. Every intermediate city on the route has to be distinct.</p>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">n</span> and <span class="math inline">m</span>: the number of cities and roads. The cities are numbered <span class="math inline">1,2,\dots,n</span>.</p>
<p>Then, there are <span class="math inline">m</span> lines describing the roads. Each line has two integers <span class="math inline">a</span> and <span class="math inline">b</span>: there is a road between those cities.</p>
<p>Every road is between two different cities, and there is at most one road between any two cities.</p>
<h1 id="output">Output</h1>
<p>First print an integer <span class="math inline">k</span>: the number of cities on the route. Then print <span class="math inline">k</span> cities in the order they will be visited. You can print any valid solution.</p>
<p>If there are no solutions, print "IMPOSSIBLE".</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 10^5</span></li>
<li><span class="math inline">1 <= m <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= a,b <= n</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5 6
1 3
1 2
5 3
1 5
2 4
4 5
</pre>
<p>Output:</p>
<pre>4
3 5 1 3
</pre></div></div>

## CSES - Monsters
<div class="md"><div class="md"><p>You and some monsters are in a labyrinth. When taking a step to some direction in the labyrinth, each monster may simultaneously take one as well. Your goal is to reach one of the boundary squares without ever sharing a square with a monster.</p>
<p>Your task is to find out if your goal is possible, and if it is, print a path that you can follow. Your plan has to work in any situation; even if the monsters know your path beforehand.</p>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">n</span> and <span class="math inline">m</span>: the height and width of the map.</p>
<p>After this there are <span class="math inline">n</span> lines of <span class="math inline">m</span> characters describing the map. Each character is <code>.</code> (floor), <code>#</code> (wall), <code>A</code> (start), or <code>M</code> (monster). There is exactly one <code>A</code> in the input.</p>
<h1 id="output">Output</h1>
<p>First print "YES" if your goal is possible, and "NO" otherwise.</p>
<p>If your goal is possible, also print an example of a valid path (the length of the path and its description using characters <code>D</code>, <code>U</code>, <code>L</code>, and <code>R</code>). You can print any path, as long as its length is at most <span class="math inline">n . m</span> steps.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n,m <= 1000</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5 8
########
#M..A..#
#.#.M#.#
#M#..#..
#.######
</pre>
<p>Output:</p>
<pre>YES
5
RRDDR
</pre></div></div>

## CSES - Shortest Routes I
<div class="md"><div class="md"><p>There are <span class="math inline">n</span> cities and <span class="math inline">m</span> flight connections between them. Your task is to determine the length of the shortest route from Syrjälä to every city.</p>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">n</span> and <span class="math inline">m</span>: the number of cities and flight connections. The cities are numbered <span class="math inline">1,2,\dots,n</span>, and city <span class="math inline">1</span> is Syrjälä.</p>
<p>After that, there are <span class="math inline">m</span> lines describing the flight connections. Each line has three integers <span class="math inline">a</span>, <span class="math inline">b</span> and <span class="math inline">c</span>: a flight begins at city <span class="math inline">a</span>, ends at city <span class="math inline">b</span>, and its length is <span class="math inline">c</span>. Each flight is a one-way flight.</p>
<p>You can assume that it is possible to travel from Syrjälä to all other cities.</p>
<h1 id="output">Output</h1>
<p>Print <span class="math inline">n</span> integers: the shortest route lengths from Syrjälä to cities <span class="math inline">1,2,\dots,n</span>.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 10^5</span></li>
<li><span class="math inline">1 <= m <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= a,b <= n</span></li>
<li><span class="math inline">1 <= c <= 10^9</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>3 4
1 2 6
1 3 2
3 2 3
1 3 4
</pre>
<p>Output:</p>
<pre>0 5 2
</pre></div></div>

## CSES - Shortest Routes II
<div class="md"><div class="md"><p>There are <span class="math inline">n</span> cities and <span class="math inline">m</span> roads between them. Your task is to process <span class="math inline">q</span> queries where you have to determine the length of the shortest route between two given cities.</p>
<h1 id="input">Input</h1>
<p>The first input line has three integers <span class="math inline">n</span>, <span class="math inline">m</span> and <span class="math inline">q</span>: the number of cities, roads, and queries.</p>
<p>Then, there are <span class="math inline">m</span> lines describing the roads. Each line has three integers <span class="math inline">a</span>, <span class="math inline">b</span> and <span class="math inline">c</span>: there is a road between cities <span class="math inline">a</span> and <span class="math inline">b</span> whose length is <span class="math inline">c</span>. All roads are two-way roads.</p>
<p>Finally, there are <span class="math inline">q</span> lines describing the queries. Each line has two integers <span class="math inline">a</span> and <span class="math inline">b</span>: determine the length of the shortest route between cities <span class="math inline">a</span> and <span class="math inline">b</span>.</p>
<h1 id="output">Output</h1>
<p>Print the length of the shortest route for each query. If there is no route, print <span class="math inline">-1</span> instead.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 500</span></li>
<li><span class="math inline">1 <= m <= n^2</span></li>
<li><span class="math inline">1 <= q <= 10^5</span></li>
<li><span class="math inline">1 <= a,b <= n</span></li>
<li><span class="math inline">1 <= c <= 10^9</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>4 3 5
1 2 5
1 3 9
2 3 3
1 2
2 1
1 3
1 4
3 2
</pre>
<p>Output:</p>
<pre>5
5
8
-1
3
</pre></div></div>

## CSES - High Score
<div class="md"><div class="md"><p>You play a game consisting of <span class="math inline">n</span> rooms and <span class="math inline">m</span> tunnels. Your initial score is <span class="math inline">0</span>, and each tunnel increases your score by <span class="math inline">x</span> where <span class="math inline">x</span> may be both positive or negative. You may go through a tunnel several times.</p>
<p>Your task is to walk from room <span class="math inline">1</span> to room <span class="math inline">n</span>. What is the maximum score you can get?</p>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">n</span> and <span class="math inline">m</span>: the number of rooms and tunnels. The rooms are numbered <span class="math inline">1,2,\dots,n</span>.</p>
<p>Then, there are <span class="math inline">m</span> lines describing the tunnels. Each line has three integers <span class="math inline">a</span>, <span class="math inline">b</span> and <span class="math inline">x</span>: the tunnel starts at room <span class="math inline">a</span>, ends at room <span class="math inline">b</span>, and it increases your score by <span class="math inline">x</span>. All tunnels are one-way tunnels.</p>
<p>You can assume that it is possible to get from room <span class="math inline">1</span> to room <span class="math inline">n</span>.</p>
<h1 id="output">Output</h1>
<p>Print one integer: the maximum score you can get. However, if you can get an arbitrarily large score, print <span class="math inline">-1</span>.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 2500</span></li>
<li><span class="math inline">1 <= m <= 5000</span></li>
<li><span class="math inline">1 <= a,b <= n</span></li>
<li><span class="math inline">-10^9 <= x <= 10^9</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>4 5
1 2 3
2 4 -1
1 3 -2
3 4 7
1 4 4
</pre>
<p>Output:</p>
<pre>5
</pre></div></div>

## CSES - Flight Discount
<div class="md"><div class="md"><p>Your task is to find a minimum-price flight route from Syrjälä to Metsälä. You have one discount coupon, using which you can halve the price of any single flight during the route. However, you can only use the coupon once.</p>
<p>When you use the discount coupon for a flight whose price is <span class="math inline">x</span>, its price becomes <span class="math inline">\lfloor x/2 \rfloor</span> (it is rounded down to an integer).</p>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">n</span> and <span class="math inline">m</span>: the number of cities and flight connections. The cities are numbered <span class="math inline">1,2,...,n</span>. City 1 is Syrjälä, and city <span class="math inline">n</span> is Metsälä.</p>
<p>After this there are <span class="math inline">m</span> lines describing the flights. Each line has three integers <span class="math inline">a</span>, <span class="math inline">b</span>, and <span class="math inline">c</span>: a flight begins at city <span class="math inline">a</span>, ends at city <span class="math inline">b</span>, and its price is <span class="math inline">c</span>. Each flight is unidirectional.</p>
<p>You can assume that it is always possible to get from Syrjälä to Metsälä.</p>
<h1 id="output">Output</h1>
<p>Print one integer: the price of the cheapest route from Syrjälä to Metsälä.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">2 <= n <= 10^5</span></li>
<li><span class="math inline">1 <= m <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= a,b <= n</span></li>
<li><span class="math inline">1 <= c <= 10^9</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>3 4
1 2 3
2 3 1
1 3 7
2 1 5
</pre>
<p>Output:</p>
<pre>2
</pre></div></div>

## CSES - Cycle Finding
<div class="md"><div class="md"><p>You are given a directed graph, and your task is to find out if it contains a negative cycle, and also give an example of such a cycle.</p>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">n</span> and <span class="math inline">m</span>: the number of nodes and edges. The nodes are numbered <span class="math inline">1,2,...,n</span>.</p>
<p>After this, the input has <span class="math inline">m</span> lines describing the edges. Each line has three integers <span class="math inline">a</span>, <span class="math inline">b</span>, and <span class="math inline">c</span>: there is an edge from node <span class="math inline">a</span> to node <span class="math inline">b</span> whose length is <span class="math inline">c</span>.</p>
<h1 id="output">Output</h1>
<p>If the graph contains a negative cycle, print first "YES", and then the nodes in the cycle in their correct order. If there are several negative cycles, you can print any of them. If there are no negative cycles, print "NO".</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 2500</span></li>
<li><span class="math inline">1 <= m <= 5000</span></li>
<li><span class="math inline">1 <= a,b <= n</span></li>
<li><span class="math inline">-10^9 <= c <= 10^9</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>4 5
1 2 1
2 4 1
3 1 1
4 1 -3
4 3 -2
</pre>
<p>Output:</p>
<pre>YES
1 2 4 1
</pre></div></div>

## CSES - Flight Routes
<div class="md"><div class="md"><p>Your task is to find the <span class="math inline">k</span> shortest flight routes from Syrjälä to Metsälä. A route can visit the same city several times.</p>
<p>Note that there can be several routes with the same price and each of them should be considered (see the example).</p>
<h1 id="input">Input</h1>
<p>The first input line has three integers <span class="math inline">n</span>, <span class="math inline">m</span>, and <span class="math inline">k</span>: the number of cities, the number of flights, and the parameter <span class="math inline">k</span>. The cities are numbered <span class="math inline">1,2,...,n</span>. City 1 is Syrjälä, and city <span class="math inline">n</span> is Metsälä.</p>
<p>After this, the input has <span class="math inline">m</span> lines describing the flights. Each line has three integers <span class="math inline">a</span>, <span class="math inline">b</span>, and <span class="math inline">c</span>: a flight begins at city <span class="math inline">a</span>, ends at city <span class="math inline">b</span>, and its price is <span class="math inline">c</span>. All flights are one-way flights.</p>
<p>You may assume that there are at least <span class="math inline">k</span> distinct routes from Syrjälä to Metsälä.</p>
<h1 id="output">Output</h1>
<p>Print <span class="math inline">k</span> integers: the prices of the <span class="math inline">k</span> cheapest routes sorted according to their prices.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">2 <= n <= 10^5</span></li>
<li><span class="math inline">1 <= m <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= a,b <= n</span></li>
<li><span class="math inline">1 <= c <= 10^9</span></li>
<li><span class="math inline">1 <= k <= 10</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>4 6 3
1 2 1
1 3 3
2 3 2
2 4 6
3 2 8
3 4 1
</pre>
<p>Output:</p>
<pre>4 4 7
</pre>
<p>Explanation: The cheapest routes are <span class="math inline">1 -> 3 -> 4</span> (price <span class="math inline">4</span>), <span class="math inline">1 -> 2 -> 3 -> 4</span> (price <span class="math inline">4</span>) and <span class="math inline">1 -> 2 -> 4</span> (price <span class="math inline">7</span>).</p>
</div></div>

## CSES - Round Trip II
<div class="md"><div class="md"><p>Byteland has <span class="math inline">n</span> cities and <span class="math inline">m</span> flight connections. Your task is to design a round trip that begins in a city, goes through one or more other cities, and finally returns to the starting city. Every intermediate city on the route has to be distinct.</p>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">n</span> and <span class="math inline">m</span>: the number of cities and flights. The cities are numbered <span class="math inline">1,2,\dots,n</span>.</p>
<p>Then, there are <span class="math inline">m</span> lines describing the flights. Each line has two integers <span class="math inline">a</span> and <span class="math inline">b</span>: there is a flight connection from city <span class="math inline">a</span> to city <span class="math inline">b</span>. All connections are one-way flights from a city to another city.</p>
<h1 id="output">Output</h1>
<p>First print an integer <span class="math inline">k</span>: the number of cities on the route. Then print <span class="math inline">k</span> cities in the order they will be visited. You can print any valid solution.</p>
<p>If there are no solutions, print "IMPOSSIBLE".</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 10^5</span></li>
<li><span class="math inline">1 <= m <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= a,b <= n</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>4 5
1 3
2 1
2 4
3 2
3 4
</pre>
<p>Output:</p>
<pre>4
2 1 3 2
</pre></div></div>

## CSES - Course Schedule
<div class="md"><div class="md"><p>You have to complete <span class="math inline">n</span> courses. There are <span class="math inline">m</span> requirements of the form "course <span class="math inline">a</span> has to be completed before course <span class="math inline">b</span>". Your task is to find an order in which you can complete the courses.</p>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">n</span> and <span class="math inline">m</span>: the number of courses and requirements. The courses are numbered <span class="math inline">1,2,\dots,n</span>.</p>
<p>After this, there are <span class="math inline">m</span> lines describing the requirements. Each line has two integers <span class="math inline">a</span> and <span class="math inline">b</span>: course <span class="math inline">a</span> has to be completed before course <span class="math inline">b</span>.</p>
<h1 id="output">Output</h1>
<p>Print an order in which you can complete the courses. You can print any valid order that includes all the courses.</p>
<p>If there are no solutions, print "IMPOSSIBLE".</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 10^5</span></li>
<li><span class="math inline">1 <= m <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= a,b <= n</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5 3
1 2
3 1
4 5
</pre>
<p>Output:</p>
<pre>3 4 1 5 2
</pre></div></div>

## CSES - Longest Flight Route
<div class="md"><div class="md"><p>Uolevi has won a contest, and the prize is a free flight trip that can consist of one or more flights through cities. Of course, Uolevi wants to choose a trip that has as many cities as possible.</p>
<p>Uolevi wants to fly from Syrjälä to Lehmälä so that he visits the maximum number of cities. You are given the list of possible flights, and you know that there are no directed cycles in the flight network.</p>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">n</span> and <span class="math inline">m</span>: the number of cities and flights. The cities are numbered <span class="math inline">1,2,\dots,n</span>. City <span class="math inline">1</span> is Syrjälä, and city <span class="math inline">n</span> is Lehmälä.</p>
<p>After this, there are <span class="math inline">m</span> lines describing the flights. Each line has two integers <span class="math inline">a</span> and <span class="math inline">b</span>: there is a flight from city <span class="math inline">a</span> to city <span class="math inline">b</span>. Each flight is a one-way flight.</p>
<h1 id="output">Output</h1>
<p>First print the maximum number of cities on the route. After this, print the cities in the order they will be visited. You can print any valid solution.</p>
<p>If there are no solutions, print "IMPOSSIBLE".</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">2 <= n <= 10^5</span></li>
<li><span class="math inline">1 <= m <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= a,b <= n</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5 5
1 2
2 5
1 3
3 4
4 5
</pre>
<p>Output:</p>
<pre>4
1 3 4 5
</pre></div></div>

## CSES - Game Routes
<div class="md"><div class="md"><p>A game has <span class="math inline">n</span> levels, connected by <span class="math inline">m</span> teleporters, and your task is to get from level <span class="math inline">1</span> to level <span class="math inline">n</span>. The game has been designed so that there are no directed cycles in the underlying graph. In how many ways can you complete the game?</p>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">n</span> and <span class="math inline">m</span>: the number of levels and teleporters. The levels are numbered <span class="math inline">1,2,\dots,n</span>.</p>
<p>After this, there are <span class="math inline">m</span> lines describing the teleporters. Each line has two integers <span class="math inline">a</span> and <span class="math inline">b</span>: there is a teleporter from level <span class="math inline">a</span> to level <span class="math inline">b</span>.</p>
<h1 id="output">Output</h1>
<p>Print one integer: the number of ways you can complete the game. Since the result may be large, print it modulo <span class="math inline">10^9+7</span>.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 10^5</span></li>
<li><span class="math inline">1 <= m <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= a,b <= n</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>4 5
1 2
2 4
1 3
3 4
1 4
</pre>
<p>Output:</p>
<pre>3
</pre></div></div>

## CSES - Investigation
<div class="md"><div class="md"><p>You are going to travel from Syrjälä to Lehmälä by plane. You would like to find answers to the following questions:</p>
<ul>
<li>what is the minimum price of such a route?</li>
<li>how many minimum-price routes are there? (modulo <span class="math inline">10^9+7)</span></li>
<li>what is the minimum number of flights in a minimum-price route?</li>
<li>what is the maximum number of flights in a minimum-price route?</li>
</ul>
<h1 id="input">Input</h1>
<p>The first input line contains two integers <span class="math inline">n</span> and <span class="math inline">m</span>: the number of cities and the number of flights. The cities are numbered <span class="math inline">1,2,...,n</span>. City 1 is Syrjälä, and city <span class="math inline">n</span> is Lehmälä.</p>
<p>After this, there are <span class="math inline">m</span> lines describing the flights. Each line has three integers <span class="math inline">a</span>, <span class="math inline">b</span>, and <span class="math inline">c</span>: there is a flight from city <span class="math inline">a</span> to city <span class="math inline">b</span> with price <span class="math inline">c</span>. All flights are one-way flights.</p>
<p>You may assume that there is a route from Syrjälä to Lehmälä.</p>
<h1 id="output">Output</h1>
<p>Print four integers according to the problem statement.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 10^5</span></li>
<li><span class="math inline">1 <= m <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= a,b <= n</span></li>
<li><span class="math inline">1 <= c <= 10^9</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>4 5
1 4 5
1 2 4
2 4 5
1 3 2
3 4 3
</pre>
<p>Output:</p>
<pre>5 2 1 2
</pre></div></div>

## CSES - Planets Queries I
<div class="md"><div class="md"><p>You are playing a game consisting of <span class="math inline">n</span> planets. Each planet has a teleporter to another planet (or the planet itself).</p>
<p>Your task is to process <span class="math inline">q</span> queries of the form: when you begin on planet <span class="math inline">x</span> and travel through <span class="math inline">k</span> teleporters, which planet will you reach?</p>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">n</span> and <span class="math inline">q</span>: the number of planets and queries. The planets are numbered <span class="math inline">1,2,\dots,n</span>.</p>
<p>The second line has <span class="math inline">n</span> integers <span class="math inline">t_1,t_2,\dots,t_n</span>: for each planet, the destination of the teleporter. It is possible that <span class="math inline">t_i=i</span>.</p>
<p>Finally, there are <span class="math inline">q</span> lines describing the queries. Each line has two integers <span class="math inline">x</span> and <span class="math inline">k</span>: you start on planet <span class="math inline">x</span> and travel through <span class="math inline">k</span> teleporters.</p>
<h1 id="output">Output</h1>
<p>Print the answer to each query.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n, q <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= t_i <= n</span></li>
<li><span class="math inline">1 <= x <= n</span></li>
<li><span class="math inline">0 <= k <= 10^9</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>4 3
2 1 1 4
1 2
3 4
4 1
</pre>
<p>Output:</p>
<pre>1
2
4
</pre></div></div>

## CSES - Planets Queries II
<div class="md"><div class="md"><p>You are playing a game consisting of n planets. Each planet has a teleporter to another planet (or the planet itself).</p>
<p>You have to process <span class="math inline">q</span> queries of the form: You are now on planet <span class="math inline">a</span> and want to reach planet <span class="math inline">b</span>. What is the minimum number of teleportations?</p>
<h1 id="input">Input</h1>
<p>The first input line contains two integers <span class="math inline">n</span> and <span class="math inline">q</span>: the number of planets and queries. The planets are numbered <span class="math inline">1,2,...,n</span>.</p>
<p>The second line contains <span class="math inline">n</span> integers <span class="math inline">t_1,t_2,...,t_n</span>: for each planet, the destination of the teleporter.</p>
<p>Finally, there are <span class="math inline">q</span> lines describing the queries. Each line has two integers <span class="math inline">a</span> and <span class="math inline">b</span>: you are now on planet <span class="math inline">a</span> and want to reach planet <span class="math inline">b</span>.</p>
<h1 id="output">Output</h1>
<p>For each query, print the minimum number of teleportations. If it is not possible to reach the destination, print <span class="math inline">-1</span>.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n, q <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= a,b <= n</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5 3
2 3 2 3 2
1 2
1 3
1 4
</pre>
<p>Output:</p>
<pre>1
2
-1
</pre></div></div>

## CSES - Planets Cycles
<div class="md"><div class="md"><p>You are playing a game consisting of <span class="math inline">n</span> planets. Each planet has a teleporter to another planet (or the planet itself).</p>
<p>You start on a planet and then travel through teleporters until you reach a planet that you have already visited before.</p>
<p>Your task is to calculate for each planet the number of teleportations there would be if you started on that planet.</p>
<h1 id="input">Input</h1>
<p>The first input line has an integer <span class="math inline">n</span>: the number of planets. The planets are numbered <span class="math inline">1,2,\dots,n</span>.</p>
<p>The second line has <span class="math inline">n</span> integers <span class="math inline">t_1,t_2,\dots,t_n</span>: for each planet, the destination of the teleporter. It is possible that <span class="math inline">t_i=i</span>.</p>
<h1 id="output">Output</h1>
<p>Print <span class="math inline">n</span> integers according to the problem statement.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= t_i <= n</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5
2 4 3 1 4
</pre>
<p>Output:</p>
<pre>3 3 1 3 4
</pre></div></div>

## CSES - Road Reparation
<div class="md"><div class="md"><p>There are <span class="math inline">n</span> cities and <span class="math inline">m</span> roads between them. Unfortunately, the condition of the roads is so poor that they cannot be used. Your task is to repair some of the roads so that there will be a decent route between any two cities.</p>
<p>For each road, you know its reparation cost, and you should find a solution where the total cost is as small as possible.</p>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">n</span> and <span class="math inline">m</span>: the number of cities and roads. The cities are numbered <span class="math inline">1,2,\dots,n</span>.</p>
<p>Then, there are <span class="math inline">m</span> lines describing the roads. Each line has three integers <span class="math inline">a</span>, <span class="math inline">b</span> and <span class="math inline">c</span>: there is a road between cities <span class="math inline">a</span> and <span class="math inline">b</span>, and its reparation cost is <span class="math inline">c</span>. All roads are two-way roads.</p>
<p>Every road is between two different cities, and there is at most one road between two cities.</p>
<h1 id="output">Output</h1>
<p>Print one integer: the minimum total reparation cost. However, if there are no solutions, print "IMPOSSIBLE".</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 10^5</span></li>
<li><span class="math inline">1 <= m <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= a,b <= n</span></li>
<li><span class="math inline">1 <= c <= 10^9</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5 6
1 2 3
2 3 5
2 4 2
3 4 8
5 1 7
5 4 4
</pre>
<p>Output:</p>
<pre>14
</pre></div></div>

## CSES - Road Construction
<div class="md"><div class="md"><p>There are <span class="math inline">n</span> cities and initially no roads between them. However, every day a new road will be constructed, and there will be a total of <span class="math inline">m</span> roads.</p>
<p>A component is a group of cities where there is a route between any two cities using the roads. After each day, your task is to find the number of components and the size of the largest component.</p>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">n</span> and <span class="math inline">m</span>: the number of cities and roads. The cities are numbered <span class="math inline">1,2,\dots,n</span>.</p>
<p>Then, there are <span class="math inline">m</span> lines describing the new roads. Each line has two integers <span class="math inline">a</span> and <span class="math inline">b</span>: a new road is constructed between cities <span class="math inline">a</span> and <span class="math inline">b</span>.</p>
<p>You may assume that every road will be constructed between two different cities.</p>
<h1 id="output">Output</h1>
<p>Print <span class="math inline">m</span> lines: the required information after each day.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 10^5</span></li>
<li><span class="math inline">1 <= m <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= a,b <= n</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5 3
1 2
1 3
4 5
</pre>
<p>Output:</p>
<pre>4 2
3 3
2 3
</pre></div></div>

## CSES - Flight Routes Check
<div class="md"><div class="md"><p>There are <span class="math inline">n</span> cities and <span class="math inline">m</span> flight connections. Your task is to check if you can travel from any city to any other city using the available flights.</p>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">n</span> and <span class="math inline">m</span>: the number of cities and flights. The cities are numbered <span class="math inline">1,2,\dots,n</span>.</p>
<p>After this, there are <span class="math inline">m</span> lines describing the flights. Each line has two integers <span class="math inline">a</span> and <span class="math inline">b</span>: there is a flight from city <span class="math inline">a</span> to city <span class="math inline">b</span>. All flights are one-way flights.</p>
<h1 id="output">Output</h1>
<p>Print "YES" if all routes are possible, and "NO" otherwise. In the latter case also print two cities <span class="math inline">a</span> and <span class="math inline">b</span> such that you cannot travel from city <span class="math inline">a</span> to city <span class="math inline">b</span>. If there are several possible solutions, you can print any of them.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 10^5</span></li>
<li><span class="math inline">1 <= m <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= a,b <= n</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>4 5
1 2
2 3
3 1
1 4
3 4
</pre>
<p>Output:</p>
<pre>NO
4 2
</pre></div></div>

## CSES - Planets and Kingdoms
<div class="md"><div class="md"><p>A game has <span class="math inline">n</span> planets, connected by <span class="math inline">m</span> teleporters. Two planets <span class="math inline">a</span> and <span class="math inline">b</span> belong to the same kingdom exactly when there is a route both from <span class="math inline">a</span> to <span class="math inline">b</span> and from <span class="math inline">b</span> to <span class="math inline">a</span>. Your task is to determine for each planet its kingdom.</p>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">n</span> and <span class="math inline">m</span>: the number of planets and teleporters. The planets are numbered <span class="math inline">1,2,\dots,n</span>.</p>
<p>After this, there are <span class="math inline">m</span> lines describing the teleporters. Each line has two integers <span class="math inline">a</span> and <span class="math inline">b</span>: you can travel from planet <span class="math inline">a</span> to planet <span class="math inline">b</span> through a teleporter.</p>
<h1 id="output">Output</h1>
<p>First print an integer <span class="math inline">k</span>: the number of kingdoms. After this, print for each planet a kingdom label between <span class="math inline">1</span> and <span class="math inline">k</span>. You can print any valid solution.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 10^5</span></li>
<li><span class="math inline">1 <= m <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= a,b <= n</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5 6
1 2
2 3
3 1
3 4
4 5
5 4
</pre>
<p>Output:</p>
<pre>2
1 1 1 2 2
</pre></div></div>

## CSES - Giant Pizza
<div class="md"><div class="md"><p>Uolevi's family is going to order a large pizza and eat it together. A total of <span class="math inline">n</span> family members will join the order, and there are <span class="math inline">m</span> possible toppings. The pizza may have any number of toppings.</p>
<p>Each family member gives two wishes concerning the toppings of the pizza. The wishes are of the form "topping <span class="math inline">x</span> is good/bad". Your task is to choose the toppings so that at least one wish from everybody becomes true (a good topping is included in the pizza or a bad topping is not included).</p>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">n</span> and <span class="math inline">m</span>: the number of family members and toppings. The toppings are numbered <span class="math inline">1,2,\dots,m</span>.</p>
<p>After this, there are <span class="math inline">n</span> lines describing the wishes. Each line has two wishes of the form "+ <span class="math inline">x</span>" (topping <span class="math inline">x</span> is good) or "- <span class="math inline">x</span>" (topping <span class="math inline">x</span> is bad).</p>
<h1 id="output">Output</h1>
<p>Print a line with <span class="math inline">m</span> symbols: for each topping "+" if it is included and "-" if it is not included. You can print any valid solution.</p>
<p>If there are no valid solutions, print "IMPOSSIBLE".</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n,m <= 10^5</span></li>
<li><span class="math inline">1 <= x <= m</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>3 5
+ 1 + 2
- 1 + 3
+ 4 - 2
</pre>
<p>Output:</p>
<pre>- + + + -
</pre></div></div>

## CSES - Coin Collector
<div class="md"><div class="md"><p>A game has <span class="math inline">n</span> rooms and <span class="math inline">m</span> tunnels between them. Each room has a certain number of coins. What is the maximum number of coins you can collect while moving through the tunnels when you can freely choose your starting and ending room?</p>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">n</span> and <span class="math inline">m</span>: the number of rooms and tunnels. The rooms are numbered <span class="math inline">1,2,\dots,n</span>.</p>
<p>Then, there are <span class="math inline">n</span> integers <span class="math inline">k_1,k_2,...,k_n</span>: the number of coins in each room.</p>
<p>Finally, there are <span class="math inline">m</span> lines describing the tunnels. Each line has two integers <span class="math inline">a</span> and <span class="math inline">b</span>: there is a tunnel from room <span class="math inline">a</span> to room <span class="math inline">b</span>. Each tunnel is a one-way tunnel.</p>
<h1 id="output">Output</h1>
<p>Print one integer: the maximum number of coins you can collect.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 10^5</span></li>
<li><span class="math inline">1 <= m <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= k_i <= 10^9</span></li>
<li><span class="math inline">1 <= a,b <= n</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>4 4
4 5 2 7
1 2
2 1
1 3
2 4
</pre>
<p>Output:</p>
<pre>16
</pre></div></div>

## CSES - Mail Delivery
<div class="md"><div class="md"><p>Your task is to deliver mail to the inhabitants of a city. For this reason, you want to find a route whose starting and ending point are the post office, and that goes through every street exactly once.</p>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">n</span> and <span class="math inline">m</span>: the number of crossings and streets. The crossings are numbered <span class="math inline">1,\,2,...,\,n</span>, and the post office is located at crossing <span class="math inline">1</span>.</p>
<p>After that, there are m lines describing the streets. Each line has two integers <span class="math inline">a</span> and <span class="math inline">b</span>: there is a street between crossings <span class="math inline">a</span> and <span class="math inline">b</span>. All streets are two-way streets.</p>
<p>Every street is between two different crossings, and there is at most one street between two crossings.</p>
<h1 id="output">Output</h1>
<p>Print all the crossings on the route in the order you will visit them. You can print any valid solution.</p>
<p>If there are no solutions, print "IMPOSSIBLE".</p>
<h1 id="constraints">Constraints</h1>
<p><span class="math inline">2<=q n<=q 10^5</span><br/>
<span class="math inline">1<=q m<=q 2 . 10^5</span><br/>
<span class="math inline">1<=q a,\,b<=q n</span></p>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>6 8
1 2
1 3
2 3
2 4
2 6
3 5
3 6
4 5
</pre>
<p>Output:</p>
<pre>1 2 6 3 2 4 5 3 1
</pre></div></div>

## CSES - De Bruijn Sequence
<div class="md"><div class="md"><p>Your task is to construct a minimum-length bit string that contains all possible substrings of length <span class="math inline">n</span>. For example, when <span class="math inline">n=2</span>, the string 00110 is a valid solution, because its substrings of length <span class="math inline">2</span> are 00, 01, 10 and 11.</p>
<h1 id="input">Input</h1>
<p>The only input line has an integer <span class="math inline">n</span>.</p>
<h1 id="output">Output</h1>
<p>Print a minimum-length bit string that contains all substrings of length <span class="math inline">n</span>. You can print any valid solution.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 15</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>2
</pre>
<p>Output:</p>
<pre>00110
</pre></div></div>

## CSES - Teleporters Path
<div class="md"><div class="md"><p>A game has <span class="math inline">n</span> levels and <span class="math inline">m</span> teleportes between them. You win the game if you move from level <span class="math inline">1</span> to level <span class="math inline">n</span> using every teleporter exactly once.</p>
<p>Can you win the game, and what is a possible way to do it?</p>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">n</span> and <span class="math inline">m</span>: the number of levels and teleporters. The levels are numbered <span class="math inline">1,2,\dots,n</span>.</p>
<p>Then, there are <span class="math inline">m</span> lines describing the teleporters. Each line has two integers <span class="math inline">a</span> and <span class="math inline">b</span>: there is a teleporter from level <span class="math inline">a</span> to level <span class="math inline">b</span>.</p>
<p>You can assume that each pair <span class="math inline">(a,b)</span> in the input is distinct.</p>
<h1 id="output">Output</h1>
<p>Print <span class="math inline">m+1</span> integers: the sequence in which you visit the levels during the game. You can print any valid solution.</p>
<p>If there are no solutions, print "IMPOSSIBLE".</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">2 <= n <= 10^5</span></li>
<li><span class="math inline">1 <= m <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= a,b <= n</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5 6
1 2
1 3
2 4
2 5
3 1
4 2
</pre>
<p>Output:</p>
<pre>1 3 1 2 4 2 5
</pre></div></div>

## CSES - Hamiltonian Flights
<div class="md"><div class="md"><p>There are <span class="math inline">n</span> cities and <span class="math inline">m</span> flight connections between them. You want to travel from Syrjälä to Lehmälä so that you visit each city exactly once. How many possible routes are there?</p>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">n</span> and <span class="math inline">m</span>: the number of cities and flights. The cities are numbered <span class="math inline">1,2,\dots,n</span>. City <span class="math inline">1</span> is Syrjälä, and city <span class="math inline">n</span> is Lehmälä.</p>
<p>Then, there are <span class="math inline">m</span> lines describing the flights. Each line has two integers <span class="math inline">a</span> and <span class="math inline">b</span>: there is a flight from city <span class="math inline">a</span> to city <span class="math inline">b</span>. All flights are one-way flights.</p>
<h1 id="output">Output</h1>
<p>Print one integer: the number of routes modulo <span class="math inline">10^9+7</span>.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">2 <= n <= 20</span></li>
<li><span class="math inline">1 <= m <= n^2</span></li>
<li><span class="math inline">1 <= a,b <= n</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>4 6
1 2
1 3
2 3
3 2
2 4
3 4
</pre>
<p>Output:</p>
<pre>2
</pre></div></div>

## CSES - Knight's Tour
<div class="md"><div class="md"><p>Given a starting position of a knight on an <span class="math inline">8 x 8</span> chessboard, your task is to find a sequence of moves such that it visits every square exactly once.</p>
<p>On each move, the knight may either move two steps horizontally and one step vertically, or one step horizontally and two steps vertically.</p>
<h1 id="input">Input</h1>
<p>The only line has two integers <span class="math inline">x</span> and <span class="math inline">y</span>: the knight's starting position.</p>
<h1 id="output">Output</h1>
<p>Print a grid that shows how the knight moves (according to the example). You can print any valid solution.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= x,y <= 8</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>2 1
</pre>
<p>Output:</p>
<pre>8 1 10 13 6 3 20 17 
11 14 7 2 19 16 23 4 
26 9 12 15 24 5 18 21 
49 58 25 28 51 22 33 30 
40 27 50 59 32 29 52 35 
57 48 41 44 37 34 31 62 
42 39 46 55 60 63 36 53 
47 56 43 38 45 54 61 64
</pre></div></div>

## CSES - Download Speed
<div class="md"><div class="md"><p>Consider a network consisting of <span class="math inline">n</span> computers and <span class="math inline">m</span> connections. Each connection specifies how fast a computer can send data to another computer.</p>
<p>Kotivalo wants to download some data from a server. What is the maximum speed he can do this, using the connections in the network?</p>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">n</span> and <span class="math inline">m</span>: the number of computers and connections. The computers are numbered <span class="math inline">1,2,\dots,n</span>. Computer <span class="math inline">1</span> is the server and computer <span class="math inline">n</span> is Kotivalo's computer.</p>
<p>After this, there are <span class="math inline">m</span> lines describing the connections. Each line has three integers <span class="math inline">a</span>, <span class="math inline">b</span> and <span class="math inline">c</span>: computer <span class="math inline">a</span> can send data to computer <span class="math inline">b</span> at speed <span class="math inline">c</span>.</p>
<h1 id="output">Output</h1>
<p>Print one integer: the maximum speed Kotivalo can download data.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 500</span></li>
<li><span class="math inline">1 <= m <= 1000</span></li>
<li><span class="math inline">1 <= a,b <= n</span></li>
<li><span class="math inline">1 <= c <= 10^9</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>4 5
1 2 3
2 4 2
1 3 4
3 4 5
4 1 3
</pre>
<p>Output:</p>
<pre>6
</pre></div></div>

## CSES - Police Chase
<div class="md"><div class="md"><p>Kaaleppi has just robbed a bank and is now heading to the harbor. However, the police wants to stop him by closing some streets of the city.</p>
<p>What is the minimum number of streets that should be closed so that there is no route between the bank and the harbor?</p>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">n</span> and <span class="math inline">m</span>: the number of crossings and streets. The crossings are numbered <span class="math inline">1,2,\dots,n</span>. The bank is located at crossing <span class="math inline">1</span>, and the harbor is located at crossing <span class="math inline">n</span>.</p>
<p>After this, there are <span class="math inline">m</span> lines that describing the streets. Each line has two integers <span class="math inline">a</span> and <span class="math inline">b</span>: there is a street between crossings <span class="math inline">a</span> and <span class="math inline">b</span>. All streets are two-way streets, and there is at most one street between two crossings.</p>
<h1 id="output">Output</h1>
<p>First print an integer <span class="math inline">k</span>: the minimum number of streets that should be closed. After this, print <span class="math inline">k</span> lines describing the streets. You can print any valid solution.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">2 <= n <= 500</span></li>
<li><span class="math inline">1 <= m <= 1000</span></li>
<li><span class="math inline">1 <= a,b <= n</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>4 5
1 2
1 3
2 3
3 4
1 4
</pre>
<p>Output:</p>
<pre>2
3 4
1 4
</pre></div></div>

## CSES - School Dance
<div class="md"><div class="md"><p>There are <span class="math inline">n</span> boys and <span class="math inline">m</span> girls in a school. Next week a school dance will be organized. A dance pair consists of a boy and a girl, and there are <span class="math inline">k</span> potential pairs.</p>
<p>Your task is to find out the maximum number of dance pairs and show how this number can be achieved.</p>
<h1 id="input">Input</h1>
<p>The first input line has three integers <span class="math inline">n</span>, <span class="math inline">m</span> and <span class="math inline">k</span>: the number of boys, girls, and potential pairs. The boys are numbered <span class="math inline">1,2,\dots,n</span>, and the girls are numbered <span class="math inline">1,2,\dots,m</span>.</p>
<p>After this, there are <span class="math inline">k</span> lines describing the potential pairs. Each line has two integers <span class="math inline">a</span> and <span class="math inline">b</span>: boy <span class="math inline">a</span> and girl <span class="math inline">b</span> are willing to dance together.</p>
<h1 id="output">Output</h1>
<p>First print one integer <span class="math inline">r</span>: the maximum number of dance pairs. After this, print <span class="math inline">r</span> lines describing the pairs. You can print any valid solution.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n,m <= 500</span></li>
<li><span class="math inline">1 <= k <= 1000</span></li>
<li><span class="math inline">1 <= a <= n</span></li>
<li><span class="math inline">1 <= b <= m</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>3 2 4
1 1
1 2
2 1
3 1
</pre>
<p>Output:</p>
<pre>2
1 2
3 1
</pre></div></div>

## CSES - Distinct Routes
<div class="md"><div class="md"><p>A game consists of <span class="math inline">n</span> rooms and <span class="math inline">m</span> teleporters. At the beginning of each day, you start in room <span class="math inline">1</span> and you have to reach room <span class="math inline">n</span>.</p>
<p>You can use each teleporter at most once during the game. How many days can you play if you choose your routes optimally?</p>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">n</span> and <span class="math inline">m</span>: the number of rooms and teleporters. The rooms are numbered <span class="math inline">1,2,\dots,n</span>.</p>
<p>After this, there are <span class="math inline">m</span> lines describing the teleporters. Each line has two integers <span class="math inline">a</span> and <span class="math inline">b</span>: there is a teleporter from room <span class="math inline">a</span> to room <span class="math inline">b</span>.</p>
<p>There are no two teleporters whose starting and ending room are the same.</p>
<h1 id="output">Output</h1>
<p>First print an integer <span class="math inline">k</span>: the maximum number of days you can play the game. Then, print <span class="math inline">k</span> route descriptions according to the example. You can print any valid solution.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">2 <= n <= 500</span></li>
<li><span class="math inline">1 <= m <= 1000</span></li>
<li><span class="math inline">1 <= a,b <= n</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>6 7
1 2
1 3
2 6
3 4
3 5
4 6
5 6
</pre>
<p>Output:</p>
<pre>2
3
1 2 6
4
1 3 4 6
</pre></div></div>

## CSES - Static Range Sum Queries
<div class="md"><div class="md"><p>Given an array of <span class="math inline">n</span> integers, your task is to process <span class="math inline">q</span> queries of the form: what is the sum of values in range <span class="math inline">[a,b]</span>?</p>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">n</span> and <span class="math inline">q</span>: the number of values and queries.</p>
<p>The second line has <span class="math inline">n</span> integers <span class="math inline">x_1,x_2,\dots,x_n</span>: the array values.</p>
<p>Finally, there are <span class="math inline">q</span> lines describing the queries. Each line has two integers <span class="math inline">a</span> and <span class="math inline">b</span>: what is the sum of values in range <span class="math inline">[a,b]</span>?</p>
<h1 id="output">Output</h1>
<p>Print the result of each query.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n,q <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= x_i <= 10^9</span></li>
<li><span class="math inline">1 <= a <= b <= n</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>8 4
3 2 4 5 1 1 5 3
2 4
5 6
1 8
3 3
</pre>
<p>Output:</p>
<pre>11
2
24
4
</pre></div></div>

## CSES - Static Range Minimum Queries
<div class="md"><div class="md"><p>Given an array of <span class="math inline">n</span> integers, your task is to process <span class="math inline">q</span> queries of the form: what is the minimum value in range <span class="math inline">[a,b]</span>?</p>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">n</span> and <span class="math inline">q</span>: the number of values and queries.</p>
<p>The second line has <span class="math inline">n</span> integers <span class="math inline">x_1,x_2,\dots,x_n</span>: the array values.</p>
<p>Finally, there are <span class="math inline">q</span> lines describing the queries. Each line has two integers <span class="math inline">a</span> and <span class="math inline">b</span>: what is the minimum value in range <span class="math inline">[a,b]</span>?</p>
<h1 id="output">Output</h1>
<p>Print the result of each query.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n,q <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= x_i <= 10^9</span></li>
<li><span class="math inline">1 <= a <= b <= n</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>8 4
3 2 4 5 1 1 5 3
2 4
5 6
1 8
3 3
</pre>
<p>Output:</p>
<pre>2
1
1
4
</pre></div></div>

## CSES - Dynamic Range Sum Queries
<div class="md"><div class="md"><p>Given an array of <span class="math inline">n</span> integers, your task is to process <span class="math inline">q</span> queries of the following types:</p>
<ol>
<li>update the value at position <span class="math inline">k</span> to <span class="math inline">u</span></li>
<li>what is the sum of values in range <span class="math inline">[a,b]</span>?</li>
</ol>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">n</span> and <span class="math inline">q</span>: the number of values and queries.</p>
<p>The second line has <span class="math inline">n</span> integers <span class="math inline">x_1,x_2,\dots,x_n</span>: the array values.</p>
<p>Finally, there are <span class="math inline">q</span> lines describing the queries. Each line has three integers: either "<span class="math inline">1</span> <span class="math inline">k</span> <span class="math inline">u</span>" or "<span class="math inline">2</span> <span class="math inline">a</span> <span class="math inline">b</span>".</p>
<h1 id="output">Output</h1>
<p>Print the result of each query of type 2.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n,q <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= x_i, u <= 10^9</span></li>
<li><span class="math inline">1 <= k <= n</span></li>
<li><span class="math inline">1 <= a <= b <= n</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>8 4
3 2 4 5 1 1 5 3
2 1 4
2 5 6
1 3 1
2 1 4
</pre>
<p>Output:</p>
<pre>14
2
11
</pre></div></div>

## CSES - Dynamic Range Minimum Queries
<div class="md"><div class="md"><p>Given an array of <span class="math inline">n</span> integers, your task is to process <span class="math inline">q</span> queries of the following types:</p>
<ol>
<li>update the value at position <span class="math inline">k</span> to <span class="math inline">u</span></li>
<li>what is the minimum value in range <span class="math inline">[a,b]</span>?</li>
</ol>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">n</span> and <span class="math inline">q</span>: the number of values and queries.</p>
<p>The second line has <span class="math inline">n</span> integers <span class="math inline">x_1,x_2,\dots,x_n</span>: the array values.</p>
<p>Finally, there are <span class="math inline">q</span> lines describing the queries. Each line has three integers: either "<span class="math inline">1</span> <span class="math inline">k</span> <span class="math inline">u</span>" or "<span class="math inline">2</span> <span class="math inline">a</span> <span class="math inline">b</span>".</p>
<h1 id="output">Output</h1>
<p>Print the result of each query of type 2.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n,q <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= x_i, u <= 10^9</span></li>
<li><span class="math inline">1 <= k <= n</span></li>
<li><span class="math inline">1 <= a <= b <= n</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>8 4
3 2 4 5 1 1 5 3
2 1 4
2 5 6
1 2 3
2 1 4
</pre>
<p>Output:</p>
<pre>2
1
3
</pre></div></div>

## CSES - Range Xor Queries
<div class="md"><div class="md"><p>Given an array of <span class="math inline">n</span> integers, your task is to process <span class="math inline">q</span> queries of the form: what is the xor sum of values in range <span class="math inline">[a,b]</span>?</p>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">n</span> and <span class="math inline">q</span>: the number of values and queries.</p>
<p>The second line has <span class="math inline">n</span> integers <span class="math inline">x_1,x_2,\dots,x_n</span>: the array values.</p>
<p>Finally, there are <span class="math inline">q</span> lines describing the queries. Each line has two integers <span class="math inline">a</span> and <span class="math inline">b</span>: what is the xor sum of values in range <span class="math inline">[a,b]</span>?</p>
<h1 id="output">Output</h1>
<p>Print the result of each query.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n,q <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= x_i <= 10^9</span></li>
<li><span class="math inline">1 <= a <= b <= n</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>8 4
3 2 4 5 1 1 5 3
2 4
5 6
1 8
3 3
</pre>
<p>Output:</p>
<pre>3
0
6
4
</pre></div></div>

## CSES - Range Update Queries
<div class="md"><div class="md"><p>Given an array of <span class="math inline">n</span> integers, your task is to process <span class="math inline">q</span> queries of the following types:</p>
<ol>
<li>increase each value in range <span class="math inline">[a,b]</span> by <span class="math inline">u</span></li>
<li>what is the value at position <span class="math inline">k</span>?</li>
</ol>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">n</span> and <span class="math inline">q</span>: the number of values and queries.</p>
<p>The second line has <span class="math inline">n</span> integers <span class="math inline">x_1,x_2,\dots,x_n</span>: the array values.</p>
<p>Finally, there are <span class="math inline">q</span> lines describing the queries. Each line has three integers: either "<span class="math inline">1</span> <span class="math inline">a</span> <span class="math inline">b</span> <span class="math inline">u</span>" or "<span class="math inline">2</span> <span class="math inline">k</span>".</p>
<h1 id="output">Output</h1>
<p>Print the result of each query of type 2.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n,q <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= x_i, u <= 10^9</span></li>
<li><span class="math inline">1 <= k <= n</span></li>
<li><span class="math inline">1 <= a <= b <= n</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>8 3
3 2 4 5 1 1 5 3
2 4
1 2 5 1
2 4
</pre>
<p>Output:</p>
<pre>5
6
</pre></div></div>

## CSES - Forest Queries
<div class="md"><div class="md"><p>You are given an <span class="math inline">n x n</span> grid representing the map of a forest. Each square is either empty or contains a tree. The upper-left square has coordinates <span class="math inline">(1,1)</span>, and the lower-right square has coordinates <span class="math inline">(n,n)</span>.</p>
<p>Your task is to process <span class="math inline">q</span> queries of the form: how many trees are inside a given rectangle in the forest?</p>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">n</span> and <span class="math inline">q</span>: the size of the forest and the number of queries.</p>
<p>Then, there are <span class="math inline">n</span> lines describing the forest. Each line has <span class="math inline">n</span> characters: <code>.</code> is an empty square and <code>*</code> is a tree.</p>
<p>Finally, there are <span class="math inline">q</span> lines describing the queries. Each line has four integers <span class="math inline">y_1</span>, <span class="math inline">x_1</span>, <span class="math inline">y_2</span>, <span class="math inline">x_2</span> corresponding to the corners of a rectangle.</p>
<h1 id="output">Output</h1>
<p>Print the number of trees inside each rectangle.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 1000</span></li>
<li><span class="math inline">1 <= q <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= y_1 <= y_2 <= n</span></li>
<li><span class="math inline">1 <= x_1 <= x_2 <= n</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>4 3
.*..
*.**
**..
****
2 2 3 4
3 1 3 1
1 1 2 2
</pre>
<p>Output:</p>
<pre>3
1
2
</pre></div></div>

## CSES - Hotel Queries
<div class="md"><div class="md"><p>There are <span class="math inline">n</span> hotels on a street. For each hotel you know the number of free rooms. Your task is to assign hotel rooms for groups of tourists. All members of a group want to stay in the same hotel.</p>
<p>The groups will come to you one after another, and you know for each group the number of rooms it requires. You always assign a group to the first hotel having enough rooms. After this, the number of free rooms in the hotel decreases.</p>
<h1 id="input">Input</h1>
<p>The first input line contains two integers <span class="math inline">n</span> and <span class="math inline">m</span>: the number of hotels and the number of groups. The hotels are numbered <span class="math inline">1,2,...,n</span>.</p>
<p>The next line contains <span class="math inline">n</span> integers <span class="math inline">h_1,h_2,...,h_n</span>: the number of free rooms in each hotel.</p>
<p>The last line contains <span class="math inline">m</span> integers <span class="math inline">r_1,r_2,...,r_m</span>: the number of rooms each group requires.</p>
<h1 id="output">Output</h1>
<p>Print the assigned hotel for each group. If a group cannot be assigned a hotel, print 0 instead.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n,m <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= h_i <= 10^9</span></li>
<li><span class="math inline">1 <= r_i <= 10^9</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>8 5
3 2 4 1 5 5 2 6
4 4 7 1 1
</pre>
<p>Output:</p>
<pre>3 5 0 1 1
</pre></div></div>

## CSES - List Removals
<div class="md"><div class="md"><p>You are given a list consisting of <span class="math inline">n</span> integers. Your task is to remove elements from the list at given positions, and report the removed elements.</p>
<h1 id="input">Input</h1>
<p>The first input line has an integer <span class="math inline">n</span>: the initial size of the list. During the process, the elements are numbered <span class="math inline">1,2,\dots,k</span> where <span class="math inline">k</span> is the current size of the list.</p>
<p>The second line has <span class="math inline">n</span> integers <span class="math inline">x_1,x_2,\dots,x_n</span>: the contents of the list.</p>
<p>The last line has <span class="math inline">n</span> integers <span class="math inline">p_1,p_2,\dots,p_n</span>: the positions of the elements to be removed.</p>
<h1 id="output">Output</h1>
<p>Print the elements in the order they are removed.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= x_i <= 10^9</span></li>
<li><span class="math inline">1 <= p_i <= n-i+1</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5
2 6 1 4 2
3 1 3 1 1
</pre>
<p>Output:</p>
<pre>1 2 2 6 4
</pre>
<p>Explanation: The contents of the list are <span class="math inline">[2,6,1,4,2]</span>, <span class="math inline">[2,6,4,2]</span>, <span class="math inline">[6,4,2]</span>, <span class="math inline">[6,4]</span>, <span class="math inline">[4]</span> and <span class="math inline">[]</span>.</p>
</div></div>

## CSES - Salary Queries
<div class="md"><div class="md"><p>A company has <span class="math inline">n</span> employees with certain salaries. Your task is to keep track of the salaries and process queries.</p>
<h1 id="input">Input</h1>
<p>The first input line contains two integers <span class="math inline">n</span> and <span class="math inline">q</span>: the number of employees and queries. The employees are numbered <span class="math inline">1,2,...,n</span>.</p>
<p>The next line has <span class="math inline">n</span> integers <span class="math inline">p_1,p_2,...,p_n</span>: each employee's salary.</p>
<p>After this, there are <span class="math inline">q</span> lines describing the queries. Each line has one of the following forms:</p>
<ul>
<li><code>!</code> <span class="math inline">k</span> <span class="math inline">x</span>: change the salary of employee <span class="math inline">k</span> to <span class="math inline">x</span></li>
<li><code>?</code> <span class="math inline">a</span> <span class="math inline">b</span>: count the number of employees whose salary is between <span class="math inline">a ... b</span></li>
</ul>
<h1 id="output">Output</h1>
<p>Print the answer to each <code>?</code> query.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n, q <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= p_i <= 10^9</span></li>
<li><span class="math inline">1 <= k <= n</span></li>
<li><span class="math inline">1 <= x <= 10^9</span></li>
<li><span class="math inline">1 <= a <= b <= 10^9</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5 3
3 7 2 2 5
? 2 3
! 3 6
? 2 3
</pre>
<p>Output:</p>
<pre>3
2
</pre></div></div>

## CSES - Prefix Sum Queries
<div class="md"><div class="md"><p>Given an array of <span class="math inline">n</span> integers, your task is to process <span class="math inline">q</span> queries of the following types:</p>
<ol>
<li>update the value at position <span class="math inline">k</span> to <span class="math inline">u</span></li>
<li>what is the maximum prefix sum in range <span class="math inline">[a,b]</span>?</li>
</ol>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">n</span> and <span class="math inline">q</span>: the number of values and queries.</p>
<p>The second line has <span class="math inline">n</span> integers <span class="math inline">x_1,x_2,\dots,x_n</span>: the array values.</p>
<p>Finally, there are <span class="math inline">q</span> lines describing the queries. Each line has three integers: either "<span class="math inline">1</span> <span class="math inline">k</span> <span class="math inline">u</span>" or "<span class="math inline">2</span> <span class="math inline">a</span> <span class="math inline">b</span>".</p>
<h1 id="output">Output</h1>
<p>Print the result of each query of type 2.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n,q <= 2 . 10^5</span></li>
<li><span class="math inline">-10^9 <= x_i, u <= 10^9</span></li>
<li><span class="math inline">1 <= k <= n</span></li>
<li><span class="math inline">1 <= a <= b <= n</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>8 4
1 2 -1 3 1 -5 1 4
2 2 6
1 4 -2
2 2 6
2 3 4
</pre>
<p>Output:</p>
<pre>5
2
0
</pre></div></div>

## CSES - Pizzeria Queries
<div class="md"><div class="md"><p>There are <span class="math inline">n</span> buildings on a street, numbered <span class="math inline">1,2,\dots,n</span>. Each building has a pizzeria and an apartment.</p>
<p>The pizza price in building <span class="math inline">k</span> is <span class="math inline">p_k</span>. If you order a pizza from building <span class="math inline">a</span> to building <span class="math inline">b</span>, its price (with delivery) is <span class="math inline">p_a+|a-b|</span>.</p>
<p>Your task is to process two types of queries:</p>
<ol>
<li>The pizza price <span class="math inline">p_k</span> in building <span class="math inline">k</span> becomes <span class="math inline">x</span>.</li>
<li>You are in building <span class="math inline">k</span> and want to order a pizza. What is the minimum price?</li>
</ol>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">n</span> and <span class="math inline">q</span>: the number of buildings and queries.</p>
<p>The second line has <span class="math inline">n</span> integers <span class="math inline">p_1,p_2,\dots,p_n</span>: the initial pizza price in each building.</p>
<p>Finally, there are <span class="math inline">q</span> lines that describe the queries. Each line is either "1 <span class="math inline">k</span> <span class="math inline">x</span>" or "2 <span class="math inline">k</span>".</p>
<h1 id="output">Output</h1>
<p>Print the answer for each query of type 2.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n,q <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= p_i, x <= 10^9</span></li>
<li><span class="math inline">1 <= k <= n</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>6 3
8 6 4 5 7 5
2 2
1 5 1
2 2
</pre>
<p>Output:</p>
<pre>5
4
</pre></div></div>

## CSES - Subarray Sum Queries
<div class="md"><div class="md"><p>There is an array consisting of <span class="math inline">n</span> integers. Some values of the array will be updated, and after each update, your task is to report the maximum subarray sum in the array. </p>
<h1 id="input">Input</h1>
<p>The first input line contains integers <span class="math inline">n</span> and <span class="math inline">m</span>: the size of the array and the number of updates. The array is indexed <span class="math inline">1,2,...,n</span>.</p>
<p>The next line has <span class="math inline">n</span> integers: <span class="math inline">x_1,x_2,...,x_n</span>: the initial contents of the array.</p>
<p>Then there are <span class="math inline">m</span> lines describing the changes. Each line has two integers <span class="math inline">k</span> and <span class="math inline">x</span>: the value at position <span class="math inline">k</span> becomes <span class="math inline">x</span>.</p>
<h1 id="output">Output</h1>
<p>After each update, print the maximum subarray sum. Empty subarrays (with sum <span class="math inline">0</span>) are allowed.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n, m <= 2 . 10^5</span></li>
<li><span class="math inline">-10^9 <= x_i <= 10^9</span></li>
<li><span class="math inline">1 <= k <= n</span></li>
<li><span class="math inline">-10^9 <= x <= 10^9</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5 3
1 2 -3 5 -1
2 6
3 1
2 -2
</pre>
<p>Output:</p>
<pre>9
13
6
</pre></div></div>

## CSES - Distinct Values Queries
<div class="md"><div class="md"><p>You are given an array of <span class="math inline">n</span> integers and <span class="math inline">q</span> queries of the form: how many distinct values are there in a range <span class="math inline">[a,b]</span>?</p>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">n</span> and <span class="math inline">q</span>: the array size and number of queries.</p>
<p>The next line has <span class="math inline">n</span> integers <span class="math inline">x_1,x_2,\dots,x_n</span>: the array values.</p>
<p>Finally, there are <span class="math inline">q</span> lines describing the queries. Each line has two integers <span class="math inline">a</span> and <span class="math inline">b</span>.</p>
<h1 id="output">Output</h1>
<p>For each query, print the number of distinct values in the range.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n,q <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= x_i <= 10^9</span></li>
<li><span class="math inline">1 <= a <= b <= n</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5 3
3 2 3 1 2
1 3
2 4
1 5
</pre>
<p>Output:</p>
<pre>2
3
3
</pre></div></div>

## CSES - Increasing Array Queries
<div class="md"><div class="md"><p>You are given an array that consists of <span class="math inline">n</span> integers. The array elements are indexed <span class="math inline">1,2,\dots,n</span>.</p>
<p>You can modify the array using the following operation: choose an array element and increase its value by one.</p>
<p>Your task is to process <span class="math inline">q</span> queries of the form: when we consider a subarray from position <span class="math inline">a</span> to position <span class="math inline">b</span>, what is the minimum number of operations after which the subarray is increasing?</p>
<p>An array is increasing if each element is greater than or equal with the previous element.</p>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">n</span> and <span class="math inline">q</span>: the size of the array and the number of queries.</p>
<p>The next line has <span class="math inline">n</span> integers <span class="math inline">x_1,x_2,\dots,x_n</span>: the contents of the array.</p>
<p>Finally, there are <span class="math inline">q</span> lines that describe the queries. Each line has two integers <span class="math inline">a</span> and <span class="math inline">b</span>: the starting and ending position of a subarray.</p>
<h1 id="output">Output</h1>
<p>For each query, print the minimum number of operations.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n,q <= 2.10^5</span></li>
<li><span class="math inline">1 <= x_i <= 10^9</span></li>
<li><span class="math inline">1 <= a <= b <= n</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5 3
2 10 4 2 5
3 5
2 2
1 4
</pre>
<p>Output:</p>
<pre>2
0
14
</pre></div></div>

## CSES - Forest Queries II
<div class="md"><div class="md"><p>You are given an <span class="math inline">n x n</span> grid representing the map of a forest. Each square is either empty or has a tree. Your task is to process <span class="math inline">q</span> queries of the following types:</p>
<ol>
<li>Change the state (empty/tree) of a square.</li>
<li>How many trees are inside a rectangle in the forest?</li>
</ol>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">n</span> and <span class="math inline">q</span>: the size of the forest and the number of queries.</p>
<p>Then, there are <span class="math inline">n</span> lines describing the forest. Each line has <span class="math inline">n</span> characters: <code>.</code> is an empty square and <code>*</code> is a tree.</p>
<p>Finally, there are <span class="math inline">q</span> lines describing the queries. The format of each line is either "<span class="math inline">1</span> <span class="math inline">y</span> <span class="math inline">x</span>" or "2 <span class="math inline">y_1</span> <span class="math inline">x_1</span> <span class="math inline">y_2</span> <span class="math inline">x_2</span>".</p>
<h1 id="output">Output</h1>
<p>Print the answer to each query of the second type.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 1000</span></li>
<li><span class="math inline">1 <= q <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= y,x <= n</span></li>
<li><span class="math inline">1 <= y_1 <= y_2 <= n</span></li>
<li><span class="math inline">1 <= x_1 <= x_2 <= n</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>4 3
.*..
*.**
**..
****
2 2 2 3 4
1 3 3
2 2 2 3 4
</pre>
<p>Output:</p>
<pre>3
4
</pre></div></div>

## CSES - Range Updates and Sums
<div class="md"><div class="md"><p>Your task is to maintain an array of <span class="math inline">n</span> values and efficiently process the following types of queries:</p>
<ol>
<li>Increase each value in range <span class="math inline">[a,b]</span> by <span class="math inline">x</span>.</li>
<li>Set each value in range <span class="math inline">[a,b]</span> to <span class="math inline">x</span>.</li>
<li>Calculate the sum of values in range <span class="math inline">[a,b]</span>.</li>
</ol>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">n</span> and <span class="math inline">q</span>: the array size and the number of queries.</p>
<p>The next line has <span class="math inline">n</span> values <span class="math inline">t_1,t_2,\dots,t_n</span>: the initial contents of the array.</p>
<p>Finally, there are <span class="math inline">q</span> lines describing the queries. The format of each line is one of the following: "1 <span class="math inline">a</span> <span class="math inline">b</span> <span class="math inline">x</span>",  "2 <span class="math inline">a</span> <span class="math inline">b</span> <span class="math inline">x</span>", or "3 <span class="math inline">a</span> <span class="math inline">b</span>". </p>
<h1 id="output">Output</h1>
<p>Print the answer to each sum query.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n, q <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= t_i, x <= 10^6</span></li>
<li><span class="math inline">1 <= a <= b <= n</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>6 5
2 3 1 1 5 3
3 3 5
1 2 4 2
3 3 5
2 2 4 5
3 3 5
</pre>
<p>Output:</p>
<pre>7
11
15
</pre></div></div>

## CSES - Polynomial Queries
<div class="md"><div class="md"><p>Your task is to maintain an array of <span class="math inline">n</span> values and efficiently process the following types of queries:</p>
<ol>
<li>Increase the first value in range <span class="math inline">[a,b]</span> by <span class="math inline">1</span>, the second value by <span class="math inline">2</span>, the third value by <span class="math inline">3</span>, and so on.</li>
<li>Calculate the sum of values in range <span class="math inline">[a,b]</span>.</li>
</ol>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">n</span> and <span class="math inline">q</span>: the size of the array and the number of queries.</p>
<p>The next line has <span class="math inline">n</span> values <span class="math inline">t_1,t_2,\dots,t_n</span>: the initial contents of the array.</p>
<p>Finally, there are <span class="math inline">q</span> lines describing the queries. The format of each line is either "1 <span class="math inline">a</span> <span class="math inline">b</span>" or "2 <span class="math inline">a</span> <span class="math inline">b</span>".</p>
<h1 id="output">Output</h1>
<p>Print the answer to each sum query.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n, q <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= t_i <= 10^6</span></li>
<li><span class="math inline">1 <= a <= b <= n</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5 3
4 2 3 1 7
2 1 5
1 1 5
2 1 5
</pre>
<p>Output:</p>
<pre>17
32
</pre></div></div>

## CSES - Range Queries and Copies
<div class="md"><div class="md"><p>Your task is to maintain a list of arrays which initially has a single array. You have to process the following types of queries:</p>
<ol>
<li>Set the value <span class="math inline">a</span> in array <span class="math inline">k</span> to <span class="math inline">x</span>.</li>
<li>Calculate the sum of values in range <span class="math inline">[a,b]</span> in array <span class="math inline">k</span>.</li>
<li>Create a copy of array <span class="math inline">k</span> and add it to the end of the list.</li>
</ol>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">n</span> and <span class="math inline">q</span>: the array size and the number of queries.</p>
<p>The next line has <span class="math inline">n</span> integers <span class="math inline">t_1,t_2,...,t_n</span>: the initial contents of the array.</p>
<p>Finally, there are <span class="math inline">q</span> lines describing the queries. The format of each line is one of the following: "1 <span class="math inline">k</span> <span class="math inline">a</span> <span class="math inline">x</span>", "2 <span class="math inline">k</span> <span class="math inline">a</span> <span class="math inline">b</span>" or "3 <span class="math inline">k</span>".</p>
<h1 id="output">Output</h1>
<p>Print the answer to each sum query.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n, q <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= t_i, x <= 10^9</span></li>
<li><span class="math inline">1 <= a <= b <= n</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5 6
2 3 1 2 5
3 1
2 1 1 5
2 2 1 5
1 2 2 5
2 1 1 5
2 2 1 5
</pre>
<p>Output:</p>
<pre>13
13
13
15
</pre></div></div>

## CSES - Subordinates
<div class="md"><div class="md"><p>Given the structure of a company, your task is to calculate for each employee the number of their subordinates.</p>
<h1 id="input">Input</h1>
<p>The first input line has an integer <span class="math inline">n</span>: the number of employees. The employees are numbered <span class="math inline">1,2,\dots,n</span>, and employee <span class="math inline">1</span> is the general director of the company.</p>
<p>After this, there are <span class="math inline">n-1</span> integers: for each employee <span class="math inline">2,3,\dots,n</span> their direct boss in the company.</p>
<h1 id="output">Output</h1>
<p>Print <span class="math inline">n</span> integers: for each employee <span class="math inline">1,2,\dots,n</span> the number of their subordinates.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 2 . 10^5</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5
1 1 2 3
</pre>
<p>Output:</p>
<pre>4 1 1 0 0
</pre></div></div>

## CSES - Tree Matching
<div class="md"><div class="md"><p>You are given a tree consisting of <span class="math inline">n</span> nodes.</p>
<p>A <em>matching</em> is a set of edges where each node is an endpoint of at most one edge. What is the maximum number of edges in a matching?</p>
<h1 id="input">Input</h1>
<p>The first input line contains an integer <span class="math inline">n</span>: the number of nodes. The nodes are numbered <span class="math inline">1,2,...,n</span>.</p>
<p>Then there are <span class="math inline">n-1</span> lines describing the edges. Each line contains two integers <span class="math inline">a</span> and <span class="math inline">b</span>: there is an edge between nodes <span class="math inline">a</span> and <span class="math inline">b</span>.</p>
<h1 id="output">Output</h1>
<p>Print one integer: the maximum number of pairs.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= a,b <= n</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5
1 2
1 3
3 4
3 5
</pre>
<p>Output:</p>
<pre>2
</pre>
<p>Explanation: One possible matching is <span class="math inline">(1,2)</span> and <span class="math inline">(3,4)</span>.</p>
</div></div>

## CSES - Tree Diameter
<div class="md"><div class="md"><p>You are given a tree consisting of <span class="math inline">n</span> nodes.</p>
<p>The <em>diameter</em> of a tree is the maximum distance between two nodes. Your task is to determine the diameter of the tree.</p>
<h1 id="input">Input</h1>
<p>The first input line contains an integer <span class="math inline">n</span>: the number of nodes. The nodes are numbered <span class="math inline">1,2,...,n</span>.</p>
<p>Then there are <span class="math inline">n-1</span> lines describing the edges. Each line contains two integers <span class="math inline">a</span> and <span class="math inline">b</span>: there is an edge between nodes <span class="math inline">a</span> and <span class="math inline">b</span>.</p>
<h1 id="output">Output</h1>
<p>Print one integer: the diameter of the tree.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= a,b <= n</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5
1 2
1 3
3 4
3 5
</pre>
<p>Output:</p>
<pre>3
</pre>
<p>Explanation: The diameter corresponds to the path <span class="math inline">2 -> 1 -> 3 -> 5</span>.</p>
</div></div>

## CSES - Tree Distances I
<div class="md"><div class="md"><p>You are given a tree consisting of <span class="math inline">n</span> nodes.</p>
<p>Your task is to determine for each node the maximum distance to another node.</p>
<h1 id="input">Input</h1>
<p>The first input line contains an integer <span class="math inline">n</span>: the number of nodes. The nodes are numbered <span class="math inline">1,2,...,n</span>.</p>
<p>Then there are <span class="math inline">n-1</span> lines describing the edges. Each line contains two integers <span class="math inline">a</span> and <span class="math inline">b</span>: there is an edge between nodes <span class="math inline">a</span> and <span class="math inline">b</span>.</p>
<h1 id="output">Output</h1>
<p>Print <span class="math inline">n</span> integers: for each node <span class="math inline">1,2,...,n</span>, the maximum distance to another node.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= a,b <= n</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5
1 2
1 3
3 4
3 5
</pre>
<p>Output:</p>
<pre>2 3 2 3 3
</pre></div></div>

## CSES - Tree Distances II
<div class="md"><div class="md"><p>You are given a tree consisting of <span class="math inline">n</span> nodes.</p>
<p>Your task is to determine for each node the sum of the distances from the node to all other nodes.</p>
<h1 id="input">Input</h1>
<p>The first input line contains an integer <span class="math inline">n</span>: the number of nodes. The nodes are numbered <span class="math inline">1,2,...,n</span>.</p>
<p>Then there are <span class="math inline">n-1</span> lines describing the edges. Each line contains two integers <span class="math inline">a</span> and <span class="math inline">b</span>: there is an edge between nodes <span class="math inline">a</span> and <span class="math inline">b</span>.</p>
<h1 id="output">Output</h1>
<p>Print <span class="math inline">n</span> integers: for each node <span class="math inline">1,2,...,n</span>, the sum of the distances.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= a,b <= n</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5
1 2
1 3
3 4
3 5
</pre>
<p>Output:</p>
<pre>6 9 5 8 8
</pre></div></div>

## CSES - Company Queries I
<div class="md"><div class="md"><p>A company has <span class="math inline">n</span> employees, who form a tree hierarchy where each employee has a boss, except for the general director.</p>
<p>Your task is to process <span class="math inline">q</span> queries of the form: who is employee <span class="math inline">x</span>'s boss <span class="math inline">k</span> levels higher up in the hierarchy?</p>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">n</span> and <span class="math inline">q</span>: the number of employees and queries. The employees are numbered <span class="math inline">1,2,\dots,n</span>, and employee <span class="math inline">1</span> is the general director.</p>
<p>The next line has <span class="math inline">n-1</span> integers <span class="math inline">e_2,e_3,\dots,e_n</span>: for each employee <span class="math inline">2,3,\dots,n</span> their boss.</p>
<p>Finally, there are <span class="math inline">q</span> lines describing the queries. Each line has two integers <span class="math inline">x</span> and <span class="math inline">k</span>: who is employee <span class="math inline">x</span>'s boss <span class="math inline">k</span> levels higher up?</p>
<h1 id="output">Output</h1>
<p>Print the answer for each query. If such a boss does not exist, print <span class="math inline">-1</span>.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n,q <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= e_i <= i-1</span></li>
<li><span class="math inline">1 <= x <= n</span></li>
<li><span class="math inline">1 <= k <= n</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5 3
1 1 3 3
4 1
4 2
4 3
</pre>
<p>Output:</p>
<pre>3
1
-1
</pre></div></div>

## CSES - Company Queries II
<div class="md"><div class="md"><p>A company has <span class="math inline">n</span> employees, who form a tree hierarchy where each employee has a boss, except for the general director.</p>
<p>Your task is to process <span class="math inline">q</span> queries of the form: who is the lowest common boss of employees <span class="math inline">a</span> and <span class="math inline">b</span> in the hierarchy?</p>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">n</span> and <span class="math inline">q</span>: the number of employees and queries. The employees are numbered <span class="math inline">1,2,\dots,n</span>, and employee <span class="math inline">1</span> is the general director.</p>
<p>The next line has <span class="math inline">n-1</span> integers <span class="math inline">e_2,e_3,\dots,e_n</span>: for each employee <span class="math inline">2,3,\dots,n</span> their boss.</p>
<p>Finally, there are <span class="math inline">q</span> lines describing the queries. Each line has two integers <span class="math inline">a</span> and <span class="math inline">b</span>: who is the lowest common boss of employees <span class="math inline">a</span> and <span class="math inline">b</span>?</p>
<h1 id="output">Output</h1>
<p>Print the answer for each query.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n,q <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= e_i <= i-1</span></li>
<li><span class="math inline">1 <= a,b <= n</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5 3
1 1 3 3
4 5
2 5
1 4
</pre>
<p>Output:</p>
<pre>3
1
1
</pre></div></div>

## CSES - Distance Queries
<div class="md"><div class="md"><p>You are given a tree consisting of <span class="math inline">n</span> nodes.</p>
<p>Your task is to process <span class="math inline">q</span> queries of the form: what is the distance between nodes <span class="math inline">a</span> and <span class="math inline">b</span>?</p>
<h1 id="input">Input</h1>
<p>The first input line contains two integers <span class="math inline">n</span> and <span class="math inline">q</span>: the number of nodes and queries. The nodes are numbered <span class="math inline">1,2,...,n</span>.</p>
<p>Then there are <span class="math inline">n-1</span> lines describing the edges. Each line contains two integers <span class="math inline">a</span> and <span class="math inline">b</span>: there is an edge between nodes <span class="math inline">a</span> and <span class="math inline">b</span>.</p>
<p>Finally, there are <span class="math inline">q</span> lines describing the queries. Each line contains two integer <span class="math inline">a</span> and <span class="math inline">b</span>: what is the distance between nodes <span class="math inline">a</span> and <span class="math inline">b</span>?</p>
<h1 id="output">Output</h1>
<p>Print <span class="math inline">q</span> integers: the answer to each query.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n, q <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= a,b <= n</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5 3
1 2
1 3
3 4
3 5
1 3
2 5
1 4
</pre>
<p>Output:</p>
<pre>1
3
2
</pre></div></div>

## CSES - Counting Paths
<div class="md"><div class="md"><p>You are given a tree consisting of <span class="math inline">n</span> nodes, and <span class="math inline">m</span> paths in the tree.</p>
<p>Your task is to calculate for each node the number of paths containing that node.</p>
<h1 id="input">Input</h1>
<p>The first input line contains integers <span class="math inline">n</span> and <span class="math inline">m</span>: the number of nodes and paths. The nodes are numbered <span class="math inline">1,2,...,n</span>.</p>
<p>Then there are <span class="math inline">n-1</span> lines describing the edges. Each line contains two integers <span class="math inline">a</span> and <span class="math inline">b</span>: there is an edge between nodes <span class="math inline">a</span> and <span class="math inline">b</span>.</p>
<p>Finally, there are <span class="math inline">m</span> lines describing the paths. Each line contains two integers <span class="math inline">a</span> and <span class="math inline">b</span>: there is a path between nodes <span class="math inline">a</span> and <span class="math inline">b</span>.</p>
<h1 id="output">Output</h1>
<p>Print <span class="math inline">n</span> integers: for each node <span class="math inline">1,2,...,n</span>, the number of paths containing that node.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n, m <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= a,b <= n</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5 3
1 2
1 3
3 4
3 5
1 3
2 5
1 4
</pre>
<p>Output:</p>
<pre>3 1 3 1 1
</pre></div></div>

## CSES - Subtree Queries
<div class="md"><div class="md"><p>You are given a rooted tree consisting of <span class="math inline">n</span> nodes. The nodes are numbered <span class="math inline">1,2,...,n</span>, and node <span class="math inline">1</span> is the root. Each node has a value.</p>
<p>Your task is to process following types of queries:</p>
<ol>
<li>change the value of node <span class="math inline">s</span> to <span class="math inline">x</span></li>
<li>calculate the sum of values in the subtree of node <span class="math inline">s</span></li>
</ol>
<h1 id="input">Input</h1>
<p>The first input line contains two integers <span class="math inline">n</span> and <span class="math inline">q</span>: the number of nodes and queries. The nodes are numbered <span class="math inline">1,2,...,n</span>.</p>
<p>The next line has <span class="math inline">n</span> integers <span class="math inline">v_1,v_2,...,v_n</span>: the value of each node.</p>
<p>Then there are <span class="math inline">n-1</span> lines describing the edges. Each line contans two integers <span class="math inline">a</span> and <span class="math inline">b</span>: there is an edge between nodes <span class="math inline">a</span> and <span class="math inline">b</span>.</p>
<p>Finally, there are <span class="math inline">q</span> lines describing the queries. Each query is either of the form "1 <span class="math inline">s</span> <span class="math inline">x</span>" or "2 <span class="math inline">s</span>".</p>
<h1 id="output">Output</h1>
<p>Print the answer to each query of type 2.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n, q <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= a,b, s <= n</span></li>
<li><span class="math inline">1 <= v_i, x <= 10^9</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5 3
4 2 5 2 1
1 2
1 3
3 4
3 5
2 3
1 5 3
2 3
</pre>
<p>Output:</p>
<pre>8
10
</pre></div></div>

## CSES - Path Queries
<div class="md"><div class="md"><p>You are given a rooted tree consisting of <span class="math inline">n</span> nodes. The nodes are numbered <span class="math inline">1,2,...,n</span>, and node <span class="math inline">1</span> is the root. Each node has a value.</p>
<p>Your task is to process following types of queries:</p>
<ol>
<li>change the value of node <span class="math inline">s</span> to <span class="math inline">x</span></li>
<li>calculate the sum of values on the path from the root to node <span class="math inline">s</span></li>
</ol>
<h1 id="input">Input</h1>
<p>The first input line contains two integers <span class="math inline">n</span> and <span class="math inline">q</span>: the number of nodes and queries. The nodes are numbered <span class="math inline">1,2,...,n</span>.</p>
<p>The next line has <span class="math inline">n</span> integers <span class="math inline">v_1,v_2,...,v_n</span>: the value of each node.</p>
<p>Then there are <span class="math inline">n-1</span> lines describing the edges. Each line contains two integers <span class="math inline">a</span> and <span class="math inline">b</span>: there is an edge between nodes <span class="math inline">a</span> and <span class="math inline">b</span>.</p>
<p>Finally, there are <span class="math inline">q</span> lines describing the queries. Each query is either of the form "1 <span class="math inline">s</span> <span class="math inline">x</span>" or "2 <span class="math inline">s</span>".</p>
<h1 id="output">Output</h1>
<p>Print the answer to each query of type 2.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n, q <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= a,b, s <= n</span></li>
<li><span class="math inline">1 <= v_i, x <= 10^9</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5 3
4 2 5 2 1
1 2
1 3
3 4
3 5
2 4
1 3 2
2 4
</pre>
<p>Output:</p>
<pre>11
8
</pre></div></div>

## CSES - Path Queries II
<div class="md"><div class="md"><p>You are given a tree consisting of <span class="math inline">n</span> nodes. The nodes are numbered <span class="math inline">1,2,...,n</span>. Each node has a value.</p>
<p>Your task is to process following types of queries:</p>
<ol>
<li>change the value of node <span class="math inline">s</span> to <span class="math inline">x</span></li>
<li>find the maximum value on the path between nodes <span class="math inline">a</span> and <span class="math inline">b</span>.</li>
</ol>
<h1 id="input">Input</h1>
<p>The first input line contains two integers <span class="math inline">n</span> and <span class="math inline">q</span>: the number of nodes and queries. The nodes are numbered <span class="math inline">1,2,...,n</span>.</p>
<p>The next line has <span class="math inline">n</span> integers <span class="math inline">v_1,v_2,...,v_n</span>: the value of each node.</p>
<p>Then there are <span class="math inline">n-1</span> lines describing the edges. Each line contains two integers <span class="math inline">a</span> and <span class="math inline">b</span>: there is an edge between nodes <span class="math inline">a</span> and <span class="math inline">b</span>.</p>
<p>Finally, there are <span class="math inline">q</span> lines describing the queries. Each query is either of the form "1 <span class="math inline">s</span> <span class="math inline">x</span>" or "2 <span class="math inline">a</span> <span class="math inline">b</span>".</p>
<h1 id="output">Output</h1>
<p>Print the answer to each query of type 2.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n, q <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= a,b, s <= n</span></li>
<li><span class="math inline">1 <= v_i, x <= 10^9</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5 3
2 4 1 3 3
1 2
1 3
2 4
2 5
2 3 5
1 2 2
2 3 5
</pre>
<p>Output:</p>
<pre>4 3
</pre></div></div>

## CSES - Distinct Colors
<div class="md"><div class="md"><p>You are given a rooted tree consisting of <span class="math inline">n</span> nodes. The nodes are numbered <span class="math inline">1,2,...,n</span>, and node <span class="math inline">1</span> is the root. Each node has a color.</p>
<p>Your task is to determine for each node the number of distinct colors in the subtree of the node.</p>
<h1 id="input">Input</h1>
<p>The first input line contains an integer <span class="math inline">n</span>: the number of nodes. The nodes are numbered <span class="math inline">1,2,...,n</span>.</p>
<p>The next line consists of <span class="math inline">n</span> integers <span class="math inline">c_1,c_2,...,c_n</span>: the color of each node.</p>
<p>Then there are <span class="math inline">n-1</span> lines describing the edges. Each line contains two integers <span class="math inline">a</span> and <span class="math inline">b</span>: there is an edge between nodes <span class="math inline">a</span> and <span class="math inline">b</span>.</p>
<h1 id="output">Output</h1>
<p>Print <span class="math inline">n</span> integers: for each node <span class="math inline">1,2,...,n</span>, the number of distinct colors.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= a,b <= n</span></li>
<li><span class="math inline">1 <= c_i <= 10^9</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5
2 3 2 2 1
1 2
1 3
3 4
3 5
</pre>
<p>Output:</p>
<pre>3 1 2 1 1
</pre></div></div>

## CSES - Finding a Centroid
<div class="md"><div class="md"><p>Given a tree of <span class="math inline">n</span> nodes, your task is to find a <em>centroid</em>, i.e., a node such that when it is appointed the root of the tree, each subtree has at most <span class="math inline">\lfloor n/2 \rfloor</span> nodes.</p>
<h1 id="input">Input</h1>
<p>The first input line contains an integer <span class="math inline">n</span>: the number of nodes. The nodes are numbered <span class="math inline">1,2,…,n</span>.</p>
<p>Then there are <span class="math inline">n-1</span> lines describing the edges. Each line contains two integers <span class="math inline">a</span> and <span class="math inline">b</span>: there is an edge between nodes <span class="math inline">a</span> and <span class="math inline">b</span>.</p>
<h1 id="output">Output</h1>
<p>Print one integer: a centroid node. If there are several possibilities, you can choose any of them.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= a,b <= n</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5
1 2
2 3
3 4
3 5
</pre>
<p>Output:</p>
<pre>3
</pre></div></div>

## CSES - Fixed-Length Paths I
<div class="md"><div class="md"><p>Given a tree of <span class="math inline">n</span> nodes, your task is to count the number of distinct paths that consist of exactly <span class="math inline">k</span> edges.</p>
<h1 id="input">Input</h1>
<p>The first input line contains two integers <span class="math inline">n</span> and <span class="math inline">k</span>: the number of nodes and the path length. The nodes are numbered <span class="math inline">1,2,...,n</span>.</p>
<p>Then there are <span class="math inline">n-1</span> lines describing the edges. Each line contains two integers <span class="math inline">a</span> and <span class="math inline">b</span>: there is an edge between nodes <span class="math inline">a</span> and <span class="math inline">b</span>.</p>
<h1 id="output">Output</h1>
<p>Print one integer: the number of paths.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= k <= n <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= a,b <= n</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5 2
1 2
2 3
3 4
3 5
</pre>
<p>Output:</p>
<pre>4
</pre></div></div>

## CSES - Fixed-Length Paths II
<div class="md"><div class="md"><p>Given a tree of <span class="math inline">n</span> nodes, your task is to count the number of distinct paths that have at least <span class="math inline">k_1</span> and at most <span class="math inline">k_2</span> edges.</p>
<h1 id="input">Input</h1>
<p>The first input line contains three integers <span class="math inline">n</span>, <span class="math inline">k_1</span> and <span class="math inline">k_2</span>: the number of nodes and the path lengths. The nodes are numbered <span class="math inline">1,2,...,n</span>.</p>
<p>Then there are <span class="math inline">n-1</span> lines describing the edges. Each line contains two integers <span class="math inline">a</span> and <span class="math inline">b</span>: there is an edge between nodes <span class="math inline">a</span> and <span class="math inline">b</span>.</p>
<h1 id="output">Output</h1>
<p>Print one integer: the number of paths.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= k_1 <= k_2 <= n <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= a,b <= n</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5 2 3
1 2
2 3
3 4
3 5
</pre>
<p>Output:</p>
<pre>6
</pre></div></div>

## CSES - Josephus Queries
<div class="md"><div class="md"><p>Consider a game where there are <span class="math inline">n</span> children (numbered <span class="math inline">1,2,\dots,n</span>) in a circle. During the game, every second child is removed from the circle, until there are no children left.</p>
<p>Your task is to process <span class="math inline">q</span> queries of the form: "when there are <span class="math inline">n</span> children, who is the <span class="math inline">k</span>th child that will be removed?"</p>
<h1 id="input">Input</h1>
<p>The first input line has an integer <span class="math inline">q</span>: the number of queries.</p>
<p>After this, there are <span class="math inline">q</span> lines that describe the queries. Each line has two integers <span class="math inline">n</span> and <span class="math inline">k</span>: the number of children and the position of the child.</p>
<h1 id="output">Output</h1>
<p>Print <span class="math inline">q</span> integers: the answer for each query.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= q <= 10^5</span></li>
<li><span class="math inline">1 <= k <= n <= 10^9</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>4
7 1
7 3
2 2
1337 1313
</pre>
<p>Output:</p>
<pre>2
6
1
1107
</pre></div></div>

## CSES - Exponentiation
<div class="md"><div class="md"><p>Your task is to efficiently calculate values <span class="math inline">a^b</span> modulo <span class="math inline">10^9+7</span>.</p>
<p>Note that in this task we assume that <span class="math inline">0^0=1</span>.</p>
<h1 id="input">Input</h1>
<p>The first input line contains an integer <span class="math inline">n</span>: the number of calculations.</p>
<p>After this, there are <span class="math inline">n</span> lines, each containing two integers <span class="math inline">a</span> and <span class="math inline">b</span>.</p>
<h1 id="output">Output</h1>
<p>Print each value <span class="math inline">a^b</span> modulo <span class="math inline">10^9+7</span>.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 2 . 10^5</span></li>
<li><span class="math inline">0 <= a,b <= 10^9</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>3
3 4
2 8
123 123
</pre>
<p>Output:</p>
<pre>81
256
921450052
</pre></div></div>

## CSES - Exponentiation II
<div class="md"><div class="md"><p>Your task is to efficiently calculate values <span class="math inline">a^{b^c}</span> modulo <span class="math inline">10^9+7</span>.</p>
<p>Note that in this task we assume that <span class="math inline">0^0=1</span>.</p>
<h1 id="input">Input</h1>
<p>The first input line has an integer <span class="math inline">n</span>: the number of calculations.</p>
<p>After this, there are <span class="math inline">n</span> lines, each containing three integers <span class="math inline">a</span>, <span class="math inline">b</span> and <span class="math inline">c</span>.</p>
<h1 id="output">Output</h1>
<p>Print each value <span class="math inline">a^{b^c}</span> modulo <span class="math inline">10^9+7</span>.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 10^5</span></li>
<li><span class="math inline">0 <= a,b,c <= 10^9</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>3
3 7 1
15 2 2
3 4 5
</pre>
<p>Output:</p>
<pre>2187
50625
763327764
</pre></div></div>

## CSES - Counting Divisors
<div class="md"><div class="md"><p>Given <span class="math inline">n</span> integers, your task is to report for each integer the number of its divisors.</p>
<p>For example, if <span class="math inline">x=18</span>, the correct answer is <span class="math inline">6</span> because its divisors are <span class="math inline">1,2,3,6,9,18</span>.</p>
<h1 id="input">Input</h1>
<p>The first input line has an integer <span class="math inline">n</span>: the number of integers.</p>
<p>After this, there are <span class="math inline">n</span> lines, each containing an integer <span class="math inline">x</span>.</p>
<h1 id="output">Output</h1>
<p>For each integer, print the number of its divisors.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 10^5</span></li>
<li><span class="math inline">1 <= x <= 10^6</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>3
16
17
18
</pre>
<p>Output:</p>
<pre>5
2
6
</pre></div></div>

## CSES - Common Divisors
<div class="md"><div class="md"><p>You are given an array of <span class="math inline">n</span> positive integers. Your task is to find two integers such that their greatest common divisor is as large as possible.</p>
<h1 id="input">Input</h1>
<p>The first input line has an integer <span class="math inline">n</span>: the size of the array.</p>
<p>The second line has <span class="math inline">n</span> integers <span class="math inline">x_1,x_2,...,x_n</span>: the contents of the array.</p>
<h1 id="output">Output</h1>
<p>Print the maximum greatest common divisor.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">2 <= n <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= x_i <= 10^6</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5
3 14 15 7 9
</pre>
<p>Output:</p>
<pre>7
</pre></div></div>

## CSES - Sum of Divisors
<div class="md"><div class="md"><p>Let <span class="math inline">\sigma(n)</span> denote the sum of divisors of an integer <span class="math inline">n</span>. For example, <span class="math inline">\sigma(12)=1+2+3+4+6+12=28</span>.</p>
<p>Your task is to calculate the sum <span class="math inline">\sum_{i=1}^n \sigma(i)</span> modulo <span class="math inline">10^9+7</span>.</p>
<h1 id="input">Input</h1>
<p>The only input line has an integer <span class="math inline">n</span>.</p>
<h1 id="output">Output</h1>
<p>Print <span class="math inline">\sum_{i=1}^n \sigma(i)</span> modulo <span class="math inline">10^9+7</span>.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 10^{12}</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5
</pre>
<p>Output:</p>
<pre>21
</pre></div></div>

## CSES - Divisor Analysis
<div class="md"><div class="md"><p>Given an integer, your task is to find the number, sum and product of its divisors. As an example, let us consider the number <span class="math inline">12</span>:</p>
<ul>
<li>the number of divisors is <span class="math inline">6</span> (they are <span class="math inline">1</span>, <span class="math inline">2</span>, <span class="math inline">3</span>, <span class="math inline">4</span>, <span class="math inline">6</span>, <span class="math inline">12</span>)</li>
<li>the sum of divisors is <span class="math inline">1+2+3+4+6+12=28</span></li>
<li>the product of divisors is <span class="math inline">1 . 2 . 3 . 4 . 6 . 12 = 1728</span></li>
</ul>
<p>Since the input number may be large, it is given as a prime factorization.</p>
<h1 id="input">Input</h1>
<p>The first line has an integer <span class="math inline">n</span>: the number of parts in the prime factorization.</p>
<p>After this, there are <span class="math inline">n</span> lines that describe the factorization. Each line has two numbers <span class="math inline">x</span> and <span class="math inline">k</span> where <span class="math inline">x</span> is a prime and <span class="math inline">k</span> is its power.</p>
<h1 id="output">Output</h1>
<p>Print three integers modulo <span class="math inline">10^9+7</span>: the number, sum and product of the divisors.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 10^5</span></li>
<li><span class="math inline">2 <= x <= 10^6</span></li>
<li>each <span class="math inline">x</span> is a distinct prime</li>
<li><span class="math inline">1 <= k <= 10^9</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>2
2 2
3 1
</pre>
<p>Output:</p>
<pre>6 28 1728
</pre></div></div>

## CSES - Prime Multiples
<div class="md"><div class="md"><p>You are given <span class="math inline">k</span> distinct prime numbers <span class="math inline">a_1,a_2,...,a_k</span> and an integer <span class="math inline">n</span>.</p>
<p>Your task is to calculate how many of the first <span class="math inline">n</span> positive integers are divisible by at least one of the given prime numbers.</p>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">n</span> and <span class="math inline">k</span>.</p>
<p>The second line has <span class="math inline">k</span> prime numbers <span class="math inline">a_1,a_2,...,a_k</span>.</p>
<h1 id="output">Output</h1>
<p>Print one integer: the number integers within the interval <span class="math inline">1,2,...,n</span> that are divisible by at least one of the prime numbers.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 10^{18}</span></li>
<li><span class="math inline">1 <= k <= 20</span></li>
<li><span class="math inline">2 <= a_i <= n</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>20 2
2 5
</pre>
<p>Output:</p>
<pre>12
</pre>
<p>Explanation: the <span class="math inline">12</span> numbers are <span class="math inline">2,4,5,6,8,10,12,14,15,16,18,20</span>.</p>
</div></div>

## CSES - Counting Coprime Pairs
<div class="md"><div class="md"><p>Given a list of <span class="math inline">n</span> positive integers, your task is to count the number of pairs of integers that are coprime (i.e., their greatest common divisor is one).</p>
<h1 id="input">Input</h1>
<p>The first input line has an integer <span class="math inline">n</span>: the number of elements.</p>
<p>The next line has <span class="math inline">n</span> integers <span class="math inline">x_1,x_2,\dots,x_n</span>: the contents of the list.</p>
<h1 id="output">Output</h1>
<p>Print one integer: the answer for the task.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 10^5</span></li>
<li><span class="math inline">1 <= x_i <= 10^6</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>8
5 4 20 1 16 17 5 15
</pre>
<p>Output:</p>
<pre>19
</pre></div></div>

## CSES - Binomial Coefficients
<div class="md"><div class="md"><p>Your task is to calculate <span class="math inline">n</span> binomial coefficients modulo <span class="math inline">10^9+7</span>.</p>
<p>A binomial coefficient <span class="math inline">{a \choose b}</span> can be calculated using the formula <span class="math inline">\frac{a!}{b!(a-b)!}</span>. We assume that <span class="math inline">a</span> and <span class="math inline">b</span> are integers and <span class="math inline">0 <= b <= a</span>.</p>
<h1 id="input">Input</h1>
<p>The first input line contains an integer <span class="math inline">n</span>: the number of calculations.</p>
<p>After this, there are <span class="math inline">n</span> lines, each of which contains two integers <span class="math inline">a</span> and <span class="math inline">b</span>.</p>
<h1 id="output">Output</h1>
<p>Print each binomial coefficient modulo <span class="math inline">10^9+7</span>.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 10^5</span></li>
<li><span class="math inline">0 <= b <= a <= 10^6</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>3
5 3
8 1
9 5
</pre>
<p>Output:</p>
<pre>10
8
126
</pre></div></div>

## CSES - Creating Strings II
<div class="md"><div class="md"><p>Given a string, your task is to calculate the number of different strings that can be created using its characters.</p>
<h1 id="input">Input</h1>
<p>The only input line has a string of length <span class="math inline">n</span>. Each character is between a–z.</p>
<h1 id="output">Output</h1>
<p>Print the number of different strings modulo <span class="math inline">10^9+7</span>.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 10^6</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>aabac
</pre>
<p>Output:</p>
<pre>20
</pre></div></div>

## CSES - Distributing Apples
<div class="md"><div class="md"><p>There are <span class="math inline">n</span> children and <span class="math inline">m</span> apples that will be distributed to them. Your task is to count the number of ways this can be done.</p>
<p>For example, if <span class="math inline">n=3</span> and <span class="math inline">m=2</span>, there are <span class="math inline">6</span> ways: <span class="math inline">[0,0,2]</span>, <span class="math inline">[0,1,1]</span>, <span class="math inline">[0,2,0]</span>, <span class="math inline">[1,0,1]</span>, <span class="math inline">[1,1,0]</span> and <span class="math inline">[2,0,0]</span>.</p>
<h1 id="input">Input</h1>
<p>The only input line has two integers <span class="math inline">n</span> and <span class="math inline">m</span>.</p>
<h1 id="output">Output</h1>
<p>Print the number of ways modulo <span class="math inline">10^9+7</span>.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n,m <= 10^6</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>3 2
</pre>
<p>Output:</p>
<pre>6
</pre></div></div>

## CSES - Christmas Party
<div class="md"><div class="md"><p>There are <span class="math inline">n</span> children at a Christmas party, and each of them has brought a gift. The idea is that everybody will get a gift brought by someone else.</p>
<p>In how many ways can the gifts be distributed?</p>
<h1 id="input">Input</h1>
<p>The only input line has an integer <span class="math inline">n</span>: the number of children.</p>
<h1 id="output">Output</h1>
<p>Print the number of ways modulo <span class="math inline">10^9+7</span>.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 10^6</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>4
</pre>
<p>Output:</p>
<pre>9
</pre></div></div>

## CSES - Bracket Sequences I
<div class="md"><div class="md"><p>Your task is to calculate the number of valid bracket sequences of length <span class="math inline">n</span>. For example, when <span class="math inline">n=6</span>, there are <span class="math inline">5</span> sequences:</p>
<ul>
<li><code>()()()</code></li>
<li><code>()(())</code></li>
<li><code>(())()</code></li>
<li><code>((()))</code></li>
<li><code>(()())</code></li>
</ul>
<h1 id="input">Input</h1>
<p>The only input line has an integer <span class="math inline">n</span>.</p>
<h1 id="output">Output</h1>
<p>Print the number of sequences modulo <span class="math inline">10^9+7</span>.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 10^6</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>6
</pre>
<p>Output:</p>
<pre>5
</pre></div></div>

## CSES - Bracket Sequences II
<div class="md"><div class="md"><p>Your task is to calculate the number of valid bracket sequences of length <span class="math inline">n</span> when a <em>prefix</em> of the sequence is given.</p>
<h1 id="input">Input</h1>
<p>The first input line has an integer <span class="math inline">n</span>.</p>
<p>The second line has a string of <span class="math inline">k</span> characters: the prefix of the sequence.</p>
<h1 id="output">Output</h1>
<p>Print the number of sequences modulo <span class="math inline">10^9+7</span>.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= k <= n <= 10^6</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>6
(()
</pre>
<p>Output:</p>
<pre>2
</pre>
<p>Explanation: There are two possible sequences: <code>(())()</code> and <code>(()())</code>.</p>
</div></div>

## CSES - Counting Necklaces
<div class="md"><div class="md"><p>Your task is to count the number of different necklaces that consist of <span class="math inline">n</span> pearls and each pearl has <span class="math inline">m</span> possible colors.</p>
<p>Two necklaces are considered to be different if it is not possible to rotate one of them so that they look the same.</p>
<h1 id="input">Input</h1>
<p>The only input line has two numbers <span class="math inline">n</span> and <span class="math inline">m</span>: the number of pearls and colors.</p>
<h1 id="output">Output</h1>
<p>Print one integer: the number of different necklaces modulo <span class="math inline">10^9+7</span>.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n,m <= 10^6</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>4 3
</pre>
<p>Output:</p>
<pre>24
</pre></div></div>

## CSES - Counting Grids
<div class="md"><div class="md"><p>Your task is to count the number of different <span class="math inline">n x n</span> grids whose each square is black or white.</p>
<p>Two grids are considered to be different if it is not possible to rotate one of them so that they look the same.</p>
<h1 id="input">Input</h1>
<p>The only input line has an integer <span class="math inline">n</span>: the size of the grid.</p>
<h1 id="output">Output</h1>
<p>Print one integer: the number of grids modulo <span class="math inline">10^9+7</span>.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 10^9</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>4
</pre>
<p>Output:</p>
<pre>16456
</pre></div></div>

## CSES - Fibonacci Numbers
<div class="md"><div class="md"><p>The Fibonacci numbers can be defined as follows:</p>
<ul>
<li><span class="math inline">F_0=0</span></li>
<li><span class="math inline">F_1=1</span></li>
<li><span class="math inline">F_n = F_{n-2}+F_{n-1}</span></li>
</ul>
<p>Your task is to calculate the value of <span class="math inline">F_n</span> for a given <span class="math inline">n</span>.</p>
<h1 id="input">Input</h1>
<p>The only input line has an integer <span class="math inline">n</span>.</p>
<h1 id="output">Output</h1>
<p>Print the value of <span class="math inline">F_n</span> modulo <span class="math inline">10^9+7</span>.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">0 <= n <= 10^{18}</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>10
</pre>
<p>Output:</p>
<pre>55
</pre></div></div>

## CSES - Throwing Dice
<div class="md"><div class="md"><p>Your task is to calculate the number of ways to get a sum <span class="math inline">n</span> by throwing dice. Each throw yields an integer between <span class="math inline">1 ... 6</span>.</p>
<p>For example, if <span class="math inline">n=10</span>, some possible ways are <span class="math inline">3+3+4</span>, <span class="math inline">1+4+1+4</span> and <span class="math inline">1+1+6+1+1</span>.</p>
<h1 id="input">Input</h1>
<p>The only input line contains an integer <span class="math inline">n</span>.</p>
<h1 id="output">Output</h1>
<p>Print the number of ways modulo <span class="math inline">10^9+7</span>.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 10^{18}</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>8
</pre>
<p>Output:</p>
<pre>125
</pre></div></div>

## CSES - Graph Paths I
<div class="md"><div class="md"><p>Consider a directed graph that has <span class="math inline">n</span> nodes and <span class="math inline">m</span> edges. Your task is to count the number of paths from node <span class="math inline">1</span> to node <span class="math inline">n</span> with exactly <span class="math inline">k</span> edges.</p>
<h1 id="input">Input</h1>
<p>The first input line contains three integers <span class="math inline">n</span>, <span class="math inline">m</span> and <span class="math inline">k</span>: the number of nodes and edges, and the length of the path. The nodes are numbered <span class="math inline">1,2,\dots,n</span>.</p>
<p>Then, there are <span class="math inline">m</span> lines describing the edges. Each line contains two integers <span class="math inline">a</span> and <span class="math inline">b</span>: there is an edge from node <span class="math inline">a</span> to node <span class="math inline">b</span>.</p>
<h1 id="output">Output</h1>
<p>Print the number of paths modulo <span class="math inline">10^9+7</span>.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 100</span></li>
<li><span class="math inline">1 <= m <= n(n-1)</span></li>
<li><span class="math inline">1 <= k <= 10^9</span></li>
<li><span class="math inline">1 <= a,b <= n</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>3 4 8
1 2
2 3
3 1
3 2
</pre>
<p>Output:</p>
<pre>2
</pre>
<p>Explanation: The paths are <span class="math inline">1 -> 2 -> 3 -> 1 -> 2 -> 3 -> 1 -> 2 -> 3</span> and <span class="math inline">1 -> 2 -> 3 -> 2 -> 3 -> 2 -> 3 -> 2 -> 3</span>.</p>
</div></div>

## CSES - Graph Paths II
<div class="md"><div class="md"><p>Consider a directed weighted graph having <span class="math inline">n</span> nodes and <span class="math inline">m</span> edges. Your task is to calculate the minimum path length from node <span class="math inline">1</span> to node <span class="math inline">n</span> with exactly <span class="math inline">k</span> edges.</p>
<h1 id="input">Input</h1>
<p>The first input line contains three integers <span class="math inline">n</span>, <span class="math inline">m</span> and <span class="math inline">k</span>: the number of nodes and edges, and the length of the path. The nodes are numbered <span class="math inline">1,2,\dots,n</span>.</p>
<p>Then, there are m lines describing the edges. Each line contains three integers <span class="math inline">a</span>, <span class="math inline">b</span> and <span class="math inline">c</span>: there is an edge from node <span class="math inline">a</span> to node <span class="math inline">b</span> with weight <span class="math inline">c</span>.</p>
<h1 id="output">Output</h1>
<p>Print the minimum path length. If there are no such paths, print <span class="math inline">-1</span>.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 100</span></li>
<li><span class="math inline">1 <= m <= n(n-1)</span></li>
<li><span class="math inline">1 <= k <= 10^9</span></li>
<li><span class="math inline">1 <= a,b <= n</span></li>
<li><span class="math inline">1 <= c <= 10^9</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>3 4 8
1 2 5
2 3 4
3 1 1
3 2 2
</pre>
<p>Output:</p>
<pre>27
</pre></div></div>

## CSES - Dice Probability
<div class="md"><div class="md"><p>You throw a dice <span class="math inline">n</span> times, and every throw produces an outcome between <span class="math inline">1</span> and <span class="math inline">6</span>. What is the probability that the sum of outcomes is between <span class="math inline">a</span> and <span class="math inline">b</span>?</p>
<h1 id="input">Input</h1>
<p>The only input line contains three integers <span class="math inline">n</span>, <span class="math inline">a</span> and <span class="math inline">b</span>.</p>
<h1 id="output">Output</h1>
<p>Print the probability rounded to six decimal places (rounding half to even).</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 100</span></li>
<li><span class="math inline">1 <= a <= b <= 6n</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>2 9 10
</pre>
<p>Output:</p>
<pre>0.194444
</pre></div></div>

## CSES - Moving Robots
<div class="md"><div class="md"><p>Each square of an <span class="math inline">8 x 8</span> chessboard has a robot. Each robot independently moves <span class="math inline">k</span> steps, and there can be many robots on the same square.</p>
<p>On each turn, a robot moves one step left, right, up or down, but not outside the board. It randomly chooses a direction among those where it can move.</p>
<p>Your task is to calculate the expected number of <em>empty</em> squares after <span class="math inline">k</span> turns.</p>
<h1 id="input">Input</h1>
<p>The only input line has an integer <span class="math inline">k</span>.</p>
<h1 id="output">Output</h1>
<p>Print the expected number of empty squares rounded to six decimal places (rounding half to even).</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= k <= 100</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>10
</pre>
<p>Output:</p>
<pre>23.120740
</pre></div></div>

## CSES - Candy Lottery
<div class="md"><div class="md"><p>There are <span class="math inline">n</span> children, and each of them independently gets a random integer number of candies between <span class="math inline">1</span> and <span class="math inline">k</span>.</p>
<p>What is the expected maximum number of candies a child gets?</p>
<h1 id="input">Input</h1>
<p>The only input line contains two integers <span class="math inline">n</span> and <span class="math inline">k</span>.</p>
<h1 id="output">Output</h1>
<p>Print the expected number rounded to six decimal places (rounding half to even).</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 100</span></li>
<li><span class="math inline">1 <= k <= 100</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>2 3
</pre>
<p>Output:</p>
<pre>2.444444
</pre></div></div>

## CSES - Inversion Probability
<div class="md"><div class="md"><p>An array has <span class="math inline">n</span> integers <span class="math inline">x_1,x_2,\dots,x_n</span>, and each of them has been randomly chosen between <span class="math inline">1</span> and <span class="math inline">r_i</span>. An inversion is a pair <span class="math inline">(a,b)</span> where <span class="math inline">a&lt;b</span> and <span class="math inline">x_a&gt;x_b</span>.</p>
<p>What is the expected number of inversions in the array?</p>
<h1 id="input">Input</h1>
<p>The first input line contains an integer <span class="math inline">n</span>: the size of the array.</p>
<p>The second line contains <span class="math inline">n</span> integers <span class="math inline">r_1,r_2,\dots,r_n</span>: the range of possible values for each array position.</p>
<h1 id="output">Output</h1>
<p>Print the expected number of inversions rounded to six decimal places (rounding half to even).</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 100</span></li>
<li><span class="math inline">1 <= r_i <= 100</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>3
5 2 7
</pre>
<p>Output:</p>
<pre>1.057143
</pre></div></div>

## CSES - Stick Game
<div class="md"><div class="md"><p>Consider a game where two players remove sticks from a heap. The players move alternately, and the player who removes the last stick wins the game.</p>
<p>A set <span class="math inline">P=\{p_1,p_2,...,p_k\}</span> determines the allowed moves. For example, if <span class="math inline">P=\{1,3,4\}</span>, a player may remove <span class="math inline">1</span>, <span class="math inline">3</span> or <span class="math inline">4</span> sticks.</p>
<p>Your task is find out for each number of sticks <span class="math inline">1,2,\dots,n</span> if the first player has a winning or losing position.</p>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">n</span> and <span class="math inline">k</span>: the number of sticks and moves.</p>
<p>The next line has <span class="math inline">k</span> integers <span class="math inline">p_1,p_2,\dots,p_k</span> that describe the allowed moves. All integers are distinct, and one of them is <span class="math inline">1</span>.</p>
<h1 id="output">Output</h1>
<p>Print a string containing <span class="math inline">n</span> characters: <code>W</code> means a winning position, and <code>L</code> means a losing position.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 10^6</span></li>
<li><span class="math inline">1 <= k <= 100</span></li>
<li><span class="math inline">1 <= p_i <= n</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>10 3
1 3 4
</pre>
<p>Output:</p>
<pre>WLWWWWLWLW
</pre></div></div>

## CSES - Nim Game I
<div class="md"><div class="md"><p>There are <span class="math inline">n</span> heaps of sticks and two players who move alternately. On each move, a player chooses a non-empty heap and removes any number of sticks. The player who removes the last stick wins the game.</p>
<p>Your task is to find out who wins if both players play optimally.</p>
<h1 id="input">Input</h1>
<p>The first input line contains an integer <span class="math inline">t</span>: the number of tests. After this, <span class="math inline">t</span> test cases are described:</p>
<p>The first line contains an integer <span class="math inline">n</span>: the number of heaps.</p>
<p>The next line has <span class="math inline">n</span> integers <span class="math inline">x_1,x_2,...,x_n</span>: the number of sticks in each heap.</p>
<h1 id="output">Output</h1>
<p>For each test case, print "first" if the first player wins the game and "second" if the second player wins the game.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= t <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= n <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= x_i <= 10^9</span></li>
<li>the sum of all <span class="math inline">n</span> is at most <span class="math inline">2 . 10^5</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>3
4
5 7 2 5
2
4 1
3
3 5 6
</pre>
<p>Output:</p>
<pre>first
first
second
</pre></div></div>

## CSES - Nim Game II
<div class="md"><div class="md"><p>There are <span class="math inline">n</span> heaps of sticks and two players who move alternately. On each move, a player chooses a non-empty heap and removes <span class="math inline">1</span>, <span class="math inline">2</span>, or <span class="math inline">3</span> sticks. The player who removes the last stick wins the game.</p>
<p>Your task is to find out who wins if both players play optimally.</p>
<h1 id="input">Input</h1>
<p>The first input line contains an integer <span class="math inline">t</span>: the number of tests. After this, <span class="math inline">t</span> test cases are described:</p>
<p>The first line contains an integer <span class="math inline">n</span>: the number of heaps.</p>
<p>The next line has <span class="math inline">n</span> integers <span class="math inline">x_1,x_2,...,x_n</span>: the number of sticks in each heap.</p>
<h1 id="output">Output</h1>
<p>For each test case, print "first" if the first player wins the game and "second" if the second player wins the game.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= t <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= n <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= x_i <= 10^9</span></li>
<li>the sum of all <span class="math inline">n</span> is at most <span class="math inline">2 . 10^5</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>3
4
5 7 2 5
2
4 1
3
4 4 4
</pre>
<p>Output:</p>
<pre>first
first
second
</pre></div></div>

## CSES - Stair Game
<div class="md"><div class="md"><p>There is a staircase consisting of <span class="math inline">n</span> stairs, numbered <span class="math inline">1,2,...,n</span>. Initially, each stair has some number of balls.</p>
<p>There are two players who move alternately. On each move, a player chooses a stair <span class="math inline">k</span> where <span class="math inline">k \neq 1</span> and it has at least one ball. Then, the player moves any number of balls from stair <span class="math inline">k</span> to stair <span class="math inline">k-1</span>. The player who moves last wins the game.</p>
<p>Your task is to find out who wins the game when both players play optimally.</p>
<p>Note that if there are no possible moves at all, the second player wins.</p>
<h1 id="input">Input</h1>
<p>The first input line has an integer <span class="math inline">t</span>: the number of tests. After this, <span class="math inline">t</span> test cases are described:</p>
<p>The first line contains an integer <span class="math inline">n</span>: the number of stairs.</p>
<p>The next line has <span class="math inline">n</span> integers <span class="math inline">p_1,p_2,...,p_n</span>: the initial number of balls on each stair.</p>
<h1 id="output">Output</h1>
<p>For each test, print "first" if the first player wins the game and "second" if the second player wins the game.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= t <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= n <= 2 . 10^5</span></li>
<li><span class="math inline">0 <= p_i <= 10^9</span></li>
<li>the sum of all <span class="math inline">n</span> is at most <span class="math inline">2 . 10^5</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>3
3
0 2 1
4
1 1 1 1
2
5 3
</pre>
<p>Output:</p>
<pre>first
second
first
</pre></div></div>

## CSES - Grundy's Game
<div class="md"><div class="md"><p>There is a heap of <span class="math inline">n</span> coins and two players who move alternately. On each move, a player chooses a heap and divides into two nonempty heaps that have a different number of coins. The player who makes the last move wins the game.</p>
<p>Your task is to find out who wins if both players play optimally.</p>
<h1 id="input">Input</h1>
<p>The first input line contains an integer <span class="math inline">t</span>: the number of tests.</p>
<p>After this, there are <span class="math inline">t</span> lines that describe the tests. Each line has an integer <span class="math inline">n</span>: the number of coins in the initial heap.</p>
<h1 id="output">Output</h1>
<p>For each test case, print "first" if the first player wins the game and "second" if the second player wins the game.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= t <= 10^5</span></li>
<li><span class="math inline">1 <= n <= 10^6</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>3
6
7
8
</pre>
<p>Output:</p>
<pre>first
second
first
</pre></div></div>

## CSES - Another Game
<div class="md"><div class="md"><p>There are <span class="math inline">n</span> heaps of coins and two players who move alternately. On each move, a player selects some of the nonempty heaps and removes one coin from each heap. The player who removes the last coin wins the game.</p>
<p>Your task is to find out who wins if both players play optimally.</p>
<h1 id="input">Input</h1>
<p>The first input line contains an integer <span class="math inline">t</span>: the number of tests. After this, <span class="math inline">t</span> test cases are described:</p>
<p>The first line contains an integer <span class="math inline">n</span>: the number of heaps.</p>
<p>The next line has <span class="math inline">n</span> integers <span class="math inline">x_1,x_2,...,x_n</span>: the number of coins in each heap.</p>
<h1 id="output">Output</h1>
<p>For each test case, print "first" if the first player wins the game and "second" if the second player wins the game.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= t <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= n <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= x_i <= 10^9</span></li>
<li>the sum of all <span class="math inline">n</span> is at most <span class="math inline">2 . 10^5</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>3
3
1 2 3
2
2 2
4
5 5 4 5
</pre>
<p>Output:</p>
<pre>first
second
first
</pre></div></div>

## CSES - Word Combinations
<div class="md"><div class="md"><p>You are given a string of length <span class="math inline">n</span> and a dictionary containing <span class="math inline">k</span> words. In how many ways can you create the string using the words?</p>
<h1 id="input">Input</h1>
<p>The first input line has a string containing <span class="math inline">n</span> characters between a–z.</p>
<p>The second line has an integer <span class="math inline">k</span>: the number of words in the dictionary.</p>
<p>Finally there are <span class="math inline">k</span> lines describing the words. Each word is unique and consists of characters a–z.</p>
<h1 id="output">Output</h1>
<p>Print the number of ways modulo <span class="math inline">10^9+7</span>.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 5000</span></li>
<li><span class="math inline">1 <= k <= 10^5</span></li>
<li>the total length of the words is at most <span class="math inline">10^6</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>ababc
4
ab
abab
c
cb
</pre>
<p>Output:</p>
<pre>2
</pre>
<p>Explanation: The possible ways are <code>ab+ab+c</code> and <code>abab+c</code>.</p>
</div></div>

## CSES - String Matching
<div class="md"><div class="md"><p>Given a string and a pattern, your task is to count the number of positions where the pattern occurs in the string.</p>
<h1 id="input">Input</h1>
<p>The first input line has a string of length <span class="math inline">n</span>, and the second input line has a pattern of length <span class="math inline">m</span>. Both of them consist of characters a–z.</p>
<h1 id="output">Output</h1>
<p>Print one integer: the number of occurrences.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n,m <= 10^6</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>saippuakauppias
pp
</pre>
<p>Output:</p>
<pre>2
</pre></div></div>

## CSES - Finding Borders
<div class="md"><div class="md"><p>A <em>border</em> of a string is a prefix that is also a suffix of the string but not the whole string. For example, the borders of <code>abcababcab</code> are <code>ab</code> and <code>abcab</code>.</p>
<p>Your task is to find all border lengths of a given string.</p>
<h1 id="input">Input</h1>
<p>The only input line has a string of length <span class="math inline">n</span> consisting of characters a–z.</p>
<h1 id="output">Output</h1>
<p>Print all border lengths of the string in increasing order.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 10^6</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>abcababcab
</pre>
<p>Output:</p>
<pre>2 5
</pre></div></div>

## CSES - Finding Periods
<div class="md"><div class="md"><p>A <em>period</em> of a string is a prefix that can be used to generate the whole string by repeating the prefix. The last repetition may be partial. For example, the periods of <code>abcabca</code> are <code>abc</code>, <code>abcabc</code> and <code>abcabca</code>.</p>
<p>Your task is to find all period lengths of a string.</p>
<h1 id="input">Input</h1>
<p>The only input line has a string of length <span class="math inline">n</span> consisting of characters a–z.</p>
<h1 id="output">Output</h1>
<p>Print all period lengths in increasing order.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 10^6</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>abcabca
</pre>
<p>Output:</p>
<pre>3 6 7
</pre></div></div>

## CSES - Minimal Rotation
<div class="md"><div class="md"><p>A rotation of a string can be generated by moving characters one after another from beginning to end. For example, the rotations of <code>acab</code> are <code>acab</code>, <code>caba</code>, <code>abac</code>, and <code>baca</code>.</p>
<p>Your task is to determine the lexicographically minimal rotation of a string.</p>
<h1 id="input">Input</h1>
<p>The only input line contains a string of length <span class="math inline">n</span>. Each character is one of a–z.</p>
<h1 id="output">Output</h1>
<p>Print the lexicographically minimal rotation.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 10^6</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>acab
</pre>
<p>Output:</p>
<pre>abac
</pre></div></div>

## CSES - Longest Palindrome
<div class="md"><div class="md"><p>Given a string, your task is to determine the longest palindromic substring of the string. For example, the longest palindrome in <code>aybabtu</code> is <code>bab</code>.</p>
<h1 id="input">Input</h1>
<p>The only input line contains a string of length <span class="math inline">n</span>. Each character is one of a–z.</p>
<h1 id="output">Output</h1>
<p>Print the longest palindrome in the string. If there are several solutions, you may print any of them.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 10^6</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>aybabtu
</pre>
<p>Output:</p>
<pre>bab
</pre></div></div>

## CSES - Required Substring
<div class="md"><div class="md"><p>Your task is to calculate the number of strings of length <span class="math inline">n</span> having a given pattern of length <span class="math inline">m</span> as their substring. All strings consist of characters A–Z.</p>
<h1 id="input">Input</h1>
<p>The first input line has an integer <span class="math inline">n</span>: the length of the final string.</p>
<p>The second line has a pattern of length <span class="math inline">m</span>.</p>
<h1 id="output">Output</h1>
<p>Print the number of strings modulo <span class="math inline">10^9+7</span>.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 1000</span></li>
<li><span class="math inline">1 <= m <= 100</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>6
ABCDB
</pre>
<p>Output:</p>
<pre>52
</pre>
<p>Explanation: The final string will be of the form ABCDB<span class="math inline">x</span> or <span class="math inline">x</span>ABCDB where <span class="math inline">x</span> is any character between A–Z.</p>
</div></div>

## CSES - Palindrome Queries
<div class="md"><div class="md"><p>You are given a string that consists of <span class="math inline">n</span> characters between a–z. The positions of the string are indexed <span class="math inline">1,2,\dots,n</span>.</p>
<p>Your task is to process <span class="math inline">m</span> operations of the following types:</p>
<ol>
<li>Change the character at position <span class="math inline">k</span> to <span class="math inline">x</span></li>
<li>Check if the substring from position <span class="math inline">a</span> to position <span class="math inline">b</span> is a palindrome</li>
</ol>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">n</span> and <span class="math inline">m</span>: the length of the string and the number of operations.</p>
<p>The next line has a string that consists of <span class="math inline">n</span> characters.</p>
<p>Finally, there are <span class="math inline">m</span> lines that describe the operations. Each line is of the form "1 <span class="math inline">k</span> <span class="math inline">x</span>" or "2 <span class="math inline">a</span> <span class="math inline">b</span>".</p>
<h1 id="output">Output</h1>
<p>For each operation 2, print YES if the substring is a palindrome and NO otherwise.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n, m <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= k <= n</span></li>
<li><span class="math inline">1 <= a <= b <= n</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>7 5
aybabtu
2 3 5
1 3 x
2 3 5
1 5 x
2 3 5
</pre>
<p>Output:</p>
<pre>YES
NO
YES
</pre></div></div>

## CSES - Finding Patterns
<div class="md"><div class="md"><p>Given a string and patterns, check for each pattern if it appears in the string.</p>
<h1 id="input">Input</h1>
<p>The first input line has a string of length <span class="math inline">n</span>.</p>
<p>The next input line has an integer <span class="math inline">k</span>: the number of patterns. Finally, there are <span class="math inline">k</span> lines that describe the patterns.</p>
<p>The string and the patterns consist of characters a–z.</p>
<h1 id="output">Output</h1>
<p>For each pattern, print "YES" if it appears in the string and "NO" otherwise.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 10^5</span></li>
<li><span class="math inline">1 <= k <= 5 . 10^5</span></li>
<li>the total length of the patterns is at most <span class="math inline">5 . 10^5</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>aybabtu
3
bab
abc
ayba
</pre>
<p>Output:</p>
<pre>YES
NO
YES
</pre></div></div>

## CSES - Counting Patterns
<div class="md"><div class="md"><p>Given a string and patterns, count for each pattern the number of positions where it appears in the string.</p>
<h1 id="input">Input</h1>
<p>The first input line has a string of length <span class="math inline">n</span>.</p>
<p>The next input line has an integer <span class="math inline">k</span>: the number of patterns. Finally, there are <span class="math inline">k</span> lines that describe the patterns.</p>
<p>The string and the patterns consist of characters a–z.</p>
<h1 id="output">Output</h1>
<p>For each pattern, print the number of positions.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 10^5</span></li>
<li><span class="math inline">1 <= k <= 5 . 10^5</span></li>
<li>the total length of the patterns is at most <span class="math inline">5 . 10^5</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>aybabtu
3
bab
abc
a
</pre>
<p>Output:</p>
<pre>1
0
2
</pre></div></div>

## CSES - Pattern Positions
<div class="md"><div class="md"><p>Given a string and patterns, find for each pattern the first position (1-indexed) where it appears in the string.</p>
<h1 id="input">Input</h1>
<p>The first input line has a string of length <span class="math inline">n</span>.</p>
<p>The next input line has an integer <span class="math inline">k</span>: the number of patterns. Finally, there are <span class="math inline">k</span> lines that describe the patterns.</p>
<p>The string and the patterns consist of characters a–z.</p>
<h1 id="output">Output</h1>
<p>Print the first position for each pattern (or <span class="math inline">-1</span> if it does not appear at all).</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 10^5</span></li>
<li><span class="math inline">1 <= k <= 5 . 10^5</span></li>
<li>the total length of the patterns is at most <span class="math inline">5 . 10^5</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>aybabtu
3
bab
abc
a
</pre>
<p>Output:</p>
<pre>3
-1
1
</pre></div></div>

## CSES - Distinct Substrings
<div class="md"><div class="md"><p>Count the number of distinct substrings that appear in a string.</p>
<h1 id="input">Input</h1>
<p>The only input line has a string of length <span class="math inline">n</span> that consists of characters a–z.</p>
<h1 id="output">Output</h1>
<p>Print one integer: the number of substrings.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 10^5</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>abaa
</pre>
<p>Output:</p>
<pre>8
</pre>
<p>Explanation: the substrings are <code>a</code>, <code>b</code>, <code>aa</code>, <code>ab</code>, <code>ba</code>, <code>aba</code>, <code>baa</code> and <code>abaa</code>.</p>
</div></div>

## CSES - Repeating Substring
<div class="md"><div class="md"><p>A repeating substring is a substring that occurs in two (or more) locations in the string. Your task is to find the longest repeating substring in a given string.</p>
<h1 id="input">Input</h1>
<p>The only input line has a string of length <span class="math inline">n</span> that consists of characters a–z.</p>
<h1 id="output">Output</h1>
<p>Print the longest repeating substring. If there are several possibilities, you can print any of them. If there is no repeating substring, print <span class="math inline">-1</span>.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 10^5</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>cabababc
</pre>
<p>Output:</p>
<pre>abab
</pre></div></div>

## CSES - String Functions
<div class="md"><div class="md"><p>We consider a string of <span class="math inline">n</span> characters, indexed <span class="math inline">1,2,\dots,n</span>. Your task is to calculate all values of the following functions:</p>
<ul>
<li><span class="math inline">z(i)</span> denotes the maximum length of a substring that begins at position <span class="math inline">i</span> and is a prefix of the string. In addition, <span class="math inline">z(1)=0</span>.</li>
<li><span class="math inline">\pi(i)</span> denotes the maximum length of a substring that ends at position <span class="math inline">i</span>, is a prefix of the string, and whose length is at most <span class="math inline">i-1</span>.</li>
</ul>
<p>Note that the function <span class="math inline">z</span> is used in the Z-algorithm, and the function <span class="math inline">\pi</span> is used in the KMP algorithm.</p>
<h1 id="input">Input</h1>
<p>The only input line has a string of length <span class="math inline">n</span>. Each character is between a–z.</p>
<h1 id="output">Output</h1>
<p>Print two lines: first the values of the <span class="math inline">z</span> function, and then the values of the <span class="math inline">\pi</span> function.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 10^6</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>abaabca
</pre>
<p>Output:</p>
<pre>0 0 1 2 0 0 1
0 0 1 1 2 0 1
</pre></div></div>

## CSES - Substring Order I
<div class="md"><div class="md"><p>You are given a string of length <span class="math inline">n</span>. If all of its distinct substrings are ordered lexicographically, what is the <span class="math inline">k</span>th smallest of them?</p>
<h1 id="input">Input</h1>
<p>The first input line has a string of length <span class="math inline">n</span> that consists of characters a–z.</p>
<p>The second input line has an integer <span class="math inline">k</span>.</p>
<h1 id="output">Output</h1>
<p>Print the <span class="math inline">k</span>th smallest distinct substring in lexicographical order.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 10^5</span></li>
<li><span class="math inline">1 <= k <= \frac{n(n+1)}{2}</span></li>
<li>It is guaranteed that <span class="math inline">k</span> does not exceed the number of distinct substrings.</li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>babaacbaab
10
</pre>
<p>Output:</p>
<pre>aba
</pre>
<p>Explanation: The 10 smallest distinct substrings in order are a, aa, aab, aac, aacb, aacba, aacbaa, aacbaab, ab, and aba.</p>
</div></div>

## CSES - Substring Order II
<div class="md"><div class="md"><p>You are given a string of length <span class="math inline">n</span>. If all of its substrings (not necessarily distinct) are ordered lexicographically, what is the <span class="math inline">k</span>th smallest of them?</p>
<h1 id="input">Input</h1>
<p>The first input line has a string of length <span class="math inline">n</span> that consists of characters a–z.</p>
<p>The second input line has an integer <span class="math inline">k</span>.</p>
<h1 id="output">Output</h1>
<p>Print the <span class="math inline">k</span>th smallest substring in lexicographical order.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 10^5</span></li>
<li><span class="math inline">1 <= k <= \frac{n(n+1)}{2}</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>baabaa
10
</pre>
<p>Output:</p>
<pre>ab
</pre>
<p>Explanation: The 10 smallest substrings in order are a, a, a, a, aa, aa, aab, aaba, aabaa, and ab.</p>
</div></div>

## CSES - Substring Distribution
<div class="md"><div class="md"><p>You are given a string of length <span class="math inline">n</span>. For every integer between <span class="math inline">1 ... n</span> you need to print the number of distinct substrings of that length.</p>
<h1 id="input">Input</h1>
<p>The only input line has a string of length <span class="math inline">n</span> that consists of characters a–z.</p>
<h1 id="output">Output</h1>
<p>For each integer between <span class="math inline">1 ... n</span> print the number of distinct substrings of that length.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 10^5</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>abab
</pre>
<p>Output:</p>
<pre>2 2 2 1
</pre></div></div>

## CSES - Point Location Test
<div class="md"><div class="md"><p>There is a line that goes through the points <span class="math inline">p_1=(x_1,y_1)</span> and <span class="math inline">p_2=(x_2,y_2)</span>. There is also a point <span class="math inline">p_3=(x_3,y_3)</span>.</p>
<p>Your task is to determine whether <span class="math inline">p_3</span> is located on the left or right side of the line or if it touches the line when we are looking from <span class="math inline">p_1</span> to <span class="math inline">p_2</span>.</p>
<h1 id="input">Input</h1>
<p>The first input line has an integer <span class="math inline">t</span>: the number of tests.</p>
<p>After this, there are <span class="math inline">t</span> lines that describe the tests. Each line has six integers: <span class="math inline">x_1</span>, <span class="math inline">y_1</span>, <span class="math inline">x_2</span>, <span class="math inline">y_2</span>, <span class="math inline">x_3</span> and <span class="math inline">y_3</span>.</p>
<h1 id="output">Output</h1>
<p>For each test, print "LEFT", "RIGHT" or "TOUCH".</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= t <= 10^5</span></li>
<li><span class="math inline">-10^9 <= x_1, y_1, x_2, y_2, x_3, y_3 <= 10^9</span></li>
<li><span class="math inline">x_1 \neq x_2</span> or <span class="math inline">y_1 \neq y_2</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>3
1 1 5 3 2 3
1 1 5 3 4 1
1 1 5 3 3 2
</pre>
<p>Output:</p>
<pre>LEFT
RIGHT
TOUCH
</pre></div></div>

## CSES - Line Segment Intersection
<div class="md"><div class="md"><p>There are two line segments: the first goes through the points <span class="math inline">(x_1,y_1)</span> and <span class="math inline">(x_2,y_2)</span>, and the second goes through the points <span class="math inline">(x_3,y_3)</span> and <span class="math inline">(x_4,y_4)</span>.</p>
<p>Your task is to determine if the line segments intersect, i.e., they have at least one common point.</p>
<h1 id="input">Input</h1>
<p>The first input line has an integer <span class="math inline">t</span>: the number of tests.</p>
<p>After this, there are <span class="math inline">t</span> lines that describe the tests. Each line has eight integers <span class="math inline">x_1</span>, <span class="math inline">y_1</span>, <span class="math inline">x_2</span>, <span class="math inline">y_2</span>, <span class="math inline">x_3</span>, <span class="math inline">y_3</span>, <span class="math inline">x_4</span> and <span class="math inline">y_4</span>.</p>
<h1 id="output">Output</h1>
<p>For each test, print "YES" if the line segments intersect and "NO" otherwise.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= t <= 10^5</span></li>
<li><span class="math inline">-10^9 <= x_1, y_1, x_2, y_2, x_3, y_3, x_4, y_4 <= 10^9</span></li>
<li><span class="math inline">(x_1,y_1) \neq (x_2,y_2)</span></li>
<li><span class="math inline">(x_3,y_3) \neq (x_4,y_4)</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5
1 1 5 3 1 2 4 3
1 1 5 3 1 1 4 3
1 1 5 3 2 3 4 1
1 1 5 3 2 4 4 1
1 1 5 3 3 2 7 4
</pre>
<p>Output:</p>
<pre>NO
YES
YES
YES
YES
</pre></div></div>

## CSES - Polygon Area
<div class="md"><div class="md"><p>Your task is to calculate the area of a given polygon.</p>
<p>The polygon consists of <span class="math inline">n</span> vertices <span class="math inline">(x_1,y_1),(x_2,y_2),\dots,(x_n,y_n)</span>. The vertices <span class="math inline">(x_i,y_i)</span> and <span class="math inline">(x_{i+1},y_{i+1})</span> are adjacent for <span class="math inline">i=1,2,\dots,n-1</span>, and the vertices <span class="math inline">(x_1,y_1)</span> and <span class="math inline">(x_n,y_n)</span> are also adjacent.</p>
<h1 id="input">Input</h1>
<p>The first input line has an integer <span class="math inline">n</span>: the number of vertices.</p>
<p>After this, there are <span class="math inline">n</span> lines that describe the vertices. The <span class="math inline">i</span>th such line has two integers <span class="math inline">x_i</span> and <span class="math inline">y_i</span>.</p>
<p>You may assume that the polygon is simple, i.e., it does not intersect itself.</p>
<h1 id="output">Output</h1>
<p>Print one integer: <span class="math inline">2a</span> where the area of the polygon is <span class="math inline">a</span> (this ensures that the result is an integer).</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">3 <= n <= 1000</span></li>
<li><span class="math inline">-10^9 <= x_i, y_i <= 10^9</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>4
1 1
4 2
3 5
1 4
</pre>
<p>Output:</p>
<pre>16
</pre></div></div>

## CSES - Point in Polygon
<div class="md"><div class="md"><p>You are given a polygon of <span class="math inline">n</span> vertices and a list of <span class="math inline">m</span> points. Your task is to determine for each point if it is inside, outside or on the boundary of the polygon.</p>
<p>The polygon consists of <span class="math inline">n</span> vertices <span class="math inline">(x_1,y_1),(x_2,y_2),\dots,(x_n,y_n)</span>. The vertices <span class="math inline">(x_i,y_i)</span> and <span class="math inline">(x_{i+1},y_{i+1})</span> are adjacent for <span class="math inline">i=1,2,\dots,n-1</span>, and the vertices <span class="math inline">(x_1,y_1)</span> and <span class="math inline">(x_n,y_n)</span> are also adjacent.</p>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">n</span> and <span class="math inline">m</span>: the number of vertices in the polygon and the number of points.</p>
<p>After this, there are <span class="math inline">n</span> lines that describe the polygon. The <span class="math inline">i</span>th such line has two integers <span class="math inline">x_i</span> and <span class="math inline">y_i</span>.</p>
<p>You may assume that the polygon is simple, i.e., it does not intersect itself.</p>
<p>Finally, there are <span class="math inline">m</span> lines that describe the points. Each line has two integers <span class="math inline">x</span> and <span class="math inline">y</span>.</p>
<h1 id="output">Output</h1>
<p>For each point, print "INSIDE", "OUTSIDE" or "BOUNDARY".</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">3 <= n,m <= 1000</span></li>
<li><span class="math inline">1 <= m <= 1000</span></li>
<li><span class="math inline">-10^9 <= x_i, y_i <= 10^9</span></li>
<li><span class="math inline">-10^9 <= x, y <= 10^9</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>4 3
1 1
4 2
3 5
1 4
2 3
3 1
1 3
</pre>
<p>Output:</p>
<pre>INSIDE
OUTSIDE
BOUNDARY
</pre></div></div>

## CSES - Polygon Lattice Points
<div class="md"><div class="md"><p>Given a polygon, your task is to calculate the number of lattice points inside the polygon and on its boundary. A lattice point is a point whose coordinates are integers.</p>
<p>The polygon consists of <span class="math inline">n</span> vertices <span class="math inline">(x_1,y_1),(x_2,y_2),\dots,(x_n,y_n)</span>. The vertices <span class="math inline">(x_i,y_i)</span> and <span class="math inline">(x_{i+1},y_{i+1})</span> are adjacent for <span class="math inline">i=1,2,\dots,n-1</span>, and the vertices <span class="math inline">(x_1,y_1)</span> and <span class="math inline">(x_n,y_n)</span> are also adjacent.</p>
<h1 id="input">Input</h1>
<p>The first input line has an integer <span class="math inline">n</span>: the number of vertices.</p>
<p>After this, there are <span class="math inline">n</span> lines that describe the vertices. The <span class="math inline">i</span>th such line has two integers <span class="math inline">x_i</span> and <span class="math inline">y_i</span>.</p>
<p>You may assume that the polygon is simple, i.e., it does not intersect itself.</p>
<h1 id="output">Output</h1>
<p>Print two integers: the number of lattice points inside the polygon and on its boundary.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">3 <= n <= 10^5</span></li>
<li><span class="math inline">-10^9 <= x_i, y_i <= 10^9</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>4
1 1
5 3
3 5
1 4
</pre>
<p>Output:</p>
<pre>6 8
</pre></div></div>

## CSES - Minimum Euclidean Distance
<div class="md"><div class="md"><p>Given a set of points in the two-dimensional plane, your task is to find the minimum Euclidean distance between two distinct points.</p>
<p>The Euclidean distance of points <span class="math inline">(x_1,y_1)</span> and <span class="math inline">(x_2,y_2)</span> is <span class="math inline">\sqrt{(x_1-x_2)^2+(y_1-y_2)^2}</span>.</p>
<h1 id="input">Input</h1>
<p>The first input line has an integer <span class="math inline">n</span>: the number of points.</p>
<p>After this, there are <span class="math inline">n</span> lines that describe the points. Each line has two integers <span class="math inline">x</span> and <span class="math inline">y</span>. You may assume that each point is distinct.</p>
<h1 id="output">Output</h1>
<p>Print one integer: <span class="math inline">d^2</span> where <span class="math inline">d</span> is the minimum Euclidean distance (this ensures that the result is an integer).</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">2 <= n <= 2 . 10^5</span></li>
<li><span class="math inline">-10^9 <= x,y <= 10^9</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>4
2 1
4 4
1 2
6 3
</pre>
<p>Output:</p>
<pre>2
</pre></div></div>

## CSES - Convex Hull
<div class="md"><div class="md"><p>Given a set of <span class="math inline">n</span> points in the two-dimensional plane, your task is to determine the convex hull of the points.</p>
<h1 id="input">Input</h1>
<p>The first input line has an integer <span class="math inline">n</span>: the number of points.</p>
<p>After this, there are <span class="math inline">n</span> lines that describe the points. Each line has two integers <span class="math inline">x</span> and <span class="math inline">y</span>: the coordinates of a point.</p>
<p>You may assume that each point is distinct, and the area of the hull is positive.</p>
<h1 id="output">Output</h1>
<p>First print an integer <span class="math inline">k</span>: the number of points in the convex hull.</p>
<p>After this, print <span class="math inline">k</span> lines that describe the points. You can print the points in any order. Print all points that lie on the convex hull.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">3 <= n <= 2 . 10^5</span></li>
<li><span class="math inline">-10^9 <= x, y <= 10^9</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>6
2 1
2 5
3 3
4 3
4 4
6 3
</pre>
<p>Output:</p>
<pre>4
2 1
2 5
4 4
6 3
</pre></div></div>

## CSES - Meet in the Middle
<div class="md"><div class="md"><p>You are given an array of <span class="math inline">n</span> numbers. In how many ways can you choose a subset of the numbers with sum <span class="math inline">x</span>?</p>
<h1 id="input">Input</h1>
<p>The first input line has two numbers <span class="math inline">n</span> and <span class="math inline">x</span>: the array size and the required sum.</p>
<p>The second line has <span class="math inline">n</span> integers <span class="math inline">t_1,t_2,\dots,t_n</span>: the numbers in the array.</p>
<h1 id="output">Output</h1>
<p>Print the number of ways you can create the sum <span class="math inline">x</span>.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 40</span></li>
<li><span class="math inline">1 <= x <= 10^9</span></li>
<li><span class="math inline">1 <= t_i <= 10^9</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>4 5
1 2 3 2
</pre>
<p>Output:</p>
<pre>3
</pre></div></div>

## CSES - Hamming Distance
<div class="md"><div class="md"><p>The Hamming distance between two strings <span class="math inline">a</span> and <span class="math inline">b</span> of equal length is the number of positions where the strings differ.</p>
<p>You are given <span class="math inline">n</span> bit strings, each of length <span class="math inline">k</span> and your task is to calculate the minimum Hamming distance between two strings. </p>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">n</span> and <span class="math inline">k</span>: the number of bit strings and their length. </p>
<p>Then there are <span class="math inline">n</span> lines each consisting of one bit string of length <span class="math inline">k</span>.</p>
<h1 id="output">Output</h1>
<p>Print the minimum Hamming distance between two strings.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">2 <= n <= 2 . 10^4</span></li>
<li><span class="math inline">1 <= k <= 30</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5 6
110111
001000
100001
101000
101110
</pre>
<p>Output:</p>
<pre>1
</pre>
<p>Explanation: The strings <code>101000</code> and <code>001000</code> differ only at the first position.</p>
</div></div>

## CSES - Beautiful Subgrids
<div class="md"><div class="md"><p>You are given an <span class="math inline">n x n</span> grid whose each square is either black or white. A subgrid is called <em>beautiful</em> if its height and width is at least two and all of its corners are black. How many beautiful subgrids are there within the given grid?</p>
<h1 id="input">Input</h1>
<p>The first input line has an integer <span class="math inline">n</span>: the size of the grid.</p>
<p>Then there are <span class="math inline">n</span> lines describing the grid: <code>1</code> means that a square is black and <code>0</code> means it is white.</p>
<h1 id="output">Output</h1>
<p>Print the number of beautiful subgrids.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 3000</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5
00010
11111
00110
11001
00010
</pre>
<p>Output:</p>
<pre>4
</pre></div></div>

## CSES - Reachable Nodes
<div class="md"><div class="md"><p>A directed acyclic graph consists of <span class="math inline">n</span> nodes and <span class="math inline">m</span> edges. The nodes are numbered <span class="math inline">1,2,\dots,n</span>.</p>
<p>Calculate for each node the number of nodes you can reach from that node (including the node itself).</p>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">n</span> and <span class="math inline">m</span>: the number of nodes and edges.</p>
<p>Then there are <span class="math inline">m</span> lines describing the edges. Each line has two distinct integers <span class="math inline">a</span> and <span class="math inline">b</span>: there is an edge from node <span class="math inline">a</span> to node <span class="math inline">b</span>.</p>
<h1 id="output">Output</h1>
<p>Print <span class="math inline">n</span> integers: for each node the number of reachable nodes.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 5 . 10^4</span></li>
<li><span class="math inline">1 <= m <= 10^5</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5 6
1 2
1 3
1 4
2 3
3 5
4 5
</pre>
<p>Output:</p>
<pre>5 3 2 2 1
</pre></div></div>

## CSES - Reachability Queries
<div class="md"><div class="md"><p>A directed graph consists of <span class="math inline">n</span> nodes and <span class="math inline">m</span> edges. The edges are numbered <span class="math inline">1,2,\dots,n</span>.</p>
<p>Your task is to answer <span class="math inline">q</span> queries of the form "can you reach node <span class="math inline">b</span> from node <span class="math inline">a</span>?"</p>
<h1 id="input">Input</h1>
<p>The first input line has three integers <span class="math inline">n</span>, <span class="math inline">m</span> and <span class="math inline">q</span>: the number of nodes, edges and queries.</p>
<p>Then there are <span class="math inline">m</span> lines describing the edges. Each line has two distinct integers <span class="math inline">a</span> and <span class="math inline">b</span>: there is an edge from node <span class="math inline">a</span> to node <span class="math inline">b</span>.</p>
<p>Finally there are <span class="math inline">q</span> lines describing the queries. Each line consists of two integers <span class="math inline">a</span> and <span class="math inline">b</span>: "can you reach node <span class="math inline">b</span> from node <span class="math inline">a</span>?"</p>
<h1 id="output">Output</h1>
<p>Print the answer for each query: either "YES" or "NO".</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 5 . 10^4</span></li>
<li><span class="math inline">1 <= m,q <= 10^5</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>4 4 3
1 2
2 3
3 1
4 3
1 3
1 4
4 1
</pre>
<p>Output:</p>
<pre>YES
NO
YES
</pre></div></div>

## CSES - Cut and Paste
<div class="md"><div class="md"><p>Given a string, your task is to process operations where you cut a substring and paste it to the end of the string. What is the final string after all the operations?</p>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">n</span> and <span class="math inline">m</span>: the length of the string and the number of operations. The characters of the string are numbered <span class="math inline">1,2,\dots,n</span>.</p>
<p>The next line has a string of length <span class="math inline">n</span> that consists of characters A–Z.</p>
<p>Finally, there are <span class="math inline">m</span> lines that describe the operations. Each line has two integers <span class="math inline">a</span> and <span class="math inline">b</span>: you cut a substring from position <span class="math inline">a</span> to position <span class="math inline">b</span>.</p>
<h1 id="output">Output</h1>
<p>Print the final string after all the operations.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n, m <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= a <= b <= n</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>7 2
AYBABTU
3 5
3 5
</pre>
<p>Output:</p>
<pre>AYABTUB
</pre></div></div>

## CSES - Substring Reversals
<div class="md"><div class="md"><p>Given a string, your task is to process operations where you reverse a substring of the string. What is the final string after all the operations?</p>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">n</span> and <span class="math inline">m</span>: the length of the string and the number of operations. The characters of the string are numbered <span class="math inline">1,2,\dots,n</span>.</p>
<p>The next line has a string of length <span class="math inline">n</span> that consists of characters A–Z.</p>
<p>Finally, there are <span class="math inline">m</span> lines that describe the operations. Each line has two integers <span class="math inline">a</span> and <span class="math inline">b</span>: you reverse a substring from position <span class="math inline">a</span> to position <span class="math inline">b</span>.</p>
<h1 id="output">Output</h1>
<p>Print the final string after all the operations.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n, m <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= a <= b <= n</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>7 2
AYBABTU
3 4
4 7
</pre>
<p>Output:</p>
<pre>AYAUTBB
</pre></div></div>

## CSES - Reversals and Sums
<div class="md"><div class="md"><p>Given an array of <span class="math inline">n</span> integers, you have to process following operations:</p>
<ol>
<li>reverse a subarray</li>
<li>calculate the sum of values in a subarray</li>
</ol>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">n</span> and <span class="math inline">m</span>: the size of the array and the number of operations. The array elements are numbered <span class="math inline">1,2,\dots,n</span>.</p>
<p>The next line as <span class="math inline">n</span> integers <span class="math inline">x_1,x_2,\dots,x_n</span>: the contents of the array.</p>
<p>Finally, there are <span class="math inline">m</span> lines that describe the operations. Each line has three integers <span class="math inline">t</span>, <span class="math inline">a</span> and <span class="math inline">b</span>. If <span class="math inline">t=1</span>, you should reverse a subarray from <span class="math inline">a</span> to <span class="math inline">b</span>. If <span class="math inline">t=2</span>, you should calculate the sum of values from <span class="math inline">a</span> to <span class="math inline">b</span>.</p>
<h1 id="output">Output</h1>
<p>Print the answer to each operation where <span class="math inline">t=2</span>.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= m <= 10^5</span></li>
<li><span class="math inline">0 <= x_i <= 10^9</span></li>
<li><span class="math inline">1 <= a <= b <= n</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>8 3
2 1 3 4 5 3 4 4
2 2 4
1 3 6
2 2 4
</pre>
<p>Output:</p>
<pre>8
9
</pre></div></div>

## CSES - Necessary Roads
<div class="md"><div class="md"><p>There are <span class="math inline">n</span> cities and <span class="math inline">m</span> roads between them. There is a route between any two cities.</p>
<p>A road is called <em>necessary</em> if there is no route between some two cities after removing that road. Your task is to find all necessary roads.</p>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">n</span> and <span class="math inline">m</span>: the number of cities and roads. The cities are numbered <span class="math inline">1,2,\dots,n</span>.</p>
<p>After this, there are <span class="math inline">m</span> lines that describe the roads. Each line has two integers <span class="math inline">a</span> and <span class="math inline">b</span>: there is a road between cities <span class="math inline">a</span> and <span class="math inline">b</span>. There is at most one road between two cities, and every road connects two distinct cities.</p>
<h1 id="output">Output</h1>
<p>First print an integer <span class="math inline">k</span>: the number of necessary roads. After that, print <span class="math inline">k</span> lines that describe the roads. You may print the roads in any order.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">2 <= n <= 10^5</span></li>
<li><span class="math inline">1 <= m <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= a,b <= n</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5 5
1 2
1 4
2 4
3 5
4 5
</pre>
<p>Output:</p>
<pre>2
3 5
4 5
</pre></div></div>

## CSES - Necessary Cities
<div class="md"><div class="md"><p>There are <span class="math inline">n</span> cities and <span class="math inline">m</span> roads between them. There is a route between any two cities.</p>
<p>A city is called <em>necessary</em> if there is no route between some other two cities after removing that city (and adjacent roads). Your task is to find all necessary cities.</p>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">n</span> and <span class="math inline">m</span>: the number of cities and roads. The cities are numbered <span class="math inline">1,2,\dots,n</span>.</p>
<p>After this, there are <span class="math inline">m</span> lines that describe the roads. Each line has two integers <span class="math inline">a</span> and <span class="math inline">b</span>: there is a road between cities <span class="math inline">a</span> and <span class="math inline">b</span>. There is at most one road between two cities, and every road connects two distinct cities.</p>
<h1 id="output">Output</h1>
<p>First print an integer <span class="math inline">k</span>: the number of necessary cities. After that, print a list of <span class="math inline">k</span> cities. You may print the cities in any order.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">2 <= n <= 10^5</span></li>
<li><span class="math inline">1 <= m <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= a,b <= n</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5 5
1 2
1 4
2 4
3 5
4 5
</pre>
<p>Output:</p>
<pre>2
4 5
</pre></div></div>

## CSES - Eulerian Subgraphs
<div class="md"><div class="md"><p>You are given an undirected graph that has <span class="math inline">n</span> nodes and <span class="math inline">m</span> edges.</p>
<p>We consider subgraphs that have all nodes of the original graph and some of its edges. A subgraph is called <em>Eulerian</em> if each node has even degree.</p>
<p>Your task is to count the number of Eulerian subgraphs modulo <span class="math inline">10^9+7</span>.</p>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">n</span> and <span class="math inline">m</span>: the number of nodes and edges. The nodes are numbered <span class="math inline">1,2,\dots,n</span>.</p>
<p>After this, there are <span class="math inline">m</span> lines that describe the edges. Each line has two integers <span class="math inline">a</span> and <span class="math inline">b</span>: there is an edge between nodes <span class="math inline">a</span> and <span class="math inline">b</span>. There is at most one edge between two nodes, and each edge connects two distinct nodes.</p>
<h1 id="output">Output</h1>
<p>Print the number of Eulerian subgraphs modulo <span class="math inline">10^9+7</span>.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 10^5</span></li>
<li><span class="math inline">0 <= m <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= a,b <= n</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>4 3
1 2
1 3
2 3
</pre>
<p>Output:</p>
<pre>2
</pre>
<p>Explanation: You can either keep or remove all edges, so there are two possible Eulerian subgraphs.</p>
</div></div>

## CSES - Monster Game I
<div class="md"><div class="md"><p>You are playing a game that consists of <span class="math inline">n</span> levels. Each level has a monster. On levels <span class="math inline">1,2,\dots,n-1</span>, you can either kill or escape the monster. However, on level <span class="math inline">n</span> you must kill the final monster to win the game.</p>
<p>Killing a monster takes <span class="math inline">sf</span> time where <span class="math inline">s</span> is the monster's strength and <span class="math inline">f</span> is your skill factor (lower skill factor is better). After killing a monster, you get a new skill factor. What is the minimum total time in which you can win the game?</p>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">n</span> and <span class="math inline">x</span>: the number of levels and your initial skill factor.</p>
<p>The second line has <span class="math inline">n</span> integers <span class="math inline">s_1,s_2,\dots,s_n</span>: each monster's strength.</p>
<p>The third line has <span class="math inline">n</span> integers <span class="math inline">f_1,f_2,\dots,f_n</span>: your new skill factor after killing a monster.</p>
<h1 id="output">Output</h1>
<p>Print one integer: the minimum total time to win the game.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= x <= 10^6</span></li>
<li><span class="math inline">1 <= s_1 <= s_2 <= \dots <= s_n <= 10^6</span></li>
<li><span class="math inline">x \ge f_1 \ge f_2 \ge \dots \ge f_n \ge 1</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5 100
20 30 30 50 90
90 60 20 20 10
</pre>
<p>Output:</p>
<pre>4800
</pre>
<p>Explanation: The best way to play is to kill the third and fifth monster.</p>
</div></div>

## CSES - Monster Game II
<div class="md"><div class="md"><p>You are playing a game that consists of <span class="math inline">n</span> levels. Each level has a monster. On levels <span class="math inline">1,2,\dots,n-1</span>, you can either kill or escape the monster. However, on level <span class="math inline">n</span> you must kill the final monster to win the game.</p>
<p>Killing a monster takes <span class="math inline">sf</span> time where <span class="math inline">s</span> is the monster's strength and <span class="math inline">f</span> is your skill factor. After killing a monster, you get a new skill factor  (lower skill factor is better). What is the minimum total time in which you can win the game?</p>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">n</span> and <span class="math inline">x</span>: the number of levels and your initial skill factor.</p>
<p>The second line has <span class="math inline">n</span> integers <span class="math inline">s_1,s_2,\dots,s_n</span>: each monster's strength.</p>
<p>The third line has <span class="math inline">n</span> integers <span class="math inline">f_1,f_2,\dots,f_n</span>: your new skill factor after killing a monster.</p>
<h1 id="output">Output</h1>
<p>Print one integer: the minimum total time to win the game.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= x <= 10^6</span></li>
<li><span class="math inline">1 <= s_i, f_i <= 10^6</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5 100
50 20 30 90 30
60 20 20 10 90
</pre>
<p>Output:</p>
<pre>2600
</pre>
<p>Explanation: The best way to play is to kill the second and fifth monster.</p>
</div></div>

## CSES - Subarray Squares
<div class="md"><div class="md"><p>Given an array of <span class="math inline">n</span> elements, your task is to divide into <span class="math inline">k</span> subarrays. The cost of each subarray is the square of the sum of the values in the subarray. What is the minimum total cost if you act optimally?</p>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">n</span> and <span class="math inline">k</span>: the array elements and the number of subarrays. The array elements are numbered <span class="math inline">1,2,\dots,n</span>.</p>
<p>The second line has <span class="math inline">n</span> integers <span class="math inline">x_1,x_2,\dots,x_n</span>: the contents of the array.</p>
<h1 id="output">Output</h1>
<p>Print one integer: the minimum total cost.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= k <= n <= 3000</span></li>
<li><span class="math inline">1 <= x_i <= 10^5</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>8 3
2 3 1 2 2 3 4 1
</pre>
<p>Output:</p>
<pre>110
</pre>
<p>Explanation: An optimal solution is <span class="math inline">[2,3,1]</span>, <span class="math inline">[2,2,3]</span>, <span class="math inline">[4,1]</span>, whose cost is <span class="math inline">(2+3+1)^2+(2+2+3)^2+(4+1)^2=110</span>.</p>
</div></div>

## CSES - Houses and Schools
<div class="md"><div class="md"><p>There are <span class="math inline">n</span> houses on a street, numbered <span class="math inline">1,2,\dots,n</span>. The distance of houses <span class="math inline">a</span> and <span class="math inline">b</span> is <span class="math inline">|a-b|</span>. You know the number of children in each house.</p>
<p>Your task is to establish <span class="math inline">k</span> schools in such a way that each school is in some house. Then, each child goes to the nearest school. What is the minimum total walking distance of the children if you act optimally?</p>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">n</span> and <span class="math inline">k</span>: the number of houses and the number of schools. The houses are numbered <span class="math inline">1,2\dots,n</span>.</p>
<p>After this, there are <span class="math inline">n</span> integers <span class="math inline">c_1,c_2,\dots,c_n</span>: the number of children in each house.</p>
<h1 id="output">Output</h1>
<p>Print the minimum total distance.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= k <= n <= 3000</span></li>
<li><span class="math inline">1 <= c_i <= 10^9</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>6 2
2 7 1 4 6 4
</pre>
<p>Output:</p>
<pre>11
</pre>
<p>Explanation: Houses 2 and 5 will have schools.</p>
</div></div>

## CSES - Knuth Division
<div class="md"><div class="md"><p>Given an array of <span class="math inline">n</span> numbers, your task is to divide it into <span class="math inline">n</span> subarrays, each of which has a single element.</p>
<p>On each move, you may choose any subarray and split it into two subarrays. The cost of such a move is the sum of values in the chosen subarray.</p>
<p>What is the minimum total cost if you act optimally?</p>
<h1 id="input">Input</h1>
<p>The first input line has an integer <span class="math inline">n</span>: the array size. The array elements are numbered <span class="math inline">1,2,\dots,n</span>.</p>
<p>The second line has <span class="math inline">n</span> integers <span class="math inline">x_1,x_2,\dots,x_n</span>: the contents of the array.</p>
<h1 id="output">Output</h1>
<p>Print one integer: the minimum total cost.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 5000</span></li>
<li><span class="math inline">1 <= x_i <= 10^9</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5
2 7 3 2 5
</pre>
<p>Output:</p>
<pre>43
</pre></div></div>

## CSES - Apples and Bananas
<div class="md"><div class="md"><p>There are <span class="math inline">n</span> apples and <span class="math inline">m</span> bananas, and each of them has an integer weight between <span class="math inline">1 ... k</span>. Your task is to calculate, for each weight <span class="math inline">w</span> between <span class="math inline">2 \dots 2k</span>, the number of ways we can choose an apple and a banana whose combined weight is <span class="math inline">w</span>.</p>
<h1 id="input">Input</h1>
<p>The first input line contains three integers <span class="math inline">k</span>, <span class="math inline">n</span> and <span class="math inline">m</span>: the number <span class="math inline">k</span>, the number of apples and the number of bananas.</p>
<p>The next line contains <span class="math inline">n</span> integers <span class="math inline">a_1,a_2,...,a_n</span>: weight of each apple.</p>
<p>The last line contains <span class="math inline">m</span> integers <span class="math inline">b_1,b_2,...,b_m</span>: weight of each banana.</p>
<h1 id="output">Output</h1>
<p>For each integer <span class="math inline">w</span> between <span class="math inline">2 ... 2k</span> print the number of ways to choose an apple and a banana whose combined weight is <span class="math inline">w</span>.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= k,n,m <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= a_i <= k</span></li>
<li><span class="math inline">1 <= b_i <= k</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5 3 4
5 2 5
4 3 2 3
</pre>
<p>Output:</p>
<pre>0 0 1 2 1 2 4 2 0  
</pre>
<p>Explanation: For example for <span class="math inline">w</span> = <span class="math inline">8</span> there are <span class="math inline">4</span> different ways: we can pick an apple of weight <span class="math inline">5</span> in two different ways and a banana of weight <span class="math inline">3</span> in two different ways.</p>
</div></div>

## CSES - One Bit Positions
<div class="md"><div class="md"><p>You are given a binary string of length <span class="math inline">n</span>. Your task is to calculate, for every <span class="math inline">k</span> between <span class="math inline">1 ... n-1</span>, the number of ways we can choose two positions <span class="math inline">i</span> and <span class="math inline">j</span> such that <span class="math inline">i-j=k</span> and there is a one-bit at both positions.</p>
<h1 id="input">Input</h1>
<p>The only input line has a string that consists only of characters <span class="math inline">0</span> and <span class="math inline">1</span>.</p>
<h1 id="output">Output</h1>
<p>For every distance <span class="math inline">k</span> between <span class="math inline">1... n-1</span> print the number of ways we can choose two such positions.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">2 <= n <= 2 . 10^5</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>1001011010
</pre>
<p>Output:</p>
<pre>1 2 3 0 2 1 0 1 0
</pre></div></div>

## CSES - Signal Processing
<div class="md"><div class="md"><p>You are given two integer sequences: a signal and a mask. Your task is to process the signal by moving the mask through the signal from left to right. At each mask position calculate the sum of products of aligned signal and mask values in the part where the signal and the mask overlap.</p>
<h1 id="input">Input</h1>
<p>The first input line consists of two integers <span class="math inline">n</span> and <span class="math inline">m</span>: the length of the signal and the length of the mask.</p>
<p>The next line consists of <span class="math inline">n</span> integers <span class="math inline">a_1,a_2,...,a_n</span> defining the signal.</p>
<p>The last line consists of <span class="math inline">m</span> integers <span class="math inline">b_1,b_2,...,b_m</span> defining the mask. </p>
<h1 id="output">Output</h1>
<p>Print <span class="math inline">n+m-1</span> integers: the sum of products of aligned values at each mask position from left to right.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n,m <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= a_i,b_i <= 100</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5 3
1 3 2 1 4
1 2 3
</pre>
<p>Output:</p>
<pre>3 11 13 10 16 9 4
</pre>
<p>Explanation: For example, at the second mask position the sum of aligned products is <span class="math inline">2 . 1 + 3 . 3 = 11</span>.</p>
</div></div>

## CSES - New Roads Queries
<div class="md"><div class="md"><p>There are <span class="math inline">n</span> cities in Byteland but no roads between them. However, each day, a new road will be built. There will be a total of <span class="math inline">m</span> roads.</p>
<p>Your task is to process <span class="math inline">q</span> queries of the form: "after how many days can we travel from city <span class="math inline">a</span> to city <span class="math inline">b</span> for the first time?"</p>
<h1 id="input">Input</h1>
<p>The first input line has three integers <span class="math inline">n</span>, <span class="math inline">m</span> and <span class="math inline">q</span>: the number of cities, roads and queries. The cities are numbered <span class="math inline">1,2,\dots,n</span>.</p>
<p>After this, there are <span class="math inline">m</span> lines that describe the roads in the order they are built. Each line has two integers <span class="math inline">a</span> and <span class="math inline">b</span>: there will be a road between cities <span class="math inline">a</span> and <span class="math inline">b</span>.</p>
<p>Finally, there are <span class="math inline">q</span> lines that describe the queries. Each line has two integers <span class="math inline">a</span> and <span class="math inline">b</span>: we want to travel from city <span class="math inline">a</span> to city <span class="math inline">b</span>.</p>
<h1 id="output">Output</h1>
<p>For each query, print the number of days, or <span class="math inline">-1</span> if it is never possible.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n, m, q <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= a,b <= n</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5 4 3
1 2
2 3
1 3
2 5
1 3
3 4
3 5
</pre>
<p>Output:</p>
<pre>2
-1
4
</pre></div></div>

## CSES - Dynamic Connectivity
<div class="md"><div class="md"><p>Consider an undirected graph that consists of <span class="math inline">n</span> nodes and <span class="math inline">m</span> edges. There are two types of events that can happen:</p>
<ol>
<li>A new edge is created between nodes <span class="math inline">a</span> and <span class="math inline">b</span>.</li>
<li>An existing edge between nodes <span class="math inline">a</span> and <span class="math inline">b</span> is removed.</li>
</ol>
<p>Your task is to report the number of components after every event.</p>
<h1 id="input">Input</h1>
<p>The first input line has three integers <span class="math inline">n</span>, <span class="math inline">m</span> and <span class="math inline">k</span>: the number of nodes, edges and events.</p>
<p>After this there are <span class="math inline">m</span> lines describing the edges. Each line has two integers <span class="math inline">a</span> and <span class="math inline">b</span>: there is an edge between nodes <span class="math inline">a</span> and <span class="math inline">b</span>. There is at most one edge between any pair of nodes.</p>
<p>Then there are <span class="math inline">k</span> lines describing the events. Each line has the form "<span class="math inline">t</span> <span class="math inline">a</span> <span class="math inline">b</span>" where <span class="math inline">t</span> is 1 (create a new edge) or 2 (remove an edge). A new edge is always created between two nodes that do not already have an edge between them, and only existing edges can get removed.</p>
<h1 id="output">Output</h1>
<p>Print <span class="math inline">k+1</span> integers: first the number of components before the first event, and after this the new number of components after each event.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">2 <= n <= 10^5</span></li>
<li><span class="math inline">1 <= m,k <= 10^5</span></li>
<li><span class="math inline">1 <= a,b <= n</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5 3 3
1 4
2 3
3 5
1 2 5
2 3 5
1 1 2
</pre>
<p>Output:</p>
<pre>2 2 2 1
</pre></div></div>

## CSES - Parcel Delivery
<div class="md"><div class="md"><p>There are <span class="math inline">n</span> cities and <span class="math inline">m</span> routes through which parcels can be carried from one city to another city. For each route, you know the maximum number of parcels and the cost of a single parcel.</p>
<p>You want to send <span class="math inline">k</span> parcels from Syrjälä to Lehmälä. What is the cheapest way to do that?</p>
<h1 id="input">Input</h1>
<p>The first input line has three integers <span class="math inline">n</span>, <span class="math inline">m</span> and <span class="math inline">k</span>: the number of cities, routes and parcels. The cities are numbered <span class="math inline">1,2,\dots,n</span>. City <span class="math inline">1</span> is Syrjälä and city <span class="math inline">n</span> is Lehmälä.</p>
<p>After this, there are <span class="math inline">m</span> lines that describe the routes. Each line has four integers <span class="math inline">a</span>, <span class="math inline">b</span>, <span class="math inline">r</span> and <span class="math inline">c</span>: there is a route from city <span class="math inline">a</span> to city <span class="math inline">b</span>, at most <span class="math inline">r</span> parcels can be carried through the route, and the cost of each parcel is <span class="math inline">c</span>.</p>
<h1 id="output">Output</h1>
<p>Print one integer: the minimum total cost or <span class="math inline">-1</span> if there are no solutions.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">2 <= n <= 500</span></li>
<li><span class="math inline">1 <= m <= 1000</span></li>
<li><span class="math inline">1 <= k <= 100</span></li>
<li><span class="math inline">1 <= a,b <= n</span></li>
<li><span class="math inline">1 <= r,c <= 1000</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>4 5 3
1 2 5 100
1 3 10 50
1 4 7 500
2 4 8 350
3 4 2 100
</pre>
<p>Output:</p>
<pre>750
</pre>
<p>Explanation: One parcel is delivered through route <span class="math inline">1 -> 2 -> 4</span> (cost <span class="math inline">1 . 450=450</span>) and two parcels are delivered through route <span class="math inline">1 -> 3 -> 4</span> (cost <span class="math inline">2 . 150=300</span>).</p>
</div></div>

## CSES - Task Assignment
<div class="md"><div class="md"><p>A company has <span class="math inline">n</span> employees and there are <span class="math inline">n</span> tasks that need to be done. We know for each employee the cost of carrying out each task. Every employee should be assigned to exactly one task. What is the minimum total cost if we assign the tasks optimally and how could they be assigned?</p>
<h1 id="input">Input</h1>
<p>The first input line has one integer <span class="math inline">n</span>: the number of employees and the number of tasks that need to be done.</p>
<p>After this, there are <span class="math inline">n</span> lines each consisting of <span class="math inline">n</span> integers. The <span class="math inline">i</span>th line consists of integers <span class="math inline">c_{i1},c_{i2},...,c_{in}</span>: the cost of each task when it is assigned to the <span class="math inline">i</span>th employee.</p>
<h1 id="output">Output</h1>
<p>First print the minimum total cost.</p>
<p>Then print <span class="math inline">n</span> lines each consisting of two integers <span class="math inline">a</span> and <span class="math inline">b</span>: you assign the <span class="math inline">b</span>th task to the <span class="math inline">a</span>th employee.</p>
<p>If there are multiple solutions you can print any of them.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 200</span></li>
<li><span class="math inline">1 <= c_{ij} <= 1000</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>4
17 8 16 9
7 15 12 19
6 9 10 11
14 7 13 10
</pre>
<p>Output:</p>
<pre>33
1 4
2 1
3 3
4 2
</pre>
<p>Explanation: The minimum total cost is <span class="math inline">33</span>. We can reach this by assigning employee 1 task 4, employee 2 task 1, employee 3 task 3 and employee 4 task 2. This will cost <span class="math inline">9 + 7 + 10 + 7 = 33</span>.</p>
</div></div>

## CSES - Distinct Routes II
<div class="md"><div class="md"><p>A game consists of <span class="math inline">n</span> rooms and <span class="math inline">m</span> teleporters. At the beginning of each day, you start in room <span class="math inline">1</span> and you have to reach room <span class="math inline">n</span>.</p>
<p>You can use each teleporter at most once during the game. You want to play the game for exactly <span class="math inline">k</span> days. Every time you use any teleporter you have to pay one coin. What is the minimum number of coins you have to pay during <span class="math inline">k</span> days if you play optimally?</p>
<h1 id="input">Input</h1>
<p>The first input line has three integers <span class="math inline">n</span>, <span class="math inline">m</span> and <span class="math inline">k</span>: the number of rooms, the number of teleporters and the number of days you play the game. The rooms are numbered <span class="math inline">1,2,\dots,n</span>.</p>
<p>After this, there are <span class="math inline">m</span> lines describing the teleporters. Each line has two integers <span class="math inline">a</span> and <span class="math inline">b</span>: there is a teleporter from room <span class="math inline">a</span> to room <span class="math inline">b</span>.</p>
<p>There are no two teleporters whose starting and ending room are the same.</p>
<h1 id="output">Output</h1>
<p>First print one integer: the minimum number of coins you have to pay if you play optimally. Then, print <span class="math inline">k</span> route descriptions according to the example. You can print any valid solution.</p>
<p>If it is not possible to play the game for <span class="math inline">k</span> days, print only -1.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">2 <= n <= 500</span></li>
<li><span class="math inline">1 <= m <= 1000</span></li>
<li><span class="math inline">1 <= k <= n-1</span></li>
<li><span class="math inline">1 <= a,b <= n</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>8 10 2
1 2
1 3
2 5
2 4
3 5 
3 6
4 8
5 8
6 7 
7 8
</pre>
<p>Output:</p>
<pre>6
4
1 2 4 8 
4
1 3 5 8 
</pre></div></div>

## CSES - Shortest Subsequence
<div class="md"><div class="md"><p>You are given a DNA sequence consisting of characters A, C, G, and T.</p>
<p>Your task is to find the shortest DNA sequence that is not a subsequence of the original sequence.</p>
<h1 id="input">Input</h1>
<p>The only input line contains a DNA sequence with <span class="math inline">n</span> characters.</p>
<h1 id="output">Output</h1>
<p>Print the shortest DNA sequence that is not a subsequence of the original sequence. If there are several solutions, you may print any of them.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 10^6</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>ACGTACGT
</pre>
<p>Output:</p>
<pre>AAA
</pre></div></div>

## CSES - Counting Bits
<div class="md"><div class="md"><p>Your task is to count the number of one bits in the binary representations of integers between <span class="math inline">1</span> and <span class="math inline">n</span>.</p>
<h1 id="input">Input</h1>
<p>The only input line has an integer <span class="math inline">n</span>.</p>
<h1 id="output">Output</h1>
<p>Print the number of one bits in the binary representations of integers between <span class="math inline">1</span> and <span class="math inline">n</span>.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 10^{15}</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>7
</pre>
<p>Output:</p>
<pre>12
</pre>
<p>Explanation: The binary representations of <span class="math inline">1 ... 7</span> are 1, 10, 11, 100, 101, 110, and 111, so there are a total of 12 one bits.</p>
</div></div>

## CSES - Swap Game
<div class="md"><div class="md"><p>You are given a <span class="math inline">3 x 3</span> grid containing the numbers <span class="math inline">1,2,\dots,9</span>. Your task is to perform a sequence of moves so that the grid will look like this:</p>
<pre>1 2 3
4 5 6
7 8 9
</pre>
<p>On each move, you can swap the numbers in any two adjacent squares (horizontally or vertically). What is the minimum number of moves required?</p>
<h1 id="input">Input</h1>
<p>The input has three lines, and each of them has three integers.</p>
<h1 id="output">Output</h1>
<p>Print one integer: the minimum number of moves.</p>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>2 1 3
7 5 9
8 4 6
</pre>
<p>Output:</p>
<pre>4
</pre></div></div>

## CSES - Prüfer Code
<div class="md"><div class="md"><p>A <em>Prüfer code</em> of a tree of <span class="math inline">n</span> nodes is a sequence of <span class="math inline">n-2</span> integers that uniquely specifies the structure of the tree.</p>
<p>The code is constructed as follows: As long as there are at least three nodes left, find a leaf with the smallest label, add the label of its only neighbor to the code, and remove the leaf from the tree.</p>
<p>Given a Prüfer code of a tree, your task is to construct the original tree.</p>
<h1 id="input">Input</h1>
<p>The first input line contains an integer <span class="math inline">n</span>: the number of nodes. The nodes are numbered <span class="math inline">1,2,...,n</span>.</p>
<p>The second line contains <span class="math inline">n-2</span> integers: the Prüfer code.</p>
<h1 id="output">Output</h1>
<p>Print <span class="math inline">n-1</span> lines describing the edges of the tree. Each line has to contain two integers <span class="math inline">a</span> and <span class="math inline">b</span>: there is an edge between nodes <span class="math inline">a</span> and <span class="math inline">b</span>. You can print the edges in any order.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">3 <= n <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= a,b <= n</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5
2 2 4
</pre>
<p>Output:</p>
<pre>1 2
2 3
2 4
4 5
</pre></div></div>

## CSES - Acyclic Graph Edges
<div class="md"><div class="md"><p>Given an undirected graph, your task is to choose a direction for each edge so that the resulting directed graph is acyclic.</p>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">n</span> and <span class="math inline">m</span>: the number of nodes and edges. The nodes are numbered <span class="math inline">1,2,\dots,n</span>.</p>
<p>After this, there are <span class="math inline">m</span> lines describing the edges. Each line has two distinct integers <span class="math inline">a</span> and <span class="math inline">b</span>: there is an edge between nodes <span class="math inline">a</span> and <span class="math inline">b</span>.</p>
<h1 id="output">Output</h1>
<p>Print <span class="math inline">m</span> lines describing the directions of the edges. Each line has two integers <span class="math inline">a</span> and <span class="math inline">b</span>: there is an edge from node <span class="math inline">a</span> to node <span class="math inline">b</span>. You can print any valid solution.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 10^5</span></li>
<li><span class="math inline">1 <= m <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= a,b <= n</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>3 3
1 2
2 3
3 1
</pre>
<p>Output:</p>
<pre>1 2
3 2
3 1
</pre></div></div>

## CSES - Strongly Connected Edges
<div class="md"><div class="md"><p>Given an undirected graph, your task is to choose a direction for each edge so that the resulting directed graph is strongly connected.</p>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">n</span> and <span class="math inline">m</span>: the number of nodes and edges. The nodes are numbered <span class="math inline">1,2,\dots,n</span>.</p>
<p>After this, there are <span class="math inline">m</span> lines describing the edges. Each line has two integers <span class="math inline">a</span> and <span class="math inline">b</span>: there is an edge between nodes <span class="math inline">a</span> and <span class="math inline">b</span>.</p>
<p>You may assume that the graph is simple, i.e., there are at most one edge between two nodes and every edge connects two distinct nodes.</p>
<h1 id="output">Output</h1>
<p>Print <span class="math inline">m</span> lines describing the directions of the edges. Each line has two integers <span class="math inline">a</span> and <span class="math inline">b</span>: there is an edge from node <span class="math inline">a</span> to node <span class="math inline">b</span>. You can print any valid solution.</p>
<p>If there are no solutions, only print "IMPOSSIBLE".</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 10^5</span></li>
<li><span class="math inline">1 <= m <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= a,b <= n</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>3 3
1 2
1 3
2 3
</pre>
<p>Output:</p>
<pre>1 2
2 3
3 1
</pre></div></div>

## CSES - Even Outdegree Edges
<div class="md"><div class="md"><p>Given an undirected graph, your task is to choose a direction for each edge so that in the resulting directed graph each node has an even outdegree. The outdegree of a node is the number of edges coming out of that node.</p>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">n</span> and <span class="math inline">m</span>: the number of nodes and edges. The nodes are numbered <span class="math inline">1,2,\dots,n</span>.</p>
<p>After this, there are <span class="math inline">m</span> lines describing the edges. Each line has two integers <span class="math inline">a</span> and <span class="math inline">b</span>: there is an edge between nodes <span class="math inline">a</span> and <span class="math inline">b</span>.</p>
<p>You may assume that the graph is simple, i.e., there is at most one edge between any two nodes and every edge connects two distinct nodes.</p>
<h1 id="output">Output</h1>
<p>Print <span class="math inline">m</span> lines describing the directions of the edges. Each line has two integers <span class="math inline">a</span> and <span class="math inline">b</span>: there is an edge from node <span class="math inline">a</span> to node <span class="math inline">b</span>. You can print any valid solution.</p>
<p>If there are no solutions, only print "IMPOSSIBLE".</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 10^5</span></li>
<li><span class="math inline">1 <= m <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= a,b <= n</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>4 4
1 2
2 3
3 4
1 4
</pre>
<p>Output:</p>
<pre>1 2
3 2
3 4
1 4
</pre></div></div>

## CSES - Multiplication Table
<div class="md"><div class="md"><p>Find the middle element when the numbers in an <span class="math inline">n x n</span> multiplication table are sorted in increasing order. It is assumed that <span class="math inline">n</span> is odd.</p>
<p>For example, the <span class="math inline">3 x 3</span> multiplication table is as follows:
<span class="math display">
\begin{matrix}
1 &amp; 2 &amp; 3 \\
2 &amp; 4 &amp; 6 \\
3 &amp; 6 &amp; 9 \\
\end{matrix}
</span>
The numbers in increasing order are <span class="math inline">[1,2,2,3,3,4,6,6,9]</span>, so the answer is <span class="math inline">3</span>.</p>
<h1 id="input">Input</h1>
<p>The only input line has an integer <span class="math inline">n</span>.</p>
<h1 id="output">Output</h1>
<p>Print one integer: the answer to the task.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n &lt; 10^6</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>3
</pre>
<p>Output:</p>
<pre>3
</pre></div></div>

## CSES - Advertisement
<div class="md"><div class="md"><p>A fence consists of <span class="math inline">n</span> vertical boards. The width of each board is 1 and their heights may vary.</p>
<p>You want to attach a rectangular advertisement to the fence. What is the maximum area of such an advertisement?</p>
<h1 id="input">Input</h1>
<p>The first input line contains an integer <span class="math inline">n</span>: the width of the fence.</p>
<p>After this, there are <span class="math inline">n</span> integers <span class="math inline">k_1,k_2,...,k_n</span>: the height of each board.</p>
<h1 id="output">Output</h1>
<p>Print one integer: the maximum area of an advertisement.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= k_i <= 10^9</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>8
4 1 5 3 3 2 4 1
</pre>
<p>Output:</p>
<pre>10
</pre></div></div>

## CSES - Special Substrings
<div class="md"><div class="md"><p>A substring is called <em>special</em> if every character that appears in the string appears the same number of times in the substring.</p>
<p>Your task is to count the number of special substrings in a given string.</p>
<h1 id="input">Input</h1>
<p>The only input line has a string of length <span class="math inline">n</span>. Every character is between a...z.</p>
<h1 id="output">Output</h1>
<p>Print one integer: the number of special substrings.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 2 . 10^5</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>abccabab
</pre>
<p>Output:</p>
<pre>5
</pre>
<p>Explanation: The special substrings are <code>abc</code>, <code>cab</code>, <code>abccab</code>, <code>bccaba</code> and <code>ccabab</code>.</p>
</div></div>

## CSES - Permutation Inversions
<div class="md"><div class="md"><p>Your task is to count the number of permutations of <span class="math inline">1,2,\dots,n</span> that have exactly <span class="math inline">k</span> inversions (i.e., pairs of elements in the wrong order).</p>
<p>For example, when <span class="math inline">n=4</span> and <span class="math inline">k=3</span>, there are <span class="math inline">6</span> such permutations:</p>
<ul>
<li><span class="math inline">[1,4,3,2]</span></li>
<li><span class="math inline">[2,3,4,1]</span></li>
<li><span class="math inline">[2,4,1,3]</span></li>
<li><span class="math inline">[3,1,4,2]</span></li>
<li><span class="math inline">[3,2,1,4]</span></li>
<li><span class="math inline">[4,1,2,3]</span></li>
</ul>
<h1 id="input">Input</h1>
<p>The only input line has two integers <span class="math inline">n</span> and <span class="math inline">k</span>.</p>
<h1 id="output">Output</h1>
<p>Print the answer modulo <span class="math inline">10^9+7</span>.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 500</span></li>
<li><span class="math inline">0 <= k <= \frac{n(n-1)}{2}</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>4 3
</pre>
<p>Output:</p>
<pre>6
</pre></div></div>

## CSES - Maximum Xor Subarray
<div class="md"><div class="md"><p>Given an array of <span class="math inline">n</span> integers, your task is to find the maximum xor sum in a subarray.</p>
<h1 id="input">Input</h1>
<p>The first input line has an integer <span class="math inline">n</span>: the size of the array.</p>
<p>The next line has <span class="math inline">n</span> integers <span class="math inline">x_1,x_2,\dots,x_n</span>: the contents of the array.</p>
<h1 id="output">Output</h1>
<p>Print one integer: the maximum xor sum in a subarray.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 2 . 10^5</span></li>
<li><span class="math inline">0 <= x_i <= 10^9</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>4
5 1 5 9
</pre>
<p>Output:</p>
<pre>13
</pre></div></div>

## CSES - Movie Festival Queries
<div class="md"><div class="md"><p>In a movie festival, <span class="math inline">n</span> movies will be shown. You know the starting and ending time of each movie.</p>
<p>Your task is to process <span class="math inline">q</span> queries of the form: if you arrive and leave the festival at specific times, what is the maximum number of movies you can watch?</p>
<p>You can watch two movies if the first movie ends before or exactly when the second movie starts. You can start the first movie exactly when you arrive and leave exactly when the last movie ends.</p>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">n</span> and <span class="math inline">q</span>: the number of movies and queries.</p>
<p>After this, there are <span class="math inline">n</span> lines describing the movies. Each line has two integers <span class="math inline">a</span> and <span class="math inline">b</span>: the starting and ending time of a movie.</p>
<p>Finally, there are <span class="math inline">q</span> lines describing the queries. Each line has two integers <span class="math inline">a</span> and <span class="math inline">b</span>: your arrival and leaving time.</p>
<h1 id="output">Output</h1>
<p>Print the maximum number of movies for each query.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n,q <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= a &lt; b <= 10^6</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>4 3
2 5
6 10
4 7
9 10
5 9
2 10
7 10
</pre>
<p>Output:</p>
<pre>0
2
1
</pre></div></div>

## CSES - Chess Tournament
<div class="md"><div class="md"><p>There will be a chess tournament of <span class="math inline">n</span> players. Each player has announced the number of games they want to play.</p>
<p>Each pair of players can play at most one game. Your task is to determine which games will be played so that everybody will be happy.</p>
<h1 id="input">Input</h1>
<p>The first input line has an integer <span class="math inline">n</span>: the number of players. The players are numbered <span class="math inline">1,2,\dots,n</span>.</p>
<p>The next line has <span class="math inline">n</span> integers <span class="math inline">x_1,x_2,\dots,x_n</span>: for each player, the number of games they want to play.</p>
<h1 id="output">Output</h1>
<p>First print an integer <span class="math inline">k</span>: the number of games. Then, print <span class="math inline">k</span> lines describing the games. You can print any valid solution.</p>
<p>If there are no solutions, print "IMPOSSIBLE".</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 10^5</span></li>
<li><span class="math inline">\sum_{i=1}^{n} x_i <= 2 . 10^5</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5
1 3 2 0 2
</pre>
<p>Output:</p>
<pre>4
1 2
2 3
2 5
3 5
</pre></div></div>

## CSES - Tree Traversals
<div class="md"><div class="md"><p>There are three common ways to traverse the nodes of a binary tree:</p>
<ul>
<li><em>Preorder</em>: First process the root, then the left subtree, and finally the right subtree.</li>
<li><em>Inorder</em>: First process the left subtree, then the root, and finally the right subtree.</li>
<li><em>Postorder</em>: First process the left subtree, then the right subtree, and finally the root.</li>
</ul>
<p>There is a binary tree of <span class="math inline">n</span> nodes with distinct labels. You are given the preorder and inorder traversals of the tree, and your task is to determine its postorder traversal.</p>
<h1 id="input">Input</h1>
<p>The first input line has an integer <span class="math inline">n</span>: the number of nodes. The nodes are numbered <span class="math inline">1,2,\dots,n</span>.</p>
<p>After this, there are two lines describing the preorder and inorder traversals of the tree. Both lines consist of <span class="math inline">n</span> integers.</p>
<p>You can assume that the input corresponds to a binary tree.</p>
<h1 id="output">Output</h1>
<p>Print the postorder traversal of the tree.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 10^5</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5
5 3 2 1 4
3 5 1 2 4
</pre>
<p>Output:</p>
<pre>3 1 4 2 5
</pre></div></div>

## CSES - Network Renovation
<div class="md"><div class="md"><p>Syrjälä's network consists of <span class="math inline">n</span> computers and <span class="math inline">n-1</span> connections between them. It is possible to send data between any two computers.</p>
<p>However, if any connection breaks down, it will no longer be possible to send data between some computers. Your task is to add the minimum number of new connections in such a way that you can still send data between any two computers even if any single connection breaks down.</p>
<h1 id="input">Input</h1>
<p>The first input line has an integer <span class="math inline">n</span>: the number of computers. The computers are numbered <span class="math inline">1,2,\dots,n</span>.</p>
<p>After this, there are <span class="math inline">n-1</span> lines describing the connections. Each line has two integers <span class="math inline">a</span> and <span class="math inline">b</span>: there is a connection between computers <span class="math inline">a</span> and <span class="math inline">b</span>.</p>
<h1 id="output">Output</h1>
<p>First print an integer <span class="math inline">k</span>: the minimum number of new connections. After this, print <span class="math inline">k</span> lines describing the connections. You can print any valid solution.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">3 <= n <= 10^5</span></li>
<li><span class="math inline">1 <= a,b <= n</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5
1 2
1 3
3 4
3 5
</pre>
<p>Output:</p>
<pre>2
2 4
4 5
</pre></div></div>

## CSES - Graph Girth
<div class="md"><div class="md"><p>Given an undirected graph, your task is to determine its <em>girth</em>, i.e., the length of its shortest cycle.</p>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">n</span> and <span class="math inline">m</span>: the number of nodes and edges. The nodes are numbered <span class="math inline">1,2,\dots,n</span>.</p>
<p>After this, there are <span class="math inline">m</span> lines describing the edges. Each line has two integers <span class="math inline">a</span> and <span class="math inline">b</span>: there is an edge between nodes <span class="math inline">a</span> and <span class="math inline">b</span>.</p>
<p>You may assume that there is at most one edge between each two nodes.</p>
<h1 id="output">Output</h1>
<p>Print one integer: the girth of the graph. If there are no cycles, print <span class="math inline">-1</span>.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 2500</span></li>
<li><span class="math inline">1 <= m <= 5000</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5 6
1 2
1 3
2 4
2 5
3 4
4 5
</pre>
<p>Output:</p>
<pre>3
</pre></div></div>

## CSES - Intersection Points
<div class="md"><div class="md"><p>Given <span class="math inline">n</span> horizontal and vertical line segments, your task is to calculate the number of their intersection points.</p>
<p>You can assume that no parallel line segments intersect, and no endpoint of a line segment is an intersection point.</p>
<h1 id="input">Input</h1>
<p>The first input line has an integer <span class="math inline">n</span>: the number of line segments.</p>
<p>Then there are <span class="math inline">n</span> lines describing the line segments. Each line has four integers: <span class="math inline">x_1</span>, <span class="math inline">y_1</span>, <span class="math inline">x_2</span> and <span class="math inline">y_2</span>: a line segment begins at point <span class="math inline">(x_1,y_1)</span> and ends at point <span class="math inline">(x_2,y_2)</span>.</p>
<h1 id="output">Output</h1>
<p>Print the number of intersection points.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 10^5</span></li>
<li><span class="math inline">-10^6 <= x_1 <= x_2 <= 10^6</span></li>
<li><span class="math inline">-10^6 <= y_1 <= y_2 <= 10^6</span></li>
<li><span class="math inline">(x_1,y_1) \neq (x_2,y_2)</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>3
2 3 7 3
3 1 3 5
6 2 6 6
</pre>
<p>Output:</p>
<pre>2
</pre></div></div>

## CSES - Inverse Inversions
<div class="md"><div class="md"><p>Your task is to create a permutation of numbers <span class="math inline">1,2,\dots,n</span> that has exactly <span class="math inline">k</span> inversions.</p>
<p>An inversion is a pair <span class="math inline">(a,b)</span> where <span class="math inline">a&lt;b</span> and <span class="math inline">p_a&gt;p_b</span> where <span class="math inline">p_i</span> denotes the number at position <span class="math inline">i</span> in the permutation.</p>
<h1 id="input">Input</h1>
<p>The only input line has two integers <span class="math inline">n</span> and <span class="math inline">k</span>.</p>
<h1 id="output">Output</h1>
<p>Print a line that contains the permutation. You can print any valid solution.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 10^6</span></li>
<li><span class="math inline">0 <= k <= \frac{n(n-1)}{2}</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5 4
</pre>
<p>Output:</p>
<pre>1 5 2 4 3
</pre></div></div>

## CSES - Monotone Subsequences
<div class="md"><div class="md"><p>Your task is to create a permutation of numbers <span class="math inline">1,2,\dots,n</span> whose longest monotone subsequence has exactly <span class="math inline">k</span> elements.</p>
<p>A monotone subsequence is either increasing or decreasing. For example, some monotone subsequences in <span class="math inline">[2,1,4,5,3]</span> are <span class="math inline">[2,4,5]</span> and <span class="math inline">[4,3]</span>.</p>
<h1 id="input">Input</h1>
<p>The first input line has an integer <span class="math inline">t</span>: the number of tests.</p>
<p>After this, there are <span class="math inline">t</span> lines. Each line has two integers <span class="math inline">n</span> and <span class="math inline">k</span>.</p>
<h1 id="output">Output</h1>
<p>For each test, print a line that contains the permutation. You can print any valid solution. If there are no solutions, print "IMPOSSIBLE".</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= t <= 1000</span></li>
<li><span class="math inline">1 <= k <= n <= 100</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>3
5 3
5 2
7 7
</pre>
<p>Output:</p>
<pre>2 1 4 5 3
IMPOSSIBLE
1 2 3 4 5 6 7
</pre></div></div>

## CSES - String Reorder
<div class="md"><div class="md"><p>Given a string, you want to reorder its characters so that no two adjacent characters are the same. What is the lexicographically minimal such string?</p>
<h1 id="input">Input</h1>
<p>The only input line as a string of length <span class="math inline">n</span> consisting of characters A–Z.</p>
<h1 id="output">Output</h1>
<p>Print the lexicographically minimal reordered string where no two adjacent characters are the same. If it is not possible to create such a string, print <span class="math inline">-1</span>.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 10^6</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>HATTIVATTI
</pre>
<p>Output:</p>
<pre>AHATITITVT
</pre></div></div>

## CSES - Stack Weights
<div class="md"><div class="md"><p>You have <span class="math inline">n</span> coins, each of which has a distinct weight.</p>
<p>There are two stacks which are initially empty. On each step you move one coin to a stack. You never remove a coin from a stack.</p>
<p>After each move, your task is to determine which stack is heavier (if we can be sure that either stack is heavier).</p>
<h1 id="input">Input</h1>
<p>The first input line has an integer <span class="math inline">n</span>: the number of coins. The coins are numbered <span class="math inline">1,2,\dots,n</span>. You know that coin <span class="math inline">i</span> is always heavier than coin <span class="math inline">i-1</span>, but you don't know their exact weights.</p>
<p>After this, there are <span class="math inline">n</span> lines that describe the moves. Each line has two integers <span class="math inline">c</span> and <span class="math inline">s</span>: move coin <span class="math inline">c</span> to stack <span class="math inline">s</span> (1 = left, 2 = right).</p>
<h1 id="output">Output</h1>
<p>After each move, print <code>&lt;</code> if the right stack is heavier, <code>&gt;</code> if the left stack is heavier, and <code>?</code> if we can't know which stack is heavier.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 2 . 10^5</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>3
2 1
3 2
1 1
</pre>
<p>Output:</p>
<pre>&gt;
&lt;
?
</pre>
<p>Explanation: After the last move, if the coins are <span class="math inline">[2,3,4]</span>, the left stack is heavier, but if the coins are <span class="math inline">[1,2,5]</span>, the right stack is heavier.</p>
</div></div>

## CSES - Pyramid Array
<div class="md"><div class="md"><p>You are given an array consisting of <span class="math inline">n</span> distinct integers. On each move, you can swap any two adjacent values.</p>
<p>You want to transform the array into a <em>pyramid array</em>. This means that the final array has to be first increasing and then decreasing. It is also allowed that the final array is only increasing or decreasing.</p>
<p>What is the minimum number of moves needed?</p>
<h1 id="input">Input</h1>
<p>The first input line has an integer <span class="math inline">n</span>: the size of the array.</p>
<p>The next line has <span class="math inline">n</span> distinct integers <span class="math inline">x_1,x_2,\dots,x_n</span>: the contents of the array.</p>
<h1 id="output">Output</h1>
<p>Print one integer: the minimum number of moves.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= x_i <= 10^9</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>4
2 1 5 3
</pre>
<p>Output:</p>
<pre>1
</pre>
<p>Explanation: You may swap the first two values which creates a pyramid array <span class="math inline">[1,2,5,3]</span>.</p>
</div></div>

## CSES - Increasing Subsequence II
<div class="md"><div class="md"><p>Given an array of <span class="math inline">n</span> integers, your task is to calculate the number of increasing subsequences it contains. If two subsequences have the same values but in different positions in the array, they are counted separately.</p>
<h1 id="input">Input</h1>
<p>The first input line has an integer <span class="math inline">n</span>: the size of the array.</p>
<p>The second line has <span class="math inline">n</span> integers <span class="math inline">x_1,x_2,\dots,x_n</span>: the contents of the array.</p>
<h1 id="output">Output</h1>
<p>Print one integer: the number of increasing subsequences modulo <span class="math inline">10^9+7</span>.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= x_i <= 10^9</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>3
2 1 3
</pre>
<p>Output:</p>
<pre>5
</pre>
<p>Explanation: The increasing subsequences are <span class="math inline">[2]</span>, <span class="math inline">[1]</span>, <span class="math inline">[3]</span>, <span class="math inline">[2,3]</span> and <span class="math inline">[1,3]</span>.</p>
</div></div>

## CSES - String Removals
<div class="md"><div class="md"><p>You are given a string. You can remove any number of characters from it, but you cannot change the order of the remaining characters.</p>
<p>How many different strings can you generate?</p>
<h1 id="input">Input</h1>
<p>The first input line contains a string of size <span class="math inline">n</span>. Each character is one of a–z.</p>
<h1 id="output">Output</h1>
<p>Print one integer: the number of strings modulo <span class="math inline">10^9+7</span>.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 5 . 10^5</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>aybabtu
</pre>
<p>Output:</p>
<pre>103
</pre></div></div>

## CSES - Bit Inversions
<div class="md"><div class="md"><p>There is a bit string consisting of <span class="math inline">n</span> bits. Then, there are some changes that invert one given bit. Your task is to report, after each change, the length of the longest substring whose each bit is the same.</p>
<h1 id="input">Input</h1>
<p>The first input line has a bit string consisting of <span class="math inline">n</span> bits. The bits are numbered <span class="math inline">1,2,...,n</span>.</p>
<p>The next line contains an integer <span class="math inline">m</span>: the number of changes.</p>
<p>The last line contains <span class="math inline">m</span> integers <span class="math inline">x_1,x_2,...,x_m</span> describing the changes.</p>
<h1 id="output">Output</h1>
<p>After each change, print the length of the longest substring whose each bit is the same.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= m <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= x_i <= n</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>001011
3
3 2 5
</pre>
<p>Output:</p>
<pre>4 2 3
</pre>
<p>Explanation: The bit string first becomes <code>000011</code>, then <code>010011</code>, and finally <code>010001</code>.</p>
</div></div>

## CSES - Xor Pyramid
<div class="md"><div class="md"><p>Consider a xor pyramid where each number is the xor of lower-left and lower-right numbers. Here is an example pyramid:
<center><img alt="" class="invertible" height="" src="/file/382652cc16953396bbaeeabf0e98daec74a4bda09afb8db8da0e67870205fc76" width="250"/></center>
Given the bottom row of the pyramid, your task is to find the topmost number.</p>
<h1 id="input">Input</h1>
<p>The first input line has an integer <span class="math inline">n</span>: the size of the pyramid.</p>
<p>The next line has <span class="math inline">n</span> integers <span class="math inline">a_1,a_2,\dots,a_n</span>: the bottom row of the pyramid.</p>
<h1 id="output">Output</h1>
<p>Print one integer: the topmost number.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= a_i <= 10^9</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>8
2 10 5 12 9 5 1 5
</pre>
<p>Output:</p>
<pre>9
</pre></div></div>

## CSES - Writing Numbers
<div class="md"><div class="md"><p>You would like to write a list of positive integers <span class="math inline">1,2,3,...</span> using your computer. However, you can press each key <span class="math inline">0</span>–<span class="math inline">9</span> at most <span class="math inline">n</span> times during the process.</p>
<p>What is the last number you can write?</p>
<h1 id="input">Input</h1>
<p>The only input line contains the value of <span class="math inline">n</span>.</p>
<h1 id="output">Output</h1>
<p>Print the last number you can write.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 10^{18}</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5
</pre>
<p>Output:</p>
<pre>12
</pre>
<p>Explanation: You can write the numbers <span class="math inline">1,2,...,12</span>. This requires that you press key <span class="math inline">1</span> five times, so you cannot write the number <span class="math inline">13</span>.</p>
</div></div>

## CSES - String Transform
<div class="md"><div class="md"><p>Consider the following string transformation:</p>
<ol>
<li>append the character # to the string (we assume that # is lexicographically smaller than all other characters of the string)</li>
<li>generate all rotations of the string</li>
<li>sort the rotations in increasing order</li>
<li>based on this order, construct a new string that contains the last character of each rotation</li>
</ol>
<p>For example, the string <code>babc</code> becomes <code>babc#</code>. Then, the sorted list of rotations is <code>#babc</code>, <code>abc#b</code>, <code>babc#</code>, <code>bc#ba</code>, and <code>c#bab</code>. This yields a string <code>cb#ab</code>.</p>
<h1 id="input">Input</h1>
<p>The only input line contains the transformed string of length <span class="math inline">n+1</span>. Each character of the original string is one of a–z.</p>
<h1 id="output">Output</h1>
<p>Print the original string of length <span class="math inline">n</span>.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 10^6</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>cb#ab
</pre>
<p>Output:</p>
<pre>babc
</pre></div></div>

## CSES - Letter Pair Move Game
<div class="md"><div class="md"><p>There are <span class="math inline">2n</span> boxes in a line. Two adjacent boxes are empty, and all other boxes have a letter "A" or "B". Both letters appear in exactly <span class="math inline">n-1</span> boxes.</p>
<p>Your task is to move the letters so that all letters "A" appear before any letter "B". On each turn you can choose any two adjacent boxes that have a letter and move the letters to the two adjacent empty boxes, preserving their order.</p>
<p>It can be proven that either there is a solution that consists of at most <span class="math inline">10n</span> turns or there are no solutions.</p>
<h1 id="input">Input</h1>
<p>The first line has an integer <span class="math inline">n</span>: there are <span class="math inline">2n</span> boxes.</p>
<p>The second line has a string of <span class="math inline">2n</span> characters which describes the starting position. Each character is "A", "B" or "." (empty box).</p>
<h1 id="output">Output</h1>
<p>First print an integer <span class="math inline">k</span>: the number of turns. After this, print <span class="math inline">k</span> lines that describe the moves. You can print any solution, as long as <span class="math inline">k <= 1000</span>.</p>
<p>If there are no solutions, print only "-1".</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 100</span></li>
</ul>
<h1 id="example1">Example 1</h1>
<p>Input:</p>
<pre>3
AB..BA
</pre>
<p>Output:</p>
<pre>2
ABBA..
A..ABB
</pre><h1 id="example2">Example 2</h1>
<p>Input:</p>
<pre>3
ABAB..
</pre>
<p>Output:</p>
<pre>-1
</pre></div></div>

## CSES - Maximum Building I
<div class="md"><div class="md"><p>You are given a map of a forest where some squares are empty and some squares have trees.</p>
<p>What is the maximum area of a rectangular building that can be placed in the forest so that no trees must be cut down?</p>
<h1 id="input">Input</h1>
<p>The first input line contains integers <span class="math inline">n</span> and <span class="math inline">m</span>: the size of the forest.</p>
<p>After this, the forest is described. Each square is empty (<code>.</code>) or has trees (<code>*</code>).</p>
<h1 id="input">Input</h1>
<p>Print the maximum area of a rectangular building.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n,m <= 1000</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>4 7
...*.*.
.*.....
.......
......*
</pre>
<p>Output:</p>
<pre>12
</pre></div></div>

## CSES - Sorting Methods
<div class="md"><div class="md"><p>Here are some possible methods using which we can sort the elements of an array in increasing order:</p>
<ol>
<li>At each step, choose two adjacent elements and swap them.</li>
<li>At each step, choose any two elements and swap them.</li>
<li>At each step, choose any element and move it to another position.</li>
<li>At each step, choose any element and move it to the front of the array.</li>
</ol>
<p>Given a permutation of numbers <span class="math inline">1,2,...,n</span>, calculate the minimum number of steps to sort the array using the above methods.</p>
<h1 id="input">Input</h1>
<p>The first input line contains an integer <span class="math inline">n</span>.</p>
<p>The second line contains <span class="math inline">n</span> integers describing the permutation.</p>
<h1 id="output">Output</h1>
<p>Print four numbers: the minimum number of steps using each method.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 2 . 10^5</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>8
7 8 2 6 5 1 3 4
</pre>
<p>Output:</p>
<pre>20 6 5 6
</pre></div></div>

## CSES - Cyclic Array
<div class="md"><div class="md"><p>You are given a cyclic array consisting of <span class="math inline">n</span> values. Each element has two neighbors; the elements at positions <span class="math inline">n</span> and <span class="math inline">1</span> are also considered neighbors.</p>
<p>Your task is to divide the array into subarrays so that the sum of each subarray is at most <span class="math inline">k</span>. What is the minimum number of subarrays?</p>
<h1 id="input">Input</h1>
<p>The first input line contains integers <span class="math inline">n</span> and <span class="math inline">k</span>.</p>
<p>The next line has <span class="math inline">n</span> integers <span class="math inline">x_1,x_2,...,x_n</span>: the contents of the array.</p>
<p>There is always at least one division (i.e., no value in the array is larger than <span class="math inline">k</span>).</p>
<h1 id="output">Output</h1>
<p>Print one integer: the minimum number of subarrays.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= x_i <= 10^9</span></li>
<li><span class="math inline">1 <= k <= 10^{18}</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>8 5
2 2 2 1 3 1 2 1
</pre>
<p>Output:</p>
<pre>3
</pre>
<p>Explanation: We can create three subarrays: <span class="math inline">[2,2,1]</span>, <span class="math inline">[3,1]</span>, and <span class="math inline">[2,1,2]</span> (remember that the array is cyclic).</p>
</div></div>

## CSES - List of Sums
<div class="md"><div class="md"><p>List <span class="math inline">A</span> consists of <span class="math inline">n</span> positive integers, and list <span class="math inline">B</span> contains the sum of each element pair of list <span class="math inline">A</span>.</p>
<p>For example, if <span class="math inline">A=[1,2,3]</span>, then <span class="math inline">B=[3,4,5]</span>, and if <span class="math inline">A=[1,3,3,3]</span>, then <span class="math inline">B=[4,4,4,6,6,6]</span>.</p>
<p>Given list <span class="math inline">B</span>, your task is to reconstruct list <span class="math inline">A</span>.</p>
<h1 id="input">Input</h1>
<p>The first input line has an integer <span class="math inline">n</span>: the size of list <span class="math inline">A</span>.</p>
<p>The next line has <span class="math inline">\frac{n(n-1)}{2}</span> integers: the contents of list <span class="math inline">B</span>.</p>
<p>You can assume that there is a list <span class="math inline">A</span> that corresponds to the input, and each value in <span class="math inline">A</span> is between <span class="math inline">1 \dots k</span>.</p>
<h1 id="output">Output</h1>
<p>Print <span class="math inline">n</span> integers: the contents of list <span class="math inline">A</span>.</p>
<p>You can print the values in any order. If there are more than one solution, you can print any of them.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">3 <= n <= 100</span></li>
<li><span class="math inline">1 <= k <= 10^9</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>4
4 4 4 6 6 6
</pre>
<p>Output:</p>
<pre>1 3 3 3
</pre>
<p>Explanation: In this case list <span class="math inline">A</span> can be either <span class="math inline">[1,3,3,3]</span> or <span class="math inline">[2,2,2,4]</span> and both solutions are accepted.</p>
</div></div>

## CSES - Increasing Array II
<div class="md"><div class="md"><p>You are given an array of <span class="math inline">n</span> integers. You want to modify the array so that it is increasing, i.e., every element is at least as large as the previous element.</p>
<p>On each move, you can increase or decrease the value of any element by one. What is the minimum number of moves required?</p>
<h1 id="input">Input</h1>
<p>The first input line contains an integer <span class="math inline">n</span>: the size of the array.</p>
<p>Then, the second line contains <span class="math inline">n</span> integers <span class="math inline">x_1,x_2,...,x_n</span>: the contents of the array.</p>
<h1 id="output">Output</h1>
<p>Print the minimum number of moves.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= x_i <= 10^9</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5
3 8 5 6 5
</pre>
<p>Output:</p>
<pre>4
</pre></div></div>

## CSES - Food Division
<div class="md"><div class="md"><p>There are <span class="math inline">n</span> children around a round table. For each child, you know the amount of food they currently have and the amount of food they want. The total amount of food in the table is correct.</p>
<p>At each step, a child can give one unit of food to his or her neighbour. What is the minimum number of steps needed?</p>
<h1 id="input">Input</h1>
<p>The first input line contains an integer <span class="math inline">n</span>: the number of children.</p>
<p>The next line has <span class="math inline">n</span> integers <span class="math inline">a_1,a_2,...,a_n</span>: the current amount of food for each child.</p>
<p>The last line has <span class="math inline">n</span> integers <span class="math inline">b_1,b_2,...,b_n</span>: the required amount of food for each child.</p>
<h1 id="output">Output</h1>
<p>Print one integer: the minimum number of steps.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 2 . 10^5</span></li>
<li><span class="math inline">0 <= a_i, b_i <= 10^6</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>3
3 5 0
2 4 2
</pre>
<p>Output:</p>
<pre>2
</pre>
<p>Explanation: Child 1 gives one unit of food to child 3, and child 2 gives one unit of food to child 3.</p>
</div></div>

## CSES - Bit Problem
<div class="md"><div class="md"><p>Given a list of <span class="math inline">n</span> integers, your task is to calculate for each element <span class="math inline">x</span>:</p>
<ol>
<li>the number of elements <span class="math inline">y</span> such that <span class="math inline">x \mid y = x</span></li>
<li>the number of elements <span class="math inline">y</span> such that <span class="math inline">x \mathrel{\&amp;} y = x</span></li>
<li>the number of elements <span class="math inline">y</span> such that <span class="math inline">x \mathrel{\&amp;} y \neq 0</span></li>
</ol>
<h1 id="input">Input</h1>
<p>The first input line has an integer <span class="math inline">n</span>: the size of the list.</p>
<p>The next line has <span class="math inline">n</span> integers <span class="math inline">x_1,x_2,\dots,x_n</span>: the elements of the list.</p>
<h1 id="output">Output</h1>
<p>Print <span class="math inline">n</span> lines: for each element the required values.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= x_i <= 10^6</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5
3 7 2 9 2
</pre>
<p>Output:</p>
<pre>3 2 5
4 1 5
2 4 4
1 1 3
2 4 4
</pre></div></div>

## CSES - Swap Round Sorting
<div class="md"><div class="md"><p>You are given an array containing a permutation of numbers <span class="math inline">1,2,\dots,n</span>, and your task is to sort the array using <em>swap rounds</em>. On each swap round, you can choose any number of distinct pairs of elements and swap each pair.</p>
<p>Your task is to find the minimum number of rounds and show how you can choose the pairs in each round.</p>
<h1 id="input">Input</h1>
<p>The first input line has an integer <span class="math inline">n</span>: the size of the array.</p>
<p>The second line has <span class="math inline">n</span> integers <span class="math inline">x_1,x_2,\dots,x_n</span>: the initial permutation.</p>
<h1 id="output">Output</h1>
<p>First print an integer <span class="math inline">k</span>: the minimum number of rounds.</p>
<p>Then, for each round, print the number of swaps and the indices of each swap. You can print any valid solution.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 2 . 10^5</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5
5 2 1 3 4
</pre>
<p>Output:</p>
<pre>2
2
1 3
4 5
1
3 5
</pre>
<p>Explanation: The inital array is <span class="math inline">[5,2,1,3,4]</span>. After round <span class="math inline">1</span>, the array becomes <span class="math inline">[1,2,5,4,3]</span>. After round <span class="math inline">2</span>, the array becomes <span class="math inline">[1,2,3,4,5]</span>.</p>
</div></div>

## CSES - Binary Subsequences
<div class="md"><div class="md"><p>Your task is to find a minimum length bit string that has exactly <span class="math inline">n</span> distinct subsequences.</p>
<p>For example, a correct solution for <span class="math inline">n=6</span> is <code>101</code> whose distinct subsequences are <code>0</code>, <code>1</code>, <code>01</code>, <code>10</code>, <code>11</code> and <code>101</code>.</p>
<h1 id="input">Input</h1>
<p>The only input line has an integer <span class="math inline">n</span>.</p>
<h1 id="output">Output</h1>
<p>Print one bit string: a solution to the task. You can print any valid solution.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 10^6</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>6
</pre>
<p>Output:</p>
<pre>101
</pre></div></div>

## CSES - Tree Isomorphism I
<div class="md"><div class="md"><p>Given two rooted trees, your task is to find out if they are <em>isomorphic</em>, i.e., it is possible to draw them so that they look the same.</p>
<h1 id="input">Input</h1>
<p>The first input line has an integer <span class="math inline">t</span>: the number of tests. Then, there are <span class="math inline">t</span> tests described as follows:</p>
<p>The first line has an integer <span class="math inline">n</span>: the number of nodes in both trees. The nodes are numbered <span class="math inline">1,2,\dots,n</span>, and node <span class="math inline">1</span> is the root.</p>
<p>Then, there are <span class="math inline">n-1</span> lines describing the edges of the first tree, and finally <span class="math inline">n-1</span> lines describing the edges of the second tree.</p>
<h1 id="output">Output</h1>
<p>For each test, print "YES", if the trees are isomorphic, and "NO" otherwise.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= t <= 1000</span></li>
<li><span class="math inline">2 <= n <= 10^5</span></li>
<li>the sum of all values of <span class="math inline">n</span> is at most <span class="math inline">10^5</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>2
3
1 2
2 3
1 2
1 3
3
1 2
2 3
1 3
3 2
</pre>
<p>Output:</p>
<pre>NO
YES
</pre></div></div>

## CSES - Counting Sequences
<div class="md"><div class="md"><p>Your task is to count the number of sequences of length <span class="math inline">n</span> where each element is an integer between <span class="math inline">1 \dots k</span> and each integer between <span class="math inline">1 \dots k</span> appears at least once in the sequence.</p>
<p>For example, when <span class="math inline">n=6</span> and <span class="math inline">k=4</span>, some valid sequences are <span class="math inline">[1,3,1,4,3,2]</span> and <span class="math inline">[2,2,1,3,4,2]</span>.</p>
<h1 id="input">Input</h1>
<p>The only input line has two integers <span class="math inline">n</span> and <span class="math inline">k</span>.</p>
<h1 id="output">Output</h1>
<p>Print one integer: the number of sequences modulo <span class="math inline">10^9+7</span>.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= k <= n <= 10^6</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>6 4
</pre>
<p>Output:</p>
<pre>1560
</pre></div></div>

## CSES - Critical Cities
<div class="md"><div class="md"><p>There are <span class="math inline">n</span> cities and <span class="math inline">m</span> flight connections between them. A city is called a <em>critical city</em> if it appears on every route from a city to another city.</p>
<p>Your task is to find all critical cities from Syrjälä to Lehmälä.</p>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">n</span> and <span class="math inline">m</span>: the number of cities and flights. The cities are numbered <span class="math inline">1,2,\dots,n</span>. City <span class="math inline">1</span> is Syrjälä, and city <span class="math inline">n</span> is Lehmälä.</p>
<p>Then, there are <span class="math inline">m</span> lines describing the connections. Each line has two integers <span class="math inline">a</span> and <span class="math inline">b</span>: there is a flight from city <span class="math inline">a</span> to city <span class="math inline">b</span>. All flights are one-way.</p>
<p>You may assume that there is a route from Syrjälä to Lehmälä.</p>
<h1 id="output">Output</h1>
<p>First print an integer <span class="math inline">k</span>: the number of critical cities. After this, print <span class="math inline">k</span> integers: the critical cities in increasing order.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">2 <= n <= 10^5</span></li>
<li><span class="math inline">1 <= m <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= a,b <= n</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5 5
1 2
2 3
2 4
3 5
4 5
</pre>
<p>Output:</p>
<pre>3
1 2 5
</pre></div></div>

## CSES - School Excursion
<div class="md"><div class="md"><p>A group of <span class="math inline">n</span> children are coming to Helsinki. There are two possible attractions: a child can visit either Korkeasaari (zoo) or Linnanmäki (amusement park).</p>
<p>There are <span class="math inline">m</span> pairs of children who want to visit the same attraction. Your task is to find all possible alternatives for the number of children that will visit Korkeasaari. The children's wishes have to be taken into account.</p>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">n</span> and <span class="math inline">m</span>: the number of children and their wishes. The children are numbered <span class="math inline">1,2,\dots,n</span>.</p>
<p>After this, there are <span class="math inline">m</span> lines describing the children's wishes. Each line has two integers <span class="math inline">a</span> and <span class="math inline">b</span>: children <span class="math inline">a</span> and <span class="math inline">b</span> want to visit the same attraction.</p>
<h1 id="output">Output</h1>
<p>Print a bit string of length <span class="math inline">n</span> where a one-bit at index <span class="math inline">i</span> indicates that it is possible that exactly <span class="math inline">i</span> children visit Korkeasaari (the bit string is to be considered one-indexed).</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 10^5</span></li>
<li><span class="math inline">0 <= m <= 10^5</span></li>
<li><span class="math inline">1 <= a,b <= n</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5 3
1 2
2 3
1 5
</pre>
<p>Output:</p>
<pre>10011
</pre>
<p>Explanation: The number of children visiting Korkeasaari can be <span class="math inline">1</span>, <span class="math inline">4</span> or <span class="math inline">5</span>.</p>
</div></div>

## CSES - Coin Grid
<div class="md"><div class="md"><p>There is an <span class="math inline">n x n</span> grid whose each square is empty or has a coin. On each move, you can remove all coins in a row or column.</p>
<p>What is the minimum number of moves after which the grid is empty?</p>
<h1 id="input">Input</h1>
<p>The first input line has an integer <span class="math inline">n</span>: the size of the grid. The rows and columns are numbered <span class="math inline">1,2,\dots,n</span>.</p>
<p>After this, there are <span class="math inline">n</span> lines describing the grid. Each line has <span class="math inline">n</span> characters: each character is either <code>.</code> (empty) or <code>o</code> (coin).</p>
<h1 id="output">Output</h1>
<p>First print an integer <span class="math inline">k</span>: the minimum number of moves. After this, print <span class="math inline">k</span> lines describing the moves.</p>
<p>On each line, first print <span class="math inline">1</span> (row) or <span class="math inline">2</span> (column), and then the number of a row or column. You can print any valid solution.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 100</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>3
..o
o.o
...
</pre>
<p>Output:</p>
<pre>2
1 2
2 3
</pre></div></div>

## CSES - Robot Path
<div class="md"><div class="md"><p>You are given a description of a robot's path. The robot begins at point <span class="math inline">(0,0)</span> and performs <span class="math inline">n</span> commands. Each command moves the robot some distance up, down, left or right.</p>
<p>The robot will stop when it has performed all commands, or immediately when it returns to a point that it has already visited. Your task is to calculate the total distance the robot moves.</p>
<h1 id="input">Input</h1>
<p>The first input line has an integer <span class="math inline">n</span>: the number of commands.</p>
<p>After that, there are <span class="math inline">n</span> lines describing the commands. Each line has a character <span class="math inline">d</span> and an integer <span class="math inline">x</span>: the robot moves the distance  <span class="math inline">x</span> to the direction <span class="math inline">d</span>. Each direction is U (up), D (down), L (left), or R (right).</p>
<h1 id="output">Output</h1>
<p>Print the total distance the robot moves.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 10^5</span></li>
<li><span class="math inline">1 <= x <= 10^6</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5
U 2
R 3
D 1
L 5
U 2
</pre>
<p>Output:</p>
<pre>9
</pre></div></div>

## CSES - Programmers and Artists
<div class="md"><div class="md"><p>A company wants to hire <span class="math inline">a</span> programmers and <span class="math inline">b</span> artists.</p>
<p>There are a total of <span class="math inline">n</span> applicants, and each applicant can become either a programmer or an artist. You know each applicant's programming and artistic skills.</p>
<p>Your task is to select the new employees so that the sum of their skills is maximum.</p>
<h1 id="input">Input</h1>
<p>The first input line has three integers <span class="math inline">a</span>, <span class="math inline">b</span> and <span class="math inline">n</span>: the required number of programmers and artists, and the total number of applicants.</p>
<p>After this, there are <span class="math inline">n</span> lines that describe the applicants. Each line has two integers <span class="math inline">x</span> and <span class="math inline">y</span>: the applicant's programming and artistic skills.</p>
<h1 id="output">Output</h1>
<p>Print one integer: the maximum sum of skills.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 2 . 10^5</span></li>
<li><span class="math inline">0 <= a,b <= n</span></li>
<li><span class="math inline">a+b <= n</span></li>
<li><span class="math inline">1 <= x,y <= 10^9</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>2 1 4
3 7
9 8
1 5
4 2
</pre>
<p>Output:</p>
<pre>20
</pre>
<p>Explanation: An optimal solution is to hire two programmers with skills <span class="math inline">9</span> and <span class="math inline">4</span> and one artist with skill <span class="math inline">7</span>. The sum of the skills is <span class="math inline">9+4+7=20</span>.</p>
</div></div>

## CSES - Course Schedule II
<div class="md"><div class="md"><p>You want to complete <span class="math inline">n</span> courses that have requirements of the form "course <span class="math inline">a</span> has to be completed before course <span class="math inline">b</span>".</p>
<p>You want to complete course <span class="math inline">1</span> as soon as possible. If there are several ways to do this, you want then to complete course <span class="math inline">2</span> as soon as possible, and so on.</p>
<p>Your task is to determine the order in which you complete the courses.</p>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">n</span> and <span class="math inline">m</span>: the number of courses and requirements. The courses are numbered <span class="math inline">1,2,\dots,n</span>.</p>
<p>Then, there are <span class="math inline">m</span> lines describing the requirements. Each line has two integers <span class="math inline">a</span> and <span class="math inline">b</span>: course <span class="math inline">a</span> has to be completed before course <span class="math inline">b</span>.</p>
<p>You can assume that there is at least one valid schedule.</p>
<h1 id="output">Output</h1>
<p>Print one line having <span class="math inline">n</span> integers: the order in which you complete the courses.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 10^5</span></li>
<li><span class="math inline">1 <= m <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= a,b <= n</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>4 2
2 1
2 3
</pre>
<p>Output:</p>
<pre>2 1 3 4
</pre></div></div>

## CSES - Removing Digits II
<div class="md"><div class="md"><p>You are given an integer <span class="math inline">n</span>. On each step, you may subtract from it any one-digit number that appears in it.</p>
<p>How many steps are required to make the number equal to <span class="math inline">0</span>?</p>
<h1 id="input">Input</h1>
<p>The only input line has an integer <span class="math inline">n</span>.</p>
<h1 id="output">Output</h1>
<p>Print one integer: the minimum number of steps.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 10^{18}</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>27
</pre>
<p>Output:</p>
<pre>5
</pre>
<p>Explanation: An optimal solution is <span class="math inline">27 -> 20 -> 18 -> 10 -> 9 -> 0</span>.</p>
</div></div>

## CSES - Coin Arrangement
<div class="md"><div class="md"><p>There is a <span class="math inline">2 x n</span> grid whose each cell contains some number of coins. The total number of coins is <span class="math inline">2n</span>.</p>
<p>Your task is to arrange the coins so that each cell contains exactly one coin. On each move you can choose any coin and move it one step left, right, up or down.</p>
<p>What is the minimum number of moves if you act optimally?</p>
<h1 id="input">Input</h1>
<p>The first input line has an integer <span class="math inline">n</span>: the width of the grid.</p>
<p>After this, there are two lines that describe the grid. Each line has <span class="math inline">n</span> integers: the number of coins in each cell.</p>
<h1 id="output">Output</h1>
<p>Print one integer: the minimum number of moves.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 10^5</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>4
0 1 0 1
2 0 1 3
</pre>
<p>Output:</p>
<pre>5
</pre></div></div>

## CSES - Counting Bishops
<div class="md"><div class="md"><p>Your task is to count the number of ways <span class="math inline">k</span> bishops can be placed on an <span class="math inline">n x n</span> chessboard so that no two bishops attack each other.</p>
<p>Two bishops attack each other if they are on the same diagonal.</p>
<h1 id="input">Input</h1>
<p>The only input line has two integers <span class="math inline">n</span> and <span class="math inline">k</span>: the board size and the number of bishops.</p>
<h1 id="output">Output</h1>
<p>Print one integer: the number of ways modulo <span class="math inline">10^9+7</span>.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 500</span></li>
<li><span class="math inline">1 <= k <= n^2</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5 4
</pre>
<p>Output:</p>
<pre>2728
</pre></div></div>

## CSES - Grid Puzzle I
<div class="md"><div class="md"><p>There is an <span class="math inline">n x n</span> grid, and your task is to choose from each row and column some number of squares. How can you do that?</p>
<h1 id="input">Input</h1>
<p>The first input line has an integer <span class="math inline">n</span>: the size of the grid. The rows and columns are numbered <span class="math inline">1,2,\dots,n</span>.</p>
<p>The next line has <span class="math inline">n</span> integers <span class="math inline">a_1,a_2,...,a_n</span>: You must choose exactly <span class="math inline">a_i</span> squares from the <span class="math inline">i</span>th row.</p>
<p>The las line has <span class="math inline">n</span> integers <span class="math inline">b_1,b_2,...,b_n</span>: You must choose exactly <span class="math inline">b_j</span> squares from the <span class="math inline">j</span>th column.</p>
<h1 id="output">Output</h1>
<p>Print <span class="math inline">n</span> lines describing which squares you choose (<code>X</code> means that you choose a square, <code>.</code> means that you don't choose it). You can print any valid solution.</p>
<p>If it is not possible to satisfy the conditions print only <span class="math inline">-1</span>.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 50</span></li>
<li><span class="math inline">0 <= a_i <= n</span></li>
<li><span class="math inline">0 <= b_j <= n</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5
0 1 3 2 0
1 2 2 0 1
</pre>
<p>Output:</p>
<pre>.....
..X..
.XX.X
XX...
.....
</pre></div></div>

## CSES - Grid Puzzle II
<div class="md"><div class="md"><p>There is an <span class="math inline">n x n</span> grid whose each square has some number of coins in it.</p>
<p>You know for each row and column how many squares you must choose from that row or column. You get all coins from every square you choose. What is the maximum number of coins you can collect and how could you choose the squares so that the given conditions are satisfied?</p>
<h1 id="input">Input</h1>
<p>The first input line has an integer <span class="math inline">n</span>: the size of the grid. The rows and columns are numbered <span class="math inline">1,2,\dots,n</span>.</p>
<p>The next line has <span class="math inline">n</span> integers <span class="math inline">a_1,a_2,...,a_n</span>: You must choose exactly <span class="math inline">a_i</span> squares from the <span class="math inline">i</span>th row.</p>
<p>The next line has <span class="math inline">n</span> integers <span class="math inline">b_1,b_2,...,b_n</span>: You must choose exactly <span class="math inline">b_j</span> squares from the <span class="math inline">j</span>th column.</p>
<p>Finally, there are <span class="math inline">n</span> lines describing the grid. You can assume that the sums of <span class="math inline">a_1,a_2,...,a_n</span> and <span class="math inline">b_1,b_2,...,b_n</span> are equal.</p>
<h1 id="output">Output</h1>
<p>First print an integer <span class="math inline">k</span>: the maximum number of coins you can collect. After this print <span class="math inline">n</span> lines describing which squares you choose (<code>X</code> means that you choose a square, <code>.</code> means that you don't choose it).</p>
<p>If it is not possible to satisfy the conditions print only <span class="math inline">-1</span>.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 50</span></li>
<li><span class="math inline">0 <= a_i <= n</span></li>
<li><span class="math inline">0 <= b_j <= n</span></li>
<li><span class="math inline">0 <= c_{ij} <= 1000</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5
0 1 3 2 0
1 2 2 0 1
2 5 1 5 1
0 2 5 1 2
3 8 9 3 5
1 4 3 7 3
0 3 6 2 8
</pre>
<p>Output:</p>
<pre>32
.....
..X..
.XX.X
XX...
.....
</pre></div></div>

## CSES - Empty String
<div class="md"><div class="md"><p>You are given a string consisting of <span class="math inline">n</span> characters between a and z.</p>
<p>On each turn, you may remove any two adjacent characters that are equal. Your goal is to construct an empty string by removing all the characters.</p>
<p>In how many ways can you do this?</p>
<h1 id="input">Input</h1>
<p>The only input line has a string of length <span class="math inline">n</span>.</p>
<h1 id="output">Output</h1>
<p>Print one integer: the number of ways modulo <span class="math inline">10^9+7</span>.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 500</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>aabccb
</pre>
<p>Output:</p>
<pre>3
</pre></div></div>

## CSES - Grid Paths
<div class="md"><div class="md"><p>Consider an <span class="math inline">n x n</span> grid whose top-left square is <span class="math inline">(1,1)</span> and bottom-right square is <span class="math inline">(n,n)</span>.</p>
<p>Your task is to move from the top-left square to the bottom-right square. On each step you may move one square right or down. In addition, there are <span class="math inline">m</span> traps in the grid. You cannot move to a square with a trap.</p>
<p>What is the total number of possible paths?</p>
<h1 id="input">Input</h1>
<p>The first input line contains two integers <span class="math inline">n</span> and <span class="math inline">m</span>: the size of the grid and the number of traps.</p>
<p>After this, there are <span class="math inline">m</span> lines describing the traps. Each such line contains two integers <span class="math inline">y</span> and <span class="math inline">x</span>: the location of a trap.</p>
<p>You can assume that there are no traps in the top-left and bottom-right square.</p>
<h1 id="output">Output</h1>
<p>Print the number of paths modulo <span class="math inline">10^9+7</span>.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 10^6</span></li>
<li><span class="math inline">1 <= m <= 1000</span></li>
<li><span class="math inline">1 <= y,x <= n</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>3 1
2 2
</pre>
<p>Output:</p>
<pre>2
</pre></div></div>

## CSES - Bit Substrings
<div class="md"><div class="md"><p>You are given a bit string of length <span class="math inline">n</span>. Your task is to calculate for each <span class="math inline">k</span> between <span class="math inline">0  ... n</span> the number of non-empty substrings that contain exactly <span class="math inline">k</span> ones.</p>
<p>For example, if the string is 101, there are:</p>
<ul>
<li>1 substring that contains 0 ones: 0</li>
<li>4 substrings that contain 1 one: 01, 1, 1, 10</li>
<li>1 substring that contains 2 ones: 101</li>
<li>0 substrings that contain 3 ones</li>
</ul>
<h1 id="input">Input</h1>
<p>The only input line contains a binary string of length <span class="math inline">n</span>.</p>
<h1 id="output">Output</h1>
<p>Print <span class="math inline">n+1</span> values as specified above.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 2 . 10^5</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>101
</pre>
<p>Output:</p>
<pre>1 4 1 0 
</pre></div></div>

## CSES - Reversal Sorting
<div class="md"><div class="md"><p>You have an array that contains a permutation of integers <span class="math inline">1,2,\dots,n</span>. Your task is to sort the array in increasing order by reversing subarrays. You can construct any solution that has at most <span class="math inline">n</span> reversals.</p>
<h1 id="input">Input</h1>
<p>The first input line has an integer <span class="math inline">n</span>: the size of the array. The array elements are numbered <span class="math inline">1,2,\dots,n</span>.</p>
<p>The next line has <span class="math inline">n</span> integers <span class="math inline">x_1,x_2,\dots,x_n</span>: the contents of the array.</p>
<h1 id="output">Output</h1>
<p>First print an integer <span class="math inline">k</span>: the number of reversals.</p>
<p>After that, print <span class="math inline">k</span> lines that describe the reversals. Each line has two integers <span class="math inline">a</span> and <span class="math inline">b</span>: you reverse a subarray from position <span class="math inline">a</span> to position <span class="math inline">b</span>.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 2 . 10^5</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>4
2 3 1 4
</pre>
<p>Output:</p>
<pre>2
1 3
2 3
</pre></div></div>

## CSES - Counting Reorders
<div class="md"><div class="md"><p>Calculate the number of ways you can reorder the characters of a string so that no two adjacent characters are the same.</p>
<p>For example, the answer for <code>aabc</code> is <span class="math inline">6</span>, because the possible orders are <code>abac</code>, <code>abca</code>, <code>acab</code>, <code>acba</code>, <code>baca</code>, and <code>caba</code>.</p>
<h1 id="input">Input</h1>
<p>The only input line has a string that consists of <span class="math inline">n</span> characters between <code>a</code>–<code>z</code>.</p>
<h1 id="output">Output</h1>
<p>Print an integer: the answer modulo <span class="math inline">10^9+7</span>.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 5000</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>aabc
</pre>
<p>Output:</p>
<pre>6
</pre></div></div>

## CSES - Book Shop II
<div class="md"><div class="md"><p>You are in a book shop which sells <span class="math inline">n</span> different books. You know the price, the number of pages and the number of copies of each book.</p>
<p>You have decided that the total price of your purchases will be at most <span class="math inline">x</span>. What is the maximum number of pages you can buy? You can buy several copies of the same book.</p>
<h1 id="input">Input</h1>
<p>The first input line contains two integers <span class="math inline">n</span> and <span class="math inline">x</span>: the number of book and the maximum total price.</p>
<p>The next line contains <span class="math inline">n</span> integers <span class="math inline">h_1,h_2,...,h_n</span>: the price of each book.</p>
<p>The next line contains <span class="math inline">n</span> integers <span class="math inline">s_1,s_2,...,s_n</span>: the number of pages of each book.</p>
<p>The last line contains <span class="math inline">n</span> integers <span class="math inline">k_1,k_2,...,k_n</span>: the number of copies of each book.</p>
<h1 id="output">Output</h1>
<p>Print one integer: the maximum number of pages.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 100</span></li>
<li><span class="math inline">1 <= x <= 10^5</span></li>
<li><span class="math inline">1 <= h_i, s_i, k_i <= 1000</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>3 10
2 6 3
8 5 4
3 5 2
</pre>
<p>Output:</p>
<pre>28
</pre>
<p>Explanation: You can buy three copies of book 1 and one copy of book 3. The price is <span class="math inline">3 . 2 + 3 = 9</span> and the number of pages is <span class="math inline">3 . 8 + 4 = 28</span>.</p>
</div></div>

## CSES - Network Breakdown
<div class="md"><div class="md"><p>Syrjälä's network has <span class="math inline">n</span> computers and <span class="math inline">m</span> connections between them. The network consists of components of computers that can send messages to each other.</p>
<p>Nobody in Syrjälä understands how the network works. For this reason, if a connection breaks down, nobody will repair it. In this situation a component may be divided into two components.</p>
<p>Your task is to calculate the number of components after each connection breakdown.</p>
<h1 id="input">Input</h1>
<p>The first input line has three integers <span class="math inline">n</span>, <span class="math inline">m</span> and <span class="math inline">k</span>: the number of computers, connections and breakdowns. The computers are numbered <span class="math inline">1,2,\dots,n</span>.</p>
<p>Then, there are <span class="math inline">m</span> lines describing the connections. Each line has two integers <span class="math inline">a</span> and <span class="math inline">b</span>: there is a connection between computers <span class="math inline">a</span> and <span class="math inline">b</span>. Each connection is between two different computers, and there is at most one connection between two computers.</p>
<p>Finally, there are <span class="math inline">k</span> lines describing the breakdowns. Each line has two integers <span class="math inline">a</span> and <span class="math inline">b</span>: the connection between computers <span class="math inline">a</span> and <span class="math inline">b</span> breaks down.</p>
<h1 id="output">Output</h1>
<p>After each breakdown, print the number of components.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 10^5</span></li>
<li><span class="math inline">1 <= m <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= k <= m</span></li>
<li><span class="math inline">1 <= a,b <= n</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5 5 3
1 2
1 3
2 3
3 4
4 5
3 4
2 3
4 5
</pre>
<p>Output:</p>
<pre>2 2 3
</pre></div></div>

## CSES - Visiting Cities
<div class="md"><div class="md"><p>You want to travel from Syrjälä to Lehmälä by plane using a minimum-price route. Which cities will you certainly visit?</p>
<h1 id="input">Input</h1>
<p>The first input line contains two integers <span class="math inline">n</span> and <span class="math inline">m</span>: the number of cities and the number of flights. The cities are numbered <span class="math inline">1,2,...,n</span>. City 1 is Syrjälä, and city <span class="math inline">n</span> is Lehmälä.</p>
<p>After this, there are <span class="math inline">m</span> lines describing the flights. Each line has three integers <span class="math inline">a</span>, <span class="math inline">b</span>, and <span class="math inline">c</span>: there is a flight from city <span class="math inline">a</span> to city <span class="math inline">b</span> with price <span class="math inline">c</span>. All flights are one-way flights.</p>
<p>You may assume that there is a route from Syrjälä to Lehmälä.</p>
<h1 id="output">Output</h1>
<p>First print an integer <span class="math inline">k</span>: the number of cities that are certainly in the route. After this, print the <span class="math inline">k</span> cities sorted in increasing order.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 10^5</span></li>
<li><span class="math inline">1 <= m <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= a,b <= n</span></li>
<li><span class="math inline">1 <= c <= 10^9</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5 6
1 2 3
1 3 4
2 3 1
2 4 5
3 4 1
4 5 8
</pre>
<p>Output:</p>
<pre>4
1 3 4 5
</pre></div></div>

## CSES - Missing Coin Sum Queries
<div class="md"><div class="md"><p>You have <span class="math inline">n</span> coins with positive integer values. The coins are numbered <span class="math inline">1,2,\dots,n</span>.</p>
<p>Your task is to process <span class="math inline">q</span> queries of the form: "if you can use coins <span class="math inline">a \dots b</span>, what is the smallest sum you cannot produce?"</p>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">n</span> and <span class="math inline">q</span>: the number of coins and queries.</p>
<p>The second line has <span class="math inline">n</span> integers <span class="math inline">x_1,x_2,\dots,x_n</span>: the value of each coin.</p>
<p>Finally, there are <span class="math inline">q</span> lines that describe the queries. Each line has two values <span class="math inline">a</span> and <span class="math inline">b</span>: you can use coins <span class="math inline">a \dots b</span>.</p>
<h1 id="output">Output</h1>
<p>Print the answer for each query.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n, q <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= x_i <= 10^9</span></li>
<li><span class="math inline">1 <= a <= b <= n</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5 3
2 9 1 2 7
2 4
4 4
1 5
</pre>
<p>Output:</p>
<pre>4
1
6
</pre>
<p>Explanation: First you can use coins <span class="math inline">[9,1,2]</span>, then coins <span class="math inline">[2]</span> and finally coins <span class="math inline">[2,9,1,2,7]</span>.</p>
</div></div>

## CSES - Number Grid
<div class="md"><div class="md"><p>Consider a two-dimensional grid whose rows and columns are <span class="math inline">1</span>-indexed. Each square contains the smallest nonnegative integer that does not appear to the left on the same row or above on the same column.</p>
<p>Your task is to calculate the value at square <span class="math inline">(y,x)</span>.</p>
<h1 id="input">Input</h1>
<p>The only input line contains two integers <span class="math inline">y</span> and <span class="math inline">x</span>.</p>
<h1 id="output">Output</h1>
<p>Print one integer: the value at square <span class="math inline">(y,x)</span>.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= y,x <= 10^9</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>3 5
</pre>
<p>Output:</p>
<pre>6
</pre></div></div>

## CSES - Maximum Building II
<div class="md"><div class="md"><p>You are given a map of a forest where some squares are empty and some squares have trees.</p>
<p>You want to place a rectangular building in the forest so that no trees need to be cut down. For each building size, your task is to calculate the number of ways you can do this.</p>
<h1 id="input">Input</h1>
<p>The first input line contains integers <span class="math inline">n</span> and <span class="math inline">m</span>: the size of the forest.</p>
<p>After this, the forest is described. Each square is empty (<code>.</code>) or has trees (<code>*</code>).</p>
<h1 id="output">Output</h1>
<p>Print <span class="math inline">n</span> lines each containing <span class="math inline">m</span> integers.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n,m <= 1000</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>4 7
...*.*.
.*.....
.......
......*
</pre>
<p>Output:</p>
<pre>24 17 13 9 6 3 1 
16 9 7 5 3 1 0 
9 3 2 1 0 0 0 
3 0 0 0 0 0 0
</pre>
<p>Explanation: For example, there are <span class="math inline">5</span> possible places for a building of size <span class="math inline">2 x 4</span>.</p>
</div></div>

## CSES - Filling Trominos
<div class="md"><div class="md"><p>Your task is to fill an <span class="math inline">n x m</span> grid using L-trominos (three squares that have an L-shape). For example, here is one way to fill a <span class="math inline">4 x 6</span> grid:
<center><img alt="" class="invertible" src="/file/da3ce928fcf66fd793d582a1a5ad7f7f9cc37e68aa2aadacee90f99bc4271692"/></center></p>
<h1 id="input">Input</h1>
<p>The first input line has an integer <span class="math inline">t</span>: the number of tests.</p>
<p>After that, there are <span class="math inline">t</span> lines that describe the tests. Each line has two integers <span class="math inline">n</span> and <span class="math inline">m</span>.</p>
<h1 id="output">Output</h1>
<p>For each test, print YES if there is a solution, and NO otherwise.</p>
<p>If there is a solution, also print <span class="math inline">n</span> lines that each contain <span class="math inline">m</span> letters between A–Z. Adjacent squares must have the same letter exactly when they belong to the same tromino. You can print any valid solution.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= t <= 100</span></li>
<li><span class="math inline">1 <= n,m <= 100</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>2
4 6
4 7
</pre>
<p>Output:</p>
<pre>YES
AADDBB
ACCDEB
BCAEEC
BBAACC
NO
</pre></div></div>

## CSES - Stick Divisions
<div class="md"><div class="md"><p>You have a stick of length <span class="math inline">x</span> and you want to divide it into <span class="math inline">n</span> sticks, with given lengths, whose total length is <span class="math inline">x</span>.</p>
<p>On each move you can take any stick and divide it into two sticks. The cost of such an operation is the length of the original stick.</p>
<p>What is the minimum cost needed to create the sticks?</p>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">x</span> and <span class="math inline">n</span>: the length of the stick and the number of sticks in the division.</p>
<p>The second line has <span class="math inline">n</span> integers <span class="math inline">d_1,d_2,...,d_n</span>: the length of each stick in the division.</p>
<h1 id="output">Output</h1>
<p>Print one integer: the minimum cost of the division.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= x <= 10^9</span></li>
<li><span class="math inline">1 <= n <= 2 . 10^5</span></li>
<li><span class="math inline">\sum d_i = x</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>8 3
2 3 3
</pre>
<p>Output:</p>
<pre>13
</pre>
<p>Explanation: You first divide the stick of length <span class="math inline">8</span> into sticks of length <span class="math inline">3</span> and <span class="math inline">5</span> (cost <span class="math inline">8</span>). After this, you divide the stick of length <span class="math inline">5</span> into sticks of length <span class="math inline">2</span> and <span class="math inline">3</span> (cost <span class="math inline">5</span>). The total cost is <span class="math inline">8+5=13</span>.</p>
</div></div>

## CSES - Coding Company
<div class="md"><div class="md"><p>Your company has <span class="math inline">n</span> coders, and each of them has a skill level between <span class="math inline">0</span> and <span class="math inline">100</span>. Your task is to divide the coders into teams that work together.</p>
<p>Based on your experience, you know that teams work well when the skill levels of the coders are about the same. For this reason, the penalty for creating a team is the skill level difference between the best and the worst coder.</p>
<p>In how many ways can you divide the coders into teams such that the sum of the penalties is at most <span class="math inline">x</span>?</p>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">n</span> and <span class="math inline">x</span>: the number of coders and the maximum allowed penalty sum.</p>
<p>The next line has <span class="math inline">n</span> integers <span class="math inline">t_1,t_2,\dots,t_n</span>: the skill level of each coder.</p>
<h1 id="output">Output</h1>
<p>Print one integer: the number of valid divisions modulo <span class="math inline">10^9+7</span>.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 100</span></li>
<li><span class="math inline">0 <= x <= 5000</span></li>
<li><span class="math inline">0 <= t_i <= 100</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>3 2
2 5 3
</pre>
<p>Output:</p>
<pre>3
</pre></div></div>

## CSES - Flight Route Requests
<div class="md"><div class="md"><p>There are <span class="math inline">n</span> cities with airports but no flight connections. You are given <span class="math inline">m</span> requests which routes should be possible to travel.</p>
<p>Your task is to determine the minimum number of one-way flight connections which makes it possible to fulfil all requests.</p>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">n</span> and <span class="math inline">m</span>: the number of cities and requests. The cities are numbered <span class="math inline">1,2,\dots,n</span>.</p>
<p>After this, there are <span class="math inline">m</span> lines describing the requests. Each line has two integers <span class="math inline">a</span> and <span class="math inline">b</span>: there has to be a route from city <span class="math inline">a</span> to city <span class="math inline">b</span>. Each request is unique.</p>
<h1 id="output">Output</h1>
<p>Print one integer: the minimum number of flight connections.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 10^5</span></li>
<li><span class="math inline">1 <= m <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= a, b <= n</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>4 5
1 2
2 3
2 4
3 1
3 4
</pre>
<p>Output:</p>
<pre>4
</pre>
<p>Explanation: You can create the connections <span class="math inline">1 -> 2</span>, <span class="math inline">2 -> 3</span>, <span class="math inline">2 -> 4</span> and <span class="math inline">3 -> 1</span>. Then you can also fly from city <span class="math inline">3</span> to city <span class="math inline">4</span> using the route <span class="math inline">3 -> 1 -> 2 -> 4</span>.</p>
</div></div>

## CSES - Two Stacks Sorting
<div class="md"><div class="md"><p>You are given an input list that consists of <span class="math inline">n</span> numbers. Each integer between <span class="math inline">1</span> and <span class="math inline">n</span> appears exactly once in the list.</p>
<p>Your task is to create a sorted output list using two stacks. On each move you can do one of the following:</p>
<ul>
<li>Move the first number from the input list to a stack</li>
<li>Move a number from a stack to the end of the output list</li>
</ul>
<h1 id="input">Input</h1>
<p>The first input line has an integer <span class="math inline">n</span>.</p>
<p>The second line has <span class="math inline">n</span> integers: the contents of the input list.</p>
<h1 id="output">Output</h1>
<p>Print <span class="math inline">n</span> integers: for each number the stack where it is moved (<span class="math inline">1</span> or <span class="math inline">2</span>).</p>
<p>You can print any valid solution. If there are no solutions, print "IMPOSSIBLE".</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 2 . 10^5</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5
2 3 1 5 4
</pre>
<p>Output:</p>
<pre>1 2 1 1 2
</pre></div></div>

## CSES - Tree Isomorphism II
<div class="md"><div class="md"><p>Given two (not rooted) trees, your task is to find out if they are <em>isomorphic</em>, i.e., it is possible to draw them so that they look the same.</p>
<h1 id="input">Input</h1>
<p>The first input line has an integer <span class="math inline">t</span>: the number of tests. Then, there are <span class="math inline">t</span> tests described as follows:</p>
<p>The first line has an integer <span class="math inline">n</span>: the number of nodes in both trees. The nodes are numbered <span class="math inline">1,2,\dots,n</span>.</p>
<p>Then, there are <span class="math inline">n-1</span> lines describing the edges of the first tree, and finally <span class="math inline">n-1</span> lines describing the edges of the second tree.</p>
<h1 id="output">Output</h1>
<p>For each test, print "YES", if the trees are isomorphic, and "NO" otherwise.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= t <= 1000</span></li>
<li><span class="math inline">2 <= n <= 10^5</span></li>
<li>the sum of all values of <span class="math inline">n</span> is at most <span class="math inline">10^5</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>2
3
1 2
2 3
1 2
1 3
3
1 2
2 3
1 3
3 2
</pre>
<p>Output:</p>
<pre>YES
YES
</pre></div></div>

## CSES - Forbidden Cities
<div class="md"><div class="md"><p>There are <span class="math inline">n</span> cities and <span class="math inline">m</span> roads between them. Kaaleppi is currently in city <span class="math inline">a</span> and wants to travel to city <span class="math inline">b</span>.</p>
<p>However, there is a problem: Kaaleppi has recently robbed a bank in city <span class="math inline">c</span> and can't enter the city, because the local police would catch him. Your task is to find out if there is a route from city <span class="math inline">a</span> to city <span class="math inline">b</span> that does not visit city <span class="math inline">c</span>.</p>
<p>As an additional challenge, you have to process <span class="math inline">q</span> queries where <span class="math inline">a</span>, <span class="math inline">b</span> and <span class="math inline">c</span> vary.</p>
<h1 id="input">Input</h1>
<p>The first input line has three integers <span class="math inline">n</span>, <span class="math inline">m</span> and <span class="math inline">q</span>: the number of cities, roads and queries. The cities are numbered <span class="math inline">1,2,\dots,n</span>.</p>
<p>Then, there are <span class="math inline">m</span> lines describing the roads. Each line has two integers <span class="math inline">a</span> and <span class="math inline">b</span>: there is a road between cities <span class="math inline">a</span> and <span class="math inline">b</span>. Each road is bidirectional.</p>
<p>Finally, there are <span class="math inline">q</span> lines describing the queries. Each line has three integers <span class="math inline">a</span>, <span class="math inline">b</span> and <span class="math inline">c</span>: is there a route from city <span class="math inline">a</span> to city <span class="math inline">b</span> that does not visit city <span class="math inline">c</span>?</p>
<p>You can assume that there is a route between any two cities.</p>
<h1 id="output">Output</h1>
<p>For each query, print "YES", if there is such a route, and "NO" otherwise.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 10^5</span></li>
<li><span class="math inline">1 <= m <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= q <= 10^5</span></li>
<li><span class="math inline">1 <= a,b,c <= n</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5 6 3
1 2
1 3
2 3
2 4
3 4
4 5
1 4 2
3 5 4
3 5 2
</pre>
<p>Output:</p>
<pre>YES
NO
YES
</pre></div></div>

## CSES - Area of Rectangles
<div class="md"><div class="md"><p>Given <span class="math inline">n</span> rectangles, your task is to determine the total area of their union.</p>
<h1 id="input">Input</h1>
<p>The first input line has an integer <span class="math inline">n</span>: the number of rectangles.</p>
<p>After that, there are <span class="math inline">n</span> lines describing the rectangles. Each line has four integers <span class="math inline">x_1</span>, <span class="math inline">y_1</span>, <span class="math inline">x_2</span> and <span class="math inline">y_2</span>: a rectangle begins at point <span class="math inline">(x_1,y_1)</span> and ends at point <span class="math inline">(x_2,y_2)</span>.</p>
<h1 id="output">Output</h1>
<p>Print the total area covered by the rectangles.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 10^5</span></li>
<li><span class="math inline">-10^6 <= x_1 &lt; x_2 <= 10^6</span></li>
<li><span class="math inline">-10^6 <= y_1 &lt; y_2 <= 10^6</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>3
1 3 4 5
3 1 7 4
5 3 8 6
</pre>
<p>Output:</p>
<pre>24
</pre></div></div>

## CSES - Grid Completion
<div class="md"><div class="md"><p>Your task is to create an <span class="math inline">n x n</span> grid whose each row and column has exactly one A and B. Some of the characters have already been placed. In how many ways can you complete the grid?</p>
<h1 id="input">Input</h1>
<p>The first input line has an integer <span class="math inline">n</span>: the size of the grid.</p>
<p>After this, there are <span class="math inline">n</span> lines that describe the grid. Each line has <span class="math inline">n</span> characters: <code>.</code> means an empty square, and <code>A</code> and <code>B</code> show the characters already placed.</p>
<p>You can assume that every row and column has at most one A and B.</p>
<h1 id="output">Output</h1>
<p>Print one integer: the number of ways modulo <span class="math inline">10^9+7</span>.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">2 <= n <= 500</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5
.....
..AB.
.....
B....
...A.
</pre>
<p>Output:</p>
<pre>16
</pre></div></div>

## CSES - Creating Offices
<div class="md"><div class="md"><p>There are <span class="math inline">n</span> cities and <span class="math inline">n-1</span> roads between them. There is a unique route between any two cities, and their distance is the number of roads on that route.</p>
<p>A company wants to have offices in some cities, but the distance between any two offices has to be at least <span class="math inline">d</span>. What is the maximum number of offices they can have?</p>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">n</span> and <span class="math inline">d</span>: the number of cities and the minimum distance. The cities are numbered <span class="math inline">1,2,\dots,n</span>.</p>
<p>After this, there are <span class="math inline">n-1</span> lines describing the roads. Each line has two integers <span class="math inline">a</span> and <span class="math inline">b</span>: there is a road between cities <span class="math inline">a</span> and <span class="math inline">b</span>.</p>
<h1 id="output">Output</h1>
<p>First print an integer <span class="math inline">k</span>: the maximum number of offices. After that, print the cities which will have offices. You can print any valid solution.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n,d <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= a,b <= n</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5 3
1 2
2 3
3 4
3 5
</pre>
<p>Output:</p>
<pre>2
1 4
</pre></div></div>

## CSES - Permutations II
<div class="md"><div class="md"><p>A permutation of integers <span class="math inline">1,2,...,n</span> is called <em>beautiful</em> if there are no adjacent elements whose difference is <span class="math inline">1</span>.</p>
<p>Given <span class="math inline">n</span>, your task is to count the number of beautiful permutations.</p>
<h1 id="input">Input</h1>
<p>The only input line contains an integer <span class="math inline">n</span>.</p>
<h1 id="output">Output</h1>
<p>Print the number of beautiful permutations of <span class="math inline">1,2,...,n</span> modulo <span class="math inline">10^9+7</span>.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 1000</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5
</pre>
<p>Output:</p>
<pre>14
</pre></div></div>

## CSES - Functional Graph Distribution
<div class="md"><div class="md"><p>A <em>functional graph</em> is a directed graph where each node has outdegree <span class="math inline">1</span>. For example, here is a functional graph that has <span class="math inline">9</span> nodes and <span class="math inline">2</span> components:
<center><img alt="" class="invertible" height="" src="/file/39a5e727e368197cdce7593736c5cfd1abf75b6439c0823e27c671ff10662377" width="300"/></center>
Given <span class="math inline">n</span>, your task is to calculate for each <span class="math inline">k=1 \dots n</span> the number of functional graphs that have <span class="math inline">n</span> nodes and <span class="math inline">k</span> components.</p>
<h1 id="input">Input</h1>
<p>The only input line has an integer <span class="math inline">n</span>: the number of nodes.</p>
<h1 id="output">Output</h1>
<p>Print <span class="math inline">n</span> lines: for each <span class="math inline">k=1 \dots n</span> the number of graphs modulo <span class="math inline">10^9+7</span>.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 5000</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>3
</pre>
<p>Output:</p>
<pre>17
9
1
</pre></div></div>

## CSES - New Flight Routes
<div class="md"><div class="md"><p>There are <span class="math inline">n</span> cities and <span class="math inline">m</span> flight connections between them. Your task is to add new flights so that it will be possible to travel from any city to any other city. What is the minimum number of new flights required?</p>
<h1 id="input">Input</h1>
<p>The first input line has two integers <span class="math inline">n</span> and <span class="math inline">m</span>: the number of cities and flights. The cities are numbered <span class="math inline">1,2,\dots,n</span>.</p>
<p>After this, there are <span class="math inline">m</span> lines describing the flights. Each line has two integers <span class="math inline">a</span> and <span class="math inline">b</span>: there is a flight from city <span class="math inline">a</span> to city <span class="math inline">b</span>. All flights are one-way flights.</p>
<h1 id="output">Output</h1>
<p>First print an integer <span class="math inline">k</span>: the required number of new flights. After this, print <span class="math inline">k</span> lines describing the new flights. You can print any valid solution.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= n <= 10^5</span></li>
<li><span class="math inline">1 <= m <= 2 . 10^5</span></li>
<li><span class="math inline">1 <= a,b <= n</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>4 5
1 2
2 3
3 1
1 4
3 4
</pre>
<p>Output:</p>
<pre>1
4 2
</pre></div></div>

## CSES - Grid Path Construction
<div class="md"><div class="md"><p>Given an <span class="math inline">n x m</span> grid and two squares <span class="math inline">a=(y_1,x_1)</span> and <span class="math inline">b=(y_2,x_2)</span>, create a path from <span class="math inline">a</span> to <span class="math inline">b</span> that visits each square exactly once.</p>
<p>For example, here is a path from <span class="math inline">a=(1,3)</span> to <span class="math inline">b=(3,6)</span> in a <span class="math inline">4 x 7</span> grid:
<center><img alt="" class="invertible" src="/file/944079e41a17eca6debb54a7d4da8f9124232206a1d80256432e8a2715c00055"/></center></p>
<h1 id="input">Input</h1>
<p>The first input line has an integer <span class="math inline">t</span>: the number of tests.</p>
<p>After this, there are <span class="math inline">t</span> lines that describe the tests. Each line has six integers <span class="math inline">n</span>, <span class="math inline">m</span>, <span class="math inline">y_1</span>, <span class="math inline">x_1</span>, <span class="math inline">y_2</span> and <span class="math inline">x_2</span>.</p>
<p>In all tests <span class="math inline">1 <= y_1,y_2 <= n</span> and <span class="math inline">1 <= x_1,x_2 <= m</span>. In addition, <span class="math inline">y_1 \neq y_2</span> or <span class="math inline">x_1 \neq x_2</span>.</p>
<h1 id="output">Output</h1>
<p>Print YES, if it is possible to construct a path, and NO otherwise.</p>
<p>If there is a path, also print its description which consists of characters <code>U</code> (up), <code>D</code> (down), <code>L</code> (left) and <code>R</code> (right). If there are several paths, you can print any of them.</p>
<h1 id="constraints">Constraints</h1>
<ul>
<li><span class="math inline">1 <= t <= 100</span></li>
<li><span class="math inline">1 <= n <= 50</span></li>
<li><span class="math inline">1 <= m <= 50</span></li>
</ul>
<h1 id="example">Example</h1>
<p>Input:</p>
<pre>5
1 3 1 1 1 3
1 3 1 2 1 3
2 2 1 1 2 2
2 2 1 1 2 1
4 7 1 3 3 6
</pre>
<p>Output:</p>
<pre>YES
RR
NO
NO
YES
RDL
YES
RRRRDDDLLLLLLUUURDDRURDRURD
</pre></div></div>

