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
void quad_(int *i, int *m, double *yr, double *x);
	}	

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

  bool first = true;
  bool fail = false;
  bool ilast = true;
  double d0=0.0;
  double d1=1.0;
  double d2=2.0;
  double d5=0.5;

  int ind[norb];
  int m, node, mk, kk, nj;
  m = l;
  // m is the angular quantum number for each orbital
  // kk is imeth or meth(m)
  double p2[ngrid], hq[ngrid], xx[ngrid];
  double v, b4, cn, c, xy, xp, azz, pp, fn, em, fm, eu,fu, delta_e;

   double ed2 = e;
   if (norb == 1){kk = 2;} 
   int node = n - m - 1; 
// local variables
   int i, j, nn, ij, jj;
   double ed2, pn , ed1, cd, dp, diff, dpw, pnn;
   bool change;

// call method1 to solve the differential equation
//
    method1(params, y, x, t, e, l, p,m, azz, fail,iprint);
    if (fail) {
        // go to 25
    }

    double pn = sqrt(quad_(&i,&m,p, p));
    for (int i_p=0; i_p < ngrid; i_p++){
        p[i_p] = p[i_p] / pn;
    }
    azz = azz/pnn;

// check if different method should be used
//
    if (kk==1){
        if ( (abs(1.0-ed2/e) < 0.005) && max(abs(d1-pn),abs(d1/pn - d1))) {
            kk = 2;
            // go to 25
        } else {
            if ( (abs(d1-ed2/e) < 0.0001) && (ic > 1)) {
                ic = ic - 1;
            }
        }
// set the accelerating parameter
// acc[norb] is the accelerating parameter in method2 alpha_i P289
    if (ipr != m) {
        acc[m] = 0.75 * acc[m];
    } else {
        ed2 = ed2 - e;
        if (ed1 * ed2 > d0) {
            acc[m] = 0.75 * acc[m];
        } else {
            acc[m] = (d1 + d3*acc[m])/d4;
        }
    }
    c = acc[m];
    cd = d1 - c;
// in our code but not in the original code
    if (acc[m] > 0.99999) {
        acc[m] = 0.5;
    }
// Improve the estimates
//
    dp = d0;
    for (int i_estm=1; i_estm<=m; i_estm++ ){
        diff = p(i_estm) - pde(i_estm);
        dp = max(dp, abs(diff)*(r2(i_estm)));
        p(i_estm) = pde(i_estm) + c * diff;
    }
    if (m != ngrid) {
        m = m + 1;
        p

    
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
	double *yr;
  	yr = (double *)malloc(ngrid*sizeof(double));
	yr = y;

	double *x;
  	x = (double *)malloc(ngrid*sizeof(double));
	if (first) {
		potl_(yr, &i);
		xch_(x, &i, 3);
        	
        	double zinf = max(0.05, z-yr)
