package im.actor.core.viewmodel;

import com.google.j2objc.annotations.Property;

import java.util.ArrayList;

import im.actor.core.entity.Peer;
import im.actor.core.viewmodel.generics.BooleanValueModel;
import im.actor.runtime.mvvm.ValueModel;

public class CallVM {

    @Property("nonatomic, readonly")
    private final long callId;
    @Property("nonatomic, readonly")
    private final Peer peer;
    @Property("nonatomic, readonly")
    private final ValueModel<CallState> state;
    @Property("nonatomic, readonly")
    private final ValueModel<ArrayList<CallMember>> members;
    @Property("nonatomic, readonly")
    private final BooleanValueModel isMuted;

    public CallVM(long callId, Peer peer, ArrayList<CallMember> initialMembers, CallState state) {
        this.callId = callId;
        this.peer = peer;
        this.state = new ValueModel<>("calls." + callId + ".state", state);
        this.members = new ValueModel<>("calls." + callId + ".members", new ArrayList<>(initialMembers));
        this.isMuted = new BooleanValueModel("calls." + callId + ".state", false);
    }

    public Peer getPeer() {
        return peer;
    }

    public long getCallId() {
        return callId;
    }

    public BooleanValueModel getIsMuted() {
        return isMuted;
    }

    public ValueModel<CallState> getState() {
        return state;
    }

    public ValueModel<ArrayList<CallMember>> getMembers() {
        return members;
    }
}