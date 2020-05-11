#include <TFile.h>
#include <TTree.h>
#include <iostream>
#include <fstream>

void AnalyzeTreeKinematics()
{
// Change lines 9, 10, 15 and 34. class = 0 for background and 1 for signal
    TFile file("sig.root");
    TTree* tree = (TTree*) file.Get("sig_1b");
    Float_t nbjet, njjet;
    Float_t ptb1, pta1, pta2, ptaa;
    Float_t etab1, etaa1, etaa2, etaaa;
    Float_t maa, sqrts;
    Float_t drbamin, drba1, dphiba1;
    Float_t weight;
    int class = 1;
    tree->SetBranchAddress("nbjet", &nbjet);
    tree->SetBranchAddress("njjet", &njjet);
    tree->SetBranchAddress("ptb1", &ptb1);
    tree->SetBranchAddress("pta1", &pta1);
    tree->SetBranchAddress("pta2", &pta2);
    tree->SetBranchAddress("ptaa", &ptaa);
    tree->SetBranchAddress("etab1", &etab1);
    tree->SetBranchAddress("etaa1", &etaa1);
    tree->SetBranchAddress("etaa2", &etaa2);
    tree->SetBranchAddress("etaaa", &etaaa);
    tree->SetBranchAddress("maa", &maa);
    tree->SetBranchAddress("sqrts", &sqrts);
    tree->SetBranchAddress("drbamin", &drbamin);
    tree->SetBranchAddress("drba1", &drba1);
    tree->SetBranchAddress("dphiba1", &dphiba1);
    tree->SetBranchAddress("weight", &weight);
    std::ofstream myfile;
    myfile.open("sig-kin.csv");
    myfile << "nbjet,njjet,ptb1,pta1,pta2,ptaa,etab1,etaa1,etaa2,etaaa,maa,sqrts,drbamin,drba1,dphiba1,class,weight" << std::endl;
    for (int i = 0, N = tree->GetEntries(); i < N; ++i) {
        tree->GetEntry(i);
        myfile << nbjet << "," << njjet << ",";
        myfile << ptb1 << "," << pta1 << "," << pta2 << "," << ptaa << ",";
        myfile << etab1 << "," << etaa1 << "," << etaa2 << "," << etaaa << ",";
        myfile << maa << "," << sqrts << ",";
        myfile << drbamin << "," << drba1 << "," << dphiba1 << "," << class << "," << weight << std::endl;
    }
    myfile.close();
}
