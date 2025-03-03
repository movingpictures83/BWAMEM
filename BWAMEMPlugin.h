#ifndef BWAMEMPLUGIN_H
#define BWAMEMPLUGIN_H

#include "Plugin.h"
#include "PluginProxy.h"
#include "Tool.h"
#include <string>

class BWAMEMPlugin : public Plugin, public Tool
{
public: 
 std::string toString() {return "BWAMEM";}
 void input(std::string file);
 void run();
 void output(std::string file);

private: 
 std::string inputfile;
 std::string outputfile;
};

#endif
