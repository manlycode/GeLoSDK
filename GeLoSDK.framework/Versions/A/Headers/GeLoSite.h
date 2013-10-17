//
//  GeLoSite.h
//  GeLoSDK
//
//  Created by Thomas Peterson on 8/30/13.
//  Copyright (c) 2013 Collective Idea. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface GeLoSite : NSObject

@property (nonatomic) NSNumber *siteId;
@property (nonatomic) NSString *name;
@property (nonatomic) NSString *logo;
@property (nonatomic) NSString *background;
@property (nonatomic) NSDate   *updatedAt;
@property (nonatomic) NSString *description;

+ (id)siteFromJson:(NSDictionary *)dictionary;
- (id)initWithJson:(NSDictionary *)dictionary;

+ (id)siteFromFile:(NSString *)path;
- (id)initWithFile:(NSString *)path;

- (BOOL)updateNeeded:(NSDate *)updatedAt;

@end
