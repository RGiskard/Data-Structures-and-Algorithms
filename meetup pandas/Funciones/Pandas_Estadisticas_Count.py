import numpy as np
import pandas as pd

df = pd.DataFrame(np.array([[1, 2, 3], [4, 5, 6], [7, 8, 9]]))

#Cuenta los datos del DataFrame
print('Conteo de datos del DataFrame:')
print(df.count())


