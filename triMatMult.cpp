#include <iostream>
#include <fstream>
#include <vector>



int main(int argc, char* argv[]){

	int matrix_size;
	int cur_matrix_number;
	std::ifstream matrix_1;
	std::ifstream matrix_2;

	matrix_1.open(argv[1]);
	matrix_1 >> matrix_size;
	std::vector<int> matrix_1_numbers;
	while(matrix_1 >> cur_matrix_number){
		matrix_1_numbers.push_back(cur_matrix_number);
	}
	matrix_1.close();

	matrix_2.open(argv[2]);
	matrix_2 >> matrix_size;
	std::vector<int> matrix_2_numbers;
	while(matrix_2 >> cur_matrix_number){
		matrix_2_numbers.push_back(cur_matrix_number);
	}

	std::vector<int> result_matrix;

	int k, g = 0;
	for (int m = matrix_size; m > 0; --m) {   //recording how many lines
		for (int i = 0; i < m; ++i) {  // recording values in each line
			int cur_result_number = 0;
			k = i;                   
			for (int j = 0; j < i + 1; ++j) {
				cur_result_number += matrix_1_numbers[g + j] * matrix_2_numbers[g + k];
				k += matrix_size - j - 1 - (matrix_size - m);
			}
			result_matrix.push_back(cur_result_number);
		}
		g += m;
	}
	int result_matrix_size = (int)(result_matrix.size());


	for (int j = 0; j < result_matrix_size; ++j) {
		std::cout << result_matrix[j] << " ";
	}
	std::cout << std::endl;
}