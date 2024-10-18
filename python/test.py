import numpy as np

# 遗传算法参数
POPULATION_SIZE = 50   # 种群规模
GENE_LENGTH = 100      # 每个个体的基因长度（100个二进制变量）
CROSSOVER_RATE = 0.8   # 交叉概率
MUTATION_RATE = 0.01   # 变异概率
GENERATIONS = 100      # 进化代数

# 目标函数：计算个体的目标值 f(x) = sum(x)
def objective_function(individual):
    return np.sum(individual)

# 适应度函数：将目标函数转换为适应度（越小越好）
def fitness(individual):
    # 使用负的目标函数值，因为我们需要最小化 sum(x)
    return -objective_function(individual)

# 初始化种群：随机生成种群，每个个体是二进制数组
def initialize_population():
    return np.random.randint(2, size=(POPULATION_SIZE, GENE_LENGTH))

# 选择操作：轮盘赌选择（适应度越高被选中的概率越大）
def select(population):
    fitness_values = np.array([fitness(ind) for ind in population])
    probabilities = fitness_values / np.sum(fitness_values)
    selected_index = np.random.choice(range(POPULATION_SIZE), size=POPULATION_SIZE, p=probabilities)
    return population[selected_index]

# 交叉操作：单点交叉
def crossover(parent1, parent2):
    if np.random.rand() < CROSSOVER_RATE:
        point = np.random.randint(1, GENE_LENGTH - 1)
        child1 = np.concatenate((parent1[:point], parent2[point:]))
        child2 = np.concatenate((parent2[:point], parent1[point:]))
        return child1, child2
    else:
        return parent1, parent2

# 变异操作：以一定概率变异个体中的某个位
def mutate(individual):
    for i in range(GENE_LENGTH):
        if np.random.rand() < MUTATION_RATE:
            individual[i] = 1 - individual[i]  # 0变1, 1变0
    return individual

# 遗传算法主过程
def genetic_algorithm():
    population = initialize_population()

    for generation in range(GENERATIONS):
        population = select(population)  # 选择操作
        new_population = []

        # 交叉操作和生成新种群
        for i in range(0, POPULATION_SIZE, 2):
            parent1, parent2 = population[i], population[i + 1]
            child1, child2 = crossover(parent1, parent2)
            new_population.append(mutate(child1))  # 变异操作
            new_population.append(mutate(child2))

        population = np.array(new_population)

        # 输出当前代的最优解
        best_individual = min(population, key=objective_function)
        print(f"Generation {generation + 1}: Best Fitness = {objective_function(best_individual)}")

    # 返回最优解及其目标值
    best_individual = min(population, key=objective_function)
    return best_individual, objective_function(best_individual)

# 运行遗传算法
best_solution, best_fitness = genetic_algorithm()
print("Best Solution:", best_solution)
print("Best Fitness:", best_fitness)
