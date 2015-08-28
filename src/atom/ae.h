
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

struct Wfns{
  int n0;
  int npdm;
  double **rnl;
  Wfns(int,int);
  ~Wfns();
};

Wfns::Wfns (int a,int b){
  n0 = a;
  npdm = b;
  rnl = new double*[n0];
  for(int i=0; i<n0; i++){
    rnl[i] = new double[npdm];
  }
}

Wfns::~Wfns(){
  for(int i=0; o<n0; i++){
    delete rnl[i];
  }
  delete rnl;
}
