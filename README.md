# fdf - Visualizing “iron wire” meshing in 3D.

The aim of this project was to take a file as input, and draw a 3D visualization into a graphic window based on that file.

![fdf-3D-view](https://github.com/salahadawi/fdf/blob/master/images/42-3D.png)
<img src="https://github.com/salahadawi/fdf/blob/master/images/42-3D.png" width="400" height="150">
<img src="https://github.com/salahadawi/fdf/blob/master/images/42-3D.png" width="400" height="150">
# Features
* Full 3D rotation

* Camera movement

* Altitude controls

* Colors according to altitude

* Zoom in/out

* Idle animation

* Parallel/Isometric projection

Relevant information, such as rotation degrees and instructions, can be toggled on-screen with the 'H' key.


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

![fdf-parallel-view](https://github.com/salahadawi/fdf/blob/master/images/42-2D.png)
