#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "BWAMEMPlugin.h"

void BWAMEMPlugin::input(std::string file) {
   readParameterFile(file);
}

void BWAMEMPlugin::run() {}

void BWAMEMPlugin::output(std::string file) {
       	std::string outputfile = file;
	//#minimap2 -ax map-ont data/genome.fasta data/reads.fastq -o ONTaln.sam
	// bwa mem -t 4 data/genome.fasta data/RNA_F.fastq data/RNA_R.fastq > RNAaln.sam
	std::string myCommand = "bwa mem -t 4 "+PluginManager::addPrefix(myParameters["database"])+" "+PluginManager::addPrefix(myParameters["forward"])+" "+PluginManager::addPrefix(myParameters["reverse"])+" > "+file;
 std::cout << myCommand << std::endl;
system(myCommand.c_str());
}

PluginProxy<BWAMEMPlugin> BWAMEMPluginProxy = PluginProxy<BWAMEMPlugin>("BWAMEM", PluginManager::getInstance());
