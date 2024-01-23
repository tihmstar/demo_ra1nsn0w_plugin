//
//  demo_ra1nsn0w_plugin.cpp
//  demo_ra1nsn0w_plugin
//
//  Created by tihmstar on 22.01.24.
//

#include "DemoObj.hpp"

#include <libgeneral/macros.h>
#include <ra1nsn0w/ra1nsn0w.hpp>
#include <ra1nsn0w/ra1nsn0w_plugins.hpp>

using namespace tihmstar;
using namespace tihmstar::ra1nsn0w;

#pragma mark global vars



static const char helpscreen[] =
"Demo_Ra1nSn0w_Plugin:\n"
"      --demo-addpatch\t\t\t\tEnable demo patch\n" \
"\n"
;

static struct option longopts[] = {
    { "demo-addpatch",  no_argument,    NULL,  0  },
    { NULL, 0, NULL, 0 }
};

static std::shared_ptr<PluginObj> DemoObj_init(void){
    return std::make_shared<DemoObj>();
}

static Plugin gPluginDef = {
    .cmdHelp = helpscreen,
    .longopts = longopts,
    .init = DemoObj_init,
};

#pragma mark constructor
__attribute__ ((constructor))
void constructor(void){
    pluginRegister(&gPluginDef);
}

__attribute__((destructor))
void destructor(void){
    pluginUnregister(&gPluginDef);
}
