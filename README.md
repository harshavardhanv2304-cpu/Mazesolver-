# Maze Solver — BFS & DFS

A high-performance maze-solving application featuring a core C++ backend algorithm engine and an interactive, browser-based frontend visualizer. The project allows you to model, analyze, and animate pathfinding algorithms side by side.

The C++ implementation (`maze_solver.cpp`) provides a robust, optimized reference architecture for reading mazes from files and calculating paths, while the Vanilla JavaScript frontend mirrors this logic to run entirely in the browser with zero external dependencies or build configurations required.

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
# Mazesolver-
Features
Interactive Grid Sandbox: Click and drag directly on the canvas to draw walls, clear open paths, or dynamically reposition the Start (S) and End (E) nodes.
Dual-Engine Animation: Watch Breadth-First Search (BFS) and Depth-First Search (DFS) race step-by-step across the grid with real-time cell state tracking.
Instant Maze Generators: Generate randomized maze configurations instantly with a built-in algorithmic generator.
File Stream Integration: Seamlessly import existing text-based maze files into the visualizer UI or export custom grid creations back into standard text layout strings.
Visual Metric Breakdown: A live analytics panel displaying step counts (path length) and total visited cells for both algorithms to clearly illustrate search efficiency.
