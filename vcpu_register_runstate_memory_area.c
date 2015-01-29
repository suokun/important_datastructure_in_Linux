//include/xen/interface/vcpu.h

struct vcpu_register_runstate_memory_area {
                union {
                                GUEST_HANDLE(vcpu_runstate_info) h;
                                struct vcpu_runstate_info *v; 
                                uint64_t p;
                } addr;
};


