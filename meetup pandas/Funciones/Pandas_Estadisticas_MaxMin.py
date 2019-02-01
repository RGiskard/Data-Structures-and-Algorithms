import numpy as np
import pandas as pd

df = pd.DataFrame(np.array([[1, 2, 3], [4, 5, 6], [7, 8, 9]]))

#Valor mas alto de cada columna del DataFrame
print('Valor mas alto de la columna del DataFrame:')
print(df.max())

#Valor minimo de cada columna del DataFrame
print('Valor minimo de la columna del DataFrame:')
print(df.min())


