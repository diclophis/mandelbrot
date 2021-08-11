/* jon Bardin GPL 2005 */

#include <sys/types.h>
#include <sys/stat.h>
#include <iostream>
#include <fstream>
#include <gd.h>
#include <thread>
#include <chrono>

#define BITSBITS 256

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
   long double seadX;
   long double seadY;
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
   void Draw(long double, long double, long double, long double, long double);
   private:
   void Iterate(long double);
};

Mandelbrot::Mandelbrot (char *name)
{ 
   modeX = BITSBITS;
   modeY = BITSBITS;

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

void Mandelbrot::Draw (long double z, long double leftX, long double lowerY, long double rightX, long double upperY)
{
   long double sea1;
   long double sea2;
   long double sea3;
   long double sea4;
   long double aaa;
   long double bbb;
           
   int screenX;
   int screenY;

   long double one_divided_by_ninety = (1.0 / 70.0);
   long double right_x_minus_left_x = (rightX - leftX);
   long double upper_y_minus_lower_y = (upperY - lowerY);
		   
   for (screenX=0; screenX<=modeX; screenX++) {
      aaa = ((long double)screenX / modeX);
      sea1 = ((aaa * (right_x_minus_left_x)) + leftX) * one_divided_by_ninety;
               	
      for (screenY=0; screenY<=modeY; screenY++) {
         bbb = (modeY - (long double)screenY) / modeY;
         sea2 = ((bbb * (upper_y_minus_lower_y)) + lowerY) * one_divided_by_ninety;

         seadX = sea1;
         seadY = sea2;
         scrX = screenX;
         scrY = screenY;           	
   
	       Iterate(z);
      }
   }

   gdImagePng(im, output);
   fclose(output);
}

void Mandelbrot::Iterate (long double z)
{   
   long double seaX = seadX;
   long double seaY = seadY;
		
   long double X = seaX;
   long double Y = seaY;
       
   int i = (int)z;
       
   long double tempX;
   long double tempY;
       
   long double modulus = 0;
       
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
  //std::this_thread::sleep_for(std::chrono::milliseconds(2000));

  long double z,a,b,c,d;

  z = strtold(argv[1], NULL);
  a = strtold(argv[2], NULL);
  b = strtold(argv[3], NULL);
  c = strtold(argv[4], NULL);
  d = strtold(argv[5], NULL);

  Mandelbrot* fractal = new Mandelbrot(argv[6]);
  fractal->Draw(z, a, b, c, d);
}
