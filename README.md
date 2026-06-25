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

