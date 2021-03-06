/*
 * Copyright 2019 Google
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#import "Firebase/InstanceID/FIRInstanceIDTokenManager.h"

#import "Firebase/InstanceID/FIRInstanceIDStore.h"
#import "Firebase/InstanceID/FIRInstanceIDTokenOperation.h"

@class FIRInstanceIDBackupExcludedPlist;
@class FIRInstanceIDCheckinPreferences;
@class FIRInstanceIDCheckinStore;
@class FIRInstanceIDTokenDeleteOperation;
@class FIRInstanceIDTokenFetchOperation;
@class FIRInstanceIDTokenStore;

@interface FIRInstanceIDTokenManager (Test) <FIRInstanceIDStoreDelegate>

@property(nonatomic, readonly, strong) FIRInstanceIDStore *instanceIDStore;

/**
 *  Create a InstanceID store with specific backup excluded plist and checkin store.
 *
 *  @param checkinStore The persistent store used to save checkin preferences.
 *  @param tokenStore   The persistent store used to cache InstanceID tokens.
 *
 *  @return Store to cache tokens and checkin preferences.
 */
- (instancetype)initWithCheckinStore:(FIRInstanceIDCheckinStore *)checkinStore
                          tokenStore:(FIRInstanceIDTokenStore *)tokenStore;

/**
 *  Create a fetch operation. This method can be stubbed to return a particular operation instance,
 *  which makes it easier to unit test different behaviors.
 */
- (FIRInstanceIDTokenFetchOperation *)
    createFetchOperationWithAuthorizedEntity:(NSString *)authorizedEntity
                                       scope:(NSString *)scope
                                     options:(NSDictionary<NSString *, NSString *> *)options
                                     keyPair:(FIRInstanceIDKeyPair *)keyPair;

/**
 *  Create a delete operation. This method can be stubbed to return a particular operation instance,
 *  which makes it easier to unit test different behaviors.
 */
- (FIRInstanceIDTokenDeleteOperation *)
    createDeleteOperationWithAuthorizedEntity:(NSString *)authorizedEntity
                                        scope:(NSString *)scope
                           checkinPreferences:(FIRInstanceIDCheckinPreferences *)checkinPreferences
                                      keyPair:(FIRInstanceIDKeyPair *)keyPair
                                       action:(FIRInstanceIDTokenAction)action;

@end
