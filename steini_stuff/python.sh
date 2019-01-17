python

import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

file = '/zhome/2e/9/124284/Documents/Vika 2/Verkefni/2. OpenMP/hpc_week2/daemi.csv'

A = np.flipud(np.loadtxt(file))

#def surface_plot(matrix, **kwargs):
