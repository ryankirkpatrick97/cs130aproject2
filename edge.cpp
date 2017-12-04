
#include"edge.h"

edge::edge(int from, int to, int weight){
    this->from = from;
    this->to = to;
    this->weight = weight;
}
edge::edge(){
    from=to=weight=0;
}

bool edge::operator< (const edge& other) const {
    return this->weight > other.weight;
 }

 void edge::swap(){
     int temp = from;
     from = to;
     to = temp;
 }
