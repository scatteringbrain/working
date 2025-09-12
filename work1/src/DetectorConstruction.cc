//#ifndef det_c without if method for now
//#define det_c 1

#include "DetectorConstruction.hh"
#include "G4Tubs.hh"
#include "G4Torus.hh"
#include "G4LogicalVolume.hh"
#include "G4SystemOfUnits.hh"
#include "G4NistManager.hh"
#include "G4Sphere.hh"
#include "G4PVPlacement.hh"
#include "globals.hh"

// the shop '#' was a problem : mention out clearly first copy from solenoid example
//  namespace sol without namespace for now
//{

//without creater and demolisher for now

DetectorConstruction::DetectorConstruction()
    : G4VUserDetectorConstruction()
 //   //fPV(nullptr)
{
}

DetectorConstruction::~DetectorConstruction()
{
}


G4VPhysicalVolume* DetectorConstruction::Construct()
{

//Get nist material manager
G4NistManager* nist = G4NistManager::Instance();

// Torus parameters

//static const double pi = 3.14159265358979323846;

G4double rmin = 20 * cm, rmax = 30* cm, rot = 0*deg, sphi =0*deg, dphi=360*deg;
G4Material* to_mat = nist->FindOrBuildMaterial("G4_WATER");



// option to switch on/off checking of volumes overlaps

G4bool checkOverlaps =true;

//world
// sphere shape


G4double world_rmin = 1.2*rmin , world_rmax = 1.2*rmax , world_sphi = 0*deg, world_dphi = 360*deg, world_sthe = 0*deg, world_dthe = 180*deg ;
G4Material* world_mat = nist -> FindOrBuildMaterial("G4_AIR");


auto solidWorld = new G4Sphere("World", // its name
world_rmin, world_rmax, world_sphi, world_dphi, world_sthe, world_dthe);

auto logicWorld = new G4LogicalVolume(solidWorld, world_mat,"World");

auto physWorld = new G4PVPlacement(0, // no rotation
				   G4ThreeVector(), // at (0,0,0)
				   logicWorld, //its logical volume
				   "World", // its name
				   0, // its mother volume 
				   false, // no boolean operation
				   0, // copy number
				   checkOverlaps); 

//Torus 
//

auto solidtorus = new G4Torus("Torus", //its name
			10*cm, 30*cm, 50*cm, 0, 30*deg);

auto logictorus = new G4LogicalVolume(solidtorus, to_mat, "Torus");

auto phytorus = new G4PVPlacement(0, // no rotation
		   G4ThreeVector(), // at (0,0,0)
		   logictorus,
		   "Torus",
            logicWorld,
		   false,
		   0,
		   checkOverlaps);


//scoring volume (later) :
//    fScoringVolume = logictorus;
// this is the essential value?
// always return the physical World (thirdly declarated one of the world )

return physWorld;

} // construct close

//} // namespace close without namespace for now
//#endif
