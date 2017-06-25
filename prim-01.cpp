#include <iostream>
#include <vector>
#include <ctime>
using namespace std;
const int max_int = 999999; 
//Prim算法实现
void prim_test()
{
    int n;
    cin >> n;
    vector<vector<int> > A(n, vector<int>(n));
    for(int i = 0; i < n ; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> A[i][j];
        }
    }

    double time1,time2;
	time1 = clock();
   

    int pos, minimum;
    int min_tree = 0;
    //lowcost数组记录每2个点间最小权值，visited数组标记某点是否已访问
    vector<int> visited, lowcost;
    for (int i = 0; i < n; ++i) {
        visited.push_back(0);    //初始化为0，表示都没加入
    }
    visited[0] = 1;   //最小生成树从第一个顶点开始
    for (int i = 0; i < n; ++i) {
        lowcost.push_back(A[0][i]);    //权值初始化为0
    }

    for (int i = 0; i < n; ++i) {    //枚举n个顶点
        minimum = max_int;
        for (int j = 0; j < n; ++j) {    //找到最小权边对应顶点
            if(!visited[j] && minimum > lowcost[j]) {
                minimum = lowcost[j];
                pos = j;
            }
        }
        if (minimum == max_int)    //如果min = max_int表示已经不再有点可以加入最小生成树中
            break;
        min_tree += minimum;
        visited[pos] = 1;     //加入最小生成树中
        for (int j = 0; j < n; ++j) {
            if(!visited[j] && lowcost[j] > A[pos][j]) lowcost[j] = A[pos][j];   //更新可更新边的权值
        }
    }
    cout << "最小路径为"<<min_tree << endl;
    
     time2 = clock() - time1;
    cout<<endl<<time2<<endl;
}

int main(void)
{
	
    prim_test();
    
    return 0;
}



