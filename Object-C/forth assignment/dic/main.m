//
//  main.m
//  dictionary
//
//  Created by Woo on 18/5/3.
//  Copyright © 2018年 Woo. All rights reserved.
//

#import <Foundation/Foundation.h>

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        
        NSString *iOSPath = [[NSBundle mainBundle] pathForResource:@"list_of_us_state" ofType:@"CSV"];
        NSString *content = [NSString stringWithContentsOfFile:iOSPath encoding:NSUTF8StringEncoding error:nil];
        NSArray *baseStationInfoArr= [content componentsSeparatedByCharactersInSet:[NSCharacterSet newlineCharacterSet]];
        NSString *names = [baseStationInfoArr objectAtIndex:0];
        NSMutableArray *baseStations = [baseStationInfoArr mutableCopy];
        [baseStations removeObjectAtIndex:0];
        NSMutableArray *allPlists = [NSMutableArray array];
        //    NSString *plistPath = [[NSBundle mainBundle] pathForResource:@"baseStation" ofType:@"plist"];
        NSString *plistPath = [NSHomeDirectory() stringByAppendingPathComponent:@"test.plist"];
        
        for (int i = 0; i < baseStations.count-1; i++) {
            
            if (i % 2 == 0) {
                continue;
            }
            NSArray *allTitle = [names componentsSeparatedByString:@","];
            NSArray *allContents = [baseStations[i] componentsSeparatedByString:@","];
            NSMutableDictionary *dic = [NSMutableDictionary dictionary];
            for (int j = 0; j < allContents.count; j++) {
                [dic setObject:allContents[j] forKey:allTitle[j]];
            }
            [allPlists addObject:dic];
        }  
        [allPlists writeToFile:plistPath atomically:YES];
        
        
        //NSURL *myURL2 = [NSURL URLWithString:@"./test.plist"];
        //NSDictionary *buffer = [NSDictionary dictionaryWithContentsOfFile:@"./test.plist"];
        
    
        
        NSString *dictfilename = @"test.plist";
        
        NSArray *readingDictArray = [NSArray arrayWithContentsOfFile:dictfilename];
        
        for(NSDictionary *dict in readingDictArray)
        {
            for(NSString *key in dict)
            {
                NSLog(@"%@>%@",key,[dict objectForKey:key]);
            }
        }
        
        
        
    }
    return 0;
}
