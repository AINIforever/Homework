//
//  main.m
//  outfile
//
//  Created by Woo on 18/4/30.
//  Copyright © 2018年 Woo. All rights reserved.
//

#import <Foundation/Foundation.h>

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        
        
        NSProcessInfo  *process = [NSProcessInfo processInfo];
        NSArray  *args = [process arguments];
        NSString *sourceStr;
        NSFileHandle  *source, *dest;
        NSData  *buffer;
        
        
        sourceStr = args[1];
        NSLog(@"the souce file is:%@",sourceStr);
        //sourcePath = [NSHomeDirectory() stringByAppendingPathComponent: sourceStr];
        if ((source = [NSFileHandle fileHandleForReadingAtPath: sourceStr]) == nil) {
            NSLog(@"Can't open source file for reading");
            return 1;
        }
        
        dest = [NSFileHandle fileHandleWithStandardOutput];
       
        do {
            buffer = [source readDataOfLength: 128];
            [dest writeData: buffer];
        } while ([buffer length]);
        [source closeFile];
        [dest closeFile];
        
    }
    return 0;
}
