import numpy as np
import pandas as pd

df = pd.DataFrame(np.array([[1, 2, 3], [4, 5, 6], [7, 8, 9]]))

#Mediana de cada columna del DataFrame
print('Mediana de la columna del DataFrame:')
print(df.median())

#Desviacion estandar de cada columna del DataFrame
print('Desviacion estandar de la columna del DataFrame:')
print(df.std())


