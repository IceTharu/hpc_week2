#!/usr/bin/env python
import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

file = '/zhome/45/0/97860/Documents/HPC/Assignment2/hpc_week2/omp13.csv'

A = np.flipud(np.loadtxt(file))


plt.imshow(A,cmap='hot',vmin=0,vmax=50)
plt.colorbar()

line = A[:,500]
plt.figure()
plt.plot(line)
