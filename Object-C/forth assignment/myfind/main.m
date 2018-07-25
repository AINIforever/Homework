//
//  main.m
//  myfind
//
//  Created by Woo on 18/4/30.
//  Copyright © 2018年 Woo. All rights reserved.
//

#import <Foundation/Foundation.h>

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        NSString  *path, *startDir, *fileToLocate;
        NSProcessInfo  *process = [NSProcessInfo processInfo];
        NSFileManager  *fm = [NSFileManager defaultManager];
        NSDirectoryEnumerator  *dirEnum;
        BOOL                    isFound = NO;
        NSArray                 *args = [process arguments];
        
        startDir = args[1];
        fileToLocate = args[2];
        
        dirEnum = [fm enumeratorAtPath: startDir];
        
        while (path = [dirEnum nextObject]) {
            
            if ([[path lastPathComponent] isEqualToString: fileToLocate]) {
                NSLog(@"File found at path:");
                NSLog(@"%@", [startDir stringByAppendingPathComponent: path]);
                isFound = YES;
            }
        }
        if(isFound == NO)
            NSLog(@"File not found");
    }
    return 0;
}
