//#ifndef ACTION_h
//#define ACTION_h 1

#include "G4VUserActionInitialization.hh"
// #include “G4VUserInitialization.hh”
//without namespcae, creation, virtual things for now for simplication 
class ActionInitialization : public G4VUserActionInitialization
{
public:
    //action() = default;
    //~action() override = default;
    
    //  void BuildForMaster() const override;
    //void Build() const override ;
    ActionInitialization();
    virtual ~ActionInitialization() override;
    
    virtual void Build() const override;
    
    
};

//#endif
