
//#ifndef DET_h
//#define DET_h 1

#include "G4VUserDetectorConstruction.hh"

class G4VPhysicalVolume;
class G4LogicalVolume;
//without namespace, creation ,if method anso on for now
//namespace sol
//{
// Detector construction class to define materials and geometry.

class DetectorConstruction : public G4VUserDetectorConstruction
{
public:
	//detector()=default;
	//virtual ~detector() override = default;

//public: // i don't know why
    //G4VPhysicalVolume* Construct() override;
    
    DetectorConstruction();
    virtual ~DetectorConstruction() override;
    
    virtual G4VPhysicalVolume* Construct() override;
//G4LogicalVolume* GetScoringVolume() const {return fScoringVolume;} //
    // "vtable for solenoid::DetectorConstruction"
    // it seems i need this
    
 //later things
// 	G4LogicalVolume* GetScroingVolume() const { return fScoringVolume; }
	
 //protected: // i need this too. this is the delcaration of the fScoringVolume;
//	G4LogicalVolume* fScoringVolume = nullptr;
}; //closing Solenoid class  (upper )
//}//namespace solenoid (lower)
//#endif
