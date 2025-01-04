import numpy as np 
from matplotlib import pyplot
def relu(x):
  return np.maximum(0,x)
series_in=[x for x in range(-10,11)]
series_out=[relu(x) for x in series_in]
pyplot.plot(series_in,series_out)
pyplot.show()
