//
//  Playlist.m
//  Music
//
//  Created by Woo on 18/4/26.
//  Copyright © 2018年 Woo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Playlist.h"

@implementation Playlist
@synthesize songCollection,name;
-(id)initWithName:(NSString *) theName{
    self = [super init];
    if(self){
        self.name = theName;
        songCollection = [[NSMutableArray alloc] init];
    }
    return self;
}
-(void) addSong:(Song *) someSong{
    [songCollection addObject:someSong];
}
-(void) removeSong:(Song *) someSong{
    [songCollection removeObjectIdenticalTo:someSong];
}
-(void)display{
    NSLog(@"========%@=======",name);
    for (Song *mySong in songCollection ) {
        NSLog(@"%-15s %-20s %-32s %-32s",[mySong.title UTF8String],[mySong.artist UTF8String],[mySong.album UTF8String],[mySong.playTime UTF8String]);
    }
    NSLog(@"|===============|");
}
@end

