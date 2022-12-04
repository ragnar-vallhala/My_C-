//Learning to code 


#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>




void Five_Highest(std::vector<int>,size_t);							//Function to print the five highest grades
void Five_Lowest(std::vector<int>,size_t);							//Functio to print the five lowest grades
float Mean(std::vector<int>,size_t);								//Function to return the Mean
float Median(std::vector<int>,size_t);								//Function to return the Median
double Standard_Deviation(std::vector<int>,size_t);					//Function to return the Standard Deviation
double Variance(std::vector<int>,size_t);							//Function to return the Variance 
void Sort(std::vector<int>*,size_t);								//Function to sort
void Swap(std::vector<int>*, size_t first_pos, size_t second_pos);	//Function to Swap the values in the Vector






int main() {

	std::vector<int> list;			//Initializing a Vector
	while (1) {
		int data{};					//Variable to get the grades from the User
		std::cin >> data;			//Getting the the grades
		if (data >= 0) {
			list.push_back(data);	//Putting grades in the Vector
		}
		else {
			break;					//Breaking in case of a negative input
		}
	}
	
	Sort(&list, std::size(list));						//Sorting the array to apply the the functions later
	std::cout << "Sorted array of the marks : ";	
	for (size_t i{}; i < std::size(list); i++) {
		/*Printing the sorted array*/
		std::cout<< list[i] << std::setw(5);
	}

	std::cout<<std::endl << "Top five marks are : ";		//Printing the top five marks
	Five_Highest(list, std::size(list));

	std::cout<<std::endl << "Bottom five marks are : ";		//Printing the bottom five marks
	Five_Lowest(list, std::size(list));

	std::cout<<std::fixed<<std::endl << std::setprecision(6) << "The Mean of the data is " << Mean(list, std::size(list)) << std::endl;			//Printing the mean of the data

	std::cout << std::fixed << std::setprecision(6) << "The Median of the data is " << Median(list, std::size(list)) << std::endl;				//Printing the median of the data

	std::cout << std::fixed << std::setprecision(6) << "The Variance of the data is " << Variance(list, std::size(list)) << std::endl;			//Printing the variance of the data

	std::cout << std::fixed << std::setprecision(6) << "The Standard Deviation of the data is " << Standard_Deviation(list, std::size(list)) << std::endl;		//Printing the standard deviation of the data
	return 0;
}




void Swap(std::vector<int>*arr, size_t first_pos, size_t second_pos) {
	/*Function works on the pointer to the vector that stores the marks in the main function and modifies its elements i.e swaps the elements*/

	int temp{ (*arr)[first_pos] };						//temp variable to hold the first element
	(*arr)[first_pos] = (*arr)[second_pos];				
	(*arr)[second_pos] = temp;							//completing the swap
}

void Sort(std::vector<int> *arr,size_t len) {
	/*Functin to sort the vector conating the marks. */
	for (size_t i{}; i < len;i++) {						//Iterating through the vector
		for (size_t j{ i + 1 }; j < len; j++) {			//Second iterator to find suitable value to swap
			if ((*arr)[i] > (*arr)[j]) {
				Swap(arr, i, j);						//Calling the Swap function
			}
		}
	}
}

void Five_Highest(std::vector<int>arr,size_t len) {
	/*Function to print the top five marks. It works on the pass-by-value mechanism of argument passing.*/
	if (len <= 5 ) {
		for (size_t i{len-1}; i>=0; i--) {				//In case of  a smaller vector
			std::cout << arr[i]<<std::setw(5);
		}
	}
	else {
		for (size_t i{len-1}; i>=(len-5); i--) {
			std::cout << arr[i] << std::setw(5);
		}
	}
}

void Five_Lowest(std::vector<int>arr, size_t len) {
	/*Function to print the bottom five marks. It works on the pass-by-value mechanism of argument passing.*/
	if (len <= 5) {
		for (size_t i{}; i < len; i++) {				//In case of  a smaller vector
			std::cout << arr[i] << std::setw(5);
		}
	}
	else {
		for (size_t i{}; i < 5; i++) {
			std::cout << arr[i] << std::setw(5);
		}
	}
}

float Mean(std::vector<int> arr,size_t len) {
	/*Function to calculate the mean of the data.*/
	float sum{};
	for (int i : arr) {
		sum += i;
	}
	return (sum / len);
}


float Median(std::vector<int>arr, size_t len) {
	/*Function to calculate the Median of the data.*/
	if (len % 2 != 0) {
		float Med = static_cast<int>(arr[len / 2]);
		return Med;
	}
	else {
		float sum_med =static_cast<int>( arr[len / 2] + arr[len / 2 + 1]);
		return sum_med / 2;
	}
}


double Variance(std::vector<int>arr, size_t len) {
	/*Function to calculate the Variance of the data.*/
	double sum{};
	double mean =static_cast<float>( Mean(arr, len));
	for (size_t i{}; i < len; i++) {
		sum += ((arr[i] - mean) * (arr[i] - mean));
	}
	return sum / len;
}

double Standard_Deviation(std::vector<int>arr, size_t len) {
	/*Function to calculate the SD of the data.*/
	return std::sqrt(Variance(arr, len));		//Calls the Variance function
}