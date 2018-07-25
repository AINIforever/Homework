//
//  Calculator.h
//  Calculator
//
//  Created by Woo on 18/3/29.
//  Copyright © 2018年 Woo. All rights reserved.
//

#import <Foundation/Foundation.h>
@interface Calculator: NSObject
{
    double accumulator;
}
// accumulator methods
-(void) setAccumulator: (double) value;
-(void) clear;
-(double) accumulator;
// arithmetic methods
-(void) add: (double) value;
-(void) subtract: (double) value;
-(void) multiply: (double) value;
-(void) divide: (double) value;
@end

