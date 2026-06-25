# Maze Solver — BFS & DFS

A high-performance maze-solving application featuring a core C++ backend algorithm engine and an interactive, browser-based frontend visualizer. The project allows you to model, analyze, and animate pathfinding algorithms side by side.

The C++ implementation (`maze_solver.cpp`) provides a robust, optimized reference architecture for reading mazes from text files and calculating paths, while the Vanilla JavaScript frontend mirrors this logic to run entirely in the browser with zero external dependencies or build configurations required.

---

## Tech Stack

| Layer | Technology | Purpose |
| :--- | :--- | :--- |
| **Backend Engine** | C++17 | Core file I/O streaming, grid parsing, and console path rendering |
| **Frontend UI** | Vanilla JS | Client-side grid sandbox, interactive state updates, and step-by-step canvas animations |
| **Markup** | HTML5 | Component layout, custom status bar structures, and responsive control panels |
| **Styling** | CSS3 | Dark-themed user interface utilizing modern CSS variables and flexbox |

---

## Project Structure

```text
maze-solver/
├── cpp/
│   ├── maze_solver.cpp   # C++ BFS & DFS solver (reads from file)
│   └── maze.txt          # Example maze layout input
├── frontend/
│   └── index.html        # Interactive visualizer (single file, no build step)
├── docs/
│   └── maze-format.md    # Maze file format specification
└── README.md



---

```
## Features
 * **Interactive Grid Sandbox:** Click and drag directly on the grid layout to paint walls, clear open paths, or dynamically reposition the Start (S) and End (E) nodes.
 * **Dual-Engine Animation:** Watch Breadth-First Search (BFS) and Depth-First Search (DFS) race step-by-step across the grid with real-time cell state tracking and distinct color-coded exploration heads.
 * **Instant Maze Generator:** Generate randomized maze configurations instantly with a built-in algorithmic layout generator.
 * **Text Stream Integration:** Seamlessly import existing text-based maze layouts into the visualizer UI or export custom grid creations back into standard text layout strings.
 * **Visual Metric Breakdown:** A live analytics panel displaying optimal step counts (path length) and total visited cells for both algorithms to clearly illustrate search efficiency.
## Maze File Format
Mazes are parsed and exported using plain text (.txt) files where each row represents a horizontal slice of the grid.
### Character Mapping
| Character | Matrix Meaning |
|---|---|
| # | **Wall** (Impassable block) |
| *(space)* | **Open Path** (Traversable corridor) |
| S | **Start Point** (Exactly one required) |
| E | **End Point** (Exactly one required) |
### Example Layout (maze.txt)
```text
####################
#S  #     #        #
# # # ### # ###### #
# #   #   # #      #
# ##### ### # ######
#       #   #      #
####### # ### #### #
####################E#

```
> **Note:** Rows may have different lengths during manual generation; the parser automatically pads shorter rows with walls. The outer border should be enclosed to safely prevent out-of-bounds matrix traversals.
> 
## C++ Core Solver
The backend engine handles file stream ingestion, matrix translation, coordinate parsing, and text-based console path rendering.
### Compilation
Compile using any standard C++17 compliant compiler:
```bash
g++ -std=c++17 -o maze_solver cpp/maze_solver.cpp

```
### Execution
Run the executable by passing the relative path to your targeted maze text file:
```bash
./maze_solver cpp/maze.txt

```
### Terminal Output Metrics
Upon successful execution, the console will output:
 1. The raw imported text matrix.
 2. The optimal **BFS path** (mapped visually using standard . paths).
 3. The structural **DFS path** (mapped visually using standard * paths).
 4. A complete summary report contrasting final step counts side-by-side.
## Frontend Visualizer
The frontend runs fully client-side. It does not require a local node server, build pipeline, bundler, or third-party dependencies.
### Launching the App
Simply open the entry file directly inside any standard modern web browser:
```bash
open frontend/index.html

```
Alternatively, spin up a quick Python local server to view it over a network handshake:
```bash
python3 -m http.server 8080
# Navigate to: http://localhost:8080/frontend/

```
## Algorithm Mechanics
### 1. Breadth-First Search (BFS)
 * **Underlying Structure:** First-In, First-Out (FIFO) using std::queue.
 * **Path Finding:** **Guaranteed to find the optimal shortest path.**
 * **Traversal Profile:** Explores the matrix uniformly level-by-level, expanding outward in all open directions from the start point. This exhaustive exploration typically results in a higher number of total visited cells before reaching the end node.
### 2. Depth-First Search (DFS)
 * **Underlying Structure:** Last-In, First-Out (LIFO) using an iterative std::stack approach to eliminate any risk of stack overflow on massive grids.
 * **Path Finding:** Finds **a** valid path, which is not guaranteed to be the shortest or most optimal route.
 * **Traversal Profile:** Dives deeply down a single path branch until hitting a wall dead-end before backtracking to the nearest intersection. It can often find the goal much faster than BFS if the search branch aligns with the exit, but can also result in long, winding visual paths.
```

```
