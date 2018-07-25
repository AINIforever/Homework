//
//  Circle.m
//  GraphicObject
//
//  Created by Woo on 18/3/22.
//
//

#import <Foundation/Foundation.h>
#import "Circle.h"
double PI = 3.14;
@implementation Circle:GraphicObject
-(Circle*)initWithRadius: (double) radius{
    [self setRadius: radius];
    return self;
}
-(void)setRadius:(double)r{
    radius = r;
}
-(double)radius{
    return radius;
}
-(double)circumference{
    return 2*PI*radius;
}
-(double)area{
    return PI*radius*radius;
}
@end