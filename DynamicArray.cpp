#include "DynamicArray.h"
#include <string>

template class DynamicArray<int>;
template class DynamicArray<double>;
template class DynamicArray<std::string>;

template double distance<int>(const DynamicArray<int>&, const DynamicArray<int>&);
template double distance<double>(const DynamicArray<double>&, const DynamicArray<double>&);
template double distance<std::string>(const DynamicArray<std::string>&, const DynamicArray<std::string>&);