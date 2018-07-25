//
//  Triangle.m
//  GraphicObject
//
//  Created by Woo on 18/3/22.
//
//

#import <Foundation/Foundation.h>
#import "math.h"
#import "Triangle.h"
@implementation Triangle:GraphicObject
-(Triangle*)initWithLengthA: (double) lengthA andLengthB: (double) lengthB andLengthC: (double) lengthC{
    self = [super init];
    if(self){
        [self setLengthA: lengthA];
        [self setLengthB: lengthB];
        [self setLengthC: lengthC];
    }
    return self;
}
-(void)setLengthA:(double)lA{
    lengthA = lA;
}
-(void)setLengthB:(double)lB{
    lengthB = lB;
}
-(void)setLengthC:(double)lC{
    lengthC= lC;
}
-(double)lengthA{
    return lengthA;
}
-(double)lengthB{
    return lengthB;
}
-(double)lengthC{
    return lengthC;
}

-(double)perimeter{
    return lengthA+lengthB+lengthC;
}
-(double)area{
    double p = 0.5 * (lengthA+lengthB+lengthC);
    double area = sqrt(p*(p-lengthA)*(p-lengthB)*(p-lengthC));
    return area;
}
@end