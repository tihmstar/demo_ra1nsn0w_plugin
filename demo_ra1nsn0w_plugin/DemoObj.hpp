//
//  DemoObj.hpp
//  demo_ra1nsn0w_plugin
//
//  Created by tihmstar on 22.01.24.
//

#ifndef DemoObj_hpp
#define DemoObj_hpp

#include <stdint.h>
#include <ra1nsn0w/ra1nsn0w_plugins.hpp>
class DemoObj : public tihmstar::ra1nsn0w::PluginObj {
    bool _doAddPatch;
public:
    DemoObj();
    virtual ~DemoObj() override;
    
    virtual bool argparse(std::string longopt, const char *optarg) override;
    virtual std::vector<tihmstar::patchfinder::patch> patcher(uint32_t component, const void *buf, size_t bufSize) override;
};

#endif /* DemoObj_hpp */
