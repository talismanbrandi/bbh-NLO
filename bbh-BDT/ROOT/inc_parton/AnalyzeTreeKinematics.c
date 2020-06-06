#include <TFile.h>
#include <TTree.h>
#include <iostream>
#include <fstream>

void AnalyzeTreeKinematics()
{
// Change lines 9, 10, 15 and 34. class = 0 for background and 1 for signal
    TFile file("yb2.root");
    TTree* tree = (TTree*) file.Get("yb2");
    Float_t nbjet;
    Float_t ptb1, ptb2, pth;
    Float_t etab1, etab2, etah;
    Float_t mbb, mb1h, mbbh, mt4;
    Float_t dphibb;
    Float_t weight;
    int type = 3;
    tree->SetBranchAddress("nbjet", &nbjet);
    tree->SetBranchAddress("ptb1", &ptb1);
	tree->SetBranchAddress("ptb2", &ptb2);
    tree->SetBranchAddress("pth", &pth);
    tree->SetBranchAddress("etab1", &etab1);
    tree->SetBranchAddress("etab2", &etab2);
    tree->SetBranchAddress("etah", &etah);
    tree->SetBranchAddress("mbb", &mbb);
	tree->SetBranchAddress("mb1h", &mb1h);
	tree->SetBranchAddress("mbbh", &mbbh);
	tree->SetBranchAddress("mt4", &mt4);
    tree->SetBranchAddress("dphibb", &dphibb);
    tree->SetBranchAddress("weight", &weight);
    std::ofstream myfile;
    myfile.open("yb2.csv");
    myfile << "nbjet,ptb1,ptb2,pth,etab1,etab2,etah,mbb,mb1h,mbbh,mt4,dphibb,class,weight" << std::endl;
    for (int i = 0, N = tree->GetEntries(); i < N; ++i) {
        tree->GetEntry(i);
        myfile << nbjet << ",";
        myfile << ptb1 << "," << ptb2 << "," << pth << ",";
        myfile << etab1 << "," << etab2 << "," << etah << ",";
        myfile << mbb << "," << mb1h << "," << mbbh << "," << mt4 << ",";
        myfile << dphibb << "," << type << "," << weight << std::endl;
    }
    myfile.close();
}
