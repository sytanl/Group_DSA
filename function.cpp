#include "function.h"
#include "SortAlg.h"
#include "DataGenerator.h"

using namespace std;

int command1(string algorithm, string input_file, string output_param, long long &input_size,  long long &count_assign, long long &count_compare, float &Time)
{
    ifstream file(input_file);
    if (!file)  return 1;

    if (output_param != "-both")
    {
        if (output_param != "-time")
        {
            if (output_param != "-comp") return 3;
        }
    }

    vector<int> data;
    int num = 0;
   

    while (file >> num)
    {
        data.push_back(num);
        input_size++;       
    }
    
    int *array = new int[input_size];

    for (int i = 0; i < input_size; i++)
    {
        array[i] = data[i];
    }

    if (algorithm == "selection-sort")
    {
        selectionSort(array, input_size, count_assign, count_compare, Time);
    }
    else if (algorithm == "insertion-sort")
    {
        insertionSort(array, input_size, count_assign, count_compare, Time);
    }
    else if (algorithm == "bubble-sort")
    {
        bubbleSort(array, input_size, count_assign, count_compare, Time);
    } 
    else if (algorithm == "heap-sort")
    {
        heapSort(array, input_size, count_assign, count_compare, Time);
    }
    else if (algorithm == "counting-sort")
    {
        countingSort(array, input_size, count_assign, count_compare, Time);
    }
    else if (algorithm == "radix-sort")
    {
        radixSort(array, input_size, count_assign, count_compare, Time);
    }
    else if (algorithm == "quick-sort")
    {
        qSortCount(array, input_size, count_assign, count_compare, Time);
    }
    else if (algorithm == "merge-sort")
    {
        mergeSortCount(array, input_size, count_assign, count_compare, Time);
    }
    else if (algorithm == "shell-sort")
    {
        shellSort(array, input_size, count_assign, count_compare, Time);
    
    }
    else if (algorithm == "shaker-sort")
    {
        shakerSort(array, input_size, count_assign, count_compare, Time);
    }
    else if (algorithm == "flash-sort")
    {
        flashSort(array, input_size, count_assign, count_compare, Time);
    }
    else return 2;

    delete[] array;
    return 0;
}

void output_for_command_1_2_3(string algorithm, string input_file, long long input_size, string output_param, long long count_compare, float Time)
{
    cout << "ALGORITHM MODE\n";
    cout << "Algorithm: " << algorithm << endl;
    cout << "Input size: " << input_size << endl;
    cout << "-------------------------\n";
    
    if (output_param == "-both")
    {
        cout << "Running time: " << Time << endl;
        cout << "Comparison: " << count_compare << endl;
    }
    else if (output_param == "-comp")
    {
        cout << "Comparison: " << count_compare << endl;
    }
    else if (output_param == "-time")
    {
        cout << "Running time: " << Time << endl;
    }
}

void use_command1(string algorithm, string input_file, string output_param, long long &input_size,  long long &count_assign, long long &count_compare, float &Time)
{
    int result = command1(algorithm, input_file, output_param, input_size, count_assign, count_compare, Time);
    switch (result)
    {
        case 1:
        {
            cout << "File not found!\n";
            break;
        }
        case 2:
        {
            cout << "Unknown algorithm!\n";
            break;
        }
        case 3:
        {
            cout << "Unkown output param!\n";
            break;
        }
        case 0:
        {
            output_for_command_1_2_3(algorithm, input_file, input_size, output_param, count_compare, Time);
            break;
        }
    }
}