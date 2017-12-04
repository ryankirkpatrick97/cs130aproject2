#ifndef EDGE_H
#define EDGE_H

class edge {
public:
    int from;
    int to;
    int weight;

    edge();
    edge(int from, int to, int weight);

    bool operator< (const edge& other) const;
    void swap();

};

#endif /*edge_H*/
