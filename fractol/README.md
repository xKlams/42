# Fract-ol ✨

**A captivating fractal exploration program developed as part of the 42 curriculum.**

This project renders beautiful and infinitely complex fractals like the Mandelbrot and Julia sets using the MiniLibX graphics library. Explore the intricate patterns through interactive zooming, panning, and color manipulation.

[![Language](https://img.shields.io/badge/Language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Norm](https://img.shields.io/badge/Norm-42%20Norm-brightgreen.svg)](https://github.com/42School/norminette)
[![Library](https://img.shields.io/badge/Library-MiniLibX-lightgrey.svg)](https://github.com/42Paris/minilibx-linux) <!-- Adjust link if needed -->

## Table of Contents

*   [Overview](#overview)
*   [Features](#features)
*   [Prerequisites](#prerequisites)
*   [Installation & Compilation](#installation--compilation)
*   [Usage](#usage)
*   [Controls](#controls)
*   [Supported Fractals](#supported-fractals)
*   [Technical Aspects](#technical-aspects)
*   [Author](#author)

## Overview

Fract-ol is designed to visualize mathematical fractal sets on your screen. It uses the escape time algorithm to determine how quickly points diverge under repeated iteration of a function, coloring them based on this behavior. The project emphasizes graphical programming concepts, event handling, and optimization within the constraints of the 42 school environment.

## Features

*   **Multiple Fractal Sets:** Renders the Mandelbrot set and customizable Julia sets. *(Add any other fractals you implemented, e.g., Burning Ship)*
*   **Interactive Zoom:** Zoom in and out using the mouse wheel for deep exploration.
*   **Panning:** Navigate the fractal space using arrow keys *(or specify if you use mouse drag)*.
*   **Iteration Control:** Increase or decrease the maximum iterations to reveal more detail or speed up rendering.
*   **Color Shifting:** Cycle through different color palettes or apply color transformations.
*   **Dynamic Julia Parameters:** (Optional) Allow changing the Julia set's constant parameters interactively or via command line.
*   **MiniLibX Integration:** Utilizes the 42 graphics library for window management, drawing, and event handling.


## Prerequisites

*   **C Compiler:** `gcc` or `clang`.
*   **Make:** Standard build automation tool.
*   **MiniLibX:** The 42 graphics library. Ensure it's properly installed and configured for your system (Linux/macOS). Installation methods vary; refer to 42 documentation or intra resources.
    *   Typically involves cloning the MiniLibX repository and potentially running configuration scripts.
    *   Requires development libraries for X11 (like `xorg-dev`, `libbsd-dev` on Debian/Ubuntu) or AppKit (macOS).
*   **X-Server / Display Environment:** Required for MiniLibX to open a window.

## Installation & Compilation

1.  **Clone the repository:**
    ```bash
    git clone https://your-repo-link/fract-ol.git
    cd fract-ol
    ```

2.  **Compile the project:**
    *(Ensure your Makefile correctly links MiniLibX. You might need to adjust paths in the Makefile depending on your MiniLibX setup.)*
    ```bash
    make
    ```
    This will create the `fractol` executable.

3.  **Available Make Rules:**
    *   `make` or `make all`: Compile the project.
    *   `make clean`: Remove object files (`.o`).
    *   `make fclean`: Remove object files and the executable (`fractol`).
    *   `make re`: Run `fclean` then `all` to force a full rebuild.

## Usage

Run the compiled executable from your terminal, specifying the fractal type.

**Basic Syntax:**

```bash
./fractol <fractal_name> [parameters]
```

**Examples:**

*   **Render Mandelbrot:**
    ```bash
    ./fractol mandelbrot
    ```

*   **Render a specific Julia set:**
    *(Julia requires two parameters: the real (c_re) and imaginary (c_im) parts of the constant 'c'. Adjust the parameter format according to your implementation.)*
    ```bash
    # Example: Render Julia set with c = -0.7 + 0.27015i
    ./fractol julia -0.7 0.27015
    ```
    *(Specify the exact parameter format you expect, e.g., space-separated, comma-separated)*

*   **(Add examples for other fractals if implemented)**
    ```bash
    # Example: Render Burning Ship
    ./fractol burningship
    ```

*   **No arguments or invalid name:**
    *(Describe what happens - does it show a usage message, default to Mandelbrot?)*
    ```bash
    ./fractol
    # Output: Usage: ./fractol <mandelbrot|julia [c_re c_im]|burningship>
    ```

## Controls

*(List the exact controls you implemented)*

| Key / Action        | Function                             |
| :------------------ | :----------------------------------- |
| `ESC`               | Exit the program                     |
| `Mouse Wheel Up`    | Zoom In (towards cursor position)    |
| `Mouse Wheel Down`  | Zoom Out (from cursor position)      |
| `↑` (Up Arrow)      | Pan Up                               |
| `↓` (Down Arrow)    | Pan Down                             |
| `←` (Left Arrow)    | Pan Left                             |
| `→` (Right Arrow)   | Pan Right                            |
| `+` / `NumPad +`    | Increase maximum iterations          |
| `-` / `NumPad -`    | Decrease maximum iterations          |
| `C`                 | Change color scheme / shift colors |
| `R`                 | Reset view to default                |
| `1`                 | Switch to Mandelbrot                 |
| `2`                 | Switch to Julia                      |
| *(Add other keys...)* | *(Describe their function...)*       |

*(Adjust the table based on your specific implementation. Specify if panning follows the mouse, etc.)*

## Supported Fractals

*   **`mandelbrot`**: The classic Mandelbrot set (Z = Z² + C, where C starts as the coordinate).
*   **`julia`**: Julia sets (Z = Z² + C, where C is a constant provided as parameters).
*   **(Optional) `burningship`**: The Burning Ship fractal (similar to Mandelbrot but uses absolute values).
*   *(Add any other fractal names your program accepts)*

## Technical Aspects

*   **Algorithm:** Implements the Escape Time Algorithm.
*   **Complex Numbers:** Utilizes basic complex number arithmetic (addition, multiplication, magnitude).
*   **Graphics:** Renders pixel by pixel using MiniLibX's image buffer functions (`mlx_pixel_put` or image manipulation functions for better performance).
*   **Event Handling:** Uses MiniLibX hooks (`mlx_hook`, `mlx_loop_hook`) to manage keyboard and mouse input, as well as window events (like closing).
*   **(Optional) Optimization:** Mention any specific optimizations like multi-threading (if used), fixed-point arithmetic (unlikely but possible), or efficient image buffer updates.

## Author

*   **Federico De Sisti** - ([xKlams](https://github.com/xKlams))

---

*This project was completed as part of the curriculum at 42 School.*
