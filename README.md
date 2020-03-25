### bbh-NLO

- Madgraph contains the versions 2.7.2, 2.6.1, 3.0.1 and 3.0.1_4FS
The simulations in the [bbh page](https://cp3.irmp.ucl.ac.be/projects/madgraph/wiki/bbH#no1)
were done with MG5 v2.6.1 in the second rivision corresponding to the numbers in
[arXiv:1409.5301](http://arxiv.org/abs/1409.5301).
  - v2.6.1 (https://bazaar.launchpad.net/~madteam/mg5amcnlo/series2.0/files/275)
  - v2.7.2 (https://launchpad.net/mg5amcnlo/2.0/2.7.x/+download/MG5_aMC_v2.7.2.tar.gz)
  - v3.0.1 (https://bazaar.launchpad.net/~maddevelopers/mg5amcnlo/3.0.1/files)
  - v3.0.1_4FS (https://bazaar.launchpad.net/~maddevelopers/mg5amcnlo/3.0.1_4FS/files)

- fastjet contains fastjet v3.3.3 from the [fastjet website](http://fastjet.fr/)

- bbh contains the code from the [bbh page](https://cp3.irmp.ucl.ac.be/projects/madgraph/wiki/bbH#no1)
corresponding to MG5 v2.6.1

To run the codes:

- untar the MG5
- untar the bbh tarball from the bbh directory
- copy the content of the bbh directory into the MG5 directory
- make sure fast jet is installed or else install it
- make sure LHAPDF is installed or install it. [LHAPDF](https://lhapdf.hepforge.org/downloads/)
- modify Card/amcatnlo_configuration.txt to include the MG5 diretory path at the bottom and the fastjet path
- move into the MG5 directory run ./bin/mg5_aMC to initialize MG5 and then quit it
- run ./bin/generate_events [LO/NLO] to get the LO and NLO respectively.

__NOTE:__ yb^2 works at NLO but ybyt works at LO only for now.
