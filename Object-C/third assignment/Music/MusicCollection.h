//
//  MusicCollection.h
//  Music
//
//  Created by Woo on 18/4/26.
//  Copyright © 2018年 Woo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Playlist.h"

@interface MusicCollection : NSObject
@property(nonatomic, copy) NSString *name;
@property(nonatomic, copy) NSMutableArray *playlistCollection;
@property(nonatomic, copy) Playlist *library;

-(id) initWithName:(NSString *)name;
-(void) addPlaylist:(Playlist *)playlist;
-(void) removePlaylist:(Playlist *)playlist;
-(void) search:(NSString *)theCollection;
-(void) list;
@end