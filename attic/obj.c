
//
//  MyView.m
//  iMandelbrot
//
//  Created by Jon Bardin on 3/7/08.
//  Copyright __MyCompanyName__ 2008. All rights reserved.
//

#import "MyView.h"

#define ITERATIONS 64

@implementation MyView

- (id) initWithFrame:(CGRect)frame
{
  if((self = [super initWithFrame:frame])) {
    scale = 1.0;
  }
  
  return self;
}

- (void)scrollViewDidEndDecelerating:(UIScrollView *)scrollView
{
//NSLog(@"The scroll-view object that is decelerating the scrolling of the content view.");
//[self setNeedsDisplay];
}

- (void)scrollViewDidEndDragging:(UIScrollView *)scrollView willDecelerate:(BOOL)decelerate
{
//NSLog(@"Tells the delegate when dragging ended in the scroll view.");
//[self setNeedsDisplay];
}

- (void)scrollViewDidEndScrollingAnimation:(UIScrollView *)scrollView
{
//NSLog(@"Tells the delegate when a scrolling animation in the scroll view concludes.");
//[self setNeedsDisplay];
}

- (void)scrollViewDidScroll:(UIScrollView *)scrollView
{
//NSLog(@"Tells the delegate when the user scrolls the content view within the receiver.");
}

- (void)scrollViewWillBeginDecelerating:(UIScrollView *)scrollView
{
//NSLog(@"Tells the delegate that the scroll view is starting to decelerate the scrolling movement.");
}

- (void)scrollViewWillBeginDragging:(UIScrollView *)scrollView
{
//NSLog(@"Tells the delegate when the scroll view is about to start scrolling the content.");
}

- (UIView *)scrollViewWillBeginZooming:(UIScrollView *)scrollView
{
//NSLog(@"begining to zoom");
return self;
}

- (void)scrollViewDidEndZooming:(UIScrollView *)scrollView withView:(UIView *)view atScale:(float)new_scale
{
scale = new_scale;
//[self setNeedsDisplay];
}

- (void) drawRect:(CGRect)clip
{
  //NSLog(@"wtf3");
  //clip.
  CGPoint center = [self center];
  NSLog(@"center.x %f center.y %f", center.x, center.y);
  
    CGRect bounds = [self bounds];
  CGRect frame = [self frame];
  
  NSLog(@"bounds.width %f", bounds.size.width);
  NSLog(@"frame.width %f", frame.size.width);
  
  NSLog(@"bounds.origin.x %f", bounds.origin.x);
  NSLog(@"frame.origin.x %f", frame.origin.x);
  
  NSLog(@"clip.origin.x %f", clip.origin.x);
  NSLog(@"clip.size.width %f", clip.size.width);
  
  //CGRect center = [self center];
  
  //float one_divided_by_ninety = (1.0 / 90.0);
  //float one_divided_by_ninety = scale; //0.1;
  //NSLog(@"multiplier = %f", one_divided_by_ninety);
  //[bounds 
  //NSLog(bounds);
  
  //NSLog(@"frameRect = %@", NSStringFromRect([self bounds]));
  //NSLog(@"wtf = %@", [self bounds]);
  
    CGContextRef context = UIGraphicsGetCurrentContext();
  CGContextScaleCTM(context, 0.5, 0.5);
  
  //CGPoint context_center = [context center];
  //NSLog(@"contenxt_center.x %f", context_center.x);
    //CGImageRef image;
    
  
  //Copy the contents of the painting context to the view's context
    //image = CGBitmapContextCreateImage(_cgContext);
    //CGContextDrawImage(context, bounds, image);
    //CGImageRelease(image);
    
    ////Blend on top the contents of the stroke context
    //CGContextSetAlpha(context, kBrushAlpha);
    //CGContextDrawLayerInRect(context, bounds, _cgLayer);
  //image = 
    //BBOX=-90,0,0,90
  
  //default BBOX=-100,-100,100,100
  //zoomed in BBOX=-78.75,16.875,-73.125,22.5
  //zoomed out BBOX=-90,0,0,90
  //float leftX, float lowerY, float rightX, float upperY)
  
  modeX = clip.size.width;
  modeY = clip.size.height;
  
  /*
  float leftX = -90;
  float lowerY = -90;
  float rightX = 90;
  float upperY = 90;
  */
  
  //float dw = abs(clip.size.width - frame.size.width);
  //float dh = abs(clip.size.width - frame.size.width);
  //float change_w = 1;
  //float change_h = 1;
  //if (dw) {
  //  change_w = (dw / clip.size.width);
  //}
  //if (dh) {
  //  change_h = dh / clip.size.height;
  //}
  
  //-59.0625,40.78125,-57.65625,42.1875
  
  //float leftX = -120 + scale;// * scale;//frame.origin.x - 2;
  //float lowerY = -120 + scale;// * scale;//frame.origin.y - 2;
  //float rightX = 120 + scale;// * scale;//frame.origin.x + 2;
  //float upperY = 120 + scale;// * scale;//frame.origin.y + 2;
  //NSLog(@"dw %f change_w %f dh %f change_h %f", dw, change_w, dh, change_h);

/*
CGPoint CGContextConvertPointToUserSpace (
   CGContextRef c,
   CGPoint point
);
*/

/*
CGPoint CGContextConvertPointToDeviceSpace (
   CGContextRef c,
   CGPoint point
);
*/

  float sea1;
  float sea2;
  
  float aaa;
  float bbb;

  int screenX;
  int screenY;

  //float one_divded_by_max_factor = 1 / 4;

  //float one_divided_by_ninety = (1.0 / 90);
  //NSLog(@"scale %f one_div %f", scale, one_divided_by_ninety);

  //float right_x_minus_left_x = (rightX - leftX);
  //float upper_y_minus_lower_y = (upperY - lowerY);

  float redd;
if (scale == 1.0) {
  redd = 1;
}

if (scale > 1.0) {
  redd = (1.0 - (scale / 100.0));
}

if (scale == 100.0) {
  redd = 0;
}

//redd = (float) scale / 100.0;

      //100, 100 => 0.0
      //50, 100 => 0.5
      //25, 100 => 0.75
      //1, 100 => 1
      
NSLog(@"red %f",redd);
  //sea goes from -4 to 4 

  //for (screenX=0; screenX<=modeX; screenX++) {
  //  for (screenY=0; screenY<=modeY; screenY++) {
  //    CGContextSetRGBFillColor (context, 1, 0, 0, 1);
  //    CGContextFillRect (context, CGRectMake (screenX, screenY, 1, 1));
  //  }
  //}
  
//int iii = 0;

  for (screenX=0; screenX<=modeX; screenX++) {
    aaa = ((float) screenX / modeX);
    //sea1 = ((aaa * (right_x_minus_left_x)) + leftX) * one_divided_by_ninety;
    
    //NSLog(@"%f",sea1);
    for (screenY=0; screenY<=modeY; screenY++) {
      //iii++;

      bbb = (modeY - (float) screenY) / modeY;
      //sea2 = ((bbb * (upper_y_minus_lower_y)) + lowerY) * one_divided_by_ninety;

      seadX = sea1;
      seadY = sea2;
      scrX = screenX;
      scrY = screenY;

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
      
      //gdImageSetPixel (im, scrX, scrY, colors[i % 255]);
      //redd = ((float) i) / (float) 100.0; //(i % 255) / 255;
      //redd = ((float) (scale % 255) / 100.0);

      
      //CGContextSetRGBFillColor (context, redd, 0, 0, 1);
      //NSLog(@"scale %f", scale);
      CGContextSetRGBFillColor (context, redd, 0, 0, 1);
      
      //int im = (iii % 255);
      
      /*
      if (im < 42) {
        CGContextSetRGBFillColor (context, 255, im * 6, 0, 1);
        //colors[m] = gdImageColorAllocate(im, 255, m * 6, 0);
      } else if (im < 84) {
        // Line 2: red = 255 -> 0 ; green = 255 ; blue = 0
        //colors[m + 42] = gdImageColorAllocate(im, (255 - m * 6), 255, 0);
        CGContextSetRGBFillColor (context, ((255 - im * 6) / 255), 1, 0, 1);
      } else if (im < 126) {
        // Line 3: red = 0 ; green = 255 ; blue = 0 -> 255
        //colors[m + 84] = gdImageColorAllocate(im, 0, 255, m * 6);
        CGContextSetRGBFillColor(context, 0, 1, ((im * 6) / 255), 1);
      } else if (im < 168) { 
        // Line 4: red = 0 ; green = 255 -> 0 ; blue = 255
        //colors[m + 126] = gdImageColorAllocate(im, 0, (255 - m * 6), 255);
        CGContextSetRGBFillColor(context, 0, ((255 - im * 6) / 255), 1, 1);
      } else if (im < 210) {
        // Line 5: red = 0 -> 255 ; green = 0 ; blue = 255
        //colors[m + 168] = gdImageColorAllocate(im, m * 6, 0, 255);
        CGContextSetRGBFillColor(context, ((im * 6) / 255), 0, 1, 1);
      } else {
        // Line 6: red = 255 ; green = 0 ; blue = 255 -> 0
        //colors[m + 210] = gdImageColorAllocate(im, 255, 0, (255 - m * 6));
        CGContextSetRGBFillColor(context, 1, 0, ((255 - im * 6) / 255), 1);
      }
      */
      //CGPoint xxx = CGContextConvertPointToUserSpace(context, CGPointMake(screenX, screenY));
      //NSLog(@"%i %i %f %f", screenX, screenY, xxx.x, xxx.y);
      //CGPoint xxx_b = CGContextConvertPointToDeviceSpace(context, CGPointMake(xxx.x, xxx.y));
      //CGContextFillRect (context, CGRectMake (xxx.x, xxx.y, 1, 1));
      CGContextFillRect (context, CGRectMake (screenX, screenY, 1, 1));
    }
  }
  //performSelectorOnMainThread:
  NSLog(@"done drawing");
  //CGContextSetRGBFillColor (context, 1, 0, 0, 1);// 3
    //CGContextFillRect (context, CGRectMake (0, 0, 200, 100 ));// 4
    //CGContextSetRGBFillColor (context, 0, 0, 1, .5);// 5
    //CGContextFillRect (context, CGRectMake (0, 0, 100, 200));
}

/*
- (void) touchesBegan:(NSSet*)touches withEvent:(UIEvent*)event
{
    //UITouch*            touch = [touches anyObject];
    ////If the user double-taps, clear the whole painting
    //if([touch tapCount] >= 2) {
    //    CGContextClearRect(_cgContext, [self bounds]);
    //    [self setNeedsDisplay];
    //}
    ////Otherwise, draw a line segment in the stroke context
    //else
    //[self touchesMoved:touches withEvent:event];
  //NSLog(@"user touched the screen");
  //[self setNeedsDisplay];
}



- (void) touchesMoved:(NSSet*)touches withEvent:(UIEvent*)event
{
    UITouch*            touch = [touches anyObject];
  
    CGPoint                location = [touch locationInView];
  //[touch wi
    //                    lastLocation = [touch previousLocationInView];
    //CGContextRef        context = CGLayerGetContext(_cgLayer);
    
    //Draw a line segment in the stroke context
    //CGContextBeginPath(context);
    //CGContextMoveToPoint(context, lastLocation.x, lastLocation.y);
    //CGContextAddLineToPoint(context, location.x, location.y);
    //CGContextStrokePath(context);
    //We need to redraw the view
  //[[touch window] frame];
  
  //[self setFrame:
  
  NSLog(@"moveed");
  
  [self setCenter:location];
    //[self setNeedsDisplay];
    //[self setNeedsDisplay];
}

- (void) touchesEnded:(NSSet*)touches withEvent:(UIEvent*)event
{
    UITouch*            touch = [touches anyObject];
    CGPoint                location = [touch locationInView];
    CGRect                bounds = [self bounds];
    
    //Merge the content of the stroke context with the painting context
    //CGContextSetAlpha(_cgContext, kBrushAlpha);
    //CGContextDrawLayerInRect(_cgContext, bounds, _cgLayer);
    
    //Clear the stroke context
    //CGContextClearRect(CGLayerGetContext(_cgLayer), bounds);
    
    //We need to redraw the view
  //[self setCenter:location];
  NSLog(@"ended");

}

*/


@end

