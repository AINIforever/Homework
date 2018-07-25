//
//  Calculator.m
//  Calculator
//
//  Created by Woo on 18/3/29.
//  Copyright © 2018年 Woo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Calculator.h"
@implementation Calculator
-(void) setAccumulator: (double) value
{
    accumulator = value;
}
-(void) clear
{
    accumulator = 0;
}
-(double) accumulator
{
    return accumulator;
}
-(void) add: (double) value
{
    accumulator += value;
}
-(void) subtract: (double) value
{
    accumulator -= value;
}
-(void) multiply: (double) value
{
    accumulator *= value;
}
-(void) divide: (double) value
{
    accumulator /= value;
}
@end
