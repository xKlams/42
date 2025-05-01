# Fractol ✨

**A captivating fractal exploration program developed as part of the 42 curriculum.**

This project renders beautiful and infinitely complex fractals like the Mandelbrot and Julia sets using the MiniLibX graphics library. Explore the intricate patterns through interactive zooming, panning, and color manipulation.

[![Language](https://img.shields.io/badge/Language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Norm](https://img.shields.io/badge/Norm-42%20Norm-brightgreen.svg)](https://github.com/42School/norminette)
[![Library](https://img.shields.io/badge/Library-MiniLibX-lightgrey.svg)](https://github.com/42Paris/minilibx-linux) 

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

Fractol is designed to visualize mathematical fractal sets on your screen. It uses the escape time algorithm to determine how quickly points diverge under repeated iteration of a function, coloring them based on this behavior. The project emphasizes graphical programming concepts, event handling, and optimization within the constraints of the 42 school environment.

## Features

*   **Multiple Fractal Sets:** Renders the Mandelbrot set, the burning ship set and customizable Julia sets.
*   **Interactive Zoom:** Zoom in and out using the mouse wheel for deep exploration.
*   **Panning:** Navigate the fractal space using arrow keys.
*   **Color Shifting:** Cycle through different color palettes or apply color transformations.
*   **Dynamic Julia Parameters:** Allow changing the Julia set's constant parameters interactively or via command line.
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
    git clone https://your-repo-link/fractol.git
    cd fractol
    ```

2.  **Compile the project:**
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

*   **Render Burning ship**
    ```bash
    # Example: Render Burning Ship
    ./fractol burningship
    ```

## Controls


| Key / Action        | Function                             |
| :------------------ | :----------------------------------- |
| `ESC`               | Exit the program                     |
| `Mouse Wheel Up`    | Zoom In (towards cursor position)    |
| `Mouse Wheel Down`  | Zoom Out (from cursor position)      |
| `↑` (Up Arrow)      | Pan Up                               |
| `↓` (Down Arrow)    | Pan Down                             |
| `←` (Left Arrow)    | Pan Left                             |
| `→` (Right Arrow)   | Pan Right                            |
| `C`                 | Change color scheme / shift colors |

## Supported Fractals

*   **`mandelbrot`**: The classic Mandelbrot set (Z = Z² + C, where C starts as the coordinate).
*   **`julia`**: Julia sets (Z = Z² + C, where C is a constant provided as parameters).
*   ** `burningship`**: The Burning Ship fractal (similar to Mandelbrot but uses absolute values).

## Technical Aspects

*   **Algorithm:** Implements the Escape Time Algorithm.
*   **Complex Numbers:** Utilizes basic complex number arithmetic (addition, multiplication, magnitude).
*   **Graphics:** using MiniLibX's image manipulation functions for efficient rendering, rather than mlx_pixel_put.
*   **Event Handling:** Uses MiniLibX hooks (`mlx_hook`, `mlx_loop_hook`) to manage keyboard and mouse input, as well as window events (like closing).

## Author

*   **Federico De Sisti** - ([xKlams](https://github.com/xKlams))

---

*This project was completed as part of the curriculum at 42 School.*
