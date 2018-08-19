# imgsort
This is a pretty useless tool that sorts pixels in your images.

Syntax:
```
./imgsort input-image output-image
```
where `./imgsort` is the executable, and `input-image` is an existing image file with extension, and `output-image` is the output image file with extension.

## Dependencies
* OpenCV 3.2 (`sudo apt install libopencv-dev`)
* ~~Your hands (probably)~~

You're probably able to use a newer version though.

## Building (on Linux)
I made this thing in Eclipse, but if you want to compile it from the command line you can do this from within the project folder:
```
g++ -o "imgsort" ./src/imgsort.cpp -I/usr/include -lopencv_core -lopencv_highgui -lopencv_imgcodecs
```
If you're not gonna debug it then add `-O3` at the end for extra thicc performance.

Fun fact: it has already been built.
## Other interesting stuff that might be interesting to know about
The commented code is for if you want to sort by VSH instead of RGB. (edit the for loop if you want to sort by HSV)

If you uncomment the code don't forget to compile with extra library: `opencv_imgproc`  
Then you'd have to compile like this (if you're on command line on Linux):
```
g++ -o "imgsort" ./src/imgsort.cpp -I/usr/include -lopencv_core -lopencv_highgui -lopencv_imgcodecs -lopencv_imgproc
```
And of course, if you want that extra thicc performance, add `-O3` at the end.

Oh and sorry for the 2 functions, `cv::Vec` only accepts const values as template arguments for some reason.
