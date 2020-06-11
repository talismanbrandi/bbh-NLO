#include <TFile.h>
#include <TTree.h>
#include <iostream>
#include <fstream>

void AnalyzeTreeKinematics()
{
// Change lines 9, 10, 15 and 34. class = 0 for background and 1 for signal
    TFile file("bdt_bbxaa.root");
    TTree* tree = (TTree*) file.Get("yb2");
	Float_t nbjet, njjet;
    Float_t ptb1, ptb2, pta1, pta2, ptaa;
    Float_t etab1, etab2, etaa1, etaa2, etaaa;
    Float_t mbb, maa, mb1h, mbbh;
    Float_t drbamin, drba1, dphiba1, dphibb;
    Float_t weight;
    int type = 4;
    tree->SetBranchAddress("nbjet", &nbjet);
    tree->SetBranchAddress("njjet", &njjet);
    tree->SetBranchAddress("ptb1", &ptb1);
    tree->SetBranchAddress("ptb2", &ptb2);
    tree->SetBranchAddress("pta1", &pta1);
    tree->SetBranchAddress("pta2", &pta2);
    tree->SetBranchAddress("ptaa", &ptaa);
    tree->SetBranchAddress("etab1", &etab1);
    tree->SetBranchAddress("etab2", &etab2);
    tree->SetBranchAddress("etaa1", &etaa1);
    tree->SetBranchAddress("etaa2", &etaa2);
    tree->SetBranchAddress("etaaa", &etaaa);
    tree->SetBranchAddress("mbb", &mbb);
    tree->SetBranchAddress("maa", &maa);
    tree->SetBranchAddress("mb1h", &mb1h);
    tree->SetBranchAddress("mbbh", &mbbh);
    tree->SetBranchAddress("drbamin", &drbamin);
    tree->SetBranchAddress("drba1", &drba1);
    tree->SetBranchAddress("dphiba1", &dphiba1);
    tree->SetBranchAddress("dphibb", &dphibb);
    tree->SetBranchAddress("weight", &weight);
    std::ofstream myfile;
    myfile.open("yb2.csv");
    myfile << "nbjet,njjet,ptb1,ptb2,pta1,pta2,ptaa,etab1,etab2,etaa1,etaa2,etaaa,mbb,maa,mb1h,mbbh,drbamin,drba1,dphiba1,dphibb,class,weight" << std::endl;
    for (int i = 0, N = tree->GetEntries(); i < N; ++i) {
        tree->GetEntry(i);
		myfile << nbjet << "," << njjet << ",";
        myfile << ptb1 << "," << ptb2 << "," << pta1 << "," << pta2 << "," << ptaa << ",";
        myfile << etab1 << "," << etab2 << "," << etaa1 << "," << etaa2 << "," << etaaa << ",";
        myfile << mbb << "," << maa << "," << mb1h << "," << mbbh << ",";
        myfile << drbamin << "," << drba1 << "," << dphiba1 << "," << dphibb << "," << type << "," << weight << std::endl;
    }
    myfile.close();
}
