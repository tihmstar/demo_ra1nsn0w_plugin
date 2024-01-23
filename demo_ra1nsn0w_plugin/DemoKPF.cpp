//
//  DemoKPF.cpp
//  demo_ra1nsn0w_plugin
//
//  Created by tihmstar on 22.01.24.
//

#include "DemoKPF.hpp"

#include <libgeneral/macros.h>

#define pushINSN(pinsn) do {arm64::insn pinsnn = pinsn; uint32_t opcode = pinsnn.opcode();patches.push_back({pinsnn,&opcode,sizeof(opcode)});} while (0)

using namespace tihmstar;
using namespace tihmstar::patchfinder;
using namespace tihmstar::libinsn;
using namespace tihmstar::libinsn::arm64;

DemoKPF::DemoKPF(tihmstar::patchfinder::kernelpatchfinder64 &&kpf)
: tihmstar::patchfinder::kernelpatchfinder64(std::move(kpf))
{
    //
}


std::vector<tihmstar::patchfinder::patch> DemoKPF::get_demo_patch(){
    std::vector<patch> patches;
    constexpr char release_arm[] = "RELEASE_ARM";
    constexpr char marijuanarm[] = "MarijuanARM";

    patchfinder64::loc_t strloc = -1;
    try {
        while ((strloc = memmem(release_arm, sizeof(release_arm)-1, strloc+1))) {
            patches.push_back({strloc,marijuanarm,sizeof(marijuanarm)-1});
        }
    } catch (...) {
        //
    }

    //everything is fine as long as we found at least one instance
    retassure(patches.size(), "Not a single instance of %s was found",release_arm);
    
    return patches;
}


#pragma mark static
DemoKPF *DemoKPF::make_DemoKPF(const char *filename){
    tihmstar::patchfinder::kernelpatchfinder64 *base = nullptr;
    cleanup([&]{
        safeDelete(base);
    });
    base = make_kernelpatchfinder64(filename);
    return new DemoKPF(std::move(*base));
}

DemoKPF *DemoKPF::make_DemoKPF(const void *buffer, size_t bufSize, bool takeOwnership){
    tihmstar::patchfinder::kernelpatchfinder64 *base = nullptr;
    cleanup([&]{
        safeDelete(base);
    });
    base = make_kernelpatchfinder64(buffer, bufSize, takeOwnership);
    return new DemoKPF(std::move(*base));
}
