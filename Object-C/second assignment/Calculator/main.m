//
//  main.m
//  Calculator
//
//  Created by Woo on 18/3/29.
//  Copyright © 2018年 Woo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Calculator+method.h"
int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        double value = 2;
        Calculator *deskCalc = [[Calculator alloc] init];
        [deskCalc setAccumulator: value];
        NSLog (@"sin2 = %2f", [deskCalc sin]);
        NSLog (@"cos2 = %2f", [deskCalc cos]);
        NSLog (@"tan2 = %2f", [deskCalc tan]);    }
    return 0;
}
