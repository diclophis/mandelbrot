/* jon Bardin GPL 2005 */

#include <sys/types.h>
#include <sys/stat.h>
#include <iostream>
#include <fstream>
#include <gd.h>

#define ITERATIONS 64

using namespace std; 

class Mandelbrot
{
   public:
   int n;
   int m;
   int pitch;
   int maxiter;
   int modeX;
   int modeY;
   float seadX;
   float seadY;
   int scrX;
   int scrY;
   int iter;
   int red;
   int green;
   int blue;
   int per_color;
   int inc;
   int colors[255];
   FILE *output;
   gdImagePtr im;
   gdImagePtr newest;
   gdImagePtr oldest;
   Mandelbrot(char*);
   ~Mandelbrot();
   void Draw(float, float, float, float);
   private:
   void Iterate();
};

Mandelbrot::Mandelbrot (char *name)
{ 
   modeX = 256;
   modeY = 256;

   output = fopen(name, "wb");

   im = gdImageCreate(modeX, modeY);

   for(m = 0; m < 42; m++) {
      // Line 1: red = 255 ; green = 0 -> 255 ; blue = 0
      colors[m] = gdImageColorAllocate(im, 255, m * 6, 0);
      // Line 2: red = 255 -> 0 ; green = 255 ; blue = 0
      colors[m + 42] = gdImageColorAllocate(im, (255 - m * 6), 255, 0);
      // Line 3: red = 0 ; green = 255 ; blue = 0 -> 255
      colors[m + 84] = gdImageColorAllocate(im, 0, 255, m * 6);
      // Line 4: red = 0 ; green = 255 -> 0 ; blue = 255
      colors[m + 126] = gdImageColorAllocate(im, 0, (255 - m * 6), 255);
      // Line 5: red = 0 -> 255 ; green = 0 ; blue = 255
      colors[m + 168] = gdImageColorAllocate(im, m * 6, 0, 255);
      // Line 6: red = 255 ; green = 0 ; blue = 255 -> 0
      colors[m + 210] = gdImageColorAllocate(im, 255, 0, (255 - m * 6));
   }
   for (m = 0; m < 3; m++) {
    colors[m] = gdImageColorAllocate(im, 255, 255, 255);
    colors[254-m] = gdImageColorAllocate(im, 255, 255, 255);
   }
}

Mandelbrot::~Mandelbrot ()
{
   gdImageDestroy(im);
}

void Mandelbrot::Draw (float leftX, float lowerY, float rightX, float upperY)
{
			
   float sea1;
   float sea2;
   float sea3;
   float sea4;
   float aaa;
   float bbb;
           
   int screenX;
   int screenY;

   float one_divided_by_ninety = (1.0 / 90.0);
   float right_x_minus_left_x = (rightX - leftX);
   float upper_y_minus_lower_y = (upperY - lowerY);
		   
   for (screenX=0; screenX<=modeX; screenX++) {
      aaa = ((float)screenX / modeX);
      sea1 = ((aaa * (right_x_minus_left_x)) + leftX) * one_divided_by_ninety;
               	
      for (screenY=0; screenY<=modeY; screenY++) {
         bbb = (modeY - (float)screenY) / modeY;
         sea2 = ((bbb * (upper_y_minus_lower_y)) + lowerY) * one_divided_by_ninety;

         seadX = sea1;
         seadY = sea2;
         scrX = screenX;
         scrY = screenY;           	
   
	       Iterate();
  
      }
   }

   gdImagePng(im, output);
   fclose(output);
}

void Mandelbrot::Iterate ()
{   
   float seaX = seadX;
   float seaY = seadY;
		
   float X = seaX;
   float Y = seaY;
       
   int i = ITERATIONS;
       
   float tempX;
   float tempY;
       
   float modulus = 0;
       
   do {
      tempX = X * X - Y * Y + seaX;
      tempY = 2 * X * Y + seaY;
      X = tempX;
      Y = tempY;
      modulus = X * X + Y * Y;
      i--;
   } while (modulus < 4 && i > 0);

   gdImageSetPixel (im, scrX, scrY, colors[i % 255]);
}

int main (int argc, char* argv[])
{
   Mandelbrot* fractal = new Mandelbrot(argv[5]);
   fractal->Draw(atof(argv[1]),atof(argv[2]),atof(argv[3]),atof(argv[4]));
}
