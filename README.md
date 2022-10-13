# Lem-in

![Screen Shot 2022-10-11 at 1.32.01 PM.png](Lem-in%209d0fac3a96144b79b42e38488ab1bf1e/Screen_Shot_2022-10-11_at_1.32.01_PM.png)

“Your ant colony must move from one point to another. How do you do it in the shortest time possible? This project will get you acquainted with graph traversal algorithms: your program will have to intelligently select paths and precise movements used by the ants.” I.e. intelligent ant colony manager algorithm.

By altikka & atenhune

**Introduction**

The goal of project is to find the quickest way to get **n** ants across a given maze-like network of rooms. The solution must contain the least amount of lines to get all given ants across the network. Obviously, there are some basic constraints. To be the first to arrive, ants will need
to take the shortest path. Ants will also need to avoid traffic jams as well as walking all over their fellow ants.  One room can be occupied by a single ant at a time. At the beginning, all the ants are in the room marked as **start** and must traverse to the room similarly marked as **end**. At the same time doing it so that processing time is kept reasonable even in cases with thousands of rooms with tens of thousands of links between them.

```c
usage: ./lem-in [-hpqt] < [file]
 options:
	 	-h	help
	 	-p	additional path information
	 	-q	quiet mode
	 	-t	test mode
```

To run the program after compiling it with Makefile, launch from the root of the repository as follows:

```bash
./lem-in < maps/augment_maps/augment_8.map
```

**The Approach**

**Research**

After going over the subject matter for the project in great detail, it was quite evident that approaches familiar to us from before might be insufficient. Just the time factor implied that going over all the possible permutations of paths in a given map using for example recursion would be not nearly fast enough, and that’s saying it kindly. 

**The Algorithm**

The most promising algorithm for our problem was Edmonds-Karp algorithm. The original algorithm computes the maximum flow in a flow network using breadth-first search. However, as such the Edmonds-Karp algorithm can’t be implemented for this problem. This is due to the differences between our problem and the problem that the Edmonds-Karp algorithm tackles. Normally there is flow capacity between nodes but in our case the nodes themselves have capacity, and the capacity between them is unlimited.

**Program Sequence**

Our program consists of three main sequences — parsing, solving and printing the solution. For intake part of the parsing and for the printing we used self-implemented dynamic arrays. The validating part of the parsing was done with help of the hash table concept. Solving is explained in detail in the next paragraph.

**Solving**

In order to find the best possible combination of paths, we implement breadth-first search to find the shortest path from start to end by following a specific set of rules:

`I` traversing inside the flow network can **only** be done **upstream**

`II` if entering a room that already is a part of the flow network,

the flow **must** be **backtracked** upstream for at least one node

`III` one node can only be **entered** **twice** during the same bfs run

but only **once** from outside and **once** from inside the flow network

An example illustrating the above rules:

![Lem-in.gif_1.gif](Lem-in%209d0fac3a96144b79b42e38488ab1bf1e/Lem-in.gif_1.gif)

After each successful run of the breadth-first search the resulting set of paths is collected. After which the path set is compared to previous one and the best one is stored. This is done until there are no more possible new paths left that connect the start to the end node. In the example above, red arrows represent one path set and the green arrows represent the second path set.

E.g. sometimes it is better to find two longer routes instead of using one that is shorter:

![lrm_g2.gif](Lem-in%209d0fac3a96144b79b42e38488ab1bf1e/lrm_g2.gif)

As can be observed from the example above,  sometimes the best solution is to not use the shortest route available [red], but the combination of routes that produce the quickest solution. It all depends on:

`I` number of ants

`II` total number of paths

`III` path lengths

All the examples are simplified versions of the problems that the graph traversal algorithm must be able to solve. As the size of the flow network increases, so does the complexity of the problems portrayed in this documentation.

**Bonus part**

- Test script
    
    ```bash
    ./run 20 -t
    ```
    
[VIDEO]

**Final thoughts**
