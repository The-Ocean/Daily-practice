//二货小易有一个W*H的网格盒子，网格的行编号为0~H-1，网格的列编号为0~W-1。
//每个格子至多可以放一块蛋糕，任意两块蛋糕的欧几里得距离不能等于2。
//对于两个格子坐标(x1, y1), (x2, y2)的欧几里得距离为:
//((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) 的算术平方根
//小易想知道最多可以放多少块蛋糕在网格盒子里。
//输入：3 2 
//输出：4
#include<iostream>
#include<vector>

int main()
{
	int W, H;
	std::cin >> W >> H;

	std::vector<std::vector<int>> arr;
	arr.resize(W);
	for (auto &e : arr)
	{
		e.resize(H, 1);
	}

	int num_cakes = 0;
	for (int i = 0; i < W; i++) {
		for (int j = 0; j < H; j++) {
			if (arr[i][j] == 1) {
				num_cakes++;                
				// 标记不能放蛋糕的位置                
				if((i+2)<W)                    
					arr[i+2][j] = 0;                                
				if((j+2)<H)                    
					arr[i][j+2] = 0;            
			}        
		}    
	}    
	std::cout << num_cakes << std::endl;

	return 0;
}
