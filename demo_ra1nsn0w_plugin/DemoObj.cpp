//
//  DemoObj.cpp
//  demo_ra1nsn0w_plugin
//
//  Created by tihmstar on 22.01.24.
//

#include "DemoObj.hpp"
#include "DemoKPF.hpp"

#include <libgeneral/macros.h>

using namespace tihmstar;

#pragma mark DemoObj
DemoObj::DemoObj()
: _doAddPatch(false)
{
    //
}

DemoObj::~DemoObj(){
    //
}

#pragma mark public
bool DemoObj::argparse(std::string longopt, const char *optarg){
    if (longopt == "demo-addpatch") {
        info("Enabling demo-addpatch !");
        _doAddPatch = true;
        return true;
    }else{
        return false;
    }
}

std::vector<patchfinder::patch> DemoObj::patcher(uint32_t component, const void *buf, size_t bufSize){
    std::vector<patchfinder::patch> ret;
    if (_doAddPatch) {
        if (component == 'rkrn') {
            DemoKPF *dkpf = nullptr;
            cleanup([&]{
                safeDelete(dkpf);
            });
            dkpf = DemoKPF::make_DemoKPF(buf, bufSize);

            {
                auto patches = dkpf->get_demo_patch();
                ret.insert(ret.end(), patches.begin(), patches.end());
            }
        }
    }
    return ret;
}
