#include <iostream>
#include <vector>
#include <ctime>
using namespace std;
const int max_int = 999999; 
//Prim�㷨ʵ��
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
    //lowcost�����¼ÿ2�������СȨֵ��visited������ĳ���Ƿ��ѷ���
    vector<int> visited, lowcost;
    for (int i = 0; i < n; ++i) {
        visited.push_back(0);    //��ʼ��Ϊ0����ʾ��û����
    }
    visited[0] = 1;   //��С�������ӵ�һ�����㿪ʼ
    for (int i = 0; i < n; ++i) {
        lowcost.push_back(A[0][i]);    //Ȩֵ��ʼ��Ϊ0
    }

    for (int i = 0; i < n; ++i) {    //ö��n������
        minimum = max_int;
        for (int j = 0; j < n; ++j) {    //�ҵ���СȨ�߶�Ӧ����
            if(!visited[j] && minimum > lowcost[j]) {
                minimum = lowcost[j];
                pos = j;
            }
        }
        if (minimum == max_int)    //���min = max_int��ʾ�Ѿ������е���Լ�����С��������
            break;
        min_tree += minimum;
        visited[pos] = 1;     //������С��������
        for (int j = 0; j < n; ++j) {
            if(!visited[j] && lowcost[j] > A[pos][j]) lowcost[j] = A[pos][j];   //���¿ɸ��±ߵ�Ȩֵ
        }
    }
    cout << "��С·��Ϊ"<<min_tree << endl;
    
     time2 = clock() - time1;
    cout<<endl<<time2<<endl;
}

int main(void)
{
	
    prim_test();
    
    return 0;
}



