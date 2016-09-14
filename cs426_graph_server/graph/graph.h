#pragma once
#include "../library/mongoose.h"
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <queue>

using namespace std;

struct node{
	uint64_t id;
	unordered_set<node*> neighbors;
    node(uint64_t i){
        this->id=i;
    }
};

class graph{
private:
    unordered_map<uint64_t, node*> nodes;
public:
	uint64_t add_node(uint64_t node_id);
	uint64_t add_edge(uint64_t node_a_id, uint64_t node_b_id);
	uint64_t remove_node(uint64_t node_id);
	uint64_t remove_edge(uint64_t node_a_id, uint64_t node_b_id);
	bool get_node(uint64_t node_id);
    /** 
       Returns a pair of boolean.
       First boolean indicates if the edge exists in the graph.
       Second boolean returns true if both nodes exist in the graph;
                              false if any of them doesn't exist in the graph.
     */
	pair<bool, bool> get_edge(uint64_t node_a_id, uint64_t node_b_id);
    /**
        Returns a set of nodes (the neighbors of the specific node).
     */
    unordered_set<node*> get_neighbors(uint64_t node_id);
    /**
        Returns a pair of int and boolean.
        int stands for the shortest path length, if returned -1, then there is no path betwwen node a and b.
        Boolean returns true if both nodes exist in the graph;
                        false if any of them doesn't exist in the graph.
     */
	pair<uint64_t, bool> shortest_path(uint64_t node_a_id, uint64_t node_b_id);
};
