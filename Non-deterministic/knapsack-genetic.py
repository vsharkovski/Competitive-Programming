import numpy as np
import random

###########################
# Configurable parameters
POPULATION_SIZE = 100
GENERATION_COUNT = 1000

CROSSOVER_RATE = 0.8
MUTATION_RATE = 0.2

###########################

assert POPULATION_SIZE % 2 == 0

PARENTS_COUNT = POPULATION_SIZE // 2
OFFSPRING_COUNT = POPULATION_SIZE - PARENTS_COUNT


def solve(items, max_weight_allowed):
    # Number of items, item weights, item values.
    items_count = len(items)
    item_weights = np.array([item[0] for item in items], dtype=np.int32)
    item_values = np.array([item[1] for item in items], dtype=np.int32)

    # Calculate probabilities for an individual item to be used
    # (per candidate) when generating the initial population.
    total_item_weight = np.sum(item_weights)
    avg_item_weight = total_item_weight / items_count
    desired_items_count_real = max_weight_allowed / avg_item_weight
    item_used_probability = desired_items_count_real / items_count

    # Calculate probability for an item to be mutated (per candidate)
    mutated_count = desired_items_count_real * MUTATION_RATE
    item_mutated_probability = mutated_count / items_count

    print(
        f"Items count: {items_count}",
        f"Max weight allowed: {max_weight_allowed}",
        f"Total item weight: {total_item_weight}",
        f"Average item weight: {avg_item_weight}",
        f"Items per candidate (in initial population): {desired_items_count_real}",
        f"Item used probability (in initial population): {item_used_probability}",
        f"Traits flipped per candidate per mutation: {mutated_count}",
        f"Item mutated probability: {item_mutated_probability}",
        sep="\n"
    )

    def calculate_fitness(population):
        fitness = np.empty(POPULATION_SIZE, dtype=np.int32)

        for index in range(POPULATION_SIZE):
            candidate = population[index, :]
            total_weight = np.dot(candidate, item_weights)
            if total_weight > max_weight_allowed:
                fitness[index] = 0
            else:
                fitness[index] = np.dot(candidate, item_values)

        return fitness

    def initialization():
        population = np.random.uniform(size=(POPULATION_SIZE, items_count))
        population = (population < item_used_probability).astype(np.int8)
        return population
        
    def selection(population, fitness):
        # Create pairs of (fitness, index) for each candidate in population.
        # Then sort them by fitness, so lowest fitness are first, highest last.
        FITNESS_INDICES_DTYPE = [('fitness', np.int32), ('index', np.int32)]

        fitness_indices = np.empty(POPULATION_SIZE, dtype=FITNESS_INDICES_DTYPE)
        for i in range(POPULATION_SIZE):
            fitness_indices[i] = (fitness[i], i)
        
        fitness_indices.sort()
        
        # Create parents list from the candidates with best fitness.
        parents = np.empty((PARENTS_COUNT, items_count), dtype=np.int8)
        for i in range(PARENTS_COUNT):
            # i-th parent should be i-th candidate with highest fitness.
            candidate_index = fitness_indices[POPULATION_SIZE - 1 - i][1]
            parents[i, :] = population[candidate_index, :]

        return parents

    def crossover(parents):
        offspring = np.empty((OFFSPRING_COUNT, items_count), dtype=np.int8)
        crossover_point = items_count // 2

        offspring_index = 0
        parent_index = 0

        while offspring_index < OFFSPRING_COUNT:
            if random.random() <= CROSSOVER_RATE:
                first_parent_index = parent_index % PARENTS_COUNT
                second_parent_index = (parent_index + 1) % PARENTS_COUNT
                offspring[offspring_index, :crossover_point] = parents[first_parent_index, :crossover_point]
                offspring[offspring_index, crossover_point:] = parents[second_parent_index, crossover_point:]
                offspring_index += 1

            parent_index += 1

        return offspring

    def mutation(offspring):
        mutated = np.random.uniform(size=(OFFSPRING_COUNT, items_count))
        mutated = (mutated < item_mutated_probability).astype(np.int8)

        mutants = np.bitwise_xor(offspring, mutated)
        return mutants


    # Create initial population.
    population = initialization()

    # Optimization phase.
    for generation in range(GENERATION_COUNT):
        fitness = calculate_fitness(population)
        parents = selection(population, fitness)
        offspring = crossover(parents)
        mutants = mutation(offspring)
        population[:PARENTS_COUNT, :] = parents
        population[PARENTS_COUNT:, :] = mutants

    # Find best final candidate.
    fitness_final_generation = calculate_fitness(population)
    
    max_fitness_final = np.max(fitness_final_generation)
    best_candidate_indices = np.where(fitness_final_generation == max_fitness_final)[0]
    best_candidate = population[best_candidate_indices[0], :]

    print(f"Max fitness final:\n{max_fitness_final}")
    print(f"Best candidate:\n{best_candidate}")

    # Return the best final candidate.
    def prettify_candidate(candidate):
        total_weight = np.dot(candidate, item_weights)
        total_value = np.dot(candidate, item_values)
        
        used_items = []
        for i in range(items_count):
            if candidate[i] == 1:
                used_items.append(items[i])
        
        return (total_weight, total_value, used_items)

    return prettify_candidate(best_candidate)


def solve_file(file_name):
    file = open(file_name, "r")

    total_item_weight = int(file.readline().strip())
    remaining_lines = file.readlines()
    items = [[int(x) for x in line.strip().split(" ")] for line in remaining_lines]

    max_weight_allowed = int(input("Enter the maximum weight allowed: "))

    file.close()

    result = solve(items, max_weight_allowed)
    
    print(
        f"Total weight: {result[0]}",
        f"Total value: {result[1]}",
        f"Items used, in format (weight, value):\n{result[2]}",
        sep="\n"
    )


solve_file("knapinput")
