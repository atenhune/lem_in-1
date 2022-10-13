# Lem-in

<img width="500" alt="Screen_Shot_2022-10-11_at_1 32 01_PM" src="https://user-images.githubusercontent.com/77926655/195675044-988c05e4-90d6-4294-a0e1-a92aa461bfa6.png">

‘Your ant colony must move from one location to another. How do you do it in the shortest time possible? The project serves as an introduction to graph traversal algorithms. The program will have to intelligently select paths and choose precise movements for the ants to traverse through a network.’

I.e. intelligent ant colony manager algorithm.

By [altikka](https://github.com/reviisori) & [atenhune](https://github.com/atenhune)

**Introduction**

The goal of the project is to find the quickest way to get **N** ants across a given maze-like network of rooms. The solution must contain the least amount of lines to get all given ants across the network. Obviously, there are some basic constraints. To be the first to arrive, ants will need to take the shortest path. Ants will also need to avoid traffic jams as well as walking all over their fellow ants.  A single room can only be occupied by a single ant at any given time. At the beginning, all the ants are in the room marked as **start** and must traverse to the room similarly marked as **end**. Doing this while keeping processing time reasonable even if there are thousands of rooms with tens of thousands of links between them.

```c
usage: ./lem-in [-hpqt] < [file]
 options:
	 -h	help
	 -p	additional path information
	 -q	quiet mode
	 -t	test mode
```

To run the program after compiling it with Makefile launch it from the root of the repository:

```bash
./lem-in < maps/augment_maps/augment_8.map
```

# **The Approach**

**Research**

After going over the subject matter for the project in great detail it was quite evident that approaches familiar to us from before might prove to be insufficient. Just the time factor alone implied that going over all the possible permutations of paths in a given network using, for example recursion, would not be nearly fast enough and that is saying it kindly. 

**The Algorithm**

We discovered that the most promising algorithm for solving the task at hand was the [Edmonds-Karp algorithm](https://en.wikipedia.org/wiki/Edmonds%E2%80%93Karp_algorithm). The original algorithm computes the maximum flow in a flow network using the [breadth-first search](https://en.wikipedia.org/wiki/Breadth-first_search). However, as such the Edmonds-Karp algorithm can’t be implemented for our particular dilemma. This is due to the differences between our problem and the problem that the Edmonds-Karp algorithm is designed to overcome. In summary, normally there exists flow capacity between nodes but in our case the nodes themselves have capacity, and the capacity in-between them is  virtually limitless.

**Program Sequence**

The program consists of three main sequences — parsing, solving and printing the solution. For printing and the intake part of the parsing we used self-implemented dynamic arrays. The validating part of the parsing was done with the help of the hash table concept. Solving is explained in detail in the next paragraph.

**Solving**

In order to find the best possible combination of paths, we implement breadth-first search to find the shortest path from start to end by following a specific set of rules:

`I` traversing inside the flow network can **only** be done **upstream**

`II` if entering a room that already is part of the flow network, the flow **must** be **backtracked** upstream for at least one node

`III` single node can only be **entered** **twice** during the same bfs run but only **once** from outside and **once** from inside of the flow network

An example illustrating the above rules:

![Lem-in gif_1](https://user-images.githubusercontent.com/77926655/195675245-ef34133f-8aa7-4559-bf64-dc07f646292b.gif)

After each successful run of the breadth-first search the resulting set of paths is collected. After which the path set is compared to  the previous one and the most optimal one is stored. This is done until there are no more possible paths left that connect the start to the end node. In the example above,  the red arrows represent one set of paths and the green arrows represent the second set.

E.g. sometimes it is better to find two longer routes instead of using the shortest one:

![lrm_g2](https://user-images.githubusercontent.com/77926655/195675450-77109f47-24d1-44d7-8c55-96f7a089df89.gif)

As can be observed from the example above,  there are times when the right solution is **not to** use the shortest route available [red], but instead the combination of routes that produce the quickest solution [green]. It all depends on:

`I` number of ants

`II` total number of paths

`III` path lengths

All the examples are simplified versions of the problems that the graph traversal algorithm must be able to solve. As the size of the flow network increases, so does the complexity of the problems portrayed in this documentation.

**Bonus part**

- Test script
    
    ```bash
    ./run.sh 100 -t
    ```
    

[VIDEO]

# **Final thoughts**

to be concluded…
