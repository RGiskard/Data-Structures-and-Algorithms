import numpy as np
import pandas as pd

df = pd.DataFrame(np.array([[1, 2, 3], [4, 5, 6], [7, 8, 9]]))

#Media de las columnas DataFrame
print('Media de las columnas DataFrame:')
print(df.mean())


