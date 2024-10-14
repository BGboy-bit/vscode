import numpy as np

def fitness(x):
    return x  2

def select(population, scores):
    total_fitness = sum(scores)
    selection_probs = [score / total_fitness for score in scores]
    selected_indices = np.random.choice(len(population), size=len(population), replace=True, p=selection_probs)
    return population[selected_indices], selected_indices, selection_probs

def crossover(population):
    offspring = np.empty_like(population)
    for i in range(0, len(population), 2):
        if i+1 < len(population):
            # 单点交叉，这里简化为中点交叉
            midpoint = 1  # 每个个体只有一个基因
            offspring[i] = np.concatenate([population[i][:midpoint], population[i+1][midpoint:]])
            offspring[i+1] = np.concatenate([population[i+1][:midpoint], population[i][midpoint:]])
    return offspring

# 参数设定
population = np.array([41, 46, 41, 46]).reshape(-1, 1)
num_generations = 3

# 遗传算法主循环
for generation in range(num_generations):
    print(f"第 {generation + 1} 代")
    fitness_vals = np.array([fitness(ind[0]) for ind in population])
    print(f"适应度值: {fitness_vals}")
    
    new_population, selected_indices, selection_probs = select(population, fitness_vals)
    print(f"选择的索引（从0开始）: {selected_indices}")
    print(f"选择概率: {selection_probs}")
    
    population = crossover(new_population)
    print(f"交叉后的新种群: {population.flatten()}")

# 由于变异率非常低，我们忽略不进行变异的步骤。
