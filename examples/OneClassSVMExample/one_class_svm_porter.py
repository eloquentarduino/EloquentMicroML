import numpy as np
from sklearn import svm
from micromlgen import port, port_testset


xx, yy = np.meshgrid(np.linspace(-5, 5, 500), np.linspace(-5, 5, 500))
# Generate train data
X = 0.3 * np.random.randn(100, 2)
X_train = np.r_[X + 2, X - 2]
# Generate some regular novel observations
X = 0.3 * np.random.randn(20, 2)
X_test = np.r_[X + 2, X - 2]
# Generate some abnormal novel observations
X_outliers = np.random.uniform(low=-4, high=4, size=(20, 2))

# fit the model
clf = svm.OneClassSVM(kernel="rbf", nu=0.5, gamma=0.1)
clf.fit(X_train)
print(port(clf))
print(port_testset(X_test, np.where(clf.predict(X_test) > 0, 1, 0)))
print(clf.predict(X_test))