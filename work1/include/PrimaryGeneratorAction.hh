//////////////////////////////////
// PrimaryGeneratorAction.hh
//////////////////////////////////
#ifndef PrimaryGeneratorAction_h
#define PrimaryGeneratorAction_h 1
#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ThreeVector.hh"
#include "globals.hh"
//#include "G4SystemOfUnits.hh"
class G4ParticleGun;
class G4Event;
class PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
public:
PrimaryGeneratorAction(
const G4String& particleName = "geantino",
G4double energy = 1. ,
                       //*MeV,
G4ThreeVector position= G4ThreeVector(0,0,0),
G4ThreeVector momentumDirection = G4ThreeVector(0,0,1));
~PrimaryGeneratorAction();
// methods
virtual void GeneratePrimaries(G4Event*);
private:
// data members
G4ParticleGun* fParticleGun; //pointer a to G4 service class
};
#endif


// from Book For Application Developers
/*https://geant4-userdoc.web.cern.ch/UsersGuides/ForApplicationDeveloper/fo/BookForApplicationDevelopers.pdf*/
