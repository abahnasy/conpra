////
//// Created by abahnasy on 25.04.20.
////
//
//#include <iostream>
//#include <stdio.h>
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <cmath>
//
//void ReplaceStringInPlace(std::string& subject, const std::string& search,
//                          const std::string& replace) {
//    size_t pos = 0;
//    while ((pos = subject.find(search, pos)) != std::string::npos) {
//        subject.replace(pos, search.length(), replace);
//        pos += replace.length();
//    }
//}
//
//
////int toPowerOf(int base,int power) {
////    int result = 1;
////    for (int i = 0; i < power; ++i) {
////        result *= base;
////    }
////
////    return result;
////}
//
//int main () {
//    std::ios_base::sync_with_stdio(false);
//
//    int t;
//    scanf("%d", &t);
//    std::string dummyLine;
//    getline(std::cin, dummyLine);
//    for (int i = 1; i<= t; ++i) {
//        std::cout << "Case #" <<i << ": ";
//        // read the line
//        std::string line;
//        getline(std::cin, line);
//
//        //convert verbal operations to symbol ones
//        ReplaceStringInPlace(line, "plus", "+");
//        ReplaceStringInPlace(line, "minus", "-");
//        ReplaceStringInPlace(line, "times", "*");
//        ReplaceStringInPlace(line, "tothepowerof", "^");
//
//
//
//        std::vector<int> nums;
//        std::vector<char> opers;
//
//        std::string temp_num;
//        for (char c: line) {
//            if ( c >= '0' && c <= '9') {
//                temp_num.push_back(c);
//            } else {
//                nums.push_back(stoi(temp_num));
//                temp_num = "";
//                opers.push_back(c);
//            }
//        }
//        nums.push_back((stoi(temp_num)));
//
//        // reverse the vectors for ease of computation
//        std::reverse(nums.begin(), nums.end());
//        std::reverse(opers.begin(), opers.end());
//
//        // do the calculation
//
//        while(nums.size() != 1) {
//            int a = nums.back();
//            nums.pop_back();
//            int b = nums.back();
//            nums.pop_back();
//            switch(opers.back()) {
//                case '+':
//                    nums.push_back(a+b);
//                    break;
//                case '-':
//                    nums.push_back(a-b);
//                    break;
//                case '*':
//                    nums.push_back(a*b);
//                    break;
//                case '^':
//                    nums.push_back(std::pow(a,b));
//                    break;
//                default:
//                    std::cout << "Invalid operation" << "\n";
//            }
//            opers.pop_back();
//        }
//
//        std::cout << nums.at(0) <<  "\n";
//
////        print(nums);
////        print(opers);
//
//
//
//
//
//
//
//
//    }
//
//
//    return 0;
//}