

struct Data{
  param_t *pt;
  double *r;
  double **rnl;
  Data(int,int);
  ~Data();
};

Data::Data (param_t *pt1){
  pt = pt1;
  int norb = pt->norb;
  int ngrid = pt->ngrid;
  for(int i=0; i<norb; i++){
    rnl[i] = new double[ngrid];
  }

  r = new double[ngrid];
}

Data::~Data(){
  int norb = pt->norb;
  int ngrid = pt->ngrid;
  for(int i=0; i<norb; i++){
    delete rnl[i];
  }
  delete rnl;
  delete r;
}
