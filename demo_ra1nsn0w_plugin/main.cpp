//
//  main.cpp
//  demo_ra1nsn0w_plugin
//
//  Created by tihmstar on 22.01.24.
//


#include <libgeneral/macros.h>

#include "DemoKPF.hpp"

using namespace tihmstar::patchfinder;


MAINFUNCTION
int main_r(int argc, const char * argv[]) {
    info("start");
    
    std::vector<patch> patches;
    DemoKPF *kpf = nullptr;
    cleanup([&]{
        safeDelete(kpf);
    });
    
    kpf = DemoKPF::make_DemoKPF(argv[1]);
    
    patches = kpf->get_demo_patch();
    
    for (auto p : patches) {
        printf(": Applying patch=0x%016llx : ",p._location);
        for (int i=0; i<p._patchSize; i++) {
            printf("%02x",((uint8_t*)p._patch)[i]);
        }
        if (p._patchSize == 4) {
            printf(" 0x%08x",*(uint32_t*)p._patch);
        } else if (p._patchSize == 2) {
            printf(" 0x%04x",*(uint16_t*)p._patch);
        }
        printf("\n");
    }
    
    
    printf("done\n");
    return 0;
}
