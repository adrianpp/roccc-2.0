// This file was automatically build by
// /home/abuyukku/roccc/trunk/roccc-compiler/src/NuSuif/suif2/build_main.pl '-lsuifnodes -lsuifkernel -liokernel -lbasicnodes -lcommon -ltypebuilder -lsuifcloning'
// from the $(LIBS} variable in the Makefile
// 
#include "suifkernel/suifkernel_forwarders.h"
#include "suifkernel/suif_env.h"
#include "suifkernel/module_subsystem.h"
#include "suifkernel/token_stream.h"
#include "suifpasses/suifpasses.h"


int main( int argc, char* argv[] ) {
  // initialize the environment
  SuifEnv* suif = new SuifEnv;
  suif->init();

  // import and initialize the necessary libraries
  suif->require_module("suifnodes");
  suif->require_module("basicnodes");
  suif->require_module("typebuilder");
  suif->require_module("suifcloning");

  // transform the input arguments into a stream of
  // input tokens
  TokenStream token_stream( argc, argv );

  // execute the Module "execute"
  ModuleSubSystem* mSubSystem = suif->get_module_subsystem();
  mSubSystem -> execute( "execute", &token_stream );

  delete suif;

  return 0;
}
