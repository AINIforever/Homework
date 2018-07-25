//
//  main.m
//  Music
//
//  Created by Woo on 18/4/26.
//  Copyright © 2018年 Woo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Song.h"
#import "Playlist.h"
#import "MusicCollection.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        
        Song *song1 = [[Song alloc] init];
        Song *song2 = [[Song alloc] init];
        Song *song3 = [[Song alloc] init];
        
        [song1 setTitle:@"aaa" andArtist:@"a's artist" andAlbum:@"a's Album" andPlayTime:@"1 min"];
        [song2 setTitle:@"bbb" andArtist:@"b's artist" andAlbum:@"b's Album" andPlayTime:@"2 min"];
        [song3 setTitle:@"ccc" andArtist:@"c's artist" andAlbum:@"c's Album" andPlayTime:@"3 min"];
        
        
        
        Playlist *playlist1 = [[Playlist alloc] initWithName:@"a and b"];
        Playlist *playlist2 = [[Playlist alloc] initWithName:@"only c"];
       
        
        [playlist1 addSong:song1];
        [playlist1 addSong:song2];
        [playlist2 addSong:song3];
        
        MusicCollection *myCollection = [[MusicCollection alloc] initWithName:@"music"];
        
        [myCollection addPlaylist:playlist1];
        [myCollection addPlaylist:playlist2];
        
        
        
        [myCollection list];
        
        [myCollection search:@"a and b"];
        
        [playlist1 removeSong: song2];
        
        [myCollection removePlaylist:playlist2];
        
        [myCollection list];
        
        [myCollection.library display];
        
        
    }
    return 0;
}
