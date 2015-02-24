//
//  Generated by the J2ObjC translator.  DO NOT EDIT!
//  source: /Users/ex3ndr/Develop/actor-model/actor-ios/build/java/im/actor/model/Messenger.java
//

#ifndef _AMMessenger_H_
#define _AMMessenger_H_

@class AMAuthStateEnum;
@class AMConfiguration;
@class AMGroupTypingVM;
@class AMI18nEngine;
@class AMMVVMCollection;
@class AMPeer;
@class AMUserTypingVM;
@class DKActor;
@class DKActorRef;
@class DKEnvelope;
@class ImActorModelModulesModules;
@class JavaLangException;
@protocol AMCommand;
@protocol AMListEngine;

#include "J2ObjC_header.h"
#include "im/actor/model/droidkit/actors/debug/TraceInterface.h"

@interface AMMessenger : NSObject {
}

- (instancetype)initWithConfig:(AMConfiguration *)configuration;

- (AMAuthStateEnum *)getAuthState;

- (jboolean)isLoggedIn;

- (id<AMCommand>)requestSmsWithLong:(jlong)phone;

- (id<AMCommand>)sendCodeWithInt:(jint)code;

- (id<AMCommand>)signUpWithNSString:(NSString *)firstName
                       withNSString:(NSString *)avatarPath
                        withBoolean:(jboolean)isSilent;

- (jlong)getAuthPhone;

- (void)resetAuth;

- (jint)myUid;

- (AMI18nEngine *)getFormatter;

- (AMMVVMCollection *)getUsers;

- (AMMVVMCollection *)getGroups;

- (id<AMListEngine>)getDialogs;

- (id<AMListEngine>)getMessagesWithAMPeer:(AMPeer *)peer;

- (AMUserTypingVM *)getTyping:(jint)uid;

- (AMGroupTypingVM *)getGroupTyping:(jint)gid;

- (void)onAppVisible;

- (void)onAppHidden;

- (void)onConversationOpen:(AMPeer *)peer;

- (void)onConversationClosed:(AMPeer *)peer;

- (void)onProfileOpen:(jint)uid;

- (void)onProfileClosed:(jint)uid;

- (void)onInMessageShown:(AMPeer *)peer withRid:(jlong)rid withDate:(jlong)sortDate withEncrypted:(jboolean)isEncrypted;

- (void)onTyping:(AMPeer *)peer;

- (jlong)loadLastReadDate:(AMPeer *)peer;

- (void)saveDraft:(AMPeer *)peer withText:(NSString *)draft;

- (NSString *)loadDraft:(AMPeer *)peer;

- (void)sendMessage:(AMPeer *)peer withText:(NSString *)text;

- (id<AMCommand>)editMyNameWithNSString:(NSString *)newName;

- (id<AMCommand>)editNameWithInt:(jint)uid
                    withNSString:(NSString *)name;

@end

J2OBJC_EMPTY_STATIC_INIT(AMMessenger)

CF_EXTERN_C_BEGIN
CF_EXTERN_C_END

typedef AMMessenger ImActorModelMessenger;

J2OBJC_TYPE_LITERAL_HEADER(AMMessenger)

@interface AMMessenger_$1 : NSObject < ImActorModelDroidkitActorsDebugTraceInterface > {
}

- (void)onEnvelopeDeliveredWithDKEnvelope:(DKEnvelope *)envelope;

- (void)onEnvelopeProcessedWithDKEnvelope:(DKEnvelope *)envelope
                                 withLong:(jlong)duration;

- (void)onDropWithDKActorRef:(DKActorRef *)sender
                      withId:(id)message
                 withDKActor:(DKActor *)actor;

- (void)onDeadLetterWithDKActorRef:(DKActorRef *)receiver
                            withId:(id)message;

- (void)onActorDieWithDKActorRef:(DKActorRef *)ref
           withJavaLangException:(JavaLangException *)e;

- (instancetype)init;

@end

J2OBJC_EMPTY_STATIC_INIT(AMMessenger_$1)

CF_EXTERN_C_BEGIN
CF_EXTERN_C_END

J2OBJC_TYPE_LITERAL_HEADER(AMMessenger_$1)

#endif // _AMMessenger_H_
