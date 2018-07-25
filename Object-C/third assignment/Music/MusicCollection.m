//
//  MusicCollection.m
//  Music
//
//  Created by Woo on 18/4/26.
//  Copyright © 2018年 Woo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MusicCollection.h"

@implementation MusicCollection
@synthesize playlistCollection,library,name;
-(id)initWithName:(NSString *) theName{
    self = [super init];
    if(self){
        self.name = [NSString stringWithString:theName];
        playlistCollection = [NSMutableArray array];
        library = [[Playlist alloc] initWithName:@"library"];
    }
    return self;
}
-(void) addPlaylist:(Playlist *)playlist{
    if ([playlistCollection containsObject: playlist] == NO)
        [playlistCollection addObject: playlist];
    
    
    for (Song *song in playlist.songCollection) {
        
        if ([library.songCollection containsObject:song] == NO)
            
            [library addSong:song];
        
    }
}
-(void) removePlaylist:(Playlist *)playlist {
    
    if ([playlistCollection containsObject: playlist] == YES)
        [playlistCollection removeObject:playlist];
    
    for (Song *song in playlist.songCollection)
        [library removeSong:song];
}

-(void) list {
    
    for (Playlist *playlist in playlistCollection)
        [playlist display];
}

-(void) search:(NSString *)theCollection {
    
    NSMutableArray *results = [[NSMutableArray alloc] init];
    
    for (Playlist *playlist in playlistCollection) {
        if ([playlist.name rangeOfString:theCollection options:NSCaseInsensitiveSearch].location != NSNotFound)
            [results addObject:playlist];
    }
    
    for (Playlist *playlists in results) {
        
        [playlists display];
        
    }
    
    
}

@end