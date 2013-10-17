//
//  GeLoTour.h
//  GeLoSDK
//
//  Created by Tim Bugai on 5/22/13.
//  Copyright (c) 2013 Collective Idea. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface GeLoTour : NSObject

@property (nonatomic) NSNumber  *tourId;
@property (nonatomic) NSString  *name;
@property (nonatomic) NSString  *map;
@property (nonatomic) NSDate	*updatedAt;
@property (nonatomic, readonly) NSDictionary	*beaconInfo;
@property (nonatomic) NSNumber *siteId;

+ (id)tourFromJson:(NSDictionary *)dictionary;
- (id)initWithJson:(NSDictionary *)dictionary;

+ (id)tourFromFile:(NSString *)path;
- (id)initWithFile:(NSString *)path;

- (BOOL)updateNeeded:(NSDate *)updatedAt;

- (BOOL)containsBeaconId:(NSInteger)beaconId;

- (NSInteger)mediaCount;

@end
