## Computer Vision Portfolio Template

*Author name: Troels Høst*
*Education: IT-Technology*

## Table of contents

* Introduction
* Problem statements
    * Use case 1
    * Use case 2
* Methodology and process
    * Use case
* Results and final evaluation
    * Use case
* Appendix

## Introduction

<p>The use of computer vision to solve many problems that has hitherto required human involvement is an exciting and developing field.
In this paper the use of computer vision is demonstrated in different use cases. One involving classifying shapes,
one in which computer vision is used to scan and rotate objects in pictures and one where computer vision is used to find faces in a picture.</p>

## Problem statement

### Use case 1

To take geometric shapes and classify them according to the classical names of geometric shapes, i.e. right triangle, triangle etc.

### Use case 2

To find faces in a video stream.

## Methodology and process

### Use case 1 - Classifying shapes

### Methodology and process

In these pictures the different shapes are to be classified by type.
![img](right%20triangle.PNG)
![img](triangle.PNG)

To preprocess the images are run through a color change, canny edge detection and finally a blur.

First the image is converted to grayscale with the builtin cvtColor function to get rid of the colors which are unnecessary in this case.
![img](/shapes/gray.PNG)
Then canny edge detection is applied to detect the shape of the geometric object.
![img](/shapes/edges.PNG)
Then a blur is applied to smooth out the shape to enure that the contour detection is not confused by the sharpness of the diagonal.
![img](/shapes/blur.PNG)
By this stage the contour is detected with the findContours() function and put into a vector: "contours".
Because of the need to distinguish between a right triangle and a triangle, i.e. a triangle where one of the angles are 90 degrees and one that hasn't,
the vertices are extracted.

Then the angles are calculated using trigonometry, first each side length is calculated from the
vertices using the norm() function and then the dot product is used to calculate the cosine of the angle between two sides of the
polygon. The dot product is calculated using the dot() function, and the cosine of the angle is then calculated using the acos() function.

Then it is checked whether any of the three angles are 90 degrees and the contours drawn onto the image and shown.

### Results and evaluation

As can be seen when running the program, the program is able to tell a right triangle from a triangle.
![img](./shapes/isrighttriangle.PNG)
![img](./shapes/notrighttriangle.PNG)
![img](/shapes/contours.PNG)

The result is somewhat disappointing the program is able to tell a right triangle from a triangle. But the attempt to make the program classify squares
into the 8 different types of squares was not successful.

### Use case 2
<br>
## Appendix
