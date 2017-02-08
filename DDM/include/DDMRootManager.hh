#ifndef ROOT_MANAGER_HH
#define ROOT_MANAGER_HH

#include "TFile.h"
#include "TTree.h"
#include "globals.hh"
#include <string>
#include "G4String.hh"
#include "TH1D.h"
#include "G4ThreeVector.hh"
#include "G4SystemOfUnits.hh"
#include <sstream>

using namespace std;

class DDMRootManager
{
	private:
		TFile* root_file;
		//Define _mng variables/arrays as needed.
		Double_t TimeStepData_mng[5] = {0};
		Int_t TreeCounter_mng = -1;
		


	public:
		static void CreateRootManager(G4String filename);
		static DDMRootManager* GetRootManager();
		static void DestroyRootManager();

		DDMRootManager(G4String filename);

		void InitialiseTree(G4String treename1);//Add more trees as arguments if desired.

		//void FillTree(); Make more of these (with specific names and the required parameters) for the individual branches as needed.
		void FillTree_TimeStepData(G4double input_time, G4double input_x, G4double input_y, G4double input_z, G4double input_energy);

		void CloseTree();
	
		//void NewBranch();

		//Define Get and Set methods for each _mng variable: can be defined inline.

		void PrintToScreen(G4String input) {G4cout << input << G4endl;}

		~DDMRootManager();

};

#endif
