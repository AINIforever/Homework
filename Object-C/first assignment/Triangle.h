//
//  Triangle.h
//  GraphicObject
//
//  Created by Woo on 18/3/22.
//
//

#import "GraphicObject.h"
@interface Triangle:GraphicObject{
    double lengthA;
    double lengthB;
    double lengthC;
}
-(Triangle*)initWithLengthA: (double) lengthA andLengthB: (double) lengthB andLengthC: (double) lengthC;

-(void)setLengthA:(double)lA;
-(void)setLengthB:(double)lB;
-(void)setLengthC:(double)lC;

-(double)lengthA;
-(double)lengthB;
-(double)lengthC;
-(double)perimeter;
-(double)area;
@end

