# Calculando SST
Y_mean = np.mean(Y)
SST = np.sum((Y - Y_mean)**2)

# Calculando R^2
R_squared = 1 - (residuals_std**2 / SST)

print("Coeficiente de determinação (R^2):", R_squared)
