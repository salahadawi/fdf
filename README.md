# fdf - Visualizing “iron wire” meshing in 3D.

The aim of this project was to take a file as input, and draw a 3D visualization into a graphic window based on that file.

As a bonus, this model can be rotated in 3D space.

![42-3D-view](https://github.com/salahadawi/fdf/blob/master/images/42-3D.png)
# Features

* Full 3D rotation

* Camera movement

* Altitude controls

* Colors according to altitude

* Zoom in/out

* Idle animation

* Parallel/Isometric projection

Relevant information, such as rotation degrees and instructions, can be toggled on-screen with the 'H' key.

# Input

The given input map is a 2D grid of numbers, where each number corresponds to its altitude.

For example, giving the following text as input:
```
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0 10 10  0  0 10 10  0  0  0 10 10 10 10 10  0  0  0
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
0  0 10 10 10 10 10 10  0  0  0  0 10 10 10 10  0  0  0
0  0  0 10 10 10 10 10  0  0  0 10 10  0  0  0  0  0  0
0  0  0  0  0  0 10 10  0  0  0 10 10  0  0  0  0  0  0
0  0  0  0  0  0 10 10  0  0  0 10 10 10 10 10 10  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
```

Results in this visualization:

![42-parallel-view](https://github.com/salahadawi/fdf/blob/master/images/42-2D.png)

# Images
![42-isometric-view](https://github.com/salahadawi/fdf/blob/master/images/42-ISO.png)
![Pyra-3D-view](https://github.com/salahadawi/fdf/blob/master/images/Pyra-3D.png)
![Earth-parallel-view](https://github.com/salahadawi/fdf/blob/master/images/Earth-3D.png)
