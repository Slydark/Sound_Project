import matplotlib.pyplot as plt
import numpy as np

x,y= np.loadtxt('CSVData.csv', delimiter=',', unpack=True)


plt.plot(x,y)

plt.title('Data from the CSV File: frequencies and magnitudes')

plt.xlabel('frequencies')
plt.ylabel('magnitudes')

plt.show()