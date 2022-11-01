#include <string>
#include <vector>
#include <algorithm>

bool occupationsCresc(std::pair<int,int> p1, std::pair<int,int> p2){
    if(p1.second < p2.second) return true;
    if(p1.second > p2.second) return false;
    //if p1.second == p2.second
    if(p1.first < p2.first) return true;
    if(p1.first > p2.first) return false;
    return false;
}

bool occupationsDecresc(std::pair<int,int> p1, std::pair<int,int> p2){
    if(p1.second > p2.second) return true;
    if(p1.second < p2.second) return false;
    //if p1.second == p2.second
    if(p1.first > p2.first) return true;
    if(p1.first < p2.first) return false;
    return false;
}

bool alphOrder(const Student& s1, const Student& s2){
    return s1.getName() < s2.getName();
}
