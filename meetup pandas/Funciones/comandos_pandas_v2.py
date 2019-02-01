# -*- coding: utf-8 -*-
"""
Created on Fri Feb  1 07:45:15 2019

@author: PAULA
"""

import numpy as np
import pandas as pd


##########################
# Funciones de selección #
##########################

print('##########################')
print('# Funciones de selección #')
print('##########################')
      
      
df = pd.DataFrame(np.array([[1,2,3],[4,5,6],[7,8,9]]))
print('DataFrame: ')
print(df)
print('____________________________')
      
#seleccionar la primera columna del DataFrame
print('Primera columna del DataFrame: ')
print(df[0])
print('____________________________')

#seleccionar dos columnas del DataFrame
print('Dos columnas del DataFrame: ')
print(df[[0,1]])
print('____________________________')

#Un valor de la primera fila y ultima columna del DataFrame
print('Valor indicando los índices del DataFrame: ')
print(df.iloc[0][2])
print('____________________________')

#Usar indices del dataframe para seleccionar sus datos, 
#valores de la primera fila del dataframe
print('Valores de la primera fila con loc: ')
print(df.loc[0])
print('____________________________')
print('Valores de la primera fila con iloc: ')
print(df.iloc[0,:])

##########################
# Funciones de limpieza  #
##########################

print('\n')
print('##########################')
print('# Funciones de limpieza  #')
print('##########################')
      
      
df2 = pd.DataFrame({'age': [5, 6, np.NaN],
                    'born': [pd.NaT, pd.Timestamp('1939-05-27'),
                             pd.Timestamp('1940-04-25')],
                    'name': ['Alfred', 'Batman', ''],
                    'toy': [None, 'Batmobile', 'Joker']})
print('DataFrame2: ')
print(df2)
print('____________________________')

#Limpiar datos, si queremos obtener resultados confiables
#verificar si faltan valores en el conjunto de datos
#verdadero para valores faltantes y falso para valores no perdidos
print('Verificar si faltan valores en el conjunto de datos: ')
print(df2.isnull())
print('____________________________')

#Eliminar datos nulos
print('Eliminar columnas, filas de datos nulos: ')
print(df2.dropna())
print('____________________________')

df3 = pd.DataFrame(np.array([[1,np.NaN,3],[4,5,np.NaN],[7,np.NaN,9], [4, np.NaN, 0]]))
print('DataFrame3: ')
print(df3)
print('____________________________')

#suma de datos nulos
print('Suma de datos nulos: ')
print(df3.isnull().sum())
print('____________________________')

#Rellenar los datos nulos con algun valor x
print('Rellenar con algun valor x: ')
print(df3.fillna(0))
print('____________________________')



