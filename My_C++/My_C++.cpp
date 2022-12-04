//Learning to code 

#include <iostream>
#include <iomanip>
#include <string>

//Subtracting the minimum from the sample.
void sub_min(double[],const int);

//Adjusting the values b/w 0 and 1 ( both inclusive ).
void normalise(double[],const int);
int main()
{

    double list[]{-1.1,2.3,-2.1,1.6,2.5,1.9,2.7,2.00,-1.96,-2.336,1.94,1.656,-2.66  };
    
    for (size_t i{}; i < std::size(list); i++) {
        //Printing the values prior to the normalization 
        std::cout <<std::fixed<<std::setprecision(10)<<std::setw(15)<< list[i] << std::endl;
        
    }


    std::cout << "End\n";       //Denoting the end of the old values 


    sub_min(list,std::size(list));      //Applying the first function to make all samples positive
    normalise(list,std::size(list));    //Applying the second function to make the normalization

    for (size_t i{}; i < std::size(list); i++) {

        //Printing the new values after normalization
        std::cout<<std::fixed<<std::setprecision(10)<<std::setw(15) << list[i] << std::endl;
    }

    return 0;

}


//Defining the function to subtract the minimum of the values in the array
void sub_min(double arr[],int len) {


    double min{ arr[0] };
    for (size_t i{}; i < len; i++) {
        if (min > arr[i]) {
            min = arr[i];
        }
    }

    for (size_t i{}; i < len; i++) {
        arr[i] -= min;
    }
}


//Defining the function to normalise the values b/w 0 and 1
void normalise(double arr[], int len) {
    double max{ arr[0] };

    for (size_t i{}; i < len; i++) {
        if (max < arr[i]) {
            max = arr[i];
        }
    }
    for (size_t i{}; i < len; i++) {
        arr[i] /= max;
    }
}

