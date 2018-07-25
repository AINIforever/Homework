//
//  Circle.h
//  GraphicObject
//
//  Created by Woo on 18/3/22.
//
//
#import "GraphicObject.h"
@interface Circle:GraphicObject{
    double radius;
}
-(Circle*)initWithRadius: (double) radius;

-(void)setRadius:(double)radius;

-(double)radius;
-(double)circumference;
-(double)area;
@end
