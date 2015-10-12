      MODULE EXAMP
      use iso_c_binding
         REAL(kind=c_float),bind(c) :: A(3)
         INTEGER,bind(c) :: I1, I2
         CHARACTER(80) ::  LINE
         type,bind(c) :: mytype
              integer(kind=c_int) :: x
              real(kind=c_float) :: y(3)
         end type mytype
      END MODULE EXAMP
