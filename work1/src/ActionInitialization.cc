//#ifndef action_c
//#define action_c 1

#include "ActionInitialization.hh"
#include "PrimaryGeneratorAction.hh"
//without namespcace and creation things for now
//namespace sol{

ActionInitialization::ActionInitialization()
    : G4VUserActionInitialization()
{
}

ActionInitialization::~ActionInitialization()
{
}


void ActionInitialization::Build() const
{
    SetUserAction(new PrimaryGeneratorAction);
}
//}
//#endif
