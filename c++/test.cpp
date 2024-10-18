#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int POP_SIZE = 50;        // 种群规模
const int POP_LENGTH = 100;     // 种群大小
const db CROSSOVER_RATE = 0.1;  // 交叉概率
const db MUTATION_RATE = 0.1;   // 变异概率
const int GENERATIONS = 100;   // 迭代次数

void init(vector<bitset<POP_LENGTH>> &pop) {
    for(ll i = 1; i <= POP_SIZE; i ++ ) {
        bitset<POP_LENGTH> b;
        for(ll j = 0; j < POP_LENGTH; j ++ ) {
            b[j] = rand() % 2;
        }
        pop.push_back(b);
    }
}

ll fitness(bitset<POP_LENGTH> &b) {
    return 100 - b.count();
}

bitset<POP_LENGTH> rouletteWheel(vector<bitset<POP_LENGTH>> pop, 
                                 vector<ll> &fit, ll &total_fit) {
    ll randfit = rand() % total_fit;
    ll sum = 0;
    for(ll i = 0; i < POP_SIZE; i ++ ) {
        sum += fit[i];
        if(randfit < sum) {
            return pop[i];
        }
    }
    return pop.back();
}

void elitism(vector<bitset<POP_LENGTH>> &pop, vector<ll> &fit, vector<bitset<POP_LENGTH>> &new_pop) {
    ll best_fit = fit[0], best_idx = 0;
    for(ll i = 1; i < POP_SIZE; i++) {
        if(fit[i] > best_fit) {
            best_fit = fit[i];
            best_idx = i;
        }
    }
    new_pop[0] = pop[best_idx];
}

void crossover(bitset<POP_LENGTH> &b1, bitset<POP_LENGTH> &b2) {
    db randcvr = (db)(rand() % 100) / 100;
    if(randcvr < CROSSOVER_RATE) {
        ll idx1 = rand() % POP_LENGTH;
        ll idx2 = rand() % POP_LENGTH;
        if(idx1 > idx2) swap(idx1, idx2);
        for(ll i = idx1; i < idx2; i++) {
            bool b = b1[i];
            b1[i] = b2[i];
            b2[i] = b;
        } 
    }
}

void mutate(bitset<POP_LENGTH> &b) {
    for(ll i = 0; i < POP_LENGTH; i ++ ) {
        db randmut = (db)(rand() % 1000) / 1000;
        if(randmut < MUTATION_RATE) {
            b[i] = 1 - b[i];
        }
    }
}

bool GA(vector<bitset<POP_LENGTH>> &pop) {
    
    // 求出每个种群的适应度
    vector<ll> fit(POP_SIZE);
    ll total_fit = 0;
    for(ll i = 0; i < POP_SIZE; i ++ ) {
        fit[i] = fitness(pop[i]);  
        total_fit += fit[i];
        if(fit[i] == 100) { // 存在最小值种群直接输出答案
            return true;
        }
    }
    
    // 保留精英个体
    vector<bitset<POP_LENGTH>> new_pop(POP_SIZE);
    elitism(pop, fit, new_pop);
    
    // 轮盘赌选择 + 交叉
    for(ll i = 1; i < POP_SIZE; i += 2) {
        bitset<POP_LENGTH> parent1 = rouletteWheel(pop, fit, total_fit);
        bitset<POP_LENGTH> parent2 = rouletteWheel(pop, fit, total_fit);
        crossover(parent1, parent2);
        new_pop[i] = parent1;
        if(i + 1 < POP_SIZE) {
            new_pop[i + 1] = parent2;
        }
    }

    // 变异
    for(ll i = 1; i < POP_SIZE; i++) {
        mutate(new_pop[i]);
    }

    pop = new_pop;
    
    ll ans = 110, ans1 = 0;
    for(ll i = 0; i < POP_SIZE; i ++ ) {
        ll sum = 0;
        for(ll j = 0; j < POP_LENGTH; j ++ ) {
            sum += pop[i][j];
        }
        if(ans > sum) {
            ans = sum;
            ans1 = i;
        }
    }
    cout << ans << "\n";

    return false;
}

int main() {
    srand(static_cast<unsigned int>(std::time(nullptr)));
    
    // 初始化种群
    vector<bitset<POP_LENGTH>> pop;
    init(pop); 
    
    for(ll i = 1; i <= GENERATIONS; i ++ ) {
        bool ac = GA(pop);
        if(ac) {
            cout << "在第" << i - 1 << "次计算后成功求出最小值0\n";
            return 0; 
        }
    }

    ll ans = 110, ans1 = 0;
    for(ll i = 0; i < POP_SIZE; i ++ ) {
        ll sum = 0;
        for(ll j = 0; j < POP_LENGTH; j ++ ) {
            sum += pop[i][j];
        }
        if(ans > sum) {
            ans = sum;
            ans1 = i;
        }
    }
    cout << "在" << GENERATIONS << "次计算后得到的最小值为" << ans << "\n";
    cout << "最小值的种族\n";
    for(ll i = 0; i < POP_LENGTH; i ++ ) {
        cout << pop[ans1][i] << " \n"[(i + 1) % 10 == 0];
    }

    return 0;
}