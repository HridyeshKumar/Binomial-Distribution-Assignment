import numpy as np
import tensorflow as tf
import matplotlib.pyplot as plt
np.set_printoptions(suppress=True)
x=tf.linspace(-10,10,100)
y=tf.keras.activation.elu(x)
alpha=1
y2=tf.where(x>0,x,alpha*(tf.exp(x)-1))
plt.plot(x,y)
plt.plot(x,y2)
plt.grid()
plt.show()
