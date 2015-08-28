
struct params_t{
  //grid
  double h;
  int npdm;
  double * r;

  //orbitals
  int n0; //number of orbitals
  double * wnl; //occupation number of orbitals
  int * no; //n-quantum number of orbitals 
  int *lo; //l-quantum number of orbitals 

  //convergence 
  int numscf; //maximum number of scf steps
  double scftol;//convergence threshold

  
  //functional
  // -1 : Hartree Fock
  // 2  : PBE GGA 96
  // 7  : PBE0 hybrid functional
  int ixc;



};
