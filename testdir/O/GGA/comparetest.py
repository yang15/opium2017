"""
Test the all electron energy for O atom
"""
import sys
import os
import numpy as np
import pytest

tol = 1e-4

eigvalues=[]
filename=open("alleEng")
for line in filename:
    """
    split the file into eigenvalues
    the third column data
    """
   words=line.split()
   eigvalues.append(float(words[2]))
   
filename.close()

"""
Comparison file data 
"""
i=0
compfilename=open("reference/alleEng")
for line in filename:
    """
    split the file into eigenvalues
    the third column data
    """
   words=line.split()
   assert np.allclose(eigvalues[i], float(words[2]), tol)
   i=i+1
   
filename.close()


