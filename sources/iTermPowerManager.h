//
//  iTermPowerManager.h
//  iTerm2SharedARC
//
//  Created by George Nachman on 2/21/18.
//

#import <Foundation/Foundation.h>

// Posted when charging status changes
extern NSString *const iTermPowerManagerStateDidChange;
extern NSString *const iTermPowerManagerMetalAllowedDidChangeNotification;

@interface iTermPowerState : NSObject
@property (nonatomic, readonly) NSString *powerStatus;
@property (nonatomic, readonly) NSNumber *percentage;
@property (nonatomic, readonly) NSNumber *timeToEmpty;
@end

@interface iTermPowerManager : NSObject

@property (nonatomic, readonly) BOOL connectedToPower;
@property (nonatomic, readonly) BOOL metalAllowed;
@property (nonatomic, readonly) NSArray<NSNumber *> *percentageSamples;
@property (nonatomic, readonly) iTermPowerState *currentState;

+ (instancetype)sharedInstance;
- (instancetype)init NS_UNAVAILABLE;
- (void)addPowerStateSubscriber:(id)subscriber block:(void (^)(iTermPowerState *))block;

@end
