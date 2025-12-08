# Fract'ol

A fractal visualization program that renders beautiful mathematical fractals in real-time using the MiniLibX graphics library.

## Overview

Fract'ol is a project that explores the fascinating world of fractals through interactive visualization. The program allows users to explore three different types of fractals with dynamic zooming, panning, and customizable color schemes.

## Features

### Supported Fractals
- **Mandelbrot Set**: The iconic fractal showcasing complex mathematical beauty
- **Julia Set**: Dynamic fractals with customizable parameters
- **Tricorn (Mandelbar)**: A variant of the Mandelbrot set using complex conjugates

### Interactive Controls
- **Mouse Wheel**: Zoom in and out with precise control
- **Arrow Keys / WASD**: Pan across the fractal landscape
- **C Key**: Cycle through 5 different color schemes
- **E/Q Keys**: Adjust color shift for dynamic palette changes
- **ESC**: Exit the program

### Visual Features
- Real-time rendering with optimized algorithms
- Five distinct color schemes:
  - Classic
  - Rainbow
  - Fire
  - Ice
  - Psychedelic
- Adaptive iteration depth based on zoom level
- Smooth zooming centered on mouse position

## Requirements

- Linux operating system
- X11 development libraries
- C compiler (gcc/clang)
- Make

### Dependencies
The Makefile will automatically clone and build:
- MiniLibX (graphics library)
- libft (custom C library)

## Installation

1. Clone the repository:
```bash
git clone <repository-url>
cd fractol
```

2. Build the project:
```bash
make
```

The Makefile will automatically download and compile all necessary dependencies.

## Usage

### Basic Syntax
```bash
./fractol <fractal_type> [parameters]
```

### Examples

**Mandelbrot Set:**
```bash
./fractol mandelbrot
```

**Julia Set:**
```bash
./fractol julia -0.7 0.27015
./fractol julia -0.4 0.6
./fractol julia 0.285 0.01
```

**Tricorn:**
```bash
./fractol tricorn
```

### Julia Set Parameters
The Julia set requires two parameters: the real and imaginary components of the complex constant C.

Popular Julia set constants:
- `-0.7 0.27015` - Classic spiral pattern
- `-0.4 0.6` - Dendrite-like structure
- `0.285 0.01` - Douady's rabbit fractal
- `-0.8 0.156` - Siegel disk fractal

## Controls Reference

| Control | Action |
|---------|--------|
| Mouse Wheel Up | Zoom in |
| Mouse Wheel Down | Zoom out |
| Arrow Keys | Pan view |
| W/A/S/D | Alternative pan controls |
| C | Change color scheme |
| E | Increase color shift |
| Q | Decrease color shift |
| ESC | Exit program |

## Technical Details

### Optimization Features
- Mandelbrot set optimization using cardioid and period-2 bulb detection
- Adaptive maximum iterations based on zoom level
- Efficient pixel-by-pixel rendering
- Direct memory buffer manipulation for performance

### Color Schemes
1. **Classic**: Smooth gradient transitions
2. **Rainbow**: Full spectrum color cycling
3. **Fire**: Warm tones from red to yellow
4. **Ice**: Cool tones from blue to white
5. **Psychedelic**: High-frequency color oscillations

### Mathematical Approach
- Escape-time algorithm for fractal generation
- Complex number arithmetic for precise calculations
- Zoom-aware coordinate transformation
- Maximum escape radius of 4.0 (16.0 squared)

## Project Structure

```
fractol/
├── inc/
│   └── main.h              # Header file with structures and prototypes
├── src/
│   ├── main.c              # Entry point and initialization
│   ├── mandelbrot.c        # Mandelbrot set implementation
│   ├── julia.c             # Julia set implementation
│   ├── tricorn.c           # Tricorn implementation
│   ├── render.c            # Rendering functions
│   ├── colours.c           # Color scheme implementations
│   ├── events.c            # Event handlers
│   ├── complex_math.c      # Complex number operations
│   ├── init.c              # Initialization and setup
│   ├── atof.c              # String to float conversion
│   └── utils.c             # Utility functions
├── Makefile
└── README.md
```

## Makefile Targets

- `make` or `make all`: Build the project
- `make clean`: Remove object files
- `make fclean`: Remove object files and executable
- `make fcleanall`: Remove everything including cloned libraries
- `make re`: Rebuild the project
- `make reall`: Clean everything and rebuild

## Algorithm Complexity

The rendering performance depends on:
- **Resolution**: 800x600 pixels by default
- **Iteration depth**: Adaptive (100-300 based on zoom)
- **Zoom level**: Higher zoom requires more iterations for detail

## Educational Value

This project demonstrates:
- Complex number mathematics
- Fractal geometry and chaos theory
- Graphics programming and event handling
- Memory management and optimization
- Interactive application development

## Known Limitations

- Maximum zoom level capped at 1,000,000x to prevent floating-point precision issues
- Minimum zoom level set to 0.1x
- Window size fixed at 800x600 pixels

## Troubleshooting

**If compilation fails:**
- Ensure X11 development libraries are installed: `sudo apt-get install libx11-dev libxext-dev`
- Check that git is available for cloning dependencies

**If the window doesn't open:**
- Verify X11 is running
- Check display permissions

**For slow rendering:**
- Reduce zoom level
- Use a simpler color scheme

## Credits

Created as part of the 42 school curriculum, exploring computer graphics and mathematical visualization.

## License

This project is part of the 42 school curriculum and follows its academic policies.
