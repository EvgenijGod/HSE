from __future__ import annotations

import numpy as np
import random
from scipy.sparse import issparse

s0_default: float = 1
p_default: float = 0.5

batch_size_default: int = 1

alpha_default: float = 0.1
eps_default: float = 1e-8

mu_default = 1e-2

tolerance_default: float = 1e-3
max_iter_default: int = 1000


class BaseDescent:
    """
    A base class and examples for all functions
    """

    def __init__(self):
        self.w = None

    def step(self, X: np.ndarray, y: np.ndarray, iteration: int) -> np.ndarray:
        """
        Descent step
        :param iteration: iteration number
        :param X: objects' features
        :param y: objects' targets
        :return: difference between weights
        """
        #print('In step', iteration)
        return self.update_weights(self.calc_gradient(X, y), iteration)

    def update_weights(self, gradient: np.ndarray, iteration: int) -> np.ndarray:
        """
        Example for update_weights function
        :param iteration: iteration number
        :param gradient: gradient
        :return: weight difference: np.ndarray
        """
        pass

    def calc_gradient(self, X: np.ndarray, y: np.ndarray) -> np.ndarray:
        """
        Example for calc_gradient function
        :param X: objects' features
        :param y: objects' targets
        :return: gradient: np.ndarray
        """
        pass


class GradientDescent(BaseDescent):
    """
    Full gradient descent class
    """

    def __init__(self, w0: np.ndarray, lambda_: float, s0: float = s0_default, p: float = p_default):
        """
        :param w0: weight initialization
        :param lambda_: learning rate parameter (float)
        :param s0: learning rate parameter (float)
        :param p: learning rate parameter (float)
        """
        super().__init__()
        self.eta = lambda k: lambda_ * (s0 / (s0 + k)) ** p
        self.w = np.copy(w0)

    def update_weights(self, gradient: np.ndarray, iteration: int) -> np.ndarray:
        """
        Changing weights with respect to gradient
        :param iteration: iteration number
        :param gradient: gradient
        :return: weight difference: np.ndarray
        """
        # TODO: implement updating weights function
        self.w -= self.eta(iteration) * gradient
        return self.eta(iteration) * gradient
        raise NotImplementedError('GradientDescent update_weights function not implemented')

    def calc_gradient(self, X: np.ndarray, y: np.ndarray) -> np.ndarray:
        """
        Getting objects, calculating gradient at point w
        :param X: objects' features
        :param y: objects' targets
        :return: gradient: np.ndarray
        """
        # TODO: implement calculating gradient function
        return (X.dot(self.w) - y).dot(X) * 2 / X.shape[0]
        raise NotImplementedError('GradientDescent calc_gradient function not implemented')


class StochasticDescent(BaseDescent):
    """
    Stochastic gradient descent class
    """

    def __init__(self, w0: np.ndarray, lambda_: float, s0: float = s0_default, p: float = p_default,
                 batch_size: int = batch_size_default):
        """
        :param w0: weight initialization
        :param lambda_: learning rate parameter (float)
        :param s0: learning rate parameter (float)
        :param p: learning rate parameter (float)
        :param batch_size: batch size (int)
        """
        super().__init__()
        self.eta = lambda k: lambda_ * (s0 / (s0 + k)) ** p
        self.batch_size = batch_size
        self.w = np.copy(w0)

    def update_weights(self, gradient: np.ndarray, iteration: int) -> np.ndarray:
        """
        Changing weights with respect to gradient
        :param iteration: iteration number
        :param gradient: gradient estimate
        :return: weight difference: np.ndarray
        """
        # TODO: implement updating weights function
        self.w -= self.eta(iteration) * gradient
        return self.eta(iteration) * gradient
        raise NotImplementedError('StochasticDescent update_weights function not implemented')

    def calc_gradient(self, X: np.ndarray, y: np.ndarray) -> np.ndarray:
        """
        Getting objects, calculating gradient at point w
        :param X: objects' features
        :param y: objects' targets
        :return: gradient: np.ndarray
        """
        # TODO: implement calculating gradient function
        l = X.shape[0]
        new_q = np.zeros(self.w.shape[0])
        idx = random.sample(range(0, l), self.batch_size)    # get batch_size number of unique indexes
        for i in range(self.batch_size):
            ik = idx[i]
            new_q += (X[ik,:].dot(self.w) - y[ik]) * X[ik,:]
        return new_q * 2 / self.batch_size 
        raise NotImplementedError('StochasticDescent calc_gradient function not implemented')


class MomentumDescent(BaseDescent):
    """
    Momentum gradient descent class
    """

    def __init__(self, w0: np.ndarray, lambda_: float, alpha: float = alpha_default, s0: float = s0_default,
                 p: float = p_default):
        """
        :param w0: weight initialization
        :param lambda_: learning rate parameter (float)
        :param alpha: momentum coefficient
        :param s0: learning rate parameter (float)
        :param p: learning rate parameter (float)
        """
        super().__init__()
        self.eta = lambda k: lambda_ * (s0 / (s0 + k)) ** p
        self.alpha = alpha
        self.w = np.copy(w0)
        self.h = 0

    def update_weights(self, gradient: np.ndarray, iteration: int) -> np.ndarray:
        """
        Changing weights with respect to gradient
        :param iteration: iteration number
        :param gradient: gradient estimate
        :return: weight difference: np.ndarray
        """
        # TODO: implement updating weights function
        self.h = self.alpha * self.h + self.eta(iteration) * gradient
        self.w -= self.h
        return self.h
        raise NotImplementedError('MomentumDescent update_weights function not implemented')

    def calc_gradient(self, X: np.ndarray, y: np.ndarray) -> np.ndarray:
        """
        Getting objects, calculating gradient at point w
        :param X: objects' features
        :param y: objects' targets
        :return: gradient: np.ndarray
        """
        # TODO: implement calculating gradient function
        l = X.shape[0]
        return ((X.dot(self.w) - y).dot(X)).flatten() * 2 / l
        raise NotImplementedError('MomentumDescent calc_gradient function not implemented')


class Adagrad(BaseDescent):
    """
    Adaptive gradient algorithm class
    """

    def __init__(self, w0: np.ndarray, lambda_: float, eps: float = eps_default, s0: float = s0_default,
                 p: float = p_default):
        """
        :param w0: weight initialization
        :param lambda_: learning rate parameter (float)
        :param eps: smoothing term (float)
        :param s0: learning rate parameter (float)
        :param p: learning rate parameter (float)
        """
        super().__init__()
        self.eta = lambda k: lambda_ * (s0 / (s0 + k)) ** p
        self.eps = eps
        self.w = np.copy(w0)
        self.g = 0

    def update_weights(self, gradient: np.ndarray, iteration: int) -> np.ndarray:
        """
        Changing weights with respect to gradient
        :param iteration: iteration number
        :param gradient: gradient estimate
        :return: weight difference: np.ndarray
        """
        # TODO: implement updating weights function
        self.g += np.power(gradient, 2)
        self.w -= self.eta(iteration) / np.sqrt(self.g + self.eps) * gradient
        return self.eta(iteration) / np.sqrt(self.g + self.eps) * gradient
        raise NotImplementedError('Adagrad update_weights function not implemented')

    def calc_gradient(self, X: np.ndarray, y: np.ndarray) -> np.ndarray:
        """
        Getting objects, calculating gradient at point w
        :param X: objects' features
        :param y: objects' targets
        :return: gradient: np.ndarray
        """
        # TODO: implement calculating gradient function
        l = X.shape[0]
        return (X.dot(self.w) - y).dot(X) * 2 / l
        raise NotImplementedError('Adagrad calc_gradient function not implemented')


class GradientDescentReg(GradientDescent):
    """
    Full gradient descent with regularization class
    """

    def __init__(self, w0: np.ndarray, lambda_: float, mu: float = mu_default, s0: float = s0_default,
                 p: float = p_default):
        """
        :param mu: l2 coefficient
        """
        super().__init__(w0=w0, lambda_=lambda_, s0=s0, p=p)
        self.mu = mu

    def update_weights(self, gradient: np.ndarray, iteration: int) -> np.ndarray:
        return super().update_weights(gradient, iteration)

    def calc_gradient(self, X: np.ndarray, y: np.ndarray) -> np.ndarray:
        l2 = np.linalg.norm(self.w) / 2
        return super().calc_gradient(X, y) + l2 * self.mu


class StochasticDescentReg(StochasticDescent):
    """
    Stochastic gradient descent with regularization class
    """

    def __init__(self, w0: np.ndarray, lambda_: float, mu: float = mu_default, s0: float = s0_default,
                 p: float = p_default, batch_size: int = batch_size_default):
        """
        :param mu: l2 coefficient
        """
        super().__init__(w0=w0, lambda_=lambda_, s0=s0, p=p, batch_size=batch_size)
        self.mu = mu

    def update_weights(self, gradient: np.ndarray, iteration: int) -> np.ndarray:
        return super().update_weights(gradient, iteration)

    def calc_gradient(self, X: np.ndarray, y: np.ndarray) -> np.ndarray:
        l2 = np.linalg.norm(self.w) / 2
        return super().calc_gradient(X, y) + l2 * self.mu


class MomentumDescentReg(MomentumDescent):
    """
    Momentum gradient descent with regularization class
    """

    def __init__(self, w0: np.ndarray, lambda_: float, alpha: float = alpha_default, mu: float = mu_default,
                 s0: float = s0_default, p: float = p_default):
        """
        :param mu: l2 coefficient
        """
        super().__init__(w0=w0, lambda_=lambda_, alpha=alpha, s0=s0, p=p)
        self.mu = mu

    def update_weights(self, gradient: np.ndarray, iteration: int) -> np.ndarray:
        return super().update_weights(gradient, iteration)

    def calc_gradient(self, X: np.ndarray, y: np.ndarray) -> np.ndarray:
        l2 = np.linalg.norm(self.w) / 2
        return super().calc_gradient(X, y) + l2 * self.mu


class AdagradReg(Adagrad):
    """
    Adaptive gradient algorithm with regularization class
    """

    def __init__(self, w0: np.ndarray, lambda_: float, eps: float = eps_default, mu: float = mu_default,
                 s0: float = s0_default, p: float = p_default):
        """
        :param mu: l2 coefficient
        """
        super().__init__(w0=w0, lambda_=lambda_, eps=eps, s0=s0, p=p)
        self.mu = mu

    def update_weights(self, gradient: np.ndarray, iteration: int) -> np.ndarray:
        return super().update_weights(gradient, iteration)

    def calc_gradient(self, X: np.ndarray, y: np.ndarray) -> np.ndarray:
        l2 = np.linalg.norm(self.w) / 2
        return super().calc_gradient(X, y) + l2 * self.mu


class LinearRegression:
    """
    Linear regression class
    """

    def __init__(self, descent, tolerance: float = tolerance_default, max_iter: int = max_iter_default):
        """
        :param descent: Descent class
        :param tolerance: float stopping criterion for square of euclidean norm of weight difference
        :param max_iter: int stopping criterion for iterations
        """
        self.descent = descent
        self.tolerance = tolerance
        self.max_iter = max_iter
        self.loss_history = []

    def fit(self, X: np.ndarray, y: np.ndarray) -> LinearRegression:
        """
        Getting objects, fitting descent weights
        :param X: objects' features
        :param y: objects' target
        :return: self
        """
        # TODO: fit weights to X and y
        iter = 0
        if issparse(X):
            X = X.toarray()
        if (self.descent.w == None).all():
            self.descent.w = np.zeros(X.shape[1])
        l2_diff = self.tolerance * 10
        while (iter < self.max_iter) and (l2_diff >= self.tolerance):
            self.calc_loss(X, y)
            diff = self.descent.step(X, y, iter)
            l2_diff = np.sum(np.power(diff, 2))
            iter += 1
        return self
        
        raise NotImplementedError('LinearRegression fit function not implemented')

    def predict(self, X: np.ndarray) -> np.ndarray:
        """
        Getting objects, predicting targets
        :param X: objects' features
        :return: predicted targets
        """
        # TODO: calculate prediction for X
        return X.dot(self.descent.w)
        raise NotImplementedError('LinearRegression predict function not implemented')

    def calc_loss(self, X: np.ndarray, y: np.ndarray) -> None:
        """
        Getting objects, calculating loss
        :param X: objects' features
        :param y: objects' target
        """
        # TODO: calculate loss and save it to loss_history
        l = X.shape[0]
        loss = np.sum(np.power((X.dot(self.descent.w) - y), 2)) / l
        self.loss_history.append(loss)
        return
        raise NotImplementedError('LinearRegression calc_loss function not implemented')


###########################################################
####################### BONUS TASK ########################
###########################################################


class StochasticAverageGradient(BaseDescent):
    """
    Stochastic average gradient class (BONUS TASK)
    """

    def __init__(self, w0: np.ndarray, lambda_: float, x_shape: int, s0: float = s0_default, p: float = p_default):
        """
        :param w0: weight initialization
        :param lambda_: learning rate parameter (float)
        :param s0: learning rate parameter (float)
        :param p: learning rate parameter (float)
        """
        super().__init__()
        self.eta = lambda k: lambda_ * (s0 / (s0 + k)) ** p
        self.w = np.copy(w0)
        self.v = np.zeros((x_shape, w0.shape[0]))
        self.d = 0

    def update_weights(self, gradient: np.ndarray, iteration: int) -> np.ndarray:
        """
        Changing weights with respect to gradient
        :param iteration: iteration number
        :param gradient: gradient
        :return: weight difference: np.ndarray
        """
        # TODO: implement updating weights function
        self.w -= self.eta(iteration) * gradient
        return self.eta(iteration) * gradient
        raise NotImplementedError('GradientDescent update_weights function not implemented')

    def calc_gradient(self, X: np.ndarray, y: np.ndarray) -> np.ndarray:
        """
        Getting objects, calculating gradient at point w
        :param X: objects' features
        :param y: objects' targets
        :return: gradient: np.ndarray
        """
        # TODO: implement calculating gradient function
        l = X.shape[0]
        ik = random.choice(range(l))
        new_q = (X[ik,:].dot(self.w) - y[ik]) * X[ik,:] * 2
        self.d -= (self.v[ik,:] - new_q)
        self.v[ik,:] = new_q
        return self.d / l
        raise NotImplementedError('GradientDescent calc_gradient function not implemented')

###########################################################
####################### BONUS TASK ########################
###########################################################
