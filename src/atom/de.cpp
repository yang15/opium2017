#include "parameter.h"

/* Differential equation solver goes here
   This should solve the differential equation
      P" + ( 2Z/R - Y - L(L+1)/R**2 - E)P = X + T

     where Y is called a potential function
           X is called an exchange function, and
           T includes contributions from off-diagonal energy parameter

     The program uses LOG(Z*R) as independent variable and
                      P/SQRT(R) as dependent variable.
     As a result all equations must be transformed as described in
     Sec. 6-2 and 6-4 of the book - ``The Hartree-Fock Method for
     Atoms'',Wiley Interscience, 1977, by Charlotte FROESE FISCHER.
*/

extern"C"{
void potl_(double *yr, int *i);
void xch_(double *x, int *i, int *iopt);
void ykf_(double *yk, int *rnli, int *rnlj, int *i, int *j, int *k, double *h, doub *z, double *r, int *lo, int *nmax);
void zkf_(double *yk, int *rnli, int *rnlj, int *i, int *j, int *k, double *h, double *z, double *r, int *np, int *lo, int *nmax);
	}	

<<<<<<< Updated upstream
void de(params_t *params, double *y, double *x,double *t, double e, int l, double *p){
  //in : y,x,t
  //out: p
  // apply Method1 in Chapter7 of the book "The Hartree-Fock meth for atoms"
=======
void de(params_t *params, double *y, double *x,double *t, double e,int n, int l, double *p){
  //in : y, x is the exchange, t is grange
  //out: p stores the solved eigenvector
  //control the solution of the differential equation 
  // e is the orbital energy passing from scf.c <=> E(I,I) 
  // n is the principle quantum number
  // l is the angular momentum nubmer
  // apply Method1 in Chapter7 of the book "The Hartree-Fock meth for atoms"
  int norb = params->norb;
  int ngrid = params->ngrid;
  e =  new double *[norb];
  for (int i_norb = 0; i_norb < norb; i_norb++){
	  e[i_norb] = new double [norb];
  }

  e = params->etrial;
>>>>>>> Stashed changes
  bool first = true;
  bool fail = false;
  double d0=0.0;
  double d2=2.0;
  double d5=0.5;
<<<<<<< Updated upstream

  
    
}


int method1(params_t *params, double *y, double *x,double *t, double e, int l, double *p){
	//initial guess of the eigenvalue of based on the hydrogenic wavefunction
	double zval = params->z
	double em = d0;
	double eu = e;   // eigenvalue initial guess
	double fu = eu;
	int mk = 0;
	solve

}


double solve(params_t *params, int i, bool first, bool rel){
  	int norb = param->norb;
	int ngrid = param->ngrid;
	double *wnl = param->wnl;
=======
  
  int i = i1; // i is the index of orbitals
  double ed2 = e;
  if (nwf == 1){kk = 2;}
  node = n

  
    
}


int method1(params_t *params, double *y, double *x,double *t, double e, int l, double *p){
	//initial guess of the eigenvalue of based on the hydrogenic wavefunction
	double zval = params->z
	double em = d0;
	double eu = e;   // eigenvalue initial guess
	double fu = eu;
	int mk = 0;
	solve

}


double solve(params_t *params, int i, bool first, bool rel){
  	int norb = params->norb;
	int ngrid = params->ngrid;
	double *wnl = params->wnl;
	double z = params->z;
>>>>>>> Stashed changes
	double *yr;
  	yr = (double *)malloc(ngrid*sizeof(double));
	yr = y;

	double *x;
  	x = (double *)malloc(ngrid*sizeof(double));
	if (first) {
		potl_(yr, &i);
		xch_(x, &i, 3);
<<<<<<< Updated upstream
        	
=======
        	double zinf = max(0.05, z-yr)
>>>>>>> Stashed changes
