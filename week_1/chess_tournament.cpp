////
//// Created by abahnasy on 25.04.20.
////
//
//#include <stdio.h>
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <sstream>
//int main () {
//
//    int t;
//    scanf("%d", &t);
//    for (int i = 1; i <= t; ++i) {
//        std::cout << "Case #" << i <<":" << "\n";
//        int n; // loop over no. of schools in each test case
//        scanf("%d", &n);
//        std::vector<std::vector<int>> schools;
//        for (int j = 0; j<n; ++j) {
//            std::vector<int> school;
//            for (int k = 0; k <5; ++k) {
//                int num;
//                scanf("%d", &num);
//                school.push_back(num);
//            }
//            //sort students per school
//            sort(school.begin(), school.end());
//            reverse(school.begin(), school.end());
//            //add school to vector of schools
//            schools.push_back(school);
//        }
//        sort(schools.begin(), schools.end());
//        reverse(schools.begin(), schools.end());
//
//        // print schools sorted
//        for (const auto &school : schools) {
//            for (const auto &item1 : school) {
//                std::cout << item1 << " ";
//            }
//            std::cout << "\n";
//        }
//
//    }
//
//
//
//    return 0;
//}