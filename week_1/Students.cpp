//
// Created by abahnasy on 25.04.20.
//

#include  <iostream>
#include  <stdio.h>
#include <string>
#include <regex>


//void ReplaceStringInPlace(std::string& subject, const std::string& search,
//                          const std::string& replace) {
//    size_t pos = 0;
//    while ((pos = subject.find(search, pos)) != std::string::npos) {
//        subject.replace(pos, search.length(), replace);
//        pos += replace.length();
//    }
//}
//

//int main() {
//    std::string s1_old = "entin"; std::string s1_new = "ierende";
//    std::string s2_old = "enten"; std::string s2_new = "ierende";
//    std::string s3_old = "ent"; std::string s3_new = "ierender";
//    //  loop  over  all  test  cases
//    int t;
//    scanf("%d", &t);
//    for(int i = 1; i  <= t; i++) {
//        int n;
//        scanf("%d", &n);
//        std::string s_dummy;
//        std::getline(std::cin, s_dummy);
//        std::cout  << "Case #" << i << ":" << "\n";
//        for(int j = 0; j < n; ++j) {
//            //  read  string from input
//            std:: string  s;
////            std::cin >> s1;
//            std::getline (std::cin,s);
//
////            s = std::regex_replace(s, std::regex(s1_old), s1_new);
////            s = std::regex_replace(s, std::regex(s2_old), s2_new);
////            s = std::regex_replace(s, std::regex(s3_old), s3_new);
////            ReplaceStringInPlace(s,s1_old,s1_new);
////            ReplaceStringInPlace(s,s2_old,s2_new);
////            ReplaceStringInPlace(s,s3_old,s3_new);
////            // search for the first pattern
////
////
//            std::size_t found = 0;
//            while((found = s.find(s1_old, found)) != std::string::npos)
//            {
//                s.replace(found, s1_old.length(), s1_new);
//                found += s1_new.length();
//            }
//
//            found = 0;
//            while((found = s.find(s2_old,found)) != std::string::npos)
//            {
//                s.replace(found, s2_old.size(), s2_new);
//                found += s2_old.size();
//            }
//
//            found = 0;
//            while((found = s.find(s3_old, found)) != std::string::npos)
//            {
//                s.replace(found, s3_old.size(), s3_new);
//                found += s3_new.size();
//            }
////            // search for the second pattern
////            found = s.find(s2_old);
////            while(found != std::string::npos)
////            {
////                s.replace(found, s2_new.size(), s2_new);
////                found = s.find(s2_old, found+s2_new.size());
////            }
////            // search for the third pattern
////            found = s.find(s3_old);
////            while(found != std::string::npos)
////            {
////                s.replace(found, s3_new.size(), s3_new);
////                found = s.find(s3_old, found+s3_new.size());
////            }
//            std::cout << s << "\n";
//        }
//
//        //  output: use  the  possibility  you  like  more
////         << "Hello "<< s1 << "!" << std::endl;
//
//    }
//
//
//    return 0;
//};