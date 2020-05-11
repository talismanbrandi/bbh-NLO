#include <TFile.h>
#include <TTree.h>
#include <iostream>
#include <fstream>

void AnalyzeTreeFourVectors()
{
// Change lines 9, 10, 15 and 34. class = 0 for background and 1 for signal
    TFile file("bkg.root");
    TTree* tree = (TTree*) file.Get("bkg");
    Float_t b1px, b1py, b1pz, b1e;
    Float_t b2px, b2py, b2pz, b2e;
    Float_t a1px, a1py, a1pz, a1e;
    Float_t a2px, a2py, a2pz, a2e;
    Float_t weight;
    int class = 0;
    tree->SetBranchAddress("b1px", &b1px);
    tree->SetBranchAddress("b1py", &b1py);
    tree->SetBranchAddress("b1pz", &b1pz);
    tree->SetBranchAddress("b1e", &b1e);
    tree->SetBranchAddress("b2px", &b2px);
    tree->SetBranchAddress("b2py", &b2py);
    tree->SetBranchAddress("b2pz", &b2pz);
    tree->SetBranchAddress("b2e", &b2e);
    tree->SetBranchAddress("a1px", &a1px);
    tree->SetBranchAddress("a1py", &a1py);
    tree->SetBranchAddress("a1pz", &a1pz);
    tree->SetBranchAddress("a1e", &a1e);
    tree->SetBranchAddress("a2px", &a2px);
    tree->SetBranchAddress("a2py", &a2py);
    tree->SetBranchAddress("a2pz", &a2pz);
    tree->SetBranchAddress("a2e", &a2e);
    tree->SetBranchAddress("weight", &weight);
    std::ofstream myfile;
    myfile.open("bkg-fv.csv");
    myfile << "b1px,b1py,b1pz,b1e,b2px,b2py,b2pz,b2e,a1px,a1py,a1pz,a1e,a2px,a2py,a2pz,a2e,class,weight" << std::endl;
    for (int i = 0, N = tree->GetEntries(); i < N; ++i) {
        tree->GetEntry(i);
        myfile << b1px << "," << b1py << "," << b1pz << "," << b1e << ",";
        myfile << b2px << "," << b2py << "," << b2pz << "," << b2e << ",";
        myfile << a1px << "," << a1py << "," << a1pz << "," << a1e << ",";
        myfile << a2px << "," << a2py << "," << a2pz << "," << a2e << ",";
        myfile << class << "," << weight << std::endl;
    }
    myfile.close();
}
