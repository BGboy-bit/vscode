#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int POP_SIZE = 50;        // 种群规模
const int POP_LENGTH = 100;     // 种群大小
const int CROSSOVER_RATE = 0.8; // 交叉概率
const int MUTATION_RATE = 0.1;  // 变异概率
const int GENERATIONS = 100;    // 迭代次数

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
    ll sum = 0;
    for(ll i = 0; i < 100; i ++ ) {
        sum += b[i];
    }
    return 100 - sum;
}

bitset<POP_LENGTH> rouletteWheel(vector<bitset<POP_LENGTH>> pop, 
                                 vector<ll> &fit, ll &total_fit) {
    ll randfit = std::rand() % total_fit;
    ll sum = 0;
    for(ll i = 0; i < POP_SIZE; i ++ ) {
        sum += fit[i];
        if(randfit < sum) {
            return pop[i];
        }
    }
    return pop.back();
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
    
    // 轮盘赌选择
    for(ll i = 0; i < POP_SIZE; i ++ ) {
        pop[i] = rouletteWheel(pop, fit, total_fit);
    }
    
    for(ll i = 0; i < POP_SIZE; i += 2) {
        
    }
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
    cout << "在100次计算后得到的最小值为" << ans << "\n";
    cout << "最小值的种族\n";
    for(ll i = 0; i < POP_LENGTH; i ++ ) {
        cout << pop[ans1][i] << " \n"[(i + 1) % 10 == 0];
    }

    return 0;
}