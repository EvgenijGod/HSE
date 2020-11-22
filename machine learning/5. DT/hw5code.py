import numpy as np
from collections import Counter


def find_best_split(feature_vector, target_vector):
    """
    Под критерием Джини здесь подразумевается следующая функция:
    $$Q(R) = -\frac {|R_l|}{|R|}H(R_l) -\frac {|R_r|}{|R|}H(R_r)$$,
    $R$ — множество объектов, $R_l$ и $R_r$ — объекты, попавшие в левое и правое поддерево,
     $H(R) = 1-p_1^2-p_0^2$, $p_1$, $p_0$ — доля объектов класса 1 и 0 соответственно.

    Указания:
    * Пороги, приводящие к попаданию в одно из поддеревьев пустого множества объектов, не рассматриваются.
    * В качестве порогов, нужно брать среднее двух соседних (при сортировке) значений признака
    * Поведение функции в случае константного признака может быть любым.
    * При одинаковых приростах Джини нужно выбирать минимальный сплит.
    * За наличие в функции циклов балл будет снижен. Векторизуйте! :)

    :param feature_vector: вещественнозначный вектор значений признака
    :param target_vector: вектор классов объектов,  len(feature_vector) == len(target_vector)

    :return thresholds: отсортированный по возрастанию вектор со всеми возможными порогами, по которым объекты можно
     разделить на две различные подвыборки, или поддерева
    :return ginis: вектор со значениями критерия Джини для каждого из порогов в thresholds len(ginis) == len(thresholds)
    :return threshold_best: оптимальный порог (число)
    :return gini_best: оптимальное значение критерия Джини (число)
    """
    l = feature_vector.shape[0]    # number of objects
    feature_vector = np.array(feature_vector)
    target_vector = np.array(target_vector)
    sorted_ft_vals = np.sort(list(set(feature_vector)))
    t = np.array((sorted_ft_vals[:-1] + sorted_ft_vals[1:]) / 2)    # thresholds
    
    len_R_r = np.cumsum(np.unique(feature_vector, return_counts=True)[1])[:-1]    # len = cumulative sums of sorted unique values
    #t_empty = np.where((len_R_r == 0) | (len_R_r == l))    # delete thresholds resulting in empty subtrees
    #np.delete(t, t_empty)
    #np.delete(len_R_r, t_empty)
    
    pos_sorted = np.sort(feature_vector[target_vector == 1])    # sorted values for objects of class 1
    pos_cnt = np.searchsorted(pos_sorted, sorted_ft_vals, side='right') - np.searchsorted(pos_sorted, sorted_ft_vals, side='left') 
    len_R_r_pos = np.cumsum(pos_cnt)[:-1]
    p1_r = len_R_r_pos / len_R_r    # p1
    H_r = 1 - np.power(p1_r, 2) - np.power((1 - p1_r), 2)
    
    len_R_l = l - len_R_r
    len_R_l_pos = np.flip(np.cumsum(np.flip(pos_cnt[1:],0)),0)
    p1_l = len_R_l_pos / len_R_l
    H_l = 1 - np.power(p1_l, 2) - np.power((1 - p1_l), 2)
    
    Q = - len_R_r / l * H_r - len_R_l / l * H_l
    max_idx = np.argmax(Q)    
    best_gini = None
    best_threshold = None
    
    best_gini = Q[max_idx]
    best_threshold = t[max_idx]
    return (t, Q, best_threshold, best_gini)
    pass


class DecisionTree:
    def __init__(self, feature_types, max_depth=None, min_samples_split=None, min_samples_leaf=None):
        if np.any(list(map(lambda x: x != "real" and x != "categorical", feature_types))):
            raise ValueError("There is unknown feature type")

        self._tree = {}
        self._feature_types = feature_types
        self._max_depth = max_depth
        self._min_samples_split = min_samples_split
        self._min_samples_leaf = min_samples_leaf
        self._depth = 0

    def _fit_node(self, sub_X, sub_y, node):
        if np.all(sub_y == sub_y[0]):    # changed != to ==
            node["type"] = "terminal"    # node is terminal when all the objects are in the same class
            node["class"] = sub_y[0]
            return
        if (self._min_samples_split is not None) and (sub_X.shape[0] < self._min_samples_split):    # required number of objects to split
            node["type"] = "terminal"
            node["class"] = Counter(sub_y).most_common(1)[0][0]    # added [0][0]
            return

        feature_best, threshold_best, gini_best, split = None, None, None, None
        for feature in range(sub_X.shape[1]):    # changed (1, sub_X.shape[1])
            feature_type = self._feature_types[feature]
            categories_map = {}

            if feature_type == "real":
                feature_vector = sub_X[:, feature]
            elif feature_type == "categorical":
                counts = Counter(sub_X[:, feature])    # counter for each value
                clicks = Counter(sub_X[sub_y == 1, feature])    # counter for each value for objects of class 1
                ratio = {}
                for key, current_count in counts.items():
                    if key in clicks:
                        current_click = clicks[key]
                    else:
                        current_click = 0
                    ratio[key] = current_click / current_count    # changed from current_count / current_click
                sorted_categories = list(map(lambda x: x[0], sorted(ratio.items(), key=lambda x: x[1])))    # changed first x[1] to x[0]
                categories_map = dict(zip(sorted_categories, list(range(len(sorted_categories)))))    # label encoding of sorted categories

                feature_vector = np.array(list(map(lambda x: categories_map[x], sub_X[:, feature])))    # encode categorical values # added list
            else:
                raise ValueError

            #if len(feature_vector) == 3:
            if np.all(feature_vector == feature_vector[0]):    # changed to check constant feature
                continue

            _, _, threshold, gini = find_best_split(feature_vector, sub_y)
            if gini_best is None or gini > gini_best:
                split = feature_vector < threshold
                if (self._min_samples_leaf is not None) and ((sub_X[split].shape[0] < self._min_samples_leaf) or \
                (sub_X[np.logical_not(split)].shape[0] < self._min_samples_leaf)):     
                    continue
                
                feature_best = feature
                gini_best = gini
                if feature_type == "real":
                    threshold_best = threshold
                elif feature_type == "categorical":    # changed from 'Categorical' to 'categorical'
                    threshold_best = list(map(lambda x: x[0],
                                              filter(lambda x: x[1] < threshold, categories_map.items())))    # get filtered initial categorical values
                else:
                    raise ValueError

        if feature_best is None:
            node["type"] = "terminal"
            node["class"] = Counter(sub_y).most_common(1)[0][0]    # added [0][0]
            return
        
        self._depth += 1    # the vertex is not a leaf, tree's depth increases
        if (self._max_depth is not None) and (self._depth == self._max_depth):    # stop when max depth is reached
            node["type"] = "terminal"
            node["class"] = Counter(sub_y).most_common(1)[0][0]    # added [0][0]
            return
        
        node["type"] = "nonterminal"

        node["feature_split"] = feature_best
        if self._feature_types[feature_best] == "real":
            node["threshold"] = threshold_best
        elif self._feature_types[feature_best] == "categorical":
            node["categories_split"] = threshold_best
        else:
            raise ValueError
        node["left_child"], node["right_child"] = {}, {}
        self._fit_node(sub_X[split], sub_y[split], node["left_child"])
        self._fit_node(sub_X[np.logical_not(split)], sub_y[np.logical_not(split)], node["right_child"])    # added np.logical_not in sub_y
        
    def _predict_node(self, x, node):
        if node["type"] == "terminal":
            return node["class"]
        if "threshold" in node:
            if x[node["feature_split"]] >= node["threshold"]:
                return self._predict_node(x, node["right_child"])
            return self._predict_node(x, node["left_child"])
        if "categories_split" in node:
            if x[node["feature_split"]] not in node["categories_split"]:
                return self._predict_node(x, node["right_child"])
            return self._predict_node(x, node["left_child"])
        pass

    def fit(self, X, y):
        self._fit_node(X, y, self._tree)

    def predict(self, X):
        predicted = []
        for x in X:
            predicted.append(self._predict_node(x, self._tree))
        return np.array(predicted)
    
    def get_params(self, deep=False):
        return {#'tree':self._tree, 
                'feature_types':self._feature_types,
                'max_depth':self._max_depth,
                'min_samples_split':self._min_samples_split, 
                'min_samples_leaf':self._min_samples_leaf}