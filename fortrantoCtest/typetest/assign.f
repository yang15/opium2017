      module ass
      USE ISO_C_BINDING
      TYPE, BIND(C) :: myType
              INTEGER(C_INT) :: i1, i2
              INTEGER(C_SIGNED_CHAR) :: i3
              REAL(C_DOUBLE) :: d1
              COMPLEX(C_FLOAT_COMPLEX) :: c1
              CHARACTER(KIND=C_CHAR) :: str(5)
      END TYPE
      TYPE :: localmyType
              INTEGER(C_INT) :: i1, i2
              INTEGER(C_SIGNED_CHAR) :: i3
              REAL(C_DOUBLE) :: d1
              COMPLEX(C_FLOAT_COMPLEX) :: c1
              CHARACTER(KIND=C_CHAR) :: str(5)
      END TYPE
      TYPE :: mt
              SEQUENCE
              INTEGER(C_INT) :: i1, i2
              INTEGER(C_SIGNED_CHAR) :: i3
              REAL(C_DOUBLE) :: d1
              COMPLEX(C_FLOAT_COMPLEX) :: c1
              CHARACTER(KIND=C_CHAR) :: str(5)
      END TYPE
      end module