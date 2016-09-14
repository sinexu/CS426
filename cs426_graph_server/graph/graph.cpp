uint64_t graph::add_node(uint64_t node_id){

}
uint64_t graph::add_edge(uint64_t node_a_id, uint64_t node_b_id){

}
uint64_t graph::remove_node(uint64_t node_id){

}
uint64_t graph::remove_edge(uint64_t node_a_id, uint64_t node_b_id){

}
bool graph::get_node(uint64_t node_id){
//    return nodes.enum_keys().contains(node_id);
    return this->nodes.find(node_id) != nodes.end();
}
// should return boolean if the EDGE exists i think
pair<bool,bool> graph::get_edge(uint64_t node_a_id, uint64_t node_b_id){
    bool edge_exist = FALSE;
    bool both_node_exist = TRUE;
    if (!get_node(node_a_id) || !get_node(node_b_id)) {
        both_node_exist = FALSE;
    }
    if (get_node(node_a_id) && get_node(node_b_id)) {
        unordered_set<node*> neighbors_a = nodes.at(node_a_id).neighbors;
        if(neighbors_a.find(node_b_id) != neighbors_a.end()) {
            edge_exist = TRUE;
        }
    }
    return pair<edge_exist, both_node_exist>;
}
unordered_set<node*> graph::get_neighbors(uint64_t node_id){
    if (this->get_node(node_id)) {
        return nodes.at(node_id).neighbors;
    } else {
        return NULL;
    }
}
pair<uint64_t, bool> graph::shortest_path(uint64_t node_a_id, uint64_t node_b_id){
    bool both_node_exist = TRUE;
    uint64_t path = -1;
    uint64_t temp_path = 0;
    if (!get_node(node_a_id) || !get_node(node_b_id)) {
        both_node_exist = FALSE;
    }
    if (get_edge(node_a_id, node_b_id)) {
        
        bool *visited = new bool[nodes.size()];
        for (int i = 0; i < nodes.size(); i++) {
            visited[i] = false;
        }
        // Create a queue for BFS
        list<uint64_t> queue;
        
        // Mark the current node as visited and enqueue it
        visited[node_a_id] = true;
        queue.push_back(node_a_id);
        
        // 'i' will be used to get all adjacent vertices of a vertex
        list<uint64_t>::iterator i;
        
        while(!queue.empty()) {
            // Dequeue a vertex from queue and print it
            s = queue.front();
            if (s == node_b_id) {
                path = temp_path;
                break;
            }
            temp_path++;
            queue.pop_front();
            
            // Get all adjacent vertices of the dequeued vertex s
            // If a adjacent has not been visited, then mark it visited
            // and enqueue it
            for(i = get_neighbors(node_a_id).begin(); i != get_neighbors(node_a_id).end(); ++i) {
                if(!visited[*i]) {
                    visited[*i] = true;
                    queue.push_back(*i);
                }
            }
        }
    }
    return pair<path, both_node_exist>;
}