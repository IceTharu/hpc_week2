#!/usr/bin/env python
import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

file = '/zhome/2e/9/124284/Documents/Vika 2/Verkefni/2. OpenMP/hpc_week2/help.csv'

A = np.flipud(np.loadtxt(file))


#def surface_plot (matrix, **kwargs):
    # acquire the cartesian coordinate matrices from the matrix
    # x is cols, y is rows
    #(x, y) = np.meshgrid(np.arange(matrix.shape[0]), np.arange(matrix.shape[1]))
    #fig = plt.figure()
    #ax = fig.add_subplot(111, projection='3d')
    #surf = ax.plot_surface(x, y, matrix, **kwargs)
    #return (fig, ax, surf)

plt.imshow(A,cmap='hot',vmin=0,vmax=25)
plt.colorbar()
plt.show()
line = A[:,150]
plt.figure()
plt.plot(line)
