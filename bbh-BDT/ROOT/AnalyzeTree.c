#include <TFile.h>
#include <TTree.h>
#include <iostream>
#include <fstream>

void AnalyzeTree()
{

	TFile file("sig.root");
	TTree* tree = (TTree*) file.Get("sig");
	Float_t ptb1, ptb2, pta1, pta2, ptaa;
	Float_t etab1, etab2, etaa1, etaa2, etaaa;
	Float_t mbb, maa, sqrts;
    Float_t drbamin, drba1, dphiba1, dphibb;
    int class = 1;
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
    tree->SetBranchAddress("sqrts", &sqrts);
    tree->SetBranchAddress("drbamin", &drbamin);
    tree->SetBranchAddress("drba1", &drba1);
    tree->SetBranchAddress("dphiba1", &dphiba1);
    tree->SetBranchAddress("dphibb", &dphibb);
	std::ofstream myfile;
    myfile.open("sig.csv");
    myfile << "ptb1,ptb2,pta1,pta2,ptaa,etab1,etab2,etaa1,etaa2,etaaa,mbb,maa,sqrts,drbamin,drba1,dphiba1,dphibb,class" << std::endl;
	for (int i = 0, N = tree->GetEntries(); i < N; ++i) {
		tree->GetEntry(i);
		myfile << ptb1 << "," << ptb2 << "," << pta1 << "," << pta2 << "," << ptaa << ",";
        myfile << etab1 << "," << etab2 << "," << etaa1 << "," << etaa2 << "," << etaaa << ",";
        myfile << mbb << "," << maa << "," << sqrts << ",";
        myfile << drbamin << "," << drba1 << "," << dphiba1 << "," << dphibb << "," << class << std::endl;
	}
	myfile.close();
}
