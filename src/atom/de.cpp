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

void de(double &y, double &x, double &p){
  //in : y,x
  //out: p
}
