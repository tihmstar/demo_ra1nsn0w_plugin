//
//  DemoKPF.hpp
//  demo_ra1nsn0w_plugin
//
//  Created by tihmstar on 22.01.24.
//

#ifndef DemoKPF_hpp
#define DemoKPF_hpp

#include <libpatchfinder/kernelpatchfinder/kernelpatchfinder64.hpp>
class DemoKPF : public tihmstar::patchfinder::kernelpatchfinder64{
    
public:
    DemoKPF(tihmstar::patchfinder::kernelpatchfinder64 &&kpf);
    
    std::vector<tihmstar::patchfinder::patch> get_demo_patch();
    
#pragma mark static
    static DemoKPF *make_DemoKPF(const char *filename);
    static DemoKPF *make_DemoKPF(const void *buffer, size_t bufSize, bool takeOwnership = false);
};

#endif /* DemoKPF_hpp */
