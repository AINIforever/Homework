//
//  GraphicObject.m
//  GraphicObject
//
//  Created by Woo on 18/3/22.
//
//

#import <Foundation/Foundation.h>
#import "GraphicObject.h"
@implementation GraphicObject
-(GraphicObject*)initWithFillColor: (int) fillColor andFilled: (BOOL) filled andLineColor: (int) lineColor{
    self = [super init];
    if(self){
        [self setFillColor: fillColor];
        [self setFilled: filled];
        [self setLineColor: lineColor];
    }
    return self;
}
-(void)setFillColor: (int) fillC{
    fillColor = fillC;
}
-(void)setFillCed: (BOOL) fillE{
    filled = fillE;
}
-(void)setLineColor: (int) lineC{
    lineColor = lineC;
}

-(int)fillColor{
    return fillColor;
}
-(BOOL)filled{
    return filled;
}
-(int)lineColor{
    return lineColor;
}
@end
