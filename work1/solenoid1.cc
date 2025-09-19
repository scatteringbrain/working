// main program of the solenoid
#include <iostream>
//#include "solenoid1.cc" //should not do this --> will be nesting problem
#include "DetectorConstruction.hh"
#include "PrimaryGeneratorAction.hh"
//#include "PhysicsList.hh"  // these are essential, because the run manager needs
               // 1. the detector geometry
               // 2. particles and physics processes
               // 3. how primary particles will be produced
               // 4. Any additional
               // so here "DetectorConstruction", "PhysicsList", "ActionInitialization are essential

#include "ActionInitialization.hh" // essential


#include "QBBC.hh" //recommanded library

#include "G4RunManagerFactory.hh"
//#include "G4RunManager.hh"
//#include "G4SteppingVerbos.hh" // don't need this i guess for now
#include "G4UIExecutive.hh" // don't know what this does
#include "G4UImanager.hh" // don't know what this does but sounds to be essential
#include "G4VisExecutive.hh" // don't know what this does but sounds to be essential
#include "G4VisManager.hh" //after trying everything except vis setting, applying this
#include "G4SteppingVerbose.hh"

// I am not sure namespace should not be used here or not/
// namespace sol{ // namespace --> lower case //class --> upper case
// without namespace for now
int main(int argc, char** argv) //for vis manager the two parameters are essentail
{
    
    //construct the run manager
    
    //auto runManager = G4RunManagerFactory::CreateRunManager();
    //G4RunManager *runManager = new G4RunManager();

    // Detect interactive mode (if no arguments) and define UI session
    //
    G4UIExecutive* ui = nullptr;
    if (argc == 1) {
    ui = new G4UIExecutive(argc, argv);
    }


      // use G4SteppingVerboseWithUnits
    G4int precision = 4;
    G4SteppingVerbose::UseBestUnit(precision);

    auto runManager = G4RunManagerFactory::CreateRunManager(G4RunManagerType::Serial);
    G4VModularPhysicsList* physicsList = new QBBC;
    physicsList->SetVerboseLevel(1);
    runManager -> SetUserInitialization(physicsList);
    runManager -> SetUserInitialization(new ActionInitialization);
    runManager -> SetUserInitialization(new DetectorConstruction);
    
    
    //initializa G4 kernel
    runManager -> Initialize();
    
    // G4UIExecutive *ui = new G4UIExecutive(argc,argv);
    
    //G4VisManager *visManager = new G4VisExecutive(argc, argv);
    // - a graphics system of choice, eg. "OGL"
    // - and a verbosity argument - see /vis/verbose guidance.
    auto visManager = new G4VisExecutive(argc, argv);
    
    //auto visManager = new G4VisExecutive("Quiet");
    
    visManager->Initialize();
    
    G4UImanager *UImanager = G4UImanager::GetUIpointer(); //no 'new'

 // Process macro or start UI session
  //
  if (!ui) {
    // batch mode
    G4String command = "/control/execute ";
    G4String fileName = argv[1];
    UImanager->ApplyCommand(command + fileName);
  }
  else {
    // interactive mode
    UImanager->ApplyCommand("/control/execute init_vis_sol.mac");
    ui->SessionStart();
    delete ui;
  }
    //set mandatory initialization classes
    // Physics list
    
    
    
    
    //int numberOfEvent = 3; can not do this for now
    
    //runManager->beamOn(numberOfEvent); can not do this for now
    
    
    // get the pointer to the UI manager and set verbosities
    // a pointer to the interface manager must be obtained.
    
    //G4UImanager* UI = G4UImanager::GetUIpointer();
    
   // G4VisManager *visManager =new G4VisExecutive();
   // visManager -> Initialize();
    
    //G4UIExecutive * ui = new G4UIExecutive(argc, argv);
    
    //ui ->SessionStart();
    
    //  There are many built-in commands ( for the applyCommand() )
    
    // There are two kinds of user classes : initialization and user action
    
    // initialization --> G4RunManager by SetUserInitialization()
    
    // action --> G4VUserActionInitialization
    
    // all three are mandatory : G4VUserDetector... G4VUserPhysicsList, G4VUserAction....
    
    // ActionInitialization shoud have a "primarygenerationaction" : G4VUserPrimaryGeneratorAction
    // --> not using this for now... wil do this later
    // However for the UI
    
    //UI->ApplyCommand("/run/verbose 1");
    //UI->ApplyCommand("/event/verbose 1");
    //UI->ApplyCommand("/tracking/verbose 1");
    
    // start a run
    //int numberOfEvent = 3; // minimum physlist and action --> nothing in here for now
    //runManager ->BeamOn(numberOfEvent);
    
    delete runManager;
    // /delete visManager;
    //delete UI;
    return 0;
    
}
//}

