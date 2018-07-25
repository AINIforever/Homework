//
//  XYPoint.m
//  GraphicObject
//
//  Created by Woo on 18/3/22.
//
//

#import <Foundation/Foundation.h>
#import "XYPoint.h"
@implementation XYPoint
@synthesize x,y;
-(void)setX:(int)xVal andY: (int)yVal{
    x = xVal;
    y = yVal;
}
@end