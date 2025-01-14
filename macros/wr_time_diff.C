//insert all headers
#include "TTree.h"
#include "TFile.h"
#include <math.h>
#include <string>
#include <iostream>
#include "TH1F.h"
#include "TH2F.h"
#include "TClonesArray.h"
#include "TChain.h"


#include <stdlib.h>
using namespace std;
const int nb_tpats = 16;
char hist_name[500];

void wr_time_diff(){


TH1D* h1_wr_ts_califa_diff_WRM_messel_rand;
sprintf(hist_name, "WR Messel -  WR Master (one random hit for event)");
h1_wr_ts_califa_diff_WRM_messel_rand = new TH1D(hist_name,hist_name,500,-5000,5000);
h1_wr_ts_califa_diff_WRM_messel_rand->GetXaxis()->SetTitle(" wr time difference [ns]");
h1_wr_ts_califa_diff_WRM_messel_rand->GetYaxis()->SetTitle("Counts");
h1_wr_ts_califa_diff_WRM_messel_rand->GetXaxis()->CenterTitle(true);
h1_wr_ts_califa_diff_WRM_messel_rand->GetYaxis()->CenterTitle(true);
h1_wr_ts_califa_diff_WRM_messel_rand->GetYaxis()->SetLabelSize(0.045);
h1_wr_ts_califa_diff_WRM_messel_rand->GetYaxis()->SetTitleSize(0.045);


TH1D* h1_wr_ts_califa_diff_WRM_wix_rand;
sprintf(hist_name, "WR Wixhausen - WR Master (one random hit for event)");
h1_wr_ts_califa_diff_WRM_wix_rand = new TH1D(hist_name,hist_name,500,-5000,5000);
h1_wr_ts_califa_diff_WRM_wix_rand->GetXaxis()->SetTitle("wr time difference [ns]");
h1_wr_ts_califa_diff_WRM_wix_rand->GetYaxis()->SetTitle("Counts");
h1_wr_ts_califa_diff_WRM_wix_rand->GetXaxis()->CenterTitle(true);
h1_wr_ts_califa_diff_WRM_wix_rand->GetYaxis()->CenterTitle(true);
h1_wr_ts_califa_diff_WRM_wix_rand->GetYaxis()->SetLabelSize(0.045);
h1_wr_ts_califa_diff_WRM_wix_rand->GetYaxis()->SetTitleSize(0.045);

TH1D* h1_wr_ts_califa_diff_WRM_both_rand;
sprintf(hist_name, "WR CALIFA - WR Master (one random hit for event wixhausen or messel)");
h1_wr_ts_califa_diff_WRM_both_rand = new TH1D(hist_name,hist_name,500,-5000,5000);
h1_wr_ts_califa_diff_WRM_both_rand->GetXaxis()->SetTitle("wr time difference [ns]");
h1_wr_ts_califa_diff_WRM_both_rand->GetYaxis()->SetTitle("Counts");
h1_wr_ts_califa_diff_WRM_both_rand->GetXaxis()->CenterTitle(true);
h1_wr_ts_califa_diff_WRM_both_rand->GetYaxis()->CenterTitle(true);
h1_wr_ts_califa_diff_WRM_both_rand->GetYaxis()->SetLabelSize(0.045);
h1_wr_ts_califa_diff_WRM_both_rand->GetYaxis()->SetTitleSize(0.045);

//WR_CALIFA - WR Master for the different Tpats:

TH1D* h1_wr_ts_califa_diff_WRM_both_rand_tpat[nb_tpats];
for (Int_t i = 0; i < nb_tpats; i++){
sprintf(hist_name, "WR CALIFA - WR Master (one random hit for event wixhausen or messel) for TPAT: %i", i+1);
h1_wr_ts_califa_diff_WRM_both_rand_tpat[i] = new TH1D(hist_name,hist_name,500,-5000,5000);
h1_wr_ts_califa_diff_WRM_both_rand_tpat[i]->GetXaxis()->SetTitle("wr time difference [ns]");
h1_wr_ts_califa_diff_WRM_both_rand_tpat[i]->GetYaxis()->SetTitle("Counts");
h1_wr_ts_califa_diff_WRM_both_rand_tpat[i]->GetXaxis()->CenterTitle(true);
h1_wr_ts_califa_diff_WRM_both_rand_tpat[i]->GetYaxis()->CenterTitle(true);
h1_wr_ts_califa_diff_WRM_both_rand_tpat[i]->GetYaxis()->SetLabelSize(0.045);
h1_wr_ts_califa_diff_WRM_both_rand_tpat[i]->GetYaxis()->SetTitleSize(0.045);
}

//Energy vs ts difference for events with wr master trigger
TH1D* h1_wr_ts_califa_vs_E_M;
sprintf(hist_name, "Hit Energy (events with master trigger)");
h1_wr_ts_califa_vs_E_M = new TH1D(hist_name,hist_name,1000,0,10);
h1_wr_ts_califa_vs_E_M->GetXaxis()->SetTitle("Energy [MeV]");
h1_wr_ts_califa_vs_E_M->GetYaxis()->SetTitle("Counts");
h1_wr_ts_califa_vs_E_M->GetXaxis()->CenterTitle(true);
h1_wr_ts_califa_vs_E_M->GetYaxis()->CenterTitle(true);
h1_wr_ts_califa_vs_E_M->GetYaxis()->SetLabelSize(0.045);
h1_wr_ts_califa_vs_E_M->GetYaxis()->SetTitleSize(0.045);

//Energy vs ts difference for events without wr master trigger
TH1D* h1_wr_ts_califa_vs_E_noM;
sprintf(hist_name, "Hit Energy (events NO master trigger)");
h1_wr_ts_califa_vs_E_noM = new TH1D(hist_name,hist_name,1000,0,10);
h1_wr_ts_califa_vs_E_noM->GetXaxis()->SetTitle("Energy [MeV]");
h1_wr_ts_califa_vs_E_noM->GetYaxis()->SetTitle("Counts");
h1_wr_ts_califa_vs_E_noM->GetXaxis()->CenterTitle(true);
h1_wr_ts_califa_vs_E_noM->GetYaxis()->CenterTitle(true);
h1_wr_ts_califa_vs_E_noM->GetYaxis()->SetLabelSize(0.045);
h1_wr_ts_califa_vs_E_noM->GetYaxis()->SetTitleSize(0.045);


//Multiplicity for events with wr master

TH1D* h1_mult_with_M;
sprintf(hist_name, "Multiplicity for events with master trigger");
h1_mult_with_M = new TH1D(hist_name,hist_name,2500,0,2500);
h1_mult_with_M->GetXaxis()->SetTitle("Multiplicity");
h1_mult_with_M->GetYaxis()->SetTitle("Counts");
h1_mult_with_M->GetXaxis()->CenterTitle(true);
h1_mult_with_M->GetYaxis()->CenterTitle(true);
h1_mult_with_M->GetYaxis()->SetLabelSize(0.045);
h1_mult_with_M->GetYaxis()->SetTitleSize(0.045);

//Multiplicity for different Tpats:

TH1D* h1_mult_with_M_tpat[nb_tpats];
for (Int_t i = 0; i < nb_tpats; i++){
sprintf(hist_name, "Multiplicity for events with TPAT: %i", i+1);
h1_mult_with_M_tpat[i] = new TH1D(hist_name,hist_name,2500,0,2500);
h1_mult_with_M_tpat[i]->GetXaxis()->SetTitle("Multiplicity");
h1_mult_with_M_tpat[i]->GetYaxis()->SetTitle("Counts");
h1_mult_with_M_tpat[i]->GetXaxis()->CenterTitle(true);
h1_mult_with_M_tpat[i]->GetYaxis()->CenterTitle(true);
h1_mult_with_M_tpat[i]->GetYaxis()->SetLabelSize(0.045);
h1_mult_with_M_tpat[i]->GetYaxis()->SetTitleSize(0.045);
}

//Multiplicity for events without wr master

TH1D* h1_mult_no_M;
sprintf(hist_name, "Multiplicity for events NO master trigger");
h1_mult_no_M = new TH1D(hist_name,hist_name,2500,0,2500);
h1_mult_no_M->GetXaxis()->SetTitle("Multiplicity");
h1_mult_no_M->GetYaxis()->SetTitle("Counts");
h1_mult_no_M->GetXaxis()->CenterTitle(true);
h1_mult_no_M->GetYaxis()->CenterTitle(true);
h1_mult_no_M->GetYaxis()->SetLabelSize(0.045);
h1_mult_no_M->GetYaxis()->SetTitleSize(0.045);

TH1D* h1_mult_e_high;
sprintf(hist_name, "Multiplicity of hits with E_lab > 20 MeV (with master trigger)");
h1_mult_e_high = new TH1D(hist_name,hist_name,2500,0,2500);
h1_mult_e_high->GetXaxis()->SetTitle("Multiplicity");
h1_mult_e_high->GetYaxis()->SetTitle("Counts");
h1_mult_e_high->GetXaxis()->CenterTitle(true);
h1_mult_e_high->GetYaxis()->CenterTitle(true);
h1_mult_e_high->GetYaxis()->SetLabelSize(0.045);
h1_mult_e_high->GetYaxis()->SetTitleSize(0.045);

//Multiplicity with high_e for different tpats

TH1D* h1_mult_e_high_tpat[nb_tpats];
for (Int_t i = 0; i < nb_tpats; i++){
sprintf(hist_name, "Multiplicity of hits with E_lab > 20 MeV for TPAT: %i", i+1);
h1_mult_e_high_tpat[i] = new TH1D(hist_name,hist_name,2500,0,2500);
h1_mult_e_high_tpat[i]->GetXaxis()->SetTitle("Multiplicity");
h1_mult_e_high_tpat[i]->GetYaxis()->SetTitle("Counts");
h1_mult_e_high_tpat[i]->GetXaxis()->CenterTitle(true);
h1_mult_e_high_tpat[i]->GetYaxis()->CenterTitle(true);
h1_mult_e_high_tpat[i]->GetYaxis()->SetLabelSize(0.045);
h1_mult_e_high_tpat[i]->GetYaxis()->SetTitleSize(0.045);
}


TH1D* h1_mult_e_high_noM;
sprintf(hist_name, "Multiplicity of hits with E_lab > 20 MeV (events without master trigger)");
h1_mult_e_high_noM = new TH1D(hist_name,hist_name,2500,0,2500);
h1_mult_e_high_noM->GetXaxis()->SetTitle("Multiplicity");
h1_mult_e_high_noM->GetYaxis()->SetTitle("Counts");
h1_mult_e_high_noM->GetXaxis()->CenterTitle(true);
h1_mult_e_high_noM->GetYaxis()->CenterTitle(true);
h1_mult_e_high_noM->GetYaxis()->SetLabelSize(0.045);
h1_mult_e_high_noM->GetYaxis()->SetTitleSize(0.045);


//check Energy versus polar angle distribution
//
TH2D* h2_energy_vs_theta;
sprintf(hist_name, "E_lab vs. polar angle (with master trigger)");
h2_energy_vs_theta = new TH2D(hist_name,hist_name,1000,0,1000,25,22.15,84.65);
h2_energy_vs_theta->GetXaxis()->SetTitle("Energy in laboratory system [MeV]");
h2_energy_vs_theta->GetYaxis()->SetTitle("Polar angle Theta [degrees]");
h2_energy_vs_theta->GetXaxis()->CenterTitle(true);
h2_energy_vs_theta->GetYaxis()->CenterTitle(true);
h2_energy_vs_theta->GetYaxis()->SetLabelSize(0.045);
h2_energy_vs_theta->GetYaxis()->SetTitleSize(0.045);


//E_lab vs ploar angle for different tpats
TH2D* h2_energy_vs_theta_tpat[nb_tpats];
for (Int_t i = 0; i < nb_tpats; i++){
sprintf(hist_name, "E_lab vs. polar angle for TPAT: %i", i+1);
h2_energy_vs_theta_tpat[i] = new TH2D(hist_name,hist_name,1000,0,1000,25,22.15,84.65);
h2_energy_vs_theta_tpat[i]->GetXaxis()->SetTitle("Energy in laboratory system [MeV]");
h2_energy_vs_theta_tpat[i]->GetYaxis()->SetTitle("Polar angle Theta [degrees]");
h2_energy_vs_theta_tpat[i]->GetXaxis()->CenterTitle(true);
h2_energy_vs_theta_tpat[i]->GetYaxis()->CenterTitle(true);
h2_energy_vs_theta_tpat[i]->GetYaxis()->SetLabelSize(0.045);
h2_energy_vs_theta_tpat[i]->GetYaxis()->SetTitleSize(0.045);
}

//check angular distribution in phi and theta

TH2D* h2_phi_vs_theta;
sprintf(hist_name, "Phi vs Theta (with master trigger)");
h2_phi_vs_theta = new TH2D(hist_name,hist_name,25,22.15,84.65,60,-180,180);
h2_phi_vs_theta->GetXaxis()->SetTitle("Polar angle  Theta[degrees]");
h2_phi_vs_theta->GetYaxis()->SetTitle("Arzimuthal angle Phi [degrees]");
h2_phi_vs_theta->GetXaxis()->CenterTitle(true);
h2_phi_vs_theta->GetYaxis()->CenterTitle(true);
h2_phi_vs_theta->GetYaxis()->SetLabelSize(0.045);
h2_phi_vs_theta->GetYaxis()->SetTitleSize(0.045);

//anglular distribution for the different tpats
TH2D* h2_phi_vs_theta_tpat[nb_tpats];
for (Int_t i = 0; i < nb_tpats; i++){
sprintf(hist_name, "Phi vs Theta for TPAT: %i", i+1);
h2_phi_vs_theta_tpat[i] = new TH2D(hist_name,hist_name,25,22.15,84.65,60,-180,180);
h2_phi_vs_theta_tpat[i]->GetXaxis()->SetTitle("Polar angle  Theta[degrees]");
h2_phi_vs_theta_tpat[i]->GetYaxis()->SetTitle("Arzimuthal angle Phi [degrees]");
h2_phi_vs_theta_tpat[i]->GetXaxis()->CenterTitle(true);
h2_phi_vs_theta_tpat[i]->GetYaxis()->CenterTitle(true);
h2_phi_vs_theta_tpat[i]->GetYaxis()->SetLabelSize(0.045);
h2_phi_vs_theta_tpat[i]->GetYaxis()->SetTitleSize(0.045);
}

//energy versus multiplicity distribution with and without master trigger
TH2D* h2_energy_vs_mult_no_M;
sprintf(hist_name, "Summed up E_lab(mapped level) vs Multiplicity, Uncorrelated");
h2_energy_vs_mult_no_M = new TH2D(hist_name,hist_name,1000,0,1000,400,0,400);
h2_energy_vs_mult_no_M->GetXaxis()->SetTitle("Summed Energy in laboratory system [MeV]");
h2_energy_vs_mult_no_M->GetYaxis()->SetTitle("Multiplicity");
h2_energy_vs_mult_no_M->GetXaxis()->CenterTitle(true);
h2_energy_vs_mult_no_M->GetYaxis()->CenterTitle(true);
h2_energy_vs_mult_no_M->GetYaxis()->SetLabelSize(0.045);
h2_energy_vs_mult_no_M->GetYaxis()->SetTitleSize(0.045);


TH2D* h2_energy_vs_mult_with_M;
sprintf(hist_name, "Summed up E_lab(mapped level) vs Multiplicity, Correlated");
h2_energy_vs_mult_with_M = new TH2D(hist_name,hist_name,1000,0,1000,400,0,400);
h2_energy_vs_mult_with_M->GetXaxis()->SetTitle("Summed Energy in laboratory system [MeV]");
h2_energy_vs_mult_with_M->GetYaxis()->SetTitle("Multiplicity");
h2_energy_vs_mult_with_M->GetXaxis()->CenterTitle(true);
h2_energy_vs_mult_with_M->GetYaxis()->CenterTitle(true);
h2_energy_vs_mult_with_M->GetYaxis()->SetLabelSize(0.045);
h2_energy_vs_mult_with_M->GetYaxis()->SetTitleSize(0.045);


//summed energy_lab vs multiplicity for different tpats
TH2D* h2_energy_vs_mult_with_M_tpat[nb_tpats];
for (Int_t i = 0; i < nb_tpats; i++){
sprintf(hist_name, "Summed up E_lab(mapped level) vs Multiplicity, for TPAT: %i", i+1);
h2_energy_vs_mult_with_M_tpat[i] = new TH2D(hist_name,hist_name,1000,0,1000,400,0,400);
h2_energy_vs_mult_with_M_tpat[i]->GetXaxis()->SetTitle("Summed Energy in laboratory system [MeV]");
h2_energy_vs_mult_with_M_tpat[i]->GetYaxis()->SetTitle("Multiplicity");
h2_energy_vs_mult_with_M_tpat[i]->GetXaxis()->CenterTitle(true);
h2_energy_vs_mult_with_M_tpat[i]->GetYaxis()->CenterTitle(true);
h2_energy_vs_mult_with_M_tpat[i]->GetYaxis()->SetLabelSize(0.045);
h2_energy_vs_mult_with_M_tpat[i]->GetYaxis()->SetTitleSize(0.045);
}


//Histo with trigger info:
TH1F* h1_trigger = new TH1F("h1_trigger", "Trigger information: Tpat", 17, -0.5, 16.5);
h1_trigger->GetXaxis()->SetTitle("Trigger number (tpat)");
h1_trigger->GetYaxis()->SetTitle("Counts");
h1_trigger->GetXaxis()->CenterTitle(true);
h1_trigger->GetYaxis()->CenterTitle(true);
h1_trigger->GetXaxis()->SetLabelSize(0.04);
h1_trigger->GetXaxis()->SetTitleSize(0.04);
h1_trigger->GetYaxis()->SetTitleOffset(1.1);
h1_trigger->GetXaxis()->SetTitleOffset(1.1);
h1_trigger->GetYaxis()->SetLabelSize(0.04);
h1_trigger->GetYaxis()->SetTitleSize(0.04);
h1_trigger->SetFillColor(kBlue + 2);

fstream fin;
fin.open("../parameters/crystal_mapping_s455_03.csv", ios::in); //FIXME:change to right .csv file

//new functionality, using map
map<int,int> map_id_califa_side;
string line, word, temp;
while(fin.peek()!=EOF) {
	getline(fin, line);
	stringstream s(line);
	vector<string> temp_vec;
	while (getline(s, word, ',')) {
		temp_vec.push_back(word);
	}
	map_id_califa_side[stoi(temp_vec[10])] = stoi(temp_vec[0]);
	temp_vec.clear();
}


char fname[500];
Long64_t entries_califa = 0;
Long64_t entries_califa_hit = 0;
Int_t entries_wr = 0;
//Input file
sprintf(fname,"../file_src/thisFile.root");

TChain* chain = new TChain("evt");
chain->Reset();
chain->Add(fname);
Long64_t nevents = chain->GetEntries();
cout << "total number of entries:\t" << nevents << endl;

//TClonesarrays

TClonesArray* CalifaMappedData = new TClonesArray("R3BCalifaMappedData",3);
R3BCalifaMappedData** califamappeddata;
TBranch *branchCalifaMappedData = chain->GetBranch("CalifaMappedData");
branchCalifaMappedData->SetAddress(&CalifaMappedData);

TClonesArray* WRMasterData = new TClonesArray("R3BWRMasterData",1);
R3BWRMasterData** wrmasterdata;
TBranch *branchWRMasterData = chain->GetBranch("WRMasterData");
branchWRMasterData->SetAddress(&WRMasterData);

TClonesArray* CalifaHitData = new TClonesArray("R3BCalifaHitData",3);
R3BCalifaHitData** califahitdata;
TBranch *branchCalifaHitData = chain->GetBranch("CalifaHitData");
branchCalifaHitData->SetAddress(&CalifaHitData);

R3BEventHeader* DataCA = new R3BEventHeader();
TBranch* branchData = chain->GetBranch("EventHeader.");
branchData->SetAddress(&DataCA);
//
const Double_t PI = 3.14159265358979323846;
uint64_t wr_Master_ts;
Long64_t events_califa_no_master = 0;
Long64_t events_califa_with_master = 0;
Long64_t events_total_califa = 0;
for(Long64_t i=0;i< nevents;i++){
    Long64_t evtnr = i;
    if (i%100000==0)
        cout<<"Processing event for charge analysis "<<i<<endl;
    chain->GetEvent(i);

    Int_t tpatbin = 0;
    Int_t ftpat = 0;
    if (DataCA->GetTpat() > 0){
            for (Int_t i = 0; i < 16; i++){
        	    tpatbin = (DataCA->GetTpat() & (1 << i));
        	    if (tpatbin != 0){
			    ftpat = i + 1;
        		    h1_trigger->Fill(ftpat);
        	    }
            }
    }
    entries_califa = CalifaMappedData->GetEntries();
    entries_califa_hit = CalifaHitData->GetEntries();
    entries_wr = WRMasterData->GetEntries();

	if (entries_califa >= 1){
		events_total_califa +=1;
		califamappeddata = new R3BCalifaMappedData*[entries_califa];
		wrmasterdata = new R3BWRMasterData*[entries_wr];
		vector<uint64_t> califa_messel_ts;
		vector<uint64_t> califa_wixhausen_ts;
		vector<uint64_t> califa_both_sides_ts;
		int e_high = 0;
		double e_sum_with_M = 0;
		double e_sum_no_M = 0;
		if (entries_wr == 1){
			events_califa_with_master+=1;
			h1_mult_with_M->Fill(entries_califa);
			for (int n = 1; n < 17; n++){
				if (ftpat == n){
					h1_mult_with_M_tpat[n-1]->Fill(entries_califa);
					}
				else
					continue;
				}
			if (entries_califa_hit){
				califahitdata = new R3BCalifaHitData*[entries_califa_hit];

			for (Int_t m = 0; m < entries_califa_hit; m++){
				califahitdata[m] = (R3BCalifaHitData*)CalifaHitData->At(m);
				h2_energy_vs_theta->Fill((califahitdata[m]->GetEnergy())/1000,((califahitdata[m]->GetTheta())/PI)*180);
				for (int n = 1; n < 17; n++){
					if (ftpat == n){
						h2_energy_vs_theta_tpat[n-1]->Fill((califahitdata[m]->GetEnergy())/1000,((califahitdata[m]->GetTheta())/PI)*180);
						}
					else
						continue;
					}
				h2_phi_vs_theta->Fill(((califahitdata[m]->GetTheta())/PI)*180,((califahitdata[m]->GetPhi())/PI)*180);
				for (int n = 1; n < 17; n++){
					if (ftpat == n){
						h2_phi_vs_theta_tpat[n-1]->Fill(((califahitdata[m]->GetTheta())/PI)*180,((califahitdata[m]->GetPhi())/PI)*180);
						}
					else
						continue;
					}
				}
			}
			}
		else if(entries_wr == 0){
			events_califa_no_master+=1;
			h1_mult_no_M->Fill(entries_califa);
			}
		for (Int_t m = 0; m < entries_califa; m++){
			califamappeddata[m] = (R3BCalifaMappedData*)CalifaMappedData->At(m);
			Int_t crystal_ID = califamappeddata[m]->GetCrystalId();
			if (crystal_ID == 1 || crystal_ID == 2){
				cout << "these are pulser events"<< endl;
				}
					if(map_id_califa_side[crystal_ID] == 1 && crystal_ID != 1 && crystal_ID != 2){ //-->Wixhausen
						califa_wixhausen_ts.push_back(califamappeddata[m]->GetWrts());
						califa_both_sides_ts.push_back(califamappeddata[m]->GetWrts());
						if (entries_wr == 1){
							h1_wr_ts_califa_vs_E_M->Fill(double((califamappeddata[m]->GetEnergy())/1000.));
							e_sum_with_M += double((califamappeddata[m]->GetEnergy())/1000.);
							if(double((califamappeddata[m]->GetEnergy())/1000.) > 20){
								e_high+=1;
								}
							}
						else if (entries_wr == 0){
							h1_wr_ts_califa_vs_E_noM->Fill(double((califamappeddata[m]->GetEnergy())/1000.));
							e_sum_no_M += double((califamappeddata[m]->GetEnergy())/1000.);
							if(double((califamappeddata[m]->GetEnergy())/1000.) > 20){
								e_high+=1;
								}
							}
						}
					else if ( map_id_califa_side[crystal_ID] ==2 && crystal_ID != 1 && crystal_ID != 2){ 	// --->MESSEL
						califa_messel_ts.push_back(califamappeddata[m]->GetWrts());
						califa_both_sides_ts.push_back(califamappeddata[m]->GetWrts());
						if (entries_wr == 1){
							h1_wr_ts_califa_vs_E_M->Fill((califamappeddata[m]->GetEnergy())/1000);
							e_sum_with_M += double((califamappeddata[m]->GetEnergy())/1000.);
							if ( (califamappeddata[m]->GetEnergy())/1000 > 20){
							e_high+=1;
							}
							}
						else if (entries_wr == 0){
							h1_wr_ts_califa_vs_E_noM->Fill((califamappeddata[m]->GetEnergy())/1000);
							e_sum_no_M += double((califamappeddata[m]->GetEnergy())/1000.);
							if(double((califamappeddata[m]->GetEnergy())/1000.) > 20){
								e_high+=1;
								}
							}
						}

				else
					continue;

			}
		if (entries_wr == 1){
			h1_mult_e_high->Fill(e_high);
			for (int n = 1; n < 17; n++){
				if (ftpat == n){
					h1_mult_e_high_tpat[n-1]->Fill(e_high);
				}
				else
					continue;
				}
			}
		if (entries_wr == 0){
			h1_mult_e_high_noM->Fill(e_high);
			}
		h2_energy_vs_mult_no_M->Fill(e_sum_no_M,entries_califa);
		h2_energy_vs_mult_with_M->Fill(e_sum_with_M,entries_califa);
		for (int n = 1; n < 17; n++){
			if (ftpat == n){
				h2_energy_vs_mult_with_M_tpat[n-1]->Fill(e_sum_with_M,entries_califa);
				}
			else
				continue;
			}
		//choose random hit in event for both messel and wixhausen:
		int rand_messel;
		int rand_wixh;
		int rand_both = rand() % califa_both_sides_ts.size();
		if (califa_messel_ts.size()){
			rand_messel = rand() % califa_messel_ts.size();
			}
		if (califa_wixhausen_ts.size()){
			rand_wixh = rand() % califa_wixhausen_ts.size();
			}
		if (califa_wixhausen_ts.size()){
		for(Int_t j = 1; j < califa_wixhausen_ts.size();++j) {
			int64_t time_diff_wixhausen = califa_wixhausen_ts[j] - califa_wixhausen_ts[0];
			if (abs(time_diff_wixhausen) > 4000){
				//cout << "this is abs. difference:\t" <<  abs(time_diff_wixhausen) <<endl;
				//cout << "and corresponding eventnr:\t" << evtnr << endl;
				}
			}
			}
		if (entries_wr == 1){
			wrmasterdata[0] = (R3BWRMasterData*)WRMasterData->At(0);
			wr_Master_ts = wrmasterdata[0]->GetTimeStamp();
			if (califa_messel_ts.size()){
				int64_t time_diff_messel_WRM_rand = califa_messel_ts[rand_messel] - wr_Master_ts;
				h1_wr_ts_califa_diff_WRM_messel_rand->Fill(time_diff_messel_WRM_rand);
				}
			if (califa_wixhausen_ts.size()){
				int64_t time_diff_wixhausen_WRM_rand = califa_wixhausen_ts[rand_wixh] - wr_Master_ts;
				h1_wr_ts_califa_diff_WRM_wix_rand->Fill(time_diff_wixhausen_WRM_rand);
				}
			if(califa_both_sides_ts.size()){
				int64_t time_diff_both_WRM_rand = califa_both_sides_ts[rand_both] - wr_Master_ts;
				h1_wr_ts_califa_diff_WRM_both_rand->Fill(time_diff_both_WRM_rand);
				for (int n = 1; n < 17; n++){
					if (ftpat == n){
						h1_wr_ts_califa_diff_WRM_both_rand_tpat[n-1]->Fill(time_diff_both_WRM_rand);
						}
					else
						continue;
					}
				}
			}
		if (entries_wr > 1){
			cout << "more than two wr_master timestamps in one event, can that be??" << endl;
			}
		califa_messel_ts.clear();
		califa_wixhausen_ts.clear();
		califa_both_sides_ts.clear();
		}
	}



char f_out_name[500];
sprintf(f_out_name,"../file_output/output_wr_time_diff.root");
TFile * f = new TFile(f_out_name,"RECREATE");
TList *l = new TList();
gStyle->SetOptStat(1111111);
l->Add(h1_wr_ts_califa_vs_E_M);
l->Add(h1_wr_ts_califa_vs_E_noM);
l->Add(h1_mult_with_M);
l->Add(h1_mult_no_M);
l->Add(h1_wr_ts_califa_diff_WRM_messel_rand);
l->Add(h1_wr_ts_califa_diff_WRM_wix_rand);
l->Add(h1_wr_ts_califa_diff_WRM_both_rand);
l->Add(h1_mult_e_high);
l->Add(h1_mult_e_high_noM);
l->Add(h2_energy_vs_theta);
l->Add(h2_phi_vs_theta);
l->Add(h2_energy_vs_mult_no_M);
l->Add(h2_energy_vs_mult_with_M);
l->Add(h1_trigger);
l->Write("histlist", TObject::kSingleKey);

TCanvas c1 ("c1","wrcalifa_wrmaster",0,0,400,300);
c1.Divide(4,4);
for (Int_t i = 0; i<nb_tpats; i++){
	c1.cd(i+1);
	h1_wr_ts_califa_diff_WRM_both_rand_tpat[i]->Draw("");
	}	
c1.Write();


TCanvas c2 ("c2","multiplicity",0,0,400,300);
c2.Divide(4,4);
for (Int_t i = 0; i<nb_tpats; i++){
	c2.cd(i+1);
	h1_mult_with_M_tpat[i]->Draw("");
	}	
c2.Write();


TCanvas c3 ("c3","high_e_multiplicity",0,0,400,300);
c3.Divide(4,4);
for (Int_t i = 0; i<nb_tpats; i++){
	c3.cd(i+1);
	h1_mult_e_high_tpat[i]->Draw("");
	}	
c3.Write();


TCanvas c4 ("c4","E_lab_vs_theta",0,0,400,300);
c4.Divide(4,4);
for (Int_t i = 0; i<nb_tpats; i++){
	c4.cd(i+1);
	h2_energy_vs_theta_tpat[i]->Draw("COLZ");
	gPad->SetLogz();
	}	
c4.Write();


TCanvas c5 ("c5","Angular_distribution",0,0,400,300);
c5.Divide(4,4);
for (Int_t i = 0; i<nb_tpats; i++){
	c5.cd(i+1);
	h2_phi_vs_theta_tpat[i]->Draw("COLZ");
	gPad->SetLogz();
	}	
c5.Write();


TCanvas c6 ("c6","Sum_energy_vs_multiplicity",0,0,400,300);
c6.Divide(4,4);
for (Int_t i = 0; i<nb_tpats; i++){
	c6.cd(i+1);
	h2_energy_vs_mult_with_M_tpat[i]->Draw("COLZ");
	gPad->SetLogz();
	}	
c6.Write();
cout << "----SUMMARY---------------------" << endl;
cout << "Califa events with master trigger:\t" << events_califa_with_master <<  " " << double(events_califa_with_master)/double(events_total_califa) << " % " << endl;
cout << "Califa events no master trigger:\t" << events_califa_no_master << " " << double(events_califa_no_master)/double(events_total_califa) << " % " << endl;
cout << "Total number of Califa events:\t" << events_total_califa << endl;
cout << "--------------------------------" << endl;

}
