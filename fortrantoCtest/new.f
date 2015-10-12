      MODULE EXAMP
      use iso_c_binding
         REAL(kind=c_float),bind(c) :: A(3)
         INTEGER :: I1, I2
         CHARACTER(80) ::  LINE

         TYPE MYDATA
             SEQUENCE
             INTEGER :: N 
             CHARACTER(len=30) :: INFO
          END TYPE MYDATA
      END MODULE EXAMP
