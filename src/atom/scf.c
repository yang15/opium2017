
#include "parameter.h"

void scf(params_t *param){

  int norb = param->norb;
  int ngrid = param->ngrid;
  double *wnl = param->wnl;

  //Initialize energy matrix
  double **e;
  e = (double **)malloc(norb*sizeof(double *));
  for(int i=0; i<norb; i++){
    e[i] = (double *)malloc(norb*sizeof(double));
  }

  for(int j=0; j<norb; j++){
    for(int jj=0; jj<norb; j++){
      e[jj][j] = 0.0;
      if (lo[j]==lo[jj]) e[jj][j]=1.0e-5;
    }
    e[j][j] = param->en[j];
  }


  //initialize misc variables
  double *dpm;
  dpm = (double *)malloc(norb*sizeof(double));
  double *acc;
  acc = (double *)malloc(norb*sizeof(double));
  int *nmax;
  nmax = (int *)malloc(norb*sizeof(int));
  for(int i=0; i<norb; i++){
    nmax[i] = param->np;
    dpm[i] = 0.0;
    acc[i] = 0.0;
  }


  //initialize screening parameter
  //assuming no core
  double *s;
  s = (double *)malloc(norb*sizeof(double));
  double ss = 0.0;
  for(int i=0; i<norb; i++){
    s[i]=ss+(wnl[i]-1.0)/2;
    ss=ss+wnl[i];
  }


  //initialize wavefunctions
  double **rnl;
  rnl = (double **)malloc(norb*sizeof(double *));
  for(int i=0; i<norb; i++){
    rnl[i] = (double *)malloc(ngrid*sizeof(double));
  }

  //az is asymtotic bahavior as r->0
  double *az;
  az = (double *)malloc(ngrid*sizeof(double));

  //initialize to appropriately screened hydrogenic wfns
  for(int i=0; i<norb; i++){
    double z_s = z-s[i];
    double pnf=hnorm_(&no+i,&lo+i,&z_s);
    for(int k=0; k<np; k++){
      rnl[i][k]=pnf*hwf_(&no+i,&lo+i,&z_s,&r+k)/sqrt(r[k]);
    }
    az[i]=pnf* pow(2.0*(z-s[i]/2)/no[i] , (lo[i]+1.0) );
  }
  

  //this looks like rotating the initial wfns
  for(int i=0; i<norb; i++){
    if (no[i]==0 && lo[i]==0){
      continue;
    }
    for(int j=0; j<i; j++){
      if (e[j][i] > 0.0) {
        int k0 = 0;
        double rx= quadr_(&i,&j,&k0,&(param->h),param->r,rnl[i],rnl[j],az,lo,nmax);
        if (abs(rx) > 1.0e-8){
          double rx2=sqrt(1.0-pow(rx,2));
          if (rnl[i][50]-rx*rnl[j][50] < 0.0) rx2 = -rx2;
          for(int k=0; k<np; k++){
            rnl[i][k]= (rnl[i][k]-rx*rnl[j][k])/rx2;
          }
        }
      }
    }
  }

  //begin SCF loop
  //
  for (int niter=0; niter < param->maxit; niter++){
  }

  //end SCF loop

}
