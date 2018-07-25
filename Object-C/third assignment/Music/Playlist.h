//
//  Playlist.h
//  Music
//
//  Created by Woo on 18/4/26.
//  Copyright © 2018年 Woo. All rights reserved.
//

#import <Foundation/NSArray.h>
#import "Song.h"
@interface Playlist: NSObject

@property (nonatomic, copy) NSString *name;
@property (nonatomic, strong) NSMutableArray *songCollection;
-(void) addSong:(Song *) someSong;
-(void) removeSong:(Song *) someSong;
-(void) display;
-(id)initWithName:(NSString *) theName;
@end